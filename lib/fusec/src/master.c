#include "common.h"


typedef struct m_param {
    uint32_t param_id;
    unsigned char param_type;
    size_t size;
    unsigned char *val;
    struct m_param *next;
} master_parameter_t;


typedef struct m_job {
    uint32_t job_id;
    uint32_t task_id;
    master_parameter_t **params;
    struct m_job *next;
} master_job_t;


typedef struct m_result {
   uint32_t job_id;
   int complete;
   master_parameter_t **params;
   struct m_result *next;
} master_result_t;


int
fuse_master_format_task(
    uint32_t job_id,
    uint32_t task_id,
    *params,
    *results);
   

typedef struct {
    
} fuse_master_t;



