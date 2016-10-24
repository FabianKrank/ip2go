/* ########### */
/* # INCLUDE # */
/* ########### */


double *linflp_k35_get_x0();
double *linflp_k35_get_x(int k);
double *linflp_k35_get_u(int k);
double *linflp_k35_get_s(int k);
double *linflp_k35_get_p(int k);
double *linflp_k35_get_y(int k);
double *linflp_k35_get_nu(int k);
double *linflp_k35_get_Hxx(int k);
double *linflp_k35_get_Hxu(int k);
double *linflp_k35_get_Huu(int k);
double *linflp_k35_get_Hss(int k);
double *linflp_k35_get_f0x(int k);
double *linflp_k35_get_f0u(int k);
double *linflp_k35_get_f0s(int k);
double *linflp_k35_get_fx(int k);
double *linflp_k35_get_fu(int k);
double *linflp_k35_get_f(int k);
double *linflp_k35_get_gx(int k);
double *linflp_k35_get_gu(int k);
double *linflp_k35_get_g(int k);
double *linflp_k35_get_stat_time();
int *linflp_k35_get_stat_iter_ref();
int *linflp_k35_get_stat_num_factor();
int *linflp_k35_get_stat_num_solve();
int *linflp_k35_get_stat_num_iter_ref();
int *linflp_k35_get_iter();
int *linflp_k35_get_termcode();
int *linflp_k35_get_error_line();
int *linflp_k35_get_error_source();
double *linflp_k35_get_norm_d();
double *linflp_k35_get_time_max();
void linflp_k35_set_time_max(double tmax);

double linflp_k35_glqdocpip_timer_get();
void linflp_k35_glqdocpip_timer_start();
int linflp_k35_glqdocpip();
