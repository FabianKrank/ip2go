/* ########### */
/* # INCLUDE # */
/* ########### */


float *mpc_dw2_get_x0();
float *mpc_dw2_get_x(int k);
float *mpc_dw2_get_u(int k);
float *mpc_dw2_get_s(int k);
float *mpc_dw2_get_p(int k);
float *mpc_dw2_get_y(int k);
float *mpc_dw2_get_nu(int k);
float *mpc_dw2_get_Hxx(int k);
float *mpc_dw2_get_Hxu(int k);
float *mpc_dw2_get_Huu(int k);
float *mpc_dw2_get_Hss(int k);
float *mpc_dw2_get_f0x(int k);
float *mpc_dw2_get_f0u(int k);
float *mpc_dw2_get_f0s(int k);
float *mpc_dw2_get_fx(int k);
float *mpc_dw2_get_fu(int k);
float *mpc_dw2_get_f(int k);
float *mpc_dw2_get_gx(int k);
float *mpc_dw2_get_gu(int k);
float *mpc_dw2_get_g(int k);
float *mpc_dw2_get_stat_time();
int *mpc_dw2_get_stat_iter_ref();
int *mpc_dw2_get_stat_num_factor();
int *mpc_dw2_get_stat_num_solve();
int *mpc_dw2_get_stat_num_iter_ref();
int *mpc_dw2_get_iter();
int *mpc_dw2_get_termcode();
int *mpc_dw2_get_error_line();
int *mpc_dw2_get_error_source();
float *mpc_dw2_get_norm_d();
double *mpc_dw2_get_time_max();
void mpc_dw2_set_time_max(double tmax);

double mpc_dw2_glqdocpip_timer_get();
void mpc_dw2_glqdocpip_timer_start();
int mpc_dw2_glqdocpip();

double mpc_dw2_glqdocpip_performance_test_1_iteration();
double mpc_dw2_glqdocpip_performance_test_factor();
double mpc_dw2_glqdocpip_performance_test_solve();
double mpc_dw2_glqdocpip_performance_test_affine();
double mpc_dw2_glqdocpip_performance_test_reduced();
double mpc_dw2_glqdocpip_performance_test_dereduce();
double mpc_dw2_glqdocpip_performance_test_norm_r();
double mpc_dw2_glqdocpip_performance_test_structure_mult_m_fx0();
double mpc_dw2_glqdocpip_performance_test_1_iteration_iterref();
double mpc_dw2_glqdocpip_performance_test_starting();
