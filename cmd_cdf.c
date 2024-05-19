#include "cmd_cdf.h"
#include "cmd.h"
#include "cmd_col.h"
#include "cmd_row.h"
#include "tools.h"

int cmd_cdf_new(Command* cmd) {
    cdf_log("cmd_cdf_new()");
//    print_header("cmd_cdf_new");
    char *usage = "cdf_new INT CHAR STRING DOUBLE INT";
    ENUM_TYPE *cdftype = malloc(cmd->size * sizeof(ENUM_TYPE));
    for (int i = 0; i < cmd->size; i++) {
        char *param = cmd->params[i];
        printf("exec cdf_new with %s\n", param);
        if (strcmp(param, "INT") == 0) {
            cdftype[i] = INT;
        } else if (strcmp(param, "UINT") == 0) {
            cdftype[i] = UINT;
        } else if (strcmp(param, "DOUBLE") == 0) {
            cdftype[i] = DOUBLE;
        } else if (strcmp(param, "FLOAT") == 0) {
            cdftype[i] = FLOAT;
        } else if (strcmp(param, "CHAR") == 0) {
            cdftype[i] = CHAR;
        } else if (strcmp(param, "STRING") == 0) {
            cdftype[i] = STRING;
        } else {
            cmd_error("Error parametre incorrect !");
        }
    }
    CDF = create_cdataframe(cdftype, cmd->size);
    return 0;
}

int cmd_cdf_display(Command* cmd) {
    cdf_log("cmd_cdf_display()");
    print_header("cmd_cdf_display");

    cdf_print_line(CDF, 0);
//    display_cdf(CDF);

    return 0;
}

int cmd_cdf_delete(Command* cmd) {
    cdf_log("cmd_cdf_delete()");
    print_header("cmd_cdf_delete");

//    lst_delete_list
//    delete_cdataframe(*CDF);

    return 0;
}

