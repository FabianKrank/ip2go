/* ########### */
/* # INCLUDE # */
/* ########### */


float *mpc_dw1_get_x0();
float *mpc_dw1_get_x(int k);
float *mpc_dw1_get_u(int k);
float *mpc_dw1_get_s(int k);
float *mpc_dw1_get_p(int k);
float *mpc_dw1_get_y(int k);
float *mpc_dw1_get_nu(int k);
float *mpc_dw1_get_Hxx(int k);
float *mpc_dw1_get_Hxu(int k);
float *mpc_dw1_get_Huu(int k);
float *mpc_dw1_get_Hss(int k);
float *mpc_dw1_get_f0x(int k);
float *mpc_dw1_get_f0u(int k);
float *mpc_dw1_get_f0s(int k);
float *mpc_dw1_get_fx(int k);
float *mpc_dw1_get_fu(int k);
float *mpc_dw1_get_f(int k);
float *mpc_dw1_get_gx(int k);
float *mpc_dw1_get_gu(int k);
float *mpc_dw1_get_g(int k);
float *mpc_dw1_get_stat_time();
int *mpc_dw1_get_stat_iter_ref();
int *mpc_dw1_get_stat_num_factor();
int *mpc_dw1_get_stat_num_solve();
int *mpc_dw1_get_stat_num_iter_ref();
int *mpc_dw1_get_iter();
int *mpc_dw1_get_termcode();
int *mpc_dw1_get_error_line();
int *mpc_dw1_get_error_source();
float *mpc_dw1_get_norm_d();
double *mpc_dw1_get_time_max();
void mpc_dw1_set_time_max(double tmax);

double mpc_dw1_glqdocpip_timer_get();
void mpc_dw1_glqdocpip_timer_start();
int mpc_dw1_glqdocpip();
