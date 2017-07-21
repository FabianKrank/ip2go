/* mpc123_glqdocpip.c */
/* Generiert: 25-Nov-2016 14:55:08 */


/* ########### */
/* # INCLUDE # */
/* ########### */
#include "float.h"
#include "math.h"

/* ########### */
/* # DEFINE # */
/* ########### */
#define IP2GO_WIN

/* include für Timer (plattformabhängig) */
#if defined(IP2GO_WIN)
/*   Windows */
  #include "windows.h"
#elif defined(IP2GO_DS1103)
/*   dSpace */
  #include "brtenv.h"
#endif


/* ######################## */
/* # Variablendeklaration # */
/* ######################## */
/* Anfangsbedingung */
static float mpc123_xinit[6];

/* Temporäre Variablen */
static float mpc123_tmp1_4_1[4];
static float mpc123_tmp2_4_1[4];
static float mpc123_tmp3_4_1[4];
static float mpc123_tmp1_0_1[1];
static float mpc123_tmp1_8_1[8];
static float mpc123_tmp2_8_1[8];
static float mpc123_tmp3_8_1[8];
static float mpc123_tmp1_8[8];
static float mpc123_tmp2_8[8];
static float mpc123_tmp3_8[8];
static float mpc123_tmp4_8[8];
static float mpc123_tmp1_1[1];
static float mpc123_tmp2_1[1];
static float mpc123_tmp3_1[1];
static float mpc123_tmp1_16[16];
static float mpc123_tmp2_16[16];
static float mpc123_tmp3_16[16];
static float mpc123_tmp4_16[16];
static float mpc123_tmp1_6_6[36];
static float mpc123_tmp1_6_4[24];
static float mpc123_tmp1_1_6[6];
static float mpc123_tmp1_1_4[4];
static float mpc123_tmp1_6_8[48];
static float mpc123_tmp1_1_8[8];
static float mpc123_tmp1_6[6];
static float mpc123_tmp1_6_1[6];
static float mpc123_tmp1_1_1[1];
static float mpc123_tmp2_1_1[1];

/* Variablen für max_stepsize */
static float mpc123_alpha_max[1];
static float mpc123_alpha_tmp[1];
static float mpc123_alpha_min_y[1];
static float mpc123_alpha_min_dy[1];
static float mpc123_alpha_min_nu[1];
static float mpc123_alpha_min_dnu[1];
static int mpc123_alpha_min_source_y;

/* Variablen für mehrotra_step */
static float mpc123_mehrotra_alpha[1];
static float mpc123_mehrotra_gamma[1];
static float mpc123_mehrotra_fpd[1];

/* Verschiedenes */
static int mpc123_iter;
static int mpc123_max_iter;
static int mpc123_termcode;
static int mpc123_iter_ref;
static int mpc123_error_line;
static int mpc123_error_source;
static float mpc123_m_ineq[1];
static float mpc123_macheps[1];
static float mpc123_tau[1];
static float mpc123_sigma[1];
static float mpc123_norm_d[1];
static float mpc123_norm_r[1];
static float mpc123_norm_r0[1];
static float mpc123_norm_r_prev[1];
static float mpc123_mu[1];
static float mpc123_mu0[1];
static float mpc123_mu_aff[1];
static float mpc123_phi[1];
static float mpc123_minphi[1];
static float mpc123_tol[1];
static float mpc123_tc1_factor[1];
static float mpc123_tc2_factor[1];
static double mpc123_timer_start;
static double mpc123_time_max;

/* Variablen für Duality Gap */
static float mpc123_dgap[1];

/* Variablen für Starting Point */
static float mpc123_starting_point_delta_y[1];
static float mpc123_starting_point_delta_nu[1];
static float mpc123_starting_point_sum[1];
static float mpc123_starting_point_sum_y[1];
static float mpc123_starting_point_sum_nu[1];

/* Variablen für Debug */
static float mpc123_debug_dgap[20];
static float mpc123_debug_phi[20];
static float mpc123_debug_minphi[20];
static float mpc123_debug_norm_d[1];
static float mpc123_debug_norm_r0[1];
static float mpc123_debug_norm_r[20];
static float mpc123_debug_mu0[1];
static float mpc123_debug_mu[20];
static float mpc123_debug_mu_aff[20];
static float mpc123_debug_sigma[20];
static float mpc123_debug_alpha_max[20];
static float mpc123_debug_mehrotra_alpha[20];

/* Variablen für Statistik */
static float mpc123_stat_time[20];
static int mpc123_stat_iter_ref[20];
static int mpc123_stat_num_iter_ref;
static int mpc123_stat_num_factor;
static int mpc123_stat_num_solve;

/* Variable für Diskretisierungsstellen */
static float mpc123_arr_t1[7081];



float *mpc123_get_x0()
{
return mpc123_xinit;
}

float *mpc123_get_x(int k)
{
int vindex[12]={2641, 2920, 3307, 3694, 4081, 4468, 4855, 5242, 5629, 6016, 6403, 6790};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_u(int k)
{
int vindex[12]={2647, 2926, 3313, 3700, 4087, 4474, 4861, 5248, 5635, 6022, 6409, 6796};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_s(int k)
{
int vindex[12]={2648, 2927, 3314, 3701, 4088, 4475, 4862, 5249, 5636, 6023, 6410, 6797};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_p(int k)
{
int vindex[12]={2652, 2935, 3322, 3709, 4096, 4483, 4870, 5257, 5644, 6031, 6418, 6801};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_y(int k)
{
int vindex[12]={2658, 2941, 3328, 3715, 4102, 4489, 4876, 5263, 5650, 6037, 6424, 6807};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_nu(int k)
{
int vindex[12]={2666, 2957, 3344, 3731, 4118, 4505, 4892, 5279, 5666, 6053, 6440, 6815};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Hxx(int k)
{
int vindex[12]={1, 151, 385, 619, 853, 1087, 1321, 1555, 1789, 2023, 2257, 2491};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Hxu(int k)
{
int vindex[12]={37, 187, 421, 655, 889, 1123, 1357, 1591, 1825, 2059, 2293, 2527};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Huu(int k)
{
int vindex[12]={43, 193, 427, 661, 895, 1129, 1363, 1597, 1831, 2065, 2299, 2533};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Hss(int k)
{
int vindex[12]={44, 194, 428, 662, 896, 1130, 1364, 1598, 1832, 2066, 2300, 2534};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_f0x(int k)
{
int vindex[12]={60, 258, 492, 726, 960, 1194, 1428, 1662, 1896, 2130, 2364, 2550};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_f0u(int k)
{
int vindex[12]={66, 264, 498, 732, 966, 1200, 1434, 1668, 1902, 2136, 2370, 2556};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_f0s(int k)
{
int vindex[12]={67, 265, 499, 733, 967, 1201, 1435, 1669, 1903, 2137, 2371, 2557};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_fx(int k)
{
int vindex[12]={71, 273, 507, 741, 975, 1209, 1443, 1677, 1911, 2145, 2379, 2561};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_fu(int k)
{
int vindex[12]={107, 309, 543, 777, 1011, 1245, 1479, 1713, 1947, 2181, 2415, 2597};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_f(int k)
{
int vindex[12]={113, 315, 549, 783, 1017, 1251, 1485, 1719, 1953, 2187, 2421, 2603};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_gx(int k)
{
int vindex[12]={119, 321, 555, 789, 1023, 1257, 1491, 1725, 1959, 2193, 2427, 2609};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_gu(int k)
{
int vindex[12]={143, 369, 603, 837, 1071, 1305, 1539, 1773, 2007, 2241, 2475, 2633};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_g(int k)
{
int vindex[12]={147, 377, 611, 845, 1079, 1313, 1547, 1781, 2015, 2249, 2483, 2637};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_stat_time()
{
return mpc123_stat_time;
}

int *mpc123_get_stat_iter_ref()
{
return &mpc123_stat_iter_ref;
}

int *mpc123_get_stat_num_factor()
{
return &mpc123_stat_num_factor;
}

int *mpc123_get_stat_num_solve()
{
return &mpc123_stat_num_solve;
}

int *mpc123_get_stat_num_iter_ref()
{
return &mpc123_stat_num_iter_ref;
}

int *mpc123_get_iter()
{
return &mpc123_iter;
}

int *mpc123_get_termcode()
{
return &mpc123_termcode;
}

int *mpc123_get_error_line()
{
return &mpc123_error_line;
}

int *mpc123_get_error_source()
{
return &mpc123_error_source;
}

float *mpc123_get_norm_d()
{
return mpc123_norm_d;
}

float *mpc123_get_dx(int k)
{
int vindex[12]={2674, 2973, 3360, 3747, 4134, 4521, 4908, 5295, 5682, 6069, 6456, 6823};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_du(int k)
{
int vindex[12]={2680, 2979, 3366, 3753, 4140, 4527, 4914, 5301, 5688, 6075, 6462, 6829};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_ds(int k)
{
int vindex[12]={2681, 2980, 3367, 3754, 4141, 4528, 4915, 5302, 5689, 6076, 6463, 6830};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_dp(int k)
{
int vindex[12]={2685, 2988, 3375, 3762, 4149, 4536, 4923, 5310, 5697, 6084, 6471, 6834};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_dy(int k)
{
int vindex[12]={2691, 2994, 3381, 3768, 4155, 4542, 4929, 5316, 5703, 6090, 6477, 6840};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_dnu(int k)
{
int vindex[12]={2699, 3010, 3397, 3784, 4171, 4558, 4945, 5332, 5719, 6106, 6493, 6848};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rf0x(int k)
{
int vindex[12]={2707, 3026, 3413, 3800, 4187, 4574, 4961, 5348, 5735, 6122, 6509, 6856};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rf0u(int k)
{
int vindex[12]={2713, 3032, 3419, 3806, 4193, 4580, 4967, 5354, 5741, 6128, 6515, 6862};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rf0s(int k)
{
int vindex[12]={2714, 3033, 3420, 3807, 4194, 4581, 4968, 5355, 5742, 6129, 6516, 6863};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rf(int k)
{
int vindex[12]={2718, 3041, 3428, 3815, 4202, 4589, 4976, 5363, 5750, 6137, 6524, 6867};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rc(int k)
{
int vindex[12]={2724, 3047, 3434, 3821, 4208, 4595, 4982, 5369, 5756, 6143, 6530, 6873};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rk(int k)
{
int vindex[12]={2732, 3063, 3450, 3837, 4224, 4611, 4998, 5385, 5772, 6159, 6546, 6881};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rs(int k)
{
int vindex[12]={2728, 3055, 3442, 3829, 4216, 4603, 4990, 5377, 5764, 6151, 6538, 6877};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rrf0x(int k)
{
int vindex[12]={2740, 3079, 3466, 3853, 4240, 4627, 5014, 5401, 5788, 6175, 6562, 6889};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rrf0u(int k)
{
int vindex[12]={2746, 3085, 3472, 3859, 4246, 4633, 5020, 5407, 5794, 6181, 6568, 6895};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_rhsxs(int k)
{
int vindex[12]={2747, 3086, 3473, 3860, 4247, 4634, 5021, 5408, 5795, 6182, 6569, 6896};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_yny(int k)
{
int vindex[12]={2751, 3094, 3481, 3868, 4255, 4642, 5029, 5416, 5803, 6190, 6577, 6900};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Gxx(int k)
{
int vindex[12]={2755, 3102, 3489, 3876, 4263, 4650, 5037, 5424, 5811, 6198, 6585, 6904};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Gxu(int k)
{
int vindex[12]={2791, 3138, 3525, 3912, 4299, 4686, 5073, 5460, 5847, 6234, 6621, 6940};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Guu(int k)
{
int vindex[12]={2797, 3144, 3531, 3918, 4305, 4692, 5079, 5466, 5853, 6240, 6627, 6946};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Rux(int k)
{
int vindex[12]={2798, 3145, 3532, 3919, 4306, 4693, 5080, 5467, 5854, 6241, 6628, 6947};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Vxx(int k)
{
int vindex[12]={2804, 3151, 3538, 3925, 4312, 4699, 5086, 5473, 5860, 6247, 6634, 6953};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_L(int k)
{
 return &mpc123_arr_t1[7069+k*1];
}

float *mpc123_get_Gx(int k)
{
int vindex[12]={2840, 3187, 3574, 3961, 4348, 4735, 5122, 5509, 5896, 6283, 6670, 6989};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Gu(int k)
{
int vindex[12]={2846, 3193, 3580, 3967, 4354, 4741, 5128, 5515, 5902, 6289, 6676, 6995};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Vx(int k)
{
int vindex[12]={2848, 3195, 3582, 3969, 4356, 4743, 5130, 5517, 5904, 6291, 6678, 6997};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_Ru(int k)
{
int vindex[12]={2847, 3194, 3581, 3968, 4355, 4742, 5129, 5516, 5903, 6290, 6677, 6996};
 return &mpc123_arr_t1[vindex[k]];
}

float *mpc123_get_debug_dgap()
{
return mpc123_debug_dgap;
}

float *mpc123_get_debug_phi()
{
return mpc123_debug_phi;
}

float *mpc123_get_debug_minphi()
{
return mpc123_debug_minphi;
}

float *mpc123_get_debug_norm_r0()
{
return mpc123_debug_norm_r0;
}

float *mpc123_get_debug_norm_r()
{
return mpc123_debug_norm_r;
}

float *mpc123_get_debug_norm_d()
{
return mpc123_debug_norm_d;
}

float *mpc123_get_debug_mu0()
{
return mpc123_debug_mu0;
}

float *mpc123_get_debug_mu()
{
return mpc123_debug_mu;
}

float *mpc123_get_debug_sigma()
{
return mpc123_debug_sigma;
}

float *mpc123_get_debug_mu_aff()
{
return mpc123_debug_mu_aff;
}

float *mpc123_get_debug_alpha_max()
{
return mpc123_debug_alpha_max;
}

float *mpc123_get_debug_mehrotra_alpha()
{
return mpc123_debug_mehrotra_alpha;
}
double *mpc123_get_time_max()
{
return &mpc123_time_max;
}

void mpc123_set_time_max(double tmax)
{
mpc123_time_max = tmax;
}


/* ###################################### */
/* Diese Funktion initialisiert den Timer */
/* ###################################### */
void mpc123_glqdocpip_timer_start()
{
#if defined(IP2GO_WIN)
  LARGE_INTEGER mpc123_tmp_counter, mpc123_tmp_frequency;
  QueryPerformanceFrequency(&mpc123_tmp_frequency);
  QueryPerformanceCounter(&mpc123_tmp_counter);
  mpc123_timer_start = (double) mpc123_tmp_counter.QuadPart/(double) mpc123_tmp_frequency.QuadPart;
#elif defined(IP2GO_DS1103)
  mpc123_timer_start = (double) ds1103_timebase_fltread();
#endif
}


/* ################################################### */
/* Diese Funktion gibt die Zeit seit Timerstart zurück */
/* ################################################### */
double mpc123_glqdocpip_timer_get()
{
#if defined(IP2GO_WIN)
  LARGE_INTEGER mpc123_tmp_counter, mpc123_tmp_frequency;
  QueryPerformanceFrequency(&mpc123_tmp_frequency);
  QueryPerformanceCounter(&mpc123_tmp_counter);
  return (double) mpc123_tmp_counter.QuadPart/(double) mpc123_tmp_frequency.QuadPart - mpc123_timer_start;
#elif defined(IP2GO_DS1103)
  return (double) ds1103_timebase_fltread()- mpc123_timer_start;
#endif
}

static void mpc123_v_copy_6(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc123_mv_sid21_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[1] += A[7] * b[1];
  out[3] += A[9] * b[1];
  out[0] += A[12] * b[2];
  out[2] += A[14] * b[2];
  out[1] += A[19] * b[3];
  out[3] += A[21] * b[3];
  return;
}

static void mpc123_mv_sid24_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_vsub_6(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  out[4] = a[4] - b[4];
  out[5] = a[5] - b[5];
  return;
}

static void mpc123_mtv_sid42_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[6] * b[0];
  out[1] += A[7] * b[1];
  out[0] += A[2] * b[2];
  out[1] += A[8] * b[2];
  out[2] += A[14] * b[2];
  out[3] += A[20] * b[2];
  out[0] += A[3] * b[3];
  out[1] += A[9] * b[3];
  out[2] += A[15] * b[3];
  out[3] += A[21] * b[3];
  out[5] += A[34] * b[4];
  return;
}

static void mpc123_mtv_sid51_sid15_4_6(float *A, float *b, float *out)
{

  out[5] += A[20] * b[0];
  out[5] += A[21] * b[1];
  return;
}

static void mpc123_v_copy_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc123_mtv_sid24_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_mv_sid27_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc123_mtv_sid45_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc123_mtv_sid54_sid15_4_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  return;
}

static void mpc123_v_copy_4(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc123_mv_sid30_sid18_4_4(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[5] * b[1];
  out[2] += A[10] * b[2];
  out[3] += A[15] * b[3];
  return;
}

static void mpc123_vsub_4(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  return;
}

static void mpc123_mv_sid51_sid2_4_6(float *A, float *b, float *out)
{

  out[0] += A[20] * b[5];
  out[1] += A[21] * b[5];
  return;
}

static void mpc123_mv_sid54_sid5_4_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  return;
}

static void mpc123_vadd_4(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  return;
}

static void mpc123_v_init0_4(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
  return;
}

static void mpc123_vv_elemult_8(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  out[4] = a[4] * b[4];
  out[5] = a[5] * b[5];
  out[6] = a[6] * b[6];
  out[7] = a[7] * b[7];
  return;
}

static void mpc123_mv_sid22_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[1] += A[7] * b[1];
  out[3] += A[9] * b[1];
  out[0] += A[12] * b[2];
  out[2] += A[14] * b[2];
  out[1] += A[19] * b[3];
  out[3] += A[21] * b[3];
  out[4] += A[28] * b[4];
  out[5] += A[29] * b[4];
  out[4] += A[34] * b[5];
  out[5] += A[35] * b[5];
  return;
}

static void mpc123_mv_sid25_sid5_6_1(float *A, float *b, float *out)
{

  out[4] += A[4] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc123_mtv_sid43_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[6] * b[0];
  out[1] += A[7] * b[1];
  out[0] += A[2] * b[2];
  out[1] += A[8] * b[2];
  out[2] += A[14] * b[2];
  out[3] += A[20] * b[2];
  out[0] += A[3] * b[3];
  out[1] += A[9] * b[3];
  out[2] += A[15] * b[3];
  out[3] += A[21] * b[3];
  out[5] += A[34] * b[4];
  return;
}

static void mpc123_mtv_sid52_sid16_8_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[16] * b[0];
  out[0] += A[1] * b[1];
  out[2] += A[17] * b[1];
  out[5] += A[42] * b[2];
  out[5] += A[43] * b[3];
  out[0] += A[4] * b[4];
  out[0] += A[5] * b[5];
  return;
}

static void mpc123_mtv_sid25_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[4] * b[4];
  out[0] += A[5] * b[5];
  return;
}

static void mpc123_mv_sid28_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc123_mtv_sid46_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc123_mtv_sid55_sid16_8_1(float *A, float *b, float *out)
{

  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  return;
}

static void mpc123_v_copy_8(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  out[6] = a[6];
  out[7] = a[7];
  return;
}

static void mpc123_mv_sid31_sid19_8_8(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[9] * b[1];
  out[2] += A[18] * b[2];
  out[3] += A[27] * b[3];
  out[4] += A[36] * b[4];
  out[5] += A[45] * b[5];
  out[6] += A[54] * b[6];
  out[7] += A[63] * b[7];
  return;
}

static void mpc123_vsub_8(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  out[4] = a[4] - b[4];
  out[5] = a[5] - b[5];
  out[6] = a[6] - b[6];
  out[7] = a[7] - b[7];
  return;
}

static void mpc123_mv_sid43_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[0] += A[6] * b[1];
  out[1] += A[7] * b[1];
  out[2] += A[8] * b[1];
  out[3] += A[9] * b[1];
  out[2] += A[14] * b[2];
  out[3] += A[15] * b[2];
  out[2] += A[20] * b[3];
  out[3] += A[21] * b[3];
  out[4] += A[34] * b[5];
  return;
}

static void mpc123_mv_sid46_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc123_mv_sid52_sid2_8_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[4] += A[4] * b[0];
  out[5] += A[5] * b[0];
  out[0] += A[16] * b[2];
  out[1] += A[17] * b[2];
  out[2] += A[42] * b[5];
  out[3] += A[43] * b[5];
  return;
}

static void mpc123_mv_sid55_sid5_8_1(float *A, float *b, float *out)
{

  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  return;
}

static void mpc123_vadd_8(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  out[4] = a[4] + b[4];
  out[5] = a[5] + b[5];
  out[6] = a[6] + b[6];
  out[7] = a[7] + b[7];
  return;
}

static void mpc123_v_init0_8(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
    a[4] =0;
    a[5] =0;
    a[6] =0;
    a[7] =0;
  return;
}

static void mpc123_vv_elemult_16(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  out[4] = a[4] * b[4];
  out[5] = a[5] * b[5];
  out[6] = a[6] * b[6];
  out[7] = a[7] * b[7];
  out[8] = a[8] * b[8];
  out[9] = a[9] * b[9];
  out[10] = a[10] * b[10];
  out[11] = a[11] * b[11];
  out[12] = a[12] * b[12];
  out[13] = a[13] * b[13];
  out[14] = a[14] * b[14];
  out[15] = a[15] * b[15];
  return;
}

static void mpc123_mv_sid23_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[1] += A[7] * b[1];
  out[3] += A[9] * b[1];
  out[0] += A[12] * b[2];
  out[2] += A[14] * b[2];
  out[1] += A[19] * b[3];
  out[3] += A[21] * b[3];
  return;
}

static void mpc123_mv_sid26_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_mtv_sid53_sid17_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[8] * b[0];
  out[0] += A[1] * b[1];
  out[2] += A[9] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  return;
}

static void mpc123_mtv_sid26_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_mv_sid29_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc123_mtv_sid56_sid17_4_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_mv_sid32_sid20_4_4(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[5] * b[1];
  out[2] += A[10] * b[2];
  out[3] += A[15] * b[3];
  return;
}

static void mpc123_mv_sid44_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[0] += A[6] * b[1];
  out[1] += A[7] * b[1];
  out[2] += A[8] * b[1];
  out[3] += A[9] * b[1];
  out[2] += A[14] * b[2];
  out[3] += A[15] * b[2];
  out[2] += A[20] * b[3];
  out[3] += A[21] * b[3];
  out[4] += A[34] * b[5];
  return;
}

static void mpc123_mv_sid47_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc123_mv_sid53_sid2_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[0] += A[8] * b[2];
  out[1] += A[9] * b[2];
  return;
}

static void mpc123_mv_sid56_sid5_4_1(float *A, float *b, float *out)
{

  return;
}

static void mpc123_vv_elediv_4(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  return;
}

static void mpc123_mv_4_4(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[0] += A[4] * b[1];
      out[1] += A[5] * b[1];
      out[2] += A[6] * b[1];
      out[3] += A[7] * b[1];
      out[0] += A[8] * b[2];
      out[1] += A[9] * b[2];
      out[2] += A[10] * b[2];
      out[3] += A[11] * b[2];
      out[0] += A[12] * b[3];
      out[1] += A[13] * b[3];
      out[2] += A[14] * b[3];
      out[3] += A[15] * b[3];
  return;
}

static void mpc123_v_init1_4(float *a)
{

    a[0] =1;
    a[1] =1;
    a[2] =1;
    a[3] =1;
  return;
}

static void mpc123_vv_elemult_4(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  return;
}

static void mpc123_vv_elediv_8(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  return;
}

static void mpc123_mv_8_8(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[4] += A[4] * b[0];
      out[5] += A[5] * b[0];
      out[6] += A[6] * b[0];
      out[7] += A[7] * b[0];
      out[0] += A[8] * b[1];
      out[1] += A[9] * b[1];
      out[2] += A[10] * b[1];
      out[3] += A[11] * b[1];
      out[4] += A[12] * b[1];
      out[5] += A[13] * b[1];
      out[6] += A[14] * b[1];
      out[7] += A[15] * b[1];
      out[0] += A[16] * b[2];
      out[1] += A[17] * b[2];
      out[2] += A[18] * b[2];
      out[3] += A[19] * b[2];
      out[4] += A[20] * b[2];
      out[5] += A[21] * b[2];
      out[6] += A[22] * b[2];
      out[7] += A[23] * b[2];
      out[0] += A[24] * b[3];
      out[1] += A[25] * b[3];
      out[2] += A[26] * b[3];
      out[3] += A[27] * b[3];
      out[4] += A[28] * b[3];
      out[5] += A[29] * b[3];
      out[6] += A[30] * b[3];
      out[7] += A[31] * b[3];
      out[0] += A[32] * b[4];
      out[1] += A[33] * b[4];
      out[2] += A[34] * b[4];
      out[3] += A[35] * b[4];
      out[4] += A[36] * b[4];
      out[5] += A[37] * b[4];
      out[6] += A[38] * b[4];
      out[7] += A[39] * b[4];
      out[0] += A[40] * b[5];
      out[1] += A[41] * b[5];
      out[2] += A[42] * b[5];
      out[3] += A[43] * b[5];
      out[4] += A[44] * b[5];
      out[5] += A[45] * b[5];
      out[6] += A[46] * b[5];
      out[7] += A[47] * b[5];
      out[0] += A[48] * b[6];
      out[1] += A[49] * b[6];
      out[2] += A[50] * b[6];
      out[3] += A[51] * b[6];
      out[4] += A[52] * b[6];
      out[5] += A[53] * b[6];
      out[6] += A[54] * b[6];
      out[7] += A[55] * b[6];
      out[0] += A[56] * b[7];
      out[1] += A[57] * b[7];
      out[2] += A[58] * b[7];
      out[3] += A[59] * b[7];
      out[4] += A[60] * b[7];
      out[5] += A[61] * b[7];
      out[6] += A[62] * b[7];
      out[7] += A[63] * b[7];
  return;
}

static void mpc123_v_init1_8(float *a)
{

    a[0] =1;
    a[1] =1;
    a[2] =1;
    a[3] =1;
    a[4] =1;
    a[5] =1;
    a[6] =1;
    a[7] =1;
  return;
}

static void mpc123_vv_elemult_1(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  return;
}

static void mpc123_sv_8(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  out[4] += a[0] * b[4];
  out[5] += a[0] * b[5];
  out[6] += a[0] * b[6];
  out[7] += a[0] * b[7];
  return;
}

static void mpc123_vadd_16(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  out[4] = a[4] + b[4];
  out[5] = a[5] + b[5];
  out[6] = a[6] + b[6];
  out[7] = a[7] + b[7];
  out[8] = a[8] + b[8];
  out[9] = a[9] + b[9];
  out[10] = a[10] + b[10];
  out[11] = a[11] + b[11];
  out[12] = a[12] + b[12];
  out[13] = a[13] + b[13];
  out[14] = a[14] + b[14];
  out[15] = a[15] + b[15];
  return;
}

static void mpc123_v_init1_16(float *a)
{

    a[0] =1;
    a[1] =1;
    a[2] =1;
    a[3] =1;
    a[4] =1;
    a[5] =1;
    a[6] =1;
    a[7] =1;
    a[8] =1;
    a[9] =1;
    a[10] =1;
    a[11] =1;
    a[12] =1;
    a[13] =1;
    a[14] =1;
    a[15] =1;
  return;
}

static void mpc123_v_init0_16(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
    a[4] =0;
    a[5] =0;
    a[6] =0;
    a[7] =0;
    a[8] =0;
    a[9] =0;
    a[10] =0;
    a[11] =0;
    a[12] =0;
    a[13] =0;
    a[14] =0;
    a[15] =0;
  return;
}

static void mpc123_sv_16(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  out[4] += a[0] * b[4];
  out[5] += a[0] * b[5];
  out[6] += a[0] * b[6];
  out[7] += a[0] * b[7];
  out[8] += a[0] * b[8];
  out[9] += a[0] * b[9];
  out[10] += a[0] * b[10];
  out[11] += a[0] * b[11];
  out[12] += a[0] * b[12];
  out[13] += a[0] * b[13];
  out[14] += a[0] * b[14];
  out[15] += a[0] * b[15];
  return;
}

static void mpc123_vsub_16(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  out[4] = a[4] - b[4];
  out[5] = a[5] - b[5];
  out[6] = a[6] - b[6];
  out[7] = a[7] - b[7];
  out[8] = a[8] - b[8];
  out[9] = a[9] - b[9];
  out[10] = a[10] - b[10];
  out[11] = a[11] - b[11];
  out[12] = a[12] - b[12];
  out[13] = a[13] - b[13];
  out[14] = a[14] - b[14];
  out[15] = a[15] - b[15];
  return;
}

static void mpc123_m_copy_6_6(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  out[6] = a[6];
  out[7] = a[7];
  out[8] = a[8];
  out[9] = a[9];
  out[10] = a[10];
  out[11] = a[11];
  out[12] = a[12];
  out[13] = a[13];
  out[14] = a[14];
  out[15] = a[15];
  out[16] = a[16];
  out[17] = a[17];
  out[18] = a[18];
  out[19] = a[19];
  out[20] = a[20];
  out[21] = a[21];
  out[22] = a[22];
  out[23] = a[23];
  out[24] = a[24];
  out[25] = a[25];
  out[26] = a[26];
  out[27] = a[27];
  out[28] = a[28];
  out[29] = a[29];
  out[30] = a[30];
  out[31] = a[31];
  out[32] = a[32];
  out[33] = a[33];
  out[34] = a[34];
  out[35] = a[35];
  return;
}

static void mpc123_m_copy_6_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc123_m_init0_6_4(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  a[6] =0;
  a[7] =0;
  a[8] =0;
  a[9] =0;
  a[10] =0;
  a[11] =0;
  a[12] =0;
  a[13] =0;
  a[14] =0;
  a[15] =0;
  a[16] =0;
  a[17] =0;
  a[18] =0;
  a[19] =0;
  a[20] =0;
  a[21] =0;
  a[22] =0;
  a[23] =0;
  return;
}

static void mpc123_mtd_sid53_sid17_4_6(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[2] += A[8] * B[0];
      out[6] += A[1] * B[1];
      out[8] += A[9] * B[1];
      out[12] += A[2] * B[2];
      out[18] += A[3] * B[3];
  return;
}

static void mpc123_mm_y_sid14_sid53_6_4_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[14] += A[2] * B[8];
out[14] += A[8] * B[9];
out[15] += A[3] * B[8];
out[15] += A[9] * B[9];
out[16] += A[4] * B[8];
out[16] += A[10] * B[9];
out[17] += A[5] * B[8];
out[17] += A[11] * B[9];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_mm_sid14_sid56_6_4_1(float *A, float *B, float *out)
{

  return;
}

static void mpc123_m_copy_1_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc123_m_init0_1_4(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  return;
}

static void mpc123_mtd_sid56_sid17_4_1(float *A, float *B, float *out)
{

  return;
}

static void mpc123_mm_1_4_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
  return;
}

static void mpc123_mtr_6_1(float *A, float *out)
{

  out[0] = A[0];
  out[1] = A[1];
  out[2] = A[2];
  out[3] = A[3];
  out[4] = A[4];
  out[5] = A[5];
  return;
}

static void mpc123_chol_factor_1(float *a, float *out)
{
  if(a[0] == 0){
    mpc123_termcode = 8;
    mpc123_error_line = __LINE__;
    return;
  }
  out[0] = 1/a[0];
  return;
}

static void mpc123_chol_solve_1_6(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<6; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc123_m_init0_6_6(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  a[6] =0;
  a[7] =0;
  a[8] =0;
  a[9] =0;
  a[10] =0;
  a[11] =0;
  a[12] =0;
  a[13] =0;
  a[14] =0;
  a[15] =0;
  a[16] =0;
  a[17] =0;
  a[18] =0;
  a[19] =0;
  a[20] =0;
  a[21] =0;
  a[22] =0;
  a[23] =0;
  a[24] =0;
  a[25] =0;
  a[26] =0;
  a[27] =0;
  a[28] =0;
  a[29] =0;
  a[30] =0;
  a[31] =0;
  a[32] =0;
  a[33] =0;
  a[34] =0;
  a[35] =0;
  return;
}

static void mpc123_mm_y_6_1_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[7] += A[1] * B[1];
out[8] += A[2] * B[1];
out[9] += A[3] * B[1];
out[10] += A[4] * B[1];
out[11] += A[5] * B[1];
out[14] += A[2] * B[2];
out[15] += A[3] * B[2];
out[16] += A[4] * B[2];
out[17] += A[5] * B[2];
out[21] += A[3] * B[3];
out[22] += A[4] * B[3];
out[23] += A[5] * B[3];
out[28] += A[4] * B[4];
out[29] += A[5] * B[4];
out[35] += A[5] * B[5];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_msub_6_6(float *A, float *B, float *out)
{

  out[0] = A[0] - B[0];
  out[1] = A[1] - B[1];
  out[2] = A[2] - B[2];
  out[3] = A[3] - B[3];
  out[4] = A[4] - B[4];
  out[5] = A[5] - B[5];
  out[6] = A[6] - B[6];
  out[7] = A[7] - B[7];
  out[8] = A[8] - B[8];
  out[9] = A[9] - B[9];
  out[10] = A[10] - B[10];
  out[11] = A[11] - B[11];
  out[12] = A[12] - B[12];
  out[13] = A[13] - B[13];
  out[14] = A[14] - B[14];
  out[15] = A[15] - B[15];
  out[16] = A[16] - B[16];
  out[17] = A[17] - B[17];
  out[18] = A[18] - B[18];
  out[19] = A[19] - B[19];
  out[20] = A[20] - B[20];
  out[21] = A[21] - B[21];
  out[22] = A[22] - B[22];
  out[23] = A[23] - B[23];
  out[24] = A[24] - B[24];
  out[25] = A[25] - B[25];
  out[26] = A[26] - B[26];
  out[27] = A[27] - B[27];
  out[28] = A[28] - B[28];
  out[29] = A[29] - B[29];
  out[30] = A[30] - B[30];
  out[31] = A[31] - B[31];
  out[32] = A[32] - B[32];
  out[33] = A[33] - B[33];
  out[34] = A[34] - B[34];
  out[35] = A[35] - B[35];
  return;
}

static void mpc123_mtm_sid43_sid1_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[1] += A[6] * B[0];
out[1] += A[7] * B[1];
out[1] += A[8] * B[2];
out[1] += A[9] * B[3];
out[2] += A[14] * B[2];
out[2] += A[15] * B[3];
out[3] += A[20] * B[2];
out[3] += A[21] * B[3];
out[5] += A[34] * B[4];
out[6] += A[0] * B[6];
out[6] += A[2] * B[8];
out[6] += A[3] * B[9];
out[7] += A[6] * B[6];
out[7] += A[7] * B[7];
out[7] += A[8] * B[8];
out[7] += A[9] * B[9];
out[8] += A[14] * B[8];
out[8] += A[15] * B[9];
out[9] += A[20] * B[8];
out[9] += A[21] * B[9];
out[11] += A[34] * B[10];
out[12] += A[0] * B[12];
out[12] += A[2] * B[14];
out[12] += A[3] * B[15];
out[13] += A[6] * B[12];
out[13] += A[7] * B[13];
out[13] += A[8] * B[14];
out[13] += A[9] * B[15];
out[14] += A[14] * B[14];
out[14] += A[15] * B[15];
out[15] += A[20] * B[14];
out[15] += A[21] * B[15];
out[17] += A[34] * B[16];
out[18] += A[0] * B[18];
out[18] += A[2] * B[20];
out[18] += A[3] * B[21];
out[19] += A[6] * B[18];
out[19] += A[7] * B[19];
out[19] += A[8] * B[20];
out[19] += A[9] * B[21];
out[20] += A[14] * B[20];
out[20] += A[15] * B[21];
out[21] += A[20] * B[20];
out[21] += A[21] * B[21];
out[23] += A[34] * B[22];
out[24] += A[0] * B[24];
out[24] += A[2] * B[26];
out[24] += A[3] * B[27];
out[25] += A[6] * B[24];
out[25] += A[7] * B[25];
out[25] += A[8] * B[26];
out[25] += A[9] * B[27];
out[26] += A[14] * B[26];
out[26] += A[15] * B[27];
out[27] += A[20] * B[26];
out[27] += A[21] * B[27];
out[29] += A[34] * B[28];
out[30] += A[0] * B[30];
out[30] += A[2] * B[32];
out[30] += A[3] * B[33];
out[31] += A[6] * B[30];
out[31] += A[7] * B[31];
out[31] += A[8] * B[32];
out[31] += A[9] * B[33];
out[32] += A[14] * B[32];
out[32] += A[15] * B[33];
out[33] += A[20] * B[32];
out[33] += A[21] * B[33];
out[35] += A[34] * B[34];
  return;
}

static void mpc123_mm_y_sid1_sid43_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[1] += A[1] * B[0];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[2] += A[2] * B[0];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[3] += A[3] * B[0];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[4] += A[4] * B[0];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[5] += A[5] * B[0];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[7] += A[1] * B[6];
out[7] += A[7] * B[7];
out[7] += A[13] * B[8];
out[7] += A[19] * B[9];
out[8] += A[2] * B[6];
out[8] += A[8] * B[7];
out[8] += A[14] * B[8];
out[8] += A[20] * B[9];
out[9] += A[3] * B[6];
out[9] += A[9] * B[7];
out[9] += A[15] * B[8];
out[9] += A[21] * B[9];
out[10] += A[4] * B[6];
out[10] += A[10] * B[7];
out[10] += A[16] * B[8];
out[10] += A[22] * B[9];
out[11] += A[5] * B[6];
out[11] += A[11] * B[7];
out[11] += A[17] * B[8];
out[11] += A[23] * B[9];
out[14] += A[14] * B[14];
out[14] += A[20] * B[15];
out[15] += A[15] * B[14];
out[15] += A[21] * B[15];
out[16] += A[16] * B[14];
out[16] += A[22] * B[15];
out[17] += A[17] * B[14];
out[17] += A[23] * B[15];
out[21] += A[15] * B[20];
out[21] += A[21] * B[21];
out[22] += A[16] * B[20];
out[22] += A[22] * B[21];
out[23] += A[17] * B[20];
out[23] += A[23] * B[21];
out[35] += A[29] * B[34];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_mm_sid1_sid46_6_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[0] += A[6] * B[1];
out[1] += A[7] * B[1];
out[2] += A[8] * B[1];
out[3] += A[9] * B[1];
out[4] += A[10] * B[1];
out[5] += A[11] * B[1];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[0] += A[30] * B[5];
out[1] += A[31] * B[5];
out[2] += A[32] * B[5];
out[3] += A[33] * B[5];
out[4] += A[34] * B[5];
out[5] += A[35] * B[5];
  return;
}

static void mpc123_m_init0_6_8(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  a[6] =0;
  a[7] =0;
  a[8] =0;
  a[9] =0;
  a[10] =0;
  a[11] =0;
  a[12] =0;
  a[13] =0;
  a[14] =0;
  a[15] =0;
  a[16] =0;
  a[17] =0;
  a[18] =0;
  a[19] =0;
  a[20] =0;
  a[21] =0;
  a[22] =0;
  a[23] =0;
  a[24] =0;
  a[25] =0;
  a[26] =0;
  a[27] =0;
  a[28] =0;
  a[29] =0;
  a[30] =0;
  a[31] =0;
  a[32] =0;
  a[33] =0;
  a[34] =0;
  a[35] =0;
  a[36] =0;
  a[37] =0;
  a[38] =0;
  a[39] =0;
  a[40] =0;
  a[41] =0;
  a[42] =0;
  a[43] =0;
  a[44] =0;
  a[45] =0;
  a[46] =0;
  a[47] =0;
  return;
}

static void mpc123_mtd_sid52_sid16_8_6(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[2] += A[16] * B[0];
      out[6] += A[1] * B[1];
      out[8] += A[17] * B[1];
      out[17] += A[42] * B[2];
      out[23] += A[43] * B[3];
      out[24] += A[4] * B[4];
      out[30] += A[5] * B[5];
  return;
}

static void mpc123_mm_y_sid13_sid52_6_8_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[0] += A[24] * B[4];
out[0] += A[30] * B[5];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[1] += A[25] * B[4];
out[1] += A[31] * B[5];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[2] += A[26] * B[4];
out[2] += A[32] * B[5];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[3] += A[27] * B[4];
out[3] += A[33] * B[5];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[4] += A[28] * B[4];
out[4] += A[34] * B[5];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[5] += A[29] * B[4];
out[5] += A[35] * B[5];
out[14] += A[2] * B[16];
out[14] += A[8] * B[17];
out[15] += A[3] * B[16];
out[15] += A[9] * B[17];
out[16] += A[4] * B[16];
out[16] += A[10] * B[17];
out[17] += A[5] * B[16];
out[17] += A[11] * B[17];
out[35] += A[17] * B[42];
out[35] += A[23] * B[43];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_mm_sid13_sid55_6_8_1(float *A, float *B, float *out)
{

out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[0] += A[36] * B[6];
out[1] += A[37] * B[6];
out[2] += A[38] * B[6];
out[3] += A[39] * B[6];
out[4] += A[40] * B[6];
out[5] += A[41] * B[6];
out[0] += A[42] * B[7];
out[1] += A[43] * B[7];
out[2] += A[44] * B[7];
out[3] += A[45] * B[7];
out[4] += A[46] * B[7];
out[5] += A[47] * B[7];
  return;
}

static void mpc123_m_init0_1_6(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  return;
}

static void mpc123_mtm_sid46_sid1_6_1_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
out[1] += A[0] * B[6];
out[1] += A[1] * B[7];
out[1] += A[2] * B[8];
out[1] += A[3] * B[9];
out[1] += A[5] * B[11];
out[2] += A[0] * B[12];
out[2] += A[1] * B[13];
out[2] += A[2] * B[14];
out[2] += A[3] * B[15];
out[2] += A[5] * B[17];
out[3] += A[0] * B[18];
out[3] += A[1] * B[19];
out[3] += A[2] * B[20];
out[3] += A[3] * B[21];
out[3] += A[5] * B[23];
out[4] += A[0] * B[24];
out[4] += A[1] * B[25];
out[4] += A[2] * B[26];
out[4] += A[3] * B[27];
out[4] += A[5] * B[29];
out[5] += A[0] * B[30];
out[5] += A[1] * B[31];
out[5] += A[2] * B[32];
out[5] += A[3] * B[33];
out[5] += A[5] * B[35];
  return;
}

static void mpc123_mm_sid8_sid46_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc123_m_init0_1_8(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  a[6] =0;
  a[7] =0;
  return;
}

static void mpc123_mtd_sid55_sid16_8_1(float *A, float *B, float *out)
{

      out[2] += A[2] * B[2];
      out[3] += A[3] * B[3];
      out[6] += A[6] * B[6];
      out[7] += A[7] * B[7];
  return;
}

static void mpc123_mm_1_8_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[4] * B[4];
out[0] += A[5] * B[5];
out[0] += A[6] * B[6];
out[0] += A[7] * B[7];
  return;
}

static void mpc123_mtm_sid42_sid1_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[1] += A[6] * B[0];
out[1] += A[7] * B[1];
out[1] += A[8] * B[2];
out[1] += A[9] * B[3];
out[2] += A[14] * B[2];
out[2] += A[15] * B[3];
out[3] += A[20] * B[2];
out[3] += A[21] * B[3];
out[5] += A[34] * B[4];
out[6] += A[0] * B[6];
out[6] += A[2] * B[8];
out[6] += A[3] * B[9];
out[7] += A[6] * B[6];
out[7] += A[7] * B[7];
out[7] += A[8] * B[8];
out[7] += A[9] * B[9];
out[8] += A[14] * B[8];
out[8] += A[15] * B[9];
out[9] += A[20] * B[8];
out[9] += A[21] * B[9];
out[11] += A[34] * B[10];
out[12] += A[0] * B[12];
out[12] += A[2] * B[14];
out[12] += A[3] * B[15];
out[13] += A[6] * B[12];
out[13] += A[7] * B[13];
out[13] += A[8] * B[14];
out[13] += A[9] * B[15];
out[14] += A[14] * B[14];
out[14] += A[15] * B[15];
out[15] += A[20] * B[14];
out[15] += A[21] * B[15];
out[17] += A[34] * B[16];
out[18] += A[0] * B[18];
out[18] += A[2] * B[20];
out[18] += A[3] * B[21];
out[19] += A[6] * B[18];
out[19] += A[7] * B[19];
out[19] += A[8] * B[20];
out[19] += A[9] * B[21];
out[20] += A[14] * B[20];
out[20] += A[15] * B[21];
out[21] += A[20] * B[20];
out[21] += A[21] * B[21];
out[23] += A[34] * B[22];
out[24] += A[0] * B[24];
out[24] += A[2] * B[26];
out[24] += A[3] * B[27];
out[25] += A[6] * B[24];
out[25] += A[7] * B[25];
out[25] += A[8] * B[26];
out[25] += A[9] * B[27];
out[26] += A[14] * B[26];
out[26] += A[15] * B[27];
out[27] += A[20] * B[26];
out[27] += A[21] * B[27];
out[29] += A[34] * B[28];
out[30] += A[0] * B[30];
out[30] += A[2] * B[32];
out[30] += A[3] * B[33];
out[31] += A[6] * B[30];
out[31] += A[7] * B[31];
out[31] += A[8] * B[32];
out[31] += A[9] * B[33];
out[32] += A[14] * B[32];
out[32] += A[15] * B[33];
out[33] += A[20] * B[32];
out[33] += A[21] * B[33];
out[35] += A[34] * B[34];
  return;
}

static void mpc123_mm_y_sid1_sid42_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[1] += A[1] * B[0];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[2] += A[2] * B[0];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[3] += A[3] * B[0];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[4] += A[4] * B[0];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[5] += A[5] * B[0];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[7] += A[1] * B[6];
out[7] += A[7] * B[7];
out[7] += A[13] * B[8];
out[7] += A[19] * B[9];
out[8] += A[2] * B[6];
out[8] += A[8] * B[7];
out[8] += A[14] * B[8];
out[8] += A[20] * B[9];
out[9] += A[3] * B[6];
out[9] += A[9] * B[7];
out[9] += A[15] * B[8];
out[9] += A[21] * B[9];
out[10] += A[4] * B[6];
out[10] += A[10] * B[7];
out[10] += A[16] * B[8];
out[10] += A[22] * B[9];
out[11] += A[5] * B[6];
out[11] += A[11] * B[7];
out[11] += A[17] * B[8];
out[11] += A[23] * B[9];
out[14] += A[14] * B[14];
out[14] += A[20] * B[15];
out[15] += A[15] * B[14];
out[15] += A[21] * B[15];
out[16] += A[16] * B[14];
out[16] += A[22] * B[15];
out[17] += A[17] * B[14];
out[17] += A[23] * B[15];
out[21] += A[15] * B[20];
out[21] += A[21] * B[21];
out[22] += A[16] * B[20];
out[22] += A[22] * B[21];
out[23] += A[17] * B[20];
out[23] += A[23] * B[21];
out[35] += A[29] * B[34];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_mm_sid1_sid45_6_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[0] += A[6] * B[1];
out[1] += A[7] * B[1];
out[2] += A[8] * B[1];
out[3] += A[9] * B[1];
out[4] += A[10] * B[1];
out[5] += A[11] * B[1];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[0] += A[30] * B[5];
out[1] += A[31] * B[5];
out[2] += A[32] * B[5];
out[3] += A[33] * B[5];
out[4] += A[34] * B[5];
out[5] += A[35] * B[5];
  return;
}

static void mpc123_mtd_sid51_sid15_4_6(float *A, float *B, float *out)
{

      out[5] += A[20] * B[0];
      out[11] += A[21] * B[1];
  return;
}

static void mpc123_mm_y_sid12_sid51_6_4_6(float *A, float *B, float *out)
{

out[35] += A[5] * B[20];
out[35] += A[11] * B[21];
out[6] = out[1];
out[12] = out[2];
out[13] = out[8];
out[18] = out[3];
out[19] = out[9];
out[20] = out[15];
out[24] = out[4];
out[25] = out[10];
out[26] = out[16];
out[27] = out[22];
out[30] = out[5];
out[31] = out[11];
out[32] = out[17];
out[33] = out[23];
out[34] = out[29];
  return;
}

static void mpc123_mm_sid12_sid54_6_4_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[0] += A[6] * B[1];
out[1] += A[7] * B[1];
out[2] += A[8] * B[1];
out[3] += A[9] * B[1];
out[4] += A[10] * B[1];
out[5] += A[11] * B[1];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
  return;
}

static void mpc123_mtm_sid45_sid1_6_1_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
out[1] += A[0] * B[6];
out[1] += A[1] * B[7];
out[1] += A[2] * B[8];
out[1] += A[3] * B[9];
out[1] += A[5] * B[11];
out[2] += A[0] * B[12];
out[2] += A[1] * B[13];
out[2] += A[2] * B[14];
out[2] += A[3] * B[15];
out[2] += A[5] * B[17];
out[3] += A[0] * B[18];
out[3] += A[1] * B[19];
out[3] += A[2] * B[20];
out[3] += A[3] * B[21];
out[3] += A[5] * B[23];
out[4] += A[0] * B[24];
out[4] += A[1] * B[25];
out[4] += A[2] * B[26];
out[4] += A[3] * B[27];
out[4] += A[5] * B[29];
out[5] += A[0] * B[30];
out[5] += A[1] * B[31];
out[5] += A[2] * B[32];
out[5] += A[3] * B[33];
out[5] += A[5] * B[35];
  return;
}

static void mpc123_mm_sid8_sid45_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc123_mtd_sid54_sid15_4_1(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[1] += A[1] * B[1];
      out[2] += A[2] * B[2];
      out[3] += A[3] * B[3];
  return;
}

static void mpc123_chol_solve_1_1(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<1; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc123_v_init0_6(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
    a[4] =0;
    a[5] =0;
  return;
}

static void mpc123_mv_6_1(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[4] += A[4] * b[0];
      out[5] += A[5] * b[0];
  return;
}

static void mpc123_mv_6_6(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[4] += A[4] * b[0];
      out[5] += A[5] * b[0];
      out[0] += A[6] * b[1];
      out[1] += A[7] * b[1];
      out[2] += A[8] * b[1];
      out[3] += A[9] * b[1];
      out[4] += A[10] * b[1];
      out[5] += A[11] * b[1];
      out[0] += A[12] * b[2];
      out[1] += A[13] * b[2];
      out[2] += A[14] * b[2];
      out[3] += A[15] * b[2];
      out[4] += A[16] * b[2];
      out[5] += A[17] * b[2];
      out[0] += A[18] * b[3];
      out[1] += A[19] * b[3];
      out[2] += A[20] * b[3];
      out[3] += A[21] * b[3];
      out[4] += A[22] * b[3];
      out[5] += A[23] * b[3];
      out[0] += A[24] * b[4];
      out[1] += A[25] * b[4];
      out[2] += A[26] * b[4];
      out[3] += A[27] * b[4];
      out[4] += A[28] * b[4];
      out[5] += A[29] * b[4];
      out[0] += A[30] * b[5];
      out[1] += A[31] * b[5];
      out[2] += A[32] * b[5];
      out[3] += A[33] * b[5];
      out[4] += A[34] * b[5];
      out[5] += A[35] * b[5];
  return;
}

static void mpc123_mv_1_6(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[0] += A[1] * b[1];
      out[0] += A[2] * b[2];
      out[0] += A[3] * b[3];
      out[0] += A[4] * b[4];
      out[0] += A[5] * b[5];
  return;
}

static void mpc123_v_turnsign_1(float *a, float *out)
{

    out[0] = -a[0];
  return;
}

static void mpc123_mv_sid42_sid2_6_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[0] += A[6] * b[1];
  out[1] += A[7] * b[1];
  out[2] += A[8] * b[1];
  out[3] += A[9] * b[1];
  out[2] += A[14] * b[2];
  out[3] += A[15] * b[2];
  out[2] += A[20] * b[3];
  out[3] += A[21] * b[3];
  out[4] += A[34] * b[5];
  return;
}

static void mpc123_mv_sid45_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc123_m_copy_4_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc123_v_turnsign_8(float *a, float *out)
{

    out[0] = -a[0];
    out[1] = -a[1];
    out[2] = -a[2];
    out[3] = -a[3];
    out[4] = -a[4];
    out[5] = -a[5];
    out[6] = -a[6];
    out[7] = -a[7];
  return;
}

static void mpc123_m_copy_8_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  out[6] = a[6];
  out[7] = a[7];
  return;
}

static void mpc123_vv_elediv_16(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  if(b[8] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[8] = a[8] / b[8];
  if(b[9] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[9] = a[9] / b[9];
  if(b[10] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[10] = a[10] / b[10];
  if(b[11] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[11] = a[11] / b[11];
  if(b[12] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[12] = a[12] / b[12];
  if(b[13] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[13] = a[13] / b[13];
  if(b[14] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[14] = a[14] / b[14];
  if(b[15] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[15] = a[15] / b[15];
  return;
}

static void mpc123_v_turnsign_16(float *a, float *out)
{

    out[0] = -a[0];
    out[1] = -a[1];
    out[2] = -a[2];
    out[3] = -a[3];
    out[4] = -a[4];
    out[5] = -a[5];
    out[6] = -a[6];
    out[7] = -a[7];
    out[8] = -a[8];
    out[9] = -a[9];
    out[10] = -a[10];
    out[11] = -a[11];
    out[12] = -a[12];
    out[13] = -a[13];
    out[14] = -a[14];
    out[15] = -a[15];
  return;
}

static void mpc123_v_copy_16(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  out[6] = a[6];
  out[7] = a[7];
  out[8] = a[8];
  out[9] = a[9];
  out[10] = a[10];
  out[11] = a[11];
  out[12] = a[12];
  out[13] = a[13];
  out[14] = a[14];
  out[15] = a[15];
  return;
}

static void mpc123_vadd_6(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  out[4] = a[4] + b[4];
  out[5] = a[5] + b[5];
  return;
}

static void mpc123_vadd_1(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  return;
}

static void mpc123_v_init0_1(float *a)
{

    a[0] =0;
  return;
}

static void mpc123_vtv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  out[0] += a[4] * b[4];
  out[0] += a[5] * b[5];
  return;
}

static void mpc123_vtv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc123_vtv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  return;
}

static void mpc123_vsub_1(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  return;
}

static void mpc123_vtv_8(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  out[0] += a[4] * b[4];
  out[0] += a[5] * b[5];
  out[0] += a[6] * b[6];
  out[0] += a[7] * b[7];
  return;
}

static void mpc123_vtv_16(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  out[0] += a[4] * b[4];
  out[0] += a[5] * b[5];
  out[0] += a[6] * b[6];
  out[0] += a[7] * b[7];
  out[0] += a[8] * b[8];
  out[0] += a[9] * b[9];
  out[0] += a[10] * b[10];
  out[0] += a[11] * b[11];
  out[0] += a[12] * b[12];
  out[0] += a[13] * b[13];
  out[0] += a[14] * b[14];
  out[0] += a[15] * b[15];
  return;
}

static void mpc123_vv_elediv_1(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc123_termcode = 8; mpc123_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  return;
}

static void mpc123_min(float *a, float *b, float *out)
{

  if  (a[0] < b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc123_v_init1_1(float *a)
{

    a[0] =1;
  return;
}

static void mpc123_max(float *a, float *b, float *out)
{

  if  (a[0] > b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc123_sv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  out[4] += a[0] * b[4];
  out[5] += a[0] * b[5];
  return;
}

static void mpc123_sv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc123_sv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  return;
}

static void mpc123_norm_inf_6_6(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  if (A[16] > out[0]) out[0] = A[16];
  if (-A[16] > out[0]) out[0] = A[16];
  if (A[17] > out[0]) out[0] = A[17];
  if (-A[17] > out[0]) out[0] = A[17];
  if (A[18] > out[0]) out[0] = A[18];
  if (-A[18] > out[0]) out[0] = A[18];
  if (A[19] > out[0]) out[0] = A[19];
  if (-A[19] > out[0]) out[0] = A[19];
  if (A[20] > out[0]) out[0] = A[20];
  if (-A[20] > out[0]) out[0] = A[20];
  if (A[21] > out[0]) out[0] = A[21];
  if (-A[21] > out[0]) out[0] = A[21];
  if (A[22] > out[0]) out[0] = A[22];
  if (-A[22] > out[0]) out[0] = A[22];
  if (A[23] > out[0]) out[0] = A[23];
  if (-A[23] > out[0]) out[0] = A[23];
  if (A[24] > out[0]) out[0] = A[24];
  if (-A[24] > out[0]) out[0] = A[24];
  if (A[25] > out[0]) out[0] = A[25];
  if (-A[25] > out[0]) out[0] = A[25];
  if (A[26] > out[0]) out[0] = A[26];
  if (-A[26] > out[0]) out[0] = A[26];
  if (A[27] > out[0]) out[0] = A[27];
  if (-A[27] > out[0]) out[0] = A[27];
  if (A[28] > out[0]) out[0] = A[28];
  if (-A[28] > out[0]) out[0] = A[28];
  if (A[29] > out[0]) out[0] = A[29];
  if (-A[29] > out[0]) out[0] = A[29];
  if (A[30] > out[0]) out[0] = A[30];
  if (-A[30] > out[0]) out[0] = A[30];
  if (A[31] > out[0]) out[0] = A[31];
  if (-A[31] > out[0]) out[0] = A[31];
  if (A[32] > out[0]) out[0] = A[32];
  if (-A[32] > out[0]) out[0] = A[32];
  if (A[33] > out[0]) out[0] = A[33];
  if (-A[33] > out[0]) out[0] = A[33];
  if (A[34] > out[0]) out[0] = A[34];
  if (-A[34] > out[0]) out[0] = A[34];
  if (A[35] > out[0]) out[0] = A[35];
  if (-A[35] > out[0]) out[0] = A[35];
  return;
}

static void mpc123_norm_inf_6_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  return;
}

static void mpc123_norm_inf_1_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  return;
}

static void mpc123_norm_inf_4_4(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  return;
}

static void mpc123_norm_inf_4_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  return;
}

static void mpc123_norm_inf_4_6(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  if (A[16] > out[0]) out[0] = A[16];
  if (-A[16] > out[0]) out[0] = A[16];
  if (A[17] > out[0]) out[0] = A[17];
  if (-A[17] > out[0]) out[0] = A[17];
  if (A[18] > out[0]) out[0] = A[18];
  if (-A[18] > out[0]) out[0] = A[18];
  if (A[19] > out[0]) out[0] = A[19];
  if (-A[19] > out[0]) out[0] = A[19];
  if (A[20] > out[0]) out[0] = A[20];
  if (-A[20] > out[0]) out[0] = A[20];
  if (A[21] > out[0]) out[0] = A[21];
  if (-A[21] > out[0]) out[0] = A[21];
  if (A[22] > out[0]) out[0] = A[22];
  if (-A[22] > out[0]) out[0] = A[22];
  if (A[23] > out[0]) out[0] = A[23];
  if (-A[23] > out[0]) out[0] = A[23];
  return;
}

static void mpc123_norm_inf_8_8(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  if (A[16] > out[0]) out[0] = A[16];
  if (-A[16] > out[0]) out[0] = A[16];
  if (A[17] > out[0]) out[0] = A[17];
  if (-A[17] > out[0]) out[0] = A[17];
  if (A[18] > out[0]) out[0] = A[18];
  if (-A[18] > out[0]) out[0] = A[18];
  if (A[19] > out[0]) out[0] = A[19];
  if (-A[19] > out[0]) out[0] = A[19];
  if (A[20] > out[0]) out[0] = A[20];
  if (-A[20] > out[0]) out[0] = A[20];
  if (A[21] > out[0]) out[0] = A[21];
  if (-A[21] > out[0]) out[0] = A[21];
  if (A[22] > out[0]) out[0] = A[22];
  if (-A[22] > out[0]) out[0] = A[22];
  if (A[23] > out[0]) out[0] = A[23];
  if (-A[23] > out[0]) out[0] = A[23];
  if (A[24] > out[0]) out[0] = A[24];
  if (-A[24] > out[0]) out[0] = A[24];
  if (A[25] > out[0]) out[0] = A[25];
  if (-A[25] > out[0]) out[0] = A[25];
  if (A[26] > out[0]) out[0] = A[26];
  if (-A[26] > out[0]) out[0] = A[26];
  if (A[27] > out[0]) out[0] = A[27];
  if (-A[27] > out[0]) out[0] = A[27];
  if (A[28] > out[0]) out[0] = A[28];
  if (-A[28] > out[0]) out[0] = A[28];
  if (A[29] > out[0]) out[0] = A[29];
  if (-A[29] > out[0]) out[0] = A[29];
  if (A[30] > out[0]) out[0] = A[30];
  if (-A[30] > out[0]) out[0] = A[30];
  if (A[31] > out[0]) out[0] = A[31];
  if (-A[31] > out[0]) out[0] = A[31];
  if (A[32] > out[0]) out[0] = A[32];
  if (-A[32] > out[0]) out[0] = A[32];
  if (A[33] > out[0]) out[0] = A[33];
  if (-A[33] > out[0]) out[0] = A[33];
  if (A[34] > out[0]) out[0] = A[34];
  if (-A[34] > out[0]) out[0] = A[34];
  if (A[35] > out[0]) out[0] = A[35];
  if (-A[35] > out[0]) out[0] = A[35];
  if (A[36] > out[0]) out[0] = A[36];
  if (-A[36] > out[0]) out[0] = A[36];
  if (A[37] > out[0]) out[0] = A[37];
  if (-A[37] > out[0]) out[0] = A[37];
  if (A[38] > out[0]) out[0] = A[38];
  if (-A[38] > out[0]) out[0] = A[38];
  if (A[39] > out[0]) out[0] = A[39];
  if (-A[39] > out[0]) out[0] = A[39];
  if (A[40] > out[0]) out[0] = A[40];
  if (-A[40] > out[0]) out[0] = A[40];
  if (A[41] > out[0]) out[0] = A[41];
  if (-A[41] > out[0]) out[0] = A[41];
  if (A[42] > out[0]) out[0] = A[42];
  if (-A[42] > out[0]) out[0] = A[42];
  if (A[43] > out[0]) out[0] = A[43];
  if (-A[43] > out[0]) out[0] = A[43];
  if (A[44] > out[0]) out[0] = A[44];
  if (-A[44] > out[0]) out[0] = A[44];
  if (A[45] > out[0]) out[0] = A[45];
  if (-A[45] > out[0]) out[0] = A[45];
  if (A[46] > out[0]) out[0] = A[46];
  if (-A[46] > out[0]) out[0] = A[46];
  if (A[47] > out[0]) out[0] = A[47];
  if (-A[47] > out[0]) out[0] = A[47];
  if (A[48] > out[0]) out[0] = A[48];
  if (-A[48] > out[0]) out[0] = A[48];
  if (A[49] > out[0]) out[0] = A[49];
  if (-A[49] > out[0]) out[0] = A[49];
  if (A[50] > out[0]) out[0] = A[50];
  if (-A[50] > out[0]) out[0] = A[50];
  if (A[51] > out[0]) out[0] = A[51];
  if (-A[51] > out[0]) out[0] = A[51];
  if (A[52] > out[0]) out[0] = A[52];
  if (-A[52] > out[0]) out[0] = A[52];
  if (A[53] > out[0]) out[0] = A[53];
  if (-A[53] > out[0]) out[0] = A[53];
  if (A[54] > out[0]) out[0] = A[54];
  if (-A[54] > out[0]) out[0] = A[54];
  if (A[55] > out[0]) out[0] = A[55];
  if (-A[55] > out[0]) out[0] = A[55];
  if (A[56] > out[0]) out[0] = A[56];
  if (-A[56] > out[0]) out[0] = A[56];
  if (A[57] > out[0]) out[0] = A[57];
  if (-A[57] > out[0]) out[0] = A[57];
  if (A[58] > out[0]) out[0] = A[58];
  if (-A[58] > out[0]) out[0] = A[58];
  if (A[59] > out[0]) out[0] = A[59];
  if (-A[59] > out[0]) out[0] = A[59];
  if (A[60] > out[0]) out[0] = A[60];
  if (-A[60] > out[0]) out[0] = A[60];
  if (A[61] > out[0]) out[0] = A[61];
  if (-A[61] > out[0]) out[0] = A[61];
  if (A[62] > out[0]) out[0] = A[62];
  if (-A[62] > out[0]) out[0] = A[62];
  if (A[63] > out[0]) out[0] = A[63];
  if (-A[63] > out[0]) out[0] = A[63];
  return;
}

static void mpc123_norm_inf_8_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  return;
}

static void mpc123_norm_inf_8_6(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  if (A[16] > out[0]) out[0] = A[16];
  if (-A[16] > out[0]) out[0] = A[16];
  if (A[17] > out[0]) out[0] = A[17];
  if (-A[17] > out[0]) out[0] = A[17];
  if (A[18] > out[0]) out[0] = A[18];
  if (-A[18] > out[0]) out[0] = A[18];
  if (A[19] > out[0]) out[0] = A[19];
  if (-A[19] > out[0]) out[0] = A[19];
  if (A[20] > out[0]) out[0] = A[20];
  if (-A[20] > out[0]) out[0] = A[20];
  if (A[21] > out[0]) out[0] = A[21];
  if (-A[21] > out[0]) out[0] = A[21];
  if (A[22] > out[0]) out[0] = A[22];
  if (-A[22] > out[0]) out[0] = A[22];
  if (A[23] > out[0]) out[0] = A[23];
  if (-A[23] > out[0]) out[0] = A[23];
  if (A[24] > out[0]) out[0] = A[24];
  if (-A[24] > out[0]) out[0] = A[24];
  if (A[25] > out[0]) out[0] = A[25];
  if (-A[25] > out[0]) out[0] = A[25];
  if (A[26] > out[0]) out[0] = A[26];
  if (-A[26] > out[0]) out[0] = A[26];
  if (A[27] > out[0]) out[0] = A[27];
  if (-A[27] > out[0]) out[0] = A[27];
  if (A[28] > out[0]) out[0] = A[28];
  if (-A[28] > out[0]) out[0] = A[28];
  if (A[29] > out[0]) out[0] = A[29];
  if (-A[29] > out[0]) out[0] = A[29];
  if (A[30] > out[0]) out[0] = A[30];
  if (-A[30] > out[0]) out[0] = A[30];
  if (A[31] > out[0]) out[0] = A[31];
  if (-A[31] > out[0]) out[0] = A[31];
  if (A[32] > out[0]) out[0] = A[32];
  if (-A[32] > out[0]) out[0] = A[32];
  if (A[33] > out[0]) out[0] = A[33];
  if (-A[33] > out[0]) out[0] = A[33];
  if (A[34] > out[0]) out[0] = A[34];
  if (-A[34] > out[0]) out[0] = A[34];
  if (A[35] > out[0]) out[0] = A[35];
  if (-A[35] > out[0]) out[0] = A[35];
  if (A[36] > out[0]) out[0] = A[36];
  if (-A[36] > out[0]) out[0] = A[36];
  if (A[37] > out[0]) out[0] = A[37];
  if (-A[37] > out[0]) out[0] = A[37];
  if (A[38] > out[0]) out[0] = A[38];
  if (-A[38] > out[0]) out[0] = A[38];
  if (A[39] > out[0]) out[0] = A[39];
  if (-A[39] > out[0]) out[0] = A[39];
  if (A[40] > out[0]) out[0] = A[40];
  if (-A[40] > out[0]) out[0] = A[40];
  if (A[41] > out[0]) out[0] = A[41];
  if (-A[41] > out[0]) out[0] = A[41];
  if (A[42] > out[0]) out[0] = A[42];
  if (-A[42] > out[0]) out[0] = A[42];
  if (A[43] > out[0]) out[0] = A[43];
  if (-A[43] > out[0]) out[0] = A[43];
  if (A[44] > out[0]) out[0] = A[44];
  if (-A[44] > out[0]) out[0] = A[44];
  if (A[45] > out[0]) out[0] = A[45];
  if (-A[45] > out[0]) out[0] = A[45];
  if (A[46] > out[0]) out[0] = A[46];
  if (-A[46] > out[0]) out[0] = A[46];
  if (A[47] > out[0]) out[0] = A[47];
  if (-A[47] > out[0]) out[0] = A[47];
  return;
}

static void mpc123_norm_inf_16_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  if (A[3] > out[0]) out[0] = A[3];
  if (-A[3] > out[0]) out[0] = A[3];
  if (A[4] > out[0]) out[0] = A[4];
  if (-A[4] > out[0]) out[0] = A[4];
  if (A[5] > out[0]) out[0] = A[5];
  if (-A[5] > out[0]) out[0] = A[5];
  if (A[6] > out[0]) out[0] = A[6];
  if (-A[6] > out[0]) out[0] = A[6];
  if (A[7] > out[0]) out[0] = A[7];
  if (-A[7] > out[0]) out[0] = A[7];
  if (A[8] > out[0]) out[0] = A[8];
  if (-A[8] > out[0]) out[0] = A[8];
  if (A[9] > out[0]) out[0] = A[9];
  if (-A[9] > out[0]) out[0] = A[9];
  if (A[10] > out[0]) out[0] = A[10];
  if (-A[10] > out[0]) out[0] = A[10];
  if (A[11] > out[0]) out[0] = A[11];
  if (-A[11] > out[0]) out[0] = A[11];
  if (A[12] > out[0]) out[0] = A[12];
  if (-A[12] > out[0]) out[0] = A[12];
  if (A[13] > out[0]) out[0] = A[13];
  if (-A[13] > out[0]) out[0] = A[13];
  if (A[14] > out[0]) out[0] = A[14];
  if (-A[14] > out[0]) out[0] = A[14];
  if (A[15] > out[0]) out[0] = A[15];
  if (-A[15] > out[0]) out[0] = A[15];
  return;
}

static void mpc123_v_min_8(float *A, float *B, float *out)
{
  int i;
  out[0] = B[0];

  for(i=0;i<8;i++)
  {
    if (A[i] < out[0])
    {
      out[0] = A[i];
    }
  }
  return;
}

static void mpc123_v_min_16(float *A, float *B, float *out)
{
  int i;
  out[0] = B[0];

  for(i=0;i<16;i++)
  {
    if (A[i] < out[0])
    {
      out[0] = A[i];
    }
  }
  return;
}

static void mpc123_vsum_8(float *a, float *out)
{

  out[0] = out[0] + a[0];
  out[0] = out[0] + a[1];
  out[0] = out[0] + a[2];
  out[0] = out[0] + a[3];
  out[0] = out[0] + a[4];
  out[0] = out[0] + a[5];
  out[0] = out[0] + a[6];
  out[0] = out[0] + a[7];
  return;
}

static void mpc123_vsum_16(float *a, float *out)
{

  out[0] = out[0] + a[0];
  out[0] = out[0] + a[1];
  out[0] = out[0] + a[2];
  out[0] = out[0] + a[3];
  out[0] = out[0] + a[4];
  out[0] = out[0] + a[5];
  out[0] = out[0] + a[6];
  out[0] = out[0] + a[7];
  out[0] = out[0] + a[8];
  out[0] = out[0] + a[9];
  out[0] = out[0] + a[10];
  out[0] = out[0] + a[11];
  out[0] = out[0] + a[12];
  out[0] = out[0] + a[13];
  out[0] = out[0] + a[14];
  out[0] = out[0] + a[15];
  return;
}

static void mpc123_vtm_6_6(float *a, float *B, float *out)
{

out[0] += a[0] * B[0];
out[0] += a[1] * B[1];
out[0] += a[2] * B[2];
out[0] += a[3] * B[3];
out[0] += a[4] * B[4];
out[0] += a[5] * B[5];
out[1] += a[0] * B[6];
out[1] += a[1] * B[7];
out[1] += a[2] * B[8];
out[1] += a[3] * B[9];
out[1] += a[4] * B[10];
out[1] += a[5] * B[11];
out[2] += a[0] * B[12];
out[2] += a[1] * B[13];
out[2] += a[2] * B[14];
out[2] += a[3] * B[15];
out[2] += a[4] * B[16];
out[2] += a[5] * B[17];
out[3] += a[0] * B[18];
out[3] += a[1] * B[19];
out[3] += a[2] * B[20];
out[3] += a[3] * B[21];
out[3] += a[4] * B[22];
out[3] += a[5] * B[23];
out[4] += a[0] * B[24];
out[4] += a[1] * B[25];
out[4] += a[2] * B[26];
out[4] += a[3] * B[27];
out[4] += a[4] * B[28];
out[4] += a[5] * B[29];
out[5] += a[0] * B[30];
out[5] += a[1] * B[31];
out[5] += a[2] * B[32];
out[5] += a[3] * B[33];
out[5] += a[4] * B[34];
out[5] += a[5] * B[35];
  return;
}

static void mpc123_mm_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[6] += A[0] * B[6];
out[7] += A[1] * B[6];
out[8] += A[2] * B[6];
out[9] += A[3] * B[6];
out[10] += A[4] * B[6];
out[11] += A[5] * B[6];
out[12] += A[0] * B[12];
out[13] += A[1] * B[12];
out[14] += A[2] * B[12];
out[15] += A[3] * B[12];
out[16] += A[4] * B[12];
out[17] += A[5] * B[12];
out[18] += A[0] * B[18];
out[19] += A[1] * B[18];
out[20] += A[2] * B[18];
out[21] += A[3] * B[18];
out[22] += A[4] * B[18];
out[23] += A[5] * B[18];
out[24] += A[0] * B[24];
out[25] += A[1] * B[24];
out[26] += A[2] * B[24];
out[27] += A[3] * B[24];
out[28] += A[4] * B[24];
out[29] += A[5] * B[24];
out[30] += A[0] * B[30];
out[31] += A[1] * B[30];
out[32] += A[2] * B[30];
out[33] += A[3] * B[30];
out[34] += A[4] * B[30];
out[35] += A[5] * B[30];
out[0] += A[6] * B[1];
out[1] += A[7] * B[1];
out[2] += A[8] * B[1];
out[3] += A[9] * B[1];
out[4] += A[10] * B[1];
out[5] += A[11] * B[1];
out[6] += A[6] * B[7];
out[7] += A[7] * B[7];
out[8] += A[8] * B[7];
out[9] += A[9] * B[7];
out[10] += A[10] * B[7];
out[11] += A[11] * B[7];
out[12] += A[6] * B[13];
out[13] += A[7] * B[13];
out[14] += A[8] * B[13];
out[15] += A[9] * B[13];
out[16] += A[10] * B[13];
out[17] += A[11] * B[13];
out[18] += A[6] * B[19];
out[19] += A[7] * B[19];
out[20] += A[8] * B[19];
out[21] += A[9] * B[19];
out[22] += A[10] * B[19];
out[23] += A[11] * B[19];
out[24] += A[6] * B[25];
out[25] += A[7] * B[25];
out[26] += A[8] * B[25];
out[27] += A[9] * B[25];
out[28] += A[10] * B[25];
out[29] += A[11] * B[25];
out[30] += A[6] * B[31];
out[31] += A[7] * B[31];
out[32] += A[8] * B[31];
out[33] += A[9] * B[31];
out[34] += A[10] * B[31];
out[35] += A[11] * B[31];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[6] += A[12] * B[8];
out[7] += A[13] * B[8];
out[8] += A[14] * B[8];
out[9] += A[15] * B[8];
out[10] += A[16] * B[8];
out[11] += A[17] * B[8];
out[12] += A[12] * B[14];
out[13] += A[13] * B[14];
out[14] += A[14] * B[14];
out[15] += A[15] * B[14];
out[16] += A[16] * B[14];
out[17] += A[17] * B[14];
out[18] += A[12] * B[20];
out[19] += A[13] * B[20];
out[20] += A[14] * B[20];
out[21] += A[15] * B[20];
out[22] += A[16] * B[20];
out[23] += A[17] * B[20];
out[24] += A[12] * B[26];
out[25] += A[13] * B[26];
out[26] += A[14] * B[26];
out[27] += A[15] * B[26];
out[28] += A[16] * B[26];
out[29] += A[17] * B[26];
out[30] += A[12] * B[32];
out[31] += A[13] * B[32];
out[32] += A[14] * B[32];
out[33] += A[15] * B[32];
out[34] += A[16] * B[32];
out[35] += A[17] * B[32];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[6] += A[18] * B[9];
out[7] += A[19] * B[9];
out[8] += A[20] * B[9];
out[9] += A[21] * B[9];
out[10] += A[22] * B[9];
out[11] += A[23] * B[9];
out[12] += A[18] * B[15];
out[13] += A[19] * B[15];
out[14] += A[20] * B[15];
out[15] += A[21] * B[15];
out[16] += A[22] * B[15];
out[17] += A[23] * B[15];
out[18] += A[18] * B[21];
out[19] += A[19] * B[21];
out[20] += A[20] * B[21];
out[21] += A[21] * B[21];
out[22] += A[22] * B[21];
out[23] += A[23] * B[21];
out[24] += A[18] * B[27];
out[25] += A[19] * B[27];
out[26] += A[20] * B[27];
out[27] += A[21] * B[27];
out[28] += A[22] * B[27];
out[29] += A[23] * B[27];
out[30] += A[18] * B[33];
out[31] += A[19] * B[33];
out[32] += A[20] * B[33];
out[33] += A[21] * B[33];
out[34] += A[22] * B[33];
out[35] += A[23] * B[33];
out[0] += A[24] * B[4];
out[1] += A[25] * B[4];
out[2] += A[26] * B[4];
out[3] += A[27] * B[4];
out[4] += A[28] * B[4];
out[5] += A[29] * B[4];
out[6] += A[24] * B[10];
out[7] += A[25] * B[10];
out[8] += A[26] * B[10];
out[9] += A[27] * B[10];
out[10] += A[28] * B[10];
out[11] += A[29] * B[10];
out[12] += A[24] * B[16];
out[13] += A[25] * B[16];
out[14] += A[26] * B[16];
out[15] += A[27] * B[16];
out[16] += A[28] * B[16];
out[17] += A[29] * B[16];
out[18] += A[24] * B[22];
out[19] += A[25] * B[22];
out[20] += A[26] * B[22];
out[21] += A[27] * B[22];
out[22] += A[28] * B[22];
out[23] += A[29] * B[22];
out[24] += A[24] * B[28];
out[25] += A[25] * B[28];
out[26] += A[26] * B[28];
out[27] += A[27] * B[28];
out[28] += A[28] * B[28];
out[29] += A[29] * B[28];
out[30] += A[24] * B[34];
out[31] += A[25] * B[34];
out[32] += A[26] * B[34];
out[33] += A[27] * B[34];
out[34] += A[28] * B[34];
out[35] += A[29] * B[34];
out[0] += A[30] * B[5];
out[1] += A[31] * B[5];
out[2] += A[32] * B[5];
out[3] += A[33] * B[5];
out[4] += A[34] * B[5];
out[5] += A[35] * B[5];
out[6] += A[30] * B[11];
out[7] += A[31] * B[11];
out[8] += A[32] * B[11];
out[9] += A[33] * B[11];
out[10] += A[34] * B[11];
out[11] += A[35] * B[11];
out[12] += A[30] * B[17];
out[13] += A[31] * B[17];
out[14] += A[32] * B[17];
out[15] += A[33] * B[17];
out[16] += A[34] * B[17];
out[17] += A[35] * B[17];
out[18] += A[30] * B[23];
out[19] += A[31] * B[23];
out[20] += A[32] * B[23];
out[21] += A[33] * B[23];
out[22] += A[34] * B[23];
out[23] += A[35] * B[23];
out[24] += A[30] * B[29];
out[25] += A[31] * B[29];
out[26] += A[32] * B[29];
out[27] += A[33] * B[29];
out[28] += A[34] * B[29];
out[29] += A[35] * B[29];
out[30] += A[30] * B[35];
out[31] += A[31] * B[35];
out[32] += A[32] * B[35];
out[33] += A[33] * B[35];
out[34] += A[34] * B[35];
out[35] += A[35] * B[35];
  return;
}

static void mpc123_mtm_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[4] * B[4];
out[0] += A[5] * B[5];
out[1] += A[6] * B[0];
out[1] += A[7] * B[1];
out[1] += A[8] * B[2];
out[1] += A[9] * B[3];
out[1] += A[10] * B[4];
out[1] += A[11] * B[5];
out[2] += A[12] * B[0];
out[2] += A[13] * B[1];
out[2] += A[14] * B[2];
out[2] += A[15] * B[3];
out[2] += A[16] * B[4];
out[2] += A[17] * B[5];
out[3] += A[18] * B[0];
out[3] += A[19] * B[1];
out[3] += A[20] * B[2];
out[3] += A[21] * B[3];
out[3] += A[22] * B[4];
out[3] += A[23] * B[5];
out[4] += A[24] * B[0];
out[4] += A[25] * B[1];
out[4] += A[26] * B[2];
out[4] += A[27] * B[3];
out[4] += A[28] * B[4];
out[4] += A[29] * B[5];
out[5] += A[30] * B[0];
out[5] += A[31] * B[1];
out[5] += A[32] * B[2];
out[5] += A[33] * B[3];
out[5] += A[34] * B[4];
out[5] += A[35] * B[5];
out[6] += A[0] * B[6];
out[6] += A[1] * B[7];
out[6] += A[2] * B[8];
out[6] += A[3] * B[9];
out[6] += A[4] * B[10];
out[6] += A[5] * B[11];
out[7] += A[6] * B[6];
out[7] += A[7] * B[7];
out[7] += A[8] * B[8];
out[7] += A[9] * B[9];
out[7] += A[10] * B[10];
out[7] += A[11] * B[11];
out[8] += A[12] * B[6];
out[8] += A[13] * B[7];
out[8] += A[14] * B[8];
out[8] += A[15] * B[9];
out[8] += A[16] * B[10];
out[8] += A[17] * B[11];
out[9] += A[18] * B[6];
out[9] += A[19] * B[7];
out[9] += A[20] * B[8];
out[9] += A[21] * B[9];
out[9] += A[22] * B[10];
out[9] += A[23] * B[11];
out[10] += A[24] * B[6];
out[10] += A[25] * B[7];
out[10] += A[26] * B[8];
out[10] += A[27] * B[9];
out[10] += A[28] * B[10];
out[10] += A[29] * B[11];
out[11] += A[30] * B[6];
out[11] += A[31] * B[7];
out[11] += A[32] * B[8];
out[11] += A[33] * B[9];
out[11] += A[34] * B[10];
out[11] += A[35] * B[11];
out[12] += A[0] * B[12];
out[12] += A[1] * B[13];
out[12] += A[2] * B[14];
out[12] += A[3] * B[15];
out[12] += A[4] * B[16];
out[12] += A[5] * B[17];
out[13] += A[6] * B[12];
out[13] += A[7] * B[13];
out[13] += A[8] * B[14];
out[13] += A[9] * B[15];
out[13] += A[10] * B[16];
out[13] += A[11] * B[17];
out[14] += A[12] * B[12];
out[14] += A[13] * B[13];
out[14] += A[14] * B[14];
out[14] += A[15] * B[15];
out[14] += A[16] * B[16];
out[14] += A[17] * B[17];
out[15] += A[18] * B[12];
out[15] += A[19] * B[13];
out[15] += A[20] * B[14];
out[15] += A[21] * B[15];
out[15] += A[22] * B[16];
out[15] += A[23] * B[17];
out[16] += A[24] * B[12];
out[16] += A[25] * B[13];
out[16] += A[26] * B[14];
out[16] += A[27] * B[15];
out[16] += A[28] * B[16];
out[16] += A[29] * B[17];
out[17] += A[30] * B[12];
out[17] += A[31] * B[13];
out[17] += A[32] * B[14];
out[17] += A[33] * B[15];
out[17] += A[34] * B[16];
out[17] += A[35] * B[17];
out[18] += A[0] * B[18];
out[18] += A[1] * B[19];
out[18] += A[2] * B[20];
out[18] += A[3] * B[21];
out[18] += A[4] * B[22];
out[18] += A[5] * B[23];
out[19] += A[6] * B[18];
out[19] += A[7] * B[19];
out[19] += A[8] * B[20];
out[19] += A[9] * B[21];
out[19] += A[10] * B[22];
out[19] += A[11] * B[23];
out[20] += A[12] * B[18];
out[20] += A[13] * B[19];
out[20] += A[14] * B[20];
out[20] += A[15] * B[21];
out[20] += A[16] * B[22];
out[20] += A[17] * B[23];
out[21] += A[18] * B[18];
out[21] += A[19] * B[19];
out[21] += A[20] * B[20];
out[21] += A[21] * B[21];
out[21] += A[22] * B[22];
out[21] += A[23] * B[23];
out[22] += A[24] * B[18];
out[22] += A[25] * B[19];
out[22] += A[26] * B[20];
out[22] += A[27] * B[21];
out[22] += A[28] * B[22];
out[22] += A[29] * B[23];
out[23] += A[30] * B[18];
out[23] += A[31] * B[19];
out[23] += A[32] * B[20];
out[23] += A[33] * B[21];
out[23] += A[34] * B[22];
out[23] += A[35] * B[23];
out[24] += A[0] * B[24];
out[24] += A[1] * B[25];
out[24] += A[2] * B[26];
out[24] += A[3] * B[27];
out[24] += A[4] * B[28];
out[24] += A[5] * B[29];
out[25] += A[6] * B[24];
out[25] += A[7] * B[25];
out[25] += A[8] * B[26];
out[25] += A[9] * B[27];
out[25] += A[10] * B[28];
out[25] += A[11] * B[29];
out[26] += A[12] * B[24];
out[26] += A[13] * B[25];
out[26] += A[14] * B[26];
out[26] += A[15] * B[27];
out[26] += A[16] * B[28];
out[26] += A[17] * B[29];
out[27] += A[18] * B[24];
out[27] += A[19] * B[25];
out[27] += A[20] * B[26];
out[27] += A[21] * B[27];
out[27] += A[22] * B[28];
out[27] += A[23] * B[29];
out[28] += A[24] * B[24];
out[28] += A[25] * B[25];
out[28] += A[26] * B[26];
out[28] += A[27] * B[27];
out[28] += A[28] * B[28];
out[28] += A[29] * B[29];
out[29] += A[30] * B[24];
out[29] += A[31] * B[25];
out[29] += A[32] * B[26];
out[29] += A[33] * B[27];
out[29] += A[34] * B[28];
out[29] += A[35] * B[29];
out[30] += A[0] * B[30];
out[30] += A[1] * B[31];
out[30] += A[2] * B[32];
out[30] += A[3] * B[33];
out[30] += A[4] * B[34];
out[30] += A[5] * B[35];
out[31] += A[6] * B[30];
out[31] += A[7] * B[31];
out[31] += A[8] * B[32];
out[31] += A[9] * B[33];
out[31] += A[10] * B[34];
out[31] += A[11] * B[35];
out[32] += A[12] * B[30];
out[32] += A[13] * B[31];
out[32] += A[14] * B[32];
out[32] += A[15] * B[33];
out[32] += A[16] * B[34];
out[32] += A[17] * B[35];
out[33] += A[18] * B[30];
out[33] += A[19] * B[31];
out[33] += A[20] * B[32];
out[33] += A[21] * B[33];
out[33] += A[22] * B[34];
out[33] += A[23] * B[35];
out[34] += A[24] * B[30];
out[34] += A[25] * B[31];
out[34] += A[26] * B[32];
out[34] += A[27] * B[33];
out[34] += A[28] * B[34];
out[34] += A[29] * B[35];
out[35] += A[30] * B[30];
out[35] += A[31] * B[31];
out[35] += A[32] * B[32];
out[35] += A[33] * B[33];
out[35] += A[34] * B[34];
out[35] += A[35] * B[35];
  return;
}

static void mpc123_mmr_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[6] += A[0] * B[6];
out[7] += A[1] * B[6];
out[8] += A[2] * B[6];
out[9] += A[3] * B[6];
out[10] += A[4] * B[6];
out[11] += A[5] * B[6];
out[12] += A[0] * B[12];
out[13] += A[1] * B[12];
out[14] += A[2] * B[12];
out[15] += A[3] * B[12];
out[16] += A[4] * B[12];
out[17] += A[5] * B[12];
out[18] += A[0] * B[18];
out[19] += A[1] * B[18];
out[20] += A[2] * B[18];
out[21] += A[3] * B[18];
out[22] += A[4] * B[18];
out[23] += A[5] * B[18];
out[24] += A[0] * B[24];
out[25] += A[1] * B[24];
out[26] += A[2] * B[24];
out[27] += A[3] * B[24];
out[28] += A[4] * B[24];
out[29] += A[5] * B[24];
out[30] += A[0] * B[30];
out[31] += A[1] * B[30];
out[32] += A[2] * B[30];
out[33] += A[3] * B[30];
out[34] += A[4] * B[30];
out[35] += A[5] * B[30];
out[0] += A[6] * B[1];
out[1] += A[7] * B[1];
out[2] += A[8] * B[1];
out[3] += A[9] * B[1];
out[4] += A[10] * B[1];
out[5] += A[11] * B[1];
out[6] += A[6] * B[7];
out[7] += A[7] * B[7];
out[8] += A[8] * B[7];
out[9] += A[9] * B[7];
out[10] += A[10] * B[7];
out[11] += A[11] * B[7];
out[12] += A[6] * B[13];
out[13] += A[7] * B[13];
out[14] += A[8] * B[13];
out[15] += A[9] * B[13];
out[16] += A[10] * B[13];
out[17] += A[11] * B[13];
out[18] += A[6] * B[19];
out[19] += A[7] * B[19];
out[20] += A[8] * B[19];
out[21] += A[9] * B[19];
out[22] += A[10] * B[19];
out[23] += A[11] * B[19];
out[24] += A[6] * B[25];
out[25] += A[7] * B[25];
out[26] += A[8] * B[25];
out[27] += A[9] * B[25];
out[28] += A[10] * B[25];
out[29] += A[11] * B[25];
out[30] += A[6] * B[31];
out[31] += A[7] * B[31];
out[32] += A[8] * B[31];
out[33] += A[9] * B[31];
out[34] += A[10] * B[31];
out[35] += A[11] * B[31];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[6] += A[12] * B[8];
out[7] += A[13] * B[8];
out[8] += A[14] * B[8];
out[9] += A[15] * B[8];
out[10] += A[16] * B[8];
out[11] += A[17] * B[8];
out[12] += A[12] * B[14];
out[13] += A[13] * B[14];
out[14] += A[14] * B[14];
out[15] += A[15] * B[14];
out[16] += A[16] * B[14];
out[17] += A[17] * B[14];
out[18] += A[12] * B[20];
out[19] += A[13] * B[20];
out[20] += A[14] * B[20];
out[21] += A[15] * B[20];
out[22] += A[16] * B[20];
out[23] += A[17] * B[20];
out[24] += A[12] * B[26];
out[25] += A[13] * B[26];
out[26] += A[14] * B[26];
out[27] += A[15] * B[26];
out[28] += A[16] * B[26];
out[29] += A[17] * B[26];
out[30] += A[12] * B[32];
out[31] += A[13] * B[32];
out[32] += A[14] * B[32];
out[33] += A[15] * B[32];
out[34] += A[16] * B[32];
out[35] += A[17] * B[32];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[6] += A[18] * B[9];
out[7] += A[19] * B[9];
out[8] += A[20] * B[9];
out[9] += A[21] * B[9];
out[10] += A[22] * B[9];
out[11] += A[23] * B[9];
out[12] += A[18] * B[15];
out[13] += A[19] * B[15];
out[14] += A[20] * B[15];
out[15] += A[21] * B[15];
out[16] += A[22] * B[15];
out[17] += A[23] * B[15];
out[18] += A[18] * B[21];
out[19] += A[19] * B[21];
out[20] += A[20] * B[21];
out[21] += A[21] * B[21];
out[22] += A[22] * B[21];
out[23] += A[23] * B[21];
out[24] += A[18] * B[27];
out[25] += A[19] * B[27];
out[26] += A[20] * B[27];
out[27] += A[21] * B[27];
out[28] += A[22] * B[27];
out[29] += A[23] * B[27];
out[30] += A[18] * B[33];
out[31] += A[19] * B[33];
out[32] += A[20] * B[33];
out[33] += A[21] * B[33];
out[34] += A[22] * B[33];
out[35] += A[23] * B[33];
out[0] += A[24] * B[4];
out[1] += A[25] * B[4];
out[2] += A[26] * B[4];
out[3] += A[27] * B[4];
out[4] += A[28] * B[4];
out[5] += A[29] * B[4];
out[6] += A[24] * B[10];
out[7] += A[25] * B[10];
out[8] += A[26] * B[10];
out[9] += A[27] * B[10];
out[10] += A[28] * B[10];
out[11] += A[29] * B[10];
out[12] += A[24] * B[16];
out[13] += A[25] * B[16];
out[14] += A[26] * B[16];
out[15] += A[27] * B[16];
out[16] += A[28] * B[16];
out[17] += A[29] * B[16];
out[18] += A[24] * B[22];
out[19] += A[25] * B[22];
out[20] += A[26] * B[22];
out[21] += A[27] * B[22];
out[22] += A[28] * B[22];
out[23] += A[29] * B[22];
out[24] += A[24] * B[28];
out[25] += A[25] * B[28];
out[26] += A[26] * B[28];
out[27] += A[27] * B[28];
out[28] += A[28] * B[28];
out[29] += A[29] * B[28];
out[30] += A[24] * B[34];
out[31] += A[25] * B[34];
out[32] += A[26] * B[34];
out[33] += A[27] * B[34];
out[34] += A[28] * B[34];
out[35] += A[29] * B[34];
out[0] += A[30] * B[5];
out[1] += A[31] * B[5];
out[2] += A[32] * B[5];
out[3] += A[33] * B[5];
out[4] += A[34] * B[5];
out[5] += A[35] * B[5];
out[6] += A[30] * B[11];
out[7] += A[31] * B[11];
out[8] += A[32] * B[11];
out[9] += A[33] * B[11];
out[10] += A[34] * B[11];
out[11] += A[35] * B[11];
out[12] += A[30] * B[17];
out[13] += A[31] * B[17];
out[14] += A[32] * B[17];
out[15] += A[33] * B[17];
out[16] += A[34] * B[17];
out[17] += A[35] * B[17];
out[18] += A[30] * B[23];
out[19] += A[31] * B[23];
out[20] += A[32] * B[23];
out[21] += A[33] * B[23];
out[22] += A[34] * B[23];
out[23] += A[35] * B[23];
out[24] += A[30] * B[29];
out[25] += A[31] * B[29];
out[26] += A[32] * B[29];
out[27] += A[33] * B[29];
out[28] += A[34] * B[29];
out[29] += A[35] * B[29];
out[30] += A[30] * B[35];
out[31] += A[31] * B[35];
out[32] += A[32] * B[35];
out[33] += A[33] * B[35];
out[34] += A[34] * B[35];
out[35] += A[35] * B[35];
  return;
}

static void mpc123_vtm_sid2_sid42_6_6(float *a, float *B, float *out)
{

out[0] += a[0] * B[0];
out[0] += a[2] * B[2];
out[0] += a[3] * B[3];
out[1] += a[0] * B[6];
out[1] += a[1] * B[7];
out[1] += a[2] * B[8];
out[1] += a[3] * B[9];
out[2] += a[2] * B[14];
out[2] += a[3] * B[15];
out[3] += a[2] * B[20];
out[3] += a[3] * B[21];
out[5] += a[4] * B[34];
  return;
}

static void mpc123_mm_sid1_sid42_6_6_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[3] += A[3] * B[0];
out[4] += A[4] * B[0];
out[5] += A[5] * B[0];
out[6] += A[0] * B[6];
out[7] += A[1] * B[6];
out[8] += A[2] * B[6];
out[9] += A[3] * B[6];
out[10] += A[4] * B[6];
out[11] += A[5] * B[6];
out[6] += A[6] * B[7];
out[7] += A[7] * B[7];
out[8] += A[8] * B[7];
out[9] += A[9] * B[7];
out[10] += A[10] * B[7];
out[11] += A[11] * B[7];
out[0] += A[12] * B[2];
out[1] += A[13] * B[2];
out[2] += A[14] * B[2];
out[3] += A[15] * B[2];
out[4] += A[16] * B[2];
out[5] += A[17] * B[2];
out[6] += A[12] * B[8];
out[7] += A[13] * B[8];
out[8] += A[14] * B[8];
out[9] += A[15] * B[8];
out[10] += A[16] * B[8];
out[11] += A[17] * B[8];
out[12] += A[12] * B[14];
out[13] += A[13] * B[14];
out[14] += A[14] * B[14];
out[15] += A[15] * B[14];
out[16] += A[16] * B[14];
out[17] += A[17] * B[14];
out[18] += A[12] * B[20];
out[19] += A[13] * B[20];
out[20] += A[14] * B[20];
out[21] += A[15] * B[20];
out[22] += A[16] * B[20];
out[23] += A[17] * B[20];
out[0] += A[18] * B[3];
out[1] += A[19] * B[3];
out[2] += A[20] * B[3];
out[3] += A[21] * B[3];
out[4] += A[22] * B[3];
out[5] += A[23] * B[3];
out[6] += A[18] * B[9];
out[7] += A[19] * B[9];
out[8] += A[20] * B[9];
out[9] += A[21] * B[9];
out[10] += A[22] * B[9];
out[11] += A[23] * B[9];
out[12] += A[18] * B[15];
out[13] += A[19] * B[15];
out[14] += A[20] * B[15];
out[15] += A[21] * B[15];
out[16] += A[22] * B[15];
out[17] += A[23] * B[15];
out[18] += A[18] * B[21];
out[19] += A[19] * B[21];
out[20] += A[20] * B[21];
out[21] += A[21] * B[21];
out[22] += A[22] * B[21];
out[23] += A[23] * B[21];
out[30] += A[24] * B[34];
out[31] += A[25] * B[34];
out[32] += A[26] * B[34];
out[33] += A[27] * B[34];
out[34] += A[28] * B[34];
out[35] += A[29] * B[34];
  return;
}


/* ########################### */
/* Diese Funktion berechnet mu */
/* ########################### */
static void mpc123_glqdocpip_calc_mu()
{
  int i1;
mpc123_v_init0_1(mpc123_mu);
/* mu = mu + y*nu */
/* Zeitschritt 0 */
mpc123_vtv_8(&mpc123_arr_t1[2658], &mpc123_arr_t1[2666], mpc123_mu);
/* Zeitschritt 1 */
mpc123_vtv_16(&mpc123_arr_t1[2941], &mpc123_arr_t1[2957], mpc123_mu);
/* Zeitschritt 2 */
mpc123_vtv_16(&mpc123_arr_t1[3328], &mpc123_arr_t1[3344], mpc123_mu);
/* Zeitschritt 3 */
mpc123_vtv_16(&mpc123_arr_t1[3715], &mpc123_arr_t1[3731], mpc123_mu);
/* Zeitschritt 4 */
mpc123_vtv_16(&mpc123_arr_t1[4102], &mpc123_arr_t1[4118], mpc123_mu);
/* Zeitschritt 5 */
mpc123_vtv_16(&mpc123_arr_t1[4489], &mpc123_arr_t1[4505], mpc123_mu);
/* Zeitschritt 6 */
mpc123_vtv_16(&mpc123_arr_t1[4876], &mpc123_arr_t1[4892], mpc123_mu);
/* Zeitschritt 7 */
mpc123_vtv_16(&mpc123_arr_t1[5263], &mpc123_arr_t1[5279], mpc123_mu);
/* Zeitschritt 8 */
mpc123_vtv_16(&mpc123_arr_t1[5650], &mpc123_arr_t1[5666], mpc123_mu);
/* Zeitschritt 9 */
mpc123_vtv_16(&mpc123_arr_t1[6037], &mpc123_arr_t1[6053], mpc123_mu);
/* Zeitschritt 10 */
mpc123_vtv_16(&mpc123_arr_t1[6424], &mpc123_arr_t1[6440], mpc123_mu);
/* Zeitschritt 11 */
mpc123_vtv_8(&mpc123_arr_t1[6807], &mpc123_arr_t1[6815], mpc123_mu);
mpc123_vv_elediv_1(mpc123_mu, mpc123_m_ineq, mpc123_mu);
if(mpc123_termcode > -1){return;}

/* mu0 bestimmen */
if(mpc123_iter == 0){
mpc123_v_copy_1(mpc123_mu, mpc123_mu0);
}
}


/* ############################### */
/* Diese Funktion berechnet mu_aff */
/* ############################### */
static void mpc123_glqdocpip_calc_mu_aff()
{
  int i1;
mpc123_v_init0_1(mpc123_mu_aff);
/* Zeitschritt 0 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_8(&mpc123_arr_t1[2658], mpc123_tmp1_8);
mpc123_sv_8(mpc123_alpha_max, &mpc123_arr_t1[2691], mpc123_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_8(&mpc123_arr_t1[2666], mpc123_tmp2_8);
mpc123_sv_8(mpc123_alpha_max, &mpc123_arr_t1[2699], mpc123_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_8(mpc123_tmp1_8, mpc123_tmp2_8, mpc123_mu_aff);
/* Zeitschritt 1 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[2941], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[2994], mpc123_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[2957], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[3010], mpc123_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp1_16, mpc123_tmp2_16, mpc123_mu_aff);
/* Zeitschritt 2 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[3328], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[3381], mpc123_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[3344], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[3397], mpc123_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp1_16, mpc123_mu_aff);
/* Zeitschritt 3 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[3715], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[3768], mpc123_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[3731], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[3784], mpc123_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp1_16, mpc123_tmp2_16, mpc123_mu_aff);
/* Zeitschritt 4 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[4102], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4155], mpc123_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[4118], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4171], mpc123_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp1_16, mpc123_mu_aff);
/* Zeitschritt 5 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[4489], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4542], mpc123_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[4505], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4558], mpc123_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp1_16, mpc123_tmp2_16, mpc123_mu_aff);
/* Zeitschritt 6 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[4876], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4929], mpc123_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[4892], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[4945], mpc123_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp1_16, mpc123_mu_aff);
/* Zeitschritt 7 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[5263], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[5316], mpc123_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[5279], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[5332], mpc123_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp1_16, mpc123_tmp2_16, mpc123_mu_aff);
/* Zeitschritt 8 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[5650], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[5703], mpc123_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[5666], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[5719], mpc123_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp1_16, mpc123_mu_aff);
/* Zeitschritt 9 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[6037], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[6090], mpc123_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[6053], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[6106], mpc123_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp1_16, mpc123_tmp2_16, mpc123_mu_aff);
/* Zeitschritt 10 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_16(&mpc123_arr_t1[6424], mpc123_tmp2_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[6477], mpc123_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_16(&mpc123_arr_t1[6440], mpc123_tmp1_16);
mpc123_sv_16(mpc123_alpha_max, &mpc123_arr_t1[6493], mpc123_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp1_16, mpc123_mu_aff);
/* Zeitschritt 11 */
/* yady = y + alpha_max*dy */
mpc123_v_copy_8(&mpc123_arr_t1[6807], mpc123_tmp2_8);
mpc123_sv_8(mpc123_alpha_max, &mpc123_arr_t1[6840], mpc123_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc123_v_copy_8(&mpc123_arr_t1[6815], mpc123_tmp1_8);
mpc123_sv_8(mpc123_alpha_max, &mpc123_arr_t1[6848], mpc123_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc123_vtv_8(mpc123_tmp2_8, mpc123_tmp1_8, mpc123_mu_aff);
mpc123_vv_elediv_1(mpc123_mu_aff, mpc123_m_ineq, mpc123_mu_aff);
if(mpc123_termcode > -1){return;}
}


/* ############################ */
/* Diese Funktion berechnet phi */
/* ############################ */
static void mpc123_glqdocpip_calc_phi()
{
mpc123_vadd_1(mpc123_norm_r, mpc123_dgap, mpc123_phi);
mpc123_vv_elediv_1(mpc123_phi, mpc123_norm_d, mpc123_phi);
if(mpc123_termcode > -1){return;}
if (mpc123_iter > 0) {

mpc123_min(mpc123_minphi, mpc123_phi, mpc123_minphi);
}else{
mpc123_v_copy_1(mpc123_phi, mpc123_minphi);
}
}


/* ######################################################## */
/* Diese Funktion berechnet den Zentrierungsparameter sigma */
/* ######################################################## */
static void mpc123_glqdocpip_calc_sigma()
{
mpc123_vv_elediv_1(mpc123_mu_aff, mpc123_mu, mpc123_tmp1_1);
if(mpc123_termcode > -1){return;}
mpc123_sigma[0] = pow(*mpc123_tmp1_1, *mpc123_tau);
}


/* ########################################################### */
/* Diese Funktion berechnet die maximal mögliche Schrittweite, */
/* bei der y und nu noch positiv bleiben */
/* ########################################################### */
static void mpc123_glqdocpip_max_stepsize()
{
int i;
  int i1;

mpc123_alpha_max[0] = -FLT_MAX;
mpc123_alpha_tmp[0] = 0;

/* Zeitschritt 0 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc123_arr_t1[2691+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[2658+i], &mpc123_arr_t1[2691+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[2658+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2691+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2666+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2699+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[2699+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[2666+i], &mpc123_arr_t1[2699+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[2658+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2691+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2666+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2699+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 1 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[2994+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[2941+i], &mpc123_arr_t1[2994+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[2941+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2994+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2957+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3010+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[3010+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[2957+i], &mpc123_arr_t1[3010+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[2941+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2994+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[2957+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3010+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 2 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[3381+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[3328+i], &mpc123_arr_t1[3381+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[3328+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3381+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3344+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3397+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[3397+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[3344+i], &mpc123_arr_t1[3397+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[3328+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3381+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3344+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3397+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 3 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[3768+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[3715+i], &mpc123_arr_t1[3768+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[3715+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3768+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3731+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3784+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[3784+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[3731+i], &mpc123_arr_t1[3784+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[3715+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3768+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3731+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[3784+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 4 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[4155+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4102+i], &mpc123_arr_t1[4155+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4102+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4155+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4118+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4171+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[4171+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4118+i], &mpc123_arr_t1[4171+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4102+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4155+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4118+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4171+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 5 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[4542+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4489+i], &mpc123_arr_t1[4542+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4489+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4542+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4505+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4558+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[4558+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4505+i], &mpc123_arr_t1[4558+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4489+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4542+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4505+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4558+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 6 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[4929+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4876+i], &mpc123_arr_t1[4929+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4876+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4929+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4892+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4945+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[4945+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[4892+i], &mpc123_arr_t1[4945+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[4876+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4929+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4892+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[4945+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 7 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[5316+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[5263+i], &mpc123_arr_t1[5316+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[5263+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5316+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5279+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5332+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[5332+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[5279+i], &mpc123_arr_t1[5332+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[5263+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5316+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5279+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5332+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 8 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[5703+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[5650+i], &mpc123_arr_t1[5703+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[5650+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5703+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5666+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5719+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[5719+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[5666+i], &mpc123_arr_t1[5719+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[5650+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5703+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5666+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[5719+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 9 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[6090+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6037+i], &mpc123_arr_t1[6090+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6037+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6090+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6053+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6106+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[6106+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6053+i], &mpc123_arr_t1[6106+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6037+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6090+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6053+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6106+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 10 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc123_arr_t1[6477+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6424+i], &mpc123_arr_t1[6477+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6424+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6477+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6440+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6493+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[6493+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6440+i], &mpc123_arr_t1[6493+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6424+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6477+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6440+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6493+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 11 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc123_arr_t1[6840+i]< 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6807+i], &mpc123_arr_t1[6840+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6807+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6840+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6815+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6848+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc123_arr_t1[6848+i] < 0)
{
mpc123_vv_elediv_1(&mpc123_arr_t1[6815+i], &mpc123_arr_t1[6848+i], mpc123_alpha_tmp);
if(mpc123_termcode > -1){return;}
if( *mpc123_alpha_tmp > *mpc123_alpha_max )
{
mpc123_alpha_max[0] = *mpc123_alpha_tmp;
mpc123_v_copy_1(&mpc123_arr_t1[6807+i], &mpc123_alpha_min_y[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6840+i], &mpc123_alpha_min_dy[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6815+i], &mpc123_alpha_min_nu[0]);
mpc123_v_copy_1(&mpc123_arr_t1[6848+i], &mpc123_alpha_min_dnu[0]);
mpc123_alpha_min_source_y = 0;
}
}
}

mpc123_v_turnsign_1(&mpc123_alpha_max[0], &mpc123_alpha_max[0]);
}


/* ####################################################### */
/* Diese Funktion berechnet die Schrittweite nach Mehrotra */
/* ####################################################### */
static void mpc123_glqdocpip_mehrotra_step()
{

/* FPD */
if (mpc123_alpha_min_source_y == 1) {
/* alpha_max durch y verursacht */
mpc123_vv_elemult_1(mpc123_alpha_max, mpc123_alpha_min_dnu, mpc123_mehrotra_fpd);
mpc123_vadd_1(mpc123_mehrotra_fpd, mpc123_alpha_min_nu, mpc123_mehrotra_fpd);
mpc123_vv_elediv_1(mpc123_mu_aff, mpc123_mehrotra_fpd, mpc123_mehrotra_fpd);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_1(mpc123_mehrotra_fpd, mpc123_mehrotra_gamma, mpc123_mehrotra_fpd);
mpc123_vsub_1(mpc123_mehrotra_fpd, mpc123_alpha_min_y, mpc123_mehrotra_fpd);
mpc123_vv_elemult_1(mpc123_alpha_max, mpc123_alpha_min_dy, mpc123_tmp1_1);
mpc123_vv_elediv_1(mpc123_mehrotra_fpd, mpc123_tmp1_1, mpc123_mehrotra_fpd);
if(mpc123_termcode > -1){return;}
} else {
/* alpha_max durch nu verursacht */
mpc123_vv_elemult_1(mpc123_alpha_max, mpc123_alpha_min_dy, mpc123_mehrotra_fpd);
mpc123_vadd_1(mpc123_mehrotra_fpd, mpc123_alpha_min_y, mpc123_mehrotra_fpd);
mpc123_vv_elediv_1(mpc123_mu_aff, mpc123_mehrotra_fpd, mpc123_mehrotra_fpd);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_1(mpc123_mehrotra_fpd, mpc123_mehrotra_gamma, mpc123_mehrotra_fpd);
mpc123_vsub_1(mpc123_mehrotra_fpd, mpc123_alpha_min_nu, mpc123_mehrotra_fpd);
mpc123_vv_elemult_1(mpc123_alpha_max, mpc123_alpha_min_dnu, mpc123_tmp1_1);
mpc123_vv_elediv_1(mpc123_mehrotra_fpd, mpc123_tmp1_1, mpc123_mehrotra_fpd);
if(mpc123_termcode > -1){return;}
}
/* Schrittweitenfaktor begrenzen */
/* Nach unten limitieren (1-gamma) */
mpc123_v_init1_1(mpc123_tmp1_1);
mpc123_vsub_1(mpc123_tmp1_1, mpc123_mehrotra_gamma, mpc123_tmp1_1);
mpc123_max(mpc123_mehrotra_fpd, mpc123_tmp1_1, mpc123_mehrotra_fpd);
/* nach oben limitieren (1-macheps) */
mpc123_v_init1_1(mpc123_tmp1_1);
mpc123_vsub_1(mpc123_tmp1_1, mpc123_macheps, mpc123_tmp1_1);
mpc123_min(mpc123_mehrotra_fpd, mpc123_tmp1_1, mpc123_mehrotra_fpd);
/* Schrittweite berechnen */
mpc123_vv_elemult_1(mpc123_mehrotra_fpd, mpc123_alpha_max, mpc123_mehrotra_alpha);
/* Schritt begrenzen 0 =< alpha =< 1 */
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(mpc123_mehrotra_alpha, mpc123_tmp1_1, mpc123_mehrotra_alpha);
mpc123_v_init1_1(mpc123_tmp1_1);
mpc123_min(mpc123_mehrotra_alpha, mpc123_tmp1_1, mpc123_mehrotra_alpha);
}


/* ########################################### */
/* Diese Funktion berechnet die Dualitätslücke */
/* ########################################### */
static void mpc123_glqdocpip_calc_duality_gap()
{
  int i1;
mpc123_v_init0_1(mpc123_dgap);
/* Zeitschritt 0 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid21_sid2_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[2641], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[2641], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid24_sid5_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2647], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[2641], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[2641], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid27_sid5_1_1(&mpc123_arr_t1[43], &mpc123_arr_t1[2647], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[2647], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[44], &mpc123_arr_t1[2648], mpc123_tmp3_4_1);
mpc123_vtv_4(&mpc123_arr_t1[2648], mpc123_tmp3_4_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[60], &mpc123_arr_t1[2641], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[66], &mpc123_arr_t1[2647], mpc123_dgap);
mpc123_vtv_4(&mpc123_arr_t1[67], &mpc123_arr_t1[2648], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(mpc123_xinit, &mpc123_arr_t1[2652], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_4(&mpc123_arr_t1[147], &mpc123_arr_t1[2658], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 1 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[151], &mpc123_arr_t1[2920], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[2920], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[2926], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[2920], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[2920], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[193], &mpc123_arr_t1[2926], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[2926], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[194], &mpc123_arr_t1[2927], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[2927], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[258], &mpc123_arr_t1[2920], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[264], &mpc123_arr_t1[2926], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[265], &mpc123_arr_t1[2927], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[113], &mpc123_arr_t1[2935], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[377], &mpc123_arr_t1[2941], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 2 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[385], &mpc123_arr_t1[3307], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[3307], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3313], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[3307], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[3307], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[427], &mpc123_arr_t1[3313], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[3313], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[428], &mpc123_arr_t1[3314], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[3314], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[492], &mpc123_arr_t1[3307], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[498], &mpc123_arr_t1[3313], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[499], &mpc123_arr_t1[3314], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[315], &mpc123_arr_t1[3322], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[611], &mpc123_arr_t1[3328], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 3 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[619], &mpc123_arr_t1[3694], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[3694], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3700], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[3694], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[3694], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[661], &mpc123_arr_t1[3700], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[3700], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[662], &mpc123_arr_t1[3701], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[3701], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[726], &mpc123_arr_t1[3694], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[732], &mpc123_arr_t1[3700], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[733], &mpc123_arr_t1[3701], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[549], &mpc123_arr_t1[3709], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[845], &mpc123_arr_t1[3715], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 4 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[853], &mpc123_arr_t1[4081], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4081], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4087], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4081], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[4081], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[895], &mpc123_arr_t1[4087], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[4087], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[896], &mpc123_arr_t1[4088], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[4088], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[960], &mpc123_arr_t1[4081], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[966], &mpc123_arr_t1[4087], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[967], &mpc123_arr_t1[4088], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[783], &mpc123_arr_t1[4096], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[1079], &mpc123_arr_t1[4102], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 5 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1087], &mpc123_arr_t1[4468], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4468], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4474], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4468], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[4468], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1129], &mpc123_arr_t1[4474], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[4474], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1130], &mpc123_arr_t1[4475], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[4475], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[1194], &mpc123_arr_t1[4468], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[1200], &mpc123_arr_t1[4474], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[1201], &mpc123_arr_t1[4475], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[1017], &mpc123_arr_t1[4483], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[1313], &mpc123_arr_t1[4489], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 6 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1321], &mpc123_arr_t1[4855], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4855], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[4861], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[4855], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[4855], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1363], &mpc123_arr_t1[4861], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[4861], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1364], &mpc123_arr_t1[4862], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[4862], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[1428], &mpc123_arr_t1[4855], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[1434], &mpc123_arr_t1[4861], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[1435], &mpc123_arr_t1[4862], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[1251], &mpc123_arr_t1[4870], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[1547], &mpc123_arr_t1[4876], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 7 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1555], &mpc123_arr_t1[5242], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[5242], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5248], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[5242], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[5242], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1597], &mpc123_arr_t1[5248], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[5248], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1598], &mpc123_arr_t1[5249], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[5249], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[1662], &mpc123_arr_t1[5242], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[1668], &mpc123_arr_t1[5248], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[1669], &mpc123_arr_t1[5249], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[1485], &mpc123_arr_t1[5257], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[1781], &mpc123_arr_t1[5263], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 8 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1789], &mpc123_arr_t1[5629], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[5629], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5635], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[5629], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[5629], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1831], &mpc123_arr_t1[5635], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[5635], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1832], &mpc123_arr_t1[5636], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[5636], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[1896], &mpc123_arr_t1[5629], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[1902], &mpc123_arr_t1[5635], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[1903], &mpc123_arr_t1[5636], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[1719], &mpc123_arr_t1[5644], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[2015], &mpc123_arr_t1[5650], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 9 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2023], &mpc123_arr_t1[6016], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6016], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6022], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6016], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[6016], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2065], &mpc123_arr_t1[6022], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[6022], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2066], &mpc123_arr_t1[6023], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[6023], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[2130], &mpc123_arr_t1[6016], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[2136], &mpc123_arr_t1[6022], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[2137], &mpc123_arr_t1[6023], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[1953], &mpc123_arr_t1[6031], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[2249], &mpc123_arr_t1[6037], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 10 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2257], &mpc123_arr_t1[6403], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6403], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6409], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6403], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[6403], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2299], &mpc123_arr_t1[6409], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[6409], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2300], &mpc123_arr_t1[6410], mpc123_tmp2_8_1);
mpc123_vtv_8(&mpc123_arr_t1[6410], mpc123_tmp2_8_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[2364], &mpc123_arr_t1[6403], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[2370], &mpc123_arr_t1[6409], mpc123_dgap);
mpc123_vtv_8(&mpc123_arr_t1[2371], &mpc123_arr_t1[6410], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[2187], &mpc123_arr_t1[6418], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_8(&mpc123_arr_t1[2483], &mpc123_arr_t1[6424], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Zeitschritt 11 */
/* Quadratischer Anteil */
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid23_sid2_6_6(&mpc123_arr_t1[2491], &mpc123_arr_t1[6790], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6790], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_6(mpc123_tmp1_6_1);
mpc123_mv_sid26_sid5_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6796], mpc123_tmp1_6_1);
mpc123_vtv_6(&mpc123_arr_t1[6790], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_vtv_6(&mpc123_arr_t1[6790], mpc123_tmp1_6_1, mpc123_dgap);
mpc123_v_init0_1(mpc123_tmp1_1_1);
mpc123_mv_sid29_sid5_1_1(&mpc123_arr_t1[2533], &mpc123_arr_t1[6796], mpc123_tmp1_1_1);
mpc123_vtv_1(&mpc123_arr_t1[6796], mpc123_tmp1_1_1, mpc123_dgap);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[2534], &mpc123_arr_t1[6797], mpc123_tmp3_4_1);
mpc123_vtv_4(&mpc123_arr_t1[6797], mpc123_tmp3_4_1, mpc123_dgap);
/* Linearer Anteil */
mpc123_vtv_6(&mpc123_arr_t1[2550], &mpc123_arr_t1[6790], mpc123_dgap);
mpc123_vtv_1(&mpc123_arr_t1[2556], &mpc123_arr_t1[6796], mpc123_dgap);
mpc123_vtv_4(&mpc123_arr_t1[2557], &mpc123_arr_t1[6797], mpc123_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_6(&mpc123_arr_t1[2421], &mpc123_arr_t1[6801], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc123_v_init0_1(mpc123_tmp2_1_1);
mpc123_vtv_4(&mpc123_arr_t1[2637], &mpc123_arr_t1[6807], mpc123_tmp2_1_1);
mpc123_vsub_1(mpc123_dgap, mpc123_tmp2_1_1, mpc123_dgap);
/* dgap = abs(dgap) */
if(mpc123_dgap[0] < 0){
mpc123_dgap[0] = -mpc123_dgap[0];}
}


/* ############################################################ */
/* Diese Funktion berechnet die Unendlichnorm der Eingangsdaten */
/* ############################################################ */
static void mpc123_glqdocpip_calc_norm_d()
{
  int i1;
mpc123_v_init1_1(mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[37], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[43], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_4(&mpc123_arr_t1[44], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[60], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[66], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[67], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[71], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[107], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[113], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_4_6(&mpc123_arr_t1[119], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[143], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[147], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[151], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[187], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[193], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[194], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[258], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[264], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[265], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[273], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[309], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[315], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[321], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[369], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[377], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[385], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[421], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[427], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[428], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[492], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[498], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[499], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[507], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[543], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[549], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[555], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[603], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[611], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[619], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[655], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[661], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[662], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[726], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[732], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[733], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[741], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[777], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[783], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[789], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[837], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[845], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[853], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[889], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[895], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[896], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[960], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[966], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[967], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[975], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1011], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1017], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[1023], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1071], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1079], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1087], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1123], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1129], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[1130], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1194], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1200], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1201], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1209], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1245], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1251], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[1257], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1305], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1313], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1321], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1357], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1363], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[1364], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1428], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1434], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1435], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1443], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1479], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1485], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[1491], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1539], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1547], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1555], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1591], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1597], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[1598], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1662], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1668], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1669], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1677], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1713], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1719], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[1725], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1773], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1781], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1789], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1825], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1831], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[1832], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1896], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[1902], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[1903], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[1911], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1947], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[1953], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[1959], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2007], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2015], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2023], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2059], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2065], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[2066], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2130], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2136], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2137], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2145], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2181], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2187], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[2193], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2241], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2249], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2257], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2293], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2299], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_8(&mpc123_arr_t1[2300], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2364], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2370], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2371], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2379], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2415], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2421], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_8_6(&mpc123_arr_t1[2427], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2475], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_8_1(&mpc123_arr_t1[2483], mpc123_norm_d, mpc123_norm_d);
/* Aus Gütefunktion */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2491], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2527], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2533], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_4(&mpc123_arr_t1[2534], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2550], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2556], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[2557], mpc123_norm_d, mpc123_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc123_norm_inf_6_6(&mpc123_arr_t1[2561], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2597], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_6_1(&mpc123_arr_t1[2603], mpc123_norm_d, mpc123_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc123_norm_inf_4_6(&mpc123_arr_t1[2609], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[2633], mpc123_norm_d, mpc123_norm_d);
mpc123_norm_inf_4_1(&mpc123_arr_t1[2637], mpc123_norm_d, mpc123_norm_d);
}


/* ############################################################# */
/* Diese Funktion berechnet die Unendlichnorm der rechten Seiten */
/* ############################################################# */
static void mpc123_glqdocpip_calc_norm_r()
{
  int i1;
/* norm_r_prev bestimmen */
if(mpc123_iter > 0){
mpc123_v_copy_1(mpc123_norm_r, mpc123_norm_r_prev);
}
mpc123_v_init0_1(mpc123_norm_r);
/* Zeitschritt 0 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[2707], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[2713], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_4_1(&mpc123_arr_t1[2714], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[2718], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_4_1(&mpc123_arr_t1[2724], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_4_1(&mpc123_arr_t1[2728], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[2732], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 1 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3026], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[3032], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3033], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3041], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[3047], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3055], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[3063], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 2 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3413], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[3419], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3420], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3428], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[3434], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3442], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[3450], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 3 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3800], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[3806], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3807], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[3815], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[3821], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[3829], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[3837], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 4 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4187], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[4193], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4194], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4202], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[4208], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4216], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[4224], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 5 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4574], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[4580], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4581], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4589], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[4595], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4603], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[4611], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 6 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4961], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[4967], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4968], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[4976], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[4982], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[4990], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[4998], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 7 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[5348], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[5354], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[5355], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[5363], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[5369], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[5377], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[5385], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 8 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[5735], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[5741], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[5742], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[5750], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[5756], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[5764], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[5772], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 9 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6122], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[6128], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[6129], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6137], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[6143], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[6151], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[6159], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 10 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6509], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[6515], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[6516], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6524], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[6530], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_8_1(&mpc123_arr_t1[6538], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_16_1(&mpc123_arr_t1[6546], mpc123_norm_r, mpc123_norm_r);
/* Zeitschritt 11 */
/* Aus Gütefunktion */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6856], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_1_1(&mpc123_arr_t1[6862], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_4_1(&mpc123_arr_t1[6863], mpc123_norm_r, mpc123_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc123_norm_inf_6_1(&mpc123_arr_t1[6867], mpc123_norm_r, mpc123_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc123_norm_inf_4_1(&mpc123_arr_t1[6873], mpc123_norm_r, mpc123_norm_r);
mpc123_norm_inf_4_1(&mpc123_arr_t1[6877], mpc123_norm_r, mpc123_norm_r);
/* Aus Komplementaritätsbedingung */
mpc123_norm_inf_8_1(&mpc123_arr_t1[6881], mpc123_norm_r, mpc123_norm_r);
/* norm_r0 bestimmen */
if(mpc123_iter == 0){
mpc123_v_copy_1(mpc123_norm_r, mpc123_norm_r0);
}
}


/* ###################################### */
/* Diese Funktion führt einen Schritt aus */
/* ###################################### */
static void mpc123_glqdocpip_step()
{
  int i1;
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[2674], &mpc123_arr_t1[2641]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[2680], &mpc123_arr_t1[2647]);
mpc123_sv_4(mpc123_mehrotra_alpha, &mpc123_arr_t1[2681], &mpc123_arr_t1[2648]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[2685], &mpc123_arr_t1[2652]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[2691], &mpc123_arr_t1[2658]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[2699], &mpc123_arr_t1[2666]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[2973], &mpc123_arr_t1[2920]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[2979], &mpc123_arr_t1[2926]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[2980], &mpc123_arr_t1[2927]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[2988], &mpc123_arr_t1[2935]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[2994], &mpc123_arr_t1[2941]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[3010], &mpc123_arr_t1[2957]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[3360], &mpc123_arr_t1[3307]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[3366], &mpc123_arr_t1[3313]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[3367], &mpc123_arr_t1[3314]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[3375], &mpc123_arr_t1[3322]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[3381], &mpc123_arr_t1[3328]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[3397], &mpc123_arr_t1[3344]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[3747], &mpc123_arr_t1[3694]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[3753], &mpc123_arr_t1[3700]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[3754], &mpc123_arr_t1[3701]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[3762], &mpc123_arr_t1[3709]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[3768], &mpc123_arr_t1[3715]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[3784], &mpc123_arr_t1[3731]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4134], &mpc123_arr_t1[4081]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[4140], &mpc123_arr_t1[4087]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[4141], &mpc123_arr_t1[4088]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4149], &mpc123_arr_t1[4096]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4155], &mpc123_arr_t1[4102]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4171], &mpc123_arr_t1[4118]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4521], &mpc123_arr_t1[4468]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[4527], &mpc123_arr_t1[4474]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[4528], &mpc123_arr_t1[4475]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4536], &mpc123_arr_t1[4483]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4542], &mpc123_arr_t1[4489]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4558], &mpc123_arr_t1[4505]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4908], &mpc123_arr_t1[4855]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[4914], &mpc123_arr_t1[4861]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[4915], &mpc123_arr_t1[4862]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[4923], &mpc123_arr_t1[4870]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4929], &mpc123_arr_t1[4876]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[4945], &mpc123_arr_t1[4892]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[5295], &mpc123_arr_t1[5242]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[5301], &mpc123_arr_t1[5248]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[5302], &mpc123_arr_t1[5249]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[5310], &mpc123_arr_t1[5257]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[5316], &mpc123_arr_t1[5263]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[5332], &mpc123_arr_t1[5279]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[5682], &mpc123_arr_t1[5629]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[5688], &mpc123_arr_t1[5635]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[5689], &mpc123_arr_t1[5636]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[5697], &mpc123_arr_t1[5644]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[5703], &mpc123_arr_t1[5650]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[5719], &mpc123_arr_t1[5666]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6069], &mpc123_arr_t1[6016]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[6075], &mpc123_arr_t1[6022]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[6076], &mpc123_arr_t1[6023]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6084], &mpc123_arr_t1[6031]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[6090], &mpc123_arr_t1[6037]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[6106], &mpc123_arr_t1[6053]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6456], &mpc123_arr_t1[6403]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[6462], &mpc123_arr_t1[6409]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[6463], &mpc123_arr_t1[6410]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6471], &mpc123_arr_t1[6418]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[6477], &mpc123_arr_t1[6424]);
mpc123_sv_16(mpc123_mehrotra_alpha, &mpc123_arr_t1[6493], &mpc123_arr_t1[6440]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6823], &mpc123_arr_t1[6790]);
mpc123_sv_1(mpc123_mehrotra_alpha, &mpc123_arr_t1[6829], &mpc123_arr_t1[6796]);
mpc123_sv_4(mpc123_mehrotra_alpha, &mpc123_arr_t1[6830], &mpc123_arr_t1[6797]);
mpc123_sv_6(mpc123_mehrotra_alpha, &mpc123_arr_t1[6834], &mpc123_arr_t1[6801]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[6840], &mpc123_arr_t1[6807]);
mpc123_sv_8(mpc123_mehrotra_alpha, &mpc123_arr_t1[6848], &mpc123_arr_t1[6815]);
}


/* ######################################################### */
/* Diese Funktion führt Konvergenz- und Divergenztests durch */
/* ######################################################### */
static void mpc123_glqdocpip_check_condiv()
{
/* Termcode 0 - Success */
if(mpc123_mu[0] <= mpc123_tol[0]){
mpc123_vv_elemult_1(mpc123_tol, mpc123_norm_d, mpc123_tmp1_1);
  if(mpc123_norm_r[0] <= mpc123_tmp1_1[0]){
  mpc123_termcode = 0;
  return;
  }
}

/* Termcode 1 - infeasible */
if(mpc123_phi[0] > mpc123_tol[0]){
mpc123_vv_elemult_1(mpc123_tc1_factor, mpc123_minphi, mpc123_tmp1_1);
  if(mpc123_phi[0] >= mpc123_tmp1_1[0]){
  mpc123_termcode = 1;
  return;
  }
}

/* Termcode 2 - slow convergence */
mpc123_vv_elemult_1(mpc123_tol, mpc123_norm_d, mpc123_tmp1_1);
if(mpc123_norm_r[0] > mpc123_tmp1_1[0]){
mpc123_vv_elediv_1(mpc123_norm_r, mpc123_mu, mpc123_tmp1_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_1(mpc123_norm_r0, mpc123_mu0, mpc123_tmp2_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_1(mpc123_tc2_factor, mpc123_tmp2_1, mpc123_tmp2_1);
  if(mpc123_tmp1_1[0] >= mpc123_tmp2_1[0]){
  mpc123_termcode = 2;
  return;
  }
}

/* Termcode 7 - calculation time limit exceeded */
if(mpc123_iter > 0){
  if(mpc123_glqdocpip_timer_get()*(double)mpc123_iter/ (double) (mpc123_iter + 1) > mpc123_time_max){
    mpc123_termcode = 7;
    return;
  }
}

/* iterative refinement */
/* ### FLAGS ### */
/* # keep_iterative_refinements_on = 0 */
/* # iterative_refinements_require_norm_r_is_not_too_small = 0 */
/* ############# */
mpc123_iter_ref = 0;
if(mpc123_iter > 0){
mpc123_tmp1_1[0] = 100;
mpc123_vv_elemult_1(mpc123_tmp1_1, mpc123_tol, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_norm_d, mpc123_tmp2_1, mpc123_tmp2_1);
if(mpc123_norm_r_prev[0] > mpc123_tmp2_1[0]){
mpc123_tmp1_1[0] = 1.001;
mpc123_vv_elemult_1(mpc123_tmp1_1, mpc123_norm_r_prev, mpc123_tmp2_1);
if(mpc123_norm_r[0] > mpc123_tmp2_1[0]){
mpc123_iter_ref = 1;
}
}
}

}


/* ################################################ */
/* Diese Funktion speichert Daten für die Statistik */
/* ################################################ */
static void mpc123_glqdocpip_stat()
{
/* Zeit */
mpc123_stat_time[mpc123_iter] = mpc123_glqdocpip_timer_get();
}


/* ############################################### */
/*   Diese Funktion speichert Daten zum Debuggen */
/* vor der Überprüfung der Kon-/Divergenzkriterien */
/* ############################################### */
static void mpc123_glqdocpip_debug1()
{

/* dgap */
mpc123_debug_dgap[mpc123_iter] = mpc123_dgap[0];

/* phi */
mpc123_debug_phi[mpc123_iter] = mpc123_phi[0];

/* minphi */
mpc123_debug_minphi[mpc123_iter] = mpc123_minphi[0];

/* norm_d */
mpc123_debug_norm_d[0] = mpc123_norm_d[0];

/* norm_r */
mpc123_debug_norm_r[mpc123_iter] = mpc123_norm_r[0];

/* norm_r0 */
mpc123_debug_norm_r0[0] = mpc123_norm_r0[0];

/* mu */
mpc123_debug_mu[mpc123_iter] = mpc123_mu[0];

/* mu0 */
mpc123_debug_mu0[0] = mpc123_mu0[0];
}


/* ########################################### */
/* Diese Funktion speichert Daten zum Debuggen */
/*      vor dem Durchführen des Schrittes */
/* ########################################### */
static void mpc123_glqdocpip_debug2()
{

/* sigma */
mpc123_debug_sigma[mpc123_iter] = mpc123_sigma[0];

/* alpha_max */
mpc123_debug_alpha_max[mpc123_iter] = mpc123_alpha_max[0];

/* mehrotra_alpha */
mpc123_debug_mehrotra_alpha[mpc123_iter] = mpc123_mehrotra_alpha[0];

/* mu_aff */
mpc123_debug_mu_aff[mpc123_iter] = mpc123_mu_aff[0];
}


static void mpc123_glqdocpip_factor()
{
  int i1;
mpc123_error_source = 1;
mpc123_stat_num_factor++;
/* Factor: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[2491], &mpc123_arr_t1[6904]);
mpc123_m_copy_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6940]);
mpc123_m_init0_6_4(mpc123_tmp1_6_4);
mpc123_mtd_sid53_sid17_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6900], mpc123_tmp1_6_4);
mpc123_mm_y_sid14_sid53_6_4_6(mpc123_tmp1_6_4, &mpc123_arr_t1[2609], &mpc123_arr_t1[6904]);
mpc123_mm_sid14_sid56_6_4_1(mpc123_tmp1_6_4, &mpc123_arr_t1[2633], &mpc123_arr_t1[6940]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[2533], &mpc123_arr_t1[6946]);
mpc123_m_init0_1_4(mpc123_tmp1_1_4);
mpc123_mtd_sid56_sid17_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6900], mpc123_tmp1_1_4);
mpc123_mm_1_4_1(mpc123_tmp1_1_4, &mpc123_arr_t1[2633], &mpc123_arr_t1[6946]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[6940], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[6946], &mpc123_arr_t1[7080]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7080], mpc123_tmp1_1_6, &mpc123_arr_t1[6947]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[6953]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[6940], &mpc123_arr_t1[6947], &mpc123_arr_t1[6953]);
mpc123_msub_6_6(&mpc123_arr_t1[6904], &mpc123_arr_t1[6953], &mpc123_arr_t1[6953]);
/* Zeitschritt 10 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[2257], &mpc123_arr_t1[6585]);
mpc123_m_copy_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6621]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6953], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[2379], &mpc123_arr_t1[6585]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[2415], &mpc123_arr_t1[6621]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6577], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[2427], &mpc123_arr_t1[6585]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[2475], &mpc123_arr_t1[6621]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[2299], &mpc123_arr_t1[6627]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[2415], &mpc123_arr_t1[6953], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[2415], &mpc123_arr_t1[6627]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6577], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[2475], &mpc123_arr_t1[6627]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[6621], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[6627], &mpc123_arr_t1[7079]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7079], mpc123_tmp1_1_6, &mpc123_arr_t1[6628]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[6634]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[6621], &mpc123_arr_t1[6628], &mpc123_arr_t1[6634]);
mpc123_msub_6_6(&mpc123_arr_t1[6585], &mpc123_arr_t1[6634], &mpc123_arr_t1[6634]);
/* Zeitschritt 9 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[2023], &mpc123_arr_t1[6198]);
mpc123_m_copy_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6234]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6634], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[2145], &mpc123_arr_t1[6198]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[2181], &mpc123_arr_t1[6234]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6190], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[2193], &mpc123_arr_t1[6198]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[2241], &mpc123_arr_t1[6234]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[2065], &mpc123_arr_t1[6240]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[2181], &mpc123_arr_t1[6634], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[2181], &mpc123_arr_t1[6240]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6190], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[2241], &mpc123_arr_t1[6240]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[6234], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[6240], &mpc123_arr_t1[7078]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7078], mpc123_tmp1_1_6, &mpc123_arr_t1[6241]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[6247]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[6234], &mpc123_arr_t1[6241], &mpc123_arr_t1[6247]);
mpc123_msub_6_6(&mpc123_arr_t1[6198], &mpc123_arr_t1[6247], &mpc123_arr_t1[6247]);
/* Zeitschritt 8 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[1789], &mpc123_arr_t1[5811]);
mpc123_m_copy_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5847]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[6247], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[1911], &mpc123_arr_t1[5811]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[1947], &mpc123_arr_t1[5847]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5803], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[1959], &mpc123_arr_t1[5811]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[2007], &mpc123_arr_t1[5847]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[1831], &mpc123_arr_t1[5853]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[1947], &mpc123_arr_t1[6247], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[1947], &mpc123_arr_t1[5853]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5803], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[2007], &mpc123_arr_t1[5853]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[5847], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[5853], &mpc123_arr_t1[7077]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7077], mpc123_tmp1_1_6, &mpc123_arr_t1[5854]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[5860]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[5847], &mpc123_arr_t1[5854], &mpc123_arr_t1[5860]);
mpc123_msub_6_6(&mpc123_arr_t1[5811], &mpc123_arr_t1[5860], &mpc123_arr_t1[5860]);
/* Zeitschritt 7 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[1555], &mpc123_arr_t1[5424]);
mpc123_m_copy_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5460]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5860], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[1677], &mpc123_arr_t1[5424]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[1713], &mpc123_arr_t1[5460]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5416], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[1725], &mpc123_arr_t1[5424]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[1773], &mpc123_arr_t1[5460]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[1597], &mpc123_arr_t1[5466]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[1713], &mpc123_arr_t1[5860], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[1713], &mpc123_arr_t1[5466]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5416], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[1773], &mpc123_arr_t1[5466]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[5460], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[5466], &mpc123_arr_t1[7076]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7076], mpc123_tmp1_1_6, &mpc123_arr_t1[5467]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[5473]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[5460], &mpc123_arr_t1[5467], &mpc123_arr_t1[5473]);
mpc123_msub_6_6(&mpc123_arr_t1[5424], &mpc123_arr_t1[5473], &mpc123_arr_t1[5473]);
/* Zeitschritt 6 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[1321], &mpc123_arr_t1[5037]);
mpc123_m_copy_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[5073]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[5473], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[1443], &mpc123_arr_t1[5037]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[1479], &mpc123_arr_t1[5073]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[5029], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[1491], &mpc123_arr_t1[5037]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[1539], &mpc123_arr_t1[5073]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[1363], &mpc123_arr_t1[5079]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[1479], &mpc123_arr_t1[5473], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[1479], &mpc123_arr_t1[5079]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[5029], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[1539], &mpc123_arr_t1[5079]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[5073], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[5079], &mpc123_arr_t1[7075]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7075], mpc123_tmp1_1_6, &mpc123_arr_t1[5080]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[5086]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[5073], &mpc123_arr_t1[5080], &mpc123_arr_t1[5086]);
mpc123_msub_6_6(&mpc123_arr_t1[5037], &mpc123_arr_t1[5086], &mpc123_arr_t1[5086]);
/* Zeitschritt 5 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[1087], &mpc123_arr_t1[4650]);
mpc123_m_copy_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4686]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[5086], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[1209], &mpc123_arr_t1[4650]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[1245], &mpc123_arr_t1[4686]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4642], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[1257], &mpc123_arr_t1[4650]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[1305], &mpc123_arr_t1[4686]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[1129], &mpc123_arr_t1[4692]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[1245], &mpc123_arr_t1[5086], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[1245], &mpc123_arr_t1[4692]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4642], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[1305], &mpc123_arr_t1[4692]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[4686], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[4692], &mpc123_arr_t1[7074]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7074], mpc123_tmp1_1_6, &mpc123_arr_t1[4693]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[4699]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[4686], &mpc123_arr_t1[4693], &mpc123_arr_t1[4699]);
mpc123_msub_6_6(&mpc123_arr_t1[4650], &mpc123_arr_t1[4699], &mpc123_arr_t1[4699]);
/* Zeitschritt 4 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[853], &mpc123_arr_t1[4263]);
mpc123_m_copy_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4299]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4699], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[975], &mpc123_arr_t1[4263]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[1011], &mpc123_arr_t1[4299]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4255], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[1023], &mpc123_arr_t1[4263]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[1071], &mpc123_arr_t1[4299]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[895], &mpc123_arr_t1[4305]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[1011], &mpc123_arr_t1[4699], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[1011], &mpc123_arr_t1[4305]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4255], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[1071], &mpc123_arr_t1[4305]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[4299], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[4305], &mpc123_arr_t1[7073]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7073], mpc123_tmp1_1_6, &mpc123_arr_t1[4306]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[4312]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[4299], &mpc123_arr_t1[4306], &mpc123_arr_t1[4312]);
mpc123_msub_6_6(&mpc123_arr_t1[4263], &mpc123_arr_t1[4312], &mpc123_arr_t1[4312]);
/* Zeitschritt 3 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[619], &mpc123_arr_t1[3876]);
mpc123_m_copy_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3912]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[4312], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[741], &mpc123_arr_t1[3876]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[777], &mpc123_arr_t1[3912]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3868], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[789], &mpc123_arr_t1[3876]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[837], &mpc123_arr_t1[3912]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[661], &mpc123_arr_t1[3918]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[777], &mpc123_arr_t1[4312], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[777], &mpc123_arr_t1[3918]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3868], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[837], &mpc123_arr_t1[3918]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[3912], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[3918], &mpc123_arr_t1[7072]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7072], mpc123_tmp1_1_6, &mpc123_arr_t1[3919]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[3925]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[3912], &mpc123_arr_t1[3919], &mpc123_arr_t1[3925]);
mpc123_msub_6_6(&mpc123_arr_t1[3876], &mpc123_arr_t1[3925], &mpc123_arr_t1[3925]);
/* Zeitschritt 2 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[385], &mpc123_arr_t1[3489]);
mpc123_m_copy_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3525]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3925], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[507], &mpc123_arr_t1[3489]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[543], &mpc123_arr_t1[3525]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3481], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[555], &mpc123_arr_t1[3489]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[603], &mpc123_arr_t1[3525]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[427], &mpc123_arr_t1[3531]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[543], &mpc123_arr_t1[3925], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[543], &mpc123_arr_t1[3531]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3481], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[603], &mpc123_arr_t1[3531]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[3525], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[3531], &mpc123_arr_t1[7071]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7071], mpc123_tmp1_1_6, &mpc123_arr_t1[3532]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[3538]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[3525], &mpc123_arr_t1[3532], &mpc123_arr_t1[3538]);
mpc123_msub_6_6(&mpc123_arr_t1[3489], &mpc123_arr_t1[3538], &mpc123_arr_t1[3538]);
/* Zeitschritt 1 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[151], &mpc123_arr_t1[3102]);
mpc123_m_copy_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[3138]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid43_sid1_6_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[3538], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid43_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[273], &mpc123_arr_t1[3102]);
mpc123_mm_sid1_sid46_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[309], &mpc123_arr_t1[3138]);
mpc123_m_init0_6_8(mpc123_tmp1_6_8);
mpc123_mtd_sid52_sid16_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[3094], mpc123_tmp1_6_8);
mpc123_mm_y_sid13_sid52_6_8_6(mpc123_tmp1_6_8, &mpc123_arr_t1[321], &mpc123_arr_t1[3102]);
mpc123_mm_sid13_sid55_6_8_1(mpc123_tmp1_6_8, &mpc123_arr_t1[369], &mpc123_arr_t1[3138]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[193], &mpc123_arr_t1[3144]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid46_sid1_6_1_6(&mpc123_arr_t1[309], &mpc123_arr_t1[3538], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid46_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[309], &mpc123_arr_t1[3144]);
mpc123_m_init0_1_8(mpc123_tmp1_1_8);
mpc123_mtd_sid55_sid16_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[3094], mpc123_tmp1_1_8);
mpc123_mm_1_8_1(mpc123_tmp1_1_8, &mpc123_arr_t1[369], &mpc123_arr_t1[3144]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[3138], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[3144], &mpc123_arr_t1[7070]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7070], mpc123_tmp1_1_6, &mpc123_arr_t1[3145]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[3151]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[3138], &mpc123_arr_t1[3145], &mpc123_arr_t1[3151]);
mpc123_msub_6_6(&mpc123_arr_t1[3102], &mpc123_arr_t1[3151], &mpc123_arr_t1[3151]);
/* Zeitschritt 0 */
/* Gxx und Gxu */
mpc123_m_copy_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[2755]);
mpc123_m_copy_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2791]);
mpc123_m_init0_6_6(mpc123_tmp1_6_6);
mpc123_mtm_sid42_sid1_6_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[3151], mpc123_tmp1_6_6);
mpc123_mm_y_sid1_sid42_6_6_6(mpc123_tmp1_6_6, &mpc123_arr_t1[71], &mpc123_arr_t1[2755]);
mpc123_mm_sid1_sid45_6_6_1(mpc123_tmp1_6_6, &mpc123_arr_t1[107], &mpc123_arr_t1[2791]);
mpc123_m_init0_6_4(mpc123_tmp1_6_4);
mpc123_mtd_sid51_sid15_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2751], mpc123_tmp1_6_4);
mpc123_mm_y_sid12_sid51_6_4_6(mpc123_tmp1_6_4, &mpc123_arr_t1[119], &mpc123_arr_t1[2755]);
mpc123_mm_sid12_sid54_6_4_1(mpc123_tmp1_6_4, &mpc123_arr_t1[143], &mpc123_arr_t1[2791]);
/* Guu */
mpc123_m_copy_1_1(&mpc123_arr_t1[43], &mpc123_arr_t1[2797]);
mpc123_m_init0_1_6(mpc123_tmp1_1_6);
mpc123_mtm_sid45_sid1_6_1_6(&mpc123_arr_t1[107], &mpc123_arr_t1[3151], mpc123_tmp1_1_6);
mpc123_mm_sid8_sid45_1_6_1(mpc123_tmp1_1_6, &mpc123_arr_t1[107], &mpc123_arr_t1[2797]);
mpc123_m_init0_1_4(mpc123_tmp1_1_4);
mpc123_mtd_sid54_sid15_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2751], mpc123_tmp1_1_4);
mpc123_mm_1_4_1(mpc123_tmp1_1_4, &mpc123_arr_t1[143], &mpc123_arr_t1[2797]);
/* Rux */
mpc123_mtr_6_1(&mpc123_arr_t1[2791], mpc123_tmp1_1_6);
mpc123_chol_factor_1(&mpc123_arr_t1[2797], &mpc123_arr_t1[7069]);
if(mpc123_termcode > -1){return;}
mpc123_chol_solve_1_6(&mpc123_arr_t1[7069], mpc123_tmp1_1_6, &mpc123_arr_t1[2798]);
if(mpc123_termcode > -1){return;}
mpc123_m_init0_6_6(&mpc123_arr_t1[2804]);
mpc123_mm_y_6_1_6(&mpc123_arr_t1[2791], &mpc123_arr_t1[2798], &mpc123_arr_t1[2804]);
mpc123_msub_6_6(&mpc123_arr_t1[2755], &mpc123_arr_t1[2804], &mpc123_arr_t1[2804]);
mpc123_error_source = 0;

}


static void mpc123_glqdocpip_solve()
{
  int i1;
mpc123_error_source = 2;
mpc123_stat_num_solve++;
/* Solve: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[6889], &mpc123_arr_t1[6989]);
mpc123_v_copy_1(&mpc123_arr_t1[6895], &mpc123_arr_t1[6995]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7080], &mpc123_arr_t1[6995], &mpc123_arr_t1[6996]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[6940], &mpc123_arr_t1[6996], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[6989], mpc123_tmp1_6, &mpc123_arr_t1[6997]);
/* Zeitschritt 10 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[6562], &mpc123_arr_t1[6670]);
mpc123_v_copy_1(&mpc123_arr_t1[6568], &mpc123_arr_t1[6676]);
mpc123_v_copy_6(&mpc123_arr_t1[6997], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[6953], &mpc123_arr_t1[6867], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2379], mpc123_tmp1_6, &mpc123_arr_t1[6670]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2415], mpc123_tmp1_6, &mpc123_arr_t1[6676]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7079], &mpc123_arr_t1[6676], &mpc123_arr_t1[6677]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[6621], &mpc123_arr_t1[6677], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[6670], mpc123_tmp1_6, &mpc123_arr_t1[6678]);
/* Zeitschritt 9 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[6175], &mpc123_arr_t1[6283]);
mpc123_v_copy_1(&mpc123_arr_t1[6181], &mpc123_arr_t1[6289]);
mpc123_v_copy_6(&mpc123_arr_t1[6678], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[6634], &mpc123_arr_t1[6524], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2145], mpc123_tmp1_6, &mpc123_arr_t1[6283]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2181], mpc123_tmp1_6, &mpc123_arr_t1[6289]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7078], &mpc123_arr_t1[6289], &mpc123_arr_t1[6290]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[6234], &mpc123_arr_t1[6290], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[6283], mpc123_tmp1_6, &mpc123_arr_t1[6291]);
/* Zeitschritt 8 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[5788], &mpc123_arr_t1[5896]);
mpc123_v_copy_1(&mpc123_arr_t1[5794], &mpc123_arr_t1[5902]);
mpc123_v_copy_6(&mpc123_arr_t1[6291], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[6247], &mpc123_arr_t1[6137], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1911], mpc123_tmp1_6, &mpc123_arr_t1[5896]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1947], mpc123_tmp1_6, &mpc123_arr_t1[5902]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7077], &mpc123_arr_t1[5902], &mpc123_arr_t1[5903]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[5847], &mpc123_arr_t1[5903], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[5896], mpc123_tmp1_6, &mpc123_arr_t1[5904]);
/* Zeitschritt 7 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[5401], &mpc123_arr_t1[5509]);
mpc123_v_copy_1(&mpc123_arr_t1[5407], &mpc123_arr_t1[5515]);
mpc123_v_copy_6(&mpc123_arr_t1[5904], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[5860], &mpc123_arr_t1[5750], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1677], mpc123_tmp1_6, &mpc123_arr_t1[5509]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1713], mpc123_tmp1_6, &mpc123_arr_t1[5515]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7076], &mpc123_arr_t1[5515], &mpc123_arr_t1[5516]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[5460], &mpc123_arr_t1[5516], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[5509], mpc123_tmp1_6, &mpc123_arr_t1[5517]);
/* Zeitschritt 6 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[5014], &mpc123_arr_t1[5122]);
mpc123_v_copy_1(&mpc123_arr_t1[5020], &mpc123_arr_t1[5128]);
mpc123_v_copy_6(&mpc123_arr_t1[5517], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[5473], &mpc123_arr_t1[5363], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1443], mpc123_tmp1_6, &mpc123_arr_t1[5122]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1479], mpc123_tmp1_6, &mpc123_arr_t1[5128]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7075], &mpc123_arr_t1[5128], &mpc123_arr_t1[5129]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[5073], &mpc123_arr_t1[5129], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[5122], mpc123_tmp1_6, &mpc123_arr_t1[5130]);
/* Zeitschritt 5 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[4627], &mpc123_arr_t1[4735]);
mpc123_v_copy_1(&mpc123_arr_t1[4633], &mpc123_arr_t1[4741]);
mpc123_v_copy_6(&mpc123_arr_t1[5130], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[5086], &mpc123_arr_t1[4976], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1209], mpc123_tmp1_6, &mpc123_arr_t1[4735]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1245], mpc123_tmp1_6, &mpc123_arr_t1[4741]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7074], &mpc123_arr_t1[4741], &mpc123_arr_t1[4742]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[4686], &mpc123_arr_t1[4742], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[4735], mpc123_tmp1_6, &mpc123_arr_t1[4743]);
/* Zeitschritt 4 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[4240], &mpc123_arr_t1[4348]);
mpc123_v_copy_1(&mpc123_arr_t1[4246], &mpc123_arr_t1[4354]);
mpc123_v_copy_6(&mpc123_arr_t1[4743], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[4699], &mpc123_arr_t1[4589], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[975], mpc123_tmp1_6, &mpc123_arr_t1[4348]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1011], mpc123_tmp1_6, &mpc123_arr_t1[4354]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7073], &mpc123_arr_t1[4354], &mpc123_arr_t1[4355]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[4299], &mpc123_arr_t1[4355], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[4348], mpc123_tmp1_6, &mpc123_arr_t1[4356]);
/* Zeitschritt 3 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[3853], &mpc123_arr_t1[3961]);
mpc123_v_copy_1(&mpc123_arr_t1[3859], &mpc123_arr_t1[3967]);
mpc123_v_copy_6(&mpc123_arr_t1[4356], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[4312], &mpc123_arr_t1[4202], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[741], mpc123_tmp1_6, &mpc123_arr_t1[3961]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[777], mpc123_tmp1_6, &mpc123_arr_t1[3967]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7072], &mpc123_arr_t1[3967], &mpc123_arr_t1[3968]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[3912], &mpc123_arr_t1[3968], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[3961], mpc123_tmp1_6, &mpc123_arr_t1[3969]);
/* Zeitschritt 2 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[3466], &mpc123_arr_t1[3574]);
mpc123_v_copy_1(&mpc123_arr_t1[3472], &mpc123_arr_t1[3580]);
mpc123_v_copy_6(&mpc123_arr_t1[3969], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[3925], &mpc123_arr_t1[3815], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[507], mpc123_tmp1_6, &mpc123_arr_t1[3574]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[543], mpc123_tmp1_6, &mpc123_arr_t1[3580]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7071], &mpc123_arr_t1[3580], &mpc123_arr_t1[3581]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[3525], &mpc123_arr_t1[3581], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[3574], mpc123_tmp1_6, &mpc123_arr_t1[3582]);
/* Zeitschritt 1 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[3079], &mpc123_arr_t1[3187]);
mpc123_v_copy_1(&mpc123_arr_t1[3085], &mpc123_arr_t1[3193]);
mpc123_v_copy_6(&mpc123_arr_t1[3582], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[3538], &mpc123_arr_t1[3428], mpc123_tmp1_6);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[273], mpc123_tmp1_6, &mpc123_arr_t1[3187]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[309], mpc123_tmp1_6, &mpc123_arr_t1[3193]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7070], &mpc123_arr_t1[3193], &mpc123_arr_t1[3194]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[3138], &mpc123_arr_t1[3194], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[3187], mpc123_tmp1_6, &mpc123_arr_t1[3195]);
/* Zeitschritt 0 */
/* Gx und Gu */
mpc123_v_copy_6(&mpc123_arr_t1[2740], &mpc123_arr_t1[2840]);
mpc123_v_copy_1(&mpc123_arr_t1[2746], &mpc123_arr_t1[2846]);
mpc123_v_copy_6(&mpc123_arr_t1[3195], mpc123_tmp1_6);
mpc123_mv_6_6(&mpc123_arr_t1[3151], &mpc123_arr_t1[3041], mpc123_tmp1_6);
mpc123_mtv_sid42_sid2_6_6(&mpc123_arr_t1[71], mpc123_tmp1_6, &mpc123_arr_t1[2840]);
mpc123_mtv_sid45_sid2_6_1(&mpc123_arr_t1[107], mpc123_tmp1_6, &mpc123_arr_t1[2846]);
/* Ru */
mpc123_chol_solve_1_1(&mpc123_arr_t1[7069], &mpc123_arr_t1[2846], &mpc123_arr_t1[2847]);
if(mpc123_termcode > -1){return;}
/* Vx */
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_v_init0_6(mpc123_tmp1_6);
mpc123_mv_6_1(&mpc123_arr_t1[2791], &mpc123_arr_t1[2847], mpc123_tmp1_6);
mpc123_vsub_6(&mpc123_arr_t1[2840], mpc123_tmp1_6, &mpc123_arr_t1[2848]);
/* Solve: Vorwärtsiteration */
/* dx0 */
mpc123_v_copy_6(&mpc123_arr_t1[2718], &mpc123_arr_t1[2674]);
/* Zeitschritt 0 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[2848], &mpc123_arr_t1[2685]);
mpc123_mv_6_6(&mpc123_arr_t1[2804], &mpc123_arr_t1[2674], &mpc123_arr_t1[2685]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[2847], &mpc123_arr_t1[2680]);
mpc123_mv_1_6(&mpc123_arr_t1[2798], &mpc123_arr_t1[2674], &mpc123_arr_t1[2680]);
mpc123_v_turnsign_1(&mpc123_arr_t1[2680], &mpc123_arr_t1[2680]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[3041], &mpc123_arr_t1[2973]);
mpc123_mv_sid42_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2674], &mpc123_arr_t1[2973]);
mpc123_mv_sid45_sid5_6_1(&mpc123_arr_t1[107], &mpc123_arr_t1[2680], &mpc123_arr_t1[2973]);
/* Zeitschritt 1 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[3195], &mpc123_arr_t1[2988]);
mpc123_mv_6_6(&mpc123_arr_t1[3151], &mpc123_arr_t1[2973], &mpc123_arr_t1[2988]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[3194], &mpc123_arr_t1[2979]);
mpc123_mv_1_6(&mpc123_arr_t1[3145], &mpc123_arr_t1[2973], &mpc123_arr_t1[2979]);
mpc123_v_turnsign_1(&mpc123_arr_t1[2979], &mpc123_arr_t1[2979]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[3428], &mpc123_arr_t1[3360]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[2973], &mpc123_arr_t1[3360]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[309], &mpc123_arr_t1[2979], &mpc123_arr_t1[3360]);
/* Zeitschritt 2 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[3582], &mpc123_arr_t1[3375]);
mpc123_mv_6_6(&mpc123_arr_t1[3538], &mpc123_arr_t1[3360], &mpc123_arr_t1[3375]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[3581], &mpc123_arr_t1[3366]);
mpc123_mv_1_6(&mpc123_arr_t1[3532], &mpc123_arr_t1[3360], &mpc123_arr_t1[3366]);
mpc123_v_turnsign_1(&mpc123_arr_t1[3366], &mpc123_arr_t1[3366]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[3815], &mpc123_arr_t1[3747]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3360], &mpc123_arr_t1[3747]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[543], &mpc123_arr_t1[3366], &mpc123_arr_t1[3747]);
/* Zeitschritt 3 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[3969], &mpc123_arr_t1[3762]);
mpc123_mv_6_6(&mpc123_arr_t1[3925], &mpc123_arr_t1[3747], &mpc123_arr_t1[3762]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[3968], &mpc123_arr_t1[3753]);
mpc123_mv_1_6(&mpc123_arr_t1[3919], &mpc123_arr_t1[3747], &mpc123_arr_t1[3753]);
mpc123_v_turnsign_1(&mpc123_arr_t1[3753], &mpc123_arr_t1[3753]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[4202], &mpc123_arr_t1[4134]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[3747], &mpc123_arr_t1[4134]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[777], &mpc123_arr_t1[3753], &mpc123_arr_t1[4134]);
/* Zeitschritt 4 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[4356], &mpc123_arr_t1[4149]);
mpc123_mv_6_6(&mpc123_arr_t1[4312], &mpc123_arr_t1[4134], &mpc123_arr_t1[4149]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[4355], &mpc123_arr_t1[4140]);
mpc123_mv_1_6(&mpc123_arr_t1[4306], &mpc123_arr_t1[4134], &mpc123_arr_t1[4140]);
mpc123_v_turnsign_1(&mpc123_arr_t1[4140], &mpc123_arr_t1[4140]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[4589], &mpc123_arr_t1[4521]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4134], &mpc123_arr_t1[4521]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1011], &mpc123_arr_t1[4140], &mpc123_arr_t1[4521]);
/* Zeitschritt 5 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[4743], &mpc123_arr_t1[4536]);
mpc123_mv_6_6(&mpc123_arr_t1[4699], &mpc123_arr_t1[4521], &mpc123_arr_t1[4536]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[4742], &mpc123_arr_t1[4527]);
mpc123_mv_1_6(&mpc123_arr_t1[4693], &mpc123_arr_t1[4521], &mpc123_arr_t1[4527]);
mpc123_v_turnsign_1(&mpc123_arr_t1[4527], &mpc123_arr_t1[4527]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[4976], &mpc123_arr_t1[4908]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[4521], &mpc123_arr_t1[4908]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1245], &mpc123_arr_t1[4527], &mpc123_arr_t1[4908]);
/* Zeitschritt 6 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[5130], &mpc123_arr_t1[4923]);
mpc123_mv_6_6(&mpc123_arr_t1[5086], &mpc123_arr_t1[4908], &mpc123_arr_t1[4923]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[5129], &mpc123_arr_t1[4914]);
mpc123_mv_1_6(&mpc123_arr_t1[5080], &mpc123_arr_t1[4908], &mpc123_arr_t1[4914]);
mpc123_v_turnsign_1(&mpc123_arr_t1[4914], &mpc123_arr_t1[4914]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[5363], &mpc123_arr_t1[5295]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[4908], &mpc123_arr_t1[5295]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1479], &mpc123_arr_t1[4914], &mpc123_arr_t1[5295]);
/* Zeitschritt 7 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[5517], &mpc123_arr_t1[5310]);
mpc123_mv_6_6(&mpc123_arr_t1[5473], &mpc123_arr_t1[5295], &mpc123_arr_t1[5310]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[5516], &mpc123_arr_t1[5301]);
mpc123_mv_1_6(&mpc123_arr_t1[5467], &mpc123_arr_t1[5295], &mpc123_arr_t1[5301]);
mpc123_v_turnsign_1(&mpc123_arr_t1[5301], &mpc123_arr_t1[5301]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[5750], &mpc123_arr_t1[5682]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5295], &mpc123_arr_t1[5682]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1713], &mpc123_arr_t1[5301], &mpc123_arr_t1[5682]);
/* Zeitschritt 8 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[5904], &mpc123_arr_t1[5697]);
mpc123_mv_6_6(&mpc123_arr_t1[5860], &mpc123_arr_t1[5682], &mpc123_arr_t1[5697]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[5903], &mpc123_arr_t1[5688]);
mpc123_mv_1_6(&mpc123_arr_t1[5854], &mpc123_arr_t1[5682], &mpc123_arr_t1[5688]);
mpc123_v_turnsign_1(&mpc123_arr_t1[5688], &mpc123_arr_t1[5688]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[6137], &mpc123_arr_t1[6069]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[5682], &mpc123_arr_t1[6069]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1947], &mpc123_arr_t1[5688], &mpc123_arr_t1[6069]);
/* Zeitschritt 9 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[6291], &mpc123_arr_t1[6084]);
mpc123_mv_6_6(&mpc123_arr_t1[6247], &mpc123_arr_t1[6069], &mpc123_arr_t1[6084]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[6290], &mpc123_arr_t1[6075]);
mpc123_mv_1_6(&mpc123_arr_t1[6241], &mpc123_arr_t1[6069], &mpc123_arr_t1[6075]);
mpc123_v_turnsign_1(&mpc123_arr_t1[6075], &mpc123_arr_t1[6075]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[6524], &mpc123_arr_t1[6456]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6069], &mpc123_arr_t1[6456]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[2181], &mpc123_arr_t1[6075], &mpc123_arr_t1[6456]);
/* Zeitschritt 10 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[6678], &mpc123_arr_t1[6471]);
mpc123_mv_6_6(&mpc123_arr_t1[6634], &mpc123_arr_t1[6456], &mpc123_arr_t1[6471]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[6677], &mpc123_arr_t1[6462]);
mpc123_mv_1_6(&mpc123_arr_t1[6628], &mpc123_arr_t1[6456], &mpc123_arr_t1[6462]);
mpc123_v_turnsign_1(&mpc123_arr_t1[6462], &mpc123_arr_t1[6462]);
/* dx */
mpc123_v_copy_6(&mpc123_arr_t1[6867], &mpc123_arr_t1[6823]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6456], &mpc123_arr_t1[6823]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[2415], &mpc123_arr_t1[6462], &mpc123_arr_t1[6823]);
/* Zeitschritt 11 */
/* dp */
mpc123_v_copy_6(&mpc123_arr_t1[6997], &mpc123_arr_t1[6834]);
mpc123_mv_6_6(&mpc123_arr_t1[6953], &mpc123_arr_t1[6823], &mpc123_arr_t1[6834]);
/* du */
mpc123_v_copy_1(&mpc123_arr_t1[6996], &mpc123_arr_t1[6829]);
mpc123_mv_1_6(&mpc123_arr_t1[6947], &mpc123_arr_t1[6823], &mpc123_arr_t1[6829]);
mpc123_v_turnsign_1(&mpc123_arr_t1[6829], &mpc123_arr_t1[6829]);
/* dx */
mpc123_error_source = 0;

}


static void mpc123_glqdocpip_rhs_starting_point_5()
{
  int i1;
/* Zeitschritt 0 */
mpc123_v_init0_6(&mpc123_arr_t1[2707]);
mpc123_v_init0_1(&mpc123_arr_t1[2713]);
mpc123_v_copy_4(&mpc123_arr_t1[67], &mpc123_arr_t1[2714]);
mpc123_v_copy_6(mpc123_xinit, &mpc123_arr_t1[2718]);
mpc123_v_copy_4(&mpc123_arr_t1[147], &mpc123_arr_t1[2724]);
mpc123_v_init0_4(&mpc123_arr_t1[2728]);
mpc123_vsub_4(&mpc123_arr_t1[2670], &mpc123_arr_t1[2648], &mpc123_arr_t1[2728]);
mpc123_vv_elemult_8(&mpc123_arr_t1[2658], &mpc123_arr_t1[2666], &mpc123_arr_t1[2732]);
/* Zeitschritt 1 */
mpc123_v_init0_6(&mpc123_arr_t1[3026]);
mpc123_v_init0_1(&mpc123_arr_t1[3032]);
mpc123_v_copy_8(&mpc123_arr_t1[265], &mpc123_arr_t1[3033]);
mpc123_v_copy_6(&mpc123_arr_t1[113], &mpc123_arr_t1[3041]);
mpc123_v_copy_8(&mpc123_arr_t1[377], &mpc123_arr_t1[3047]);
mpc123_v_init0_8(&mpc123_arr_t1[3055]);
mpc123_vsub_8(&mpc123_arr_t1[2965], &mpc123_arr_t1[2927], &mpc123_arr_t1[3055]);
mpc123_vv_elemult_16(&mpc123_arr_t1[2941], &mpc123_arr_t1[2957], &mpc123_arr_t1[3063]);
/* Zeitschritt 2 */
mpc123_v_init0_6(&mpc123_arr_t1[3413]);
mpc123_v_init0_1(&mpc123_arr_t1[3419]);
mpc123_v_copy_8(&mpc123_arr_t1[499], &mpc123_arr_t1[3420]);
mpc123_v_copy_6(&mpc123_arr_t1[315], &mpc123_arr_t1[3428]);
mpc123_v_copy_8(&mpc123_arr_t1[611], &mpc123_arr_t1[3434]);
mpc123_v_init0_8(&mpc123_arr_t1[3442]);
mpc123_vsub_8(&mpc123_arr_t1[3352], &mpc123_arr_t1[3314], &mpc123_arr_t1[3442]);
mpc123_vv_elemult_16(&mpc123_arr_t1[3328], &mpc123_arr_t1[3344], &mpc123_arr_t1[3450]);
/* Zeitschritt 3 */
mpc123_v_init0_6(&mpc123_arr_t1[3800]);
mpc123_v_init0_1(&mpc123_arr_t1[3806]);
mpc123_v_copy_8(&mpc123_arr_t1[733], &mpc123_arr_t1[3807]);
mpc123_v_copy_6(&mpc123_arr_t1[549], &mpc123_arr_t1[3815]);
mpc123_v_copy_8(&mpc123_arr_t1[845], &mpc123_arr_t1[3821]);
mpc123_v_init0_8(&mpc123_arr_t1[3829]);
mpc123_vsub_8(&mpc123_arr_t1[3739], &mpc123_arr_t1[3701], &mpc123_arr_t1[3829]);
mpc123_vv_elemult_16(&mpc123_arr_t1[3715], &mpc123_arr_t1[3731], &mpc123_arr_t1[3837]);
/* Zeitschritt 4 */
mpc123_v_init0_6(&mpc123_arr_t1[4187]);
mpc123_v_init0_1(&mpc123_arr_t1[4193]);
mpc123_v_copy_8(&mpc123_arr_t1[967], &mpc123_arr_t1[4194]);
mpc123_v_copy_6(&mpc123_arr_t1[783], &mpc123_arr_t1[4202]);
mpc123_v_copy_8(&mpc123_arr_t1[1079], &mpc123_arr_t1[4208]);
mpc123_v_init0_8(&mpc123_arr_t1[4216]);
mpc123_vsub_8(&mpc123_arr_t1[4126], &mpc123_arr_t1[4088], &mpc123_arr_t1[4216]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4102], &mpc123_arr_t1[4118], &mpc123_arr_t1[4224]);
/* Zeitschritt 5 */
mpc123_v_init0_6(&mpc123_arr_t1[4574]);
mpc123_v_init0_1(&mpc123_arr_t1[4580]);
mpc123_v_copy_8(&mpc123_arr_t1[1201], &mpc123_arr_t1[4581]);
mpc123_v_copy_6(&mpc123_arr_t1[1017], &mpc123_arr_t1[4589]);
mpc123_v_copy_8(&mpc123_arr_t1[1313], &mpc123_arr_t1[4595]);
mpc123_v_init0_8(&mpc123_arr_t1[4603]);
mpc123_vsub_8(&mpc123_arr_t1[4513], &mpc123_arr_t1[4475], &mpc123_arr_t1[4603]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4489], &mpc123_arr_t1[4505], &mpc123_arr_t1[4611]);
/* Zeitschritt 6 */
mpc123_v_init0_6(&mpc123_arr_t1[4961]);
mpc123_v_init0_1(&mpc123_arr_t1[4967]);
mpc123_v_copy_8(&mpc123_arr_t1[1435], &mpc123_arr_t1[4968]);
mpc123_v_copy_6(&mpc123_arr_t1[1251], &mpc123_arr_t1[4976]);
mpc123_v_copy_8(&mpc123_arr_t1[1547], &mpc123_arr_t1[4982]);
mpc123_v_init0_8(&mpc123_arr_t1[4990]);
mpc123_vsub_8(&mpc123_arr_t1[4900], &mpc123_arr_t1[4862], &mpc123_arr_t1[4990]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4876], &mpc123_arr_t1[4892], &mpc123_arr_t1[4998]);
/* Zeitschritt 7 */
mpc123_v_init0_6(&mpc123_arr_t1[5348]);
mpc123_v_init0_1(&mpc123_arr_t1[5354]);
mpc123_v_copy_8(&mpc123_arr_t1[1669], &mpc123_arr_t1[5355]);
mpc123_v_copy_6(&mpc123_arr_t1[1485], &mpc123_arr_t1[5363]);
mpc123_v_copy_8(&mpc123_arr_t1[1781], &mpc123_arr_t1[5369]);
mpc123_v_init0_8(&mpc123_arr_t1[5377]);
mpc123_vsub_8(&mpc123_arr_t1[5287], &mpc123_arr_t1[5249], &mpc123_arr_t1[5377]);
mpc123_vv_elemult_16(&mpc123_arr_t1[5263], &mpc123_arr_t1[5279], &mpc123_arr_t1[5385]);
/* Zeitschritt 8 */
mpc123_v_init0_6(&mpc123_arr_t1[5735]);
mpc123_v_init0_1(&mpc123_arr_t1[5741]);
mpc123_v_copy_8(&mpc123_arr_t1[1903], &mpc123_arr_t1[5742]);
mpc123_v_copy_6(&mpc123_arr_t1[1719], &mpc123_arr_t1[5750]);
mpc123_v_copy_8(&mpc123_arr_t1[2015], &mpc123_arr_t1[5756]);
mpc123_v_init0_8(&mpc123_arr_t1[5764]);
mpc123_vsub_8(&mpc123_arr_t1[5674], &mpc123_arr_t1[5636], &mpc123_arr_t1[5764]);
mpc123_vv_elemult_16(&mpc123_arr_t1[5650], &mpc123_arr_t1[5666], &mpc123_arr_t1[5772]);
/* Zeitschritt 9 */
mpc123_v_init0_6(&mpc123_arr_t1[6122]);
mpc123_v_init0_1(&mpc123_arr_t1[6128]);
mpc123_v_copy_8(&mpc123_arr_t1[2137], &mpc123_arr_t1[6129]);
mpc123_v_copy_6(&mpc123_arr_t1[1953], &mpc123_arr_t1[6137]);
mpc123_v_copy_8(&mpc123_arr_t1[2249], &mpc123_arr_t1[6143]);
mpc123_v_init0_8(&mpc123_arr_t1[6151]);
mpc123_vsub_8(&mpc123_arr_t1[6061], &mpc123_arr_t1[6023], &mpc123_arr_t1[6151]);
mpc123_vv_elemult_16(&mpc123_arr_t1[6037], &mpc123_arr_t1[6053], &mpc123_arr_t1[6159]);
/* Zeitschritt 10 */
mpc123_v_init0_6(&mpc123_arr_t1[6509]);
mpc123_v_init0_1(&mpc123_arr_t1[6515]);
mpc123_v_copy_8(&mpc123_arr_t1[2371], &mpc123_arr_t1[6516]);
mpc123_v_copy_6(&mpc123_arr_t1[2187], &mpc123_arr_t1[6524]);
mpc123_v_copy_8(&mpc123_arr_t1[2483], &mpc123_arr_t1[6530]);
mpc123_v_init0_8(&mpc123_arr_t1[6538]);
mpc123_vsub_8(&mpc123_arr_t1[6448], &mpc123_arr_t1[6410], &mpc123_arr_t1[6538]);
mpc123_vv_elemult_16(&mpc123_arr_t1[6424], &mpc123_arr_t1[6440], &mpc123_arr_t1[6546]);
/* Zeitschritt 11 */
mpc123_v_init0_6(&mpc123_arr_t1[6856]);
mpc123_v_init0_1(&mpc123_arr_t1[6862]);
mpc123_v_copy_4(&mpc123_arr_t1[2557], &mpc123_arr_t1[6863]);
mpc123_v_copy_6(&mpc123_arr_t1[2421], &mpc123_arr_t1[6867]);
mpc123_v_copy_4(&mpc123_arr_t1[2637], &mpc123_arr_t1[6873]);
mpc123_v_init0_4(&mpc123_arr_t1[6877]);
mpc123_vsub_4(&mpc123_arr_t1[6819], &mpc123_arr_t1[6797], &mpc123_arr_t1[6877]);
mpc123_vv_elemult_8(&mpc123_arr_t1[6807], &mpc123_arr_t1[6815], &mpc123_arr_t1[6881]);
}


static void mpc123_glqdocpip_rhs_affine()
{
  int i1;
/* Zeitschritt 0 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[60], &mpc123_arr_t1[2707]);
mpc123_mv_sid21_sid2_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[2641], &mpc123_arr_t1[2707]);
mpc123_mv_sid24_sid5_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2647], &mpc123_arr_t1[2707]);
mpc123_vsub_6(&mpc123_arr_t1[2707], &mpc123_arr_t1[2652], &mpc123_arr_t1[2707]);
mpc123_mtv_sid42_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2935], &mpc123_arr_t1[2707]);
mpc123_mtv_sid51_sid15_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2658], &mpc123_arr_t1[2707]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[66], &mpc123_arr_t1[2713]);
mpc123_mtv_sid24_sid2_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2641], &mpc123_arr_t1[2713]);
mpc123_mv_sid27_sid5_1_1(&mpc123_arr_t1[43], &mpc123_arr_t1[2647], &mpc123_arr_t1[2713]);
mpc123_mtv_sid45_sid2_6_1(&mpc123_arr_t1[107], &mpc123_arr_t1[2935], &mpc123_arr_t1[2713]);
mpc123_mtv_sid54_sid15_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2658], &mpc123_arr_t1[2713]);
/* rf0s */
mpc123_v_copy_4(&mpc123_arr_t1[67], &mpc123_arr_t1[2714]);
mpc123_mv_sid30_sid18_4_4(&mpc123_arr_t1[44], &mpc123_arr_t1[2648], &mpc123_arr_t1[2714]);
mpc123_vsub_4(&mpc123_arr_t1[2714], &mpc123_arr_t1[2658], &mpc123_arr_t1[2714]);
mpc123_vsub_4(&mpc123_arr_t1[2714], &mpc123_arr_t1[2662], &mpc123_arr_t1[2714]);
/* rf */
mpc123_v_copy_6(mpc123_xinit, &mpc123_arr_t1[2718]);
mpc123_vsub_6(&mpc123_arr_t1[2718], &mpc123_arr_t1[2641], &mpc123_arr_t1[2718]);
/* rc */
mpc123_v_copy_4(&mpc123_arr_t1[147], &mpc123_arr_t1[2724]);
mpc123_mv_sid51_sid2_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2641], &mpc123_arr_t1[2724]);
mpc123_mv_sid54_sid5_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2647], &mpc123_arr_t1[2724]);
mpc123_vadd_4(&mpc123_arr_t1[2724], &mpc123_arr_t1[2666], &mpc123_arr_t1[2724]);
mpc123_vsub_4(&mpc123_arr_t1[2724], &mpc123_arr_t1[2648], &mpc123_arr_t1[2724]);
/* rs */
mpc123_v_init0_4(&mpc123_arr_t1[2728]);
mpc123_vsub_4(&mpc123_arr_t1[2670], &mpc123_arr_t1[2648], &mpc123_arr_t1[2728]);
/* rk */
mpc123_vv_elemult_8(&mpc123_arr_t1[2658], &mpc123_arr_t1[2666], &mpc123_arr_t1[2732]);
/* Zeitschritt 1 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[258], &mpc123_arr_t1[3026]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[151], &mpc123_arr_t1[2920], &mpc123_arr_t1[3026]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[2926], &mpc123_arr_t1[3026]);
mpc123_vsub_6(&mpc123_arr_t1[3026], &mpc123_arr_t1[2935], &mpc123_arr_t1[3026]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[3322], &mpc123_arr_t1[3026]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[2941], &mpc123_arr_t1[3026]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[264], &mpc123_arr_t1[3032]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[2920], &mpc123_arr_t1[3032]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[193], &mpc123_arr_t1[2926], &mpc123_arr_t1[3032]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[309], &mpc123_arr_t1[3322], &mpc123_arr_t1[3032]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[2941], &mpc123_arr_t1[3032]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[265], &mpc123_arr_t1[3033]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[194], &mpc123_arr_t1[2927], &mpc123_arr_t1[3033]);
mpc123_vsub_8(&mpc123_arr_t1[3033], &mpc123_arr_t1[2941], &mpc123_arr_t1[3033]);
mpc123_vsub_8(&mpc123_arr_t1[3033], &mpc123_arr_t1[2949], &mpc123_arr_t1[3033]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[113], &mpc123_arr_t1[3041]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2641], &mpc123_arr_t1[3041]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[107], &mpc123_arr_t1[2647], &mpc123_arr_t1[3041]);
mpc123_vsub_6(&mpc123_arr_t1[3041], &mpc123_arr_t1[2920], &mpc123_arr_t1[3041]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[377], &mpc123_arr_t1[3047]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[2920], &mpc123_arr_t1[3047]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[2926], &mpc123_arr_t1[3047]);
mpc123_vadd_8(&mpc123_arr_t1[3047], &mpc123_arr_t1[2957], &mpc123_arr_t1[3047]);
mpc123_vsub_8(&mpc123_arr_t1[3047], &mpc123_arr_t1[2927], &mpc123_arr_t1[3047]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[3055]);
mpc123_vsub_8(&mpc123_arr_t1[2965], &mpc123_arr_t1[2927], &mpc123_arr_t1[3055]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[2941], &mpc123_arr_t1[2957], &mpc123_arr_t1[3063]);
/* Zeitschritt 2 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[492], &mpc123_arr_t1[3413]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[385], &mpc123_arr_t1[3307], &mpc123_arr_t1[3413]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3313], &mpc123_arr_t1[3413]);
mpc123_vsub_6(&mpc123_arr_t1[3413], &mpc123_arr_t1[3322], &mpc123_arr_t1[3413]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3709], &mpc123_arr_t1[3413]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3328], &mpc123_arr_t1[3413]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[498], &mpc123_arr_t1[3419]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3307], &mpc123_arr_t1[3419]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[427], &mpc123_arr_t1[3313], &mpc123_arr_t1[3419]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[543], &mpc123_arr_t1[3709], &mpc123_arr_t1[3419]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3328], &mpc123_arr_t1[3419]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[499], &mpc123_arr_t1[3420]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[428], &mpc123_arr_t1[3314], &mpc123_arr_t1[3420]);
mpc123_vsub_8(&mpc123_arr_t1[3420], &mpc123_arr_t1[3328], &mpc123_arr_t1[3420]);
mpc123_vsub_8(&mpc123_arr_t1[3420], &mpc123_arr_t1[3336], &mpc123_arr_t1[3420]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[315], &mpc123_arr_t1[3428]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[2920], &mpc123_arr_t1[3428]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[309], &mpc123_arr_t1[2926], &mpc123_arr_t1[3428]);
mpc123_vsub_6(&mpc123_arr_t1[3428], &mpc123_arr_t1[3307], &mpc123_arr_t1[3428]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[611], &mpc123_arr_t1[3434]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3307], &mpc123_arr_t1[3434]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3313], &mpc123_arr_t1[3434]);
mpc123_vadd_8(&mpc123_arr_t1[3434], &mpc123_arr_t1[3344], &mpc123_arr_t1[3434]);
mpc123_vsub_8(&mpc123_arr_t1[3434], &mpc123_arr_t1[3314], &mpc123_arr_t1[3434]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[3442]);
mpc123_vsub_8(&mpc123_arr_t1[3352], &mpc123_arr_t1[3314], &mpc123_arr_t1[3442]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[3328], &mpc123_arr_t1[3344], &mpc123_arr_t1[3450]);
/* Zeitschritt 3 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[726], &mpc123_arr_t1[3800]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[619], &mpc123_arr_t1[3694], &mpc123_arr_t1[3800]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3700], &mpc123_arr_t1[3800]);
mpc123_vsub_6(&mpc123_arr_t1[3800], &mpc123_arr_t1[3709], &mpc123_arr_t1[3800]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[4096], &mpc123_arr_t1[3800]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3715], &mpc123_arr_t1[3800]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[732], &mpc123_arr_t1[3806]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3694], &mpc123_arr_t1[3806]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[661], &mpc123_arr_t1[3700], &mpc123_arr_t1[3806]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[777], &mpc123_arr_t1[4096], &mpc123_arr_t1[3806]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3715], &mpc123_arr_t1[3806]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[733], &mpc123_arr_t1[3807]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[662], &mpc123_arr_t1[3701], &mpc123_arr_t1[3807]);
mpc123_vsub_8(&mpc123_arr_t1[3807], &mpc123_arr_t1[3715], &mpc123_arr_t1[3807]);
mpc123_vsub_8(&mpc123_arr_t1[3807], &mpc123_arr_t1[3723], &mpc123_arr_t1[3807]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[549], &mpc123_arr_t1[3815]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3307], &mpc123_arr_t1[3815]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[543], &mpc123_arr_t1[3313], &mpc123_arr_t1[3815]);
mpc123_vsub_6(&mpc123_arr_t1[3815], &mpc123_arr_t1[3694], &mpc123_arr_t1[3815]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[845], &mpc123_arr_t1[3821]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3694], &mpc123_arr_t1[3821]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3700], &mpc123_arr_t1[3821]);
mpc123_vadd_8(&mpc123_arr_t1[3821], &mpc123_arr_t1[3731], &mpc123_arr_t1[3821]);
mpc123_vsub_8(&mpc123_arr_t1[3821], &mpc123_arr_t1[3701], &mpc123_arr_t1[3821]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[3829]);
mpc123_vsub_8(&mpc123_arr_t1[3739], &mpc123_arr_t1[3701], &mpc123_arr_t1[3829]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[3715], &mpc123_arr_t1[3731], &mpc123_arr_t1[3837]);
/* Zeitschritt 4 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[960], &mpc123_arr_t1[4187]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[853], &mpc123_arr_t1[4081], &mpc123_arr_t1[4187]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4087], &mpc123_arr_t1[4187]);
mpc123_vsub_6(&mpc123_arr_t1[4187], &mpc123_arr_t1[4096], &mpc123_arr_t1[4187]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4483], &mpc123_arr_t1[4187]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4102], &mpc123_arr_t1[4187]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[966], &mpc123_arr_t1[4193]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4081], &mpc123_arr_t1[4193]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[895], &mpc123_arr_t1[4087], &mpc123_arr_t1[4193]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1011], &mpc123_arr_t1[4483], &mpc123_arr_t1[4193]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4102], &mpc123_arr_t1[4193]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[967], &mpc123_arr_t1[4194]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[896], &mpc123_arr_t1[4088], &mpc123_arr_t1[4194]);
mpc123_vsub_8(&mpc123_arr_t1[4194], &mpc123_arr_t1[4102], &mpc123_arr_t1[4194]);
mpc123_vsub_8(&mpc123_arr_t1[4194], &mpc123_arr_t1[4110], &mpc123_arr_t1[4194]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[783], &mpc123_arr_t1[4202]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[3694], &mpc123_arr_t1[4202]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[777], &mpc123_arr_t1[3700], &mpc123_arr_t1[4202]);
mpc123_vsub_6(&mpc123_arr_t1[4202], &mpc123_arr_t1[4081], &mpc123_arr_t1[4202]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[1079], &mpc123_arr_t1[4208]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4081], &mpc123_arr_t1[4208]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4087], &mpc123_arr_t1[4208]);
mpc123_vadd_8(&mpc123_arr_t1[4208], &mpc123_arr_t1[4118], &mpc123_arr_t1[4208]);
mpc123_vsub_8(&mpc123_arr_t1[4208], &mpc123_arr_t1[4088], &mpc123_arr_t1[4208]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[4216]);
mpc123_vsub_8(&mpc123_arr_t1[4126], &mpc123_arr_t1[4088], &mpc123_arr_t1[4216]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4102], &mpc123_arr_t1[4118], &mpc123_arr_t1[4224]);
/* Zeitschritt 5 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[1194], &mpc123_arr_t1[4574]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1087], &mpc123_arr_t1[4468], &mpc123_arr_t1[4574]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4474], &mpc123_arr_t1[4574]);
mpc123_vsub_6(&mpc123_arr_t1[4574], &mpc123_arr_t1[4483], &mpc123_arr_t1[4574]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[4870], &mpc123_arr_t1[4574]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4489], &mpc123_arr_t1[4574]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[1200], &mpc123_arr_t1[4580]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4468], &mpc123_arr_t1[4580]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1129], &mpc123_arr_t1[4474], &mpc123_arr_t1[4580]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1245], &mpc123_arr_t1[4870], &mpc123_arr_t1[4580]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4489], &mpc123_arr_t1[4580]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[1201], &mpc123_arr_t1[4581]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1130], &mpc123_arr_t1[4475], &mpc123_arr_t1[4581]);
mpc123_vsub_8(&mpc123_arr_t1[4581], &mpc123_arr_t1[4489], &mpc123_arr_t1[4581]);
mpc123_vsub_8(&mpc123_arr_t1[4581], &mpc123_arr_t1[4497], &mpc123_arr_t1[4581]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[1017], &mpc123_arr_t1[4589]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4081], &mpc123_arr_t1[4589]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1011], &mpc123_arr_t1[4087], &mpc123_arr_t1[4589]);
mpc123_vsub_6(&mpc123_arr_t1[4589], &mpc123_arr_t1[4468], &mpc123_arr_t1[4589]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[1313], &mpc123_arr_t1[4595]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4468], &mpc123_arr_t1[4595]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4474], &mpc123_arr_t1[4595]);
mpc123_vadd_8(&mpc123_arr_t1[4595], &mpc123_arr_t1[4505], &mpc123_arr_t1[4595]);
mpc123_vsub_8(&mpc123_arr_t1[4595], &mpc123_arr_t1[4475], &mpc123_arr_t1[4595]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[4603]);
mpc123_vsub_8(&mpc123_arr_t1[4513], &mpc123_arr_t1[4475], &mpc123_arr_t1[4603]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4489], &mpc123_arr_t1[4505], &mpc123_arr_t1[4611]);
/* Zeitschritt 6 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[1428], &mpc123_arr_t1[4961]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1321], &mpc123_arr_t1[4855], &mpc123_arr_t1[4961]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[4861], &mpc123_arr_t1[4961]);
mpc123_vsub_6(&mpc123_arr_t1[4961], &mpc123_arr_t1[4870], &mpc123_arr_t1[4961]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[5257], &mpc123_arr_t1[4961]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[4876], &mpc123_arr_t1[4961]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[1434], &mpc123_arr_t1[4967]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[4855], &mpc123_arr_t1[4967]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1363], &mpc123_arr_t1[4861], &mpc123_arr_t1[4967]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1479], &mpc123_arr_t1[5257], &mpc123_arr_t1[4967]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[4876], &mpc123_arr_t1[4967]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[1435], &mpc123_arr_t1[4968]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1364], &mpc123_arr_t1[4862], &mpc123_arr_t1[4968]);
mpc123_vsub_8(&mpc123_arr_t1[4968], &mpc123_arr_t1[4876], &mpc123_arr_t1[4968]);
mpc123_vsub_8(&mpc123_arr_t1[4968], &mpc123_arr_t1[4884], &mpc123_arr_t1[4968]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[1251], &mpc123_arr_t1[4976]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[4468], &mpc123_arr_t1[4976]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1245], &mpc123_arr_t1[4474], &mpc123_arr_t1[4976]);
mpc123_vsub_6(&mpc123_arr_t1[4976], &mpc123_arr_t1[4855], &mpc123_arr_t1[4976]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[1547], &mpc123_arr_t1[4982]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[4855], &mpc123_arr_t1[4982]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[4861], &mpc123_arr_t1[4982]);
mpc123_vadd_8(&mpc123_arr_t1[4982], &mpc123_arr_t1[4892], &mpc123_arr_t1[4982]);
mpc123_vsub_8(&mpc123_arr_t1[4982], &mpc123_arr_t1[4862], &mpc123_arr_t1[4982]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[4990]);
mpc123_vsub_8(&mpc123_arr_t1[4900], &mpc123_arr_t1[4862], &mpc123_arr_t1[4990]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4876], &mpc123_arr_t1[4892], &mpc123_arr_t1[4998]);
/* Zeitschritt 7 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[1662], &mpc123_arr_t1[5348]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1555], &mpc123_arr_t1[5242], &mpc123_arr_t1[5348]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5248], &mpc123_arr_t1[5348]);
mpc123_vsub_6(&mpc123_arr_t1[5348], &mpc123_arr_t1[5257], &mpc123_arr_t1[5348]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5644], &mpc123_arr_t1[5348]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5263], &mpc123_arr_t1[5348]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[1668], &mpc123_arr_t1[5354]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5242], &mpc123_arr_t1[5354]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1597], &mpc123_arr_t1[5248], &mpc123_arr_t1[5354]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1713], &mpc123_arr_t1[5644], &mpc123_arr_t1[5354]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5263], &mpc123_arr_t1[5354]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[1669], &mpc123_arr_t1[5355]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1598], &mpc123_arr_t1[5249], &mpc123_arr_t1[5355]);
mpc123_vsub_8(&mpc123_arr_t1[5355], &mpc123_arr_t1[5263], &mpc123_arr_t1[5355]);
mpc123_vsub_8(&mpc123_arr_t1[5355], &mpc123_arr_t1[5271], &mpc123_arr_t1[5355]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[1485], &mpc123_arr_t1[5363]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[4855], &mpc123_arr_t1[5363]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1479], &mpc123_arr_t1[4861], &mpc123_arr_t1[5363]);
mpc123_vsub_6(&mpc123_arr_t1[5363], &mpc123_arr_t1[5242], &mpc123_arr_t1[5363]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[1781], &mpc123_arr_t1[5369]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5242], &mpc123_arr_t1[5369]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5248], &mpc123_arr_t1[5369]);
mpc123_vadd_8(&mpc123_arr_t1[5369], &mpc123_arr_t1[5279], &mpc123_arr_t1[5369]);
mpc123_vsub_8(&mpc123_arr_t1[5369], &mpc123_arr_t1[5249], &mpc123_arr_t1[5369]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[5377]);
mpc123_vsub_8(&mpc123_arr_t1[5287], &mpc123_arr_t1[5249], &mpc123_arr_t1[5377]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[5263], &mpc123_arr_t1[5279], &mpc123_arr_t1[5385]);
/* Zeitschritt 8 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[1896], &mpc123_arr_t1[5735]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1789], &mpc123_arr_t1[5629], &mpc123_arr_t1[5735]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5635], &mpc123_arr_t1[5735]);
mpc123_vsub_6(&mpc123_arr_t1[5735], &mpc123_arr_t1[5644], &mpc123_arr_t1[5735]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[6031], &mpc123_arr_t1[5735]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5650], &mpc123_arr_t1[5735]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[1902], &mpc123_arr_t1[5741]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5629], &mpc123_arr_t1[5741]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1831], &mpc123_arr_t1[5635], &mpc123_arr_t1[5741]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1947], &mpc123_arr_t1[6031], &mpc123_arr_t1[5741]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5650], &mpc123_arr_t1[5741]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[1903], &mpc123_arr_t1[5742]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1832], &mpc123_arr_t1[5636], &mpc123_arr_t1[5742]);
mpc123_vsub_8(&mpc123_arr_t1[5742], &mpc123_arr_t1[5650], &mpc123_arr_t1[5742]);
mpc123_vsub_8(&mpc123_arr_t1[5742], &mpc123_arr_t1[5658], &mpc123_arr_t1[5742]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[1719], &mpc123_arr_t1[5750]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5242], &mpc123_arr_t1[5750]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1713], &mpc123_arr_t1[5248], &mpc123_arr_t1[5750]);
mpc123_vsub_6(&mpc123_arr_t1[5750], &mpc123_arr_t1[5629], &mpc123_arr_t1[5750]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[2015], &mpc123_arr_t1[5756]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5629], &mpc123_arr_t1[5756]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5635], &mpc123_arr_t1[5756]);
mpc123_vadd_8(&mpc123_arr_t1[5756], &mpc123_arr_t1[5666], &mpc123_arr_t1[5756]);
mpc123_vsub_8(&mpc123_arr_t1[5756], &mpc123_arr_t1[5636], &mpc123_arr_t1[5756]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[5764]);
mpc123_vsub_8(&mpc123_arr_t1[5674], &mpc123_arr_t1[5636], &mpc123_arr_t1[5764]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[5650], &mpc123_arr_t1[5666], &mpc123_arr_t1[5772]);
/* Zeitschritt 9 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[2130], &mpc123_arr_t1[6122]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2023], &mpc123_arr_t1[6016], &mpc123_arr_t1[6122]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6022], &mpc123_arr_t1[6122]);
mpc123_vsub_6(&mpc123_arr_t1[6122], &mpc123_arr_t1[6031], &mpc123_arr_t1[6122]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6418], &mpc123_arr_t1[6122]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6037], &mpc123_arr_t1[6122]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[2136], &mpc123_arr_t1[6128]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6016], &mpc123_arr_t1[6128]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2065], &mpc123_arr_t1[6022], &mpc123_arr_t1[6128]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2181], &mpc123_arr_t1[6418], &mpc123_arr_t1[6128]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6037], &mpc123_arr_t1[6128]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[2137], &mpc123_arr_t1[6129]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[2066], &mpc123_arr_t1[6023], &mpc123_arr_t1[6129]);
mpc123_vsub_8(&mpc123_arr_t1[6129], &mpc123_arr_t1[6037], &mpc123_arr_t1[6129]);
mpc123_vsub_8(&mpc123_arr_t1[6129], &mpc123_arr_t1[6045], &mpc123_arr_t1[6129]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[1953], &mpc123_arr_t1[6137]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[5629], &mpc123_arr_t1[6137]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1947], &mpc123_arr_t1[5635], &mpc123_arr_t1[6137]);
mpc123_vsub_6(&mpc123_arr_t1[6137], &mpc123_arr_t1[6016], &mpc123_arr_t1[6137]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[2249], &mpc123_arr_t1[6143]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6016], &mpc123_arr_t1[6143]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6022], &mpc123_arr_t1[6143]);
mpc123_vadd_8(&mpc123_arr_t1[6143], &mpc123_arr_t1[6053], &mpc123_arr_t1[6143]);
mpc123_vsub_8(&mpc123_arr_t1[6143], &mpc123_arr_t1[6023], &mpc123_arr_t1[6143]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[6151]);
mpc123_vsub_8(&mpc123_arr_t1[6061], &mpc123_arr_t1[6023], &mpc123_arr_t1[6151]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[6037], &mpc123_arr_t1[6053], &mpc123_arr_t1[6159]);
/* Zeitschritt 10 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[2364], &mpc123_arr_t1[6509]);
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2257], &mpc123_arr_t1[6403], &mpc123_arr_t1[6509]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6409], &mpc123_arr_t1[6509]);
mpc123_vsub_6(&mpc123_arr_t1[6509], &mpc123_arr_t1[6418], &mpc123_arr_t1[6509]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6801], &mpc123_arr_t1[6509]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6424], &mpc123_arr_t1[6509]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[2370], &mpc123_arr_t1[6515]);
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6403], &mpc123_arr_t1[6515]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2299], &mpc123_arr_t1[6409], &mpc123_arr_t1[6515]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2415], &mpc123_arr_t1[6801], &mpc123_arr_t1[6515]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6424], &mpc123_arr_t1[6515]);
/* rf0s */
mpc123_v_copy_8(&mpc123_arr_t1[2371], &mpc123_arr_t1[6516]);
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[2300], &mpc123_arr_t1[6410], &mpc123_arr_t1[6516]);
mpc123_vsub_8(&mpc123_arr_t1[6516], &mpc123_arr_t1[6424], &mpc123_arr_t1[6516]);
mpc123_vsub_8(&mpc123_arr_t1[6516], &mpc123_arr_t1[6432], &mpc123_arr_t1[6516]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[2187], &mpc123_arr_t1[6524]);
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6016], &mpc123_arr_t1[6524]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[2181], &mpc123_arr_t1[6022], &mpc123_arr_t1[6524]);
mpc123_vsub_6(&mpc123_arr_t1[6524], &mpc123_arr_t1[6403], &mpc123_arr_t1[6524]);
/* rc */
mpc123_v_copy_8(&mpc123_arr_t1[2483], &mpc123_arr_t1[6530]);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6403], &mpc123_arr_t1[6530]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6409], &mpc123_arr_t1[6530]);
mpc123_vadd_8(&mpc123_arr_t1[6530], &mpc123_arr_t1[6440], &mpc123_arr_t1[6530]);
mpc123_vsub_8(&mpc123_arr_t1[6530], &mpc123_arr_t1[6410], &mpc123_arr_t1[6530]);
/* rs */
mpc123_v_init0_8(&mpc123_arr_t1[6538]);
mpc123_vsub_8(&mpc123_arr_t1[6448], &mpc123_arr_t1[6410], &mpc123_arr_t1[6538]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[6424], &mpc123_arr_t1[6440], &mpc123_arr_t1[6546]);
/* Zeitschritt 11 */
/* rf0x */
mpc123_v_copy_6(&mpc123_arr_t1[2550], &mpc123_arr_t1[6856]);
mpc123_mv_sid23_sid2_6_6(&mpc123_arr_t1[2491], &mpc123_arr_t1[6790], &mpc123_arr_t1[6856]);
mpc123_mv_sid26_sid5_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6796], &mpc123_arr_t1[6856]);
mpc123_vsub_6(&mpc123_arr_t1[6856], &mpc123_arr_t1[6801], &mpc123_arr_t1[6856]);
mpc123_mtv_sid53_sid17_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6807], &mpc123_arr_t1[6856]);
/* rf0u */
mpc123_v_copy_1(&mpc123_arr_t1[2556], &mpc123_arr_t1[6862]);
mpc123_mtv_sid26_sid2_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6790], &mpc123_arr_t1[6862]);
mpc123_mv_sid29_sid5_1_1(&mpc123_arr_t1[2533], &mpc123_arr_t1[6796], &mpc123_arr_t1[6862]);
mpc123_mtv_sid56_sid17_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6807], &mpc123_arr_t1[6862]);
/* rf0s */
mpc123_v_copy_4(&mpc123_arr_t1[2557], &mpc123_arr_t1[6863]);
mpc123_mv_sid32_sid20_4_4(&mpc123_arr_t1[2534], &mpc123_arr_t1[6797], &mpc123_arr_t1[6863]);
mpc123_vsub_4(&mpc123_arr_t1[6863], &mpc123_arr_t1[6807], &mpc123_arr_t1[6863]);
mpc123_vsub_4(&mpc123_arr_t1[6863], &mpc123_arr_t1[6811], &mpc123_arr_t1[6863]);
/* rf */
mpc123_v_copy_6(&mpc123_arr_t1[2421], &mpc123_arr_t1[6867]);
mpc123_mv_sid44_sid2_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6403], &mpc123_arr_t1[6867]);
mpc123_mv_sid47_sid5_6_1(&mpc123_arr_t1[2415], &mpc123_arr_t1[6409], &mpc123_arr_t1[6867]);
mpc123_vsub_6(&mpc123_arr_t1[6867], &mpc123_arr_t1[6790], &mpc123_arr_t1[6867]);
/* rc */
mpc123_v_copy_4(&mpc123_arr_t1[2637], &mpc123_arr_t1[6873]);
mpc123_mv_sid53_sid2_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6790], &mpc123_arr_t1[6873]);
mpc123_mv_sid56_sid5_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6796], &mpc123_arr_t1[6873]);
mpc123_vadd_4(&mpc123_arr_t1[6873], &mpc123_arr_t1[6815], &mpc123_arr_t1[6873]);
mpc123_vsub_4(&mpc123_arr_t1[6873], &mpc123_arr_t1[6797], &mpc123_arr_t1[6873]);
/* rs */
mpc123_v_init0_4(&mpc123_arr_t1[6877]);
mpc123_vsub_4(&mpc123_arr_t1[6819], &mpc123_arr_t1[6797], &mpc123_arr_t1[6877]);
/* rk */
mpc123_vv_elemult_8(&mpc123_arr_t1[6807], &mpc123_arr_t1[6815], &mpc123_arr_t1[6881]);
}


static void mpc123_glqdocpip_rhs_corrector()
{
  int i1;
/* Zeitschritt 0 */
/* rk_corr */
mpc123_vv_elemult_8(&mpc123_arr_t1[2691], &mpc123_arr_t1[2699], mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[2732], mpc123_tmp1_8, &mpc123_arr_t1[2732]);
mpc123_v_init1_8(mpc123_tmp1_8);
mpc123_v_init0_8(mpc123_tmp2_8);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_8(mpc123_tmp1_1, mpc123_tmp1_8, mpc123_tmp2_8);
mpc123_vsub_8(&mpc123_arr_t1[2732], mpc123_tmp2_8, &mpc123_arr_t1[2732]);
/* Zeitschritt 1 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[2994], &mpc123_arr_t1[3010], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3063], mpc123_tmp1_16, &mpc123_arr_t1[3063]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vsub_16(&mpc123_arr_t1[3063], mpc123_tmp2_16, &mpc123_arr_t1[3063]);
/* Zeitschritt 2 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[3381], &mpc123_arr_t1[3397], mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[3450], mpc123_tmp2_16, &mpc123_arr_t1[3450]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vsub_16(&mpc123_arr_t1[3450], mpc123_tmp1_16, &mpc123_arr_t1[3450]);
/* Zeitschritt 3 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[3768], &mpc123_arr_t1[3784], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3837], mpc123_tmp1_16, &mpc123_arr_t1[3837]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vsub_16(&mpc123_arr_t1[3837], mpc123_tmp2_16, &mpc123_arr_t1[3837]);
/* Zeitschritt 4 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[4155], &mpc123_arr_t1[4171], mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[4224], mpc123_tmp2_16, &mpc123_arr_t1[4224]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vsub_16(&mpc123_arr_t1[4224], mpc123_tmp1_16, &mpc123_arr_t1[4224]);
/* Zeitschritt 5 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[4542], &mpc123_arr_t1[4558], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4611], mpc123_tmp1_16, &mpc123_arr_t1[4611]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vsub_16(&mpc123_arr_t1[4611], mpc123_tmp2_16, &mpc123_arr_t1[4611]);
/* Zeitschritt 6 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[4929], &mpc123_arr_t1[4945], mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[4998], mpc123_tmp2_16, &mpc123_arr_t1[4998]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vsub_16(&mpc123_arr_t1[4998], mpc123_tmp1_16, &mpc123_arr_t1[4998]);
/* Zeitschritt 7 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[5316], &mpc123_arr_t1[5332], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5385], mpc123_tmp1_16, &mpc123_arr_t1[5385]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vsub_16(&mpc123_arr_t1[5385], mpc123_tmp2_16, &mpc123_arr_t1[5385]);
/* Zeitschritt 8 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[5703], &mpc123_arr_t1[5719], mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[5772], mpc123_tmp2_16, &mpc123_arr_t1[5772]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vsub_16(&mpc123_arr_t1[5772], mpc123_tmp1_16, &mpc123_arr_t1[5772]);
/* Zeitschritt 9 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[6090], &mpc123_arr_t1[6106], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6159], mpc123_tmp1_16, &mpc123_arr_t1[6159]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vsub_16(&mpc123_arr_t1[6159], mpc123_tmp2_16, &mpc123_arr_t1[6159]);
/* Zeitschritt 10 */
/* rk_corr */
mpc123_vv_elemult_16(&mpc123_arr_t1[6477], &mpc123_arr_t1[6493], mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[6546], mpc123_tmp2_16, &mpc123_arr_t1[6546]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_16(mpc123_tmp1_1, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vsub_16(&mpc123_arr_t1[6546], mpc123_tmp1_16, &mpc123_arr_t1[6546]);
/* Zeitschritt 11 */
/* rk_corr */
mpc123_vv_elemult_8(&mpc123_arr_t1[6840], &mpc123_arr_t1[6848], mpc123_tmp2_8);
mpc123_vadd_8(&mpc123_arr_t1[6881], mpc123_tmp2_8, &mpc123_arr_t1[6881]);
mpc123_v_init1_8(mpc123_tmp2_8);
mpc123_v_init0_8(mpc123_tmp1_8);
mpc123_vv_elemult_1(mpc123_sigma, mpc123_mu, mpc123_tmp1_1);
mpc123_sv_8(mpc123_tmp1_1, mpc123_tmp2_8, mpc123_tmp1_8);
mpc123_vsub_8(&mpc123_arr_t1[6881], mpc123_tmp1_8, &mpc123_arr_t1[6881]);
}


static void mpc123_glqdocpip_rhs_reduced()
{
  int i1;
mpc123_error_source = 3;
/* Zeitschritt 0 */
/* rhsxs */
mpc123_v_init0_4(&mpc123_arr_t1[2747]);
mpc123_vsub_4(&mpc123_arr_t1[2724], &mpc123_arr_t1[2728], &mpc123_arr_t1[2747]);
mpc123_vv_elediv_4(&mpc123_arr_t1[2732], &mpc123_arr_t1[2658], mpc123_tmp1_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_4(&mpc123_arr_t1[2747], mpc123_tmp1_4_1, &mpc123_arr_t1[2747]);
mpc123_vv_elediv_4(&mpc123_arr_t1[2736], &mpc123_arr_t1[2662], mpc123_tmp1_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(&mpc123_arr_t1[2747], mpc123_tmp1_4_1, &mpc123_arr_t1[2747]);
mpc123_v_init0_4(mpc123_tmp2_4_1);
mpc123_vsub_4(&mpc123_arr_t1[2728], mpc123_tmp1_4_1, mpc123_tmp2_4_1);
mpc123_v_copy_4(&mpc123_arr_t1[2714], mpc123_tmp1_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[44], mpc123_tmp2_4_1, mpc123_tmp1_4_1);
mpc123_v_init1_4(mpc123_tmp2_4_1);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[44], mpc123_tmp2_4_1, mpc123_tmp3_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[2662], &mpc123_arr_t1[2670], mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp3_4_1, mpc123_tmp2_4_1, mpc123_tmp2_4_1);
mpc123_vv_elediv_4(mpc123_tmp1_4_1, mpc123_tmp2_4_1, mpc123_tmp1_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(&mpc123_arr_t1[2747], mpc123_tmp1_4_1, &mpc123_arr_t1[2747]);
/* yny */
mpc123_v_init0_4(&mpc123_arr_t1[2751]);
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_v_init0_4(mpc123_tmp2_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[44], mpc123_tmp3_4_1, mpc123_tmp2_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[2662], &mpc123_arr_t1[2670], mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp2_4_1, mpc123_tmp3_4_1, mpc123_tmp2_4_1);
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_vv_elediv_4(mpc123_tmp3_4_1, mpc123_tmp2_4_1, mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_4(&mpc123_arr_t1[2666], &mpc123_arr_t1[2658], mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp3_4_1, mpc123_tmp2_4_1, mpc123_tmp2_4_1);
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_vv_elediv_4(mpc123_tmp3_4_1, mpc123_tmp2_4_1, &mpc123_arr_t1[2751]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_4(&mpc123_arr_t1[2747], mpc123_tmp2_4_1);
mpc123_vv_elemult_4(&mpc123_arr_t1[2751], mpc123_tmp2_4_1, mpc123_tmp2_4_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[2707], &mpc123_arr_t1[2740]);
mpc123_mtv_sid51_sid15_4_6(&mpc123_arr_t1[119], mpc123_tmp2_4_1, &mpc123_arr_t1[2740]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[2713], &mpc123_arr_t1[2746]);
mpc123_mtv_sid54_sid15_4_1(&mpc123_arr_t1[143], mpc123_tmp2_4_1, &mpc123_arr_t1[2746]);
/* Zeitschritt 1 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[3086]);
mpc123_vsub_8(&mpc123_arr_t1[3047], &mpc123_arr_t1[3055], &mpc123_arr_t1[3086]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3063], &mpc123_arr_t1[2941], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3086], mpc123_tmp1_8_1, &mpc123_arr_t1[3086]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3071], &mpc123_arr_t1[2949], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3086], mpc123_tmp1_8_1, &mpc123_arr_t1[3086]);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vsub_8(&mpc123_arr_t1[3055], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[3033], mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[194], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[194], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[2949], &mpc123_arr_t1[2965], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3086], mpc123_tmp1_8_1, &mpc123_arr_t1[3086]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[3094]);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[194], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[2949], &mpc123_arr_t1[2965], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[2957], &mpc123_arr_t1[2941], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, &mpc123_arr_t1[3094]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[3086], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3094], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[3026], &mpc123_arr_t1[3079]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[321], mpc123_tmp2_8_1, &mpc123_arr_t1[3079]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[3032], &mpc123_arr_t1[3085]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[369], mpc123_tmp2_8_1, &mpc123_arr_t1[3085]);
/* Zeitschritt 2 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[3473]);
mpc123_vsub_8(&mpc123_arr_t1[3434], &mpc123_arr_t1[3442], &mpc123_arr_t1[3473]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3450], &mpc123_arr_t1[3328], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3473], mpc123_tmp2_8_1, &mpc123_arr_t1[3473]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3458], &mpc123_arr_t1[3336], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3473], mpc123_tmp2_8_1, &mpc123_arr_t1[3473]);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_vsub_8(&mpc123_arr_t1[3442], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[3420], mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[428], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[428], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3336], &mpc123_arr_t1[3352], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3473], mpc123_tmp2_8_1, &mpc123_arr_t1[3473]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[3481]);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[428], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3336], &mpc123_arr_t1[3352], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[3344], &mpc123_arr_t1[3328], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[3481]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[3473], mpc123_tmp3_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3481], mpc123_tmp3_8_1, mpc123_tmp3_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[3413], &mpc123_arr_t1[3466]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[555], mpc123_tmp3_8_1, &mpc123_arr_t1[3466]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[3419], &mpc123_arr_t1[3472]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[603], mpc123_tmp3_8_1, &mpc123_arr_t1[3472]);
/* Zeitschritt 3 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[3860]);
mpc123_vsub_8(&mpc123_arr_t1[3821], &mpc123_arr_t1[3829], &mpc123_arr_t1[3860]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3837], &mpc123_arr_t1[3715], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3860], mpc123_tmp3_8_1, &mpc123_arr_t1[3860]);
mpc123_vv_elediv_8(&mpc123_arr_t1[3845], &mpc123_arr_t1[3723], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3860], mpc123_tmp3_8_1, &mpc123_arr_t1[3860]);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vsub_8(&mpc123_arr_t1[3829], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[3807], mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[662], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[662], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3723], &mpc123_arr_t1[3739], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[3860], mpc123_tmp3_8_1, &mpc123_arr_t1[3860]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[3868]);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[662], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3723], &mpc123_arr_t1[3739], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[3731], &mpc123_arr_t1[3715], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, &mpc123_arr_t1[3868]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[3860], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3868], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[3800], &mpc123_arr_t1[3853]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[789], mpc123_tmp1_8_1, &mpc123_arr_t1[3853]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[3806], &mpc123_arr_t1[3859]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[837], mpc123_tmp1_8_1, &mpc123_arr_t1[3859]);
/* Zeitschritt 4 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[4247]);
mpc123_vsub_8(&mpc123_arr_t1[4208], &mpc123_arr_t1[4216], &mpc123_arr_t1[4247]);
mpc123_vv_elediv_8(&mpc123_arr_t1[4224], &mpc123_arr_t1[4102], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[4247], mpc123_tmp1_8_1, &mpc123_arr_t1[4247]);
mpc123_vv_elediv_8(&mpc123_arr_t1[4232], &mpc123_arr_t1[4110], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[4247], mpc123_tmp1_8_1, &mpc123_arr_t1[4247]);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vsub_8(&mpc123_arr_t1[4216], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[4194], mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[896], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[896], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4110], &mpc123_arr_t1[4126], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[4247], mpc123_tmp1_8_1, &mpc123_arr_t1[4247]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[4255]);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[896], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4110], &mpc123_arr_t1[4126], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[4118], &mpc123_arr_t1[4102], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, &mpc123_arr_t1[4255]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[4247], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[4255], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[4187], &mpc123_arr_t1[4240]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1023], mpc123_tmp2_8_1, &mpc123_arr_t1[4240]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[4193], &mpc123_arr_t1[4246]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1071], mpc123_tmp2_8_1, &mpc123_arr_t1[4246]);
/* Zeitschritt 5 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[4634]);
mpc123_vsub_8(&mpc123_arr_t1[4595], &mpc123_arr_t1[4603], &mpc123_arr_t1[4634]);
mpc123_vv_elediv_8(&mpc123_arr_t1[4611], &mpc123_arr_t1[4489], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[4634], mpc123_tmp2_8_1, &mpc123_arr_t1[4634]);
mpc123_vv_elediv_8(&mpc123_arr_t1[4619], &mpc123_arr_t1[4497], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[4634], mpc123_tmp2_8_1, &mpc123_arr_t1[4634]);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_vsub_8(&mpc123_arr_t1[4603], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[4581], mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1130], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1130], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4497], &mpc123_arr_t1[4513], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[4634], mpc123_tmp2_8_1, &mpc123_arr_t1[4634]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[4642]);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1130], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4497], &mpc123_arr_t1[4513], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[4505], &mpc123_arr_t1[4489], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[4642]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[4634], mpc123_tmp3_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[4642], mpc123_tmp3_8_1, mpc123_tmp3_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[4574], &mpc123_arr_t1[4627]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1257], mpc123_tmp3_8_1, &mpc123_arr_t1[4627]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[4580], &mpc123_arr_t1[4633]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1305], mpc123_tmp3_8_1, &mpc123_arr_t1[4633]);
/* Zeitschritt 6 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[5021]);
mpc123_vsub_8(&mpc123_arr_t1[4982], &mpc123_arr_t1[4990], &mpc123_arr_t1[5021]);
mpc123_vv_elediv_8(&mpc123_arr_t1[4998], &mpc123_arr_t1[4876], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[5021], mpc123_tmp3_8_1, &mpc123_arr_t1[5021]);
mpc123_vv_elediv_8(&mpc123_arr_t1[5006], &mpc123_arr_t1[4884], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5021], mpc123_tmp3_8_1, &mpc123_arr_t1[5021]);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vsub_8(&mpc123_arr_t1[4990], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[4968], mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1364], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1364], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4884], &mpc123_arr_t1[4900], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5021], mpc123_tmp3_8_1, &mpc123_arr_t1[5021]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[5029]);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1364], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4884], &mpc123_arr_t1[4900], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[4892], &mpc123_arr_t1[4876], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, &mpc123_arr_t1[5029]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[5021], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5029], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[4961], &mpc123_arr_t1[5014]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1491], mpc123_tmp1_8_1, &mpc123_arr_t1[5014]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[4967], &mpc123_arr_t1[5020]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1539], mpc123_tmp1_8_1, &mpc123_arr_t1[5020]);
/* Zeitschritt 7 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[5408]);
mpc123_vsub_8(&mpc123_arr_t1[5369], &mpc123_arr_t1[5377], &mpc123_arr_t1[5408]);
mpc123_vv_elediv_8(&mpc123_arr_t1[5385], &mpc123_arr_t1[5263], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[5408], mpc123_tmp1_8_1, &mpc123_arr_t1[5408]);
mpc123_vv_elediv_8(&mpc123_arr_t1[5393], &mpc123_arr_t1[5271], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5408], mpc123_tmp1_8_1, &mpc123_arr_t1[5408]);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vsub_8(&mpc123_arr_t1[5377], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[5355], mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1598], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1598], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5271], &mpc123_arr_t1[5287], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5408], mpc123_tmp1_8_1, &mpc123_arr_t1[5408]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[5416]);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1598], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5271], &mpc123_arr_t1[5287], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[5279], &mpc123_arr_t1[5263], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, &mpc123_arr_t1[5416]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[5408], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5416], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[5348], &mpc123_arr_t1[5401]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1725], mpc123_tmp2_8_1, &mpc123_arr_t1[5401]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[5354], &mpc123_arr_t1[5407]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1773], mpc123_tmp2_8_1, &mpc123_arr_t1[5407]);
/* Zeitschritt 8 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[5795]);
mpc123_vsub_8(&mpc123_arr_t1[5756], &mpc123_arr_t1[5764], &mpc123_arr_t1[5795]);
mpc123_vv_elediv_8(&mpc123_arr_t1[5772], &mpc123_arr_t1[5650], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[5795], mpc123_tmp2_8_1, &mpc123_arr_t1[5795]);
mpc123_vv_elediv_8(&mpc123_arr_t1[5780], &mpc123_arr_t1[5658], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5795], mpc123_tmp2_8_1, &mpc123_arr_t1[5795]);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_vsub_8(&mpc123_arr_t1[5764], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[5742], mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1832], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1832], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5658], &mpc123_arr_t1[5674], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[5795], mpc123_tmp2_8_1, &mpc123_arr_t1[5795]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[5803]);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1832], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5658], &mpc123_arr_t1[5674], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[5666], &mpc123_arr_t1[5650], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[5803]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[5795], mpc123_tmp3_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5803], mpc123_tmp3_8_1, mpc123_tmp3_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[5735], &mpc123_arr_t1[5788]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1959], mpc123_tmp3_8_1, &mpc123_arr_t1[5788]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[5741], &mpc123_arr_t1[5794]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2007], mpc123_tmp3_8_1, &mpc123_arr_t1[5794]);
/* Zeitschritt 9 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[6182]);
mpc123_vsub_8(&mpc123_arr_t1[6143], &mpc123_arr_t1[6151], &mpc123_arr_t1[6182]);
mpc123_vv_elediv_8(&mpc123_arr_t1[6159], &mpc123_arr_t1[6037], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[6182], mpc123_tmp3_8_1, &mpc123_arr_t1[6182]);
mpc123_vv_elediv_8(&mpc123_arr_t1[6167], &mpc123_arr_t1[6045], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[6182], mpc123_tmp3_8_1, &mpc123_arr_t1[6182]);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vsub_8(&mpc123_arr_t1[6151], mpc123_tmp3_8_1, mpc123_tmp1_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[6129], mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2066], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2066], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6045], &mpc123_arr_t1[6061], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[6182], mpc123_tmp3_8_1, &mpc123_arr_t1[6182]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[6190]);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2066], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6045], &mpc123_arr_t1[6061], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[6053], &mpc123_arr_t1[6037], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp1_8_1, &mpc123_arr_t1[6190]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[6182], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[6190], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[6122], &mpc123_arr_t1[6175]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2193], mpc123_tmp1_8_1, &mpc123_arr_t1[6175]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[6128], &mpc123_arr_t1[6181]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2241], mpc123_tmp1_8_1, &mpc123_arr_t1[6181]);
/* Zeitschritt 10 */
/* rhsxs */
mpc123_v_init0_8(&mpc123_arr_t1[6569]);
mpc123_vsub_8(&mpc123_arr_t1[6530], &mpc123_arr_t1[6538], &mpc123_arr_t1[6569]);
mpc123_vv_elediv_8(&mpc123_arr_t1[6546], &mpc123_arr_t1[6424], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[6569], mpc123_tmp1_8_1, &mpc123_arr_t1[6569]);
mpc123_vv_elediv_8(&mpc123_arr_t1[6554], &mpc123_arr_t1[6432], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[6569], mpc123_tmp1_8_1, &mpc123_arr_t1[6569]);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vsub_8(&mpc123_arr_t1[6538], mpc123_tmp1_8_1, mpc123_tmp2_8_1);
mpc123_v_copy_8(&mpc123_arr_t1[6516], mpc123_tmp1_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2300], mpc123_tmp2_8_1, mpc123_tmp1_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2300], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6432], &mpc123_arr_t1[6448], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp2_8_1, mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(&mpc123_arr_t1[6569], mpc123_tmp1_8_1, &mpc123_arr_t1[6569]);
/* yny */
mpc123_v_init0_8(&mpc123_arr_t1[6577]);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2300], mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6432], &mpc123_arr_t1[6448], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_8(&mpc123_arr_t1[6440], &mpc123_arr_t1[6424], mpc123_tmp3_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_v_init1_8(mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, &mpc123_arr_t1[6577]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_8(&mpc123_arr_t1[6569], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[6577], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[6509], &mpc123_arr_t1[6562]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2427], mpc123_tmp2_8_1, &mpc123_arr_t1[6562]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[6515], &mpc123_arr_t1[6568]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2475], mpc123_tmp2_8_1, &mpc123_arr_t1[6568]);
/* Zeitschritt 11 */
/* rhsxs */
mpc123_v_init0_4(&mpc123_arr_t1[6896]);
mpc123_vsub_4(&mpc123_arr_t1[6873], &mpc123_arr_t1[6877], &mpc123_arr_t1[6896]);
mpc123_vv_elediv_4(&mpc123_arr_t1[6881], &mpc123_arr_t1[6807], mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_4(&mpc123_arr_t1[6896], mpc123_tmp2_4_1, &mpc123_arr_t1[6896]);
mpc123_vv_elediv_4(&mpc123_arr_t1[6885], &mpc123_arr_t1[6811], mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(&mpc123_arr_t1[6896], mpc123_tmp2_4_1, &mpc123_arr_t1[6896]);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_vsub_4(&mpc123_arr_t1[6877], mpc123_tmp2_4_1, mpc123_tmp3_4_1);
mpc123_v_copy_4(&mpc123_arr_t1[6863], mpc123_tmp2_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[2534], mpc123_tmp3_4_1, mpc123_tmp2_4_1);
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_v_init0_4(mpc123_tmp1_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[2534], mpc123_tmp3_4_1, mpc123_tmp1_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[6811], &mpc123_arr_t1[6819], mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp3_4_1);
mpc123_vv_elediv_4(mpc123_tmp2_4_1, mpc123_tmp3_4_1, mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(&mpc123_arr_t1[6896], mpc123_tmp2_4_1, &mpc123_arr_t1[6896]);
/* yny */
mpc123_v_init0_4(&mpc123_arr_t1[6900]);
mpc123_v_init1_4(mpc123_tmp1_4_1);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[2534], mpc123_tmp1_4_1, mpc123_tmp3_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[6811], &mpc123_arr_t1[6819], mpc123_tmp1_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp3_4_1, mpc123_tmp1_4_1, mpc123_tmp3_4_1);
mpc123_v_init1_4(mpc123_tmp1_4_1);
mpc123_vv_elediv_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elediv_4(&mpc123_arr_t1[6815], &mpc123_arr_t1[6807], mpc123_tmp1_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vadd_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp3_4_1);
mpc123_v_init1_4(mpc123_tmp1_4_1);
mpc123_vv_elediv_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, &mpc123_arr_t1[6900]);
if(mpc123_termcode > -1){return;}
/* v1 */
mpc123_v_copy_4(&mpc123_arr_t1[6896], mpc123_tmp3_4_1);
mpc123_vv_elemult_4(&mpc123_arr_t1[6900], mpc123_tmp3_4_1, mpc123_tmp3_4_1);
/* rrf0x */
mpc123_v_copy_6(&mpc123_arr_t1[6856], &mpc123_arr_t1[6889]);
mpc123_mtv_sid53_sid17_4_6(&mpc123_arr_t1[2609], mpc123_tmp3_4_1, &mpc123_arr_t1[6889]);
/* rrf0u */
mpc123_v_copy_1(&mpc123_arr_t1[6862], &mpc123_arr_t1[6895]);
mpc123_mtv_sid56_sid17_4_1(&mpc123_arr_t1[2633], mpc123_tmp3_4_1, &mpc123_arr_t1[6895]);
mpc123_error_source = 0;
}


static void mpc123_glqdocpip_rhs_iter_ref()
{
  int i1;
/* Zeitschritt 0 */
/* rf0x */
mpc123_mv_sid21_sid2_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[2674], &mpc123_arr_t1[2707]);
mpc123_mv_sid24_sid5_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2680], &mpc123_arr_t1[2707]);
mpc123_vsub_6(&mpc123_arr_t1[2707], &mpc123_arr_t1[2685], &mpc123_arr_t1[2707]);
mpc123_mtv_sid42_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2988], &mpc123_arr_t1[2707]);
mpc123_mtv_sid51_sid15_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2691], &mpc123_arr_t1[2707]);
/* rf0u */
mpc123_mtv_sid24_sid2_6_1(&mpc123_arr_t1[37], &mpc123_arr_t1[2674], &mpc123_arr_t1[2713]);
mpc123_mv_sid27_sid5_1_1(&mpc123_arr_t1[43], &mpc123_arr_t1[2680], &mpc123_arr_t1[2713]);
mpc123_mtv_sid45_sid2_6_1(&mpc123_arr_t1[107], &mpc123_arr_t1[2988], &mpc123_arr_t1[2713]);
mpc123_mtv_sid54_sid15_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2691], &mpc123_arr_t1[2713]);
/* rf0s */
mpc123_mv_sid30_sid18_4_4(&mpc123_arr_t1[44], &mpc123_arr_t1[2681], &mpc123_arr_t1[2714]);
mpc123_vsub_4(&mpc123_arr_t1[2714], &mpc123_arr_t1[2691], &mpc123_arr_t1[2714]);
mpc123_vsub_4(&mpc123_arr_t1[2714], &mpc123_arr_t1[2695], &mpc123_arr_t1[2714]);
/* rf */
mpc123_vsub_6(&mpc123_arr_t1[2718], &mpc123_arr_t1[2674], &mpc123_arr_t1[2718]);
/* rc */
mpc123_mv_sid51_sid2_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2674], &mpc123_arr_t1[2724]);
mpc123_mv_sid54_sid5_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2680], &mpc123_arr_t1[2724]);
mpc123_vadd_4(&mpc123_arr_t1[2724], &mpc123_arr_t1[2699], &mpc123_arr_t1[2724]);
mpc123_vsub_4(&mpc123_arr_t1[2724], &mpc123_arr_t1[2681], &mpc123_arr_t1[2724]);
/* rs */
mpc123_vadd_4(&mpc123_arr_t1[2728], &mpc123_arr_t1[2703], &mpc123_arr_t1[2728]);
mpc123_vsub_4(&mpc123_arr_t1[2728], &mpc123_arr_t1[2681], &mpc123_arr_t1[2728]);
/* rk */
mpc123_vv_elemult_8(&mpc123_arr_t1[2691], &mpc123_arr_t1[2666], mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[2732], mpc123_tmp1_8, &mpc123_arr_t1[2732]);
mpc123_vv_elemult_8(&mpc123_arr_t1[2699], &mpc123_arr_t1[2658], mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[2732], mpc123_tmp1_8, &mpc123_arr_t1[2732]);
/* Zeitschritt 1 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[151], &mpc123_arr_t1[2973], &mpc123_arr_t1[3026]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[2979], &mpc123_arr_t1[3026]);
mpc123_vsub_6(&mpc123_arr_t1[3026], &mpc123_arr_t1[2988], &mpc123_arr_t1[3026]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[3375], &mpc123_arr_t1[3026]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[2994], &mpc123_arr_t1[3026]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[187], &mpc123_arr_t1[2973], &mpc123_arr_t1[3032]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[193], &mpc123_arr_t1[2979], &mpc123_arr_t1[3032]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[309], &mpc123_arr_t1[3375], &mpc123_arr_t1[3032]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[2994], &mpc123_arr_t1[3032]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[194], &mpc123_arr_t1[2980], &mpc123_arr_t1[3033]);
mpc123_vsub_8(&mpc123_arr_t1[3033], &mpc123_arr_t1[2994], &mpc123_arr_t1[3033]);
mpc123_vsub_8(&mpc123_arr_t1[3033], &mpc123_arr_t1[3002], &mpc123_arr_t1[3033]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2674], &mpc123_arr_t1[3041]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[107], &mpc123_arr_t1[2680], &mpc123_arr_t1[3041]);
mpc123_vsub_6(&mpc123_arr_t1[3041], &mpc123_arr_t1[2973], &mpc123_arr_t1[3041]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[2973], &mpc123_arr_t1[3047]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[2979], &mpc123_arr_t1[3047]);
mpc123_vadd_8(&mpc123_arr_t1[3047], &mpc123_arr_t1[3010], &mpc123_arr_t1[3047]);
mpc123_vsub_8(&mpc123_arr_t1[3047], &mpc123_arr_t1[2980], &mpc123_arr_t1[3047]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[3055], &mpc123_arr_t1[3018], &mpc123_arr_t1[3055]);
mpc123_vsub_8(&mpc123_arr_t1[3055], &mpc123_arr_t1[2980], &mpc123_arr_t1[3055]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[2994], &mpc123_arr_t1[2957], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3063], mpc123_tmp1_16, &mpc123_arr_t1[3063]);
mpc123_vv_elemult_16(&mpc123_arr_t1[3010], &mpc123_arr_t1[2941], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3063], mpc123_tmp1_16, &mpc123_arr_t1[3063]);
/* Zeitschritt 2 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[385], &mpc123_arr_t1[3360], &mpc123_arr_t1[3413]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3366], &mpc123_arr_t1[3413]);
mpc123_vsub_6(&mpc123_arr_t1[3413], &mpc123_arr_t1[3375], &mpc123_arr_t1[3413]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3762], &mpc123_arr_t1[3413]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3381], &mpc123_arr_t1[3413]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[421], &mpc123_arr_t1[3360], &mpc123_arr_t1[3419]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[427], &mpc123_arr_t1[3366], &mpc123_arr_t1[3419]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[543], &mpc123_arr_t1[3762], &mpc123_arr_t1[3419]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3381], &mpc123_arr_t1[3419]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[428], &mpc123_arr_t1[3367], &mpc123_arr_t1[3420]);
mpc123_vsub_8(&mpc123_arr_t1[3420], &mpc123_arr_t1[3381], &mpc123_arr_t1[3420]);
mpc123_vsub_8(&mpc123_arr_t1[3420], &mpc123_arr_t1[3389], &mpc123_arr_t1[3420]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[273], &mpc123_arr_t1[2973], &mpc123_arr_t1[3428]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[309], &mpc123_arr_t1[2979], &mpc123_arr_t1[3428]);
mpc123_vsub_6(&mpc123_arr_t1[3428], &mpc123_arr_t1[3360], &mpc123_arr_t1[3428]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3360], &mpc123_arr_t1[3434]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3366], &mpc123_arr_t1[3434]);
mpc123_vadd_8(&mpc123_arr_t1[3434], &mpc123_arr_t1[3397], &mpc123_arr_t1[3434]);
mpc123_vsub_8(&mpc123_arr_t1[3434], &mpc123_arr_t1[3367], &mpc123_arr_t1[3434]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[3442], &mpc123_arr_t1[3405], &mpc123_arr_t1[3442]);
mpc123_vsub_8(&mpc123_arr_t1[3442], &mpc123_arr_t1[3367], &mpc123_arr_t1[3442]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[3381], &mpc123_arr_t1[3344], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3450], mpc123_tmp1_16, &mpc123_arr_t1[3450]);
mpc123_vv_elemult_16(&mpc123_arr_t1[3397], &mpc123_arr_t1[3328], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3450], mpc123_tmp1_16, &mpc123_arr_t1[3450]);
/* Zeitschritt 3 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[619], &mpc123_arr_t1[3747], &mpc123_arr_t1[3800]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3753], &mpc123_arr_t1[3800]);
mpc123_vsub_6(&mpc123_arr_t1[3800], &mpc123_arr_t1[3762], &mpc123_arr_t1[3800]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[4149], &mpc123_arr_t1[3800]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3768], &mpc123_arr_t1[3800]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[655], &mpc123_arr_t1[3747], &mpc123_arr_t1[3806]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[661], &mpc123_arr_t1[3753], &mpc123_arr_t1[3806]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[777], &mpc123_arr_t1[4149], &mpc123_arr_t1[3806]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3768], &mpc123_arr_t1[3806]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[662], &mpc123_arr_t1[3754], &mpc123_arr_t1[3807]);
mpc123_vsub_8(&mpc123_arr_t1[3807], &mpc123_arr_t1[3768], &mpc123_arr_t1[3807]);
mpc123_vsub_8(&mpc123_arr_t1[3807], &mpc123_arr_t1[3776], &mpc123_arr_t1[3807]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[507], &mpc123_arr_t1[3360], &mpc123_arr_t1[3815]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[543], &mpc123_arr_t1[3366], &mpc123_arr_t1[3815]);
mpc123_vsub_6(&mpc123_arr_t1[3815], &mpc123_arr_t1[3747], &mpc123_arr_t1[3815]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3747], &mpc123_arr_t1[3821]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3753], &mpc123_arr_t1[3821]);
mpc123_vadd_8(&mpc123_arr_t1[3821], &mpc123_arr_t1[3784], &mpc123_arr_t1[3821]);
mpc123_vsub_8(&mpc123_arr_t1[3821], &mpc123_arr_t1[3754], &mpc123_arr_t1[3821]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[3829], &mpc123_arr_t1[3792], &mpc123_arr_t1[3829]);
mpc123_vsub_8(&mpc123_arr_t1[3829], &mpc123_arr_t1[3754], &mpc123_arr_t1[3829]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[3768], &mpc123_arr_t1[3731], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3837], mpc123_tmp1_16, &mpc123_arr_t1[3837]);
mpc123_vv_elemult_16(&mpc123_arr_t1[3784], &mpc123_arr_t1[3715], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3837], mpc123_tmp1_16, &mpc123_arr_t1[3837]);
/* Zeitschritt 4 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[853], &mpc123_arr_t1[4134], &mpc123_arr_t1[4187]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4140], &mpc123_arr_t1[4187]);
mpc123_vsub_6(&mpc123_arr_t1[4187], &mpc123_arr_t1[4149], &mpc123_arr_t1[4187]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4536], &mpc123_arr_t1[4187]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4155], &mpc123_arr_t1[4187]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[889], &mpc123_arr_t1[4134], &mpc123_arr_t1[4193]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[895], &mpc123_arr_t1[4140], &mpc123_arr_t1[4193]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1011], &mpc123_arr_t1[4536], &mpc123_arr_t1[4193]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4155], &mpc123_arr_t1[4193]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[896], &mpc123_arr_t1[4141], &mpc123_arr_t1[4194]);
mpc123_vsub_8(&mpc123_arr_t1[4194], &mpc123_arr_t1[4155], &mpc123_arr_t1[4194]);
mpc123_vsub_8(&mpc123_arr_t1[4194], &mpc123_arr_t1[4163], &mpc123_arr_t1[4194]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[741], &mpc123_arr_t1[3747], &mpc123_arr_t1[4202]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[777], &mpc123_arr_t1[3753], &mpc123_arr_t1[4202]);
mpc123_vsub_6(&mpc123_arr_t1[4202], &mpc123_arr_t1[4134], &mpc123_arr_t1[4202]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4134], &mpc123_arr_t1[4208]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4140], &mpc123_arr_t1[4208]);
mpc123_vadd_8(&mpc123_arr_t1[4208], &mpc123_arr_t1[4171], &mpc123_arr_t1[4208]);
mpc123_vsub_8(&mpc123_arr_t1[4208], &mpc123_arr_t1[4141], &mpc123_arr_t1[4208]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[4216], &mpc123_arr_t1[4179], &mpc123_arr_t1[4216]);
mpc123_vsub_8(&mpc123_arr_t1[4216], &mpc123_arr_t1[4141], &mpc123_arr_t1[4216]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4155], &mpc123_arr_t1[4118], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4224], mpc123_tmp1_16, &mpc123_arr_t1[4224]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4171], &mpc123_arr_t1[4102], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4224], mpc123_tmp1_16, &mpc123_arr_t1[4224]);
/* Zeitschritt 5 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1087], &mpc123_arr_t1[4521], &mpc123_arr_t1[4574]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4527], &mpc123_arr_t1[4574]);
mpc123_vsub_6(&mpc123_arr_t1[4574], &mpc123_arr_t1[4536], &mpc123_arr_t1[4574]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[4923], &mpc123_arr_t1[4574]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4542], &mpc123_arr_t1[4574]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1123], &mpc123_arr_t1[4521], &mpc123_arr_t1[4580]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1129], &mpc123_arr_t1[4527], &mpc123_arr_t1[4580]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1245], &mpc123_arr_t1[4923], &mpc123_arr_t1[4580]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4542], &mpc123_arr_t1[4580]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1130], &mpc123_arr_t1[4528], &mpc123_arr_t1[4581]);
mpc123_vsub_8(&mpc123_arr_t1[4581], &mpc123_arr_t1[4542], &mpc123_arr_t1[4581]);
mpc123_vsub_8(&mpc123_arr_t1[4581], &mpc123_arr_t1[4550], &mpc123_arr_t1[4581]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[975], &mpc123_arr_t1[4134], &mpc123_arr_t1[4589]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1011], &mpc123_arr_t1[4140], &mpc123_arr_t1[4589]);
mpc123_vsub_6(&mpc123_arr_t1[4589], &mpc123_arr_t1[4521], &mpc123_arr_t1[4589]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4521], &mpc123_arr_t1[4595]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4527], &mpc123_arr_t1[4595]);
mpc123_vadd_8(&mpc123_arr_t1[4595], &mpc123_arr_t1[4558], &mpc123_arr_t1[4595]);
mpc123_vsub_8(&mpc123_arr_t1[4595], &mpc123_arr_t1[4528], &mpc123_arr_t1[4595]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[4603], &mpc123_arr_t1[4566], &mpc123_arr_t1[4603]);
mpc123_vsub_8(&mpc123_arr_t1[4603], &mpc123_arr_t1[4528], &mpc123_arr_t1[4603]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4542], &mpc123_arr_t1[4505], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4611], mpc123_tmp1_16, &mpc123_arr_t1[4611]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4558], &mpc123_arr_t1[4489], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4611], mpc123_tmp1_16, &mpc123_arr_t1[4611]);
/* Zeitschritt 6 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1321], &mpc123_arr_t1[4908], &mpc123_arr_t1[4961]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[4914], &mpc123_arr_t1[4961]);
mpc123_vsub_6(&mpc123_arr_t1[4961], &mpc123_arr_t1[4923], &mpc123_arr_t1[4961]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[5310], &mpc123_arr_t1[4961]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[4929], &mpc123_arr_t1[4961]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1357], &mpc123_arr_t1[4908], &mpc123_arr_t1[4967]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1363], &mpc123_arr_t1[4914], &mpc123_arr_t1[4967]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1479], &mpc123_arr_t1[5310], &mpc123_arr_t1[4967]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[4929], &mpc123_arr_t1[4967]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1364], &mpc123_arr_t1[4915], &mpc123_arr_t1[4968]);
mpc123_vsub_8(&mpc123_arr_t1[4968], &mpc123_arr_t1[4929], &mpc123_arr_t1[4968]);
mpc123_vsub_8(&mpc123_arr_t1[4968], &mpc123_arr_t1[4937], &mpc123_arr_t1[4968]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1209], &mpc123_arr_t1[4521], &mpc123_arr_t1[4976]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1245], &mpc123_arr_t1[4527], &mpc123_arr_t1[4976]);
mpc123_vsub_6(&mpc123_arr_t1[4976], &mpc123_arr_t1[4908], &mpc123_arr_t1[4976]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[4908], &mpc123_arr_t1[4982]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[4914], &mpc123_arr_t1[4982]);
mpc123_vadd_8(&mpc123_arr_t1[4982], &mpc123_arr_t1[4945], &mpc123_arr_t1[4982]);
mpc123_vsub_8(&mpc123_arr_t1[4982], &mpc123_arr_t1[4915], &mpc123_arr_t1[4982]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[4990], &mpc123_arr_t1[4953], &mpc123_arr_t1[4990]);
mpc123_vsub_8(&mpc123_arr_t1[4990], &mpc123_arr_t1[4915], &mpc123_arr_t1[4990]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[4929], &mpc123_arr_t1[4892], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4998], mpc123_tmp1_16, &mpc123_arr_t1[4998]);
mpc123_vv_elemult_16(&mpc123_arr_t1[4945], &mpc123_arr_t1[4876], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4998], mpc123_tmp1_16, &mpc123_arr_t1[4998]);
/* Zeitschritt 7 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1555], &mpc123_arr_t1[5295], &mpc123_arr_t1[5348]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5301], &mpc123_arr_t1[5348]);
mpc123_vsub_6(&mpc123_arr_t1[5348], &mpc123_arr_t1[5310], &mpc123_arr_t1[5348]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5697], &mpc123_arr_t1[5348]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5316], &mpc123_arr_t1[5348]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1591], &mpc123_arr_t1[5295], &mpc123_arr_t1[5354]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1597], &mpc123_arr_t1[5301], &mpc123_arr_t1[5354]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1713], &mpc123_arr_t1[5697], &mpc123_arr_t1[5354]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5316], &mpc123_arr_t1[5354]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1598], &mpc123_arr_t1[5302], &mpc123_arr_t1[5355]);
mpc123_vsub_8(&mpc123_arr_t1[5355], &mpc123_arr_t1[5316], &mpc123_arr_t1[5355]);
mpc123_vsub_8(&mpc123_arr_t1[5355], &mpc123_arr_t1[5324], &mpc123_arr_t1[5355]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1443], &mpc123_arr_t1[4908], &mpc123_arr_t1[5363]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1479], &mpc123_arr_t1[4914], &mpc123_arr_t1[5363]);
mpc123_vsub_6(&mpc123_arr_t1[5363], &mpc123_arr_t1[5295], &mpc123_arr_t1[5363]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5295], &mpc123_arr_t1[5369]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5301], &mpc123_arr_t1[5369]);
mpc123_vadd_8(&mpc123_arr_t1[5369], &mpc123_arr_t1[5332], &mpc123_arr_t1[5369]);
mpc123_vsub_8(&mpc123_arr_t1[5369], &mpc123_arr_t1[5302], &mpc123_arr_t1[5369]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[5377], &mpc123_arr_t1[5340], &mpc123_arr_t1[5377]);
mpc123_vsub_8(&mpc123_arr_t1[5377], &mpc123_arr_t1[5302], &mpc123_arr_t1[5377]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[5316], &mpc123_arr_t1[5279], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5385], mpc123_tmp1_16, &mpc123_arr_t1[5385]);
mpc123_vv_elemult_16(&mpc123_arr_t1[5332], &mpc123_arr_t1[5263], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5385], mpc123_tmp1_16, &mpc123_arr_t1[5385]);
/* Zeitschritt 8 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[1789], &mpc123_arr_t1[5682], &mpc123_arr_t1[5735]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5688], &mpc123_arr_t1[5735]);
mpc123_vsub_6(&mpc123_arr_t1[5735], &mpc123_arr_t1[5697], &mpc123_arr_t1[5735]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[6084], &mpc123_arr_t1[5735]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5703], &mpc123_arr_t1[5735]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[1825], &mpc123_arr_t1[5682], &mpc123_arr_t1[5741]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[1831], &mpc123_arr_t1[5688], &mpc123_arr_t1[5741]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[1947], &mpc123_arr_t1[6084], &mpc123_arr_t1[5741]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5703], &mpc123_arr_t1[5741]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[1832], &mpc123_arr_t1[5689], &mpc123_arr_t1[5742]);
mpc123_vsub_8(&mpc123_arr_t1[5742], &mpc123_arr_t1[5703], &mpc123_arr_t1[5742]);
mpc123_vsub_8(&mpc123_arr_t1[5742], &mpc123_arr_t1[5711], &mpc123_arr_t1[5742]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1677], &mpc123_arr_t1[5295], &mpc123_arr_t1[5750]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1713], &mpc123_arr_t1[5301], &mpc123_arr_t1[5750]);
mpc123_vsub_6(&mpc123_arr_t1[5750], &mpc123_arr_t1[5682], &mpc123_arr_t1[5750]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5682], &mpc123_arr_t1[5756]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5688], &mpc123_arr_t1[5756]);
mpc123_vadd_8(&mpc123_arr_t1[5756], &mpc123_arr_t1[5719], &mpc123_arr_t1[5756]);
mpc123_vsub_8(&mpc123_arr_t1[5756], &mpc123_arr_t1[5689], &mpc123_arr_t1[5756]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[5764], &mpc123_arr_t1[5727], &mpc123_arr_t1[5764]);
mpc123_vsub_8(&mpc123_arr_t1[5764], &mpc123_arr_t1[5689], &mpc123_arr_t1[5764]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[5703], &mpc123_arr_t1[5666], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5772], mpc123_tmp1_16, &mpc123_arr_t1[5772]);
mpc123_vv_elemult_16(&mpc123_arr_t1[5719], &mpc123_arr_t1[5650], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5772], mpc123_tmp1_16, &mpc123_arr_t1[5772]);
/* Zeitschritt 9 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2023], &mpc123_arr_t1[6069], &mpc123_arr_t1[6122]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6075], &mpc123_arr_t1[6122]);
mpc123_vsub_6(&mpc123_arr_t1[6122], &mpc123_arr_t1[6084], &mpc123_arr_t1[6122]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6471], &mpc123_arr_t1[6122]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6090], &mpc123_arr_t1[6122]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[2059], &mpc123_arr_t1[6069], &mpc123_arr_t1[6128]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2065], &mpc123_arr_t1[6075], &mpc123_arr_t1[6128]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2181], &mpc123_arr_t1[6471], &mpc123_arr_t1[6128]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6090], &mpc123_arr_t1[6128]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[2066], &mpc123_arr_t1[6076], &mpc123_arr_t1[6129]);
mpc123_vsub_8(&mpc123_arr_t1[6129], &mpc123_arr_t1[6090], &mpc123_arr_t1[6129]);
mpc123_vsub_8(&mpc123_arr_t1[6129], &mpc123_arr_t1[6098], &mpc123_arr_t1[6129]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[1911], &mpc123_arr_t1[5682], &mpc123_arr_t1[6137]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[1947], &mpc123_arr_t1[5688], &mpc123_arr_t1[6137]);
mpc123_vsub_6(&mpc123_arr_t1[6137], &mpc123_arr_t1[6069], &mpc123_arr_t1[6137]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6069], &mpc123_arr_t1[6143]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6075], &mpc123_arr_t1[6143]);
mpc123_vadd_8(&mpc123_arr_t1[6143], &mpc123_arr_t1[6106], &mpc123_arr_t1[6143]);
mpc123_vsub_8(&mpc123_arr_t1[6143], &mpc123_arr_t1[6076], &mpc123_arr_t1[6143]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[6151], &mpc123_arr_t1[6114], &mpc123_arr_t1[6151]);
mpc123_vsub_8(&mpc123_arr_t1[6151], &mpc123_arr_t1[6076], &mpc123_arr_t1[6151]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[6090], &mpc123_arr_t1[6053], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6159], mpc123_tmp1_16, &mpc123_arr_t1[6159]);
mpc123_vv_elemult_16(&mpc123_arr_t1[6106], &mpc123_arr_t1[6037], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6159], mpc123_tmp1_16, &mpc123_arr_t1[6159]);
/* Zeitschritt 10 */
/* rf0x */
mpc123_mv_sid22_sid2_6_6(&mpc123_arr_t1[2257], &mpc123_arr_t1[6456], &mpc123_arr_t1[6509]);
mpc123_mv_sid25_sid5_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6462], &mpc123_arr_t1[6509]);
mpc123_vsub_6(&mpc123_arr_t1[6509], &mpc123_arr_t1[6471], &mpc123_arr_t1[6509]);
mpc123_mtv_sid43_sid2_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6834], &mpc123_arr_t1[6509]);
mpc123_mtv_sid52_sid16_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6477], &mpc123_arr_t1[6509]);
/* rf0u */
mpc123_mtv_sid25_sid2_6_1(&mpc123_arr_t1[2293], &mpc123_arr_t1[6456], &mpc123_arr_t1[6515]);
mpc123_mv_sid28_sid5_1_1(&mpc123_arr_t1[2299], &mpc123_arr_t1[6462], &mpc123_arr_t1[6515]);
mpc123_mtv_sid46_sid2_6_1(&mpc123_arr_t1[2415], &mpc123_arr_t1[6834], &mpc123_arr_t1[6515]);
mpc123_mtv_sid55_sid16_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6477], &mpc123_arr_t1[6515]);
/* rf0s */
mpc123_mv_sid31_sid19_8_8(&mpc123_arr_t1[2300], &mpc123_arr_t1[6463], &mpc123_arr_t1[6516]);
mpc123_vsub_8(&mpc123_arr_t1[6516], &mpc123_arr_t1[6477], &mpc123_arr_t1[6516]);
mpc123_vsub_8(&mpc123_arr_t1[6516], &mpc123_arr_t1[6485], &mpc123_arr_t1[6516]);
/* rf */
mpc123_mv_sid43_sid2_6_6(&mpc123_arr_t1[2145], &mpc123_arr_t1[6069], &mpc123_arr_t1[6524]);
mpc123_mv_sid46_sid5_6_1(&mpc123_arr_t1[2181], &mpc123_arr_t1[6075], &mpc123_arr_t1[6524]);
mpc123_vsub_6(&mpc123_arr_t1[6524], &mpc123_arr_t1[6456], &mpc123_arr_t1[6524]);
/* rc */
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6456], &mpc123_arr_t1[6530]);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6462], &mpc123_arr_t1[6530]);
mpc123_vadd_8(&mpc123_arr_t1[6530], &mpc123_arr_t1[6493], &mpc123_arr_t1[6530]);
mpc123_vsub_8(&mpc123_arr_t1[6530], &mpc123_arr_t1[6463], &mpc123_arr_t1[6530]);
/* rs */
mpc123_vadd_8(&mpc123_arr_t1[6538], &mpc123_arr_t1[6501], &mpc123_arr_t1[6538]);
mpc123_vsub_8(&mpc123_arr_t1[6538], &mpc123_arr_t1[6463], &mpc123_arr_t1[6538]);
/* rk */
mpc123_vv_elemult_16(&mpc123_arr_t1[6477], &mpc123_arr_t1[6440], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6546], mpc123_tmp1_16, &mpc123_arr_t1[6546]);
mpc123_vv_elemult_16(&mpc123_arr_t1[6493], &mpc123_arr_t1[6424], mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6546], mpc123_tmp1_16, &mpc123_arr_t1[6546]);
/* Zeitschritt 11 */
/* rf0x */
mpc123_mv_sid23_sid2_6_6(&mpc123_arr_t1[2491], &mpc123_arr_t1[6823], &mpc123_arr_t1[6856]);
mpc123_mv_sid26_sid5_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6829], &mpc123_arr_t1[6856]);
mpc123_vsub_6(&mpc123_arr_t1[6856], &mpc123_arr_t1[6834], &mpc123_arr_t1[6856]);
mpc123_mtv_sid53_sid17_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6840], &mpc123_arr_t1[6856]);
/* rf0u */
mpc123_mtv_sid26_sid2_6_1(&mpc123_arr_t1[2527], &mpc123_arr_t1[6823], &mpc123_arr_t1[6862]);
mpc123_mv_sid29_sid5_1_1(&mpc123_arr_t1[2533], &mpc123_arr_t1[6829], &mpc123_arr_t1[6862]);
mpc123_mtv_sid56_sid17_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6840], &mpc123_arr_t1[6862]);
/* rf0s */
mpc123_mv_sid32_sid20_4_4(&mpc123_arr_t1[2534], &mpc123_arr_t1[6830], &mpc123_arr_t1[6863]);
mpc123_vsub_4(&mpc123_arr_t1[6863], &mpc123_arr_t1[6840], &mpc123_arr_t1[6863]);
mpc123_vsub_4(&mpc123_arr_t1[6863], &mpc123_arr_t1[6844], &mpc123_arr_t1[6863]);
/* rf */
mpc123_mv_sid44_sid2_6_6(&mpc123_arr_t1[2379], &mpc123_arr_t1[6456], &mpc123_arr_t1[6867]);
mpc123_mv_sid47_sid5_6_1(&mpc123_arr_t1[2415], &mpc123_arr_t1[6462], &mpc123_arr_t1[6867]);
mpc123_vsub_6(&mpc123_arr_t1[6867], &mpc123_arr_t1[6823], &mpc123_arr_t1[6867]);
/* rc */
mpc123_mv_sid53_sid2_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6823], &mpc123_arr_t1[6873]);
mpc123_mv_sid56_sid5_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6829], &mpc123_arr_t1[6873]);
mpc123_vadd_4(&mpc123_arr_t1[6873], &mpc123_arr_t1[6848], &mpc123_arr_t1[6873]);
mpc123_vsub_4(&mpc123_arr_t1[6873], &mpc123_arr_t1[6830], &mpc123_arr_t1[6873]);
/* rs */
mpc123_vadd_4(&mpc123_arr_t1[6877], &mpc123_arr_t1[6852], &mpc123_arr_t1[6877]);
mpc123_vsub_4(&mpc123_arr_t1[6877], &mpc123_arr_t1[6830], &mpc123_arr_t1[6877]);
/* rk */
mpc123_vv_elemult_8(&mpc123_arr_t1[6840], &mpc123_arr_t1[6815], mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[6881], mpc123_tmp1_8, &mpc123_arr_t1[6881]);
mpc123_vv_elemult_8(&mpc123_arr_t1[6848], &mpc123_arr_t1[6807], mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[6881], mpc123_tmp1_8, &mpc123_arr_t1[6881]);
}


static void mpc123_glqdocpip_dereduce()
{
  int i1;
mpc123_error_source = 4;
/* Zeitschritt 0 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_m_copy_4_1(&mpc123_arr_t1[2747], mpc123_tmp3_4_1);
mpc123_mv_sid51_sid2_4_6(&mpc123_arr_t1[119], &mpc123_arr_t1[2674], mpc123_tmp3_4_1);
mpc123_mv_sid54_sid5_4_1(&mpc123_arr_t1[143], &mpc123_arr_t1[2680], mpc123_tmp3_4_1);
mpc123_vv_elemult_4(&mpc123_arr_t1[2751], mpc123_tmp3_4_1, &mpc123_arr_t1[2691]);
/* dy_ss */
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_v_init0_4(mpc123_tmp1_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[44], mpc123_tmp3_4_1, mpc123_tmp1_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[2736], &mpc123_arr_t1[2662], mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_4(&mpc123_arr_t1[2728], mpc123_tmp3_4_1, mpc123_tmp3_4_1);
mpc123_vv_elemult_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp3_4_1);
mpc123_vadd_4(mpc123_tmp3_4_1, &mpc123_arr_t1[2714], mpc123_tmp3_4_1);
mpc123_vsub_4(mpc123_tmp3_4_1, &mpc123_arr_t1[2691], mpc123_tmp3_4_1);
mpc123_v_init0_4(mpc123_tmp2_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[2670], &mpc123_arr_t1[2662], mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_4(mpc123_tmp1_4_1, mpc123_tmp2_4_1, mpc123_tmp1_4_1);
mpc123_v_init1_4(mpc123_tmp2_4_1);
mpc123_vadd_4(mpc123_tmp1_4_1, mpc123_tmp2_4_1, mpc123_tmp1_4_1);
mpc123_vv_elediv_4(mpc123_tmp3_4_1, mpc123_tmp1_4_1, &mpc123_arr_t1[2695]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_8(&mpc123_arr_t1[2666], &mpc123_arr_t1[2691], &mpc123_arr_t1[2699]);
mpc123_vadd_8(&mpc123_arr_t1[2699], &mpc123_arr_t1[2732], &mpc123_arr_t1[2699]);
mpc123_vv_elediv_8(&mpc123_arr_t1[2699], &mpc123_arr_t1[2658], &mpc123_arr_t1[2699]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_8(&mpc123_arr_t1[2699], &mpc123_arr_t1[2699]);
/* ds */
mpc123_v_init0_4(&mpc123_arr_t1[2681]);
mpc123_vadd_4(&mpc123_arr_t1[2728], &mpc123_arr_t1[2703], &mpc123_arr_t1[2681]);
/* Zeitschritt 1 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[3086], mpc123_tmp2_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[321], &mpc123_arr_t1[2973], mpc123_tmp2_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[369], &mpc123_arr_t1[2979], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3094], mpc123_tmp2_8_1, &mpc123_arr_t1[2994]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[194], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3071], &mpc123_arr_t1[2949], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3055], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp2_8_1, &mpc123_arr_t1[3033], mpc123_tmp2_8_1);
mpc123_vsub_8(mpc123_tmp2_8_1, &mpc123_arr_t1[2994], mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[2965], &mpc123_arr_t1[2949], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[3002]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[2957], &mpc123_arr_t1[2994], &mpc123_arr_t1[3010]);
mpc123_vadd_16(&mpc123_arr_t1[3010], &mpc123_arr_t1[3063], &mpc123_arr_t1[3010]);
mpc123_vv_elediv_16(&mpc123_arr_t1[3010], &mpc123_arr_t1[2941], &mpc123_arr_t1[3010]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[3010], &mpc123_arr_t1[3010]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[2980]);
mpc123_vadd_8(&mpc123_arr_t1[3055], &mpc123_arr_t1[3018], &mpc123_arr_t1[2980]);
/* Zeitschritt 2 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[3473], mpc123_tmp1_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[555], &mpc123_arr_t1[3360], mpc123_tmp1_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[603], &mpc123_arr_t1[3366], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3481], mpc123_tmp1_8_1, &mpc123_arr_t1[3381]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[428], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3458], &mpc123_arr_t1[3336], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3442], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp1_8_1, &mpc123_arr_t1[3420], mpc123_tmp1_8_1);
mpc123_vsub_8(mpc123_tmp1_8_1, &mpc123_arr_t1[3381], mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3352], &mpc123_arr_t1[3336], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[3389]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[3344], &mpc123_arr_t1[3381], &mpc123_arr_t1[3397]);
mpc123_vadd_16(&mpc123_arr_t1[3397], &mpc123_arr_t1[3450], &mpc123_arr_t1[3397]);
mpc123_vv_elediv_16(&mpc123_arr_t1[3397], &mpc123_arr_t1[3328], &mpc123_arr_t1[3397]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[3397], &mpc123_arr_t1[3397]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[3367]);
mpc123_vadd_8(&mpc123_arr_t1[3442], &mpc123_arr_t1[3405], &mpc123_arr_t1[3367]);
/* Zeitschritt 3 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[3860], mpc123_tmp2_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[789], &mpc123_arr_t1[3747], mpc123_tmp2_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[837], &mpc123_arr_t1[3753], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[3868], mpc123_tmp2_8_1, &mpc123_arr_t1[3768]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[662], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3845], &mpc123_arr_t1[3723], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[3829], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp2_8_1, &mpc123_arr_t1[3807], mpc123_tmp2_8_1);
mpc123_vsub_8(mpc123_tmp2_8_1, &mpc123_arr_t1[3768], mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[3739], &mpc123_arr_t1[3723], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[3776]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[3731], &mpc123_arr_t1[3768], &mpc123_arr_t1[3784]);
mpc123_vadd_16(&mpc123_arr_t1[3784], &mpc123_arr_t1[3837], &mpc123_arr_t1[3784]);
mpc123_vv_elediv_16(&mpc123_arr_t1[3784], &mpc123_arr_t1[3715], &mpc123_arr_t1[3784]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[3784], &mpc123_arr_t1[3784]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[3754]);
mpc123_vadd_8(&mpc123_arr_t1[3829], &mpc123_arr_t1[3792], &mpc123_arr_t1[3754]);
/* Zeitschritt 4 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[4247], mpc123_tmp1_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1023], &mpc123_arr_t1[4134], mpc123_tmp1_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1071], &mpc123_arr_t1[4140], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[4255], mpc123_tmp1_8_1, &mpc123_arr_t1[4155]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[896], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4232], &mpc123_arr_t1[4110], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[4216], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp1_8_1, &mpc123_arr_t1[4194], mpc123_tmp1_8_1);
mpc123_vsub_8(mpc123_tmp1_8_1, &mpc123_arr_t1[4155], mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4126], &mpc123_arr_t1[4110], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[4163]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[4118], &mpc123_arr_t1[4155], &mpc123_arr_t1[4171]);
mpc123_vadd_16(&mpc123_arr_t1[4171], &mpc123_arr_t1[4224], &mpc123_arr_t1[4171]);
mpc123_vv_elediv_16(&mpc123_arr_t1[4171], &mpc123_arr_t1[4102], &mpc123_arr_t1[4171]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[4171], &mpc123_arr_t1[4171]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[4141]);
mpc123_vadd_8(&mpc123_arr_t1[4216], &mpc123_arr_t1[4179], &mpc123_arr_t1[4141]);
/* Zeitschritt 5 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[4634], mpc123_tmp2_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1257], &mpc123_arr_t1[4521], mpc123_tmp2_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1305], &mpc123_arr_t1[4527], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[4642], mpc123_tmp2_8_1, &mpc123_arr_t1[4542]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1130], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4619], &mpc123_arr_t1[4497], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[4603], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp2_8_1, &mpc123_arr_t1[4581], mpc123_tmp2_8_1);
mpc123_vsub_8(mpc123_tmp2_8_1, &mpc123_arr_t1[4542], mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4513], &mpc123_arr_t1[4497], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[4550]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[4505], &mpc123_arr_t1[4542], &mpc123_arr_t1[4558]);
mpc123_vadd_16(&mpc123_arr_t1[4558], &mpc123_arr_t1[4611], &mpc123_arr_t1[4558]);
mpc123_vv_elediv_16(&mpc123_arr_t1[4558], &mpc123_arr_t1[4489], &mpc123_arr_t1[4558]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[4558], &mpc123_arr_t1[4558]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[4528]);
mpc123_vadd_8(&mpc123_arr_t1[4603], &mpc123_arr_t1[4566], &mpc123_arr_t1[4528]);
/* Zeitschritt 6 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[5021], mpc123_tmp1_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1491], &mpc123_arr_t1[4908], mpc123_tmp1_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1539], &mpc123_arr_t1[4914], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5029], mpc123_tmp1_8_1, &mpc123_arr_t1[4929]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1364], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5006], &mpc123_arr_t1[4884], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[4990], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp1_8_1, &mpc123_arr_t1[4968], mpc123_tmp1_8_1);
mpc123_vsub_8(mpc123_tmp1_8_1, &mpc123_arr_t1[4929], mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[4900], &mpc123_arr_t1[4884], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[4937]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[4892], &mpc123_arr_t1[4929], &mpc123_arr_t1[4945]);
mpc123_vadd_16(&mpc123_arr_t1[4945], &mpc123_arr_t1[4998], &mpc123_arr_t1[4945]);
mpc123_vv_elediv_16(&mpc123_arr_t1[4945], &mpc123_arr_t1[4876], &mpc123_arr_t1[4945]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[4945], &mpc123_arr_t1[4945]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[4915]);
mpc123_vadd_8(&mpc123_arr_t1[4990], &mpc123_arr_t1[4953], &mpc123_arr_t1[4915]);
/* Zeitschritt 7 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[5408], mpc123_tmp2_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1725], &mpc123_arr_t1[5295], mpc123_tmp2_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[1773], &mpc123_arr_t1[5301], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5416], mpc123_tmp2_8_1, &mpc123_arr_t1[5316]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1598], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5393], &mpc123_arr_t1[5271], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[5377], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp2_8_1, &mpc123_arr_t1[5355], mpc123_tmp2_8_1);
mpc123_vsub_8(mpc123_tmp2_8_1, &mpc123_arr_t1[5316], mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5287], &mpc123_arr_t1[5271], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[5324]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[5279], &mpc123_arr_t1[5316], &mpc123_arr_t1[5332]);
mpc123_vadd_16(&mpc123_arr_t1[5332], &mpc123_arr_t1[5385], &mpc123_arr_t1[5332]);
mpc123_vv_elediv_16(&mpc123_arr_t1[5332], &mpc123_arr_t1[5263], &mpc123_arr_t1[5332]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[5332], &mpc123_arr_t1[5332]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[5302]);
mpc123_vadd_8(&mpc123_arr_t1[5377], &mpc123_arr_t1[5340], &mpc123_arr_t1[5302]);
/* Zeitschritt 8 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[5795], mpc123_tmp1_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[1959], &mpc123_arr_t1[5682], mpc123_tmp1_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2007], &mpc123_arr_t1[5688], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[5803], mpc123_tmp1_8_1, &mpc123_arr_t1[5703]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[1832], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5780], &mpc123_arr_t1[5658], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[5764], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp1_8_1, &mpc123_arr_t1[5742], mpc123_tmp1_8_1);
mpc123_vsub_8(mpc123_tmp1_8_1, &mpc123_arr_t1[5703], mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[5674], &mpc123_arr_t1[5658], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[5711]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[5666], &mpc123_arr_t1[5703], &mpc123_arr_t1[5719]);
mpc123_vadd_16(&mpc123_arr_t1[5719], &mpc123_arr_t1[5772], &mpc123_arr_t1[5719]);
mpc123_vv_elediv_16(&mpc123_arr_t1[5719], &mpc123_arr_t1[5650], &mpc123_arr_t1[5719]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[5719], &mpc123_arr_t1[5719]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[5689]);
mpc123_vadd_8(&mpc123_arr_t1[5764], &mpc123_arr_t1[5727], &mpc123_arr_t1[5689]);
/* Zeitschritt 9 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[6182], mpc123_tmp2_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2193], &mpc123_arr_t1[6069], mpc123_tmp2_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2241], &mpc123_arr_t1[6075], mpc123_tmp2_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[6190], mpc123_tmp2_8_1, &mpc123_arr_t1[6090]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2066], mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6167], &mpc123_arr_t1[6045], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[6151], mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp2_8_1, &mpc123_arr_t1[6129], mpc123_tmp2_8_1);
mpc123_vsub_8(mpc123_tmp2_8_1, &mpc123_arr_t1[6090], mpc123_tmp2_8_1);
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6061], &mpc123_arr_t1[6045], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp2_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[6098]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[6053], &mpc123_arr_t1[6090], &mpc123_arr_t1[6106]);
mpc123_vadd_16(&mpc123_arr_t1[6106], &mpc123_arr_t1[6159], &mpc123_arr_t1[6106]);
mpc123_vv_elediv_16(&mpc123_arr_t1[6106], &mpc123_arr_t1[6037], &mpc123_arr_t1[6106]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[6106], &mpc123_arr_t1[6106]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[6076]);
mpc123_vadd_8(&mpc123_arr_t1[6151], &mpc123_arr_t1[6114], &mpc123_arr_t1[6076]);
/* Zeitschritt 10 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_8(mpc123_tmp1_8_1);
mpc123_m_copy_8_1(&mpc123_arr_t1[6569], mpc123_tmp1_8_1);
mpc123_mv_sid52_sid2_8_6(&mpc123_arr_t1[2427], &mpc123_arr_t1[6456], mpc123_tmp1_8_1);
mpc123_mv_sid55_sid5_8_1(&mpc123_arr_t1[2475], &mpc123_arr_t1[6462], mpc123_tmp1_8_1);
mpc123_vv_elemult_8(&mpc123_arr_t1[6577], mpc123_tmp1_8_1, &mpc123_arr_t1[6477]);
/* dy_ss */
mpc123_v_init1_8(mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp3_8_1);
mpc123_mv_8_8(&mpc123_arr_t1[2300], mpc123_tmp1_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6554], &mpc123_arr_t1[6432], mpc123_tmp1_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_8(&mpc123_arr_t1[6538], mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp1_8_1, mpc123_tmp1_8_1);
mpc123_vadd_8(mpc123_tmp1_8_1, &mpc123_arr_t1[6516], mpc123_tmp1_8_1);
mpc123_vsub_8(mpc123_tmp1_8_1, &mpc123_arr_t1[6477], mpc123_tmp1_8_1);
mpc123_v_init0_8(mpc123_tmp2_8_1);
mpc123_vv_elediv_8(&mpc123_arr_t1[6448], &mpc123_arr_t1[6432], mpc123_tmp2_8_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_v_init1_8(mpc123_tmp2_8_1);
mpc123_vadd_8(mpc123_tmp3_8_1, mpc123_tmp2_8_1, mpc123_tmp3_8_1);
mpc123_vv_elediv_8(mpc123_tmp1_8_1, mpc123_tmp3_8_1, &mpc123_arr_t1[6485]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_16(&mpc123_arr_t1[6440], &mpc123_arr_t1[6477], &mpc123_arr_t1[6493]);
mpc123_vadd_16(&mpc123_arr_t1[6493], &mpc123_arr_t1[6546], &mpc123_arr_t1[6493]);
mpc123_vv_elediv_16(&mpc123_arr_t1[6493], &mpc123_arr_t1[6424], &mpc123_arr_t1[6493]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_16(&mpc123_arr_t1[6493], &mpc123_arr_t1[6493]);
/* ds */
mpc123_v_init0_8(&mpc123_arr_t1[6463]);
mpc123_vadd_8(&mpc123_arr_t1[6538], &mpc123_arr_t1[6501], &mpc123_arr_t1[6463]);
/* Zeitschritt 11 */
/* dy */
/* Hilfsvektor */
mpc123_v_init0_4(mpc123_tmp2_4_1);
mpc123_m_copy_4_1(&mpc123_arr_t1[6896], mpc123_tmp2_4_1);
mpc123_mv_sid53_sid2_4_6(&mpc123_arr_t1[2609], &mpc123_arr_t1[6823], mpc123_tmp2_4_1);
mpc123_mv_sid56_sid5_4_1(&mpc123_arr_t1[2633], &mpc123_arr_t1[6829], mpc123_tmp2_4_1);
mpc123_vv_elemult_4(&mpc123_arr_t1[6900], mpc123_tmp2_4_1, &mpc123_arr_t1[6840]);
/* dy_ss */
mpc123_v_init1_4(mpc123_tmp2_4_1);
mpc123_v_init0_4(mpc123_tmp1_4_1);
mpc123_mv_4_4(&mpc123_arr_t1[2534], mpc123_tmp2_4_1, mpc123_tmp1_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[6885], &mpc123_arr_t1[6811], mpc123_tmp2_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vsub_4(&mpc123_arr_t1[6877], mpc123_tmp2_4_1, mpc123_tmp2_4_1);
mpc123_vv_elemult_4(mpc123_tmp1_4_1, mpc123_tmp2_4_1, mpc123_tmp2_4_1);
mpc123_vadd_4(mpc123_tmp2_4_1, &mpc123_arr_t1[6863], mpc123_tmp2_4_1);
mpc123_vsub_4(mpc123_tmp2_4_1, &mpc123_arr_t1[6840], mpc123_tmp2_4_1);
mpc123_v_init0_4(mpc123_tmp3_4_1);
mpc123_vv_elediv_4(&mpc123_arr_t1[6819], &mpc123_arr_t1[6811], mpc123_tmp3_4_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp1_4_1);
mpc123_v_init1_4(mpc123_tmp3_4_1);
mpc123_vadd_4(mpc123_tmp1_4_1, mpc123_tmp3_4_1, mpc123_tmp1_4_1);
mpc123_vv_elediv_4(mpc123_tmp2_4_1, mpc123_tmp1_4_1, &mpc123_arr_t1[6844]);
if(mpc123_termcode > -1){return;}
/* dnu */
mpc123_vv_elemult_8(&mpc123_arr_t1[6815], &mpc123_arr_t1[6840], &mpc123_arr_t1[6848]);
mpc123_vadd_8(&mpc123_arr_t1[6848], &mpc123_arr_t1[6881], &mpc123_arr_t1[6848]);
mpc123_vv_elediv_8(&mpc123_arr_t1[6848], &mpc123_arr_t1[6807], &mpc123_arr_t1[6848]);
if(mpc123_termcode > -1){return;}
mpc123_v_turnsign_8(&mpc123_arr_t1[6848], &mpc123_arr_t1[6848]);
/* ds */
mpc123_v_init0_4(&mpc123_arr_t1[6830]);
mpc123_vadd_4(&mpc123_arr_t1[6877], &mpc123_arr_t1[6852], &mpc123_arr_t1[6830]);
mpc123_error_source = 0;

}


/* ###################################################### */
/* Diese Funktion berechnet führt die Nachiteration durch */
/* ###################################################### */
static void mpc123_glqdocpip_iter_ref()
{
  int i1;
if(mpc123_iter_ref == 1){
mpc123_stat_num_iter_ref++;
mpc123_stat_iter_ref[mpc123_iter] = 1;
/* Lösung sichern */
mpc123_v_copy_6(&mpc123_arr_t1[2674], &mpc123_arr_t1[2854]);
mpc123_v_copy_1(&mpc123_arr_t1[2680], &mpc123_arr_t1[2860]);
mpc123_v_copy_4(&mpc123_arr_t1[2681], &mpc123_arr_t1[2861]);
mpc123_v_copy_6(&mpc123_arr_t1[2685], &mpc123_arr_t1[2865]);
mpc123_v_copy_8(&mpc123_arr_t1[2691], &mpc123_arr_t1[2871]);
mpc123_v_copy_8(&mpc123_arr_t1[2699], &mpc123_arr_t1[2879]);
mpc123_v_copy_6(&mpc123_arr_t1[2973], &mpc123_arr_t1[3201]);
mpc123_v_copy_1(&mpc123_arr_t1[2979], &mpc123_arr_t1[3207]);
mpc123_v_copy_8(&mpc123_arr_t1[2980], &mpc123_arr_t1[3208]);
mpc123_v_copy_6(&mpc123_arr_t1[2988], &mpc123_arr_t1[3216]);
mpc123_v_copy_16(&mpc123_arr_t1[2994], &mpc123_arr_t1[3222]);
mpc123_v_copy_16(&mpc123_arr_t1[3010], &mpc123_arr_t1[3238]);
mpc123_v_copy_6(&mpc123_arr_t1[3360], &mpc123_arr_t1[3588]);
mpc123_v_copy_1(&mpc123_arr_t1[3366], &mpc123_arr_t1[3594]);
mpc123_v_copy_8(&mpc123_arr_t1[3367], &mpc123_arr_t1[3595]);
mpc123_v_copy_6(&mpc123_arr_t1[3375], &mpc123_arr_t1[3603]);
mpc123_v_copy_16(&mpc123_arr_t1[3381], &mpc123_arr_t1[3609]);
mpc123_v_copy_16(&mpc123_arr_t1[3397], &mpc123_arr_t1[3625]);
mpc123_v_copy_6(&mpc123_arr_t1[3747], &mpc123_arr_t1[3975]);
mpc123_v_copy_1(&mpc123_arr_t1[3753], &mpc123_arr_t1[3981]);
mpc123_v_copy_8(&mpc123_arr_t1[3754], &mpc123_arr_t1[3982]);
mpc123_v_copy_6(&mpc123_arr_t1[3762], &mpc123_arr_t1[3990]);
mpc123_v_copy_16(&mpc123_arr_t1[3768], &mpc123_arr_t1[3996]);
mpc123_v_copy_16(&mpc123_arr_t1[3784], &mpc123_arr_t1[4012]);
mpc123_v_copy_6(&mpc123_arr_t1[4134], &mpc123_arr_t1[4362]);
mpc123_v_copy_1(&mpc123_arr_t1[4140], &mpc123_arr_t1[4368]);
mpc123_v_copy_8(&mpc123_arr_t1[4141], &mpc123_arr_t1[4369]);
mpc123_v_copy_6(&mpc123_arr_t1[4149], &mpc123_arr_t1[4377]);
mpc123_v_copy_16(&mpc123_arr_t1[4155], &mpc123_arr_t1[4383]);
mpc123_v_copy_16(&mpc123_arr_t1[4171], &mpc123_arr_t1[4399]);
mpc123_v_copy_6(&mpc123_arr_t1[4521], &mpc123_arr_t1[4749]);
mpc123_v_copy_1(&mpc123_arr_t1[4527], &mpc123_arr_t1[4755]);
mpc123_v_copy_8(&mpc123_arr_t1[4528], &mpc123_arr_t1[4756]);
mpc123_v_copy_6(&mpc123_arr_t1[4536], &mpc123_arr_t1[4764]);
mpc123_v_copy_16(&mpc123_arr_t1[4542], &mpc123_arr_t1[4770]);
mpc123_v_copy_16(&mpc123_arr_t1[4558], &mpc123_arr_t1[4786]);
mpc123_v_copy_6(&mpc123_arr_t1[4908], &mpc123_arr_t1[5136]);
mpc123_v_copy_1(&mpc123_arr_t1[4914], &mpc123_arr_t1[5142]);
mpc123_v_copy_8(&mpc123_arr_t1[4915], &mpc123_arr_t1[5143]);
mpc123_v_copy_6(&mpc123_arr_t1[4923], &mpc123_arr_t1[5151]);
mpc123_v_copy_16(&mpc123_arr_t1[4929], &mpc123_arr_t1[5157]);
mpc123_v_copy_16(&mpc123_arr_t1[4945], &mpc123_arr_t1[5173]);
mpc123_v_copy_6(&mpc123_arr_t1[5295], &mpc123_arr_t1[5523]);
mpc123_v_copy_1(&mpc123_arr_t1[5301], &mpc123_arr_t1[5529]);
mpc123_v_copy_8(&mpc123_arr_t1[5302], &mpc123_arr_t1[5530]);
mpc123_v_copy_6(&mpc123_arr_t1[5310], &mpc123_arr_t1[5538]);
mpc123_v_copy_16(&mpc123_arr_t1[5316], &mpc123_arr_t1[5544]);
mpc123_v_copy_16(&mpc123_arr_t1[5332], &mpc123_arr_t1[5560]);
mpc123_v_copy_6(&mpc123_arr_t1[5682], &mpc123_arr_t1[5910]);
mpc123_v_copy_1(&mpc123_arr_t1[5688], &mpc123_arr_t1[5916]);
mpc123_v_copy_8(&mpc123_arr_t1[5689], &mpc123_arr_t1[5917]);
mpc123_v_copy_6(&mpc123_arr_t1[5697], &mpc123_arr_t1[5925]);
mpc123_v_copy_16(&mpc123_arr_t1[5703], &mpc123_arr_t1[5931]);
mpc123_v_copy_16(&mpc123_arr_t1[5719], &mpc123_arr_t1[5947]);
mpc123_v_copy_6(&mpc123_arr_t1[6069], &mpc123_arr_t1[6297]);
mpc123_v_copy_1(&mpc123_arr_t1[6075], &mpc123_arr_t1[6303]);
mpc123_v_copy_8(&mpc123_arr_t1[6076], &mpc123_arr_t1[6304]);
mpc123_v_copy_6(&mpc123_arr_t1[6084], &mpc123_arr_t1[6312]);
mpc123_v_copy_16(&mpc123_arr_t1[6090], &mpc123_arr_t1[6318]);
mpc123_v_copy_16(&mpc123_arr_t1[6106], &mpc123_arr_t1[6334]);
mpc123_v_copy_6(&mpc123_arr_t1[6456], &mpc123_arr_t1[6684]);
mpc123_v_copy_1(&mpc123_arr_t1[6462], &mpc123_arr_t1[6690]);
mpc123_v_copy_8(&mpc123_arr_t1[6463], &mpc123_arr_t1[6691]);
mpc123_v_copy_6(&mpc123_arr_t1[6471], &mpc123_arr_t1[6699]);
mpc123_v_copy_16(&mpc123_arr_t1[6477], &mpc123_arr_t1[6705]);
mpc123_v_copy_16(&mpc123_arr_t1[6493], &mpc123_arr_t1[6721]);
mpc123_v_copy_6(&mpc123_arr_t1[6823], &mpc123_arr_t1[7003]);
mpc123_v_copy_1(&mpc123_arr_t1[6829], &mpc123_arr_t1[7009]);
mpc123_v_copy_4(&mpc123_arr_t1[6830], &mpc123_arr_t1[7010]);
mpc123_v_copy_6(&mpc123_arr_t1[6834], &mpc123_arr_t1[7014]);
mpc123_v_copy_8(&mpc123_arr_t1[6840], &mpc123_arr_t1[7020]);
mpc123_v_copy_8(&mpc123_arr_t1[6848], &mpc123_arr_t1[7028]);
/* rhs sichern */
mpc123_v_copy_6(&mpc123_arr_t1[2707], &mpc123_arr_t1[2887]);
mpc123_v_copy_1(&mpc123_arr_t1[2713], &mpc123_arr_t1[2893]);
mpc123_v_copy_4(&mpc123_arr_t1[2714], &mpc123_arr_t1[2894]);
mpc123_v_copy_6(&mpc123_arr_t1[2718], &mpc123_arr_t1[2898]);
mpc123_v_copy_8(&mpc123_arr_t1[2724], &mpc123_arr_t1[2904]);
mpc123_v_copy_4(&mpc123_arr_t1[2728], &mpc123_arr_t1[2908]);
mpc123_v_copy_8(&mpc123_arr_t1[2732], &mpc123_arr_t1[2912]);
mpc123_v_copy_6(&mpc123_arr_t1[3026], &mpc123_arr_t1[3254]);
mpc123_v_copy_1(&mpc123_arr_t1[3032], &mpc123_arr_t1[3260]);
mpc123_v_copy_8(&mpc123_arr_t1[3033], &mpc123_arr_t1[3261]);
mpc123_v_copy_6(&mpc123_arr_t1[3041], &mpc123_arr_t1[3269]);
mpc123_v_copy_16(&mpc123_arr_t1[3047], &mpc123_arr_t1[3275]);
mpc123_v_copy_8(&mpc123_arr_t1[3055], &mpc123_arr_t1[3283]);
mpc123_v_copy_16(&mpc123_arr_t1[3063], &mpc123_arr_t1[3291]);
mpc123_v_copy_6(&mpc123_arr_t1[3413], &mpc123_arr_t1[3641]);
mpc123_v_copy_1(&mpc123_arr_t1[3419], &mpc123_arr_t1[3647]);
mpc123_v_copy_8(&mpc123_arr_t1[3420], &mpc123_arr_t1[3648]);
mpc123_v_copy_6(&mpc123_arr_t1[3428], &mpc123_arr_t1[3656]);
mpc123_v_copy_16(&mpc123_arr_t1[3434], &mpc123_arr_t1[3662]);
mpc123_v_copy_8(&mpc123_arr_t1[3442], &mpc123_arr_t1[3670]);
mpc123_v_copy_16(&mpc123_arr_t1[3450], &mpc123_arr_t1[3678]);
mpc123_v_copy_6(&mpc123_arr_t1[3800], &mpc123_arr_t1[4028]);
mpc123_v_copy_1(&mpc123_arr_t1[3806], &mpc123_arr_t1[4034]);
mpc123_v_copy_8(&mpc123_arr_t1[3807], &mpc123_arr_t1[4035]);
mpc123_v_copy_6(&mpc123_arr_t1[3815], &mpc123_arr_t1[4043]);
mpc123_v_copy_16(&mpc123_arr_t1[3821], &mpc123_arr_t1[4049]);
mpc123_v_copy_8(&mpc123_arr_t1[3829], &mpc123_arr_t1[4057]);
mpc123_v_copy_16(&mpc123_arr_t1[3837], &mpc123_arr_t1[4065]);
mpc123_v_copy_6(&mpc123_arr_t1[4187], &mpc123_arr_t1[4415]);
mpc123_v_copy_1(&mpc123_arr_t1[4193], &mpc123_arr_t1[4421]);
mpc123_v_copy_8(&mpc123_arr_t1[4194], &mpc123_arr_t1[4422]);
mpc123_v_copy_6(&mpc123_arr_t1[4202], &mpc123_arr_t1[4430]);
mpc123_v_copy_16(&mpc123_arr_t1[4208], &mpc123_arr_t1[4436]);
mpc123_v_copy_8(&mpc123_arr_t1[4216], &mpc123_arr_t1[4444]);
mpc123_v_copy_16(&mpc123_arr_t1[4224], &mpc123_arr_t1[4452]);
mpc123_v_copy_6(&mpc123_arr_t1[4574], &mpc123_arr_t1[4802]);
mpc123_v_copy_1(&mpc123_arr_t1[4580], &mpc123_arr_t1[4808]);
mpc123_v_copy_8(&mpc123_arr_t1[4581], &mpc123_arr_t1[4809]);
mpc123_v_copy_6(&mpc123_arr_t1[4589], &mpc123_arr_t1[4817]);
mpc123_v_copy_16(&mpc123_arr_t1[4595], &mpc123_arr_t1[4823]);
mpc123_v_copy_8(&mpc123_arr_t1[4603], &mpc123_arr_t1[4831]);
mpc123_v_copy_16(&mpc123_arr_t1[4611], &mpc123_arr_t1[4839]);
mpc123_v_copy_6(&mpc123_arr_t1[4961], &mpc123_arr_t1[5189]);
mpc123_v_copy_1(&mpc123_arr_t1[4967], &mpc123_arr_t1[5195]);
mpc123_v_copy_8(&mpc123_arr_t1[4968], &mpc123_arr_t1[5196]);
mpc123_v_copy_6(&mpc123_arr_t1[4976], &mpc123_arr_t1[5204]);
mpc123_v_copy_16(&mpc123_arr_t1[4982], &mpc123_arr_t1[5210]);
mpc123_v_copy_8(&mpc123_arr_t1[4990], &mpc123_arr_t1[5218]);
mpc123_v_copy_16(&mpc123_arr_t1[4998], &mpc123_arr_t1[5226]);
mpc123_v_copy_6(&mpc123_arr_t1[5348], &mpc123_arr_t1[5576]);
mpc123_v_copy_1(&mpc123_arr_t1[5354], &mpc123_arr_t1[5582]);
mpc123_v_copy_8(&mpc123_arr_t1[5355], &mpc123_arr_t1[5583]);
mpc123_v_copy_6(&mpc123_arr_t1[5363], &mpc123_arr_t1[5591]);
mpc123_v_copy_16(&mpc123_arr_t1[5369], &mpc123_arr_t1[5597]);
mpc123_v_copy_8(&mpc123_arr_t1[5377], &mpc123_arr_t1[5605]);
mpc123_v_copy_16(&mpc123_arr_t1[5385], &mpc123_arr_t1[5613]);
mpc123_v_copy_6(&mpc123_arr_t1[5735], &mpc123_arr_t1[5963]);
mpc123_v_copy_1(&mpc123_arr_t1[5741], &mpc123_arr_t1[5969]);
mpc123_v_copy_8(&mpc123_arr_t1[5742], &mpc123_arr_t1[5970]);
mpc123_v_copy_6(&mpc123_arr_t1[5750], &mpc123_arr_t1[5978]);
mpc123_v_copy_16(&mpc123_arr_t1[5756], &mpc123_arr_t1[5984]);
mpc123_v_copy_8(&mpc123_arr_t1[5764], &mpc123_arr_t1[5992]);
mpc123_v_copy_16(&mpc123_arr_t1[5772], &mpc123_arr_t1[6000]);
mpc123_v_copy_6(&mpc123_arr_t1[6122], &mpc123_arr_t1[6350]);
mpc123_v_copy_1(&mpc123_arr_t1[6128], &mpc123_arr_t1[6356]);
mpc123_v_copy_8(&mpc123_arr_t1[6129], &mpc123_arr_t1[6357]);
mpc123_v_copy_6(&mpc123_arr_t1[6137], &mpc123_arr_t1[6365]);
mpc123_v_copy_16(&mpc123_arr_t1[6143], &mpc123_arr_t1[6371]);
mpc123_v_copy_8(&mpc123_arr_t1[6151], &mpc123_arr_t1[6379]);
mpc123_v_copy_16(&mpc123_arr_t1[6159], &mpc123_arr_t1[6387]);
mpc123_v_copy_6(&mpc123_arr_t1[6509], &mpc123_arr_t1[6737]);
mpc123_v_copy_1(&mpc123_arr_t1[6515], &mpc123_arr_t1[6743]);
mpc123_v_copy_8(&mpc123_arr_t1[6516], &mpc123_arr_t1[6744]);
mpc123_v_copy_6(&mpc123_arr_t1[6524], &mpc123_arr_t1[6752]);
mpc123_v_copy_16(&mpc123_arr_t1[6530], &mpc123_arr_t1[6758]);
mpc123_v_copy_8(&mpc123_arr_t1[6538], &mpc123_arr_t1[6766]);
mpc123_v_copy_16(&mpc123_arr_t1[6546], &mpc123_arr_t1[6774]);
mpc123_v_copy_6(&mpc123_arr_t1[6856], &mpc123_arr_t1[7036]);
mpc123_v_copy_1(&mpc123_arr_t1[6862], &mpc123_arr_t1[7042]);
mpc123_v_copy_4(&mpc123_arr_t1[6863], &mpc123_arr_t1[7043]);
mpc123_v_copy_6(&mpc123_arr_t1[6867], &mpc123_arr_t1[7047]);
mpc123_v_copy_8(&mpc123_arr_t1[6873], &mpc123_arr_t1[7053]);
mpc123_v_copy_4(&mpc123_arr_t1[6877], &mpc123_arr_t1[7057]);
mpc123_v_copy_8(&mpc123_arr_t1[6881], &mpc123_arr_t1[7061]);
/* Residuum berechnen */
mpc123_glqdocpip_rhs_iter_ref();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_rhs_reduced();
if(mpc123_termcode > -1){return;}
/* GLS mit Residuum als rechte Seite lösen */
mpc123_glqdocpip_solve();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_dereduce();
if(mpc123_termcode > -1){return;}
/* Lösung aktualisieren */
mpc123_vadd_6(&mpc123_arr_t1[2854], &mpc123_arr_t1[2674], &mpc123_arr_t1[2674]);
mpc123_vadd_1(&mpc123_arr_t1[2860], &mpc123_arr_t1[2680], &mpc123_arr_t1[2680]);
mpc123_vadd_4(&mpc123_arr_t1[2861], &mpc123_arr_t1[2681], &mpc123_arr_t1[2681]);
mpc123_vadd_6(&mpc123_arr_t1[2865], &mpc123_arr_t1[2685], &mpc123_arr_t1[2685]);
mpc123_vadd_8(&mpc123_arr_t1[2871], &mpc123_arr_t1[2691], &mpc123_arr_t1[2691]);
mpc123_vadd_8(&mpc123_arr_t1[2879], &mpc123_arr_t1[2699], &mpc123_arr_t1[2699]);
mpc123_vadd_6(&mpc123_arr_t1[3201], &mpc123_arr_t1[2973], &mpc123_arr_t1[2973]);
mpc123_vadd_1(&mpc123_arr_t1[3207], &mpc123_arr_t1[2979], &mpc123_arr_t1[2979]);
mpc123_vadd_8(&mpc123_arr_t1[3208], &mpc123_arr_t1[2980], &mpc123_arr_t1[2980]);
mpc123_vadd_6(&mpc123_arr_t1[3216], &mpc123_arr_t1[2988], &mpc123_arr_t1[2988]);
mpc123_vadd_16(&mpc123_arr_t1[3222], &mpc123_arr_t1[2994], &mpc123_arr_t1[2994]);
mpc123_vadd_16(&mpc123_arr_t1[3238], &mpc123_arr_t1[3010], &mpc123_arr_t1[3010]);
mpc123_vadd_6(&mpc123_arr_t1[3588], &mpc123_arr_t1[3360], &mpc123_arr_t1[3360]);
mpc123_vadd_1(&mpc123_arr_t1[3594], &mpc123_arr_t1[3366], &mpc123_arr_t1[3366]);
mpc123_vadd_8(&mpc123_arr_t1[3595], &mpc123_arr_t1[3367], &mpc123_arr_t1[3367]);
mpc123_vadd_6(&mpc123_arr_t1[3603], &mpc123_arr_t1[3375], &mpc123_arr_t1[3375]);
mpc123_vadd_16(&mpc123_arr_t1[3609], &mpc123_arr_t1[3381], &mpc123_arr_t1[3381]);
mpc123_vadd_16(&mpc123_arr_t1[3625], &mpc123_arr_t1[3397], &mpc123_arr_t1[3397]);
mpc123_vadd_6(&mpc123_arr_t1[3975], &mpc123_arr_t1[3747], &mpc123_arr_t1[3747]);
mpc123_vadd_1(&mpc123_arr_t1[3981], &mpc123_arr_t1[3753], &mpc123_arr_t1[3753]);
mpc123_vadd_8(&mpc123_arr_t1[3982], &mpc123_arr_t1[3754], &mpc123_arr_t1[3754]);
mpc123_vadd_6(&mpc123_arr_t1[3990], &mpc123_arr_t1[3762], &mpc123_arr_t1[3762]);
mpc123_vadd_16(&mpc123_arr_t1[3996], &mpc123_arr_t1[3768], &mpc123_arr_t1[3768]);
mpc123_vadd_16(&mpc123_arr_t1[4012], &mpc123_arr_t1[3784], &mpc123_arr_t1[3784]);
mpc123_vadd_6(&mpc123_arr_t1[4362], &mpc123_arr_t1[4134], &mpc123_arr_t1[4134]);
mpc123_vadd_1(&mpc123_arr_t1[4368], &mpc123_arr_t1[4140], &mpc123_arr_t1[4140]);
mpc123_vadd_8(&mpc123_arr_t1[4369], &mpc123_arr_t1[4141], &mpc123_arr_t1[4141]);
mpc123_vadd_6(&mpc123_arr_t1[4377], &mpc123_arr_t1[4149], &mpc123_arr_t1[4149]);
mpc123_vadd_16(&mpc123_arr_t1[4383], &mpc123_arr_t1[4155], &mpc123_arr_t1[4155]);
mpc123_vadd_16(&mpc123_arr_t1[4399], &mpc123_arr_t1[4171], &mpc123_arr_t1[4171]);
mpc123_vadd_6(&mpc123_arr_t1[4749], &mpc123_arr_t1[4521], &mpc123_arr_t1[4521]);
mpc123_vadd_1(&mpc123_arr_t1[4755], &mpc123_arr_t1[4527], &mpc123_arr_t1[4527]);
mpc123_vadd_8(&mpc123_arr_t1[4756], &mpc123_arr_t1[4528], &mpc123_arr_t1[4528]);
mpc123_vadd_6(&mpc123_arr_t1[4764], &mpc123_arr_t1[4536], &mpc123_arr_t1[4536]);
mpc123_vadd_16(&mpc123_arr_t1[4770], &mpc123_arr_t1[4542], &mpc123_arr_t1[4542]);
mpc123_vadd_16(&mpc123_arr_t1[4786], &mpc123_arr_t1[4558], &mpc123_arr_t1[4558]);
mpc123_vadd_6(&mpc123_arr_t1[5136], &mpc123_arr_t1[4908], &mpc123_arr_t1[4908]);
mpc123_vadd_1(&mpc123_arr_t1[5142], &mpc123_arr_t1[4914], &mpc123_arr_t1[4914]);
mpc123_vadd_8(&mpc123_arr_t1[5143], &mpc123_arr_t1[4915], &mpc123_arr_t1[4915]);
mpc123_vadd_6(&mpc123_arr_t1[5151], &mpc123_arr_t1[4923], &mpc123_arr_t1[4923]);
mpc123_vadd_16(&mpc123_arr_t1[5157], &mpc123_arr_t1[4929], &mpc123_arr_t1[4929]);
mpc123_vadd_16(&mpc123_arr_t1[5173], &mpc123_arr_t1[4945], &mpc123_arr_t1[4945]);
mpc123_vadd_6(&mpc123_arr_t1[5523], &mpc123_arr_t1[5295], &mpc123_arr_t1[5295]);
mpc123_vadd_1(&mpc123_arr_t1[5529], &mpc123_arr_t1[5301], &mpc123_arr_t1[5301]);
mpc123_vadd_8(&mpc123_arr_t1[5530], &mpc123_arr_t1[5302], &mpc123_arr_t1[5302]);
mpc123_vadd_6(&mpc123_arr_t1[5538], &mpc123_arr_t1[5310], &mpc123_arr_t1[5310]);
mpc123_vadd_16(&mpc123_arr_t1[5544], &mpc123_arr_t1[5316], &mpc123_arr_t1[5316]);
mpc123_vadd_16(&mpc123_arr_t1[5560], &mpc123_arr_t1[5332], &mpc123_arr_t1[5332]);
mpc123_vadd_6(&mpc123_arr_t1[5910], &mpc123_arr_t1[5682], &mpc123_arr_t1[5682]);
mpc123_vadd_1(&mpc123_arr_t1[5916], &mpc123_arr_t1[5688], &mpc123_arr_t1[5688]);
mpc123_vadd_8(&mpc123_arr_t1[5917], &mpc123_arr_t1[5689], &mpc123_arr_t1[5689]);
mpc123_vadd_6(&mpc123_arr_t1[5925], &mpc123_arr_t1[5697], &mpc123_arr_t1[5697]);
mpc123_vadd_16(&mpc123_arr_t1[5931], &mpc123_arr_t1[5703], &mpc123_arr_t1[5703]);
mpc123_vadd_16(&mpc123_arr_t1[5947], &mpc123_arr_t1[5719], &mpc123_arr_t1[5719]);
mpc123_vadd_6(&mpc123_arr_t1[6297], &mpc123_arr_t1[6069], &mpc123_arr_t1[6069]);
mpc123_vadd_1(&mpc123_arr_t1[6303], &mpc123_arr_t1[6075], &mpc123_arr_t1[6075]);
mpc123_vadd_8(&mpc123_arr_t1[6304], &mpc123_arr_t1[6076], &mpc123_arr_t1[6076]);
mpc123_vadd_6(&mpc123_arr_t1[6312], &mpc123_arr_t1[6084], &mpc123_arr_t1[6084]);
mpc123_vadd_16(&mpc123_arr_t1[6318], &mpc123_arr_t1[6090], &mpc123_arr_t1[6090]);
mpc123_vadd_16(&mpc123_arr_t1[6334], &mpc123_arr_t1[6106], &mpc123_arr_t1[6106]);
mpc123_vadd_6(&mpc123_arr_t1[6684], &mpc123_arr_t1[6456], &mpc123_arr_t1[6456]);
mpc123_vadd_1(&mpc123_arr_t1[6690], &mpc123_arr_t1[6462], &mpc123_arr_t1[6462]);
mpc123_vadd_8(&mpc123_arr_t1[6691], &mpc123_arr_t1[6463], &mpc123_arr_t1[6463]);
mpc123_vadd_6(&mpc123_arr_t1[6699], &mpc123_arr_t1[6471], &mpc123_arr_t1[6471]);
mpc123_vadd_16(&mpc123_arr_t1[6705], &mpc123_arr_t1[6477], &mpc123_arr_t1[6477]);
mpc123_vadd_16(&mpc123_arr_t1[6721], &mpc123_arr_t1[6493], &mpc123_arr_t1[6493]);
mpc123_vadd_6(&mpc123_arr_t1[7003], &mpc123_arr_t1[6823], &mpc123_arr_t1[6823]);
mpc123_vadd_1(&mpc123_arr_t1[7009], &mpc123_arr_t1[6829], &mpc123_arr_t1[6829]);
mpc123_vadd_4(&mpc123_arr_t1[7010], &mpc123_arr_t1[6830], &mpc123_arr_t1[6830]);
mpc123_vadd_6(&mpc123_arr_t1[7014], &mpc123_arr_t1[6834], &mpc123_arr_t1[6834]);
mpc123_vadd_8(&mpc123_arr_t1[7020], &mpc123_arr_t1[6840], &mpc123_arr_t1[6840]);
mpc123_vadd_8(&mpc123_arr_t1[7028], &mpc123_arr_t1[6848], &mpc123_arr_t1[6848]);
/* rhs wiederherstellen */
mpc123_v_copy_6(&mpc123_arr_t1[2887], &mpc123_arr_t1[2707]);
mpc123_v_copy_1(&mpc123_arr_t1[2893], &mpc123_arr_t1[2713]);
mpc123_v_copy_4(&mpc123_arr_t1[2894], &mpc123_arr_t1[2714]);
mpc123_v_copy_6(&mpc123_arr_t1[2898], &mpc123_arr_t1[2718]);
mpc123_v_copy_8(&mpc123_arr_t1[2904], &mpc123_arr_t1[2724]);
mpc123_v_copy_4(&mpc123_arr_t1[2908], &mpc123_arr_t1[2728]);
mpc123_v_copy_8(&mpc123_arr_t1[2912], &mpc123_arr_t1[2732]);
mpc123_v_copy_6(&mpc123_arr_t1[3254], &mpc123_arr_t1[3026]);
mpc123_v_copy_1(&mpc123_arr_t1[3260], &mpc123_arr_t1[3032]);
mpc123_v_copy_8(&mpc123_arr_t1[3261], &mpc123_arr_t1[3033]);
mpc123_v_copy_6(&mpc123_arr_t1[3269], &mpc123_arr_t1[3041]);
mpc123_v_copy_16(&mpc123_arr_t1[3275], &mpc123_arr_t1[3047]);
mpc123_v_copy_8(&mpc123_arr_t1[3283], &mpc123_arr_t1[3055]);
mpc123_v_copy_16(&mpc123_arr_t1[3291], &mpc123_arr_t1[3063]);
mpc123_v_copy_6(&mpc123_arr_t1[3641], &mpc123_arr_t1[3413]);
mpc123_v_copy_1(&mpc123_arr_t1[3647], &mpc123_arr_t1[3419]);
mpc123_v_copy_8(&mpc123_arr_t1[3648], &mpc123_arr_t1[3420]);
mpc123_v_copy_6(&mpc123_arr_t1[3656], &mpc123_arr_t1[3428]);
mpc123_v_copy_16(&mpc123_arr_t1[3662], &mpc123_arr_t1[3434]);
mpc123_v_copy_8(&mpc123_arr_t1[3670], &mpc123_arr_t1[3442]);
mpc123_v_copy_16(&mpc123_arr_t1[3678], &mpc123_arr_t1[3450]);
mpc123_v_copy_6(&mpc123_arr_t1[4028], &mpc123_arr_t1[3800]);
mpc123_v_copy_1(&mpc123_arr_t1[4034], &mpc123_arr_t1[3806]);
mpc123_v_copy_8(&mpc123_arr_t1[4035], &mpc123_arr_t1[3807]);
mpc123_v_copy_6(&mpc123_arr_t1[4043], &mpc123_arr_t1[3815]);
mpc123_v_copy_16(&mpc123_arr_t1[4049], &mpc123_arr_t1[3821]);
mpc123_v_copy_8(&mpc123_arr_t1[4057], &mpc123_arr_t1[3829]);
mpc123_v_copy_16(&mpc123_arr_t1[4065], &mpc123_arr_t1[3837]);
mpc123_v_copy_6(&mpc123_arr_t1[4415], &mpc123_arr_t1[4187]);
mpc123_v_copy_1(&mpc123_arr_t1[4421], &mpc123_arr_t1[4193]);
mpc123_v_copy_8(&mpc123_arr_t1[4422], &mpc123_arr_t1[4194]);
mpc123_v_copy_6(&mpc123_arr_t1[4430], &mpc123_arr_t1[4202]);
mpc123_v_copy_16(&mpc123_arr_t1[4436], &mpc123_arr_t1[4208]);
mpc123_v_copy_8(&mpc123_arr_t1[4444], &mpc123_arr_t1[4216]);
mpc123_v_copy_16(&mpc123_arr_t1[4452], &mpc123_arr_t1[4224]);
mpc123_v_copy_6(&mpc123_arr_t1[4802], &mpc123_arr_t1[4574]);
mpc123_v_copy_1(&mpc123_arr_t1[4808], &mpc123_arr_t1[4580]);
mpc123_v_copy_8(&mpc123_arr_t1[4809], &mpc123_arr_t1[4581]);
mpc123_v_copy_6(&mpc123_arr_t1[4817], &mpc123_arr_t1[4589]);
mpc123_v_copy_16(&mpc123_arr_t1[4823], &mpc123_arr_t1[4595]);
mpc123_v_copy_8(&mpc123_arr_t1[4831], &mpc123_arr_t1[4603]);
mpc123_v_copy_16(&mpc123_arr_t1[4839], &mpc123_arr_t1[4611]);
mpc123_v_copy_6(&mpc123_arr_t1[5189], &mpc123_arr_t1[4961]);
mpc123_v_copy_1(&mpc123_arr_t1[5195], &mpc123_arr_t1[4967]);
mpc123_v_copy_8(&mpc123_arr_t1[5196], &mpc123_arr_t1[4968]);
mpc123_v_copy_6(&mpc123_arr_t1[5204], &mpc123_arr_t1[4976]);
mpc123_v_copy_16(&mpc123_arr_t1[5210], &mpc123_arr_t1[4982]);
mpc123_v_copy_8(&mpc123_arr_t1[5218], &mpc123_arr_t1[4990]);
mpc123_v_copy_16(&mpc123_arr_t1[5226], &mpc123_arr_t1[4998]);
mpc123_v_copy_6(&mpc123_arr_t1[5576], &mpc123_arr_t1[5348]);
mpc123_v_copy_1(&mpc123_arr_t1[5582], &mpc123_arr_t1[5354]);
mpc123_v_copy_8(&mpc123_arr_t1[5583], &mpc123_arr_t1[5355]);
mpc123_v_copy_6(&mpc123_arr_t1[5591], &mpc123_arr_t1[5363]);
mpc123_v_copy_16(&mpc123_arr_t1[5597], &mpc123_arr_t1[5369]);
mpc123_v_copy_8(&mpc123_arr_t1[5605], &mpc123_arr_t1[5377]);
mpc123_v_copy_16(&mpc123_arr_t1[5613], &mpc123_arr_t1[5385]);
mpc123_v_copy_6(&mpc123_arr_t1[5963], &mpc123_arr_t1[5735]);
mpc123_v_copy_1(&mpc123_arr_t1[5969], &mpc123_arr_t1[5741]);
mpc123_v_copy_8(&mpc123_arr_t1[5970], &mpc123_arr_t1[5742]);
mpc123_v_copy_6(&mpc123_arr_t1[5978], &mpc123_arr_t1[5750]);
mpc123_v_copy_16(&mpc123_arr_t1[5984], &mpc123_arr_t1[5756]);
mpc123_v_copy_8(&mpc123_arr_t1[5992], &mpc123_arr_t1[5764]);
mpc123_v_copy_16(&mpc123_arr_t1[6000], &mpc123_arr_t1[5772]);
mpc123_v_copy_6(&mpc123_arr_t1[6350], &mpc123_arr_t1[6122]);
mpc123_v_copy_1(&mpc123_arr_t1[6356], &mpc123_arr_t1[6128]);
mpc123_v_copy_8(&mpc123_arr_t1[6357], &mpc123_arr_t1[6129]);
mpc123_v_copy_6(&mpc123_arr_t1[6365], &mpc123_arr_t1[6137]);
mpc123_v_copy_16(&mpc123_arr_t1[6371], &mpc123_arr_t1[6143]);
mpc123_v_copy_8(&mpc123_arr_t1[6379], &mpc123_arr_t1[6151]);
mpc123_v_copy_16(&mpc123_arr_t1[6387], &mpc123_arr_t1[6159]);
mpc123_v_copy_6(&mpc123_arr_t1[6737], &mpc123_arr_t1[6509]);
mpc123_v_copy_1(&mpc123_arr_t1[6743], &mpc123_arr_t1[6515]);
mpc123_v_copy_8(&mpc123_arr_t1[6744], &mpc123_arr_t1[6516]);
mpc123_v_copy_6(&mpc123_arr_t1[6752], &mpc123_arr_t1[6524]);
mpc123_v_copy_16(&mpc123_arr_t1[6758], &mpc123_arr_t1[6530]);
mpc123_v_copy_8(&mpc123_arr_t1[6766], &mpc123_arr_t1[6538]);
mpc123_v_copy_16(&mpc123_arr_t1[6774], &mpc123_arr_t1[6546]);
mpc123_v_copy_6(&mpc123_arr_t1[7036], &mpc123_arr_t1[6856]);
mpc123_v_copy_1(&mpc123_arr_t1[7042], &mpc123_arr_t1[6862]);
mpc123_v_copy_4(&mpc123_arr_t1[7043], &mpc123_arr_t1[6863]);
mpc123_v_copy_6(&mpc123_arr_t1[7047], &mpc123_arr_t1[6867]);
mpc123_v_copy_8(&mpc123_arr_t1[7053], &mpc123_arr_t1[6873]);
mpc123_v_copy_4(&mpc123_arr_t1[7057], &mpc123_arr_t1[6877]);
mpc123_v_copy_8(&mpc123_arr_t1[7061], &mpc123_arr_t1[6881]);
}
}


/* ####################################### */
/* Diese Funktion berechnet den Startpunkt */
/*           Startpunktmethode: 5          */
/* ####################################### */
static void mpc123_glqdocpip_starting_point()
{
  int i1;
/* Very Cold Start */
/* Zeitschritt 0 */
mpc123_v_init0_6(&mpc123_arr_t1[2641]);
mpc123_v_init0_1(&mpc123_arr_t1[2647]);
mpc123_v_init0_4(&mpc123_arr_t1[2648]);
mpc123_max(&mpc123_arr_t1[2648], &mpc123_arr_t1[147], &mpc123_arr_t1[2648]);
mpc123_max(&mpc123_arr_t1[2649], &mpc123_arr_t1[148], &mpc123_arr_t1[2649]);
mpc123_max(&mpc123_arr_t1[2650], &mpc123_arr_t1[149], &mpc123_arr_t1[2650]);
mpc123_max(&mpc123_arr_t1[2651], &mpc123_arr_t1[150], &mpc123_arr_t1[2651]);
mpc123_v_init0_6(&mpc123_arr_t1[2652]);
mpc123_v_init1_8(&mpc123_arr_t1[2658]);
mpc123_v_init1_8(&mpc123_arr_t1[2666]);
/* Zeitschritt 1 */
mpc123_v_init0_6(&mpc123_arr_t1[2920]);
mpc123_v_init0_1(&mpc123_arr_t1[2926]);
mpc123_v_init0_8(&mpc123_arr_t1[2927]);
mpc123_max(&mpc123_arr_t1[2927], &mpc123_arr_t1[377], &mpc123_arr_t1[2927]);
mpc123_max(&mpc123_arr_t1[2928], &mpc123_arr_t1[378], &mpc123_arr_t1[2928]);
mpc123_max(&mpc123_arr_t1[2929], &mpc123_arr_t1[379], &mpc123_arr_t1[2929]);
mpc123_max(&mpc123_arr_t1[2930], &mpc123_arr_t1[380], &mpc123_arr_t1[2930]);
mpc123_max(&mpc123_arr_t1[2931], &mpc123_arr_t1[381], &mpc123_arr_t1[2931]);
mpc123_max(&mpc123_arr_t1[2932], &mpc123_arr_t1[382], &mpc123_arr_t1[2932]);
mpc123_max(&mpc123_arr_t1[2933], &mpc123_arr_t1[383], &mpc123_arr_t1[2933]);
mpc123_max(&mpc123_arr_t1[2934], &mpc123_arr_t1[384], &mpc123_arr_t1[2934]);
mpc123_v_init0_6(&mpc123_arr_t1[2935]);
mpc123_v_init1_16(&mpc123_arr_t1[2941]);
mpc123_v_init1_16(&mpc123_arr_t1[2957]);
/* Zeitschritt 2 */
mpc123_v_init0_6(&mpc123_arr_t1[3307]);
mpc123_v_init0_1(&mpc123_arr_t1[3313]);
mpc123_v_init0_8(&mpc123_arr_t1[3314]);
mpc123_max(&mpc123_arr_t1[3314], &mpc123_arr_t1[611], &mpc123_arr_t1[3314]);
mpc123_max(&mpc123_arr_t1[3315], &mpc123_arr_t1[612], &mpc123_arr_t1[3315]);
mpc123_max(&mpc123_arr_t1[3316], &mpc123_arr_t1[613], &mpc123_arr_t1[3316]);
mpc123_max(&mpc123_arr_t1[3317], &mpc123_arr_t1[614], &mpc123_arr_t1[3317]);
mpc123_max(&mpc123_arr_t1[3318], &mpc123_arr_t1[615], &mpc123_arr_t1[3318]);
mpc123_max(&mpc123_arr_t1[3319], &mpc123_arr_t1[616], &mpc123_arr_t1[3319]);
mpc123_max(&mpc123_arr_t1[3320], &mpc123_arr_t1[617], &mpc123_arr_t1[3320]);
mpc123_max(&mpc123_arr_t1[3321], &mpc123_arr_t1[618], &mpc123_arr_t1[3321]);
mpc123_v_init0_6(&mpc123_arr_t1[3322]);
mpc123_v_init1_16(&mpc123_arr_t1[3328]);
mpc123_v_init1_16(&mpc123_arr_t1[3344]);
/* Zeitschritt 3 */
mpc123_v_init0_6(&mpc123_arr_t1[3694]);
mpc123_v_init0_1(&mpc123_arr_t1[3700]);
mpc123_v_init0_8(&mpc123_arr_t1[3701]);
mpc123_max(&mpc123_arr_t1[3701], &mpc123_arr_t1[845], &mpc123_arr_t1[3701]);
mpc123_max(&mpc123_arr_t1[3702], &mpc123_arr_t1[846], &mpc123_arr_t1[3702]);
mpc123_max(&mpc123_arr_t1[3703], &mpc123_arr_t1[847], &mpc123_arr_t1[3703]);
mpc123_max(&mpc123_arr_t1[3704], &mpc123_arr_t1[848], &mpc123_arr_t1[3704]);
mpc123_max(&mpc123_arr_t1[3705], &mpc123_arr_t1[849], &mpc123_arr_t1[3705]);
mpc123_max(&mpc123_arr_t1[3706], &mpc123_arr_t1[850], &mpc123_arr_t1[3706]);
mpc123_max(&mpc123_arr_t1[3707], &mpc123_arr_t1[851], &mpc123_arr_t1[3707]);
mpc123_max(&mpc123_arr_t1[3708], &mpc123_arr_t1[852], &mpc123_arr_t1[3708]);
mpc123_v_init0_6(&mpc123_arr_t1[3709]);
mpc123_v_init1_16(&mpc123_arr_t1[3715]);
mpc123_v_init1_16(&mpc123_arr_t1[3731]);
/* Zeitschritt 4 */
mpc123_v_init0_6(&mpc123_arr_t1[4081]);
mpc123_v_init0_1(&mpc123_arr_t1[4087]);
mpc123_v_init0_8(&mpc123_arr_t1[4088]);
mpc123_max(&mpc123_arr_t1[4088], &mpc123_arr_t1[1079], &mpc123_arr_t1[4088]);
mpc123_max(&mpc123_arr_t1[4089], &mpc123_arr_t1[1080], &mpc123_arr_t1[4089]);
mpc123_max(&mpc123_arr_t1[4090], &mpc123_arr_t1[1081], &mpc123_arr_t1[4090]);
mpc123_max(&mpc123_arr_t1[4091], &mpc123_arr_t1[1082], &mpc123_arr_t1[4091]);
mpc123_max(&mpc123_arr_t1[4092], &mpc123_arr_t1[1083], &mpc123_arr_t1[4092]);
mpc123_max(&mpc123_arr_t1[4093], &mpc123_arr_t1[1084], &mpc123_arr_t1[4093]);
mpc123_max(&mpc123_arr_t1[4094], &mpc123_arr_t1[1085], &mpc123_arr_t1[4094]);
mpc123_max(&mpc123_arr_t1[4095], &mpc123_arr_t1[1086], &mpc123_arr_t1[4095]);
mpc123_v_init0_6(&mpc123_arr_t1[4096]);
mpc123_v_init1_16(&mpc123_arr_t1[4102]);
mpc123_v_init1_16(&mpc123_arr_t1[4118]);
/* Zeitschritt 5 */
mpc123_v_init0_6(&mpc123_arr_t1[4468]);
mpc123_v_init0_1(&mpc123_arr_t1[4474]);
mpc123_v_init0_8(&mpc123_arr_t1[4475]);
mpc123_max(&mpc123_arr_t1[4475], &mpc123_arr_t1[1313], &mpc123_arr_t1[4475]);
mpc123_max(&mpc123_arr_t1[4476], &mpc123_arr_t1[1314], &mpc123_arr_t1[4476]);
mpc123_max(&mpc123_arr_t1[4477], &mpc123_arr_t1[1315], &mpc123_arr_t1[4477]);
mpc123_max(&mpc123_arr_t1[4478], &mpc123_arr_t1[1316], &mpc123_arr_t1[4478]);
mpc123_max(&mpc123_arr_t1[4479], &mpc123_arr_t1[1317], &mpc123_arr_t1[4479]);
mpc123_max(&mpc123_arr_t1[4480], &mpc123_arr_t1[1318], &mpc123_arr_t1[4480]);
mpc123_max(&mpc123_arr_t1[4481], &mpc123_arr_t1[1319], &mpc123_arr_t1[4481]);
mpc123_max(&mpc123_arr_t1[4482], &mpc123_arr_t1[1320], &mpc123_arr_t1[4482]);
mpc123_v_init0_6(&mpc123_arr_t1[4483]);
mpc123_v_init1_16(&mpc123_arr_t1[4489]);
mpc123_v_init1_16(&mpc123_arr_t1[4505]);
/* Zeitschritt 6 */
mpc123_v_init0_6(&mpc123_arr_t1[4855]);
mpc123_v_init0_1(&mpc123_arr_t1[4861]);
mpc123_v_init0_8(&mpc123_arr_t1[4862]);
mpc123_max(&mpc123_arr_t1[4862], &mpc123_arr_t1[1547], &mpc123_arr_t1[4862]);
mpc123_max(&mpc123_arr_t1[4863], &mpc123_arr_t1[1548], &mpc123_arr_t1[4863]);
mpc123_max(&mpc123_arr_t1[4864], &mpc123_arr_t1[1549], &mpc123_arr_t1[4864]);
mpc123_max(&mpc123_arr_t1[4865], &mpc123_arr_t1[1550], &mpc123_arr_t1[4865]);
mpc123_max(&mpc123_arr_t1[4866], &mpc123_arr_t1[1551], &mpc123_arr_t1[4866]);
mpc123_max(&mpc123_arr_t1[4867], &mpc123_arr_t1[1552], &mpc123_arr_t1[4867]);
mpc123_max(&mpc123_arr_t1[4868], &mpc123_arr_t1[1553], &mpc123_arr_t1[4868]);
mpc123_max(&mpc123_arr_t1[4869], &mpc123_arr_t1[1554], &mpc123_arr_t1[4869]);
mpc123_v_init0_6(&mpc123_arr_t1[4870]);
mpc123_v_init1_16(&mpc123_arr_t1[4876]);
mpc123_v_init1_16(&mpc123_arr_t1[4892]);
/* Zeitschritt 7 */
mpc123_v_init0_6(&mpc123_arr_t1[5242]);
mpc123_v_init0_1(&mpc123_arr_t1[5248]);
mpc123_v_init0_8(&mpc123_arr_t1[5249]);
mpc123_max(&mpc123_arr_t1[5249], &mpc123_arr_t1[1781], &mpc123_arr_t1[5249]);
mpc123_max(&mpc123_arr_t1[5250], &mpc123_arr_t1[1782], &mpc123_arr_t1[5250]);
mpc123_max(&mpc123_arr_t1[5251], &mpc123_arr_t1[1783], &mpc123_arr_t1[5251]);
mpc123_max(&mpc123_arr_t1[5252], &mpc123_arr_t1[1784], &mpc123_arr_t1[5252]);
mpc123_max(&mpc123_arr_t1[5253], &mpc123_arr_t1[1785], &mpc123_arr_t1[5253]);
mpc123_max(&mpc123_arr_t1[5254], &mpc123_arr_t1[1786], &mpc123_arr_t1[5254]);
mpc123_max(&mpc123_arr_t1[5255], &mpc123_arr_t1[1787], &mpc123_arr_t1[5255]);
mpc123_max(&mpc123_arr_t1[5256], &mpc123_arr_t1[1788], &mpc123_arr_t1[5256]);
mpc123_v_init0_6(&mpc123_arr_t1[5257]);
mpc123_v_init1_16(&mpc123_arr_t1[5263]);
mpc123_v_init1_16(&mpc123_arr_t1[5279]);
/* Zeitschritt 8 */
mpc123_v_init0_6(&mpc123_arr_t1[5629]);
mpc123_v_init0_1(&mpc123_arr_t1[5635]);
mpc123_v_init0_8(&mpc123_arr_t1[5636]);
mpc123_max(&mpc123_arr_t1[5636], &mpc123_arr_t1[2015], &mpc123_arr_t1[5636]);
mpc123_max(&mpc123_arr_t1[5637], &mpc123_arr_t1[2016], &mpc123_arr_t1[5637]);
mpc123_max(&mpc123_arr_t1[5638], &mpc123_arr_t1[2017], &mpc123_arr_t1[5638]);
mpc123_max(&mpc123_arr_t1[5639], &mpc123_arr_t1[2018], &mpc123_arr_t1[5639]);
mpc123_max(&mpc123_arr_t1[5640], &mpc123_arr_t1[2019], &mpc123_arr_t1[5640]);
mpc123_max(&mpc123_arr_t1[5641], &mpc123_arr_t1[2020], &mpc123_arr_t1[5641]);
mpc123_max(&mpc123_arr_t1[5642], &mpc123_arr_t1[2021], &mpc123_arr_t1[5642]);
mpc123_max(&mpc123_arr_t1[5643], &mpc123_arr_t1[2022], &mpc123_arr_t1[5643]);
mpc123_v_init0_6(&mpc123_arr_t1[5644]);
mpc123_v_init1_16(&mpc123_arr_t1[5650]);
mpc123_v_init1_16(&mpc123_arr_t1[5666]);
/* Zeitschritt 9 */
mpc123_v_init0_6(&mpc123_arr_t1[6016]);
mpc123_v_init0_1(&mpc123_arr_t1[6022]);
mpc123_v_init0_8(&mpc123_arr_t1[6023]);
mpc123_max(&mpc123_arr_t1[6023], &mpc123_arr_t1[2249], &mpc123_arr_t1[6023]);
mpc123_max(&mpc123_arr_t1[6024], &mpc123_arr_t1[2250], &mpc123_arr_t1[6024]);
mpc123_max(&mpc123_arr_t1[6025], &mpc123_arr_t1[2251], &mpc123_arr_t1[6025]);
mpc123_max(&mpc123_arr_t1[6026], &mpc123_arr_t1[2252], &mpc123_arr_t1[6026]);
mpc123_max(&mpc123_arr_t1[6027], &mpc123_arr_t1[2253], &mpc123_arr_t1[6027]);
mpc123_max(&mpc123_arr_t1[6028], &mpc123_arr_t1[2254], &mpc123_arr_t1[6028]);
mpc123_max(&mpc123_arr_t1[6029], &mpc123_arr_t1[2255], &mpc123_arr_t1[6029]);
mpc123_max(&mpc123_arr_t1[6030], &mpc123_arr_t1[2256], &mpc123_arr_t1[6030]);
mpc123_v_init0_6(&mpc123_arr_t1[6031]);
mpc123_v_init1_16(&mpc123_arr_t1[6037]);
mpc123_v_init1_16(&mpc123_arr_t1[6053]);
/* Zeitschritt 10 */
mpc123_v_init0_6(&mpc123_arr_t1[6403]);
mpc123_v_init0_1(&mpc123_arr_t1[6409]);
mpc123_v_init0_8(&mpc123_arr_t1[6410]);
mpc123_max(&mpc123_arr_t1[6410], &mpc123_arr_t1[2483], &mpc123_arr_t1[6410]);
mpc123_max(&mpc123_arr_t1[6411], &mpc123_arr_t1[2484], &mpc123_arr_t1[6411]);
mpc123_max(&mpc123_arr_t1[6412], &mpc123_arr_t1[2485], &mpc123_arr_t1[6412]);
mpc123_max(&mpc123_arr_t1[6413], &mpc123_arr_t1[2486], &mpc123_arr_t1[6413]);
mpc123_max(&mpc123_arr_t1[6414], &mpc123_arr_t1[2487], &mpc123_arr_t1[6414]);
mpc123_max(&mpc123_arr_t1[6415], &mpc123_arr_t1[2488], &mpc123_arr_t1[6415]);
mpc123_max(&mpc123_arr_t1[6416], &mpc123_arr_t1[2489], &mpc123_arr_t1[6416]);
mpc123_max(&mpc123_arr_t1[6417], &mpc123_arr_t1[2490], &mpc123_arr_t1[6417]);
mpc123_v_init0_6(&mpc123_arr_t1[6418]);
mpc123_v_init1_16(&mpc123_arr_t1[6424]);
mpc123_v_init1_16(&mpc123_arr_t1[6440]);
/* Zeitschritt 11 */
mpc123_v_init0_6(&mpc123_arr_t1[6790]);
mpc123_v_init0_1(&mpc123_arr_t1[6796]);
mpc123_v_init0_4(&mpc123_arr_t1[6797]);
mpc123_max(&mpc123_arr_t1[6797], &mpc123_arr_t1[2637], &mpc123_arr_t1[6797]);
mpc123_max(&mpc123_arr_t1[6798], &mpc123_arr_t1[2638], &mpc123_arr_t1[6798]);
mpc123_max(&mpc123_arr_t1[6799], &mpc123_arr_t1[2639], &mpc123_arr_t1[6799]);
mpc123_max(&mpc123_arr_t1[6800], &mpc123_arr_t1[2640], &mpc123_arr_t1[6800]);
mpc123_v_init0_6(&mpc123_arr_t1[6801]);
mpc123_v_init1_8(&mpc123_arr_t1[6807]);
mpc123_v_init1_8(&mpc123_arr_t1[6815]);
/* Methode 5 */
/* Calc one step */
mpc123_glqdocpip_rhs_starting_point_5();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_rhs_reduced();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_factor();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_solve();
if(mpc123_termcode > -1){return;}
mpc123_glqdocpip_dereduce();
if(mpc123_termcode > -1){return;}
mpc123_v_copy_6(&mpc123_arr_t1[2674], &mpc123_arr_t1[2641]);
mpc123_v_copy_1(&mpc123_arr_t1[2680], &mpc123_arr_t1[2647]);
mpc123_v_copy_4(&mpc123_arr_t1[2681], &mpc123_arr_t1[2648]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[147], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2648], mpc123_tmp1_1, &mpc123_arr_t1[2648]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[148], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2649], mpc123_tmp1_1, &mpc123_arr_t1[2649]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[149], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2650], mpc123_tmp1_1, &mpc123_arr_t1[2650]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[150], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2651], mpc123_tmp1_1, &mpc123_arr_t1[2651]);
mpc123_v_copy_6(&mpc123_arr_t1[2685], &mpc123_arr_t1[2652]);
mpc123_vadd_8(&mpc123_arr_t1[2658], &mpc123_arr_t1[2691], &mpc123_arr_t1[2691]);
mpc123_vadd_8(&mpc123_arr_t1[2666], &mpc123_arr_t1[2699], &mpc123_arr_t1[2699]);
mpc123_v_copy_6(&mpc123_arr_t1[2973], &mpc123_arr_t1[2920]);
mpc123_v_copy_1(&mpc123_arr_t1[2979], &mpc123_arr_t1[2926]);
mpc123_v_copy_8(&mpc123_arr_t1[2980], &mpc123_arr_t1[2927]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[377], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2927], mpc123_tmp1_1, &mpc123_arr_t1[2927]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[378], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2928], mpc123_tmp1_1, &mpc123_arr_t1[2928]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[379], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2929], mpc123_tmp1_1, &mpc123_arr_t1[2929]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[380], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2930], mpc123_tmp1_1, &mpc123_arr_t1[2930]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[381], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2931], mpc123_tmp1_1, &mpc123_arr_t1[2931]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[382], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2932], mpc123_tmp1_1, &mpc123_arr_t1[2932]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[383], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2933], mpc123_tmp1_1, &mpc123_arr_t1[2933]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[384], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2934], mpc123_tmp1_1, &mpc123_arr_t1[2934]);
mpc123_v_copy_6(&mpc123_arr_t1[2988], &mpc123_arr_t1[2935]);
mpc123_vadd_16(&mpc123_arr_t1[2941], &mpc123_arr_t1[2994], &mpc123_arr_t1[2994]);
mpc123_vadd_16(&mpc123_arr_t1[2957], &mpc123_arr_t1[3010], &mpc123_arr_t1[3010]);
mpc123_v_copy_6(&mpc123_arr_t1[3360], &mpc123_arr_t1[3307]);
mpc123_v_copy_1(&mpc123_arr_t1[3366], &mpc123_arr_t1[3313]);
mpc123_v_copy_8(&mpc123_arr_t1[3367], &mpc123_arr_t1[3314]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[611], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3314], mpc123_tmp1_1, &mpc123_arr_t1[3314]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[612], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3315], mpc123_tmp1_1, &mpc123_arr_t1[3315]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[613], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3316], mpc123_tmp1_1, &mpc123_arr_t1[3316]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[614], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3317], mpc123_tmp1_1, &mpc123_arr_t1[3317]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[615], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3318], mpc123_tmp1_1, &mpc123_arr_t1[3318]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[616], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3319], mpc123_tmp1_1, &mpc123_arr_t1[3319]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[617], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3320], mpc123_tmp1_1, &mpc123_arr_t1[3320]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[618], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3321], mpc123_tmp1_1, &mpc123_arr_t1[3321]);
mpc123_v_copy_6(&mpc123_arr_t1[3375], &mpc123_arr_t1[3322]);
mpc123_vadd_16(&mpc123_arr_t1[3328], &mpc123_arr_t1[3381], &mpc123_arr_t1[3381]);
mpc123_vadd_16(&mpc123_arr_t1[3344], &mpc123_arr_t1[3397], &mpc123_arr_t1[3397]);
mpc123_v_copy_6(&mpc123_arr_t1[3747], &mpc123_arr_t1[3694]);
mpc123_v_copy_1(&mpc123_arr_t1[3753], &mpc123_arr_t1[3700]);
mpc123_v_copy_8(&mpc123_arr_t1[3754], &mpc123_arr_t1[3701]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[845], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3701], mpc123_tmp1_1, &mpc123_arr_t1[3701]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[846], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3702], mpc123_tmp1_1, &mpc123_arr_t1[3702]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[847], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3703], mpc123_tmp1_1, &mpc123_arr_t1[3703]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[848], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3704], mpc123_tmp1_1, &mpc123_arr_t1[3704]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[849], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3705], mpc123_tmp1_1, &mpc123_arr_t1[3705]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[850], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3706], mpc123_tmp1_1, &mpc123_arr_t1[3706]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[851], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3707], mpc123_tmp1_1, &mpc123_arr_t1[3707]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[852], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[3708], mpc123_tmp1_1, &mpc123_arr_t1[3708]);
mpc123_v_copy_6(&mpc123_arr_t1[3762], &mpc123_arr_t1[3709]);
mpc123_vadd_16(&mpc123_arr_t1[3715], &mpc123_arr_t1[3768], &mpc123_arr_t1[3768]);
mpc123_vadd_16(&mpc123_arr_t1[3731], &mpc123_arr_t1[3784], &mpc123_arr_t1[3784]);
mpc123_v_copy_6(&mpc123_arr_t1[4134], &mpc123_arr_t1[4081]);
mpc123_v_copy_1(&mpc123_arr_t1[4140], &mpc123_arr_t1[4087]);
mpc123_v_copy_8(&mpc123_arr_t1[4141], &mpc123_arr_t1[4088]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1079], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4088], mpc123_tmp1_1, &mpc123_arr_t1[4088]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1080], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4089], mpc123_tmp1_1, &mpc123_arr_t1[4089]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1081], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4090], mpc123_tmp1_1, &mpc123_arr_t1[4090]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1082], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4091], mpc123_tmp1_1, &mpc123_arr_t1[4091]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1083], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4092], mpc123_tmp1_1, &mpc123_arr_t1[4092]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1084], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4093], mpc123_tmp1_1, &mpc123_arr_t1[4093]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1085], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4094], mpc123_tmp1_1, &mpc123_arr_t1[4094]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1086], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4095], mpc123_tmp1_1, &mpc123_arr_t1[4095]);
mpc123_v_copy_6(&mpc123_arr_t1[4149], &mpc123_arr_t1[4096]);
mpc123_vadd_16(&mpc123_arr_t1[4102], &mpc123_arr_t1[4155], &mpc123_arr_t1[4155]);
mpc123_vadd_16(&mpc123_arr_t1[4118], &mpc123_arr_t1[4171], &mpc123_arr_t1[4171]);
mpc123_v_copy_6(&mpc123_arr_t1[4521], &mpc123_arr_t1[4468]);
mpc123_v_copy_1(&mpc123_arr_t1[4527], &mpc123_arr_t1[4474]);
mpc123_v_copy_8(&mpc123_arr_t1[4528], &mpc123_arr_t1[4475]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1313], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4475], mpc123_tmp1_1, &mpc123_arr_t1[4475]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1314], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4476], mpc123_tmp1_1, &mpc123_arr_t1[4476]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1315], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4477], mpc123_tmp1_1, &mpc123_arr_t1[4477]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1316], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4478], mpc123_tmp1_1, &mpc123_arr_t1[4478]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1317], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4479], mpc123_tmp1_1, &mpc123_arr_t1[4479]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1318], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4480], mpc123_tmp1_1, &mpc123_arr_t1[4480]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1319], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4481], mpc123_tmp1_1, &mpc123_arr_t1[4481]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1320], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4482], mpc123_tmp1_1, &mpc123_arr_t1[4482]);
mpc123_v_copy_6(&mpc123_arr_t1[4536], &mpc123_arr_t1[4483]);
mpc123_vadd_16(&mpc123_arr_t1[4489], &mpc123_arr_t1[4542], &mpc123_arr_t1[4542]);
mpc123_vadd_16(&mpc123_arr_t1[4505], &mpc123_arr_t1[4558], &mpc123_arr_t1[4558]);
mpc123_v_copy_6(&mpc123_arr_t1[4908], &mpc123_arr_t1[4855]);
mpc123_v_copy_1(&mpc123_arr_t1[4914], &mpc123_arr_t1[4861]);
mpc123_v_copy_8(&mpc123_arr_t1[4915], &mpc123_arr_t1[4862]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1547], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4862], mpc123_tmp1_1, &mpc123_arr_t1[4862]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1548], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4863], mpc123_tmp1_1, &mpc123_arr_t1[4863]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1549], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4864], mpc123_tmp1_1, &mpc123_arr_t1[4864]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1550], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4865], mpc123_tmp1_1, &mpc123_arr_t1[4865]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1551], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4866], mpc123_tmp1_1, &mpc123_arr_t1[4866]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1552], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4867], mpc123_tmp1_1, &mpc123_arr_t1[4867]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1553], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4868], mpc123_tmp1_1, &mpc123_arr_t1[4868]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1554], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[4869], mpc123_tmp1_1, &mpc123_arr_t1[4869]);
mpc123_v_copy_6(&mpc123_arr_t1[4923], &mpc123_arr_t1[4870]);
mpc123_vadd_16(&mpc123_arr_t1[4876], &mpc123_arr_t1[4929], &mpc123_arr_t1[4929]);
mpc123_vadd_16(&mpc123_arr_t1[4892], &mpc123_arr_t1[4945], &mpc123_arr_t1[4945]);
mpc123_v_copy_6(&mpc123_arr_t1[5295], &mpc123_arr_t1[5242]);
mpc123_v_copy_1(&mpc123_arr_t1[5301], &mpc123_arr_t1[5248]);
mpc123_v_copy_8(&mpc123_arr_t1[5302], &mpc123_arr_t1[5249]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1781], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5249], mpc123_tmp1_1, &mpc123_arr_t1[5249]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1782], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5250], mpc123_tmp1_1, &mpc123_arr_t1[5250]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1783], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5251], mpc123_tmp1_1, &mpc123_arr_t1[5251]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1784], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5252], mpc123_tmp1_1, &mpc123_arr_t1[5252]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1785], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5253], mpc123_tmp1_1, &mpc123_arr_t1[5253]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1786], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5254], mpc123_tmp1_1, &mpc123_arr_t1[5254]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1787], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5255], mpc123_tmp1_1, &mpc123_arr_t1[5255]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[1788], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5256], mpc123_tmp1_1, &mpc123_arr_t1[5256]);
mpc123_v_copy_6(&mpc123_arr_t1[5310], &mpc123_arr_t1[5257]);
mpc123_vadd_16(&mpc123_arr_t1[5263], &mpc123_arr_t1[5316], &mpc123_arr_t1[5316]);
mpc123_vadd_16(&mpc123_arr_t1[5279], &mpc123_arr_t1[5332], &mpc123_arr_t1[5332]);
mpc123_v_copy_6(&mpc123_arr_t1[5682], &mpc123_arr_t1[5629]);
mpc123_v_copy_1(&mpc123_arr_t1[5688], &mpc123_arr_t1[5635]);
mpc123_v_copy_8(&mpc123_arr_t1[5689], &mpc123_arr_t1[5636]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2015], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5636], mpc123_tmp1_1, &mpc123_arr_t1[5636]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2016], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5637], mpc123_tmp1_1, &mpc123_arr_t1[5637]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2017], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5638], mpc123_tmp1_1, &mpc123_arr_t1[5638]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2018], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5639], mpc123_tmp1_1, &mpc123_arr_t1[5639]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2019], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5640], mpc123_tmp1_1, &mpc123_arr_t1[5640]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2020], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5641], mpc123_tmp1_1, &mpc123_arr_t1[5641]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2021], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5642], mpc123_tmp1_1, &mpc123_arr_t1[5642]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2022], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[5643], mpc123_tmp1_1, &mpc123_arr_t1[5643]);
mpc123_v_copy_6(&mpc123_arr_t1[5697], &mpc123_arr_t1[5644]);
mpc123_vadd_16(&mpc123_arr_t1[5650], &mpc123_arr_t1[5703], &mpc123_arr_t1[5703]);
mpc123_vadd_16(&mpc123_arr_t1[5666], &mpc123_arr_t1[5719], &mpc123_arr_t1[5719]);
mpc123_v_copy_6(&mpc123_arr_t1[6069], &mpc123_arr_t1[6016]);
mpc123_v_copy_1(&mpc123_arr_t1[6075], &mpc123_arr_t1[6022]);
mpc123_v_copy_8(&mpc123_arr_t1[6076], &mpc123_arr_t1[6023]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2249], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6023], mpc123_tmp1_1, &mpc123_arr_t1[6023]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2250], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6024], mpc123_tmp1_1, &mpc123_arr_t1[6024]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2251], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6025], mpc123_tmp1_1, &mpc123_arr_t1[6025]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2252], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6026], mpc123_tmp1_1, &mpc123_arr_t1[6026]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2253], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6027], mpc123_tmp1_1, &mpc123_arr_t1[6027]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2254], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6028], mpc123_tmp1_1, &mpc123_arr_t1[6028]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2255], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6029], mpc123_tmp1_1, &mpc123_arr_t1[6029]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2256], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6030], mpc123_tmp1_1, &mpc123_arr_t1[6030]);
mpc123_v_copy_6(&mpc123_arr_t1[6084], &mpc123_arr_t1[6031]);
mpc123_vadd_16(&mpc123_arr_t1[6037], &mpc123_arr_t1[6090], &mpc123_arr_t1[6090]);
mpc123_vadd_16(&mpc123_arr_t1[6053], &mpc123_arr_t1[6106], &mpc123_arr_t1[6106]);
mpc123_v_copy_6(&mpc123_arr_t1[6456], &mpc123_arr_t1[6403]);
mpc123_v_copy_1(&mpc123_arr_t1[6462], &mpc123_arr_t1[6409]);
mpc123_v_copy_8(&mpc123_arr_t1[6463], &mpc123_arr_t1[6410]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2483], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6410], mpc123_tmp1_1, &mpc123_arr_t1[6410]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2484], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6411], mpc123_tmp1_1, &mpc123_arr_t1[6411]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2485], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6412], mpc123_tmp1_1, &mpc123_arr_t1[6412]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2486], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6413], mpc123_tmp1_1, &mpc123_arr_t1[6413]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2487], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6414], mpc123_tmp1_1, &mpc123_arr_t1[6414]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2488], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6415], mpc123_tmp1_1, &mpc123_arr_t1[6415]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2489], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6416], mpc123_tmp1_1, &mpc123_arr_t1[6416]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2490], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6417], mpc123_tmp1_1, &mpc123_arr_t1[6417]);
mpc123_v_copy_6(&mpc123_arr_t1[6471], &mpc123_arr_t1[6418]);
mpc123_vadd_16(&mpc123_arr_t1[6424], &mpc123_arr_t1[6477], &mpc123_arr_t1[6477]);
mpc123_vadd_16(&mpc123_arr_t1[6440], &mpc123_arr_t1[6493], &mpc123_arr_t1[6493]);
mpc123_v_copy_6(&mpc123_arr_t1[6823], &mpc123_arr_t1[6790]);
mpc123_v_copy_1(&mpc123_arr_t1[6829], &mpc123_arr_t1[6796]);
mpc123_v_copy_4(&mpc123_arr_t1[6830], &mpc123_arr_t1[6797]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2637], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6797], mpc123_tmp1_1, &mpc123_arr_t1[6797]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2638], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6798], mpc123_tmp1_1, &mpc123_arr_t1[6798]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2639], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6799], mpc123_tmp1_1, &mpc123_arr_t1[6799]);
mpc123_v_init0_1(mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[2640], mpc123_tmp1_1, mpc123_tmp1_1);
mpc123_max(&mpc123_arr_t1[6800], mpc123_tmp1_1, &mpc123_arr_t1[6800]);
mpc123_v_copy_6(&mpc123_arr_t1[6834], &mpc123_arr_t1[6801]);
mpc123_vadd_8(&mpc123_arr_t1[6807], &mpc123_arr_t1[6840], &mpc123_arr_t1[6840]);
mpc123_vadd_8(&mpc123_arr_t1[6815], &mpc123_arr_t1[6848], &mpc123_arr_t1[6848]);
/* Init delta_y and delta_nu */
mpc123_v_init0_1(mpc123_starting_point_delta_y);
mpc123_v_init0_1(mpc123_starting_point_delta_nu);
mpc123_tmp1_1[0] = -1.5;
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_8(&mpc123_arr_t1[2691], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_8(&mpc123_arr_t1[2699], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[2994], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[3010], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[3381], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[3397], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[3768], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[3784], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4155], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4171], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4542], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4558], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4929], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[4945], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[5316], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[5332], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[5703], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[5719], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[6090], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[6106], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[6477], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_16(&mpc123_arr_t1[6493], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_8(&mpc123_arr_t1[6840], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_y, mpc123_starting_point_delta_y);
mpc123_tmp2_1[0] = FLT_MAX;
mpc123_v_min_8(&mpc123_arr_t1[6848], mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vv_elemult_1(mpc123_tmp2_1, mpc123_tmp1_1, mpc123_tmp2_1);
mpc123_max(mpc123_tmp2_1, mpc123_starting_point_delta_nu, mpc123_starting_point_delta_nu);
mpc123_v_init0_1(mpc123_starting_point_sum);
mpc123_v_init0_1(mpc123_starting_point_sum_y);
mpc123_v_init0_1(mpc123_starting_point_sum_nu);
mpc123_v_init1_8(mpc123_tmp1_8);
mpc123_v_copy_8(&mpc123_arr_t1[2691], mpc123_tmp2_8);
mpc123_sv_8(mpc123_starting_point_delta_y, mpc123_tmp1_8, mpc123_tmp2_8);
mpc123_v_init1_8(mpc123_tmp3_8);
mpc123_v_copy_8(&mpc123_arr_t1[2699], mpc123_tmp4_8);
mpc123_sv_8(mpc123_starting_point_delta_nu, mpc123_tmp3_8, mpc123_tmp4_8);
mpc123_vtv_8(mpc123_tmp2_8, mpc123_tmp4_8, mpc123_starting_point_sum);
mpc123_vsum_8(mpc123_tmp2_8, mpc123_starting_point_sum_y);
mpc123_vsum_8(mpc123_tmp4_8, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_copy_16(&mpc123_arr_t1[2994], mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_v_init1_16(mpc123_tmp3_16);
mpc123_v_copy_16(&mpc123_arr_t1[3010], mpc123_tmp4_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp3_16, mpc123_tmp4_16);
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp4_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp2_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp4_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp4_16);
mpc123_v_copy_16(&mpc123_arr_t1[3381], mpc123_tmp3_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp4_16, mpc123_tmp3_16);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_copy_16(&mpc123_arr_t1[3397], mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vtv_16(mpc123_tmp3_16, mpc123_tmp1_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp3_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp1_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_copy_16(&mpc123_arr_t1[3768], mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_v_init1_16(mpc123_tmp3_16);
mpc123_v_copy_16(&mpc123_arr_t1[3784], mpc123_tmp4_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp3_16, mpc123_tmp4_16);
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp4_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp2_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp4_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp4_16);
mpc123_v_copy_16(&mpc123_arr_t1[4155], mpc123_tmp3_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp4_16, mpc123_tmp3_16);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_copy_16(&mpc123_arr_t1[4171], mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vtv_16(mpc123_tmp3_16, mpc123_tmp1_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp3_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp1_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_copy_16(&mpc123_arr_t1[4542], mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_v_init1_16(mpc123_tmp3_16);
mpc123_v_copy_16(&mpc123_arr_t1[4558], mpc123_tmp4_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp3_16, mpc123_tmp4_16);
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp4_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp2_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp4_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp4_16);
mpc123_v_copy_16(&mpc123_arr_t1[4929], mpc123_tmp3_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp4_16, mpc123_tmp3_16);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_copy_16(&mpc123_arr_t1[4945], mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vtv_16(mpc123_tmp3_16, mpc123_tmp1_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp3_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp1_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_copy_16(&mpc123_arr_t1[5316], mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_v_init1_16(mpc123_tmp3_16);
mpc123_v_copy_16(&mpc123_arr_t1[5332], mpc123_tmp4_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp3_16, mpc123_tmp4_16);
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp4_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp2_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp4_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp4_16);
mpc123_v_copy_16(&mpc123_arr_t1[5703], mpc123_tmp3_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp4_16, mpc123_tmp3_16);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_copy_16(&mpc123_arr_t1[5719], mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vtv_16(mpc123_tmp3_16, mpc123_tmp1_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp3_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp1_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_copy_16(&mpc123_arr_t1[6090], mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_v_init1_16(mpc123_tmp3_16);
mpc123_v_copy_16(&mpc123_arr_t1[6106], mpc123_tmp4_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp3_16, mpc123_tmp4_16);
mpc123_vtv_16(mpc123_tmp2_16, mpc123_tmp4_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp2_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp4_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_16(mpc123_tmp4_16);
mpc123_v_copy_16(&mpc123_arr_t1[6477], mpc123_tmp3_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp4_16, mpc123_tmp3_16);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_copy_16(&mpc123_arr_t1[6493], mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vtv_16(mpc123_tmp3_16, mpc123_tmp1_16, mpc123_starting_point_sum);
mpc123_vsum_16(mpc123_tmp3_16, mpc123_starting_point_sum_y);
mpc123_vsum_16(mpc123_tmp1_16, mpc123_starting_point_sum_nu);
mpc123_v_init1_8(mpc123_tmp4_8);
mpc123_v_copy_8(&mpc123_arr_t1[6840], mpc123_tmp3_8);
mpc123_sv_8(mpc123_starting_point_delta_y, mpc123_tmp4_8, mpc123_tmp3_8);
mpc123_v_init1_8(mpc123_tmp2_8);
mpc123_v_copy_8(&mpc123_arr_t1[6848], mpc123_tmp1_8);
mpc123_sv_8(mpc123_starting_point_delta_nu, mpc123_tmp2_8, mpc123_tmp1_8);
mpc123_vtv_8(mpc123_tmp3_8, mpc123_tmp1_8, mpc123_starting_point_sum);
mpc123_vsum_8(mpc123_tmp3_8, mpc123_starting_point_sum_y);
mpc123_vsum_8(mpc123_tmp1_8, mpc123_starting_point_sum_nu);
mpc123_tmp1_1[0] = 0.5;
mpc123_vv_elediv_1(mpc123_starting_point_sum, mpc123_starting_point_sum_nu, mpc123_tmp2_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_1(mpc123_tmp1_1, mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vadd_1(mpc123_starting_point_delta_y, mpc123_tmp2_1, mpc123_starting_point_delta_y);
mpc123_vv_elediv_1(mpc123_starting_point_sum, mpc123_starting_point_sum_y, mpc123_tmp2_1);
if(mpc123_termcode > -1){return;}
mpc123_vv_elemult_1(mpc123_tmp1_1, mpc123_tmp2_1, mpc123_tmp2_1);
mpc123_vadd_1(mpc123_starting_point_delta_nu, mpc123_tmp2_1, mpc123_starting_point_delta_nu);
mpc123_v_init1_8(mpc123_tmp1_8);
mpc123_v_init0_8(mpc123_tmp2_8);
mpc123_sv_8(mpc123_starting_point_delta_y, mpc123_tmp1_8, mpc123_tmp2_8);
mpc123_vadd_8(&mpc123_arr_t1[2691], mpc123_tmp2_8, &mpc123_arr_t1[2658]);
mpc123_v_init1_8(mpc123_tmp1_8);
mpc123_v_init0_8(mpc123_tmp2_8);
mpc123_sv_8(mpc123_starting_point_delta_nu, mpc123_tmp1_8, mpc123_tmp2_8);
mpc123_vadd_8(&mpc123_arr_t1[2699], mpc123_tmp2_8, &mpc123_arr_t1[2666]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[2994], mpc123_tmp2_16, &mpc123_arr_t1[2941]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[3010], mpc123_tmp2_16, &mpc123_arr_t1[2957]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3381], mpc123_tmp1_16, &mpc123_arr_t1[3328]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[3397], mpc123_tmp1_16, &mpc123_arr_t1[3344]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[3768], mpc123_tmp2_16, &mpc123_arr_t1[3715]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[3784], mpc123_tmp2_16, &mpc123_arr_t1[3731]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4155], mpc123_tmp1_16, &mpc123_arr_t1[4102]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4171], mpc123_tmp1_16, &mpc123_arr_t1[4118]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[4542], mpc123_tmp2_16, &mpc123_arr_t1[4489]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[4558], mpc123_tmp2_16, &mpc123_arr_t1[4505]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4929], mpc123_tmp1_16, &mpc123_arr_t1[4876]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[4945], mpc123_tmp1_16, &mpc123_arr_t1[4892]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[5316], mpc123_tmp2_16, &mpc123_arr_t1[5263]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[5332], mpc123_tmp2_16, &mpc123_arr_t1[5279]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5703], mpc123_tmp1_16, &mpc123_arr_t1[5650]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[5719], mpc123_tmp1_16, &mpc123_arr_t1[5666]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[6090], mpc123_tmp2_16, &mpc123_arr_t1[6037]);
mpc123_v_init1_16(mpc123_tmp1_16);
mpc123_v_init0_16(mpc123_tmp2_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp1_16, mpc123_tmp2_16);
mpc123_vadd_16(&mpc123_arr_t1[6106], mpc123_tmp2_16, &mpc123_arr_t1[6053]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_y, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6477], mpc123_tmp1_16, &mpc123_arr_t1[6424]);
mpc123_v_init1_16(mpc123_tmp2_16);
mpc123_v_init0_16(mpc123_tmp1_16);
mpc123_sv_16(mpc123_starting_point_delta_nu, mpc123_tmp2_16, mpc123_tmp1_16);
mpc123_vadd_16(&mpc123_arr_t1[6493], mpc123_tmp1_16, &mpc123_arr_t1[6440]);
mpc123_v_init1_8(mpc123_tmp2_8);
mpc123_v_init0_8(mpc123_tmp1_8);
mpc123_sv_8(mpc123_starting_point_delta_y, mpc123_tmp2_8, mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[6840], mpc123_tmp1_8, &mpc123_arr_t1[6807]);
mpc123_v_init1_8(mpc123_tmp2_8);
mpc123_v_init0_8(mpc123_tmp1_8);
mpc123_sv_8(mpc123_starting_point_delta_nu, mpc123_tmp2_8, mpc123_tmp1_8);
mpc123_vadd_8(&mpc123_arr_t1[6848], mpc123_tmp1_8, &mpc123_arr_t1[6815]);
}


void mpc123_glqdocpip_init()
{
/* ## Parameter INIT ##  */
/* Anzahl Ungleichungsbedingungen */
mpc123_m_ineq[0] = 176;
/* Toleranz (Abbruchkriterium) */
mpc123_tol[0] = 0.0001;
/* Mehrotra Gamma */
mpc123_mehrotra_gamma[0] = 0.01;
/* Machine Epsilon */
/* Init Berechnung */
mpc123_v_init0_1(mpc123_tmp3_1);
mpc123_tmp2_1[0] = 1;
mpc123_tmp1_1[0] = 1.0f - mpc123_tmp2_1[0]/2;
/* Berechnungsschleife: while((1-div/2)!=1){div = div/2} */
while(mpc123_tmp1_1[0] != 1.0f){
mpc123_tmp2_1[0] = mpc123_tmp2_1[0]/2;
mpc123_tmp1_1[0] = 1.0f - mpc123_tmp2_1[0]/2;
mpc123_tmp3_1[0] += 1;
if(mpc123_tmp3_1[0] > 100){
mpc123_termcode = 10;
return;
}
}
mpc123_macheps[0] = mpc123_tmp2_1[0];
/* tau */
mpc123_tau[0] = 3;
/* termcode */
mpc123_termcode = -1;
/* Error Line */
mpc123_error_line = 0;
/* Error Source */
mpc123_error_source = 0;
/* termcode 1 factor */
mpc123_tc1_factor[0] = 10000;
/* termcode 2 factor */
mpc123_tc2_factor[0] = 100000000;
/* tmax */
mpc123_time_max = 1;
/* max_iter */
mpc123_max_iter = 20;
/* num_iter_ref */
mpc123_stat_num_iter_ref = 0;
/* num_factor */
mpc123_stat_num_factor = 0;
/* num_solve */
mpc123_stat_num_solve = 0;
}


int mpc123_glqdocpip()
{

/* High Performance Timer (Windows) */
mpc123_glqdocpip_timer_start();

/* Init */
mpc123_glqdocpip_init();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Anfangsnorm bestimmen (norm_d) */
mpc123_glqdocpip_calc_norm_d();

/* starting point */
mpc123_glqdocpip_starting_point();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Main Iteration Loop */
for(mpc123_iter = 0; mpc123_iter < mpc123_max_iter; mpc123_iter++){

/* Predictor rhs berechnen */
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Konvergenz- und Divergenztests, inkl. Berechnung der dafür nötigen Parameter */
mpc123_glqdocpip_calc_norm_r();
mpc123_glqdocpip_calc_mu();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_calc_duality_gap();
mpc123_glqdocpip_calc_phi();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_debug1();
mpc123_glqdocpip_stat();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_check_condiv();
/* Bei entsprechendem Termcode Funktion beenden */
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Predictor GLS faktorisieren */
mpc123_glqdocpip_factor();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Predictor GLS lösen */
mpc123_glqdocpip_solve();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_dereduce();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_iter_ref();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Korrekturfaktor für CorrectorGLS berechnen, */
/* inkl der dafür nötigen Parameter */
mpc123_glqdocpip_max_stepsize();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_calc_mu_aff();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_calc_sigma();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Corrector rhs berechnen */
mpc123_glqdocpip_rhs_corrector();
mpc123_glqdocpip_rhs_reduced();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Corrector GLS lösen */
mpc123_glqdocpip_solve();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_dereduce();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_iter_ref();
if(mpc123_termcode > -1){return mpc123_termcode;}

/* Schritt berechnen und durchführen */
mpc123_glqdocpip_max_stepsize();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_calc_mu_aff();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_mehrotra_step();
if(mpc123_termcode > -1){return mpc123_termcode;}
mpc123_glqdocpip_debug2();
mpc123_glqdocpip_step();

/* Ende - Main Iteration Loop */
}


/* Termcode 3: Max Iterations exceeded */
mpc123_termcode = 3;
return mpc123_termcode;
}


double mpc123_glqdocpip_performance_test_math_mv()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mv_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[113], &mpc123_arr_t1[2641]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_vtm()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_vtm_6_6(&mpc123_arr_t1[113], &mpc123_arr_t1[1], &mpc123_arr_t1[2641]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_mm()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mm_6_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[151], &mpc123_arr_t1[2755]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_mtm()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mtm_6_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[151], &mpc123_arr_t1[2755]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_norm_inf()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_norm_inf_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[2641], &mpc123_arr_t1[2641]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_vv_elediv()
{
int i;
mpc123_glqdocpip_init();
mpc123_v_init1_8(&mpc123_arr_t1[2666]);

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_vv_elediv_8(&mpc123_arr_t1[2658], &mpc123_arr_t1[2666], &mpc123_arr_t1[2941]);
if(mpc123_termcode > -1){return;}
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_math_mm_reorder()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mmr_6_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[151], &mpc123_arr_t1[2755]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_structure_mult_fx0_v()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mv_sid42_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2641], &mpc123_arr_t1[2674]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_structure_mult_fx0T_v()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mtv_sid42_sid2_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[2641], &mpc123_arr_t1[2674]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_structure_mult_vT_fx0()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_vtm_sid2_sid42_6_6(&mpc123_arr_t1[2641], &mpc123_arr_t1[71], &mpc123_arr_t1[2674]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_structure_mult_m_fx0()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mm_sid1_sid42_6_6_6(&mpc123_arr_t1[1], &mpc123_arr_t1[71], &mpc123_arr_t1[2755]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_structure_mult_fx0T_m()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 1000000; i++){
mpc123_mtm_sid42_sid1_6_6_6(&mpc123_arr_t1[71], &mpc123_arr_t1[1], &mpc123_arr_t1[2755]);
}
return mpc123_glqdocpip_timer_get()/1000000*1000;
}


double mpc123_glqdocpip_performance_test_affine()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_affine();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_reduced()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_reduced();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_factor()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_factor();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_solve()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_solve();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_dereduce()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_reduced();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_starting()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_starting_point();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_rhs_iter_ref()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_iter_ref();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_iter_ref()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_iter_ref = 1;

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_iter_ref();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_norm_d()
{
int i;
mpc123_glqdocpip_init();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_norm_d();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_norm_r()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_norm_r();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_mu()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_mu();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_duality_gap()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_duality_gap();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_calc_phi()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_calc_norm_r();
mpc123_glqdocpip_calc_mu();
mpc123_glqdocpip_calc_duality_gap();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_phi();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_check_condiv()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_calc_norm_r();
mpc123_glqdocpip_calc_mu();
mpc123_glqdocpip_calc_duality_gap();
mpc123_glqdocpip_calc_phi();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_check_condiv();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_max_stepsize()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_max_stepsize();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_mu_aff()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_mu_aff();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_sigma()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_calc_mu();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_calc_sigma();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_corrector()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_calc_mu();
mpc123_glqdocpip_calc_sigma();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_corrector();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_mehrotra_step()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_mehrotra_step();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_step()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_mehrotra_step();

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_step();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_startup()
{
int i;

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_init();
mpc123_glqdocpip_starting_point();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_1_iteration()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_calc_norm_d();
mpc123_glqdocpip_starting_point();
mpc123_iter = 1;

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_calc_norm_r();
mpc123_glqdocpip_calc_mu();
mpc123_glqdocpip_calc_duality_gap();
mpc123_glqdocpip_calc_phi();
mpc123_glqdocpip_stat();
mpc123_termcode = -1;
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_calc_sigma();
mpc123_glqdocpip_rhs_corrector();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_mehrotra_step();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}


double mpc123_glqdocpip_performance_test_1_iteration_iterref()
{
int i;
mpc123_glqdocpip_init();
mpc123_glqdocpip_calc_norm_d();
mpc123_glqdocpip_starting_point();
mpc123_iter = 1;

mpc123_glqdocpip_timer_start();
for(i = 0; i < 10000; i++){
mpc123_glqdocpip_rhs_affine();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_calc_norm_r();
mpc123_glqdocpip_calc_mu();
mpc123_glqdocpip_calc_duality_gap();
mpc123_glqdocpip_calc_phi();
mpc123_glqdocpip_stat();
mpc123_termcode = -1;
mpc123_iter_ref = 1;
mpc123_glqdocpip_factor();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_iter_ref();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_calc_sigma();
mpc123_glqdocpip_rhs_corrector();
mpc123_glqdocpip_rhs_reduced();
mpc123_glqdocpip_solve();
mpc123_glqdocpip_dereduce();
mpc123_glqdocpip_iter_ref();
mpc123_glqdocpip_max_stepsize();
mpc123_glqdocpip_calc_mu_aff();
mpc123_glqdocpip_mehrotra_step();
}
return mpc123_glqdocpip_timer_get()/10000*1000;
}
