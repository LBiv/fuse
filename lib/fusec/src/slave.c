typedef int (*slave_callback_t)(unsigned char **params);

typedef struct param {
    uint32_t param_id;
    unsigned char param_type
    size_t size;
    unsigned char *val;
    struct param *next;
} slave_parameter_t;

typedef struct job {
    uint32_t job_id;
    uint32_t task_id;
    slave_parameter_t **params;
    struct job *next;
} slave_job_t;

typedef struct result {
    uint32_t job_id;
    uint32_t response_code;
    slave_parameter_t **params;
    struct result *next;
} slave_result_t

typedef struct {
    slave_callback_t *task_table;
    char **response_table;
    slave_parameter_t *params;
    slave_job_t *jobs;
    slave_result_t *results;
} fuse_slave_t; 


/*
int
slave_parse_input(
    fuse_slave_t *slave,
    unsigned char *in,
    size_t insize,
    slave_job_t **jobs)
{
    if(!slave || !in || !insize || !jobs) {
        return -1;
    }


}
*/






slave_parameter_t *
slave_param_save(
    fuse_slave_t *slave,
    uint32_t param_id,
    unsigned char param_type,
    unsigned char *val,
    size_t size)
{
    slave_parameter_t *result;

    if(!slave || !val) {
        return NULL;
    }

    if(!(result = malloc(sizeof(fuse_slave_t)))) {
        return NULL;
    }

    memset(result, 0, sizeof(fuse_slave_t));
    result->param_id = param_id;
    result->param_type = param_type;
    result->size = size;
    result->val = val;

    return result;
}


void
slave_param_destroy(
    slave_parameter_t *param)
{
    if(!param) {
        return;
    }

    if(param->val) {
        free(param->val);
    }
}


int
slave_param_free(
    fuse_slave_t *slave,
    uint32_t param_id)
{
    slave_parameter_t *last, *next;

    if(!slave || !param_id) {
        return -1;
    }

    last = slave->params;
    next = slave->params->next;
    
    if(last->param_id == param_id) {
        slave->params = last->next;
        slave_param_destroy(last);
        return 0;
    }

    while(next) {
        
        if(next->param_id == param_id) {
            last>next = next->next;
            slave_param_destroy(next);
            return 0;
        }

        last = next;
        next = next->next;
    }

    return -2;
}

    

