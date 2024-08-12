#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Get .json file
    FILE *json_file = fopen(argv[1], "r");

    if (json_file == NULL)
    {
        perror("JSON to C: failed to open JSON file.");
        return -1;
    }

    // Get file size
    fseek(json_file, 0, SEEK_END);
    long file_size = ftell(json_file);
    fseek(json_file, 0, SEEK_SET);

    // Get memory
    char *file_content = (char *)malloc(file_size + 1);

    if (file_content == NULL)
    {
        perror("JSON to C: failed to allocate memory for file.");
        fclose(json_file);
        return -1;
    }

    // Write file to memory
    fread(file_content, 1, file_size, json_file);
    file_content[file_size] = '\0';
    fclose(json_file);

    // Parse file
    cJSON *json = cJSON_Parse(file_content);
    
    if (json == NULL)
    {
        perror("JSON to C: failed to parse JSON file.");

        const char *error_ptr = cJSON_GetErrorPtr();

        if (error_ptr != NULL)
        {
            fprintf(stderr, "\tParsing failed at character %ld\n", error_ptr - file_content);
        }

        return -1;
    }
    free(file_content);

    // Create output file
    FILE *out = fopen("out.c", "w");

    if (out == NULL) {
        perror("JSON to C: failed to create or open ./out.c.");
        return -1;
    }

    // Add header for all the constructs
    fprintf(out, "#include <scratchc.h>\n\n");

    // Add sprite declarations
    cJSON *targets = cJSON_GetObjectItemCaseSensitive(json, "targets");

    cJSON *target;
    cJSON *name;
    cJSON_ArrayForEach(target, targets) {
        if (!cJSON_IsNull(target)) {
            name = cJSON_GetObjectItemCaseSensitive(target, "name");
            printf("%x\n", (int)name->valuestring);
            fprintf(out, "sprite %s = sprite();\n", name->valuestring);
        }
    }
    
    fclose(out);
    cJSON_Delete(json);
    return 0;
}