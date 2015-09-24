typedef int (*slave_callback_t)(unsigned char **params);

typedef struct param {
    uint32_t param_id;
    unsigned char param_type
    size_t size;
    unsigned char *val;
    struct param *next;
} slave_parameter_t;

typedef struct result {
    uint32_t job_id;
    uint32_t response_code;
    uint32_t *param_ids;
    struct result *next;
} slave_result_t

typedef struct {
    slave_callback_t *func_table;
    char **response_table;
    slave_parameter_t *top_param;
    slave_parameter_t *bot_param;
    slave_result_t *top_result;
    slave_result_t *bot_result;
} fuse_slave_t; 









