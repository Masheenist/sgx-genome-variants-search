#ifndef __ENCLAVE_QUOTE_H
#define __ENCLAVE_QUOTE_H

#ifdef NON_SGX
#include "../include/config.h"

sgx_status_t get_report(sgx_report_t *report, sgx_target_info_t *target_info);

size_t get_pse_manifest_size();

sgx_status_t get_pse_manifest(char *buf, size_t sz);

sgx_status_t enclave_ra_init(sgx_ec256_public_t key, int b_pse,
                             sgx_ra_context_t *ctx, sgx_status_t *pse_status);

sgx_status_t enclave_ra_init_def(int b_pse, sgx_ra_context_t *ctx,
                                 sgx_status_t *pse_status);

sgx_status_t enclave_ra_close(sgx_ra_context_t ctx);

// Application specific enclave functions
void enclave_derive_key(sgx_ra_context_t ctx);

// Public ECALL interface for getting results out of the enclave
void enclave_get_eig_buf(float *my_res);
void enclave_init_temp_buf(int ENC_BUFF_LEN);
void enclave_get_temp_buf(float *res, int len);
void enclave_free_temp_buf();
void enclave_get_mh_ids(uint32_t *ids, int l);
void enclave_get_mh_vals(uint16_t *vals, int l);
void enclave_get_mh_pairs(res_pair *pairs, int l);
void enclave_init_id_buf(int ENC_BUFF_LEN);
void enclave_get_id_buf(uint32_t *id, int k);
void enclave_free_id_buf();
void enclave_init_res_buf(int ENC_BUFF_LEN);
void enclave_get_res_buf(float *countf, int k);
void enclave_get_res_pairs(res_pair *pairs, int k);
void enclave_free_res_buf();

// Open-Addressing Hash-Table public ECALL interface
void enclave_init_oa(int OA_INIT_CAPACITY);
void enclave_decrypt_process_oa(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                size_t ciphertext_len);
void enclave_free_oa();

// Robin-Hood-Hash-Table public ECALL interface
void enclave_init_rhht(int RHHT_INIT_CAPACITY);
void enclave_decrypt_process_rhht(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                  size_t ciphertext_len);
void enclave_free_rhht();
void enclave_free_rhht_pcc();

// Three-Pass version
void enclave_init_sketch_rhht(int MH_INIT_CAPACITY);
void enclave_decrypt_process_sketch_rhht(sgx_ra_context_t ctx,
                                         uint8_t *ciphertext,
                                         size_t ciphertext_len);

void enclave_init_rhht_pcc(int MH_INIT_CAPACITY);
void enclave_decrypt_process_rhht_pcc(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                      size_t ciphertext_len);
void enclave_decrypt_init_rhht_pcc(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                   size_t ciphertext_len);

// Chained-Move-to-Front Hash Table public ECALL interface
void enclave_init_cmtf(int CMTF_NUM_BUCKETS);
void enclave_decrypt_process_cmtf(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                  size_t ciphertext_len);
void enclave_free_cmtf();

// Count-Min-Sketch public ECALL interface
void enclave_init_cms(int CMS_WIDTH, int CMS_DEPTH);
void enclave_normalize_cms_st_length();
void enclave_decrypt_update_cms(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                size_t ciphertext_len);
void enclave_decrypt_update_cms_row(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                    size_t ciphertext_len);
void enclave_decrypt_query_cms(sgx_ra_context_t ctx, uint8_t *ciphertext,
                               size_t ciphertext_len);
void enclave_free_cms();

// Multi-threaded CMS public ECALL interface
void enclave_decrypt_store_cms(sgx_ra_context_t ctx, uint8_t *ciphertext,
                               size_t ciphertext_len);
// void enclave_update_cms(sgx_ra_context_t ctx, uint32_t thread_num);
void enclave_clear_cms(sgx_ra_context_t ctx);
sgx_status_t ecall_thread_cms(int thread_num, int nrows_per_thread);
sgx_status_t ecall_thread_cms_ca(int thread_num, int nrows_per_thread,
                                 int part_num);
sgx_status_t ecall_thread_csk(int thread_num, int nrows_per_thread);
sgx_status_t ecall_thread_csk_ca(int thread_num, int nrows_per_thread,
                                 int part_num);

// Count-Sketch public ECALL interface
void enclave_init_csk(int CSK_WIDTH, int CSK_DEPTH);
void enclave_init_csk_f(int CSK_WIDTH, int CSK_DEPTH);
void enclave_free_csk();
void enclave_decrypt_update_csk(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                size_t ciphertext_len);
void enclave_decrypt_update_csk_row(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                    size_t ciphertext_len);
void enclave_decrypt_update_csk_f(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                  size_t ciphertext_len);
void enclave_decrypt_query_csk(sgx_ra_context_t ctx, uint8_t *ciphertext,
                               size_t ciphertext_len);
void enclave_decrypt_query_csk_f(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                 size_t ciphertext_len);

// Matrix Count-Sketch public ECALL interface
void enclave_reset_file_idx();
void enclave_init_mcsk(int MCSK_WIDTH, int MCSK_NUM_PC, float MCSK_EPS);
void enclave_decrypt_update_mcsk(sgx_ra_context_t ctx, uint8_t *ciphertext,
                                 size_t ciphertext_len);
void enclave_mcsk_mean_centering();

// Multi-threaded CSK public ECALL interface
void enclave_decrypt_store_csk(sgx_ra_context_t ctx, uint8_t *ciphertext,
                               size_t ciphertext_len);
void enclave_update_csk(sgx_ra_context_t ctx, uint32_t thread_num);
void enclave_clear_csk(sgx_ra_context_t ctx);
void enclave_svd();

// Min-Heap public ECALL interface
void enclave_init_mh(int MH_INIT_CAPACITY);
void enclave_init_mh_f(int MH_INIT_CAPACITY);
void enclave_free_mh();

// Chi-Squared Test public ECALL interface
void oa_init_chi_sq(uint16_t case_count, uint16_t control_count, int k);
void rhht_init_chi_sq(uint16_t case_count, uint16_t control_count, int k);
void cmtf_init_chi_sq(uint16_t case_total, uint16_t control_total, int k);
void rhht_init_cat_chi_sq(uint16_t count_total, int k);

#endif

typedef enum _ra_state { ra_inited = 0, ra_get_gaed, ra_proc_msg2ed } ra_state;

typedef struct _ra_db_item_t {
  sgx_ec256_public_t g_a;
  sgx_ec256_public_t g_b;
  sgx_ec_key_128bit_t vk_key;
  sgx_ec256_public_t sp_pubkey;
  sgx_ec256_private_t a;
  sgx_ps_sec_prop_desc_t ps_sec_prop;
  sgx_ec_key_128bit_t mk_key;
  sgx_ec_key_128bit_t sk_key;
  sgx_ec_key_128bit_t smk_key;
  sgx_quote_nonce_t quote_nonce;
  sgx_target_info_t qe_target;
  ra_state state;
  sgx_spinlock_t item_lock;
  uintptr_t derive_key_cb;
} ra_db_item_t;

#endif
