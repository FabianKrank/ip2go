/* mpc_dw3_glqdocpip.c */
/* Generiert: 07-Jul-2016 13:15:02 */


/* ########### */
/* # INCLUDE # */
/* ########### */
#include "float.h"
#include "math.h"

/* include für Timer (plattformabhängig) */
#if defined(__WIN32__) || defined(WIN32)
/*   Windows */
  #include "windows.h"
#elif defined(_DS1103)
/*   dSpace */
  #include "brtenv.h"
#endif


/* ######################## */
/* # Variablendeklaration # */
/* ######################## */
/* Anfangsbedingung */
static float mpc_dw3_xinit[6];

/* Variablen für Disketisierungsstelle 0 */
/* Optimierungsvariablen */
static float mpc_dw3_x0[6];
static float mpc_dw3_u0[1];
static float mpc_dw3_s0[4];
static float mpc_dw3_p0[6];
static float mpc_dw3_y0[8];
static float mpc_dw3_nu0[8];
/* Schrittvariablen */
static float mpc_dw3_dx0[6];
static float mpc_dw3_du0[1];
static float mpc_dw3_ds0[4];
static float mpc_dw3_dp0[6];
static float mpc_dw3_dy0[8];
static float mpc_dw3_dnu0[8];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx0[36];
static float mpc_dw3_Hxu0[6];
static float mpc_dw3_Huu0[1];
static float mpc_dw3_Hss0[16];
static float mpc_dw3_f0x0[6];
static float mpc_dw3_f0u0[1];
static float mpc_dw3_f0s0[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx0[36];
static float mpc_dw3_fu0[6];
static float mpc_dw3_f0[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx0[24];
static float mpc_dw3_gu0[4];
static float mpc_dw3_g0[4];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x0[6];
static float mpc_dw3_rf0u0[1];
static float mpc_dw3_rf0s0[4];
static float mpc_dw3_rf0[6];
static float mpc_dw3_rc0[4];
static float mpc_dw3_rs0[4];
static float mpc_dw3_rk0[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x0[6];
static float mpc_dw3_rrf0u0[1];
static float mpc_dw3_rhsxs0[4];
static float mpc_dw3_yny0[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx0[36];
static float mpc_dw3_Gxu0[6];
static float mpc_dw3_Guu0[1];
static float mpc_dw3_Rux0[6];
static float mpc_dw3_Vxx0[36];
static float mpc_dw3_Gx0[6];
static float mpc_dw3_Gu0[1];
static float mpc_dw3_Ru0[1];
static float mpc_dw3_Vx0[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir0[6];
static float mpc_dw3_du_ir0[1];
static float mpc_dw3_ds_ir0[4];
static float mpc_dw3_dp_ir0[6];
static float mpc_dw3_dy_ir0[8];
static float mpc_dw3_dnu_ir0[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir0[6];
static float mpc_dw3_rf0u_ir0[1];
static float mpc_dw3_rf0s_ir0[4];
static float mpc_dw3_rf_ir0[6];
static float mpc_dw3_rc_ir0[4];
static float mpc_dw3_rs_ir0[4];
static float mpc_dw3_rk_ir0[8];

/* Variablen für Disketisierungsstelle 1 */
/* Optimierungsvariablen */
static float mpc_dw3_x1[6];
static float mpc_dw3_u1[1];
static float mpc_dw3_s1[8];
static float mpc_dw3_p1[6];
static float mpc_dw3_y1[16];
static float mpc_dw3_nu1[16];
/* Schrittvariablen */
static float mpc_dw3_dx1[6];
static float mpc_dw3_du1[1];
static float mpc_dw3_ds1[8];
static float mpc_dw3_dp1[6];
static float mpc_dw3_dy1[16];
static float mpc_dw3_dnu1[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx1[36];
static float mpc_dw3_Hxu1[6];
static float mpc_dw3_Huu1[1];
static float mpc_dw3_Hss1[64];
static float mpc_dw3_f0x1[6];
static float mpc_dw3_f0u1[1];
static float mpc_dw3_f0s1[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx1[36];
static float mpc_dw3_fu1[6];
static float mpc_dw3_f1[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx1[48];
static float mpc_dw3_gu1[8];
static float mpc_dw3_g1[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x1[6];
static float mpc_dw3_rf0u1[1];
static float mpc_dw3_rf0s1[8];
static float mpc_dw3_rf1[6];
static float mpc_dw3_rc1[8];
static float mpc_dw3_rs1[8];
static float mpc_dw3_rk1[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x1[6];
static float mpc_dw3_rrf0u1[1];
static float mpc_dw3_rhsxs1[8];
static float mpc_dw3_yny1[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx1[36];
static float mpc_dw3_Gxu1[6];
static float mpc_dw3_Guu1[1];
static float mpc_dw3_Rux1[6];
static float mpc_dw3_Vxx1[36];
static float mpc_dw3_Gx1[6];
static float mpc_dw3_Gu1[1];
static float mpc_dw3_Ru1[1];
static float mpc_dw3_Vx1[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir1[6];
static float mpc_dw3_du_ir1[1];
static float mpc_dw3_ds_ir1[8];
static float mpc_dw3_dp_ir1[6];
static float mpc_dw3_dy_ir1[16];
static float mpc_dw3_dnu_ir1[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir1[6];
static float mpc_dw3_rf0u_ir1[1];
static float mpc_dw3_rf0s_ir1[8];
static float mpc_dw3_rf_ir1[6];
static float mpc_dw3_rc_ir1[8];
static float mpc_dw3_rs_ir1[8];
static float mpc_dw3_rk_ir1[16];

/* Variablen für Disketisierungsstelle 2 */
/* Optimierungsvariablen */
static float mpc_dw3_x2[6];
static float mpc_dw3_u2[1];
static float mpc_dw3_s2[8];
static float mpc_dw3_p2[6];
static float mpc_dw3_y2[16];
static float mpc_dw3_nu2[16];
/* Schrittvariablen */
static float mpc_dw3_dx2[6];
static float mpc_dw3_du2[1];
static float mpc_dw3_ds2[8];
static float mpc_dw3_dp2[6];
static float mpc_dw3_dy2[16];
static float mpc_dw3_dnu2[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx2[36];
static float mpc_dw3_Hxu2[6];
static float mpc_dw3_Huu2[1];
static float mpc_dw3_Hss2[64];
static float mpc_dw3_f0x2[6];
static float mpc_dw3_f0u2[1];
static float mpc_dw3_f0s2[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx2[36];
static float mpc_dw3_fu2[6];
static float mpc_dw3_f2[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx2[48];
static float mpc_dw3_gu2[8];
static float mpc_dw3_g2[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x2[6];
static float mpc_dw3_rf0u2[1];
static float mpc_dw3_rf0s2[8];
static float mpc_dw3_rf2[6];
static float mpc_dw3_rc2[8];
static float mpc_dw3_rs2[8];
static float mpc_dw3_rk2[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x2[6];
static float mpc_dw3_rrf0u2[1];
static float mpc_dw3_rhsxs2[8];
static float mpc_dw3_yny2[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx2[36];
static float mpc_dw3_Gxu2[6];
static float mpc_dw3_Guu2[1];
static float mpc_dw3_Rux2[6];
static float mpc_dw3_Vxx2[36];
static float mpc_dw3_Gx2[6];
static float mpc_dw3_Gu2[1];
static float mpc_dw3_Ru2[1];
static float mpc_dw3_Vx2[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir2[6];
static float mpc_dw3_du_ir2[1];
static float mpc_dw3_ds_ir2[8];
static float mpc_dw3_dp_ir2[6];
static float mpc_dw3_dy_ir2[16];
static float mpc_dw3_dnu_ir2[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir2[6];
static float mpc_dw3_rf0u_ir2[1];
static float mpc_dw3_rf0s_ir2[8];
static float mpc_dw3_rf_ir2[6];
static float mpc_dw3_rc_ir2[8];
static float mpc_dw3_rs_ir2[8];
static float mpc_dw3_rk_ir2[16];

/* Variablen für Disketisierungsstelle 3 */
/* Optimierungsvariablen */
static float mpc_dw3_x3[6];
static float mpc_dw3_u3[1];
static float mpc_dw3_s3[8];
static float mpc_dw3_p3[6];
static float mpc_dw3_y3[16];
static float mpc_dw3_nu3[16];
/* Schrittvariablen */
static float mpc_dw3_dx3[6];
static float mpc_dw3_du3[1];
static float mpc_dw3_ds3[8];
static float mpc_dw3_dp3[6];
static float mpc_dw3_dy3[16];
static float mpc_dw3_dnu3[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx3[36];
static float mpc_dw3_Hxu3[6];
static float mpc_dw3_Huu3[1];
static float mpc_dw3_Hss3[64];
static float mpc_dw3_f0x3[6];
static float mpc_dw3_f0u3[1];
static float mpc_dw3_f0s3[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx3[36];
static float mpc_dw3_fu3[6];
static float mpc_dw3_f3[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx3[48];
static float mpc_dw3_gu3[8];
static float mpc_dw3_g3[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x3[6];
static float mpc_dw3_rf0u3[1];
static float mpc_dw3_rf0s3[8];
static float mpc_dw3_rf3[6];
static float mpc_dw3_rc3[8];
static float mpc_dw3_rs3[8];
static float mpc_dw3_rk3[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x3[6];
static float mpc_dw3_rrf0u3[1];
static float mpc_dw3_rhsxs3[8];
static float mpc_dw3_yny3[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx3[36];
static float mpc_dw3_Gxu3[6];
static float mpc_dw3_Guu3[1];
static float mpc_dw3_Rux3[6];
static float mpc_dw3_Vxx3[36];
static float mpc_dw3_Gx3[6];
static float mpc_dw3_Gu3[1];
static float mpc_dw3_Ru3[1];
static float mpc_dw3_Vx3[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir3[6];
static float mpc_dw3_du_ir3[1];
static float mpc_dw3_ds_ir3[8];
static float mpc_dw3_dp_ir3[6];
static float mpc_dw3_dy_ir3[16];
static float mpc_dw3_dnu_ir3[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir3[6];
static float mpc_dw3_rf0u_ir3[1];
static float mpc_dw3_rf0s_ir3[8];
static float mpc_dw3_rf_ir3[6];
static float mpc_dw3_rc_ir3[8];
static float mpc_dw3_rs_ir3[8];
static float mpc_dw3_rk_ir3[16];

/* Variablen für Disketisierungsstelle 4 */
/* Optimierungsvariablen */
static float mpc_dw3_x4[6];
static float mpc_dw3_u4[1];
static float mpc_dw3_s4[8];
static float mpc_dw3_p4[6];
static float mpc_dw3_y4[16];
static float mpc_dw3_nu4[16];
/* Schrittvariablen */
static float mpc_dw3_dx4[6];
static float mpc_dw3_du4[1];
static float mpc_dw3_ds4[8];
static float mpc_dw3_dp4[6];
static float mpc_dw3_dy4[16];
static float mpc_dw3_dnu4[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx4[36];
static float mpc_dw3_Hxu4[6];
static float mpc_dw3_Huu4[1];
static float mpc_dw3_Hss4[64];
static float mpc_dw3_f0x4[6];
static float mpc_dw3_f0u4[1];
static float mpc_dw3_f0s4[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx4[36];
static float mpc_dw3_fu4[6];
static float mpc_dw3_f4[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx4[48];
static float mpc_dw3_gu4[8];
static float mpc_dw3_g4[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x4[6];
static float mpc_dw3_rf0u4[1];
static float mpc_dw3_rf0s4[8];
static float mpc_dw3_rf4[6];
static float mpc_dw3_rc4[8];
static float mpc_dw3_rs4[8];
static float mpc_dw3_rk4[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x4[6];
static float mpc_dw3_rrf0u4[1];
static float mpc_dw3_rhsxs4[8];
static float mpc_dw3_yny4[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx4[36];
static float mpc_dw3_Gxu4[6];
static float mpc_dw3_Guu4[1];
static float mpc_dw3_Rux4[6];
static float mpc_dw3_Vxx4[36];
static float mpc_dw3_Gx4[6];
static float mpc_dw3_Gu4[1];
static float mpc_dw3_Ru4[1];
static float mpc_dw3_Vx4[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir4[6];
static float mpc_dw3_du_ir4[1];
static float mpc_dw3_ds_ir4[8];
static float mpc_dw3_dp_ir4[6];
static float mpc_dw3_dy_ir4[16];
static float mpc_dw3_dnu_ir4[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir4[6];
static float mpc_dw3_rf0u_ir4[1];
static float mpc_dw3_rf0s_ir4[8];
static float mpc_dw3_rf_ir4[6];
static float mpc_dw3_rc_ir4[8];
static float mpc_dw3_rs_ir4[8];
static float mpc_dw3_rk_ir4[16];

/* Variablen für Disketisierungsstelle 5 */
/* Optimierungsvariablen */
static float mpc_dw3_x5[6];
static float mpc_dw3_u5[1];
static float mpc_dw3_s5[8];
static float mpc_dw3_p5[6];
static float mpc_dw3_y5[16];
static float mpc_dw3_nu5[16];
/* Schrittvariablen */
static float mpc_dw3_dx5[6];
static float mpc_dw3_du5[1];
static float mpc_dw3_ds5[8];
static float mpc_dw3_dp5[6];
static float mpc_dw3_dy5[16];
static float mpc_dw3_dnu5[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx5[36];
static float mpc_dw3_Hxu5[6];
static float mpc_dw3_Huu5[1];
static float mpc_dw3_Hss5[64];
static float mpc_dw3_f0x5[6];
static float mpc_dw3_f0u5[1];
static float mpc_dw3_f0s5[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx5[36];
static float mpc_dw3_fu5[6];
static float mpc_dw3_f5[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx5[48];
static float mpc_dw3_gu5[8];
static float mpc_dw3_g5[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x5[6];
static float mpc_dw3_rf0u5[1];
static float mpc_dw3_rf0s5[8];
static float mpc_dw3_rf5[6];
static float mpc_dw3_rc5[8];
static float mpc_dw3_rs5[8];
static float mpc_dw3_rk5[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x5[6];
static float mpc_dw3_rrf0u5[1];
static float mpc_dw3_rhsxs5[8];
static float mpc_dw3_yny5[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx5[36];
static float mpc_dw3_Gxu5[6];
static float mpc_dw3_Guu5[1];
static float mpc_dw3_Rux5[6];
static float mpc_dw3_Vxx5[36];
static float mpc_dw3_Gx5[6];
static float mpc_dw3_Gu5[1];
static float mpc_dw3_Ru5[1];
static float mpc_dw3_Vx5[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir5[6];
static float mpc_dw3_du_ir5[1];
static float mpc_dw3_ds_ir5[8];
static float mpc_dw3_dp_ir5[6];
static float mpc_dw3_dy_ir5[16];
static float mpc_dw3_dnu_ir5[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir5[6];
static float mpc_dw3_rf0u_ir5[1];
static float mpc_dw3_rf0s_ir5[8];
static float mpc_dw3_rf_ir5[6];
static float mpc_dw3_rc_ir5[8];
static float mpc_dw3_rs_ir5[8];
static float mpc_dw3_rk_ir5[16];

/* Variablen für Disketisierungsstelle 6 */
/* Optimierungsvariablen */
static float mpc_dw3_x6[6];
static float mpc_dw3_u6[1];
static float mpc_dw3_s6[8];
static float mpc_dw3_p6[6];
static float mpc_dw3_y6[16];
static float mpc_dw3_nu6[16];
/* Schrittvariablen */
static float mpc_dw3_dx6[6];
static float mpc_dw3_du6[1];
static float mpc_dw3_ds6[8];
static float mpc_dw3_dp6[6];
static float mpc_dw3_dy6[16];
static float mpc_dw3_dnu6[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx6[36];
static float mpc_dw3_Hxu6[6];
static float mpc_dw3_Huu6[1];
static float mpc_dw3_Hss6[64];
static float mpc_dw3_f0x6[6];
static float mpc_dw3_f0u6[1];
static float mpc_dw3_f0s6[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx6[36];
static float mpc_dw3_fu6[6];
static float mpc_dw3_f6[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx6[48];
static float mpc_dw3_gu6[8];
static float mpc_dw3_g6[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x6[6];
static float mpc_dw3_rf0u6[1];
static float mpc_dw3_rf0s6[8];
static float mpc_dw3_rf6[6];
static float mpc_dw3_rc6[8];
static float mpc_dw3_rs6[8];
static float mpc_dw3_rk6[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x6[6];
static float mpc_dw3_rrf0u6[1];
static float mpc_dw3_rhsxs6[8];
static float mpc_dw3_yny6[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx6[36];
static float mpc_dw3_Gxu6[6];
static float mpc_dw3_Guu6[1];
static float mpc_dw3_Rux6[6];
static float mpc_dw3_Vxx6[36];
static float mpc_dw3_Gx6[6];
static float mpc_dw3_Gu6[1];
static float mpc_dw3_Ru6[1];
static float mpc_dw3_Vx6[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir6[6];
static float mpc_dw3_du_ir6[1];
static float mpc_dw3_ds_ir6[8];
static float mpc_dw3_dp_ir6[6];
static float mpc_dw3_dy_ir6[16];
static float mpc_dw3_dnu_ir6[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir6[6];
static float mpc_dw3_rf0u_ir6[1];
static float mpc_dw3_rf0s_ir6[8];
static float mpc_dw3_rf_ir6[6];
static float mpc_dw3_rc_ir6[8];
static float mpc_dw3_rs_ir6[8];
static float mpc_dw3_rk_ir6[16];

/* Variablen für Disketisierungsstelle 7 */
/* Optimierungsvariablen */
static float mpc_dw3_x7[6];
static float mpc_dw3_u7[1];
static float mpc_dw3_s7[8];
static float mpc_dw3_p7[6];
static float mpc_dw3_y7[16];
static float mpc_dw3_nu7[16];
/* Schrittvariablen */
static float mpc_dw3_dx7[6];
static float mpc_dw3_du7[1];
static float mpc_dw3_ds7[8];
static float mpc_dw3_dp7[6];
static float mpc_dw3_dy7[16];
static float mpc_dw3_dnu7[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx7[36];
static float mpc_dw3_Hxu7[6];
static float mpc_dw3_Huu7[1];
static float mpc_dw3_Hss7[64];
static float mpc_dw3_f0x7[6];
static float mpc_dw3_f0u7[1];
static float mpc_dw3_f0s7[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx7[36];
static float mpc_dw3_fu7[6];
static float mpc_dw3_f7[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx7[48];
static float mpc_dw3_gu7[8];
static float mpc_dw3_g7[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x7[6];
static float mpc_dw3_rf0u7[1];
static float mpc_dw3_rf0s7[8];
static float mpc_dw3_rf7[6];
static float mpc_dw3_rc7[8];
static float mpc_dw3_rs7[8];
static float mpc_dw3_rk7[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x7[6];
static float mpc_dw3_rrf0u7[1];
static float mpc_dw3_rhsxs7[8];
static float mpc_dw3_yny7[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx7[36];
static float mpc_dw3_Gxu7[6];
static float mpc_dw3_Guu7[1];
static float mpc_dw3_Rux7[6];
static float mpc_dw3_Vxx7[36];
static float mpc_dw3_Gx7[6];
static float mpc_dw3_Gu7[1];
static float mpc_dw3_Ru7[1];
static float mpc_dw3_Vx7[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir7[6];
static float mpc_dw3_du_ir7[1];
static float mpc_dw3_ds_ir7[8];
static float mpc_dw3_dp_ir7[6];
static float mpc_dw3_dy_ir7[16];
static float mpc_dw3_dnu_ir7[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir7[6];
static float mpc_dw3_rf0u_ir7[1];
static float mpc_dw3_rf0s_ir7[8];
static float mpc_dw3_rf_ir7[6];
static float mpc_dw3_rc_ir7[8];
static float mpc_dw3_rs_ir7[8];
static float mpc_dw3_rk_ir7[16];

/* Variablen für Disketisierungsstelle 8 */
/* Optimierungsvariablen */
static float mpc_dw3_x8[6];
static float mpc_dw3_u8[1];
static float mpc_dw3_s8[8];
static float mpc_dw3_p8[6];
static float mpc_dw3_y8[16];
static float mpc_dw3_nu8[16];
/* Schrittvariablen */
static float mpc_dw3_dx8[6];
static float mpc_dw3_du8[1];
static float mpc_dw3_ds8[8];
static float mpc_dw3_dp8[6];
static float mpc_dw3_dy8[16];
static float mpc_dw3_dnu8[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx8[36];
static float mpc_dw3_Hxu8[6];
static float mpc_dw3_Huu8[1];
static float mpc_dw3_Hss8[64];
static float mpc_dw3_f0x8[6];
static float mpc_dw3_f0u8[1];
static float mpc_dw3_f0s8[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx8[36];
static float mpc_dw3_fu8[6];
static float mpc_dw3_f8[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx8[48];
static float mpc_dw3_gu8[8];
static float mpc_dw3_g8[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x8[6];
static float mpc_dw3_rf0u8[1];
static float mpc_dw3_rf0s8[8];
static float mpc_dw3_rf8[6];
static float mpc_dw3_rc8[8];
static float mpc_dw3_rs8[8];
static float mpc_dw3_rk8[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x8[6];
static float mpc_dw3_rrf0u8[1];
static float mpc_dw3_rhsxs8[8];
static float mpc_dw3_yny8[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx8[36];
static float mpc_dw3_Gxu8[6];
static float mpc_dw3_Guu8[1];
static float mpc_dw3_Rux8[6];
static float mpc_dw3_Vxx8[36];
static float mpc_dw3_Gx8[6];
static float mpc_dw3_Gu8[1];
static float mpc_dw3_Ru8[1];
static float mpc_dw3_Vx8[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir8[6];
static float mpc_dw3_du_ir8[1];
static float mpc_dw3_ds_ir8[8];
static float mpc_dw3_dp_ir8[6];
static float mpc_dw3_dy_ir8[16];
static float mpc_dw3_dnu_ir8[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir8[6];
static float mpc_dw3_rf0u_ir8[1];
static float mpc_dw3_rf0s_ir8[8];
static float mpc_dw3_rf_ir8[6];
static float mpc_dw3_rc_ir8[8];
static float mpc_dw3_rs_ir8[8];
static float mpc_dw3_rk_ir8[16];

/* Variablen für Disketisierungsstelle 9 */
/* Optimierungsvariablen */
static float mpc_dw3_x9[6];
static float mpc_dw3_u9[1];
static float mpc_dw3_s9[8];
static float mpc_dw3_p9[6];
static float mpc_dw3_y9[16];
static float mpc_dw3_nu9[16];
/* Schrittvariablen */
static float mpc_dw3_dx9[6];
static float mpc_dw3_du9[1];
static float mpc_dw3_ds9[8];
static float mpc_dw3_dp9[6];
static float mpc_dw3_dy9[16];
static float mpc_dw3_dnu9[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx9[36];
static float mpc_dw3_Hxu9[6];
static float mpc_dw3_Huu9[1];
static float mpc_dw3_Hss9[64];
static float mpc_dw3_f0x9[6];
static float mpc_dw3_f0u9[1];
static float mpc_dw3_f0s9[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx9[36];
static float mpc_dw3_fu9[6];
static float mpc_dw3_f9[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx9[48];
static float mpc_dw3_gu9[8];
static float mpc_dw3_g9[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x9[6];
static float mpc_dw3_rf0u9[1];
static float mpc_dw3_rf0s9[8];
static float mpc_dw3_rf9[6];
static float mpc_dw3_rc9[8];
static float mpc_dw3_rs9[8];
static float mpc_dw3_rk9[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x9[6];
static float mpc_dw3_rrf0u9[1];
static float mpc_dw3_rhsxs9[8];
static float mpc_dw3_yny9[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx9[36];
static float mpc_dw3_Gxu9[6];
static float mpc_dw3_Guu9[1];
static float mpc_dw3_Rux9[6];
static float mpc_dw3_Vxx9[36];
static float mpc_dw3_Gx9[6];
static float mpc_dw3_Gu9[1];
static float mpc_dw3_Ru9[1];
static float mpc_dw3_Vx9[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir9[6];
static float mpc_dw3_du_ir9[1];
static float mpc_dw3_ds_ir9[8];
static float mpc_dw3_dp_ir9[6];
static float mpc_dw3_dy_ir9[16];
static float mpc_dw3_dnu_ir9[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir9[6];
static float mpc_dw3_rf0u_ir9[1];
static float mpc_dw3_rf0s_ir9[8];
static float mpc_dw3_rf_ir9[6];
static float mpc_dw3_rc_ir9[8];
static float mpc_dw3_rs_ir9[8];
static float mpc_dw3_rk_ir9[16];

/* Variablen für Disketisierungsstelle 10 */
/* Optimierungsvariablen */
static float mpc_dw3_x10[6];
static float mpc_dw3_u10[1];
static float mpc_dw3_s10[8];
static float mpc_dw3_p10[6];
static float mpc_dw3_y10[16];
static float mpc_dw3_nu10[16];
/* Schrittvariablen */
static float mpc_dw3_dx10[6];
static float mpc_dw3_du10[1];
static float mpc_dw3_ds10[8];
static float mpc_dw3_dp10[6];
static float mpc_dw3_dy10[16];
static float mpc_dw3_dnu10[16];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx10[36];
static float mpc_dw3_Hxu10[6];
static float mpc_dw3_Huu10[1];
static float mpc_dw3_Hss10[64];
static float mpc_dw3_f0x10[6];
static float mpc_dw3_f0u10[1];
static float mpc_dw3_f0s10[8];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx10[36];
static float mpc_dw3_fu10[6];
static float mpc_dw3_f10[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx10[48];
static float mpc_dw3_gu10[8];
static float mpc_dw3_g10[8];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x10[6];
static float mpc_dw3_rf0u10[1];
static float mpc_dw3_rf0s10[8];
static float mpc_dw3_rf10[6];
static float mpc_dw3_rc10[8];
static float mpc_dw3_rs10[8];
static float mpc_dw3_rk10[16];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x10[6];
static float mpc_dw3_rrf0u10[1];
static float mpc_dw3_rhsxs10[8];
static float mpc_dw3_yny10[8];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx10[36];
static float mpc_dw3_Gxu10[6];
static float mpc_dw3_Guu10[1];
static float mpc_dw3_Rux10[6];
static float mpc_dw3_Vxx10[36];
static float mpc_dw3_Gx10[6];
static float mpc_dw3_Gu10[1];
static float mpc_dw3_Ru10[1];
static float mpc_dw3_Vx10[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir10[6];
static float mpc_dw3_du_ir10[1];
static float mpc_dw3_ds_ir10[8];
static float mpc_dw3_dp_ir10[6];
static float mpc_dw3_dy_ir10[16];
static float mpc_dw3_dnu_ir10[16];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir10[6];
static float mpc_dw3_rf0u_ir10[1];
static float mpc_dw3_rf0s_ir10[8];
static float mpc_dw3_rf_ir10[6];
static float mpc_dw3_rc_ir10[8];
static float mpc_dw3_rs_ir10[8];
static float mpc_dw3_rk_ir10[16];

/* Variablen für Disketisierungsstelle 11 */
/* Optimierungsvariablen */
static float mpc_dw3_x11[6];
static float mpc_dw3_u11[1];
static float mpc_dw3_s11[4];
static float mpc_dw3_p11[6];
static float mpc_dw3_y11[8];
static float mpc_dw3_nu11[8];
/* Schrittvariablen */
static float mpc_dw3_dx11[6];
static float mpc_dw3_du11[1];
static float mpc_dw3_ds11[4];
static float mpc_dw3_dp11[6];
static float mpc_dw3_dy11[8];
static float mpc_dw3_dnu11[8];
/* Variablen der Guetefunktion */
static float mpc_dw3_Hxx11[36];
static float mpc_dw3_Hxu11[6];
static float mpc_dw3_Huu11[1];
static float mpc_dw3_Hss11[16];
static float mpc_dw3_f0x11[6];
static float mpc_dw3_f0u11[1];
static float mpc_dw3_f0s11[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw3_fx11[36];
static float mpc_dw3_fu11[6];
static float mpc_dw3_f11[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw3_gx11[24];
static float mpc_dw3_gu11[4];
static float mpc_dw3_g11[4];
/* Variablen der rechten Seiten */
static float mpc_dw3_rf0x11[6];
static float mpc_dw3_rf0u11[1];
static float mpc_dw3_rf0s11[4];
static float mpc_dw3_rf11[6];
static float mpc_dw3_rc11[4];
static float mpc_dw3_rs11[4];
static float mpc_dw3_rk11[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw3_rrf0x11[6];
static float mpc_dw3_rrf0u11[1];
static float mpc_dw3_rhsxs11[4];
static float mpc_dw3_yny11[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw3_Gxx11[36];
static float mpc_dw3_Gxu11[6];
static float mpc_dw3_Guu11[1];
static float mpc_dw3_Rux11[6];
static float mpc_dw3_Vxx11[36];
static float mpc_dw3_Gx11[6];
static float mpc_dw3_Gu11[1];
static float mpc_dw3_Ru11[1];
static float mpc_dw3_Vx11[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw3_dx_ir11[6];
static float mpc_dw3_du_ir11[1];
static float mpc_dw3_ds_ir11[4];
static float mpc_dw3_dp_ir11[6];
static float mpc_dw3_dy_ir11[8];
static float mpc_dw3_dnu_ir11[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw3_rf0x_ir11[6];
static float mpc_dw3_rf0u_ir11[1];
static float mpc_dw3_rf0s_ir11[4];
static float mpc_dw3_rf_ir11[6];
static float mpc_dw3_rc_ir11[4];
static float mpc_dw3_rs_ir11[4];
static float mpc_dw3_rk_ir11[8];

/* Temporäre Variablen */
static float mpc_dw3_tmp1_4_1[4];
static float mpc_dw3_tmp2_4_1[4];
static float mpc_dw3_tmp3_4_1[4];
static float mpc_dw3_tmp1_0_1[1];
static float mpc_dw3_tmp1_8_1[8];
static float mpc_dw3_tmp2_8_1[8];
static float mpc_dw3_tmp3_8_1[8];
static float mpc_dw3_tmp1_8[8];
static float mpc_dw3_tmp2_8[8];
static float mpc_dw3_tmp3_8[8];
static float mpc_dw3_tmp4_8[8];
static float mpc_dw3_tmp1_1[1];
static float mpc_dw3_tmp2_1[1];
static float mpc_dw3_tmp3_1[1];
static float mpc_dw3_tmp1_16[16];
static float mpc_dw3_tmp2_16[16];
static float mpc_dw3_tmp3_16[16];
static float mpc_dw3_tmp4_16[16];
static float mpc_dw3_tmp1_6_6[36];
static float mpc_dw3_tmp1_6_4[24];
static float mpc_dw3_tmp1_1_6[6];
static float mpc_dw3_tmp1_1_4[4];
static float mpc_dw3_tmp1_6_8[48];
static float mpc_dw3_tmp1_1_8[8];
static float mpc_dw3_tmp1_6[6];
static float mpc_dw3_tmp1_6_1[6];
static float mpc_dw3_tmp1_1_1[1];
static float mpc_dw3_tmp2_1_1[1];

/* Temporäre Variablen für Cholesky Zerlegung */
static float mpc_dw3_L0[1];
static float mpc_dw3_L1[1];
static float mpc_dw3_L2[1];
static float mpc_dw3_L3[1];
static float mpc_dw3_L4[1];
static float mpc_dw3_L5[1];
static float mpc_dw3_L6[1];
static float mpc_dw3_L7[1];
static float mpc_dw3_L8[1];
static float mpc_dw3_L9[1];
static float mpc_dw3_L10[1];
static float mpc_dw3_L11[1];

/* Variablen für max_stepsize */
static float mpc_dw3_alpha_max[1];
static float mpc_dw3_alpha_tmp[1];
static float mpc_dw3_alpha_min_y[1];
static float mpc_dw3_alpha_min_dy[1];
static float mpc_dw3_alpha_min_nu[1];
static float mpc_dw3_alpha_min_dnu[1];
static int mpc_dw3_alpha_min_source_y;

/* Variablen für mehrotra_step */
static float mpc_dw3_mehrotra_alpha[1];
static float mpc_dw3_mehrotra_gamma[1];
static float mpc_dw3_mehrotra_fpd[1];

/* Verschiedenes */
static int mpc_dw3_iter;
static int mpc_dw3_max_iter;
static int mpc_dw3_termcode;
static int mpc_dw3_iter_ref;
static int mpc_dw3_error_line;
static int mpc_dw3_error_source;
static float mpc_dw3_m_ineq[1];
static float mpc_dw3_macheps[1];
static float mpc_dw3_tau[1];
static float mpc_dw3_sigma[1];
static float mpc_dw3_norm_d[1];
static float mpc_dw3_norm_r[1];
static float mpc_dw3_norm_r0[1];
static float mpc_dw3_norm_r_prev[1];
static float mpc_dw3_mu[1];
static float mpc_dw3_mu0[1];
static float mpc_dw3_mu_aff[1];
static float mpc_dw3_phi[1];
static float mpc_dw3_minphi[1];
static float mpc_dw3_tol[1];
static float mpc_dw3_tc1_factor[1];
static float mpc_dw3_tc2_factor[1];
static double mpc_dw3_timer_start;
static double mpc_dw3_time_max;

/* Variablen für Duality Gap */
static float mpc_dw3_dgap[1];

/* Variablen für Starting Point */
static float mpc_dw3_starting_point_delta_y[1];
static float mpc_dw3_starting_point_delta_nu[1];
static float mpc_dw3_starting_point_sum[1];
static float mpc_dw3_starting_point_sum_y[1];
static float mpc_dw3_starting_point_sum_nu[1];

/* Variablen für Statistik */
static float mpc_dw3_stat_time[20];
static int mpc_dw3_stat_iter_ref[20];
static int mpc_dw3_stat_num_iter_ref;
static int mpc_dw3_stat_num_factor;
static int mpc_dw3_stat_num_solve;



float *mpc_dw3_get_x0()
{
return mpc_dw3_xinit;
}

float *mpc_dw3_get_x(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_x0;
    case 1: return mpc_dw3_x1;
    case 2: return mpc_dw3_x2;
    case 3: return mpc_dw3_x3;
    case 4: return mpc_dw3_x4;
    case 5: return mpc_dw3_x5;
    case 6: return mpc_dw3_x6;
    case 7: return mpc_dw3_x7;
    case 8: return mpc_dw3_x8;
    case 9: return mpc_dw3_x9;
    case 10: return mpc_dw3_x10;
    case 11: return mpc_dw3_x11;
    default: return 0;
  }
}

float *mpc_dw3_get_u(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_u0;
    case 1: return mpc_dw3_u1;
    case 2: return mpc_dw3_u2;
    case 3: return mpc_dw3_u3;
    case 4: return mpc_dw3_u4;
    case 5: return mpc_dw3_u5;
    case 6: return mpc_dw3_u6;
    case 7: return mpc_dw3_u7;
    case 8: return mpc_dw3_u8;
    case 9: return mpc_dw3_u9;
    case 10: return mpc_dw3_u10;
    case 11: return mpc_dw3_u11;
    default: return 0;
  }
}

float *mpc_dw3_get_s(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_s0;
    case 1: return mpc_dw3_s1;
    case 2: return mpc_dw3_s2;
    case 3: return mpc_dw3_s3;
    case 4: return mpc_dw3_s4;
    case 5: return mpc_dw3_s5;
    case 6: return mpc_dw3_s6;
    case 7: return mpc_dw3_s7;
    case 8: return mpc_dw3_s8;
    case 9: return mpc_dw3_s9;
    case 10: return mpc_dw3_s10;
    case 11: return mpc_dw3_s11;
    default: return 0;
  }
}

float *mpc_dw3_get_p(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_p0;
    case 1: return mpc_dw3_p1;
    case 2: return mpc_dw3_p2;
    case 3: return mpc_dw3_p3;
    case 4: return mpc_dw3_p4;
    case 5: return mpc_dw3_p5;
    case 6: return mpc_dw3_p6;
    case 7: return mpc_dw3_p7;
    case 8: return mpc_dw3_p8;
    case 9: return mpc_dw3_p9;
    case 10: return mpc_dw3_p10;
    case 11: return mpc_dw3_p11;
    default: return 0;
  }
}

float *mpc_dw3_get_y(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_y0;
    case 1: return mpc_dw3_y1;
    case 2: return mpc_dw3_y2;
    case 3: return mpc_dw3_y3;
    case 4: return mpc_dw3_y4;
    case 5: return mpc_dw3_y5;
    case 6: return mpc_dw3_y6;
    case 7: return mpc_dw3_y7;
    case 8: return mpc_dw3_y8;
    case 9: return mpc_dw3_y9;
    case 10: return mpc_dw3_y10;
    case 11: return mpc_dw3_y11;
    default: return 0;
  }
}

float *mpc_dw3_get_nu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_nu0;
    case 1: return mpc_dw3_nu1;
    case 2: return mpc_dw3_nu2;
    case 3: return mpc_dw3_nu3;
    case 4: return mpc_dw3_nu4;
    case 5: return mpc_dw3_nu5;
    case 6: return mpc_dw3_nu6;
    case 7: return mpc_dw3_nu7;
    case 8: return mpc_dw3_nu8;
    case 9: return mpc_dw3_nu9;
    case 10: return mpc_dw3_nu10;
    case 11: return mpc_dw3_nu11;
    default: return 0;
  }
}

float *mpc_dw3_get_Hxx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_Hxx0;
    case 1: return mpc_dw3_Hxx1;
    case 2: return mpc_dw3_Hxx2;
    case 3: return mpc_dw3_Hxx3;
    case 4: return mpc_dw3_Hxx4;
    case 5: return mpc_dw3_Hxx5;
    case 6: return mpc_dw3_Hxx6;
    case 7: return mpc_dw3_Hxx7;
    case 8: return mpc_dw3_Hxx8;
    case 9: return mpc_dw3_Hxx9;
    case 10: return mpc_dw3_Hxx10;
    case 11: return mpc_dw3_Hxx11;
    default: return 0;
  }
}

float *mpc_dw3_get_Hxu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_Hxu0;
    case 1: return mpc_dw3_Hxu1;
    case 2: return mpc_dw3_Hxu2;
    case 3: return mpc_dw3_Hxu3;
    case 4: return mpc_dw3_Hxu4;
    case 5: return mpc_dw3_Hxu5;
    case 6: return mpc_dw3_Hxu6;
    case 7: return mpc_dw3_Hxu7;
    case 8: return mpc_dw3_Hxu8;
    case 9: return mpc_dw3_Hxu9;
    case 10: return mpc_dw3_Hxu10;
    case 11: return mpc_dw3_Hxu11;
    default: return 0;
  }
}

float *mpc_dw3_get_Huu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_Huu0;
    case 1: return mpc_dw3_Huu1;
    case 2: return mpc_dw3_Huu2;
    case 3: return mpc_dw3_Huu3;
    case 4: return mpc_dw3_Huu4;
    case 5: return mpc_dw3_Huu5;
    case 6: return mpc_dw3_Huu6;
    case 7: return mpc_dw3_Huu7;
    case 8: return mpc_dw3_Huu8;
    case 9: return mpc_dw3_Huu9;
    case 10: return mpc_dw3_Huu10;
    case 11: return mpc_dw3_Huu11;
    default: return 0;
  }
}

float *mpc_dw3_get_Hss(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_Hss0;
    case 1: return mpc_dw3_Hss1;
    case 2: return mpc_dw3_Hss2;
    case 3: return mpc_dw3_Hss3;
    case 4: return mpc_dw3_Hss4;
    case 5: return mpc_dw3_Hss5;
    case 6: return mpc_dw3_Hss6;
    case 7: return mpc_dw3_Hss7;
    case 8: return mpc_dw3_Hss8;
    case 9: return mpc_dw3_Hss9;
    case 10: return mpc_dw3_Hss10;
    case 11: return mpc_dw3_Hss11;
    default: return 0;
  }
}

float *mpc_dw3_get_f0x(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_f0x0;
    case 1: return mpc_dw3_f0x1;
    case 2: return mpc_dw3_f0x2;
    case 3: return mpc_dw3_f0x3;
    case 4: return mpc_dw3_f0x4;
    case 5: return mpc_dw3_f0x5;
    case 6: return mpc_dw3_f0x6;
    case 7: return mpc_dw3_f0x7;
    case 8: return mpc_dw3_f0x8;
    case 9: return mpc_dw3_f0x9;
    case 10: return mpc_dw3_f0x10;
    case 11: return mpc_dw3_f0x11;
    default: return 0;
  }
}

float *mpc_dw3_get_f0u(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_f0u0;
    case 1: return mpc_dw3_f0u1;
    case 2: return mpc_dw3_f0u2;
    case 3: return mpc_dw3_f0u3;
    case 4: return mpc_dw3_f0u4;
    case 5: return mpc_dw3_f0u5;
    case 6: return mpc_dw3_f0u6;
    case 7: return mpc_dw3_f0u7;
    case 8: return mpc_dw3_f0u8;
    case 9: return mpc_dw3_f0u9;
    case 10: return mpc_dw3_f0u10;
    case 11: return mpc_dw3_f0u11;
    default: return 0;
  }
}

float *mpc_dw3_get_f0s(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_f0s0;
    case 1: return mpc_dw3_f0s1;
    case 2: return mpc_dw3_f0s2;
    case 3: return mpc_dw3_f0s3;
    case 4: return mpc_dw3_f0s4;
    case 5: return mpc_dw3_f0s5;
    case 6: return mpc_dw3_f0s6;
    case 7: return mpc_dw3_f0s7;
    case 8: return mpc_dw3_f0s8;
    case 9: return mpc_dw3_f0s9;
    case 10: return mpc_dw3_f0s10;
    case 11: return mpc_dw3_f0s11;
    default: return 0;
  }
}

float *mpc_dw3_get_fx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_fx0;
    case 1: return mpc_dw3_fx1;
    case 2: return mpc_dw3_fx2;
    case 3: return mpc_dw3_fx3;
    case 4: return mpc_dw3_fx4;
    case 5: return mpc_dw3_fx5;
    case 6: return mpc_dw3_fx6;
    case 7: return mpc_dw3_fx7;
    case 8: return mpc_dw3_fx8;
    case 9: return mpc_dw3_fx9;
    case 10: return mpc_dw3_fx10;
    case 11: return mpc_dw3_fx11;
    default: return 0;
  }
}

float *mpc_dw3_get_fu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_fu0;
    case 1: return mpc_dw3_fu1;
    case 2: return mpc_dw3_fu2;
    case 3: return mpc_dw3_fu3;
    case 4: return mpc_dw3_fu4;
    case 5: return mpc_dw3_fu5;
    case 6: return mpc_dw3_fu6;
    case 7: return mpc_dw3_fu7;
    case 8: return mpc_dw3_fu8;
    case 9: return mpc_dw3_fu9;
    case 10: return mpc_dw3_fu10;
    case 11: return mpc_dw3_fu11;
    default: return 0;
  }
}

float *mpc_dw3_get_f(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_f0;
    case 1: return mpc_dw3_f1;
    case 2: return mpc_dw3_f2;
    case 3: return mpc_dw3_f3;
    case 4: return mpc_dw3_f4;
    case 5: return mpc_dw3_f5;
    case 6: return mpc_dw3_f6;
    case 7: return mpc_dw3_f7;
    case 8: return mpc_dw3_f8;
    case 9: return mpc_dw3_f9;
    case 10: return mpc_dw3_f10;
    case 11: return mpc_dw3_f11;
    default: return 0;
  }
}

float *mpc_dw3_get_gx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_gx0;
    case 1: return mpc_dw3_gx1;
    case 2: return mpc_dw3_gx2;
    case 3: return mpc_dw3_gx3;
    case 4: return mpc_dw3_gx4;
    case 5: return mpc_dw3_gx5;
    case 6: return mpc_dw3_gx6;
    case 7: return mpc_dw3_gx7;
    case 8: return mpc_dw3_gx8;
    case 9: return mpc_dw3_gx9;
    case 10: return mpc_dw3_gx10;
    case 11: return mpc_dw3_gx11;
    default: return 0;
  }
}

float *mpc_dw3_get_gu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_gu0;
    case 1: return mpc_dw3_gu1;
    case 2: return mpc_dw3_gu2;
    case 3: return mpc_dw3_gu3;
    case 4: return mpc_dw3_gu4;
    case 5: return mpc_dw3_gu5;
    case 6: return mpc_dw3_gu6;
    case 7: return mpc_dw3_gu7;
    case 8: return mpc_dw3_gu8;
    case 9: return mpc_dw3_gu9;
    case 10: return mpc_dw3_gu10;
    case 11: return mpc_dw3_gu11;
    default: return 0;
  }
}

float *mpc_dw3_get_g(int k)
{
  switch(k)
  {
    case 0: return mpc_dw3_g0;
    case 1: return mpc_dw3_g1;
    case 2: return mpc_dw3_g2;
    case 3: return mpc_dw3_g3;
    case 4: return mpc_dw3_g4;
    case 5: return mpc_dw3_g5;
    case 6: return mpc_dw3_g6;
    case 7: return mpc_dw3_g7;
    case 8: return mpc_dw3_g8;
    case 9: return mpc_dw3_g9;
    case 10: return mpc_dw3_g10;
    case 11: return mpc_dw3_g11;
    default: return 0;
  }
}

float *mpc_dw3_get_stat_time()
{
return mpc_dw3_stat_time;
}

int *mpc_dw3_get_stat_iter_ref()
{
return &mpc_dw3_stat_iter_ref;
}

int *mpc_dw3_get_stat_num_factor()
{
return &mpc_dw3_stat_num_factor;
}

int *mpc_dw3_get_stat_num_solve()
{
return &mpc_dw3_stat_num_solve;
}

int *mpc_dw3_get_stat_num_iter_ref()
{
return &mpc_dw3_stat_num_iter_ref;
}

int *mpc_dw3_get_iter()
{
return &mpc_dw3_iter;
}

int *mpc_dw3_get_termcode()
{
return &mpc_dw3_termcode;
}

int *mpc_dw3_get_error_line()
{
return &mpc_dw3_error_line;
}

int *mpc_dw3_get_error_source()
{
return &mpc_dw3_error_source;
}

float *mpc_dw3_get_norm_d()
{
return mpc_dw3_norm_d;
}
double *mpc_dw3_get_time_max()
{
return &mpc_dw3_time_max;
}

void mpc_dw3_set_time_max(double tmax)
{
mpc_dw3_time_max = tmax;
}


/* ###################################### */
/* Diese Funktion initialisiert den Timer */
/* ###################################### */
void mpc_dw3_glqdocpip_timer_start()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER mpc_dw3_tmp_counter, mpc_dw3_tmp_frequency;
  QueryPerformanceFrequency(&mpc_dw3_tmp_frequency);
  QueryPerformanceCounter(&mpc_dw3_tmp_counter);
  mpc_dw3_timer_start = (double) mpc_dw3_tmp_counter.QuadPart/(double) mpc_dw3_tmp_frequency.QuadPart;
#elif defined(_DS1103)
  mpc_dw3_timer_start = (double) ds1103_timebase_fltread();
#endif
}


/* ################################################### */
/* Diese Funktion gibt die Zeit seit Timerstart zurück */
/* ################################################### */
double mpc_dw3_glqdocpip_timer_get()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER mpc_dw3_tmp_counter, mpc_dw3_tmp_frequency;
  QueryPerformanceFrequency(&mpc_dw3_tmp_frequency);
  QueryPerformanceCounter(&mpc_dw3_tmp_counter);
  return (double) mpc_dw3_tmp_counter.QuadPart/(double) mpc_dw3_tmp_frequency.QuadPart - mpc_dw3_timer_start;
#elif defined(_DS1103)
  return (double) ds1103_timebase_fltread()- mpc_dw3_timer_start;
#endif
}

static void mpc_dw3_v_copy_6(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc_dw3_mv_sid21_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid24_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_vsub_6(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  out[4] = a[4] - b[4];
  out[5] = a[5] - b[5];
  return;
}

static void mpc_dw3_mtv_sid42_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mtv_sid51_sid15_4_6(float *A, float *b, float *out)
{

  out[5] += A[20] * b[0];
  out[5] += A[21] * b[1];
  return;
}

static void mpc_dw3_v_copy_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc_dw3_mtv_sid24_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_mv_sid27_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw3_mtv_sid45_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw3_mtv_sid54_sid15_4_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  return;
}

static void mpc_dw3_v_copy_4(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc_dw3_mv_sid30_sid18_4_4(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[5] * b[1];
  out[2] += A[10] * b[2];
  out[3] += A[15] * b[3];
  return;
}

static void mpc_dw3_vsub_4(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  return;
}

static void mpc_dw3_mv_sid51_sid2_4_6(float *A, float *b, float *out)
{

  out[0] += A[20] * b[5];
  out[1] += A[21] * b[5];
  return;
}

static void mpc_dw3_mv_sid54_sid5_4_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  return;
}

static void mpc_dw3_vadd_4(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  return;
}

static void mpc_dw3_v_init0_4(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
  return;
}

static void mpc_dw3_vv_elemult_8(float *a, float *b, float *out)
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

static void mpc_dw3_mv_sid22_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid25_sid5_6_1(float *A, float *b, float *out)
{

  out[4] += A[4] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw3_mtv_sid43_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mtv_sid52_sid16_8_6(float *A, float *b, float *out)
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

static void mpc_dw3_mtv_sid25_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[4] * b[4];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw3_mv_sid28_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw3_mtv_sid46_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw3_mtv_sid55_sid16_8_1(float *A, float *b, float *out)
{

  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  return;
}

static void mpc_dw3_v_copy_8(float *a, float *out)
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

static void mpc_dw3_mv_sid31_sid19_8_8(float *A, float *b, float *out)
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

static void mpc_dw3_vsub_8(float *a, float *b, float *out)
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

static void mpc_dw3_mv_sid43_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid46_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw3_mv_sid52_sid2_8_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid55_sid5_8_1(float *A, float *b, float *out)
{

  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  return;
}

static void mpc_dw3_vadd_8(float *a, float *b, float *out)
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

static void mpc_dw3_v_init0_8(float *a)
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

static void mpc_dw3_vv_elemult_16(float *a, float *b, float *out)
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

static void mpc_dw3_mv_sid23_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid26_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_mtv_sid53_sid17_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[8] * b[0];
  out[0] += A[1] * b[1];
  out[2] += A[9] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  return;
}

static void mpc_dw3_mtv_sid26_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_mv_sid29_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw3_mtv_sid56_sid17_4_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_mv_sid32_sid20_4_4(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[5] * b[1];
  out[2] += A[10] * b[2];
  out[3] += A[15] * b[3];
  return;
}

static void mpc_dw3_mv_sid44_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid47_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw3_mv_sid53_sid2_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[0] += A[8] * b[2];
  out[1] += A[9] * b[2];
  return;
}

static void mpc_dw3_mv_sid56_sid5_4_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw3_vv_elediv_4(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  return;
}

static void mpc_dw3_mv_4_4(float *A, float *b, float *out)
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

static void mpc_dw3_v_init1_4(float *a)
{

    a[0] =1;
    a[1] =1;
    a[2] =1;
    a[3] =1;
  return;
}

static void mpc_dw3_vv_elemult_4(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  return;
}

static void mpc_dw3_vv_elediv_8(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  return;
}

static void mpc_dw3_mv_8_8(float *A, float *b, float *out)
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

static void mpc_dw3_v_init1_8(float *a)
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

static void mpc_dw3_vv_elemult_1(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  return;
}

static void mpc_dw3_sv_8(float *a, float *b, float *out)
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

static void mpc_dw3_vadd_16(float *a, float *b, float *out)
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

static void mpc_dw3_v_init1_16(float *a)
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

static void mpc_dw3_v_init0_16(float *a)
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

static void mpc_dw3_sv_16(float *a, float *b, float *out)
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

static void mpc_dw3_vsub_16(float *a, float *b, float *out)
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

static void mpc_dw3_m_copy_6_6(float *a, float *out)
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

static void mpc_dw3_m_copy_6_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc_dw3_m_init0_6_4(float *a)
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

static void mpc_dw3_mtd_sid53_sid17_4_6(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[2] += A[8] * B[0];
      out[6] += A[1] * B[1];
      out[8] += A[9] * B[1];
      out[12] += A[2] * B[2];
      out[18] += A[3] * B[3];
  return;
}

static void mpc_dw3_mm_y_sid14_sid53_6_4_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid14_sid56_6_4_1(float *A, float *B, float *out)
{

  return;
}

static void mpc_dw3_m_copy_1_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc_dw3_m_init0_1_4(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  return;
}

static void mpc_dw3_mtd_sid56_sid17_4_1(float *A, float *B, float *out)
{

  return;
}

static void mpc_dw3_mm_1_4_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
  return;
}

static void mpc_dw3_mtr_6_1(float *A, float *out)
{

  out[0] = A[0];
  out[1] = A[1];
  out[2] = A[2];
  out[3] = A[3];
  out[4] = A[4];
  out[5] = A[5];
  return;
}

static void mpc_dw3_chol_factor_1(float *a, float *out)
{
  if(a[0] == 0){
    mpc_dw3_termcode = 8;
    mpc_dw3_error_line = __LINE__;
    return;
  }
  out[0] = 1/a[0];
  return;
}

static void mpc_dw3_chol_solve_1_6(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<6; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc_dw3_m_init0_6_6(float *a)
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

static void mpc_dw3_mm_y_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw3_msub_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_mtm_sid43_sid1_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_y_sid1_sid43_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid1_sid46_6_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[0] += A[30] * B[5];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[1] += A[31] * B[5];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[2] += A[32] * B[5];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[3] += A[33] * B[5];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[4] += A[34] * B[5];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[5] += A[35] * B[5];
  return;
}

static void mpc_dw3_m_init0_6_8(float *a)
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

static void mpc_dw3_mtd_sid52_sid16_8_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_y_sid13_sid52_6_8_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid13_sid55_6_8_1(float *A, float *B, float *out)
{

out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[0] += A[36] * B[6];
out[0] += A[42] * B[7];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[1] += A[37] * B[6];
out[1] += A[43] * B[7];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[2] += A[38] * B[6];
out[2] += A[44] * B[7];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[3] += A[39] * B[6];
out[3] += A[45] * B[7];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[4] += A[40] * B[6];
out[4] += A[46] * B[7];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[5] += A[41] * B[6];
out[5] += A[47] * B[7];
  return;
}

static void mpc_dw3_m_init0_1_6(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  return;
}

static void mpc_dw3_mtm_sid46_sid1_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid8_sid46_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc_dw3_m_init0_1_8(float *a)
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

static void mpc_dw3_mtd_sid55_sid16_8_1(float *A, float *B, float *out)
{

      out[2] += A[2] * B[2];
      out[3] += A[3] * B[3];
      out[6] += A[6] * B[6];
      out[7] += A[7] * B[7];
  return;
}

static void mpc_dw3_mm_1_8_1(float *A, float *B, float *out)
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

static void mpc_dw3_mtm_sid42_sid1_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_y_sid1_sid42_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid1_sid45_6_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[0] += A[30] * B[5];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[1] += A[31] * B[5];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[2] += A[32] * B[5];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[3] += A[33] * B[5];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[4] += A[34] * B[5];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
out[5] += A[35] * B[5];
  return;
}

static void mpc_dw3_mtd_sid51_sid15_4_6(float *A, float *B, float *out)
{

      out[5] += A[20] * B[0];
      out[11] += A[21] * B[1];
  return;
}

static void mpc_dw3_mm_y_sid12_sid51_6_4_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid12_sid54_6_4_1(float *A, float *B, float *out)
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
  return;
}

static void mpc_dw3_mtm_sid45_sid1_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw3_mm_sid8_sid45_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc_dw3_mtd_sid54_sid15_4_1(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[1] += A[1] * B[1];
      out[2] += A[2] * B[2];
      out[3] += A[3] * B[3];
  return;
}

static void mpc_dw3_chol_solve_1_1(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<1; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc_dw3_v_init0_6(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
    a[4] =0;
    a[5] =0;
  return;
}

static void mpc_dw3_mv_6_1(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[4] += A[4] * b[0];
      out[5] += A[5] * b[0];
  return;
}

static void mpc_dw3_mv_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_1_6(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[0] += A[1] * b[1];
      out[0] += A[2] * b[2];
      out[0] += A[3] * b[3];
      out[0] += A[4] * b[4];
      out[0] += A[5] * b[5];
  return;
}

static void mpc_dw3_v_turnsign_1(float *a, float *out)
{

    out[0] = -a[0];
  return;
}

static void mpc_dw3_mv_sid42_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw3_mv_sid45_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw3_m_copy_4_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc_dw3_v_turnsign_8(float *a, float *out)
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

static void mpc_dw3_m_copy_8_1(float *a, float *out)
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

static void mpc_dw3_vv_elediv_16(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  if(b[8] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[8] = a[8] / b[8];
  if(b[9] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[9] = a[9] / b[9];
  if(b[10] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[10] = a[10] / b[10];
  if(b[11] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[11] = a[11] / b[11];
  if(b[12] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[12] = a[12] / b[12];
  if(b[13] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[13] = a[13] / b[13];
  if(b[14] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[14] = a[14] / b[14];
  if(b[15] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[15] = a[15] / b[15];
  return;
}

static void mpc_dw3_v_turnsign_16(float *a, float *out)
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

static void mpc_dw3_v_copy_16(float *a, float *out)
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

static void mpc_dw3_vadd_6(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  out[4] = a[4] + b[4];
  out[5] = a[5] + b[5];
  return;
}

static void mpc_dw3_vadd_1(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  return;
}

static void mpc_dw3_v_init0_1(float *a)
{

    a[0] =0;
  return;
}

static void mpc_dw3_vtv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  out[0] += a[4] * b[4];
  out[0] += a[5] * b[5];
  return;
}

static void mpc_dw3_vtv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc_dw3_vtv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  return;
}

static void mpc_dw3_vsub_1(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  return;
}

static void mpc_dw3_vtv_8(float *a, float *b, float *out)
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

static void mpc_dw3_vtv_16(float *a, float *b, float *out)
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

static void mpc_dw3_vv_elediv_1(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw3_termcode = 8; mpc_dw3_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  return;
}

static void mpc_dw3_min(float *a, float *b, float *out)
{

  if  (a[0] < b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc_dw3_v_init1_1(float *a)
{

    a[0] =1;
  return;
}

static void mpc_dw3_max(float *a, float *b, float *out)
{

  if  (a[0] > b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc_dw3_sv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  out[4] += a[0] * b[4];
  out[5] += a[0] * b[5];
  return;
}

static void mpc_dw3_sv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc_dw3_sv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  return;
}

static void mpc_dw3_norm_inf_6_6(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_6_1(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_1_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  return;
}

static void mpc_dw3_norm_inf_4_4(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_4_1(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_4_6(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_8_8(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_8_1(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_8_6(float *A, float *B, float *out)
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

static void mpc_dw3_norm_inf_16_1(float *A, float *B, float *out)
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

static void mpc_dw3_v_min_8(float *A, float *B, float *out)
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

static void mpc_dw3_v_min_16(float *A, float *B, float *out)
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

static void mpc_dw3_vsum_8(float *a, float *out)
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

static void mpc_dw3_vsum_16(float *a, float *out)
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

static void mpc_dw3_mm_sid1_sid42_6_6_6(float *A, float *B, float *out)
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
out[6] += A[0] * B[6];
out[6] += A[6] * B[7];
out[6] += A[12] * B[8];
out[6] += A[18] * B[9];
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
out[12] += A[12] * B[14];
out[12] += A[18] * B[15];
out[13] += A[13] * B[14];
out[13] += A[19] * B[15];
out[14] += A[14] * B[14];
out[14] += A[20] * B[15];
out[15] += A[15] * B[14];
out[15] += A[21] * B[15];
out[16] += A[16] * B[14];
out[16] += A[22] * B[15];
out[17] += A[17] * B[14];
out[17] += A[23] * B[15];
out[18] += A[12] * B[20];
out[18] += A[18] * B[21];
out[19] += A[13] * B[20];
out[19] += A[19] * B[21];
out[20] += A[14] * B[20];
out[20] += A[20] * B[21];
out[21] += A[15] * B[20];
out[21] += A[21] * B[21];
out[22] += A[16] * B[20];
out[22] += A[22] * B[21];
out[23] += A[17] * B[20];
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
static void mpc_dw3_glqdocpip_calc_mu()
{
mpc_dw3_v_init0_1(mpc_dw3_mu);
/* mu = mu + y*nu */
/* Zeitschritt 0 */
mpc_dw3_vtv_8(mpc_dw3_y0, mpc_dw3_nu0, mpc_dw3_mu);
/* Zeitschritt 1 */
mpc_dw3_vtv_16(mpc_dw3_y1, mpc_dw3_nu1, mpc_dw3_mu);
/* Zeitschritt 2 */
mpc_dw3_vtv_16(mpc_dw3_y2, mpc_dw3_nu2, mpc_dw3_mu);
/* Zeitschritt 3 */
mpc_dw3_vtv_16(mpc_dw3_y3, mpc_dw3_nu3, mpc_dw3_mu);
/* Zeitschritt 4 */
mpc_dw3_vtv_16(mpc_dw3_y4, mpc_dw3_nu4, mpc_dw3_mu);
/* Zeitschritt 5 */
mpc_dw3_vtv_16(mpc_dw3_y5, mpc_dw3_nu5, mpc_dw3_mu);
/* Zeitschritt 6 */
mpc_dw3_vtv_16(mpc_dw3_y6, mpc_dw3_nu6, mpc_dw3_mu);
/* Zeitschritt 7 */
mpc_dw3_vtv_16(mpc_dw3_y7, mpc_dw3_nu7, mpc_dw3_mu);
/* Zeitschritt 8 */
mpc_dw3_vtv_16(mpc_dw3_y8, mpc_dw3_nu8, mpc_dw3_mu);
/* Zeitschritt 9 */
mpc_dw3_vtv_16(mpc_dw3_y9, mpc_dw3_nu9, mpc_dw3_mu);
/* Zeitschritt 10 */
mpc_dw3_vtv_16(mpc_dw3_y10, mpc_dw3_nu10, mpc_dw3_mu);
/* Zeitschritt 11 */
mpc_dw3_vtv_8(mpc_dw3_y11, mpc_dw3_nu11, mpc_dw3_mu);
mpc_dw3_vv_elediv_1(mpc_dw3_mu, mpc_dw3_m_ineq, mpc_dw3_mu);
if(mpc_dw3_termcode > -1){return;}

/* mu0 bestimmen */
if(mpc_dw3_iter == 0){
mpc_dw3_v_copy_1(mpc_dw3_mu, mpc_dw3_mu0);
}
}


/* ############################### */
/* Diese Funktion berechnet mu_aff */
/* ############################### */
static void mpc_dw3_glqdocpip_calc_mu_aff()
{
mpc_dw3_v_init0_1(mpc_dw3_mu_aff);
/* Zeitschritt 0 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_8(mpc_dw3_y0, mpc_dw3_tmp1_8);
mpc_dw3_sv_8(mpc_dw3_alpha_max, mpc_dw3_dy0, mpc_dw3_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_8(mpc_dw3_nu0, mpc_dw3_tmp2_8);
mpc_dw3_sv_8(mpc_dw3_alpha_max, mpc_dw3_dnu0, mpc_dw3_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_8(mpc_dw3_tmp1_8, mpc_dw3_tmp2_8, mpc_dw3_mu_aff);
/* Zeitschritt 1 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y1, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy1, mpc_dw3_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu1, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu1, mpc_dw3_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp1_16, mpc_dw3_tmp2_16, mpc_dw3_mu_aff);
/* Zeitschritt 2 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y2, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy2, mpc_dw3_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu2, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu2, mpc_dw3_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp1_16, mpc_dw3_mu_aff);
/* Zeitschritt 3 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y3, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy3, mpc_dw3_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu3, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu3, mpc_dw3_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp1_16, mpc_dw3_tmp2_16, mpc_dw3_mu_aff);
/* Zeitschritt 4 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y4, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy4, mpc_dw3_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu4, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu4, mpc_dw3_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp1_16, mpc_dw3_mu_aff);
/* Zeitschritt 5 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y5, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy5, mpc_dw3_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu5, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu5, mpc_dw3_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp1_16, mpc_dw3_tmp2_16, mpc_dw3_mu_aff);
/* Zeitschritt 6 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y6, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy6, mpc_dw3_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu6, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu6, mpc_dw3_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp1_16, mpc_dw3_mu_aff);
/* Zeitschritt 7 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y7, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy7, mpc_dw3_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu7, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu7, mpc_dw3_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp1_16, mpc_dw3_tmp2_16, mpc_dw3_mu_aff);
/* Zeitschritt 8 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y8, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy8, mpc_dw3_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu8, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu8, mpc_dw3_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp1_16, mpc_dw3_mu_aff);
/* Zeitschritt 9 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y9, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy9, mpc_dw3_tmp1_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu9, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu9, mpc_dw3_tmp2_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp1_16, mpc_dw3_tmp2_16, mpc_dw3_mu_aff);
/* Zeitschritt 10 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_16(mpc_dw3_y10, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dy10, mpc_dw3_tmp2_16);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_16(mpc_dw3_nu10, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_alpha_max, mpc_dw3_dnu10, mpc_dw3_tmp1_16);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp1_16, mpc_dw3_mu_aff);
/* Zeitschritt 11 */
/* yady = y + alpha_max*dy */
mpc_dw3_v_copy_8(mpc_dw3_y11, mpc_dw3_tmp2_8);
mpc_dw3_sv_8(mpc_dw3_alpha_max, mpc_dw3_dy11, mpc_dw3_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw3_v_copy_8(mpc_dw3_nu11, mpc_dw3_tmp1_8);
mpc_dw3_sv_8(mpc_dw3_alpha_max, mpc_dw3_dnu11, mpc_dw3_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw3_vtv_8(mpc_dw3_tmp2_8, mpc_dw3_tmp1_8, mpc_dw3_mu_aff);
mpc_dw3_vv_elediv_1(mpc_dw3_mu_aff, mpc_dw3_m_ineq, mpc_dw3_mu_aff);
if(mpc_dw3_termcode > -1){return;}
}


/* ############################ */
/* Diese Funktion berechnet phi */
/* ############################ */
static void mpc_dw3_glqdocpip_calc_phi()
{
mpc_dw3_vadd_1(mpc_dw3_norm_r, mpc_dw3_dgap, mpc_dw3_phi);
mpc_dw3_vv_elediv_1(mpc_dw3_phi, mpc_dw3_norm_d, mpc_dw3_phi);
if(mpc_dw3_termcode > -1){return;}
if (mpc_dw3_iter > 0) {

mpc_dw3_min(mpc_dw3_minphi, mpc_dw3_phi, mpc_dw3_minphi);
}else{
mpc_dw3_v_copy_1(mpc_dw3_phi, mpc_dw3_minphi);
}
}


/* ######################################################## */
/* Diese Funktion berechnet den Zentrierungsparameter sigma */
/* ######################################################## */
static void mpc_dw3_glqdocpip_calc_sigma()
{
mpc_dw3_vv_elediv_1(mpc_dw3_mu_aff, mpc_dw3_mu, mpc_dw3_tmp1_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_sigma[0] = pow(*mpc_dw3_tmp1_1, *mpc_dw3_tau);
}


/* ########################################################### */
/* Diese Funktion berechnet die maximal mögliche Schrittweite, */
/* bei der y und nu noch positiv bleiben */
/* ########################################################### */
static void mpc_dw3_glqdocpip_max_stepsize()
{
int i;

mpc_dw3_alpha_max[0] = -FLT_MAX;
mpc_dw3_alpha_tmp[0] = 0;

/* Zeitschritt 0 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw3_dy0[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y0[i], &mpc_dw3_dy0[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y0[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy0[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu0[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu0[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu0[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu0[i], &mpc_dw3_dnu0[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y0[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy0[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu0[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu0[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 1 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy1[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y1[i], &mpc_dw3_dy1[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y1[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy1[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu1[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu1[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu1[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu1[i], &mpc_dw3_dnu1[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y1[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy1[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu1[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu1[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 2 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy2[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y2[i], &mpc_dw3_dy2[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y2[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy2[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu2[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu2[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu2[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu2[i], &mpc_dw3_dnu2[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y2[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy2[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu2[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu2[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 3 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy3[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y3[i], &mpc_dw3_dy3[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y3[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy3[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu3[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu3[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu3[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu3[i], &mpc_dw3_dnu3[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y3[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy3[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu3[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu3[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 4 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy4[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y4[i], &mpc_dw3_dy4[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y4[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy4[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu4[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu4[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu4[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu4[i], &mpc_dw3_dnu4[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y4[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy4[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu4[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu4[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 5 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy5[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y5[i], &mpc_dw3_dy5[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y5[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy5[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu5[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu5[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu5[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu5[i], &mpc_dw3_dnu5[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y5[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy5[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu5[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu5[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 6 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy6[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y6[i], &mpc_dw3_dy6[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y6[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy6[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu6[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu6[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu6[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu6[i], &mpc_dw3_dnu6[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y6[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy6[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu6[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu6[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 7 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy7[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y7[i], &mpc_dw3_dy7[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y7[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy7[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu7[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu7[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu7[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu7[i], &mpc_dw3_dnu7[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y7[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy7[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu7[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu7[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 8 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy8[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y8[i], &mpc_dw3_dy8[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y8[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy8[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu8[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu8[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu8[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu8[i], &mpc_dw3_dnu8[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y8[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy8[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu8[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu8[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 9 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy9[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y9[i], &mpc_dw3_dy9[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y9[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy9[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu9[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu9[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu9[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu9[i], &mpc_dw3_dnu9[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y9[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy9[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu9[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu9[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 10 */
for(i=0;i<16;i++)
{
/* dy-check */
if( mpc_dw3_dy10[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y10[i], &mpc_dw3_dy10[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y10[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy10[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu10[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu10[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu10[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu10[i], &mpc_dw3_dnu10[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y10[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy10[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu10[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu10[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 11 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw3_dy11[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_y11[i], &mpc_dw3_dy11[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y11[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy11[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu11[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu11[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw3_dnu11[i] < 0)
{
mpc_dw3_vv_elediv_1(&mpc_dw3_nu11[i], &mpc_dw3_dnu11[i], mpc_dw3_alpha_tmp);
if(mpc_dw3_termcode > -1){return;}
if( *mpc_dw3_alpha_tmp > *mpc_dw3_alpha_max )
{
mpc_dw3_alpha_max[0] = *mpc_dw3_alpha_tmp;
mpc_dw3_v_copy_1(&mpc_dw3_y11[i], &mpc_dw3_alpha_min_y[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dy11[i], &mpc_dw3_alpha_min_dy[0]);
mpc_dw3_v_copy_1(&mpc_dw3_nu11[i], &mpc_dw3_alpha_min_nu[0]);
mpc_dw3_v_copy_1(&mpc_dw3_dnu11[i], &mpc_dw3_alpha_min_dnu[0]);
mpc_dw3_alpha_min_source_y = 0;
}
}
}

mpc_dw3_v_turnsign_1(&mpc_dw3_alpha_max[0], &mpc_dw3_alpha_max[0]);
}


/* ####################################################### */
/* Diese Funktion berechnet die Schrittweite nach Mehrotra */
/* ####################################################### */
static void mpc_dw3_glqdocpip_mehrotra_step()
{

/* FPD */
if (mpc_dw3_alpha_min_source_y == 1) {
/* alpha_max durch y verursacht */
mpc_dw3_vv_elemult_1(mpc_dw3_alpha_max, mpc_dw3_alpha_min_dnu, mpc_dw3_mehrotra_fpd);
mpc_dw3_vadd_1(mpc_dw3_mehrotra_fpd, mpc_dw3_alpha_min_nu, mpc_dw3_mehrotra_fpd);
mpc_dw3_vv_elediv_1(mpc_dw3_mu_aff, mpc_dw3_mehrotra_fpd, mpc_dw3_mehrotra_fpd);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_1(mpc_dw3_mehrotra_fpd, mpc_dw3_mehrotra_gamma, mpc_dw3_mehrotra_fpd);
mpc_dw3_vsub_1(mpc_dw3_mehrotra_fpd, mpc_dw3_alpha_min_y, mpc_dw3_mehrotra_fpd);
mpc_dw3_vv_elemult_1(mpc_dw3_alpha_max, mpc_dw3_alpha_min_dy, mpc_dw3_tmp1_1);
mpc_dw3_vv_elediv_1(mpc_dw3_mehrotra_fpd, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_fpd);
if(mpc_dw3_termcode > -1){return;}
} else {
/* alpha_max durch nu verursacht */
mpc_dw3_vv_elemult_1(mpc_dw3_alpha_max, mpc_dw3_alpha_min_dy, mpc_dw3_mehrotra_fpd);
mpc_dw3_vadd_1(mpc_dw3_mehrotra_fpd, mpc_dw3_alpha_min_y, mpc_dw3_mehrotra_fpd);
mpc_dw3_vv_elediv_1(mpc_dw3_mu_aff, mpc_dw3_mehrotra_fpd, mpc_dw3_mehrotra_fpd);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_1(mpc_dw3_mehrotra_fpd, mpc_dw3_mehrotra_gamma, mpc_dw3_mehrotra_fpd);
mpc_dw3_vsub_1(mpc_dw3_mehrotra_fpd, mpc_dw3_alpha_min_nu, mpc_dw3_mehrotra_fpd);
mpc_dw3_vv_elemult_1(mpc_dw3_alpha_max, mpc_dw3_alpha_min_dnu, mpc_dw3_tmp1_1);
mpc_dw3_vv_elediv_1(mpc_dw3_mehrotra_fpd, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_fpd);
if(mpc_dw3_termcode > -1){return;}
}
/* Schrittweitenfaktor begrenzen */
/* Nach unten limitieren (1-gamma) */
mpc_dw3_v_init1_1(mpc_dw3_tmp1_1);
mpc_dw3_vsub_1(mpc_dw3_tmp1_1, mpc_dw3_mehrotra_gamma, mpc_dw3_tmp1_1);
mpc_dw3_max(mpc_dw3_mehrotra_fpd, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_fpd);
/* nach oben limitieren (1-macheps) */
mpc_dw3_v_init1_1(mpc_dw3_tmp1_1);
mpc_dw3_vsub_1(mpc_dw3_tmp1_1, mpc_dw3_macheps, mpc_dw3_tmp1_1);
mpc_dw3_min(mpc_dw3_mehrotra_fpd, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_fpd);
/* Schrittweite berechnen */
mpc_dw3_vv_elemult_1(mpc_dw3_mehrotra_fpd, mpc_dw3_alpha_max, mpc_dw3_mehrotra_alpha);
/* Schritt begrenzen 0 =< alpha =< 1 */
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(mpc_dw3_mehrotra_alpha, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_alpha);
mpc_dw3_v_init1_1(mpc_dw3_tmp1_1);
mpc_dw3_min(mpc_dw3_mehrotra_alpha, mpc_dw3_tmp1_1, mpc_dw3_mehrotra_alpha);
}


/* ########################################### */
/* Diese Funktion berechnet die Dualitätslücke */
/* ########################################### */
static void mpc_dw3_glqdocpip_calc_duality_gap()
{
mpc_dw3_v_init0_1(mpc_dw3_dgap);
/* Zeitschritt 0 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid21_sid2_6_6(mpc_dw3_Hxx0, mpc_dw3_x0, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x0, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid24_sid5_6_1(mpc_dw3_Hxu0, mpc_dw3_u0, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x0, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x0, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid27_sid5_1_1(mpc_dw3_Huu0, mpc_dw3_u0, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u0, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss0, mpc_dw3_s0, mpc_dw3_tmp3_4_1);
mpc_dw3_vtv_4(mpc_dw3_s0, mpc_dw3_tmp3_4_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x0, mpc_dw3_x0, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u0, mpc_dw3_u0, mpc_dw3_dgap);
mpc_dw3_vtv_4(mpc_dw3_f0s0, mpc_dw3_s0, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_xinit, mpc_dw3_p0, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_4(mpc_dw3_g0, mpc_dw3_y0, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 1 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx1, mpc_dw3_x1, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x1, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu1, mpc_dw3_u1, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x1, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x1, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu1, mpc_dw3_u1, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u1, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss1, mpc_dw3_s1, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s1, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x1, mpc_dw3_x1, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u1, mpc_dw3_u1, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s1, mpc_dw3_s1, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f0, mpc_dw3_p1, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g1, mpc_dw3_y1, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 2 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx2, mpc_dw3_x2, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x2, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu2, mpc_dw3_u2, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x2, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x2, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu2, mpc_dw3_u2, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u2, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss2, mpc_dw3_s2, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s2, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x2, mpc_dw3_x2, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u2, mpc_dw3_u2, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s2, mpc_dw3_s2, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f1, mpc_dw3_p2, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g2, mpc_dw3_y2, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 3 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx3, mpc_dw3_x3, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x3, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu3, mpc_dw3_u3, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x3, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x3, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu3, mpc_dw3_u3, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u3, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss3, mpc_dw3_s3, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s3, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x3, mpc_dw3_x3, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u3, mpc_dw3_u3, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s3, mpc_dw3_s3, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f2, mpc_dw3_p3, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g3, mpc_dw3_y3, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 4 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx4, mpc_dw3_x4, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x4, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu4, mpc_dw3_u4, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x4, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x4, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu4, mpc_dw3_u4, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u4, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss4, mpc_dw3_s4, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s4, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x4, mpc_dw3_x4, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u4, mpc_dw3_u4, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s4, mpc_dw3_s4, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f3, mpc_dw3_p4, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g4, mpc_dw3_y4, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 5 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx5, mpc_dw3_x5, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x5, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu5, mpc_dw3_u5, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x5, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x5, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu5, mpc_dw3_u5, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u5, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss5, mpc_dw3_s5, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s5, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x5, mpc_dw3_x5, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u5, mpc_dw3_u5, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s5, mpc_dw3_s5, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f4, mpc_dw3_p5, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g5, mpc_dw3_y5, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 6 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx6, mpc_dw3_x6, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x6, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu6, mpc_dw3_u6, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x6, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x6, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu6, mpc_dw3_u6, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u6, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss6, mpc_dw3_s6, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s6, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x6, mpc_dw3_x6, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u6, mpc_dw3_u6, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s6, mpc_dw3_s6, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f5, mpc_dw3_p6, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g6, mpc_dw3_y6, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 7 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx7, mpc_dw3_x7, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x7, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu7, mpc_dw3_u7, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x7, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x7, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu7, mpc_dw3_u7, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u7, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss7, mpc_dw3_s7, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s7, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x7, mpc_dw3_x7, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u7, mpc_dw3_u7, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s7, mpc_dw3_s7, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f6, mpc_dw3_p7, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g7, mpc_dw3_y7, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 8 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx8, mpc_dw3_x8, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x8, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu8, mpc_dw3_u8, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x8, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x8, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu8, mpc_dw3_u8, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u8, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss8, mpc_dw3_s8, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s8, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x8, mpc_dw3_x8, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u8, mpc_dw3_u8, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s8, mpc_dw3_s8, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f7, mpc_dw3_p8, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g8, mpc_dw3_y8, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 9 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx9, mpc_dw3_x9, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x9, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu9, mpc_dw3_u9, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x9, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x9, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu9, mpc_dw3_u9, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u9, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss9, mpc_dw3_s9, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s9, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x9, mpc_dw3_x9, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u9, mpc_dw3_u9, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s9, mpc_dw3_s9, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f8, mpc_dw3_p9, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g9, mpc_dw3_y9, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 10 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx10, mpc_dw3_x10, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x10, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu10, mpc_dw3_u10, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x10, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x10, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu10, mpc_dw3_u10, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u10, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss10, mpc_dw3_s10, mpc_dw3_tmp2_8_1);
mpc_dw3_vtv_8(mpc_dw3_s10, mpc_dw3_tmp2_8_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x10, mpc_dw3_x10, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u10, mpc_dw3_u10, mpc_dw3_dgap);
mpc_dw3_vtv_8(mpc_dw3_f0s10, mpc_dw3_s10, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f9, mpc_dw3_p10, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_8(mpc_dw3_g10, mpc_dw3_y10, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Zeitschritt 11 */
/* Quadratischer Anteil */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid23_sid2_6_6(mpc_dw3_Hxx11, mpc_dw3_x11, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x11, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6_1);
mpc_dw3_mv_sid26_sid5_6_1(mpc_dw3_Hxu11, mpc_dw3_u11, mpc_dw3_tmp1_6_1);
mpc_dw3_vtv_6(mpc_dw3_x11, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_vtv_6(mpc_dw3_x11, mpc_dw3_tmp1_6_1, mpc_dw3_dgap);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1_1);
mpc_dw3_mv_sid29_sid5_1_1(mpc_dw3_Huu11, mpc_dw3_u11, mpc_dw3_tmp1_1_1);
mpc_dw3_vtv_1(mpc_dw3_u11, mpc_dw3_tmp1_1_1, mpc_dw3_dgap);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss11, mpc_dw3_s11, mpc_dw3_tmp3_4_1);
mpc_dw3_vtv_4(mpc_dw3_s11, mpc_dw3_tmp3_4_1, mpc_dw3_dgap);
/* Linearer Anteil */
mpc_dw3_vtv_6(mpc_dw3_f0x11, mpc_dw3_x11, mpc_dw3_dgap);
mpc_dw3_vtv_1(mpc_dw3_f0u11, mpc_dw3_u11, mpc_dw3_dgap);
mpc_dw3_vtv_4(mpc_dw3_f0s11, mpc_dw3_s11, mpc_dw3_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_6(mpc_dw3_f10, mpc_dw3_p11, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw3_v_init0_1(mpc_dw3_tmp2_1_1);
mpc_dw3_vtv_4(mpc_dw3_g11, mpc_dw3_y11, mpc_dw3_tmp2_1_1);
mpc_dw3_vsub_1(mpc_dw3_dgap, mpc_dw3_tmp2_1_1, mpc_dw3_dgap);
/* dgap = abs(dgap) */
if(mpc_dw3_dgap[0] < 0){
mpc_dw3_dgap[0] = -mpc_dw3_dgap[0];}
}


/* ############################################################ */
/* Diese Funktion berechnet die Unendlichnorm der Eingangsdaten */
/* ############################################################ */
static void mpc_dw3_glqdocpip_calc_norm_d()
{
mpc_dw3_v_init1_1(mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_4(mpc_dw3_Hss0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_f0s0, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_4_6(mpc_dw3_gx0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_gu0, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_g0, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s1, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f1, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu1, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g1, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s2, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f2, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu2, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g2, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s3, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f3, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu3, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g3, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s4, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f4, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu4, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g4, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s5, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f5, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu5, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g5, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s6, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f6, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu6, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g6, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s7, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f7, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu7, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g7, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s8, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f8, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu8, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g8, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s9, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f9, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu9, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g9, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_8(mpc_dw3_Hss10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_f0s10, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f10, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_8_6(mpc_dw3_gx10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_gu10, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_8_1(mpc_dw3_g10, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_6(mpc_dw3_Hxx11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_Hxu11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_Huu11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_4(mpc_dw3_Hss11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f0x11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_1_1(mpc_dw3_f0u11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_f0s11, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw3_norm_inf_6_6(mpc_dw3_fx11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_fu11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_6_1(mpc_dw3_f11, mpc_dw3_norm_d, mpc_dw3_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw3_norm_inf_4_6(mpc_dw3_gx11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_gu11, mpc_dw3_norm_d, mpc_dw3_norm_d);
mpc_dw3_norm_inf_4_1(mpc_dw3_g11, mpc_dw3_norm_d, mpc_dw3_norm_d);
}


/* ############################################################# */
/* Diese Funktion berechnet die Unendlichnorm der rechten Seiten */
/* ############################################################# */
static void mpc_dw3_glqdocpip_calc_norm_r()
{
/* norm_r_prev bestimmen */
if(mpc_dw3_iter > 0){
mpc_dw3_v_copy_1(mpc_dw3_norm_r, mpc_dw3_norm_r_prev);
}
mpc_dw3_v_init0_1(mpc_dw3_norm_r);
/* Zeitschritt 0 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x0, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u0, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_4_1(mpc_dw3_rf0s0, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_4_1(mpc_dw3_rc0, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_4_1(mpc_dw3_rs0, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rk0, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 1 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x1, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u1, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s1, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf1, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc1, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs1, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk1, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 2 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x2, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u2, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s2, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf2, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc2, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs2, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk2, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 3 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x3, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u3, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s3, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf3, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc3, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs3, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk3, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 4 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x4, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u4, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s4, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf4, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc4, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs4, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk4, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 5 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x5, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u5, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s5, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf5, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc5, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs5, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk5, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 6 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x6, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u6, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s6, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf6, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc6, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs6, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk6, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 7 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x7, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u7, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s7, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf7, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc7, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs7, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk7, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 8 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x8, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u8, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s8, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf8, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc8, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs8, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk8, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 9 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x9, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u9, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s9, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf9, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc9, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs9, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk9, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 10 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x10, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u10, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rf0s10, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf10, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rc10, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_8_1(mpc_dw3_rs10, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_16_1(mpc_dw3_rk10, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Zeitschritt 11 */
/* Aus Gütefunktion */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf0x11, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_1_1(mpc_dw3_rf0u11, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_4_1(mpc_dw3_rf0s11, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw3_norm_inf_6_1(mpc_dw3_rf11, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw3_norm_inf_4_1(mpc_dw3_rc11, mpc_dw3_norm_r, mpc_dw3_norm_r);
mpc_dw3_norm_inf_4_1(mpc_dw3_rs11, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw3_norm_inf_8_1(mpc_dw3_rk11, mpc_dw3_norm_r, mpc_dw3_norm_r);
/* norm_r0 bestimmen */
if(mpc_dw3_iter == 0){
mpc_dw3_v_copy_1(mpc_dw3_norm_r, mpc_dw3_norm_r0);
}
}


/* ###################################### */
/* Diese Funktion führt einen Schritt aus */
/* ###################################### */
static void mpc_dw3_glqdocpip_step()
{
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx0, mpc_dw3_x0);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du0, mpc_dw3_u0);
mpc_dw3_sv_4(mpc_dw3_mehrotra_alpha, mpc_dw3_ds0, mpc_dw3_s0);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp0, mpc_dw3_p0);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_dy0, mpc_dw3_y0);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu0, mpc_dw3_nu0);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx1, mpc_dw3_x1);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du1, mpc_dw3_u1);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds1, mpc_dw3_s1);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp1, mpc_dw3_p1);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy1, mpc_dw3_y1);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu1, mpc_dw3_nu1);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx2, mpc_dw3_x2);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du2, mpc_dw3_u2);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds2, mpc_dw3_s2);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp2, mpc_dw3_p2);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy2, mpc_dw3_y2);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu2, mpc_dw3_nu2);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx3, mpc_dw3_x3);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du3, mpc_dw3_u3);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds3, mpc_dw3_s3);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp3, mpc_dw3_p3);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy3, mpc_dw3_y3);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu3, mpc_dw3_nu3);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx4, mpc_dw3_x4);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du4, mpc_dw3_u4);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds4, mpc_dw3_s4);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp4, mpc_dw3_p4);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy4, mpc_dw3_y4);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu4, mpc_dw3_nu4);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx5, mpc_dw3_x5);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du5, mpc_dw3_u5);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds5, mpc_dw3_s5);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp5, mpc_dw3_p5);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy5, mpc_dw3_y5);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu5, mpc_dw3_nu5);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx6, mpc_dw3_x6);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du6, mpc_dw3_u6);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds6, mpc_dw3_s6);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp6, mpc_dw3_p6);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy6, mpc_dw3_y6);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu6, mpc_dw3_nu6);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx7, mpc_dw3_x7);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du7, mpc_dw3_u7);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds7, mpc_dw3_s7);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp7, mpc_dw3_p7);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy7, mpc_dw3_y7);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu7, mpc_dw3_nu7);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx8, mpc_dw3_x8);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du8, mpc_dw3_u8);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds8, mpc_dw3_s8);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp8, mpc_dw3_p8);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy8, mpc_dw3_y8);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu8, mpc_dw3_nu8);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx9, mpc_dw3_x9);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du9, mpc_dw3_u9);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds9, mpc_dw3_s9);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp9, mpc_dw3_p9);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy9, mpc_dw3_y9);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu9, mpc_dw3_nu9);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx10, mpc_dw3_x10);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du10, mpc_dw3_u10);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_ds10, mpc_dw3_s10);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp10, mpc_dw3_p10);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dy10, mpc_dw3_y10);
mpc_dw3_sv_16(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu10, mpc_dw3_nu10);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dx11, mpc_dw3_x11);
mpc_dw3_sv_1(mpc_dw3_mehrotra_alpha, mpc_dw3_du11, mpc_dw3_u11);
mpc_dw3_sv_4(mpc_dw3_mehrotra_alpha, mpc_dw3_ds11, mpc_dw3_s11);
mpc_dw3_sv_6(mpc_dw3_mehrotra_alpha, mpc_dw3_dp11, mpc_dw3_p11);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_dy11, mpc_dw3_y11);
mpc_dw3_sv_8(mpc_dw3_mehrotra_alpha, mpc_dw3_dnu11, mpc_dw3_nu11);
}


/* ######################################################### */
/* Diese Funktion führt Konvergenz- und Divergenztests durch */
/* ######################################################### */
static void mpc_dw3_glqdocpip_check_condiv()
{
/* Termcode 0 - Success */
if(mpc_dw3_mu[0] <= mpc_dw3_tol[0]){
mpc_dw3_vv_elemult_1(mpc_dw3_tol, mpc_dw3_norm_d, mpc_dw3_tmp1_1);
  if(mpc_dw3_norm_r[0] <= mpc_dw3_tmp1_1[0]){
  mpc_dw3_termcode = 0;
  return;
  }
}

/* Termcode 1 - infeasible */
if(mpc_dw3_phi[0] > mpc_dw3_tol[0]){
mpc_dw3_vv_elemult_1(mpc_dw3_tc1_factor, mpc_dw3_minphi, mpc_dw3_tmp1_1);
  if(mpc_dw3_phi[0] >= mpc_dw3_tmp1_1[0]){
  mpc_dw3_termcode = 1;
  return;
  }
}

/* Termcode 2 - slow convergence */
mpc_dw3_vv_elemult_1(mpc_dw3_tol, mpc_dw3_norm_d, mpc_dw3_tmp1_1);
if(mpc_dw3_norm_r[0] > mpc_dw3_tmp1_1[0]){
mpc_dw3_vv_elediv_1(mpc_dw3_norm_r, mpc_dw3_mu, mpc_dw3_tmp1_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_1(mpc_dw3_norm_r0, mpc_dw3_mu0, mpc_dw3_tmp2_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_1(mpc_dw3_tc2_factor, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
  if(mpc_dw3_tmp1_1[0] >= mpc_dw3_tmp2_1[0]){
  mpc_dw3_termcode = 2;
  return;
  }
}

/* Termcode 7 - calculation time limit exceeded */
if(mpc_dw3_iter > 0){
  if(mpc_dw3_glqdocpip_timer_get()*(double)mpc_dw3_iter/ (double) (mpc_dw3_iter + 1) > mpc_dw3_time_max){
    mpc_dw3_termcode = 7;
    return;
  }
}

/* iterative refinement */
/* ### FLAGS ### */
/* # keep_iterative_refinements_on = 0 */
/* # iterative_refinements_require_norm_r_is_not_too_small = 0 */
/* ############# */
mpc_dw3_iter_ref = 0;
if(mpc_dw3_iter > 0){
mpc_dw3_tmp1_1[0] = 100;
mpc_dw3_vv_elemult_1(mpc_dw3_tmp1_1, mpc_dw3_tol, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_norm_d, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
if(mpc_dw3_norm_r_prev[0] > mpc_dw3_tmp2_1[0]){
mpc_dw3_tmp1_1[0] = 1.001;
mpc_dw3_vv_elemult_1(mpc_dw3_tmp1_1, mpc_dw3_norm_r_prev, mpc_dw3_tmp2_1);
if(mpc_dw3_norm_r[0] > mpc_dw3_tmp2_1[0]){
mpc_dw3_iter_ref = 1;
}
}
}

}


/* ################################################ */
/* Diese Funktion speichert Daten für die Statistik */
/* ################################################ */
static void mpc_dw3_glqdocpip_stat()
{
/* Zeit */
mpc_dw3_stat_time[mpc_dw3_iter] = mpc_dw3_glqdocpip_timer_get();
}


static void mpc_dw3_glqdocpip_factor()
{
mpc_dw3_error_source = 1;
mpc_dw3_stat_num_factor++;
/* Factor: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx11, mpc_dw3_Gxx11);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu11, mpc_dw3_Gxu11);
mpc_dw3_m_init0_6_4(mpc_dw3_tmp1_6_4);
mpc_dw3_mtd_sid53_sid17_4_6(mpc_dw3_gx11, mpc_dw3_yny11, mpc_dw3_tmp1_6_4);
mpc_dw3_mm_y_sid14_sid53_6_4_6(mpc_dw3_tmp1_6_4, mpc_dw3_gx11, mpc_dw3_Gxx11);
mpc_dw3_mm_sid14_sid56_6_4_1(mpc_dw3_tmp1_6_4, mpc_dw3_gu11, mpc_dw3_Gxu11);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu11, mpc_dw3_Guu11);
mpc_dw3_m_init0_1_4(mpc_dw3_tmp1_1_4);
mpc_dw3_mtd_sid56_sid17_4_1(mpc_dw3_gu11, mpc_dw3_yny11, mpc_dw3_tmp1_1_4);
mpc_dw3_mm_1_4_1(mpc_dw3_tmp1_1_4, mpc_dw3_gu11, mpc_dw3_Guu11);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu11, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu11, mpc_dw3_L11);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L11, mpc_dw3_tmp1_1_6, mpc_dw3_Rux11);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx11);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu11, mpc_dw3_Rux11, mpc_dw3_Vxx11);
mpc_dw3_msub_6_6(mpc_dw3_Gxx11, mpc_dw3_Vxx11, mpc_dw3_Vxx11);
/* Zeitschritt 10 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx10, mpc_dw3_Gxx10);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu10, mpc_dw3_Gxu10);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx10, mpc_dw3_Vxx11, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx10, mpc_dw3_Gxx10);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu10, mpc_dw3_Gxu10);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx10, mpc_dw3_yny10, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx10, mpc_dw3_Gxx10);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu10, mpc_dw3_Gxu10);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu10, mpc_dw3_Guu10);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu10, mpc_dw3_Vxx11, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu10, mpc_dw3_Guu10);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu10, mpc_dw3_yny10, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu10, mpc_dw3_Guu10);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu10, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu10, mpc_dw3_L10);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L10, mpc_dw3_tmp1_1_6, mpc_dw3_Rux10);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx10);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu10, mpc_dw3_Rux10, mpc_dw3_Vxx10);
mpc_dw3_msub_6_6(mpc_dw3_Gxx10, mpc_dw3_Vxx10, mpc_dw3_Vxx10);
/* Zeitschritt 9 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx9, mpc_dw3_Gxx9);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu9, mpc_dw3_Gxu9);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx9, mpc_dw3_Vxx10, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx9, mpc_dw3_Gxx9);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu9, mpc_dw3_Gxu9);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx9, mpc_dw3_yny9, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx9, mpc_dw3_Gxx9);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu9, mpc_dw3_Gxu9);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu9, mpc_dw3_Guu9);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu9, mpc_dw3_Vxx10, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu9, mpc_dw3_Guu9);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu9, mpc_dw3_yny9, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu9, mpc_dw3_Guu9);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu9, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu9, mpc_dw3_L9);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L9, mpc_dw3_tmp1_1_6, mpc_dw3_Rux9);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx9);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu9, mpc_dw3_Rux9, mpc_dw3_Vxx9);
mpc_dw3_msub_6_6(mpc_dw3_Gxx9, mpc_dw3_Vxx9, mpc_dw3_Vxx9);
/* Zeitschritt 8 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx8, mpc_dw3_Gxx8);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu8, mpc_dw3_Gxu8);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx8, mpc_dw3_Vxx9, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx8, mpc_dw3_Gxx8);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu8, mpc_dw3_Gxu8);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx8, mpc_dw3_yny8, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx8, mpc_dw3_Gxx8);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu8, mpc_dw3_Gxu8);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu8, mpc_dw3_Guu8);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu8, mpc_dw3_Vxx9, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu8, mpc_dw3_Guu8);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu8, mpc_dw3_yny8, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu8, mpc_dw3_Guu8);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu8, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu8, mpc_dw3_L8);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L8, mpc_dw3_tmp1_1_6, mpc_dw3_Rux8);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx8);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu8, mpc_dw3_Rux8, mpc_dw3_Vxx8);
mpc_dw3_msub_6_6(mpc_dw3_Gxx8, mpc_dw3_Vxx8, mpc_dw3_Vxx8);
/* Zeitschritt 7 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx7, mpc_dw3_Gxx7);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu7, mpc_dw3_Gxu7);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx7, mpc_dw3_Vxx8, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx7, mpc_dw3_Gxx7);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu7, mpc_dw3_Gxu7);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx7, mpc_dw3_yny7, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx7, mpc_dw3_Gxx7);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu7, mpc_dw3_Gxu7);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu7, mpc_dw3_Guu7);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu7, mpc_dw3_Vxx8, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu7, mpc_dw3_Guu7);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu7, mpc_dw3_yny7, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu7, mpc_dw3_Guu7);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu7, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu7, mpc_dw3_L7);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L7, mpc_dw3_tmp1_1_6, mpc_dw3_Rux7);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx7);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu7, mpc_dw3_Rux7, mpc_dw3_Vxx7);
mpc_dw3_msub_6_6(mpc_dw3_Gxx7, mpc_dw3_Vxx7, mpc_dw3_Vxx7);
/* Zeitschritt 6 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx6, mpc_dw3_Gxx6);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu6, mpc_dw3_Gxu6);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx6, mpc_dw3_Vxx7, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx6, mpc_dw3_Gxx6);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu6, mpc_dw3_Gxu6);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx6, mpc_dw3_yny6, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx6, mpc_dw3_Gxx6);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu6, mpc_dw3_Gxu6);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu6, mpc_dw3_Guu6);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu6, mpc_dw3_Vxx7, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu6, mpc_dw3_Guu6);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu6, mpc_dw3_yny6, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu6, mpc_dw3_Guu6);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu6, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu6, mpc_dw3_L6);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L6, mpc_dw3_tmp1_1_6, mpc_dw3_Rux6);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx6);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu6, mpc_dw3_Rux6, mpc_dw3_Vxx6);
mpc_dw3_msub_6_6(mpc_dw3_Gxx6, mpc_dw3_Vxx6, mpc_dw3_Vxx6);
/* Zeitschritt 5 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx5, mpc_dw3_Gxx5);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu5, mpc_dw3_Gxu5);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx5, mpc_dw3_Vxx6, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx5, mpc_dw3_Gxx5);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu5, mpc_dw3_Gxu5);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx5, mpc_dw3_yny5, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx5, mpc_dw3_Gxx5);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu5, mpc_dw3_Gxu5);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu5, mpc_dw3_Guu5);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu5, mpc_dw3_Vxx6, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu5, mpc_dw3_Guu5);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu5, mpc_dw3_yny5, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu5, mpc_dw3_Guu5);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu5, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu5, mpc_dw3_L5);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L5, mpc_dw3_tmp1_1_6, mpc_dw3_Rux5);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx5);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu5, mpc_dw3_Rux5, mpc_dw3_Vxx5);
mpc_dw3_msub_6_6(mpc_dw3_Gxx5, mpc_dw3_Vxx5, mpc_dw3_Vxx5);
/* Zeitschritt 4 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx4, mpc_dw3_Gxx4);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu4, mpc_dw3_Gxu4);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx4, mpc_dw3_Vxx5, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx4, mpc_dw3_Gxx4);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu4, mpc_dw3_Gxu4);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx4, mpc_dw3_yny4, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx4, mpc_dw3_Gxx4);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu4, mpc_dw3_Gxu4);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu4, mpc_dw3_Guu4);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu4, mpc_dw3_Vxx5, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu4, mpc_dw3_Guu4);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu4, mpc_dw3_yny4, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu4, mpc_dw3_Guu4);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu4, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu4, mpc_dw3_L4);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L4, mpc_dw3_tmp1_1_6, mpc_dw3_Rux4);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx4);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu4, mpc_dw3_Rux4, mpc_dw3_Vxx4);
mpc_dw3_msub_6_6(mpc_dw3_Gxx4, mpc_dw3_Vxx4, mpc_dw3_Vxx4);
/* Zeitschritt 3 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx3, mpc_dw3_Gxx3);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu3, mpc_dw3_Gxu3);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx3, mpc_dw3_Vxx4, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx3, mpc_dw3_Gxx3);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu3, mpc_dw3_Gxu3);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx3, mpc_dw3_yny3, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx3, mpc_dw3_Gxx3);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu3, mpc_dw3_Gxu3);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu3, mpc_dw3_Guu3);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu3, mpc_dw3_Vxx4, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu3, mpc_dw3_Guu3);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu3, mpc_dw3_yny3, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu3, mpc_dw3_Guu3);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu3, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu3, mpc_dw3_L3);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L3, mpc_dw3_tmp1_1_6, mpc_dw3_Rux3);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx3);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu3, mpc_dw3_Rux3, mpc_dw3_Vxx3);
mpc_dw3_msub_6_6(mpc_dw3_Gxx3, mpc_dw3_Vxx3, mpc_dw3_Vxx3);
/* Zeitschritt 2 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx2, mpc_dw3_Gxx2);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu2, mpc_dw3_Gxu2);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx2, mpc_dw3_Vxx3, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx2, mpc_dw3_Gxx2);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu2, mpc_dw3_Gxu2);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx2, mpc_dw3_yny2, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx2, mpc_dw3_Gxx2);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu2, mpc_dw3_Gxu2);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu2, mpc_dw3_Guu2);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu2, mpc_dw3_Vxx3, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu2, mpc_dw3_Guu2);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu2, mpc_dw3_yny2, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu2, mpc_dw3_Guu2);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu2, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu2, mpc_dw3_L2);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L2, mpc_dw3_tmp1_1_6, mpc_dw3_Rux2);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx2);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu2, mpc_dw3_Rux2, mpc_dw3_Vxx2);
mpc_dw3_msub_6_6(mpc_dw3_Gxx2, mpc_dw3_Vxx2, mpc_dw3_Vxx2);
/* Zeitschritt 1 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx1, mpc_dw3_Gxx1);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu1, mpc_dw3_Gxu1);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid43_sid1_6_6_6(mpc_dw3_fx1, mpc_dw3_Vxx2, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid43_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx1, mpc_dw3_Gxx1);
mpc_dw3_mm_sid1_sid46_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu1, mpc_dw3_Gxu1);
mpc_dw3_m_init0_6_8(mpc_dw3_tmp1_6_8);
mpc_dw3_mtd_sid52_sid16_8_6(mpc_dw3_gx1, mpc_dw3_yny1, mpc_dw3_tmp1_6_8);
mpc_dw3_mm_y_sid13_sid52_6_8_6(mpc_dw3_tmp1_6_8, mpc_dw3_gx1, mpc_dw3_Gxx1);
mpc_dw3_mm_sid13_sid55_6_8_1(mpc_dw3_tmp1_6_8, mpc_dw3_gu1, mpc_dw3_Gxu1);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu1, mpc_dw3_Guu1);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid46_sid1_6_1_6(mpc_dw3_fu1, mpc_dw3_Vxx2, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid46_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu1, mpc_dw3_Guu1);
mpc_dw3_m_init0_1_8(mpc_dw3_tmp1_1_8);
mpc_dw3_mtd_sid55_sid16_8_1(mpc_dw3_gu1, mpc_dw3_yny1, mpc_dw3_tmp1_1_8);
mpc_dw3_mm_1_8_1(mpc_dw3_tmp1_1_8, mpc_dw3_gu1, mpc_dw3_Guu1);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu1, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu1, mpc_dw3_L1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L1, mpc_dw3_tmp1_1_6, mpc_dw3_Rux1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx1);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu1, mpc_dw3_Rux1, mpc_dw3_Vxx1);
mpc_dw3_msub_6_6(mpc_dw3_Gxx1, mpc_dw3_Vxx1, mpc_dw3_Vxx1);
/* Zeitschritt 0 */
/* Gxx und Gxu */
mpc_dw3_m_copy_6_6(mpc_dw3_Hxx0, mpc_dw3_Gxx0);
mpc_dw3_m_copy_6_1(mpc_dw3_Hxu0, mpc_dw3_Gxu0);
mpc_dw3_m_init0_6_6(mpc_dw3_tmp1_6_6);
mpc_dw3_mtm_sid42_sid1_6_6_6(mpc_dw3_fx0, mpc_dw3_Vxx1, mpc_dw3_tmp1_6_6);
mpc_dw3_mm_y_sid1_sid42_6_6_6(mpc_dw3_tmp1_6_6, mpc_dw3_fx0, mpc_dw3_Gxx0);
mpc_dw3_mm_sid1_sid45_6_6_1(mpc_dw3_tmp1_6_6, mpc_dw3_fu0, mpc_dw3_Gxu0);
mpc_dw3_m_init0_6_4(mpc_dw3_tmp1_6_4);
mpc_dw3_mtd_sid51_sid15_4_6(mpc_dw3_gx0, mpc_dw3_yny0, mpc_dw3_tmp1_6_4);
mpc_dw3_mm_y_sid12_sid51_6_4_6(mpc_dw3_tmp1_6_4, mpc_dw3_gx0, mpc_dw3_Gxx0);
mpc_dw3_mm_sid12_sid54_6_4_1(mpc_dw3_tmp1_6_4, mpc_dw3_gu0, mpc_dw3_Gxu0);
/* Guu */
mpc_dw3_m_copy_1_1(mpc_dw3_Huu0, mpc_dw3_Guu0);
mpc_dw3_m_init0_1_6(mpc_dw3_tmp1_1_6);
mpc_dw3_mtm_sid45_sid1_6_1_6(mpc_dw3_fu0, mpc_dw3_Vxx1, mpc_dw3_tmp1_1_6);
mpc_dw3_mm_sid8_sid45_1_6_1(mpc_dw3_tmp1_1_6, mpc_dw3_fu0, mpc_dw3_Guu0);
mpc_dw3_m_init0_1_4(mpc_dw3_tmp1_1_4);
mpc_dw3_mtd_sid54_sid15_4_1(mpc_dw3_gu0, mpc_dw3_yny0, mpc_dw3_tmp1_1_4);
mpc_dw3_mm_1_4_1(mpc_dw3_tmp1_1_4, mpc_dw3_gu0, mpc_dw3_Guu0);
/* Rux */
mpc_dw3_mtr_6_1(mpc_dw3_Gxu0, mpc_dw3_tmp1_1_6);
mpc_dw3_chol_factor_1(mpc_dw3_Guu0, mpc_dw3_L0);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_chol_solve_1_6(mpc_dw3_L0, mpc_dw3_tmp1_1_6, mpc_dw3_Rux0);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_m_init0_6_6(mpc_dw3_Vxx0);
mpc_dw3_mm_y_6_1_6(mpc_dw3_Gxu0, mpc_dw3_Rux0, mpc_dw3_Vxx0);
mpc_dw3_msub_6_6(mpc_dw3_Gxx0, mpc_dw3_Vxx0, mpc_dw3_Vxx0);
mpc_dw3_error_source = 0;

}


static void mpc_dw3_glqdocpip_solve()
{
mpc_dw3_error_source = 2;
mpc_dw3_stat_num_solve++;
/* Solve: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x11, mpc_dw3_Gx11);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u11, mpc_dw3_Gu11);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L11, mpc_dw3_Gu11, mpc_dw3_Ru11);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu11, mpc_dw3_Ru11, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx11, mpc_dw3_tmp1_6, mpc_dw3_Vx11);
/* Zeitschritt 10 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x10, mpc_dw3_Gx10);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u10, mpc_dw3_Gu10);
mpc_dw3_v_copy_6(mpc_dw3_Vx11, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx11, mpc_dw3_rf11, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx10, mpc_dw3_tmp1_6, mpc_dw3_Gx10);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu10, mpc_dw3_tmp1_6, mpc_dw3_Gu10);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L10, mpc_dw3_Gu10, mpc_dw3_Ru10);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu10, mpc_dw3_Ru10, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx10, mpc_dw3_tmp1_6, mpc_dw3_Vx10);
/* Zeitschritt 9 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x9, mpc_dw3_Gx9);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u9, mpc_dw3_Gu9);
mpc_dw3_v_copy_6(mpc_dw3_Vx10, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx10, mpc_dw3_rf10, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_tmp1_6, mpc_dw3_Gx9);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu9, mpc_dw3_tmp1_6, mpc_dw3_Gu9);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L9, mpc_dw3_Gu9, mpc_dw3_Ru9);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu9, mpc_dw3_Ru9, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx9, mpc_dw3_tmp1_6, mpc_dw3_Vx9);
/* Zeitschritt 8 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x8, mpc_dw3_Gx8);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u8, mpc_dw3_Gu8);
mpc_dw3_v_copy_6(mpc_dw3_Vx9, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx9, mpc_dw3_rf9, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_tmp1_6, mpc_dw3_Gx8);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu8, mpc_dw3_tmp1_6, mpc_dw3_Gu8);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L8, mpc_dw3_Gu8, mpc_dw3_Ru8);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu8, mpc_dw3_Ru8, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx8, mpc_dw3_tmp1_6, mpc_dw3_Vx8);
/* Zeitschritt 7 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x7, mpc_dw3_Gx7);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u7, mpc_dw3_Gu7);
mpc_dw3_v_copy_6(mpc_dw3_Vx8, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx8, mpc_dw3_rf8, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_tmp1_6, mpc_dw3_Gx7);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu7, mpc_dw3_tmp1_6, mpc_dw3_Gu7);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L7, mpc_dw3_Gu7, mpc_dw3_Ru7);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu7, mpc_dw3_Ru7, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx7, mpc_dw3_tmp1_6, mpc_dw3_Vx7);
/* Zeitschritt 6 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x6, mpc_dw3_Gx6);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u6, mpc_dw3_Gu6);
mpc_dw3_v_copy_6(mpc_dw3_Vx7, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx7, mpc_dw3_rf7, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_tmp1_6, mpc_dw3_Gx6);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu6, mpc_dw3_tmp1_6, mpc_dw3_Gu6);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L6, mpc_dw3_Gu6, mpc_dw3_Ru6);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu6, mpc_dw3_Ru6, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx6, mpc_dw3_tmp1_6, mpc_dw3_Vx6);
/* Zeitschritt 5 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x5, mpc_dw3_Gx5);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u5, mpc_dw3_Gu5);
mpc_dw3_v_copy_6(mpc_dw3_Vx6, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx6, mpc_dw3_rf6, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_tmp1_6, mpc_dw3_Gx5);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu5, mpc_dw3_tmp1_6, mpc_dw3_Gu5);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L5, mpc_dw3_Gu5, mpc_dw3_Ru5);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu5, mpc_dw3_Ru5, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx5, mpc_dw3_tmp1_6, mpc_dw3_Vx5);
/* Zeitschritt 4 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x4, mpc_dw3_Gx4);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u4, mpc_dw3_Gu4);
mpc_dw3_v_copy_6(mpc_dw3_Vx5, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx5, mpc_dw3_rf5, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_tmp1_6, mpc_dw3_Gx4);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu4, mpc_dw3_tmp1_6, mpc_dw3_Gu4);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L4, mpc_dw3_Gu4, mpc_dw3_Ru4);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu4, mpc_dw3_Ru4, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx4, mpc_dw3_tmp1_6, mpc_dw3_Vx4);
/* Zeitschritt 3 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x3, mpc_dw3_Gx3);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u3, mpc_dw3_Gu3);
mpc_dw3_v_copy_6(mpc_dw3_Vx4, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx4, mpc_dw3_rf4, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_tmp1_6, mpc_dw3_Gx3);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu3, mpc_dw3_tmp1_6, mpc_dw3_Gu3);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L3, mpc_dw3_Gu3, mpc_dw3_Ru3);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu3, mpc_dw3_Ru3, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx3, mpc_dw3_tmp1_6, mpc_dw3_Vx3);
/* Zeitschritt 2 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x2, mpc_dw3_Gx2);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u2, mpc_dw3_Gu2);
mpc_dw3_v_copy_6(mpc_dw3_Vx3, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx3, mpc_dw3_rf3, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_tmp1_6, mpc_dw3_Gx2);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu2, mpc_dw3_tmp1_6, mpc_dw3_Gu2);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L2, mpc_dw3_Gu2, mpc_dw3_Ru2);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu2, mpc_dw3_Ru2, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx2, mpc_dw3_tmp1_6, mpc_dw3_Vx2);
/* Zeitschritt 1 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x1, mpc_dw3_Gx1);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u1, mpc_dw3_Gu1);
mpc_dw3_v_copy_6(mpc_dw3_Vx2, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx2, mpc_dw3_rf2, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_tmp1_6, mpc_dw3_Gx1);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu1, mpc_dw3_tmp1_6, mpc_dw3_Gu1);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L1, mpc_dw3_Gu1, mpc_dw3_Ru1);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu1, mpc_dw3_Ru1, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx1, mpc_dw3_tmp1_6, mpc_dw3_Vx1);
/* Zeitschritt 0 */
/* Gx und Gu */
mpc_dw3_v_copy_6(mpc_dw3_rrf0x0, mpc_dw3_Gx0);
mpc_dw3_v_copy_1(mpc_dw3_rrf0u0, mpc_dw3_Gu0);
mpc_dw3_v_copy_6(mpc_dw3_Vx1, mpc_dw3_tmp1_6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx1, mpc_dw3_rf1, mpc_dw3_tmp1_6);
mpc_dw3_mtv_sid42_sid2_6_6(mpc_dw3_fx0, mpc_dw3_tmp1_6, mpc_dw3_Gx0);
mpc_dw3_mtv_sid45_sid2_6_1(mpc_dw3_fu0, mpc_dw3_tmp1_6, mpc_dw3_Gu0);
/* Ru */
mpc_dw3_chol_solve_1_1(mpc_dw3_L0, mpc_dw3_Gu0, mpc_dw3_Ru0);
if(mpc_dw3_termcode > -1){return;}
/* Vx */
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_v_init0_6(mpc_dw3_tmp1_6);
mpc_dw3_mv_6_1(mpc_dw3_Gxu0, mpc_dw3_Ru0, mpc_dw3_tmp1_6);
mpc_dw3_vsub_6(mpc_dw3_Gx0, mpc_dw3_tmp1_6, mpc_dw3_Vx0);
/* Solve: Vorwärtsiteration */
/* dx0 */
mpc_dw3_v_copy_6(mpc_dw3_rf0, mpc_dw3_dx0);
/* Zeitschritt 0 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx0, mpc_dw3_dp0);
mpc_dw3_mv_6_6(mpc_dw3_Vxx0, mpc_dw3_dx0, mpc_dw3_dp0);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru0, mpc_dw3_du0);
mpc_dw3_mv_1_6(mpc_dw3_Rux0, mpc_dw3_dx0, mpc_dw3_du0);
mpc_dw3_v_turnsign_1(mpc_dw3_du0, mpc_dw3_du0);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf1, mpc_dw3_dx1);
mpc_dw3_mv_sid42_sid2_6_6(mpc_dw3_fx0, mpc_dw3_dx0, mpc_dw3_dx1);
mpc_dw3_mv_sid45_sid5_6_1(mpc_dw3_fu0, mpc_dw3_du0, mpc_dw3_dx1);
/* Zeitschritt 1 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx1, mpc_dw3_dp1);
mpc_dw3_mv_6_6(mpc_dw3_Vxx1, mpc_dw3_dx1, mpc_dw3_dp1);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru1, mpc_dw3_du1);
mpc_dw3_mv_1_6(mpc_dw3_Rux1, mpc_dw3_dx1, mpc_dw3_du1);
mpc_dw3_v_turnsign_1(mpc_dw3_du1, mpc_dw3_du1);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf2, mpc_dw3_dx2);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_dx1, mpc_dw3_dx2);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu1, mpc_dw3_du1, mpc_dw3_dx2);
/* Zeitschritt 2 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx2, mpc_dw3_dp2);
mpc_dw3_mv_6_6(mpc_dw3_Vxx2, mpc_dw3_dx2, mpc_dw3_dp2);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru2, mpc_dw3_du2);
mpc_dw3_mv_1_6(mpc_dw3_Rux2, mpc_dw3_dx2, mpc_dw3_du2);
mpc_dw3_v_turnsign_1(mpc_dw3_du2, mpc_dw3_du2);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf3, mpc_dw3_dx3);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_dx2, mpc_dw3_dx3);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu2, mpc_dw3_du2, mpc_dw3_dx3);
/* Zeitschritt 3 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx3, mpc_dw3_dp3);
mpc_dw3_mv_6_6(mpc_dw3_Vxx3, mpc_dw3_dx3, mpc_dw3_dp3);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru3, mpc_dw3_du3);
mpc_dw3_mv_1_6(mpc_dw3_Rux3, mpc_dw3_dx3, mpc_dw3_du3);
mpc_dw3_v_turnsign_1(mpc_dw3_du3, mpc_dw3_du3);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf4, mpc_dw3_dx4);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_dx3, mpc_dw3_dx4);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu3, mpc_dw3_du3, mpc_dw3_dx4);
/* Zeitschritt 4 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx4, mpc_dw3_dp4);
mpc_dw3_mv_6_6(mpc_dw3_Vxx4, mpc_dw3_dx4, mpc_dw3_dp4);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru4, mpc_dw3_du4);
mpc_dw3_mv_1_6(mpc_dw3_Rux4, mpc_dw3_dx4, mpc_dw3_du4);
mpc_dw3_v_turnsign_1(mpc_dw3_du4, mpc_dw3_du4);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf5, mpc_dw3_dx5);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_dx4, mpc_dw3_dx5);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu4, mpc_dw3_du4, mpc_dw3_dx5);
/* Zeitschritt 5 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx5, mpc_dw3_dp5);
mpc_dw3_mv_6_6(mpc_dw3_Vxx5, mpc_dw3_dx5, mpc_dw3_dp5);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru5, mpc_dw3_du5);
mpc_dw3_mv_1_6(mpc_dw3_Rux5, mpc_dw3_dx5, mpc_dw3_du5);
mpc_dw3_v_turnsign_1(mpc_dw3_du5, mpc_dw3_du5);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf6, mpc_dw3_dx6);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_dx5, mpc_dw3_dx6);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu5, mpc_dw3_du5, mpc_dw3_dx6);
/* Zeitschritt 6 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx6, mpc_dw3_dp6);
mpc_dw3_mv_6_6(mpc_dw3_Vxx6, mpc_dw3_dx6, mpc_dw3_dp6);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru6, mpc_dw3_du6);
mpc_dw3_mv_1_6(mpc_dw3_Rux6, mpc_dw3_dx6, mpc_dw3_du6);
mpc_dw3_v_turnsign_1(mpc_dw3_du6, mpc_dw3_du6);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf7, mpc_dw3_dx7);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_dx6, mpc_dw3_dx7);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu6, mpc_dw3_du6, mpc_dw3_dx7);
/* Zeitschritt 7 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx7, mpc_dw3_dp7);
mpc_dw3_mv_6_6(mpc_dw3_Vxx7, mpc_dw3_dx7, mpc_dw3_dp7);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru7, mpc_dw3_du7);
mpc_dw3_mv_1_6(mpc_dw3_Rux7, mpc_dw3_dx7, mpc_dw3_du7);
mpc_dw3_v_turnsign_1(mpc_dw3_du7, mpc_dw3_du7);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf8, mpc_dw3_dx8);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_dx7, mpc_dw3_dx8);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu7, mpc_dw3_du7, mpc_dw3_dx8);
/* Zeitschritt 8 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx8, mpc_dw3_dp8);
mpc_dw3_mv_6_6(mpc_dw3_Vxx8, mpc_dw3_dx8, mpc_dw3_dp8);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru8, mpc_dw3_du8);
mpc_dw3_mv_1_6(mpc_dw3_Rux8, mpc_dw3_dx8, mpc_dw3_du8);
mpc_dw3_v_turnsign_1(mpc_dw3_du8, mpc_dw3_du8);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf9, mpc_dw3_dx9);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_dx8, mpc_dw3_dx9);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu8, mpc_dw3_du8, mpc_dw3_dx9);
/* Zeitschritt 9 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx9, mpc_dw3_dp9);
mpc_dw3_mv_6_6(mpc_dw3_Vxx9, mpc_dw3_dx9, mpc_dw3_dp9);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru9, mpc_dw3_du9);
mpc_dw3_mv_1_6(mpc_dw3_Rux9, mpc_dw3_dx9, mpc_dw3_du9);
mpc_dw3_v_turnsign_1(mpc_dw3_du9, mpc_dw3_du9);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf10, mpc_dw3_dx10);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_dx9, mpc_dw3_dx10);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu9, mpc_dw3_du9, mpc_dw3_dx10);
/* Zeitschritt 10 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx10, mpc_dw3_dp10);
mpc_dw3_mv_6_6(mpc_dw3_Vxx10, mpc_dw3_dx10, mpc_dw3_dp10);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru10, mpc_dw3_du10);
mpc_dw3_mv_1_6(mpc_dw3_Rux10, mpc_dw3_dx10, mpc_dw3_du10);
mpc_dw3_v_turnsign_1(mpc_dw3_du10, mpc_dw3_du10);
/* dx */
mpc_dw3_v_copy_6(mpc_dw3_rf11, mpc_dw3_dx11);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx10, mpc_dw3_dx10, mpc_dw3_dx11);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu10, mpc_dw3_du10, mpc_dw3_dx11);
/* Zeitschritt 11 */
/* dp */
mpc_dw3_v_copy_6(mpc_dw3_Vx11, mpc_dw3_dp11);
mpc_dw3_mv_6_6(mpc_dw3_Vxx11, mpc_dw3_dx11, mpc_dw3_dp11);
/* du */
mpc_dw3_v_copy_1(mpc_dw3_Ru11, mpc_dw3_du11);
mpc_dw3_mv_1_6(mpc_dw3_Rux11, mpc_dw3_dx11, mpc_dw3_du11);
mpc_dw3_v_turnsign_1(mpc_dw3_du11, mpc_dw3_du11);
/* dx */
mpc_dw3_error_source = 0;

}


static void mpc_dw3_glqdocpip_rhs_starting_point_5()
{
/* Zeitschritt 0 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x0);
mpc_dw3_v_init0_1(mpc_dw3_rf0u0);
mpc_dw3_v_copy_4(mpc_dw3_f0s0, mpc_dw3_rf0s0);
mpc_dw3_v_copy_6(mpc_dw3_xinit, mpc_dw3_rf0);
mpc_dw3_v_copy_4(mpc_dw3_g0, mpc_dw3_rc0);
mpc_dw3_v_init0_4(mpc_dw3_rs0);
mpc_dw3_vsub_4(&mpc_dw3_nu0[4], mpc_dw3_s0, mpc_dw3_rs0);
mpc_dw3_vv_elemult_8(mpc_dw3_y0, mpc_dw3_nu0, mpc_dw3_rk0);
/* Zeitschritt 1 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x1);
mpc_dw3_v_init0_1(mpc_dw3_rf0u1);
mpc_dw3_v_copy_8(mpc_dw3_f0s1, mpc_dw3_rf0s1);
mpc_dw3_v_copy_6(mpc_dw3_f0, mpc_dw3_rf1);
mpc_dw3_v_copy_8(mpc_dw3_g1, mpc_dw3_rc1);
mpc_dw3_v_init0_8(mpc_dw3_rs1);
mpc_dw3_vsub_8(&mpc_dw3_nu1[8], mpc_dw3_s1, mpc_dw3_rs1);
mpc_dw3_vv_elemult_16(mpc_dw3_y1, mpc_dw3_nu1, mpc_dw3_rk1);
/* Zeitschritt 2 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x2);
mpc_dw3_v_init0_1(mpc_dw3_rf0u2);
mpc_dw3_v_copy_8(mpc_dw3_f0s2, mpc_dw3_rf0s2);
mpc_dw3_v_copy_6(mpc_dw3_f1, mpc_dw3_rf2);
mpc_dw3_v_copy_8(mpc_dw3_g2, mpc_dw3_rc2);
mpc_dw3_v_init0_8(mpc_dw3_rs2);
mpc_dw3_vsub_8(&mpc_dw3_nu2[8], mpc_dw3_s2, mpc_dw3_rs2);
mpc_dw3_vv_elemult_16(mpc_dw3_y2, mpc_dw3_nu2, mpc_dw3_rk2);
/* Zeitschritt 3 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x3);
mpc_dw3_v_init0_1(mpc_dw3_rf0u3);
mpc_dw3_v_copy_8(mpc_dw3_f0s3, mpc_dw3_rf0s3);
mpc_dw3_v_copy_6(mpc_dw3_f2, mpc_dw3_rf3);
mpc_dw3_v_copy_8(mpc_dw3_g3, mpc_dw3_rc3);
mpc_dw3_v_init0_8(mpc_dw3_rs3);
mpc_dw3_vsub_8(&mpc_dw3_nu3[8], mpc_dw3_s3, mpc_dw3_rs3);
mpc_dw3_vv_elemult_16(mpc_dw3_y3, mpc_dw3_nu3, mpc_dw3_rk3);
/* Zeitschritt 4 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x4);
mpc_dw3_v_init0_1(mpc_dw3_rf0u4);
mpc_dw3_v_copy_8(mpc_dw3_f0s4, mpc_dw3_rf0s4);
mpc_dw3_v_copy_6(mpc_dw3_f3, mpc_dw3_rf4);
mpc_dw3_v_copy_8(mpc_dw3_g4, mpc_dw3_rc4);
mpc_dw3_v_init0_8(mpc_dw3_rs4);
mpc_dw3_vsub_8(&mpc_dw3_nu4[8], mpc_dw3_s4, mpc_dw3_rs4);
mpc_dw3_vv_elemult_16(mpc_dw3_y4, mpc_dw3_nu4, mpc_dw3_rk4);
/* Zeitschritt 5 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x5);
mpc_dw3_v_init0_1(mpc_dw3_rf0u5);
mpc_dw3_v_copy_8(mpc_dw3_f0s5, mpc_dw3_rf0s5);
mpc_dw3_v_copy_6(mpc_dw3_f4, mpc_dw3_rf5);
mpc_dw3_v_copy_8(mpc_dw3_g5, mpc_dw3_rc5);
mpc_dw3_v_init0_8(mpc_dw3_rs5);
mpc_dw3_vsub_8(&mpc_dw3_nu5[8], mpc_dw3_s5, mpc_dw3_rs5);
mpc_dw3_vv_elemult_16(mpc_dw3_y5, mpc_dw3_nu5, mpc_dw3_rk5);
/* Zeitschritt 6 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x6);
mpc_dw3_v_init0_1(mpc_dw3_rf0u6);
mpc_dw3_v_copy_8(mpc_dw3_f0s6, mpc_dw3_rf0s6);
mpc_dw3_v_copy_6(mpc_dw3_f5, mpc_dw3_rf6);
mpc_dw3_v_copy_8(mpc_dw3_g6, mpc_dw3_rc6);
mpc_dw3_v_init0_8(mpc_dw3_rs6);
mpc_dw3_vsub_8(&mpc_dw3_nu6[8], mpc_dw3_s6, mpc_dw3_rs6);
mpc_dw3_vv_elemult_16(mpc_dw3_y6, mpc_dw3_nu6, mpc_dw3_rk6);
/* Zeitschritt 7 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x7);
mpc_dw3_v_init0_1(mpc_dw3_rf0u7);
mpc_dw3_v_copy_8(mpc_dw3_f0s7, mpc_dw3_rf0s7);
mpc_dw3_v_copy_6(mpc_dw3_f6, mpc_dw3_rf7);
mpc_dw3_v_copy_8(mpc_dw3_g7, mpc_dw3_rc7);
mpc_dw3_v_init0_8(mpc_dw3_rs7);
mpc_dw3_vsub_8(&mpc_dw3_nu7[8], mpc_dw3_s7, mpc_dw3_rs7);
mpc_dw3_vv_elemult_16(mpc_dw3_y7, mpc_dw3_nu7, mpc_dw3_rk7);
/* Zeitschritt 8 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x8);
mpc_dw3_v_init0_1(mpc_dw3_rf0u8);
mpc_dw3_v_copy_8(mpc_dw3_f0s8, mpc_dw3_rf0s8);
mpc_dw3_v_copy_6(mpc_dw3_f7, mpc_dw3_rf8);
mpc_dw3_v_copy_8(mpc_dw3_g8, mpc_dw3_rc8);
mpc_dw3_v_init0_8(mpc_dw3_rs8);
mpc_dw3_vsub_8(&mpc_dw3_nu8[8], mpc_dw3_s8, mpc_dw3_rs8);
mpc_dw3_vv_elemult_16(mpc_dw3_y8, mpc_dw3_nu8, mpc_dw3_rk8);
/* Zeitschritt 9 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x9);
mpc_dw3_v_init0_1(mpc_dw3_rf0u9);
mpc_dw3_v_copy_8(mpc_dw3_f0s9, mpc_dw3_rf0s9);
mpc_dw3_v_copy_6(mpc_dw3_f8, mpc_dw3_rf9);
mpc_dw3_v_copy_8(mpc_dw3_g9, mpc_dw3_rc9);
mpc_dw3_v_init0_8(mpc_dw3_rs9);
mpc_dw3_vsub_8(&mpc_dw3_nu9[8], mpc_dw3_s9, mpc_dw3_rs9);
mpc_dw3_vv_elemult_16(mpc_dw3_y9, mpc_dw3_nu9, mpc_dw3_rk9);
/* Zeitschritt 10 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x10);
mpc_dw3_v_init0_1(mpc_dw3_rf0u10);
mpc_dw3_v_copy_8(mpc_dw3_f0s10, mpc_dw3_rf0s10);
mpc_dw3_v_copy_6(mpc_dw3_f9, mpc_dw3_rf10);
mpc_dw3_v_copy_8(mpc_dw3_g10, mpc_dw3_rc10);
mpc_dw3_v_init0_8(mpc_dw3_rs10);
mpc_dw3_vsub_8(&mpc_dw3_nu10[8], mpc_dw3_s10, mpc_dw3_rs10);
mpc_dw3_vv_elemult_16(mpc_dw3_y10, mpc_dw3_nu10, mpc_dw3_rk10);
/* Zeitschritt 11 */
mpc_dw3_v_init0_6(mpc_dw3_rf0x11);
mpc_dw3_v_init0_1(mpc_dw3_rf0u11);
mpc_dw3_v_copy_4(mpc_dw3_f0s11, mpc_dw3_rf0s11);
mpc_dw3_v_copy_6(mpc_dw3_f10, mpc_dw3_rf11);
mpc_dw3_v_copy_4(mpc_dw3_g11, mpc_dw3_rc11);
mpc_dw3_v_init0_4(mpc_dw3_rs11);
mpc_dw3_vsub_4(&mpc_dw3_nu11[4], mpc_dw3_s11, mpc_dw3_rs11);
mpc_dw3_vv_elemult_8(mpc_dw3_y11, mpc_dw3_nu11, mpc_dw3_rk11);
}


static void mpc_dw3_glqdocpip_rhs_affine()
{
/* Zeitschritt 0 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x0, mpc_dw3_rf0x0);
mpc_dw3_mv_sid21_sid2_6_6(mpc_dw3_Hxx0, mpc_dw3_x0, mpc_dw3_rf0x0);
mpc_dw3_mv_sid24_sid5_6_1(mpc_dw3_Hxu0, mpc_dw3_u0, mpc_dw3_rf0x0);
mpc_dw3_vsub_6(mpc_dw3_rf0x0, mpc_dw3_p0, mpc_dw3_rf0x0);
mpc_dw3_mtv_sid42_sid2_6_6(mpc_dw3_fx0, mpc_dw3_p1, mpc_dw3_rf0x0);
mpc_dw3_mtv_sid51_sid15_4_6(mpc_dw3_gx0, mpc_dw3_y0, mpc_dw3_rf0x0);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u0, mpc_dw3_rf0u0);
mpc_dw3_mtv_sid24_sid2_6_1(mpc_dw3_Hxu0, mpc_dw3_x0, mpc_dw3_rf0u0);
mpc_dw3_mv_sid27_sid5_1_1(mpc_dw3_Huu0, mpc_dw3_u0, mpc_dw3_rf0u0);
mpc_dw3_mtv_sid45_sid2_6_1(mpc_dw3_fu0, mpc_dw3_p1, mpc_dw3_rf0u0);
mpc_dw3_mtv_sid54_sid15_4_1(mpc_dw3_gu0, mpc_dw3_y0, mpc_dw3_rf0u0);
/* rf0s */
mpc_dw3_v_copy_4(mpc_dw3_f0s0, mpc_dw3_rf0s0);
mpc_dw3_mv_sid30_sid18_4_4(mpc_dw3_Hss0, mpc_dw3_s0, mpc_dw3_rf0s0);
mpc_dw3_vsub_4(mpc_dw3_rf0s0, &mpc_dw3_y0[0], mpc_dw3_rf0s0);
mpc_dw3_vsub_4(mpc_dw3_rf0s0, &mpc_dw3_y0[4], mpc_dw3_rf0s0);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_xinit, mpc_dw3_rf0);
mpc_dw3_vsub_6(mpc_dw3_rf0, mpc_dw3_x0, mpc_dw3_rf0);
/* rc */
mpc_dw3_v_copy_4(mpc_dw3_g0, mpc_dw3_rc0);
mpc_dw3_mv_sid51_sid2_4_6(mpc_dw3_gx0, mpc_dw3_x0, mpc_dw3_rc0);
mpc_dw3_mv_sid54_sid5_4_1(mpc_dw3_gu0, mpc_dw3_u0, mpc_dw3_rc0);
mpc_dw3_vadd_4(mpc_dw3_rc0, mpc_dw3_nu0, mpc_dw3_rc0);
mpc_dw3_vsub_4(mpc_dw3_rc0, mpc_dw3_s0, mpc_dw3_rc0);
/* rs */
mpc_dw3_v_init0_4(mpc_dw3_rs0);
mpc_dw3_vsub_4(&mpc_dw3_nu0[4], mpc_dw3_s0, mpc_dw3_rs0);
/* rk */
mpc_dw3_vv_elemult_8(mpc_dw3_y0, mpc_dw3_nu0, mpc_dw3_rk0);
/* Zeitschritt 1 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x1, mpc_dw3_rf0x1);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx1, mpc_dw3_x1, mpc_dw3_rf0x1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu1, mpc_dw3_u1, mpc_dw3_rf0x1);
mpc_dw3_vsub_6(mpc_dw3_rf0x1, mpc_dw3_p1, mpc_dw3_rf0x1);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_p2, mpc_dw3_rf0x1);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx1, mpc_dw3_y1, mpc_dw3_rf0x1);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u1, mpc_dw3_rf0u1);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu1, mpc_dw3_x1, mpc_dw3_rf0u1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu1, mpc_dw3_u1, mpc_dw3_rf0u1);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu1, mpc_dw3_p2, mpc_dw3_rf0u1);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu1, mpc_dw3_y1, mpc_dw3_rf0u1);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s1, mpc_dw3_rf0s1);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss1, mpc_dw3_s1, mpc_dw3_rf0s1);
mpc_dw3_vsub_8(mpc_dw3_rf0s1, &mpc_dw3_y1[0], mpc_dw3_rf0s1);
mpc_dw3_vsub_8(mpc_dw3_rf0s1, &mpc_dw3_y1[8], mpc_dw3_rf0s1);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f0, mpc_dw3_rf1);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx0, mpc_dw3_x0, mpc_dw3_rf1);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu0, mpc_dw3_u0, mpc_dw3_rf1);
mpc_dw3_vsub_6(mpc_dw3_rf1, mpc_dw3_x1, mpc_dw3_rf1);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g1, mpc_dw3_rc1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx1, mpc_dw3_x1, mpc_dw3_rc1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu1, mpc_dw3_u1, mpc_dw3_rc1);
mpc_dw3_vadd_8(mpc_dw3_rc1, mpc_dw3_nu1, mpc_dw3_rc1);
mpc_dw3_vsub_8(mpc_dw3_rc1, mpc_dw3_s1, mpc_dw3_rc1);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs1);
mpc_dw3_vsub_8(&mpc_dw3_nu1[8], mpc_dw3_s1, mpc_dw3_rs1);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y1, mpc_dw3_nu1, mpc_dw3_rk1);
/* Zeitschritt 2 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x2, mpc_dw3_rf0x2);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx2, mpc_dw3_x2, mpc_dw3_rf0x2);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu2, mpc_dw3_u2, mpc_dw3_rf0x2);
mpc_dw3_vsub_6(mpc_dw3_rf0x2, mpc_dw3_p2, mpc_dw3_rf0x2);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_p3, mpc_dw3_rf0x2);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx2, mpc_dw3_y2, mpc_dw3_rf0x2);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u2, mpc_dw3_rf0u2);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu2, mpc_dw3_x2, mpc_dw3_rf0u2);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu2, mpc_dw3_u2, mpc_dw3_rf0u2);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu2, mpc_dw3_p3, mpc_dw3_rf0u2);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu2, mpc_dw3_y2, mpc_dw3_rf0u2);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s2, mpc_dw3_rf0s2);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss2, mpc_dw3_s2, mpc_dw3_rf0s2);
mpc_dw3_vsub_8(mpc_dw3_rf0s2, &mpc_dw3_y2[0], mpc_dw3_rf0s2);
mpc_dw3_vsub_8(mpc_dw3_rf0s2, &mpc_dw3_y2[8], mpc_dw3_rf0s2);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f1, mpc_dw3_rf2);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_x1, mpc_dw3_rf2);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu1, mpc_dw3_u1, mpc_dw3_rf2);
mpc_dw3_vsub_6(mpc_dw3_rf2, mpc_dw3_x2, mpc_dw3_rf2);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g2, mpc_dw3_rc2);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx2, mpc_dw3_x2, mpc_dw3_rc2);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu2, mpc_dw3_u2, mpc_dw3_rc2);
mpc_dw3_vadd_8(mpc_dw3_rc2, mpc_dw3_nu2, mpc_dw3_rc2);
mpc_dw3_vsub_8(mpc_dw3_rc2, mpc_dw3_s2, mpc_dw3_rc2);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs2);
mpc_dw3_vsub_8(&mpc_dw3_nu2[8], mpc_dw3_s2, mpc_dw3_rs2);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y2, mpc_dw3_nu2, mpc_dw3_rk2);
/* Zeitschritt 3 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x3, mpc_dw3_rf0x3);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx3, mpc_dw3_x3, mpc_dw3_rf0x3);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu3, mpc_dw3_u3, mpc_dw3_rf0x3);
mpc_dw3_vsub_6(mpc_dw3_rf0x3, mpc_dw3_p3, mpc_dw3_rf0x3);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_p4, mpc_dw3_rf0x3);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx3, mpc_dw3_y3, mpc_dw3_rf0x3);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u3, mpc_dw3_rf0u3);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu3, mpc_dw3_x3, mpc_dw3_rf0u3);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu3, mpc_dw3_u3, mpc_dw3_rf0u3);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu3, mpc_dw3_p4, mpc_dw3_rf0u3);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu3, mpc_dw3_y3, mpc_dw3_rf0u3);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s3, mpc_dw3_rf0s3);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss3, mpc_dw3_s3, mpc_dw3_rf0s3);
mpc_dw3_vsub_8(mpc_dw3_rf0s3, &mpc_dw3_y3[0], mpc_dw3_rf0s3);
mpc_dw3_vsub_8(mpc_dw3_rf0s3, &mpc_dw3_y3[8], mpc_dw3_rf0s3);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f2, mpc_dw3_rf3);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_x2, mpc_dw3_rf3);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu2, mpc_dw3_u2, mpc_dw3_rf3);
mpc_dw3_vsub_6(mpc_dw3_rf3, mpc_dw3_x3, mpc_dw3_rf3);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g3, mpc_dw3_rc3);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx3, mpc_dw3_x3, mpc_dw3_rc3);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu3, mpc_dw3_u3, mpc_dw3_rc3);
mpc_dw3_vadd_8(mpc_dw3_rc3, mpc_dw3_nu3, mpc_dw3_rc3);
mpc_dw3_vsub_8(mpc_dw3_rc3, mpc_dw3_s3, mpc_dw3_rc3);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs3);
mpc_dw3_vsub_8(&mpc_dw3_nu3[8], mpc_dw3_s3, mpc_dw3_rs3);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y3, mpc_dw3_nu3, mpc_dw3_rk3);
/* Zeitschritt 4 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x4, mpc_dw3_rf0x4);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx4, mpc_dw3_x4, mpc_dw3_rf0x4);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu4, mpc_dw3_u4, mpc_dw3_rf0x4);
mpc_dw3_vsub_6(mpc_dw3_rf0x4, mpc_dw3_p4, mpc_dw3_rf0x4);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_p5, mpc_dw3_rf0x4);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx4, mpc_dw3_y4, mpc_dw3_rf0x4);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u4, mpc_dw3_rf0u4);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu4, mpc_dw3_x4, mpc_dw3_rf0u4);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu4, mpc_dw3_u4, mpc_dw3_rf0u4);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu4, mpc_dw3_p5, mpc_dw3_rf0u4);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu4, mpc_dw3_y4, mpc_dw3_rf0u4);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s4, mpc_dw3_rf0s4);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss4, mpc_dw3_s4, mpc_dw3_rf0s4);
mpc_dw3_vsub_8(mpc_dw3_rf0s4, &mpc_dw3_y4[0], mpc_dw3_rf0s4);
mpc_dw3_vsub_8(mpc_dw3_rf0s4, &mpc_dw3_y4[8], mpc_dw3_rf0s4);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f3, mpc_dw3_rf4);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_x3, mpc_dw3_rf4);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu3, mpc_dw3_u3, mpc_dw3_rf4);
mpc_dw3_vsub_6(mpc_dw3_rf4, mpc_dw3_x4, mpc_dw3_rf4);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g4, mpc_dw3_rc4);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx4, mpc_dw3_x4, mpc_dw3_rc4);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu4, mpc_dw3_u4, mpc_dw3_rc4);
mpc_dw3_vadd_8(mpc_dw3_rc4, mpc_dw3_nu4, mpc_dw3_rc4);
mpc_dw3_vsub_8(mpc_dw3_rc4, mpc_dw3_s4, mpc_dw3_rc4);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs4);
mpc_dw3_vsub_8(&mpc_dw3_nu4[8], mpc_dw3_s4, mpc_dw3_rs4);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y4, mpc_dw3_nu4, mpc_dw3_rk4);
/* Zeitschritt 5 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x5, mpc_dw3_rf0x5);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx5, mpc_dw3_x5, mpc_dw3_rf0x5);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu5, mpc_dw3_u5, mpc_dw3_rf0x5);
mpc_dw3_vsub_6(mpc_dw3_rf0x5, mpc_dw3_p5, mpc_dw3_rf0x5);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_p6, mpc_dw3_rf0x5);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx5, mpc_dw3_y5, mpc_dw3_rf0x5);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u5, mpc_dw3_rf0u5);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu5, mpc_dw3_x5, mpc_dw3_rf0u5);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu5, mpc_dw3_u5, mpc_dw3_rf0u5);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu5, mpc_dw3_p6, mpc_dw3_rf0u5);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu5, mpc_dw3_y5, mpc_dw3_rf0u5);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s5, mpc_dw3_rf0s5);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss5, mpc_dw3_s5, mpc_dw3_rf0s5);
mpc_dw3_vsub_8(mpc_dw3_rf0s5, &mpc_dw3_y5[0], mpc_dw3_rf0s5);
mpc_dw3_vsub_8(mpc_dw3_rf0s5, &mpc_dw3_y5[8], mpc_dw3_rf0s5);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f4, mpc_dw3_rf5);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_x4, mpc_dw3_rf5);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu4, mpc_dw3_u4, mpc_dw3_rf5);
mpc_dw3_vsub_6(mpc_dw3_rf5, mpc_dw3_x5, mpc_dw3_rf5);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g5, mpc_dw3_rc5);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx5, mpc_dw3_x5, mpc_dw3_rc5);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu5, mpc_dw3_u5, mpc_dw3_rc5);
mpc_dw3_vadd_8(mpc_dw3_rc5, mpc_dw3_nu5, mpc_dw3_rc5);
mpc_dw3_vsub_8(mpc_dw3_rc5, mpc_dw3_s5, mpc_dw3_rc5);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs5);
mpc_dw3_vsub_8(&mpc_dw3_nu5[8], mpc_dw3_s5, mpc_dw3_rs5);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y5, mpc_dw3_nu5, mpc_dw3_rk5);
/* Zeitschritt 6 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x6, mpc_dw3_rf0x6);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx6, mpc_dw3_x6, mpc_dw3_rf0x6);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu6, mpc_dw3_u6, mpc_dw3_rf0x6);
mpc_dw3_vsub_6(mpc_dw3_rf0x6, mpc_dw3_p6, mpc_dw3_rf0x6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_p7, mpc_dw3_rf0x6);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx6, mpc_dw3_y6, mpc_dw3_rf0x6);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u6, mpc_dw3_rf0u6);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu6, mpc_dw3_x6, mpc_dw3_rf0u6);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu6, mpc_dw3_u6, mpc_dw3_rf0u6);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu6, mpc_dw3_p7, mpc_dw3_rf0u6);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu6, mpc_dw3_y6, mpc_dw3_rf0u6);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s6, mpc_dw3_rf0s6);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss6, mpc_dw3_s6, mpc_dw3_rf0s6);
mpc_dw3_vsub_8(mpc_dw3_rf0s6, &mpc_dw3_y6[0], mpc_dw3_rf0s6);
mpc_dw3_vsub_8(mpc_dw3_rf0s6, &mpc_dw3_y6[8], mpc_dw3_rf0s6);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f5, mpc_dw3_rf6);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_x5, mpc_dw3_rf6);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu5, mpc_dw3_u5, mpc_dw3_rf6);
mpc_dw3_vsub_6(mpc_dw3_rf6, mpc_dw3_x6, mpc_dw3_rf6);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g6, mpc_dw3_rc6);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx6, mpc_dw3_x6, mpc_dw3_rc6);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu6, mpc_dw3_u6, mpc_dw3_rc6);
mpc_dw3_vadd_8(mpc_dw3_rc6, mpc_dw3_nu6, mpc_dw3_rc6);
mpc_dw3_vsub_8(mpc_dw3_rc6, mpc_dw3_s6, mpc_dw3_rc6);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs6);
mpc_dw3_vsub_8(&mpc_dw3_nu6[8], mpc_dw3_s6, mpc_dw3_rs6);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y6, mpc_dw3_nu6, mpc_dw3_rk6);
/* Zeitschritt 7 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x7, mpc_dw3_rf0x7);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx7, mpc_dw3_x7, mpc_dw3_rf0x7);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu7, mpc_dw3_u7, mpc_dw3_rf0x7);
mpc_dw3_vsub_6(mpc_dw3_rf0x7, mpc_dw3_p7, mpc_dw3_rf0x7);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_p8, mpc_dw3_rf0x7);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx7, mpc_dw3_y7, mpc_dw3_rf0x7);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u7, mpc_dw3_rf0u7);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu7, mpc_dw3_x7, mpc_dw3_rf0u7);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu7, mpc_dw3_u7, mpc_dw3_rf0u7);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu7, mpc_dw3_p8, mpc_dw3_rf0u7);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu7, mpc_dw3_y7, mpc_dw3_rf0u7);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s7, mpc_dw3_rf0s7);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss7, mpc_dw3_s7, mpc_dw3_rf0s7);
mpc_dw3_vsub_8(mpc_dw3_rf0s7, &mpc_dw3_y7[0], mpc_dw3_rf0s7);
mpc_dw3_vsub_8(mpc_dw3_rf0s7, &mpc_dw3_y7[8], mpc_dw3_rf0s7);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f6, mpc_dw3_rf7);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_x6, mpc_dw3_rf7);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu6, mpc_dw3_u6, mpc_dw3_rf7);
mpc_dw3_vsub_6(mpc_dw3_rf7, mpc_dw3_x7, mpc_dw3_rf7);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g7, mpc_dw3_rc7);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx7, mpc_dw3_x7, mpc_dw3_rc7);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu7, mpc_dw3_u7, mpc_dw3_rc7);
mpc_dw3_vadd_8(mpc_dw3_rc7, mpc_dw3_nu7, mpc_dw3_rc7);
mpc_dw3_vsub_8(mpc_dw3_rc7, mpc_dw3_s7, mpc_dw3_rc7);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs7);
mpc_dw3_vsub_8(&mpc_dw3_nu7[8], mpc_dw3_s7, mpc_dw3_rs7);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y7, mpc_dw3_nu7, mpc_dw3_rk7);
/* Zeitschritt 8 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x8, mpc_dw3_rf0x8);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx8, mpc_dw3_x8, mpc_dw3_rf0x8);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu8, mpc_dw3_u8, mpc_dw3_rf0x8);
mpc_dw3_vsub_6(mpc_dw3_rf0x8, mpc_dw3_p8, mpc_dw3_rf0x8);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_p9, mpc_dw3_rf0x8);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx8, mpc_dw3_y8, mpc_dw3_rf0x8);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u8, mpc_dw3_rf0u8);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu8, mpc_dw3_x8, mpc_dw3_rf0u8);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu8, mpc_dw3_u8, mpc_dw3_rf0u8);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu8, mpc_dw3_p9, mpc_dw3_rf0u8);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu8, mpc_dw3_y8, mpc_dw3_rf0u8);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s8, mpc_dw3_rf0s8);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss8, mpc_dw3_s8, mpc_dw3_rf0s8);
mpc_dw3_vsub_8(mpc_dw3_rf0s8, &mpc_dw3_y8[0], mpc_dw3_rf0s8);
mpc_dw3_vsub_8(mpc_dw3_rf0s8, &mpc_dw3_y8[8], mpc_dw3_rf0s8);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f7, mpc_dw3_rf8);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_x7, mpc_dw3_rf8);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu7, mpc_dw3_u7, mpc_dw3_rf8);
mpc_dw3_vsub_6(mpc_dw3_rf8, mpc_dw3_x8, mpc_dw3_rf8);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g8, mpc_dw3_rc8);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx8, mpc_dw3_x8, mpc_dw3_rc8);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu8, mpc_dw3_u8, mpc_dw3_rc8);
mpc_dw3_vadd_8(mpc_dw3_rc8, mpc_dw3_nu8, mpc_dw3_rc8);
mpc_dw3_vsub_8(mpc_dw3_rc8, mpc_dw3_s8, mpc_dw3_rc8);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs8);
mpc_dw3_vsub_8(&mpc_dw3_nu8[8], mpc_dw3_s8, mpc_dw3_rs8);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y8, mpc_dw3_nu8, mpc_dw3_rk8);
/* Zeitschritt 9 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x9, mpc_dw3_rf0x9);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx9, mpc_dw3_x9, mpc_dw3_rf0x9);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu9, mpc_dw3_u9, mpc_dw3_rf0x9);
mpc_dw3_vsub_6(mpc_dw3_rf0x9, mpc_dw3_p9, mpc_dw3_rf0x9);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_p10, mpc_dw3_rf0x9);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx9, mpc_dw3_y9, mpc_dw3_rf0x9);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u9, mpc_dw3_rf0u9);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu9, mpc_dw3_x9, mpc_dw3_rf0u9);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu9, mpc_dw3_u9, mpc_dw3_rf0u9);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu9, mpc_dw3_p10, mpc_dw3_rf0u9);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu9, mpc_dw3_y9, mpc_dw3_rf0u9);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s9, mpc_dw3_rf0s9);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss9, mpc_dw3_s9, mpc_dw3_rf0s9);
mpc_dw3_vsub_8(mpc_dw3_rf0s9, &mpc_dw3_y9[0], mpc_dw3_rf0s9);
mpc_dw3_vsub_8(mpc_dw3_rf0s9, &mpc_dw3_y9[8], mpc_dw3_rf0s9);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f8, mpc_dw3_rf9);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_x8, mpc_dw3_rf9);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu8, mpc_dw3_u8, mpc_dw3_rf9);
mpc_dw3_vsub_6(mpc_dw3_rf9, mpc_dw3_x9, mpc_dw3_rf9);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g9, mpc_dw3_rc9);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx9, mpc_dw3_x9, mpc_dw3_rc9);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu9, mpc_dw3_u9, mpc_dw3_rc9);
mpc_dw3_vadd_8(mpc_dw3_rc9, mpc_dw3_nu9, mpc_dw3_rc9);
mpc_dw3_vsub_8(mpc_dw3_rc9, mpc_dw3_s9, mpc_dw3_rc9);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs9);
mpc_dw3_vsub_8(&mpc_dw3_nu9[8], mpc_dw3_s9, mpc_dw3_rs9);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y9, mpc_dw3_nu9, mpc_dw3_rk9);
/* Zeitschritt 10 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x10, mpc_dw3_rf0x10);
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx10, mpc_dw3_x10, mpc_dw3_rf0x10);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu10, mpc_dw3_u10, mpc_dw3_rf0x10);
mpc_dw3_vsub_6(mpc_dw3_rf0x10, mpc_dw3_p10, mpc_dw3_rf0x10);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx10, mpc_dw3_p11, mpc_dw3_rf0x10);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx10, mpc_dw3_y10, mpc_dw3_rf0x10);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u10, mpc_dw3_rf0u10);
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu10, mpc_dw3_x10, mpc_dw3_rf0u10);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu10, mpc_dw3_u10, mpc_dw3_rf0u10);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu10, mpc_dw3_p11, mpc_dw3_rf0u10);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu10, mpc_dw3_y10, mpc_dw3_rf0u10);
/* rf0s */
mpc_dw3_v_copy_8(mpc_dw3_f0s10, mpc_dw3_rf0s10);
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss10, mpc_dw3_s10, mpc_dw3_rf0s10);
mpc_dw3_vsub_8(mpc_dw3_rf0s10, &mpc_dw3_y10[0], mpc_dw3_rf0s10);
mpc_dw3_vsub_8(mpc_dw3_rf0s10, &mpc_dw3_y10[8], mpc_dw3_rf0s10);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f9, mpc_dw3_rf10);
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_x9, mpc_dw3_rf10);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu9, mpc_dw3_u9, mpc_dw3_rf10);
mpc_dw3_vsub_6(mpc_dw3_rf10, mpc_dw3_x10, mpc_dw3_rf10);
/* rc */
mpc_dw3_v_copy_8(mpc_dw3_g10, mpc_dw3_rc10);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx10, mpc_dw3_x10, mpc_dw3_rc10);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu10, mpc_dw3_u10, mpc_dw3_rc10);
mpc_dw3_vadd_8(mpc_dw3_rc10, mpc_dw3_nu10, mpc_dw3_rc10);
mpc_dw3_vsub_8(mpc_dw3_rc10, mpc_dw3_s10, mpc_dw3_rc10);
/* rs */
mpc_dw3_v_init0_8(mpc_dw3_rs10);
mpc_dw3_vsub_8(&mpc_dw3_nu10[8], mpc_dw3_s10, mpc_dw3_rs10);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_y10, mpc_dw3_nu10, mpc_dw3_rk10);
/* Zeitschritt 11 */
/* rf0x */
mpc_dw3_v_copy_6(mpc_dw3_f0x11, mpc_dw3_rf0x11);
mpc_dw3_mv_sid23_sid2_6_6(mpc_dw3_Hxx11, mpc_dw3_x11, mpc_dw3_rf0x11);
mpc_dw3_mv_sid26_sid5_6_1(mpc_dw3_Hxu11, mpc_dw3_u11, mpc_dw3_rf0x11);
mpc_dw3_vsub_6(mpc_dw3_rf0x11, mpc_dw3_p11, mpc_dw3_rf0x11);
mpc_dw3_mtv_sid53_sid17_4_6(mpc_dw3_gx11, mpc_dw3_y11, mpc_dw3_rf0x11);
/* rf0u */
mpc_dw3_v_copy_1(mpc_dw3_f0u11, mpc_dw3_rf0u11);
mpc_dw3_mtv_sid26_sid2_6_1(mpc_dw3_Hxu11, mpc_dw3_x11, mpc_dw3_rf0u11);
mpc_dw3_mv_sid29_sid5_1_1(mpc_dw3_Huu11, mpc_dw3_u11, mpc_dw3_rf0u11);
mpc_dw3_mtv_sid56_sid17_4_1(mpc_dw3_gu11, mpc_dw3_y11, mpc_dw3_rf0u11);
/* rf0s */
mpc_dw3_v_copy_4(mpc_dw3_f0s11, mpc_dw3_rf0s11);
mpc_dw3_mv_sid32_sid20_4_4(mpc_dw3_Hss11, mpc_dw3_s11, mpc_dw3_rf0s11);
mpc_dw3_vsub_4(mpc_dw3_rf0s11, &mpc_dw3_y11[0], mpc_dw3_rf0s11);
mpc_dw3_vsub_4(mpc_dw3_rf0s11, &mpc_dw3_y11[4], mpc_dw3_rf0s11);
/* rf */
mpc_dw3_v_copy_6(mpc_dw3_f10, mpc_dw3_rf11);
mpc_dw3_mv_sid44_sid2_6_6(mpc_dw3_fx10, mpc_dw3_x10, mpc_dw3_rf11);
mpc_dw3_mv_sid47_sid5_6_1(mpc_dw3_fu10, mpc_dw3_u10, mpc_dw3_rf11);
mpc_dw3_vsub_6(mpc_dw3_rf11, mpc_dw3_x11, mpc_dw3_rf11);
/* rc */
mpc_dw3_v_copy_4(mpc_dw3_g11, mpc_dw3_rc11);
mpc_dw3_mv_sid53_sid2_4_6(mpc_dw3_gx11, mpc_dw3_x11, mpc_dw3_rc11);
mpc_dw3_mv_sid56_sid5_4_1(mpc_dw3_gu11, mpc_dw3_u11, mpc_dw3_rc11);
mpc_dw3_vadd_4(mpc_dw3_rc11, mpc_dw3_nu11, mpc_dw3_rc11);
mpc_dw3_vsub_4(mpc_dw3_rc11, mpc_dw3_s11, mpc_dw3_rc11);
/* rs */
mpc_dw3_v_init0_4(mpc_dw3_rs11);
mpc_dw3_vsub_4(&mpc_dw3_nu11[4], mpc_dw3_s11, mpc_dw3_rs11);
/* rk */
mpc_dw3_vv_elemult_8(mpc_dw3_y11, mpc_dw3_nu11, mpc_dw3_rk11);
}


static void mpc_dw3_glqdocpip_rhs_corrector()
{
/* Zeitschritt 0 */
/* rk_corr */
mpc_dw3_vv_elemult_8(mpc_dw3_dy0, mpc_dw3_dnu0, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_rk0, mpc_dw3_tmp1_8, mpc_dw3_rk0);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_8(mpc_dw3_tmp1_1, mpc_dw3_tmp1_8, mpc_dw3_tmp2_8);
mpc_dw3_vsub_8(mpc_dw3_rk0, mpc_dw3_tmp2_8, mpc_dw3_rk0);
/* Zeitschritt 1 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy1, mpc_dw3_dnu1, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk1, mpc_dw3_tmp1_16, mpc_dw3_rk1);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vsub_16(mpc_dw3_rk1, mpc_dw3_tmp2_16, mpc_dw3_rk1);
/* Zeitschritt 2 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy2, mpc_dw3_dnu2, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_rk2, mpc_dw3_tmp2_16, mpc_dw3_rk2);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vsub_16(mpc_dw3_rk2, mpc_dw3_tmp1_16, mpc_dw3_rk2);
/* Zeitschritt 3 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy3, mpc_dw3_dnu3, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk3, mpc_dw3_tmp1_16, mpc_dw3_rk3);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vsub_16(mpc_dw3_rk3, mpc_dw3_tmp2_16, mpc_dw3_rk3);
/* Zeitschritt 4 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy4, mpc_dw3_dnu4, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_rk4, mpc_dw3_tmp2_16, mpc_dw3_rk4);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vsub_16(mpc_dw3_rk4, mpc_dw3_tmp1_16, mpc_dw3_rk4);
/* Zeitschritt 5 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy5, mpc_dw3_dnu5, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk5, mpc_dw3_tmp1_16, mpc_dw3_rk5);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vsub_16(mpc_dw3_rk5, mpc_dw3_tmp2_16, mpc_dw3_rk5);
/* Zeitschritt 6 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy6, mpc_dw3_dnu6, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_rk6, mpc_dw3_tmp2_16, mpc_dw3_rk6);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vsub_16(mpc_dw3_rk6, mpc_dw3_tmp1_16, mpc_dw3_rk6);
/* Zeitschritt 7 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy7, mpc_dw3_dnu7, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk7, mpc_dw3_tmp1_16, mpc_dw3_rk7);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vsub_16(mpc_dw3_rk7, mpc_dw3_tmp2_16, mpc_dw3_rk7);
/* Zeitschritt 8 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy8, mpc_dw3_dnu8, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_rk8, mpc_dw3_tmp2_16, mpc_dw3_rk8);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vsub_16(mpc_dw3_rk8, mpc_dw3_tmp1_16, mpc_dw3_rk8);
/* Zeitschritt 9 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy9, mpc_dw3_dnu9, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk9, mpc_dw3_tmp1_16, mpc_dw3_rk9);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vsub_16(mpc_dw3_rk9, mpc_dw3_tmp2_16, mpc_dw3_rk9);
/* Zeitschritt 10 */
/* rk_corr */
mpc_dw3_vv_elemult_16(mpc_dw3_dy10, mpc_dw3_dnu10, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_rk10, mpc_dw3_tmp2_16, mpc_dw3_rk10);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_16(mpc_dw3_tmp1_1, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vsub_16(mpc_dw3_rk10, mpc_dw3_tmp1_16, mpc_dw3_rk10);
/* Zeitschritt 11 */
/* rk_corr */
mpc_dw3_vv_elemult_8(mpc_dw3_dy11, mpc_dw3_dnu11, mpc_dw3_tmp2_8);
mpc_dw3_vadd_8(mpc_dw3_rk11, mpc_dw3_tmp2_8, mpc_dw3_rk11);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8);
mpc_dw3_vv_elemult_1(mpc_dw3_sigma, mpc_dw3_mu, mpc_dw3_tmp1_1);
mpc_dw3_sv_8(mpc_dw3_tmp1_1, mpc_dw3_tmp2_8, mpc_dw3_tmp1_8);
mpc_dw3_vsub_8(mpc_dw3_rk11, mpc_dw3_tmp1_8, mpc_dw3_rk11);
}


static void mpc_dw3_glqdocpip_rhs_reduced()
{
mpc_dw3_error_source = 3;
/* Zeitschritt 0 */
/* rhsxs */
mpc_dw3_v_init0_4(mpc_dw3_rhsxs0);
mpc_dw3_vsub_4(mpc_dw3_rc0, mpc_dw3_rs0, mpc_dw3_rhsxs0);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk0[0], &mpc_dw3_y0[0], mpc_dw3_tmp1_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_4(mpc_dw3_rhsxs0, mpc_dw3_tmp1_4_1, mpc_dw3_rhsxs0);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk0[4], &mpc_dw3_y0[4], mpc_dw3_tmp1_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_rhsxs0, mpc_dw3_tmp1_4_1, mpc_dw3_rhsxs0);
mpc_dw3_v_init0_4(mpc_dw3_tmp2_4_1);
mpc_dw3_vsub_4(mpc_dw3_rs0, mpc_dw3_tmp1_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_v_copy_4(mpc_dw3_rf0s0, mpc_dw3_tmp1_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss0, mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp2_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss0, mpc_dw3_tmp2_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_y0[4], &mpc_dw3_nu0[4], mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_rhsxs0, mpc_dw3_tmp1_4_1, mpc_dw3_rhsxs0);
/* yny */
mpc_dw3_v_init0_4(mpc_dw3_yny0);
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp2_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss0, mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_y0[4], &mpc_dw3_nu0[4], mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp2_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_4(&mpc_dw3_nu0[0], &mpc_dw3_y0[0], mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1, &mpc_dw3_yny0[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_4(mpc_dw3_rhsxs0, mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_yny0, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x0, mpc_dw3_rrf0x0);
mpc_dw3_mtv_sid51_sid15_4_6(mpc_dw3_gx0, mpc_dw3_tmp2_4_1, mpc_dw3_rrf0x0);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u0, mpc_dw3_rrf0u0);
mpc_dw3_mtv_sid54_sid15_4_1(mpc_dw3_gu0, mpc_dw3_tmp2_4_1, mpc_dw3_rrf0u0);
/* Zeitschritt 1 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs1);
mpc_dw3_vsub_8(mpc_dw3_rc1, mpc_dw3_rs1, mpc_dw3_rhsxs1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk1[0], &mpc_dw3_y1[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs1, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk1[8], &mpc_dw3_y1[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs1, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s1, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y1[8], &mpc_dw3_nu1[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs1, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs1);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y1[8], &mpc_dw3_nu1[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu1[0], &mpc_dw3_y1[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, &mpc_dw3_yny1[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x1, mpc_dw3_rrf0x1);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx1, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0x1);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u1, mpc_dw3_rrf0u1);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu1, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0u1);
/* Zeitschritt 2 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs2);
mpc_dw3_vsub_8(mpc_dw3_rc2, mpc_dw3_rs2, mpc_dw3_rhsxs2);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk2[0], &mpc_dw3_y2[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs2, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs2);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk2[8], &mpc_dw3_y2[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs2, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs2);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs2, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s2, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss2, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss2, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y2[8], &mpc_dw3_nu2[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs2, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs2);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny2);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss2, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y2[8], &mpc_dw3_nu2[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu2[0], &mpc_dw3_y2[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_yny2[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs2, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny2, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x2, mpc_dw3_rrf0x2);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx2, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0x2);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u2, mpc_dw3_rrf0u2);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu2, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0u2);
/* Zeitschritt 3 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs3);
mpc_dw3_vsub_8(mpc_dw3_rc3, mpc_dw3_rs3, mpc_dw3_rhsxs3);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk3[0], &mpc_dw3_y3[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs3, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs3);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk3[8], &mpc_dw3_y3[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs3, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs3);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs3, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s3, mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss3, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss3, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y3[8], &mpc_dw3_nu3[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs3, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs3);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny3);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss3, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y3[8], &mpc_dw3_nu3[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu3[0], &mpc_dw3_y3[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, &mpc_dw3_yny3[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs3, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny3, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x3, mpc_dw3_rrf0x3);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx3, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0x3);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u3, mpc_dw3_rrf0u3);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu3, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0u3);
/* Zeitschritt 4 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs4);
mpc_dw3_vsub_8(mpc_dw3_rc4, mpc_dw3_rs4, mpc_dw3_rhsxs4);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk4[0], &mpc_dw3_y4[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs4, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs4);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk4[8], &mpc_dw3_y4[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs4, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs4);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs4, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s4, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss4, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss4, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y4[8], &mpc_dw3_nu4[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs4, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs4);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny4);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss4, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y4[8], &mpc_dw3_nu4[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu4[0], &mpc_dw3_y4[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, &mpc_dw3_yny4[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs4, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny4, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x4, mpc_dw3_rrf0x4);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx4, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0x4);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u4, mpc_dw3_rrf0u4);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu4, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0u4);
/* Zeitschritt 5 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs5);
mpc_dw3_vsub_8(mpc_dw3_rc5, mpc_dw3_rs5, mpc_dw3_rhsxs5);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk5[0], &mpc_dw3_y5[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs5, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs5);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk5[8], &mpc_dw3_y5[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs5, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs5);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs5, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s5, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss5, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss5, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y5[8], &mpc_dw3_nu5[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs5, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs5);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny5);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss5, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y5[8], &mpc_dw3_nu5[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu5[0], &mpc_dw3_y5[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_yny5[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs5, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny5, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x5, mpc_dw3_rrf0x5);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx5, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0x5);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u5, mpc_dw3_rrf0u5);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu5, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0u5);
/* Zeitschritt 6 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs6);
mpc_dw3_vsub_8(mpc_dw3_rc6, mpc_dw3_rs6, mpc_dw3_rhsxs6);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk6[0], &mpc_dw3_y6[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs6, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs6);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk6[8], &mpc_dw3_y6[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs6, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs6);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs6, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s6, mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss6, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss6, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y6[8], &mpc_dw3_nu6[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs6, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs6);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny6);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss6, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y6[8], &mpc_dw3_nu6[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu6[0], &mpc_dw3_y6[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, &mpc_dw3_yny6[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs6, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny6, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x6, mpc_dw3_rrf0x6);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx6, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0x6);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u6, mpc_dw3_rrf0u6);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu6, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0u6);
/* Zeitschritt 7 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs7);
mpc_dw3_vsub_8(mpc_dw3_rc7, mpc_dw3_rs7, mpc_dw3_rhsxs7);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk7[0], &mpc_dw3_y7[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs7, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs7);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk7[8], &mpc_dw3_y7[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs7, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs7);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs7, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s7, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss7, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss7, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y7[8], &mpc_dw3_nu7[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs7, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs7);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny7);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss7, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y7[8], &mpc_dw3_nu7[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu7[0], &mpc_dw3_y7[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, &mpc_dw3_yny7[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs7, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny7, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x7, mpc_dw3_rrf0x7);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx7, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0x7);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u7, mpc_dw3_rrf0u7);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu7, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0u7);
/* Zeitschritt 8 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs8);
mpc_dw3_vsub_8(mpc_dw3_rc8, mpc_dw3_rs8, mpc_dw3_rhsxs8);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk8[0], &mpc_dw3_y8[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs8, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs8);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk8[8], &mpc_dw3_y8[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs8, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs8);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs8, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s8, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss8, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss8, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y8[8], &mpc_dw3_nu8[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs8, mpc_dw3_tmp2_8_1, mpc_dw3_rhsxs8);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny8);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss8, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y8[8], &mpc_dw3_nu8[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu8[0], &mpc_dw3_y8[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_yny8[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs8, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny8, mpc_dw3_tmp3_8_1, mpc_dw3_tmp3_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x8, mpc_dw3_rrf0x8);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx8, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0x8);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u8, mpc_dw3_rrf0u8);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu8, mpc_dw3_tmp3_8_1, mpc_dw3_rrf0u8);
/* Zeitschritt 9 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs9);
mpc_dw3_vsub_8(mpc_dw3_rc9, mpc_dw3_rs9, mpc_dw3_rhsxs9);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk9[0], &mpc_dw3_y9[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs9, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs9);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk9[8], &mpc_dw3_y9[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs9, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs9);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs9, mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s9, mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss9, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss9, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y9[8], &mpc_dw3_nu9[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs9, mpc_dw3_tmp3_8_1, mpc_dw3_rhsxs9);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny9);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss9, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y9[8], &mpc_dw3_nu9[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu9[0], &mpc_dw3_y9[0], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1, &mpc_dw3_yny9[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs9, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny9, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x9, mpc_dw3_rrf0x9);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx9, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0x9);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u9, mpc_dw3_rrf0u9);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu9, mpc_dw3_tmp1_8_1, mpc_dw3_rrf0u9);
/* Zeitschritt 10 */
/* rhsxs */
mpc_dw3_v_init0_8(mpc_dw3_rhsxs10);
mpc_dw3_vsub_8(mpc_dw3_rc10, mpc_dw3_rs10, mpc_dw3_rhsxs10);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk10[0], &mpc_dw3_y10[0], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rhsxs10, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs10);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk10[8], &mpc_dw3_y10[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs10, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs10);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_rs10, mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s10, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss10, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss10, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y10[8], &mpc_dw3_nu10[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_rhsxs10, mpc_dw3_tmp1_8_1, mpc_dw3_rhsxs10);
/* yny */
mpc_dw3_v_init0_8(mpc_dw3_yny10);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss10, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_y10[8], &mpc_dw3_nu10[8], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_8(&mpc_dw3_nu10[0], &mpc_dw3_y10[0], mpc_dw3_tmp3_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, &mpc_dw3_yny10[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_8(mpc_dw3_rhsxs10, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny10, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x10, mpc_dw3_rrf0x10);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx10, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0x10);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u10, mpc_dw3_rrf0u10);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu10, mpc_dw3_tmp2_8_1, mpc_dw3_rrf0u10);
/* Zeitschritt 11 */
/* rhsxs */
mpc_dw3_v_init0_4(mpc_dw3_rhsxs11);
mpc_dw3_vsub_4(mpc_dw3_rc11, mpc_dw3_rs11, mpc_dw3_rhsxs11);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk11[0], &mpc_dw3_y11[0], mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_4(mpc_dw3_rhsxs11, mpc_dw3_tmp2_4_1, mpc_dw3_rhsxs11);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk11[4], &mpc_dw3_y11[4], mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_rhsxs11, mpc_dw3_tmp2_4_1, mpc_dw3_rhsxs11);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_vsub_4(mpc_dw3_rs11, mpc_dw3_tmp2_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_v_copy_4(mpc_dw3_rf0s11, mpc_dw3_tmp2_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss11, mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp1_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss11, mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_y11[4], &mpc_dw3_nu11[4], mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp2_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_rhsxs11, mpc_dw3_tmp2_4_1, mpc_dw3_rhsxs11);
/* yny */
mpc_dw3_v_init0_4(mpc_dw3_yny11);
mpc_dw3_v_init1_4(mpc_dw3_tmp1_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss11, mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_y11[4], &mpc_dw3_nu11[4], mpc_dw3_tmp1_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elediv_4(&mpc_dw3_nu11[0], &mpc_dw3_y11[0], mpc_dw3_tmp1_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vadd_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, &mpc_dw3_yny11[0]);
if(mpc_dw3_termcode > -1){return;}
/* v1 */
mpc_dw3_v_copy_4(mpc_dw3_rhsxs11, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_yny11, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
/* rrf0x */
mpc_dw3_v_copy_6(mpc_dw3_rf0x11, mpc_dw3_rrf0x11);
mpc_dw3_mtv_sid53_sid17_4_6(mpc_dw3_gx11, mpc_dw3_tmp3_4_1, mpc_dw3_rrf0x11);
/* rrf0u */
mpc_dw3_v_copy_1(mpc_dw3_rf0u11, mpc_dw3_rrf0u11);
mpc_dw3_mtv_sid56_sid17_4_1(mpc_dw3_gu11, mpc_dw3_tmp3_4_1, mpc_dw3_rrf0u11);
mpc_dw3_error_source = 0;
}


static void mpc_dw3_glqdocpip_rhs_iter_ref()
{
/* Zeitschritt 0 */
/* rf0x */
mpc_dw3_mv_sid21_sid2_6_6(mpc_dw3_Hxx0, mpc_dw3_dx0, mpc_dw3_rf0x0);
mpc_dw3_mv_sid24_sid5_6_1(mpc_dw3_Hxu0, mpc_dw3_du0, mpc_dw3_rf0x0);
mpc_dw3_vsub_6(mpc_dw3_rf0x0, mpc_dw3_dp0, mpc_dw3_rf0x0);
mpc_dw3_mtv_sid42_sid2_6_6(mpc_dw3_fx0, mpc_dw3_dp1, mpc_dw3_rf0x0);
mpc_dw3_mtv_sid51_sid15_4_6(mpc_dw3_gx0, mpc_dw3_dy0, mpc_dw3_rf0x0);
/* rf0u */
mpc_dw3_mtv_sid24_sid2_6_1(mpc_dw3_Hxu0, mpc_dw3_dx0, mpc_dw3_rf0u0);
mpc_dw3_mv_sid27_sid5_1_1(mpc_dw3_Huu0, mpc_dw3_du0, mpc_dw3_rf0u0);
mpc_dw3_mtv_sid45_sid2_6_1(mpc_dw3_fu0, mpc_dw3_dp1, mpc_dw3_rf0u0);
mpc_dw3_mtv_sid54_sid15_4_1(mpc_dw3_gu0, mpc_dw3_dy0, mpc_dw3_rf0u0);
/* rf0s */
mpc_dw3_mv_sid30_sid18_4_4(mpc_dw3_Hss0, mpc_dw3_ds0, mpc_dw3_rf0s0);
mpc_dw3_vsub_4(mpc_dw3_rf0s0, &mpc_dw3_dy0[0], mpc_dw3_rf0s0);
mpc_dw3_vsub_4(mpc_dw3_rf0s0, &mpc_dw3_dy0[4], mpc_dw3_rf0s0);
/* rf */
mpc_dw3_vsub_6(mpc_dw3_rf0, mpc_dw3_dx0, mpc_dw3_rf0);
/* rc */
mpc_dw3_mv_sid51_sid2_4_6(mpc_dw3_gx0, mpc_dw3_dx0, mpc_dw3_rc0);
mpc_dw3_mv_sid54_sid5_4_1(mpc_dw3_gu0, mpc_dw3_du0, mpc_dw3_rc0);
mpc_dw3_vadd_4(mpc_dw3_rc0, mpc_dw3_dnu0, mpc_dw3_rc0);
mpc_dw3_vsub_4(mpc_dw3_rc0, mpc_dw3_ds0, mpc_dw3_rc0);
/* rs */
mpc_dw3_vadd_4(mpc_dw3_rs0, &mpc_dw3_dnu0[4], mpc_dw3_rs0);
mpc_dw3_vsub_4(mpc_dw3_rs0, mpc_dw3_ds0, mpc_dw3_rs0);
/* rk */
mpc_dw3_vv_elemult_8(mpc_dw3_dy0, mpc_dw3_nu0, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_rk0, mpc_dw3_tmp1_8, mpc_dw3_rk0);
mpc_dw3_vv_elemult_8(mpc_dw3_dnu0, mpc_dw3_y0, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_rk0, mpc_dw3_tmp1_8, mpc_dw3_rk0);
/* Zeitschritt 1 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx1, mpc_dw3_dx1, mpc_dw3_rf0x1);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu1, mpc_dw3_du1, mpc_dw3_rf0x1);
mpc_dw3_vsub_6(mpc_dw3_rf0x1, mpc_dw3_dp1, mpc_dw3_rf0x1);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_dp2, mpc_dw3_rf0x1);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx1, mpc_dw3_dy1, mpc_dw3_rf0x1);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu1, mpc_dw3_dx1, mpc_dw3_rf0u1);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu1, mpc_dw3_du1, mpc_dw3_rf0u1);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu1, mpc_dw3_dp2, mpc_dw3_rf0u1);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu1, mpc_dw3_dy1, mpc_dw3_rf0u1);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss1, mpc_dw3_ds1, mpc_dw3_rf0s1);
mpc_dw3_vsub_8(mpc_dw3_rf0s1, &mpc_dw3_dy1[0], mpc_dw3_rf0s1);
mpc_dw3_vsub_8(mpc_dw3_rf0s1, &mpc_dw3_dy1[8], mpc_dw3_rf0s1);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx0, mpc_dw3_dx0, mpc_dw3_rf1);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu0, mpc_dw3_du0, mpc_dw3_rf1);
mpc_dw3_vsub_6(mpc_dw3_rf1, mpc_dw3_dx1, mpc_dw3_rf1);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx1, mpc_dw3_dx1, mpc_dw3_rc1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu1, mpc_dw3_du1, mpc_dw3_rc1);
mpc_dw3_vadd_8(mpc_dw3_rc1, mpc_dw3_dnu1, mpc_dw3_rc1);
mpc_dw3_vsub_8(mpc_dw3_rc1, mpc_dw3_ds1, mpc_dw3_rc1);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs1, &mpc_dw3_dnu1[8], mpc_dw3_rs1);
mpc_dw3_vsub_8(mpc_dw3_rs1, mpc_dw3_ds1, mpc_dw3_rs1);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy1, mpc_dw3_nu1, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk1, mpc_dw3_tmp1_16, mpc_dw3_rk1);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu1, mpc_dw3_y1, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk1, mpc_dw3_tmp1_16, mpc_dw3_rk1);
/* Zeitschritt 2 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx2, mpc_dw3_dx2, mpc_dw3_rf0x2);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu2, mpc_dw3_du2, mpc_dw3_rf0x2);
mpc_dw3_vsub_6(mpc_dw3_rf0x2, mpc_dw3_dp2, mpc_dw3_rf0x2);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_dp3, mpc_dw3_rf0x2);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx2, mpc_dw3_dy2, mpc_dw3_rf0x2);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu2, mpc_dw3_dx2, mpc_dw3_rf0u2);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu2, mpc_dw3_du2, mpc_dw3_rf0u2);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu2, mpc_dw3_dp3, mpc_dw3_rf0u2);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu2, mpc_dw3_dy2, mpc_dw3_rf0u2);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss2, mpc_dw3_ds2, mpc_dw3_rf0s2);
mpc_dw3_vsub_8(mpc_dw3_rf0s2, &mpc_dw3_dy2[0], mpc_dw3_rf0s2);
mpc_dw3_vsub_8(mpc_dw3_rf0s2, &mpc_dw3_dy2[8], mpc_dw3_rf0s2);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx1, mpc_dw3_dx1, mpc_dw3_rf2);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu1, mpc_dw3_du1, mpc_dw3_rf2);
mpc_dw3_vsub_6(mpc_dw3_rf2, mpc_dw3_dx2, mpc_dw3_rf2);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx2, mpc_dw3_dx2, mpc_dw3_rc2);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu2, mpc_dw3_du2, mpc_dw3_rc2);
mpc_dw3_vadd_8(mpc_dw3_rc2, mpc_dw3_dnu2, mpc_dw3_rc2);
mpc_dw3_vsub_8(mpc_dw3_rc2, mpc_dw3_ds2, mpc_dw3_rc2);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs2, &mpc_dw3_dnu2[8], mpc_dw3_rs2);
mpc_dw3_vsub_8(mpc_dw3_rs2, mpc_dw3_ds2, mpc_dw3_rs2);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy2, mpc_dw3_nu2, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk2, mpc_dw3_tmp1_16, mpc_dw3_rk2);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu2, mpc_dw3_y2, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk2, mpc_dw3_tmp1_16, mpc_dw3_rk2);
/* Zeitschritt 3 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx3, mpc_dw3_dx3, mpc_dw3_rf0x3);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu3, mpc_dw3_du3, mpc_dw3_rf0x3);
mpc_dw3_vsub_6(mpc_dw3_rf0x3, mpc_dw3_dp3, mpc_dw3_rf0x3);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_dp4, mpc_dw3_rf0x3);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx3, mpc_dw3_dy3, mpc_dw3_rf0x3);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu3, mpc_dw3_dx3, mpc_dw3_rf0u3);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu3, mpc_dw3_du3, mpc_dw3_rf0u3);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu3, mpc_dw3_dp4, mpc_dw3_rf0u3);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu3, mpc_dw3_dy3, mpc_dw3_rf0u3);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss3, mpc_dw3_ds3, mpc_dw3_rf0s3);
mpc_dw3_vsub_8(mpc_dw3_rf0s3, &mpc_dw3_dy3[0], mpc_dw3_rf0s3);
mpc_dw3_vsub_8(mpc_dw3_rf0s3, &mpc_dw3_dy3[8], mpc_dw3_rf0s3);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx2, mpc_dw3_dx2, mpc_dw3_rf3);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu2, mpc_dw3_du2, mpc_dw3_rf3);
mpc_dw3_vsub_6(mpc_dw3_rf3, mpc_dw3_dx3, mpc_dw3_rf3);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx3, mpc_dw3_dx3, mpc_dw3_rc3);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu3, mpc_dw3_du3, mpc_dw3_rc3);
mpc_dw3_vadd_8(mpc_dw3_rc3, mpc_dw3_dnu3, mpc_dw3_rc3);
mpc_dw3_vsub_8(mpc_dw3_rc3, mpc_dw3_ds3, mpc_dw3_rc3);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs3, &mpc_dw3_dnu3[8], mpc_dw3_rs3);
mpc_dw3_vsub_8(mpc_dw3_rs3, mpc_dw3_ds3, mpc_dw3_rs3);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy3, mpc_dw3_nu3, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk3, mpc_dw3_tmp1_16, mpc_dw3_rk3);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu3, mpc_dw3_y3, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk3, mpc_dw3_tmp1_16, mpc_dw3_rk3);
/* Zeitschritt 4 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx4, mpc_dw3_dx4, mpc_dw3_rf0x4);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu4, mpc_dw3_du4, mpc_dw3_rf0x4);
mpc_dw3_vsub_6(mpc_dw3_rf0x4, mpc_dw3_dp4, mpc_dw3_rf0x4);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_dp5, mpc_dw3_rf0x4);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx4, mpc_dw3_dy4, mpc_dw3_rf0x4);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu4, mpc_dw3_dx4, mpc_dw3_rf0u4);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu4, mpc_dw3_du4, mpc_dw3_rf0u4);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu4, mpc_dw3_dp5, mpc_dw3_rf0u4);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu4, mpc_dw3_dy4, mpc_dw3_rf0u4);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss4, mpc_dw3_ds4, mpc_dw3_rf0s4);
mpc_dw3_vsub_8(mpc_dw3_rf0s4, &mpc_dw3_dy4[0], mpc_dw3_rf0s4);
mpc_dw3_vsub_8(mpc_dw3_rf0s4, &mpc_dw3_dy4[8], mpc_dw3_rf0s4);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx3, mpc_dw3_dx3, mpc_dw3_rf4);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu3, mpc_dw3_du3, mpc_dw3_rf4);
mpc_dw3_vsub_6(mpc_dw3_rf4, mpc_dw3_dx4, mpc_dw3_rf4);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx4, mpc_dw3_dx4, mpc_dw3_rc4);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu4, mpc_dw3_du4, mpc_dw3_rc4);
mpc_dw3_vadd_8(mpc_dw3_rc4, mpc_dw3_dnu4, mpc_dw3_rc4);
mpc_dw3_vsub_8(mpc_dw3_rc4, mpc_dw3_ds4, mpc_dw3_rc4);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs4, &mpc_dw3_dnu4[8], mpc_dw3_rs4);
mpc_dw3_vsub_8(mpc_dw3_rs4, mpc_dw3_ds4, mpc_dw3_rs4);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy4, mpc_dw3_nu4, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk4, mpc_dw3_tmp1_16, mpc_dw3_rk4);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu4, mpc_dw3_y4, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk4, mpc_dw3_tmp1_16, mpc_dw3_rk4);
/* Zeitschritt 5 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx5, mpc_dw3_dx5, mpc_dw3_rf0x5);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu5, mpc_dw3_du5, mpc_dw3_rf0x5);
mpc_dw3_vsub_6(mpc_dw3_rf0x5, mpc_dw3_dp5, mpc_dw3_rf0x5);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_dp6, mpc_dw3_rf0x5);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx5, mpc_dw3_dy5, mpc_dw3_rf0x5);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu5, mpc_dw3_dx5, mpc_dw3_rf0u5);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu5, mpc_dw3_du5, mpc_dw3_rf0u5);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu5, mpc_dw3_dp6, mpc_dw3_rf0u5);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu5, mpc_dw3_dy5, mpc_dw3_rf0u5);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss5, mpc_dw3_ds5, mpc_dw3_rf0s5);
mpc_dw3_vsub_8(mpc_dw3_rf0s5, &mpc_dw3_dy5[0], mpc_dw3_rf0s5);
mpc_dw3_vsub_8(mpc_dw3_rf0s5, &mpc_dw3_dy5[8], mpc_dw3_rf0s5);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx4, mpc_dw3_dx4, mpc_dw3_rf5);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu4, mpc_dw3_du4, mpc_dw3_rf5);
mpc_dw3_vsub_6(mpc_dw3_rf5, mpc_dw3_dx5, mpc_dw3_rf5);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx5, mpc_dw3_dx5, mpc_dw3_rc5);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu5, mpc_dw3_du5, mpc_dw3_rc5);
mpc_dw3_vadd_8(mpc_dw3_rc5, mpc_dw3_dnu5, mpc_dw3_rc5);
mpc_dw3_vsub_8(mpc_dw3_rc5, mpc_dw3_ds5, mpc_dw3_rc5);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs5, &mpc_dw3_dnu5[8], mpc_dw3_rs5);
mpc_dw3_vsub_8(mpc_dw3_rs5, mpc_dw3_ds5, mpc_dw3_rs5);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy5, mpc_dw3_nu5, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk5, mpc_dw3_tmp1_16, mpc_dw3_rk5);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu5, mpc_dw3_y5, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk5, mpc_dw3_tmp1_16, mpc_dw3_rk5);
/* Zeitschritt 6 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx6, mpc_dw3_dx6, mpc_dw3_rf0x6);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu6, mpc_dw3_du6, mpc_dw3_rf0x6);
mpc_dw3_vsub_6(mpc_dw3_rf0x6, mpc_dw3_dp6, mpc_dw3_rf0x6);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_dp7, mpc_dw3_rf0x6);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx6, mpc_dw3_dy6, mpc_dw3_rf0x6);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu6, mpc_dw3_dx6, mpc_dw3_rf0u6);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu6, mpc_dw3_du6, mpc_dw3_rf0u6);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu6, mpc_dw3_dp7, mpc_dw3_rf0u6);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu6, mpc_dw3_dy6, mpc_dw3_rf0u6);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss6, mpc_dw3_ds6, mpc_dw3_rf0s6);
mpc_dw3_vsub_8(mpc_dw3_rf0s6, &mpc_dw3_dy6[0], mpc_dw3_rf0s6);
mpc_dw3_vsub_8(mpc_dw3_rf0s6, &mpc_dw3_dy6[8], mpc_dw3_rf0s6);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx5, mpc_dw3_dx5, mpc_dw3_rf6);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu5, mpc_dw3_du5, mpc_dw3_rf6);
mpc_dw3_vsub_6(mpc_dw3_rf6, mpc_dw3_dx6, mpc_dw3_rf6);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx6, mpc_dw3_dx6, mpc_dw3_rc6);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu6, mpc_dw3_du6, mpc_dw3_rc6);
mpc_dw3_vadd_8(mpc_dw3_rc6, mpc_dw3_dnu6, mpc_dw3_rc6);
mpc_dw3_vsub_8(mpc_dw3_rc6, mpc_dw3_ds6, mpc_dw3_rc6);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs6, &mpc_dw3_dnu6[8], mpc_dw3_rs6);
mpc_dw3_vsub_8(mpc_dw3_rs6, mpc_dw3_ds6, mpc_dw3_rs6);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy6, mpc_dw3_nu6, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk6, mpc_dw3_tmp1_16, mpc_dw3_rk6);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu6, mpc_dw3_y6, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk6, mpc_dw3_tmp1_16, mpc_dw3_rk6);
/* Zeitschritt 7 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx7, mpc_dw3_dx7, mpc_dw3_rf0x7);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu7, mpc_dw3_du7, mpc_dw3_rf0x7);
mpc_dw3_vsub_6(mpc_dw3_rf0x7, mpc_dw3_dp7, mpc_dw3_rf0x7);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_dp8, mpc_dw3_rf0x7);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx7, mpc_dw3_dy7, mpc_dw3_rf0x7);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu7, mpc_dw3_dx7, mpc_dw3_rf0u7);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu7, mpc_dw3_du7, mpc_dw3_rf0u7);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu7, mpc_dw3_dp8, mpc_dw3_rf0u7);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu7, mpc_dw3_dy7, mpc_dw3_rf0u7);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss7, mpc_dw3_ds7, mpc_dw3_rf0s7);
mpc_dw3_vsub_8(mpc_dw3_rf0s7, &mpc_dw3_dy7[0], mpc_dw3_rf0s7);
mpc_dw3_vsub_8(mpc_dw3_rf0s7, &mpc_dw3_dy7[8], mpc_dw3_rf0s7);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx6, mpc_dw3_dx6, mpc_dw3_rf7);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu6, mpc_dw3_du6, mpc_dw3_rf7);
mpc_dw3_vsub_6(mpc_dw3_rf7, mpc_dw3_dx7, mpc_dw3_rf7);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx7, mpc_dw3_dx7, mpc_dw3_rc7);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu7, mpc_dw3_du7, mpc_dw3_rc7);
mpc_dw3_vadd_8(mpc_dw3_rc7, mpc_dw3_dnu7, mpc_dw3_rc7);
mpc_dw3_vsub_8(mpc_dw3_rc7, mpc_dw3_ds7, mpc_dw3_rc7);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs7, &mpc_dw3_dnu7[8], mpc_dw3_rs7);
mpc_dw3_vsub_8(mpc_dw3_rs7, mpc_dw3_ds7, mpc_dw3_rs7);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy7, mpc_dw3_nu7, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk7, mpc_dw3_tmp1_16, mpc_dw3_rk7);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu7, mpc_dw3_y7, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk7, mpc_dw3_tmp1_16, mpc_dw3_rk7);
/* Zeitschritt 8 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx8, mpc_dw3_dx8, mpc_dw3_rf0x8);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu8, mpc_dw3_du8, mpc_dw3_rf0x8);
mpc_dw3_vsub_6(mpc_dw3_rf0x8, mpc_dw3_dp8, mpc_dw3_rf0x8);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_dp9, mpc_dw3_rf0x8);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx8, mpc_dw3_dy8, mpc_dw3_rf0x8);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu8, mpc_dw3_dx8, mpc_dw3_rf0u8);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu8, mpc_dw3_du8, mpc_dw3_rf0u8);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu8, mpc_dw3_dp9, mpc_dw3_rf0u8);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu8, mpc_dw3_dy8, mpc_dw3_rf0u8);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss8, mpc_dw3_ds8, mpc_dw3_rf0s8);
mpc_dw3_vsub_8(mpc_dw3_rf0s8, &mpc_dw3_dy8[0], mpc_dw3_rf0s8);
mpc_dw3_vsub_8(mpc_dw3_rf0s8, &mpc_dw3_dy8[8], mpc_dw3_rf0s8);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx7, mpc_dw3_dx7, mpc_dw3_rf8);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu7, mpc_dw3_du7, mpc_dw3_rf8);
mpc_dw3_vsub_6(mpc_dw3_rf8, mpc_dw3_dx8, mpc_dw3_rf8);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx8, mpc_dw3_dx8, mpc_dw3_rc8);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu8, mpc_dw3_du8, mpc_dw3_rc8);
mpc_dw3_vadd_8(mpc_dw3_rc8, mpc_dw3_dnu8, mpc_dw3_rc8);
mpc_dw3_vsub_8(mpc_dw3_rc8, mpc_dw3_ds8, mpc_dw3_rc8);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs8, &mpc_dw3_dnu8[8], mpc_dw3_rs8);
mpc_dw3_vsub_8(mpc_dw3_rs8, mpc_dw3_ds8, mpc_dw3_rs8);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy8, mpc_dw3_nu8, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk8, mpc_dw3_tmp1_16, mpc_dw3_rk8);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu8, mpc_dw3_y8, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk8, mpc_dw3_tmp1_16, mpc_dw3_rk8);
/* Zeitschritt 9 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx9, mpc_dw3_dx9, mpc_dw3_rf0x9);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu9, mpc_dw3_du9, mpc_dw3_rf0x9);
mpc_dw3_vsub_6(mpc_dw3_rf0x9, mpc_dw3_dp9, mpc_dw3_rf0x9);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_dp10, mpc_dw3_rf0x9);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx9, mpc_dw3_dy9, mpc_dw3_rf0x9);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu9, mpc_dw3_dx9, mpc_dw3_rf0u9);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu9, mpc_dw3_du9, mpc_dw3_rf0u9);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu9, mpc_dw3_dp10, mpc_dw3_rf0u9);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu9, mpc_dw3_dy9, mpc_dw3_rf0u9);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss9, mpc_dw3_ds9, mpc_dw3_rf0s9);
mpc_dw3_vsub_8(mpc_dw3_rf0s9, &mpc_dw3_dy9[0], mpc_dw3_rf0s9);
mpc_dw3_vsub_8(mpc_dw3_rf0s9, &mpc_dw3_dy9[8], mpc_dw3_rf0s9);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx8, mpc_dw3_dx8, mpc_dw3_rf9);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu8, mpc_dw3_du8, mpc_dw3_rf9);
mpc_dw3_vsub_6(mpc_dw3_rf9, mpc_dw3_dx9, mpc_dw3_rf9);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx9, mpc_dw3_dx9, mpc_dw3_rc9);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu9, mpc_dw3_du9, mpc_dw3_rc9);
mpc_dw3_vadd_8(mpc_dw3_rc9, mpc_dw3_dnu9, mpc_dw3_rc9);
mpc_dw3_vsub_8(mpc_dw3_rc9, mpc_dw3_ds9, mpc_dw3_rc9);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs9, &mpc_dw3_dnu9[8], mpc_dw3_rs9);
mpc_dw3_vsub_8(mpc_dw3_rs9, mpc_dw3_ds9, mpc_dw3_rs9);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy9, mpc_dw3_nu9, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk9, mpc_dw3_tmp1_16, mpc_dw3_rk9);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu9, mpc_dw3_y9, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk9, mpc_dw3_tmp1_16, mpc_dw3_rk9);
/* Zeitschritt 10 */
/* rf0x */
mpc_dw3_mv_sid22_sid2_6_6(mpc_dw3_Hxx10, mpc_dw3_dx10, mpc_dw3_rf0x10);
mpc_dw3_mv_sid25_sid5_6_1(mpc_dw3_Hxu10, mpc_dw3_du10, mpc_dw3_rf0x10);
mpc_dw3_vsub_6(mpc_dw3_rf0x10, mpc_dw3_dp10, mpc_dw3_rf0x10);
mpc_dw3_mtv_sid43_sid2_6_6(mpc_dw3_fx10, mpc_dw3_dp11, mpc_dw3_rf0x10);
mpc_dw3_mtv_sid52_sid16_8_6(mpc_dw3_gx10, mpc_dw3_dy10, mpc_dw3_rf0x10);
/* rf0u */
mpc_dw3_mtv_sid25_sid2_6_1(mpc_dw3_Hxu10, mpc_dw3_dx10, mpc_dw3_rf0u10);
mpc_dw3_mv_sid28_sid5_1_1(mpc_dw3_Huu10, mpc_dw3_du10, mpc_dw3_rf0u10);
mpc_dw3_mtv_sid46_sid2_6_1(mpc_dw3_fu10, mpc_dw3_dp11, mpc_dw3_rf0u10);
mpc_dw3_mtv_sid55_sid16_8_1(mpc_dw3_gu10, mpc_dw3_dy10, mpc_dw3_rf0u10);
/* rf0s */
mpc_dw3_mv_sid31_sid19_8_8(mpc_dw3_Hss10, mpc_dw3_ds10, mpc_dw3_rf0s10);
mpc_dw3_vsub_8(mpc_dw3_rf0s10, &mpc_dw3_dy10[0], mpc_dw3_rf0s10);
mpc_dw3_vsub_8(mpc_dw3_rf0s10, &mpc_dw3_dy10[8], mpc_dw3_rf0s10);
/* rf */
mpc_dw3_mv_sid43_sid2_6_6(mpc_dw3_fx9, mpc_dw3_dx9, mpc_dw3_rf10);
mpc_dw3_mv_sid46_sid5_6_1(mpc_dw3_fu9, mpc_dw3_du9, mpc_dw3_rf10);
mpc_dw3_vsub_6(mpc_dw3_rf10, mpc_dw3_dx10, mpc_dw3_rf10);
/* rc */
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx10, mpc_dw3_dx10, mpc_dw3_rc10);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu10, mpc_dw3_du10, mpc_dw3_rc10);
mpc_dw3_vadd_8(mpc_dw3_rc10, mpc_dw3_dnu10, mpc_dw3_rc10);
mpc_dw3_vsub_8(mpc_dw3_rc10, mpc_dw3_ds10, mpc_dw3_rc10);
/* rs */
mpc_dw3_vadd_8(mpc_dw3_rs10, &mpc_dw3_dnu10[8], mpc_dw3_rs10);
mpc_dw3_vsub_8(mpc_dw3_rs10, mpc_dw3_ds10, mpc_dw3_rs10);
/* rk */
mpc_dw3_vv_elemult_16(mpc_dw3_dy10, mpc_dw3_nu10, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk10, mpc_dw3_tmp1_16, mpc_dw3_rk10);
mpc_dw3_vv_elemult_16(mpc_dw3_dnu10, mpc_dw3_y10, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_rk10, mpc_dw3_tmp1_16, mpc_dw3_rk10);
/* Zeitschritt 11 */
/* rf0x */
mpc_dw3_mv_sid23_sid2_6_6(mpc_dw3_Hxx11, mpc_dw3_dx11, mpc_dw3_rf0x11);
mpc_dw3_mv_sid26_sid5_6_1(mpc_dw3_Hxu11, mpc_dw3_du11, mpc_dw3_rf0x11);
mpc_dw3_vsub_6(mpc_dw3_rf0x11, mpc_dw3_dp11, mpc_dw3_rf0x11);
mpc_dw3_mtv_sid53_sid17_4_6(mpc_dw3_gx11, mpc_dw3_dy11, mpc_dw3_rf0x11);
/* rf0u */
mpc_dw3_mtv_sid26_sid2_6_1(mpc_dw3_Hxu11, mpc_dw3_dx11, mpc_dw3_rf0u11);
mpc_dw3_mv_sid29_sid5_1_1(mpc_dw3_Huu11, mpc_dw3_du11, mpc_dw3_rf0u11);
mpc_dw3_mtv_sid56_sid17_4_1(mpc_dw3_gu11, mpc_dw3_dy11, mpc_dw3_rf0u11);
/* rf0s */
mpc_dw3_mv_sid32_sid20_4_4(mpc_dw3_Hss11, mpc_dw3_ds11, mpc_dw3_rf0s11);
mpc_dw3_vsub_4(mpc_dw3_rf0s11, &mpc_dw3_dy11[0], mpc_dw3_rf0s11);
mpc_dw3_vsub_4(mpc_dw3_rf0s11, &mpc_dw3_dy11[4], mpc_dw3_rf0s11);
/* rf */
mpc_dw3_mv_sid44_sid2_6_6(mpc_dw3_fx10, mpc_dw3_dx10, mpc_dw3_rf11);
mpc_dw3_mv_sid47_sid5_6_1(mpc_dw3_fu10, mpc_dw3_du10, mpc_dw3_rf11);
mpc_dw3_vsub_6(mpc_dw3_rf11, mpc_dw3_dx11, mpc_dw3_rf11);
/* rc */
mpc_dw3_mv_sid53_sid2_4_6(mpc_dw3_gx11, mpc_dw3_dx11, mpc_dw3_rc11);
mpc_dw3_mv_sid56_sid5_4_1(mpc_dw3_gu11, mpc_dw3_du11, mpc_dw3_rc11);
mpc_dw3_vadd_4(mpc_dw3_rc11, mpc_dw3_dnu11, mpc_dw3_rc11);
mpc_dw3_vsub_4(mpc_dw3_rc11, mpc_dw3_ds11, mpc_dw3_rc11);
/* rs */
mpc_dw3_vadd_4(mpc_dw3_rs11, &mpc_dw3_dnu11[4], mpc_dw3_rs11);
mpc_dw3_vsub_4(mpc_dw3_rs11, mpc_dw3_ds11, mpc_dw3_rs11);
/* rk */
mpc_dw3_vv_elemult_8(mpc_dw3_dy11, mpc_dw3_nu11, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_rk11, mpc_dw3_tmp1_8, mpc_dw3_rk11);
mpc_dw3_vv_elemult_8(mpc_dw3_dnu11, mpc_dw3_y11, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_rk11, mpc_dw3_tmp1_8, mpc_dw3_rk11);
}


static void mpc_dw3_glqdocpip_dereduce()
{
mpc_dw3_error_source = 4;
/* Zeitschritt 0 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_m_copy_4_1(mpc_dw3_rhsxs0, mpc_dw3_tmp3_4_1);
mpc_dw3_mv_sid51_sid2_4_6(mpc_dw3_gx0, mpc_dw3_dx0, mpc_dw3_tmp3_4_1);
mpc_dw3_mv_sid54_sid5_4_1(mpc_dw3_gu0, mpc_dw3_du0, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_yny0, mpc_dw3_tmp3_4_1, mpc_dw3_dy0);
/* dy_ss */
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp1_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss0, mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk0[4], &mpc_dw3_y0[4], mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_4(mpc_dw3_rs0, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp3_4_1);
mpc_dw3_vadd_4(mpc_dw3_tmp3_4_1, mpc_dw3_rf0s0, mpc_dw3_tmp3_4_1);
mpc_dw3_vsub_4(mpc_dw3_tmp3_4_1, mpc_dw3_dy0, mpc_dw3_tmp3_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_nu0[4], &mpc_dw3_y0[4], mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp2_4_1);
mpc_dw3_vadd_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1, &mpc_dw3_dy0[4]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_8(mpc_dw3_nu0, mpc_dw3_dy0, mpc_dw3_dnu0);
mpc_dw3_vadd_8(mpc_dw3_dnu0, mpc_dw3_rk0, mpc_dw3_dnu0);
mpc_dw3_vv_elediv_8(mpc_dw3_dnu0, mpc_dw3_y0, mpc_dw3_dnu0);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_8(mpc_dw3_dnu0, mpc_dw3_dnu0);
/* ds */
mpc_dw3_v_init0_4(mpc_dw3_ds0);
mpc_dw3_vadd_4(mpc_dw3_rs0, &mpc_dw3_dnu0[4], mpc_dw3_ds0);
/* Zeitschritt 1 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs1, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx1, mpc_dw3_dx1, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu1, mpc_dw3_du1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny1, mpc_dw3_tmp2_8_1, mpc_dw3_dy1);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk1[8], &mpc_dw3_y1[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_rf0s1, mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp2_8_1, mpc_dw3_dy1, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu1[8], &mpc_dw3_y1[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy1[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu1, mpc_dw3_dy1, mpc_dw3_dnu1);
mpc_dw3_vadd_16(mpc_dw3_dnu1, mpc_dw3_rk1, mpc_dw3_dnu1);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu1, mpc_dw3_y1, mpc_dw3_dnu1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu1, mpc_dw3_dnu1);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds1);
mpc_dw3_vadd_8(mpc_dw3_rs1, &mpc_dw3_dnu1[8], mpc_dw3_ds1);
/* Zeitschritt 2 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs2, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx2, mpc_dw3_dx2, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu2, mpc_dw3_du2, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny2, mpc_dw3_tmp1_8_1, mpc_dw3_dy2);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss2, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk2[8], &mpc_dw3_y2[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs2, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_rf0s2, mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp1_8_1, mpc_dw3_dy2, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu2[8], &mpc_dw3_y2[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy2[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu2, mpc_dw3_dy2, mpc_dw3_dnu2);
mpc_dw3_vadd_16(mpc_dw3_dnu2, mpc_dw3_rk2, mpc_dw3_dnu2);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu2, mpc_dw3_y2, mpc_dw3_dnu2);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu2, mpc_dw3_dnu2);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds2);
mpc_dw3_vadd_8(mpc_dw3_rs2, &mpc_dw3_dnu2[8], mpc_dw3_ds2);
/* Zeitschritt 3 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs3, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx3, mpc_dw3_dx3, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu3, mpc_dw3_du3, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny3, mpc_dw3_tmp2_8_1, mpc_dw3_dy3);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss3, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk3[8], &mpc_dw3_y3[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs3, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_rf0s3, mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp2_8_1, mpc_dw3_dy3, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu3[8], &mpc_dw3_y3[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy3[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu3, mpc_dw3_dy3, mpc_dw3_dnu3);
mpc_dw3_vadd_16(mpc_dw3_dnu3, mpc_dw3_rk3, mpc_dw3_dnu3);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu3, mpc_dw3_y3, mpc_dw3_dnu3);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu3, mpc_dw3_dnu3);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds3);
mpc_dw3_vadd_8(mpc_dw3_rs3, &mpc_dw3_dnu3[8], mpc_dw3_ds3);
/* Zeitschritt 4 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs4, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx4, mpc_dw3_dx4, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu4, mpc_dw3_du4, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny4, mpc_dw3_tmp1_8_1, mpc_dw3_dy4);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss4, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk4[8], &mpc_dw3_y4[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs4, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_rf0s4, mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp1_8_1, mpc_dw3_dy4, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu4[8], &mpc_dw3_y4[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy4[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu4, mpc_dw3_dy4, mpc_dw3_dnu4);
mpc_dw3_vadd_16(mpc_dw3_dnu4, mpc_dw3_rk4, mpc_dw3_dnu4);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu4, mpc_dw3_y4, mpc_dw3_dnu4);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu4, mpc_dw3_dnu4);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds4);
mpc_dw3_vadd_8(mpc_dw3_rs4, &mpc_dw3_dnu4[8], mpc_dw3_ds4);
/* Zeitschritt 5 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs5, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx5, mpc_dw3_dx5, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu5, mpc_dw3_du5, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny5, mpc_dw3_tmp2_8_1, mpc_dw3_dy5);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss5, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk5[8], &mpc_dw3_y5[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs5, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_rf0s5, mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp2_8_1, mpc_dw3_dy5, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu5[8], &mpc_dw3_y5[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy5[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu5, mpc_dw3_dy5, mpc_dw3_dnu5);
mpc_dw3_vadd_16(mpc_dw3_dnu5, mpc_dw3_rk5, mpc_dw3_dnu5);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu5, mpc_dw3_y5, mpc_dw3_dnu5);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu5, mpc_dw3_dnu5);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds5);
mpc_dw3_vadd_8(mpc_dw3_rs5, &mpc_dw3_dnu5[8], mpc_dw3_ds5);
/* Zeitschritt 6 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs6, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx6, mpc_dw3_dx6, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu6, mpc_dw3_du6, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny6, mpc_dw3_tmp1_8_1, mpc_dw3_dy6);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss6, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk6[8], &mpc_dw3_y6[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs6, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_rf0s6, mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp1_8_1, mpc_dw3_dy6, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu6[8], &mpc_dw3_y6[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy6[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu6, mpc_dw3_dy6, mpc_dw3_dnu6);
mpc_dw3_vadd_16(mpc_dw3_dnu6, mpc_dw3_rk6, mpc_dw3_dnu6);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu6, mpc_dw3_y6, mpc_dw3_dnu6);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu6, mpc_dw3_dnu6);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds6);
mpc_dw3_vadd_8(mpc_dw3_rs6, &mpc_dw3_dnu6[8], mpc_dw3_ds6);
/* Zeitschritt 7 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs7, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx7, mpc_dw3_dx7, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu7, mpc_dw3_du7, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny7, mpc_dw3_tmp2_8_1, mpc_dw3_dy7);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss7, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk7[8], &mpc_dw3_y7[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs7, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_rf0s7, mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp2_8_1, mpc_dw3_dy7, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu7[8], &mpc_dw3_y7[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy7[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu7, mpc_dw3_dy7, mpc_dw3_dnu7);
mpc_dw3_vadd_16(mpc_dw3_dnu7, mpc_dw3_rk7, mpc_dw3_dnu7);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu7, mpc_dw3_y7, mpc_dw3_dnu7);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu7, mpc_dw3_dnu7);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds7);
mpc_dw3_vadd_8(mpc_dw3_rs7, &mpc_dw3_dnu7[8], mpc_dw3_ds7);
/* Zeitschritt 8 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs8, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx8, mpc_dw3_dx8, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu8, mpc_dw3_du8, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny8, mpc_dw3_tmp1_8_1, mpc_dw3_dy8);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss8, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk8[8], &mpc_dw3_y8[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs8, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_rf0s8, mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp1_8_1, mpc_dw3_dy8, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu8[8], &mpc_dw3_y8[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy8[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu8, mpc_dw3_dy8, mpc_dw3_dnu8);
mpc_dw3_vadd_16(mpc_dw3_dnu8, mpc_dw3_rk8, mpc_dw3_dnu8);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu8, mpc_dw3_y8, mpc_dw3_dnu8);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu8, mpc_dw3_dnu8);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds8);
mpc_dw3_vadd_8(mpc_dw3_rs8, &mpc_dw3_dnu8[8], mpc_dw3_ds8);
/* Zeitschritt 9 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs9, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx9, mpc_dw3_dx9, mpc_dw3_tmp2_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu9, mpc_dw3_du9, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny9, mpc_dw3_tmp2_8_1, mpc_dw3_dy9);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss9, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk9[8], &mpc_dw3_y9[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs9, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp2_8_1, mpc_dw3_rf0s9, mpc_dw3_tmp2_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp2_8_1, mpc_dw3_dy9, mpc_dw3_tmp2_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu9[8], &mpc_dw3_y9[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy9[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu9, mpc_dw3_dy9, mpc_dw3_dnu9);
mpc_dw3_vadd_16(mpc_dw3_dnu9, mpc_dw3_rk9, mpc_dw3_dnu9);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu9, mpc_dw3_y9, mpc_dw3_dnu9);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu9, mpc_dw3_dnu9);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds9);
mpc_dw3_vadd_8(mpc_dw3_rs9, &mpc_dw3_dnu9[8], mpc_dw3_ds9);
/* Zeitschritt 10 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8_1);
mpc_dw3_m_copy_8_1(mpc_dw3_rhsxs10, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid52_sid2_8_6(mpc_dw3_gx10, mpc_dw3_dx10, mpc_dw3_tmp1_8_1);
mpc_dw3_mv_sid55_sid5_8_1(mpc_dw3_gu10, mpc_dw3_du10, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_yny10, mpc_dw3_tmp1_8_1, mpc_dw3_dy10);
/* dy_ss */
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp3_8_1);
mpc_dw3_mv_8_8(mpc_dw3_Hss10, mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_rk10[8], &mpc_dw3_y10[8], mpc_dw3_tmp1_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_8(mpc_dw3_rs10, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp1_8_1, mpc_dw3_tmp1_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp1_8_1, mpc_dw3_rf0s10, mpc_dw3_tmp1_8_1);
mpc_dw3_vsub_8(mpc_dw3_tmp1_8_1, mpc_dw3_dy10, mpc_dw3_tmp1_8_1);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vv_elediv_8(&mpc_dw3_nu10[8], &mpc_dw3_y10[8], mpc_dw3_tmp2_8_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8_1);
mpc_dw3_vadd_8(mpc_dw3_tmp3_8_1, mpc_dw3_tmp2_8_1, mpc_dw3_tmp3_8_1);
mpc_dw3_vv_elediv_8(mpc_dw3_tmp1_8_1, mpc_dw3_tmp3_8_1, &mpc_dw3_dy10[8]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_16(mpc_dw3_nu10, mpc_dw3_dy10, mpc_dw3_dnu10);
mpc_dw3_vadd_16(mpc_dw3_dnu10, mpc_dw3_rk10, mpc_dw3_dnu10);
mpc_dw3_vv_elediv_16(mpc_dw3_dnu10, mpc_dw3_y10, mpc_dw3_dnu10);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_16(mpc_dw3_dnu10, mpc_dw3_dnu10);
/* ds */
mpc_dw3_v_init0_8(mpc_dw3_ds10);
mpc_dw3_vadd_8(mpc_dw3_rs10, &mpc_dw3_dnu10[8], mpc_dw3_ds10);
/* Zeitschritt 11 */
/* dy */
/* Hilfsvektor */
mpc_dw3_v_init0_4(mpc_dw3_tmp2_4_1);
mpc_dw3_m_copy_4_1(mpc_dw3_rhsxs11, mpc_dw3_tmp2_4_1);
mpc_dw3_mv_sid53_sid2_4_6(mpc_dw3_gx11, mpc_dw3_dx11, mpc_dw3_tmp2_4_1);
mpc_dw3_mv_sid56_sid5_4_1(mpc_dw3_gu11, mpc_dw3_du11, mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_yny11, mpc_dw3_tmp2_4_1, mpc_dw3_dy11);
/* dy_ss */
mpc_dw3_v_init1_4(mpc_dw3_tmp2_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp1_4_1);
mpc_dw3_mv_4_4(mpc_dw3_Hss11, mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_rk11[4], &mpc_dw3_y11[4], mpc_dw3_tmp2_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vsub_4(mpc_dw3_rs11, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_vv_elemult_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp2_4_1, mpc_dw3_tmp2_4_1);
mpc_dw3_vadd_4(mpc_dw3_tmp2_4_1, mpc_dw3_rf0s11, mpc_dw3_tmp2_4_1);
mpc_dw3_vsub_4(mpc_dw3_tmp2_4_1, mpc_dw3_dy11, mpc_dw3_tmp2_4_1);
mpc_dw3_v_init0_4(mpc_dw3_tmp3_4_1);
mpc_dw3_vv_elediv_4(&mpc_dw3_nu11[4], &mpc_dw3_y11[4], mpc_dw3_tmp3_4_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_v_init1_4(mpc_dw3_tmp3_4_1);
mpc_dw3_vadd_4(mpc_dw3_tmp1_4_1, mpc_dw3_tmp3_4_1, mpc_dw3_tmp1_4_1);
mpc_dw3_vv_elediv_4(mpc_dw3_tmp2_4_1, mpc_dw3_tmp1_4_1, &mpc_dw3_dy11[4]);
if(mpc_dw3_termcode > -1){return;}
/* dnu */
mpc_dw3_vv_elemult_8(mpc_dw3_nu11, mpc_dw3_dy11, mpc_dw3_dnu11);
mpc_dw3_vadd_8(mpc_dw3_dnu11, mpc_dw3_rk11, mpc_dw3_dnu11);
mpc_dw3_vv_elediv_8(mpc_dw3_dnu11, mpc_dw3_y11, mpc_dw3_dnu11);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_turnsign_8(mpc_dw3_dnu11, mpc_dw3_dnu11);
/* ds */
mpc_dw3_v_init0_4(mpc_dw3_ds11);
mpc_dw3_vadd_4(mpc_dw3_rs11, &mpc_dw3_dnu11[4], mpc_dw3_ds11);
mpc_dw3_error_source = 0;

}


/* ###################################################### */
/* Diese Funktion berechnet führt die Nachiteration durch */
/* ###################################################### */
static void mpc_dw3_glqdocpip_iter_ref()
{
if(mpc_dw3_iter_ref == 1){
mpc_dw3_stat_num_iter_ref++;
mpc_dw3_stat_iter_ref[mpc_dw3_iter] = 1;
/* Lösung sichern */
mpc_dw3_v_copy_6(mpc_dw3_dx0, mpc_dw3_dx_ir0);
mpc_dw3_v_copy_1(mpc_dw3_du0, mpc_dw3_du_ir0);
mpc_dw3_v_copy_4(mpc_dw3_ds0, mpc_dw3_ds_ir0);
mpc_dw3_v_copy_6(mpc_dw3_dp0, mpc_dw3_dp_ir0);
mpc_dw3_v_copy_8(mpc_dw3_dy0, mpc_dw3_dy_ir0);
mpc_dw3_v_copy_8(mpc_dw3_dnu0, mpc_dw3_dnu_ir0);
mpc_dw3_v_copy_6(mpc_dw3_dx1, mpc_dw3_dx_ir1);
mpc_dw3_v_copy_1(mpc_dw3_du1, mpc_dw3_du_ir1);
mpc_dw3_v_copy_8(mpc_dw3_ds1, mpc_dw3_ds_ir1);
mpc_dw3_v_copy_6(mpc_dw3_dp1, mpc_dw3_dp_ir1);
mpc_dw3_v_copy_16(mpc_dw3_dy1, mpc_dw3_dy_ir1);
mpc_dw3_v_copy_16(mpc_dw3_dnu1, mpc_dw3_dnu_ir1);
mpc_dw3_v_copy_6(mpc_dw3_dx2, mpc_dw3_dx_ir2);
mpc_dw3_v_copy_1(mpc_dw3_du2, mpc_dw3_du_ir2);
mpc_dw3_v_copy_8(mpc_dw3_ds2, mpc_dw3_ds_ir2);
mpc_dw3_v_copy_6(mpc_dw3_dp2, mpc_dw3_dp_ir2);
mpc_dw3_v_copy_16(mpc_dw3_dy2, mpc_dw3_dy_ir2);
mpc_dw3_v_copy_16(mpc_dw3_dnu2, mpc_dw3_dnu_ir2);
mpc_dw3_v_copy_6(mpc_dw3_dx3, mpc_dw3_dx_ir3);
mpc_dw3_v_copy_1(mpc_dw3_du3, mpc_dw3_du_ir3);
mpc_dw3_v_copy_8(mpc_dw3_ds3, mpc_dw3_ds_ir3);
mpc_dw3_v_copy_6(mpc_dw3_dp3, mpc_dw3_dp_ir3);
mpc_dw3_v_copy_16(mpc_dw3_dy3, mpc_dw3_dy_ir3);
mpc_dw3_v_copy_16(mpc_dw3_dnu3, mpc_dw3_dnu_ir3);
mpc_dw3_v_copy_6(mpc_dw3_dx4, mpc_dw3_dx_ir4);
mpc_dw3_v_copy_1(mpc_dw3_du4, mpc_dw3_du_ir4);
mpc_dw3_v_copy_8(mpc_dw3_ds4, mpc_dw3_ds_ir4);
mpc_dw3_v_copy_6(mpc_dw3_dp4, mpc_dw3_dp_ir4);
mpc_dw3_v_copy_16(mpc_dw3_dy4, mpc_dw3_dy_ir4);
mpc_dw3_v_copy_16(mpc_dw3_dnu4, mpc_dw3_dnu_ir4);
mpc_dw3_v_copy_6(mpc_dw3_dx5, mpc_dw3_dx_ir5);
mpc_dw3_v_copy_1(mpc_dw3_du5, mpc_dw3_du_ir5);
mpc_dw3_v_copy_8(mpc_dw3_ds5, mpc_dw3_ds_ir5);
mpc_dw3_v_copy_6(mpc_dw3_dp5, mpc_dw3_dp_ir5);
mpc_dw3_v_copy_16(mpc_dw3_dy5, mpc_dw3_dy_ir5);
mpc_dw3_v_copy_16(mpc_dw3_dnu5, mpc_dw3_dnu_ir5);
mpc_dw3_v_copy_6(mpc_dw3_dx6, mpc_dw3_dx_ir6);
mpc_dw3_v_copy_1(mpc_dw3_du6, mpc_dw3_du_ir6);
mpc_dw3_v_copy_8(mpc_dw3_ds6, mpc_dw3_ds_ir6);
mpc_dw3_v_copy_6(mpc_dw3_dp6, mpc_dw3_dp_ir6);
mpc_dw3_v_copy_16(mpc_dw3_dy6, mpc_dw3_dy_ir6);
mpc_dw3_v_copy_16(mpc_dw3_dnu6, mpc_dw3_dnu_ir6);
mpc_dw3_v_copy_6(mpc_dw3_dx7, mpc_dw3_dx_ir7);
mpc_dw3_v_copy_1(mpc_dw3_du7, mpc_dw3_du_ir7);
mpc_dw3_v_copy_8(mpc_dw3_ds7, mpc_dw3_ds_ir7);
mpc_dw3_v_copy_6(mpc_dw3_dp7, mpc_dw3_dp_ir7);
mpc_dw3_v_copy_16(mpc_dw3_dy7, mpc_dw3_dy_ir7);
mpc_dw3_v_copy_16(mpc_dw3_dnu7, mpc_dw3_dnu_ir7);
mpc_dw3_v_copy_6(mpc_dw3_dx8, mpc_dw3_dx_ir8);
mpc_dw3_v_copy_1(mpc_dw3_du8, mpc_dw3_du_ir8);
mpc_dw3_v_copy_8(mpc_dw3_ds8, mpc_dw3_ds_ir8);
mpc_dw3_v_copy_6(mpc_dw3_dp8, mpc_dw3_dp_ir8);
mpc_dw3_v_copy_16(mpc_dw3_dy8, mpc_dw3_dy_ir8);
mpc_dw3_v_copy_16(mpc_dw3_dnu8, mpc_dw3_dnu_ir8);
mpc_dw3_v_copy_6(mpc_dw3_dx9, mpc_dw3_dx_ir9);
mpc_dw3_v_copy_1(mpc_dw3_du9, mpc_dw3_du_ir9);
mpc_dw3_v_copy_8(mpc_dw3_ds9, mpc_dw3_ds_ir9);
mpc_dw3_v_copy_6(mpc_dw3_dp9, mpc_dw3_dp_ir9);
mpc_dw3_v_copy_16(mpc_dw3_dy9, mpc_dw3_dy_ir9);
mpc_dw3_v_copy_16(mpc_dw3_dnu9, mpc_dw3_dnu_ir9);
mpc_dw3_v_copy_6(mpc_dw3_dx10, mpc_dw3_dx_ir10);
mpc_dw3_v_copy_1(mpc_dw3_du10, mpc_dw3_du_ir10);
mpc_dw3_v_copy_8(mpc_dw3_ds10, mpc_dw3_ds_ir10);
mpc_dw3_v_copy_6(mpc_dw3_dp10, mpc_dw3_dp_ir10);
mpc_dw3_v_copy_16(mpc_dw3_dy10, mpc_dw3_dy_ir10);
mpc_dw3_v_copy_16(mpc_dw3_dnu10, mpc_dw3_dnu_ir10);
mpc_dw3_v_copy_6(mpc_dw3_dx11, mpc_dw3_dx_ir11);
mpc_dw3_v_copy_1(mpc_dw3_du11, mpc_dw3_du_ir11);
mpc_dw3_v_copy_4(mpc_dw3_ds11, mpc_dw3_ds_ir11);
mpc_dw3_v_copy_6(mpc_dw3_dp11, mpc_dw3_dp_ir11);
mpc_dw3_v_copy_8(mpc_dw3_dy11, mpc_dw3_dy_ir11);
mpc_dw3_v_copy_8(mpc_dw3_dnu11, mpc_dw3_dnu_ir11);
/* rhs sichern */
mpc_dw3_v_copy_6(mpc_dw3_rf0x0, mpc_dw3_rf0x_ir0);
mpc_dw3_v_copy_1(mpc_dw3_rf0u0, mpc_dw3_rf0u_ir0);
mpc_dw3_v_copy_4(mpc_dw3_rf0s0, mpc_dw3_rf0s_ir0);
mpc_dw3_v_copy_6(mpc_dw3_rf0, mpc_dw3_rf_ir0);
mpc_dw3_v_copy_8(mpc_dw3_rc0, mpc_dw3_rc_ir0);
mpc_dw3_v_copy_4(mpc_dw3_rs0, mpc_dw3_rs_ir0);
mpc_dw3_v_copy_8(mpc_dw3_rk0, mpc_dw3_rk_ir0);
mpc_dw3_v_copy_6(mpc_dw3_rf0x1, mpc_dw3_rf0x_ir1);
mpc_dw3_v_copy_1(mpc_dw3_rf0u1, mpc_dw3_rf0u_ir1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s1, mpc_dw3_rf0s_ir1);
mpc_dw3_v_copy_6(mpc_dw3_rf1, mpc_dw3_rf_ir1);
mpc_dw3_v_copy_16(mpc_dw3_rc1, mpc_dw3_rc_ir1);
mpc_dw3_v_copy_8(mpc_dw3_rs1, mpc_dw3_rs_ir1);
mpc_dw3_v_copy_16(mpc_dw3_rk1, mpc_dw3_rk_ir1);
mpc_dw3_v_copy_6(mpc_dw3_rf0x2, mpc_dw3_rf0x_ir2);
mpc_dw3_v_copy_1(mpc_dw3_rf0u2, mpc_dw3_rf0u_ir2);
mpc_dw3_v_copy_8(mpc_dw3_rf0s2, mpc_dw3_rf0s_ir2);
mpc_dw3_v_copy_6(mpc_dw3_rf2, mpc_dw3_rf_ir2);
mpc_dw3_v_copy_16(mpc_dw3_rc2, mpc_dw3_rc_ir2);
mpc_dw3_v_copy_8(mpc_dw3_rs2, mpc_dw3_rs_ir2);
mpc_dw3_v_copy_16(mpc_dw3_rk2, mpc_dw3_rk_ir2);
mpc_dw3_v_copy_6(mpc_dw3_rf0x3, mpc_dw3_rf0x_ir3);
mpc_dw3_v_copy_1(mpc_dw3_rf0u3, mpc_dw3_rf0u_ir3);
mpc_dw3_v_copy_8(mpc_dw3_rf0s3, mpc_dw3_rf0s_ir3);
mpc_dw3_v_copy_6(mpc_dw3_rf3, mpc_dw3_rf_ir3);
mpc_dw3_v_copy_16(mpc_dw3_rc3, mpc_dw3_rc_ir3);
mpc_dw3_v_copy_8(mpc_dw3_rs3, mpc_dw3_rs_ir3);
mpc_dw3_v_copy_16(mpc_dw3_rk3, mpc_dw3_rk_ir3);
mpc_dw3_v_copy_6(mpc_dw3_rf0x4, mpc_dw3_rf0x_ir4);
mpc_dw3_v_copy_1(mpc_dw3_rf0u4, mpc_dw3_rf0u_ir4);
mpc_dw3_v_copy_8(mpc_dw3_rf0s4, mpc_dw3_rf0s_ir4);
mpc_dw3_v_copy_6(mpc_dw3_rf4, mpc_dw3_rf_ir4);
mpc_dw3_v_copy_16(mpc_dw3_rc4, mpc_dw3_rc_ir4);
mpc_dw3_v_copy_8(mpc_dw3_rs4, mpc_dw3_rs_ir4);
mpc_dw3_v_copy_16(mpc_dw3_rk4, mpc_dw3_rk_ir4);
mpc_dw3_v_copy_6(mpc_dw3_rf0x5, mpc_dw3_rf0x_ir5);
mpc_dw3_v_copy_1(mpc_dw3_rf0u5, mpc_dw3_rf0u_ir5);
mpc_dw3_v_copy_8(mpc_dw3_rf0s5, mpc_dw3_rf0s_ir5);
mpc_dw3_v_copy_6(mpc_dw3_rf5, mpc_dw3_rf_ir5);
mpc_dw3_v_copy_16(mpc_dw3_rc5, mpc_dw3_rc_ir5);
mpc_dw3_v_copy_8(mpc_dw3_rs5, mpc_dw3_rs_ir5);
mpc_dw3_v_copy_16(mpc_dw3_rk5, mpc_dw3_rk_ir5);
mpc_dw3_v_copy_6(mpc_dw3_rf0x6, mpc_dw3_rf0x_ir6);
mpc_dw3_v_copy_1(mpc_dw3_rf0u6, mpc_dw3_rf0u_ir6);
mpc_dw3_v_copy_8(mpc_dw3_rf0s6, mpc_dw3_rf0s_ir6);
mpc_dw3_v_copy_6(mpc_dw3_rf6, mpc_dw3_rf_ir6);
mpc_dw3_v_copy_16(mpc_dw3_rc6, mpc_dw3_rc_ir6);
mpc_dw3_v_copy_8(mpc_dw3_rs6, mpc_dw3_rs_ir6);
mpc_dw3_v_copy_16(mpc_dw3_rk6, mpc_dw3_rk_ir6);
mpc_dw3_v_copy_6(mpc_dw3_rf0x7, mpc_dw3_rf0x_ir7);
mpc_dw3_v_copy_1(mpc_dw3_rf0u7, mpc_dw3_rf0u_ir7);
mpc_dw3_v_copy_8(mpc_dw3_rf0s7, mpc_dw3_rf0s_ir7);
mpc_dw3_v_copy_6(mpc_dw3_rf7, mpc_dw3_rf_ir7);
mpc_dw3_v_copy_16(mpc_dw3_rc7, mpc_dw3_rc_ir7);
mpc_dw3_v_copy_8(mpc_dw3_rs7, mpc_dw3_rs_ir7);
mpc_dw3_v_copy_16(mpc_dw3_rk7, mpc_dw3_rk_ir7);
mpc_dw3_v_copy_6(mpc_dw3_rf0x8, mpc_dw3_rf0x_ir8);
mpc_dw3_v_copy_1(mpc_dw3_rf0u8, mpc_dw3_rf0u_ir8);
mpc_dw3_v_copy_8(mpc_dw3_rf0s8, mpc_dw3_rf0s_ir8);
mpc_dw3_v_copy_6(mpc_dw3_rf8, mpc_dw3_rf_ir8);
mpc_dw3_v_copy_16(mpc_dw3_rc8, mpc_dw3_rc_ir8);
mpc_dw3_v_copy_8(mpc_dw3_rs8, mpc_dw3_rs_ir8);
mpc_dw3_v_copy_16(mpc_dw3_rk8, mpc_dw3_rk_ir8);
mpc_dw3_v_copy_6(mpc_dw3_rf0x9, mpc_dw3_rf0x_ir9);
mpc_dw3_v_copy_1(mpc_dw3_rf0u9, mpc_dw3_rf0u_ir9);
mpc_dw3_v_copy_8(mpc_dw3_rf0s9, mpc_dw3_rf0s_ir9);
mpc_dw3_v_copy_6(mpc_dw3_rf9, mpc_dw3_rf_ir9);
mpc_dw3_v_copy_16(mpc_dw3_rc9, mpc_dw3_rc_ir9);
mpc_dw3_v_copy_8(mpc_dw3_rs9, mpc_dw3_rs_ir9);
mpc_dw3_v_copy_16(mpc_dw3_rk9, mpc_dw3_rk_ir9);
mpc_dw3_v_copy_6(mpc_dw3_rf0x10, mpc_dw3_rf0x_ir10);
mpc_dw3_v_copy_1(mpc_dw3_rf0u10, mpc_dw3_rf0u_ir10);
mpc_dw3_v_copy_8(mpc_dw3_rf0s10, mpc_dw3_rf0s_ir10);
mpc_dw3_v_copy_6(mpc_dw3_rf10, mpc_dw3_rf_ir10);
mpc_dw3_v_copy_16(mpc_dw3_rc10, mpc_dw3_rc_ir10);
mpc_dw3_v_copy_8(mpc_dw3_rs10, mpc_dw3_rs_ir10);
mpc_dw3_v_copy_16(mpc_dw3_rk10, mpc_dw3_rk_ir10);
mpc_dw3_v_copy_6(mpc_dw3_rf0x11, mpc_dw3_rf0x_ir11);
mpc_dw3_v_copy_1(mpc_dw3_rf0u11, mpc_dw3_rf0u_ir11);
mpc_dw3_v_copy_4(mpc_dw3_rf0s11, mpc_dw3_rf0s_ir11);
mpc_dw3_v_copy_6(mpc_dw3_rf11, mpc_dw3_rf_ir11);
mpc_dw3_v_copy_8(mpc_dw3_rc11, mpc_dw3_rc_ir11);
mpc_dw3_v_copy_4(mpc_dw3_rs11, mpc_dw3_rs_ir11);
mpc_dw3_v_copy_8(mpc_dw3_rk11, mpc_dw3_rk_ir11);
/* Residuum berechnen */
mpc_dw3_glqdocpip_rhs_iter_ref();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_rhs_reduced();
if(mpc_dw3_termcode > -1){return;}
/* GLS mit Residuum als rechte Seite lösen */
mpc_dw3_glqdocpip_solve();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_dereduce();
if(mpc_dw3_termcode > -1){return;}
/* Lösung aktualisieren */
mpc_dw3_vadd_6(mpc_dw3_dx_ir0, mpc_dw3_dx0, mpc_dw3_dx0);
mpc_dw3_vadd_1(mpc_dw3_du_ir0, mpc_dw3_du0, mpc_dw3_du0);
mpc_dw3_vadd_4(mpc_dw3_ds_ir0, mpc_dw3_ds0, mpc_dw3_ds0);
mpc_dw3_vadd_6(mpc_dw3_dp_ir0, mpc_dw3_dp0, mpc_dw3_dp0);
mpc_dw3_vadd_8(mpc_dw3_dy_ir0, mpc_dw3_dy0, mpc_dw3_dy0);
mpc_dw3_vadd_8(mpc_dw3_dnu_ir0, mpc_dw3_dnu0, mpc_dw3_dnu0);
mpc_dw3_vadd_6(mpc_dw3_dx_ir1, mpc_dw3_dx1, mpc_dw3_dx1);
mpc_dw3_vadd_1(mpc_dw3_du_ir1, mpc_dw3_du1, mpc_dw3_du1);
mpc_dw3_vadd_8(mpc_dw3_ds_ir1, mpc_dw3_ds1, mpc_dw3_ds1);
mpc_dw3_vadd_6(mpc_dw3_dp_ir1, mpc_dw3_dp1, mpc_dw3_dp1);
mpc_dw3_vadd_16(mpc_dw3_dy_ir1, mpc_dw3_dy1, mpc_dw3_dy1);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir1, mpc_dw3_dnu1, mpc_dw3_dnu1);
mpc_dw3_vadd_6(mpc_dw3_dx_ir2, mpc_dw3_dx2, mpc_dw3_dx2);
mpc_dw3_vadd_1(mpc_dw3_du_ir2, mpc_dw3_du2, mpc_dw3_du2);
mpc_dw3_vadd_8(mpc_dw3_ds_ir2, mpc_dw3_ds2, mpc_dw3_ds2);
mpc_dw3_vadd_6(mpc_dw3_dp_ir2, mpc_dw3_dp2, mpc_dw3_dp2);
mpc_dw3_vadd_16(mpc_dw3_dy_ir2, mpc_dw3_dy2, mpc_dw3_dy2);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir2, mpc_dw3_dnu2, mpc_dw3_dnu2);
mpc_dw3_vadd_6(mpc_dw3_dx_ir3, mpc_dw3_dx3, mpc_dw3_dx3);
mpc_dw3_vadd_1(mpc_dw3_du_ir3, mpc_dw3_du3, mpc_dw3_du3);
mpc_dw3_vadd_8(mpc_dw3_ds_ir3, mpc_dw3_ds3, mpc_dw3_ds3);
mpc_dw3_vadd_6(mpc_dw3_dp_ir3, mpc_dw3_dp3, mpc_dw3_dp3);
mpc_dw3_vadd_16(mpc_dw3_dy_ir3, mpc_dw3_dy3, mpc_dw3_dy3);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir3, mpc_dw3_dnu3, mpc_dw3_dnu3);
mpc_dw3_vadd_6(mpc_dw3_dx_ir4, mpc_dw3_dx4, mpc_dw3_dx4);
mpc_dw3_vadd_1(mpc_dw3_du_ir4, mpc_dw3_du4, mpc_dw3_du4);
mpc_dw3_vadd_8(mpc_dw3_ds_ir4, mpc_dw3_ds4, mpc_dw3_ds4);
mpc_dw3_vadd_6(mpc_dw3_dp_ir4, mpc_dw3_dp4, mpc_dw3_dp4);
mpc_dw3_vadd_16(mpc_dw3_dy_ir4, mpc_dw3_dy4, mpc_dw3_dy4);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir4, mpc_dw3_dnu4, mpc_dw3_dnu4);
mpc_dw3_vadd_6(mpc_dw3_dx_ir5, mpc_dw3_dx5, mpc_dw3_dx5);
mpc_dw3_vadd_1(mpc_dw3_du_ir5, mpc_dw3_du5, mpc_dw3_du5);
mpc_dw3_vadd_8(mpc_dw3_ds_ir5, mpc_dw3_ds5, mpc_dw3_ds5);
mpc_dw3_vadd_6(mpc_dw3_dp_ir5, mpc_dw3_dp5, mpc_dw3_dp5);
mpc_dw3_vadd_16(mpc_dw3_dy_ir5, mpc_dw3_dy5, mpc_dw3_dy5);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir5, mpc_dw3_dnu5, mpc_dw3_dnu5);
mpc_dw3_vadd_6(mpc_dw3_dx_ir6, mpc_dw3_dx6, mpc_dw3_dx6);
mpc_dw3_vadd_1(mpc_dw3_du_ir6, mpc_dw3_du6, mpc_dw3_du6);
mpc_dw3_vadd_8(mpc_dw3_ds_ir6, mpc_dw3_ds6, mpc_dw3_ds6);
mpc_dw3_vadd_6(mpc_dw3_dp_ir6, mpc_dw3_dp6, mpc_dw3_dp6);
mpc_dw3_vadd_16(mpc_dw3_dy_ir6, mpc_dw3_dy6, mpc_dw3_dy6);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir6, mpc_dw3_dnu6, mpc_dw3_dnu6);
mpc_dw3_vadd_6(mpc_dw3_dx_ir7, mpc_dw3_dx7, mpc_dw3_dx7);
mpc_dw3_vadd_1(mpc_dw3_du_ir7, mpc_dw3_du7, mpc_dw3_du7);
mpc_dw3_vadd_8(mpc_dw3_ds_ir7, mpc_dw3_ds7, mpc_dw3_ds7);
mpc_dw3_vadd_6(mpc_dw3_dp_ir7, mpc_dw3_dp7, mpc_dw3_dp7);
mpc_dw3_vadd_16(mpc_dw3_dy_ir7, mpc_dw3_dy7, mpc_dw3_dy7);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir7, mpc_dw3_dnu7, mpc_dw3_dnu7);
mpc_dw3_vadd_6(mpc_dw3_dx_ir8, mpc_dw3_dx8, mpc_dw3_dx8);
mpc_dw3_vadd_1(mpc_dw3_du_ir8, mpc_dw3_du8, mpc_dw3_du8);
mpc_dw3_vadd_8(mpc_dw3_ds_ir8, mpc_dw3_ds8, mpc_dw3_ds8);
mpc_dw3_vadd_6(mpc_dw3_dp_ir8, mpc_dw3_dp8, mpc_dw3_dp8);
mpc_dw3_vadd_16(mpc_dw3_dy_ir8, mpc_dw3_dy8, mpc_dw3_dy8);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir8, mpc_dw3_dnu8, mpc_dw3_dnu8);
mpc_dw3_vadd_6(mpc_dw3_dx_ir9, mpc_dw3_dx9, mpc_dw3_dx9);
mpc_dw3_vadd_1(mpc_dw3_du_ir9, mpc_dw3_du9, mpc_dw3_du9);
mpc_dw3_vadd_8(mpc_dw3_ds_ir9, mpc_dw3_ds9, mpc_dw3_ds9);
mpc_dw3_vadd_6(mpc_dw3_dp_ir9, mpc_dw3_dp9, mpc_dw3_dp9);
mpc_dw3_vadd_16(mpc_dw3_dy_ir9, mpc_dw3_dy9, mpc_dw3_dy9);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir9, mpc_dw3_dnu9, mpc_dw3_dnu9);
mpc_dw3_vadd_6(mpc_dw3_dx_ir10, mpc_dw3_dx10, mpc_dw3_dx10);
mpc_dw3_vadd_1(mpc_dw3_du_ir10, mpc_dw3_du10, mpc_dw3_du10);
mpc_dw3_vadd_8(mpc_dw3_ds_ir10, mpc_dw3_ds10, mpc_dw3_ds10);
mpc_dw3_vadd_6(mpc_dw3_dp_ir10, mpc_dw3_dp10, mpc_dw3_dp10);
mpc_dw3_vadd_16(mpc_dw3_dy_ir10, mpc_dw3_dy10, mpc_dw3_dy10);
mpc_dw3_vadd_16(mpc_dw3_dnu_ir10, mpc_dw3_dnu10, mpc_dw3_dnu10);
mpc_dw3_vadd_6(mpc_dw3_dx_ir11, mpc_dw3_dx11, mpc_dw3_dx11);
mpc_dw3_vadd_1(mpc_dw3_du_ir11, mpc_dw3_du11, mpc_dw3_du11);
mpc_dw3_vadd_4(mpc_dw3_ds_ir11, mpc_dw3_ds11, mpc_dw3_ds11);
mpc_dw3_vadd_6(mpc_dw3_dp_ir11, mpc_dw3_dp11, mpc_dw3_dp11);
mpc_dw3_vadd_8(mpc_dw3_dy_ir11, mpc_dw3_dy11, mpc_dw3_dy11);
mpc_dw3_vadd_8(mpc_dw3_dnu_ir11, mpc_dw3_dnu11, mpc_dw3_dnu11);
/* rhs wiederherstellen */
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir0, mpc_dw3_rf0x0);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir0, mpc_dw3_rf0u0);
mpc_dw3_v_copy_4(mpc_dw3_rf0s_ir0, mpc_dw3_rf0s0);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir0, mpc_dw3_rf0);
mpc_dw3_v_copy_8(mpc_dw3_rc_ir0, mpc_dw3_rc0);
mpc_dw3_v_copy_4(mpc_dw3_rs_ir0, mpc_dw3_rs0);
mpc_dw3_v_copy_8(mpc_dw3_rk_ir0, mpc_dw3_rk0);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir1, mpc_dw3_rf0x1);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir1, mpc_dw3_rf0u1);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir1, mpc_dw3_rf0s1);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir1, mpc_dw3_rf1);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir1, mpc_dw3_rc1);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir1, mpc_dw3_rs1);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir1, mpc_dw3_rk1);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir2, mpc_dw3_rf0x2);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir2, mpc_dw3_rf0u2);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir2, mpc_dw3_rf0s2);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir2, mpc_dw3_rf2);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir2, mpc_dw3_rc2);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir2, mpc_dw3_rs2);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir2, mpc_dw3_rk2);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir3, mpc_dw3_rf0x3);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir3, mpc_dw3_rf0u3);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir3, mpc_dw3_rf0s3);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir3, mpc_dw3_rf3);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir3, mpc_dw3_rc3);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir3, mpc_dw3_rs3);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir3, mpc_dw3_rk3);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir4, mpc_dw3_rf0x4);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir4, mpc_dw3_rf0u4);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir4, mpc_dw3_rf0s4);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir4, mpc_dw3_rf4);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir4, mpc_dw3_rc4);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir4, mpc_dw3_rs4);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir4, mpc_dw3_rk4);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir5, mpc_dw3_rf0x5);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir5, mpc_dw3_rf0u5);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir5, mpc_dw3_rf0s5);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir5, mpc_dw3_rf5);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir5, mpc_dw3_rc5);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir5, mpc_dw3_rs5);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir5, mpc_dw3_rk5);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir6, mpc_dw3_rf0x6);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir6, mpc_dw3_rf0u6);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir6, mpc_dw3_rf0s6);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir6, mpc_dw3_rf6);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir6, mpc_dw3_rc6);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir6, mpc_dw3_rs6);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir6, mpc_dw3_rk6);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir7, mpc_dw3_rf0x7);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir7, mpc_dw3_rf0u7);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir7, mpc_dw3_rf0s7);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir7, mpc_dw3_rf7);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir7, mpc_dw3_rc7);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir7, mpc_dw3_rs7);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir7, mpc_dw3_rk7);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir8, mpc_dw3_rf0x8);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir8, mpc_dw3_rf0u8);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir8, mpc_dw3_rf0s8);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir8, mpc_dw3_rf8);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir8, mpc_dw3_rc8);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir8, mpc_dw3_rs8);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir8, mpc_dw3_rk8);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir9, mpc_dw3_rf0x9);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir9, mpc_dw3_rf0u9);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir9, mpc_dw3_rf0s9);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir9, mpc_dw3_rf9);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir9, mpc_dw3_rc9);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir9, mpc_dw3_rs9);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir9, mpc_dw3_rk9);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir10, mpc_dw3_rf0x10);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir10, mpc_dw3_rf0u10);
mpc_dw3_v_copy_8(mpc_dw3_rf0s_ir10, mpc_dw3_rf0s10);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir10, mpc_dw3_rf10);
mpc_dw3_v_copy_16(mpc_dw3_rc_ir10, mpc_dw3_rc10);
mpc_dw3_v_copy_8(mpc_dw3_rs_ir10, mpc_dw3_rs10);
mpc_dw3_v_copy_16(mpc_dw3_rk_ir10, mpc_dw3_rk10);
mpc_dw3_v_copy_6(mpc_dw3_rf0x_ir11, mpc_dw3_rf0x11);
mpc_dw3_v_copy_1(mpc_dw3_rf0u_ir11, mpc_dw3_rf0u11);
mpc_dw3_v_copy_4(mpc_dw3_rf0s_ir11, mpc_dw3_rf0s11);
mpc_dw3_v_copy_6(mpc_dw3_rf_ir11, mpc_dw3_rf11);
mpc_dw3_v_copy_8(mpc_dw3_rc_ir11, mpc_dw3_rc11);
mpc_dw3_v_copy_4(mpc_dw3_rs_ir11, mpc_dw3_rs11);
mpc_dw3_v_copy_8(mpc_dw3_rk_ir11, mpc_dw3_rk11);
}
}


/* ####################################### */
/* Diese Funktion berechnet den Startpunkt */
/*           Startpunktmethode: 5          */
/* ####################################### */
static void mpc_dw3_glqdocpip_starting_point()
{
/* Very Cold Start */
/* Zeitschritt 0 */
mpc_dw3_v_init0_6(mpc_dw3_x0);
mpc_dw3_v_init0_1(mpc_dw3_u0);
mpc_dw3_v_init0_4(mpc_dw3_s0);
mpc_dw3_max(&mpc_dw3_s0[0], &mpc_dw3_g0[0], &mpc_dw3_s0[0]);
mpc_dw3_max(&mpc_dw3_s0[1], &mpc_dw3_g0[1], &mpc_dw3_s0[1]);
mpc_dw3_max(&mpc_dw3_s0[2], &mpc_dw3_g0[2], &mpc_dw3_s0[2]);
mpc_dw3_max(&mpc_dw3_s0[3], &mpc_dw3_g0[3], &mpc_dw3_s0[3]);
mpc_dw3_v_init0_6(mpc_dw3_p0);
mpc_dw3_v_init1_8(mpc_dw3_y0);
mpc_dw3_v_init1_8(mpc_dw3_nu0);
/* Zeitschritt 1 */
mpc_dw3_v_init0_6(mpc_dw3_x1);
mpc_dw3_v_init0_1(mpc_dw3_u1);
mpc_dw3_v_init0_8(mpc_dw3_s1);
mpc_dw3_max(&mpc_dw3_s1[0], &mpc_dw3_g1[0], &mpc_dw3_s1[0]);
mpc_dw3_max(&mpc_dw3_s1[1], &mpc_dw3_g1[1], &mpc_dw3_s1[1]);
mpc_dw3_max(&mpc_dw3_s1[2], &mpc_dw3_g1[2], &mpc_dw3_s1[2]);
mpc_dw3_max(&mpc_dw3_s1[3], &mpc_dw3_g1[3], &mpc_dw3_s1[3]);
mpc_dw3_max(&mpc_dw3_s1[4], &mpc_dw3_g1[4], &mpc_dw3_s1[4]);
mpc_dw3_max(&mpc_dw3_s1[5], &mpc_dw3_g1[5], &mpc_dw3_s1[5]);
mpc_dw3_max(&mpc_dw3_s1[6], &mpc_dw3_g1[6], &mpc_dw3_s1[6]);
mpc_dw3_max(&mpc_dw3_s1[7], &mpc_dw3_g1[7], &mpc_dw3_s1[7]);
mpc_dw3_v_init0_6(mpc_dw3_p1);
mpc_dw3_v_init1_16(mpc_dw3_y1);
mpc_dw3_v_init1_16(mpc_dw3_nu1);
/* Zeitschritt 2 */
mpc_dw3_v_init0_6(mpc_dw3_x2);
mpc_dw3_v_init0_1(mpc_dw3_u2);
mpc_dw3_v_init0_8(mpc_dw3_s2);
mpc_dw3_max(&mpc_dw3_s2[0], &mpc_dw3_g2[0], &mpc_dw3_s2[0]);
mpc_dw3_max(&mpc_dw3_s2[1], &mpc_dw3_g2[1], &mpc_dw3_s2[1]);
mpc_dw3_max(&mpc_dw3_s2[2], &mpc_dw3_g2[2], &mpc_dw3_s2[2]);
mpc_dw3_max(&mpc_dw3_s2[3], &mpc_dw3_g2[3], &mpc_dw3_s2[3]);
mpc_dw3_max(&mpc_dw3_s2[4], &mpc_dw3_g2[4], &mpc_dw3_s2[4]);
mpc_dw3_max(&mpc_dw3_s2[5], &mpc_dw3_g2[5], &mpc_dw3_s2[5]);
mpc_dw3_max(&mpc_dw3_s2[6], &mpc_dw3_g2[6], &mpc_dw3_s2[6]);
mpc_dw3_max(&mpc_dw3_s2[7], &mpc_dw3_g2[7], &mpc_dw3_s2[7]);
mpc_dw3_v_init0_6(mpc_dw3_p2);
mpc_dw3_v_init1_16(mpc_dw3_y2);
mpc_dw3_v_init1_16(mpc_dw3_nu2);
/* Zeitschritt 3 */
mpc_dw3_v_init0_6(mpc_dw3_x3);
mpc_dw3_v_init0_1(mpc_dw3_u3);
mpc_dw3_v_init0_8(mpc_dw3_s3);
mpc_dw3_max(&mpc_dw3_s3[0], &mpc_dw3_g3[0], &mpc_dw3_s3[0]);
mpc_dw3_max(&mpc_dw3_s3[1], &mpc_dw3_g3[1], &mpc_dw3_s3[1]);
mpc_dw3_max(&mpc_dw3_s3[2], &mpc_dw3_g3[2], &mpc_dw3_s3[2]);
mpc_dw3_max(&mpc_dw3_s3[3], &mpc_dw3_g3[3], &mpc_dw3_s3[3]);
mpc_dw3_max(&mpc_dw3_s3[4], &mpc_dw3_g3[4], &mpc_dw3_s3[4]);
mpc_dw3_max(&mpc_dw3_s3[5], &mpc_dw3_g3[5], &mpc_dw3_s3[5]);
mpc_dw3_max(&mpc_dw3_s3[6], &mpc_dw3_g3[6], &mpc_dw3_s3[6]);
mpc_dw3_max(&mpc_dw3_s3[7], &mpc_dw3_g3[7], &mpc_dw3_s3[7]);
mpc_dw3_v_init0_6(mpc_dw3_p3);
mpc_dw3_v_init1_16(mpc_dw3_y3);
mpc_dw3_v_init1_16(mpc_dw3_nu3);
/* Zeitschritt 4 */
mpc_dw3_v_init0_6(mpc_dw3_x4);
mpc_dw3_v_init0_1(mpc_dw3_u4);
mpc_dw3_v_init0_8(mpc_dw3_s4);
mpc_dw3_max(&mpc_dw3_s4[0], &mpc_dw3_g4[0], &mpc_dw3_s4[0]);
mpc_dw3_max(&mpc_dw3_s4[1], &mpc_dw3_g4[1], &mpc_dw3_s4[1]);
mpc_dw3_max(&mpc_dw3_s4[2], &mpc_dw3_g4[2], &mpc_dw3_s4[2]);
mpc_dw3_max(&mpc_dw3_s4[3], &mpc_dw3_g4[3], &mpc_dw3_s4[3]);
mpc_dw3_max(&mpc_dw3_s4[4], &mpc_dw3_g4[4], &mpc_dw3_s4[4]);
mpc_dw3_max(&mpc_dw3_s4[5], &mpc_dw3_g4[5], &mpc_dw3_s4[5]);
mpc_dw3_max(&mpc_dw3_s4[6], &mpc_dw3_g4[6], &mpc_dw3_s4[6]);
mpc_dw3_max(&mpc_dw3_s4[7], &mpc_dw3_g4[7], &mpc_dw3_s4[7]);
mpc_dw3_v_init0_6(mpc_dw3_p4);
mpc_dw3_v_init1_16(mpc_dw3_y4);
mpc_dw3_v_init1_16(mpc_dw3_nu4);
/* Zeitschritt 5 */
mpc_dw3_v_init0_6(mpc_dw3_x5);
mpc_dw3_v_init0_1(mpc_dw3_u5);
mpc_dw3_v_init0_8(mpc_dw3_s5);
mpc_dw3_max(&mpc_dw3_s5[0], &mpc_dw3_g5[0], &mpc_dw3_s5[0]);
mpc_dw3_max(&mpc_dw3_s5[1], &mpc_dw3_g5[1], &mpc_dw3_s5[1]);
mpc_dw3_max(&mpc_dw3_s5[2], &mpc_dw3_g5[2], &mpc_dw3_s5[2]);
mpc_dw3_max(&mpc_dw3_s5[3], &mpc_dw3_g5[3], &mpc_dw3_s5[3]);
mpc_dw3_max(&mpc_dw3_s5[4], &mpc_dw3_g5[4], &mpc_dw3_s5[4]);
mpc_dw3_max(&mpc_dw3_s5[5], &mpc_dw3_g5[5], &mpc_dw3_s5[5]);
mpc_dw3_max(&mpc_dw3_s5[6], &mpc_dw3_g5[6], &mpc_dw3_s5[6]);
mpc_dw3_max(&mpc_dw3_s5[7], &mpc_dw3_g5[7], &mpc_dw3_s5[7]);
mpc_dw3_v_init0_6(mpc_dw3_p5);
mpc_dw3_v_init1_16(mpc_dw3_y5);
mpc_dw3_v_init1_16(mpc_dw3_nu5);
/* Zeitschritt 6 */
mpc_dw3_v_init0_6(mpc_dw3_x6);
mpc_dw3_v_init0_1(mpc_dw3_u6);
mpc_dw3_v_init0_8(mpc_dw3_s6);
mpc_dw3_max(&mpc_dw3_s6[0], &mpc_dw3_g6[0], &mpc_dw3_s6[0]);
mpc_dw3_max(&mpc_dw3_s6[1], &mpc_dw3_g6[1], &mpc_dw3_s6[1]);
mpc_dw3_max(&mpc_dw3_s6[2], &mpc_dw3_g6[2], &mpc_dw3_s6[2]);
mpc_dw3_max(&mpc_dw3_s6[3], &mpc_dw3_g6[3], &mpc_dw3_s6[3]);
mpc_dw3_max(&mpc_dw3_s6[4], &mpc_dw3_g6[4], &mpc_dw3_s6[4]);
mpc_dw3_max(&mpc_dw3_s6[5], &mpc_dw3_g6[5], &mpc_dw3_s6[5]);
mpc_dw3_max(&mpc_dw3_s6[6], &mpc_dw3_g6[6], &mpc_dw3_s6[6]);
mpc_dw3_max(&mpc_dw3_s6[7], &mpc_dw3_g6[7], &mpc_dw3_s6[7]);
mpc_dw3_v_init0_6(mpc_dw3_p6);
mpc_dw3_v_init1_16(mpc_dw3_y6);
mpc_dw3_v_init1_16(mpc_dw3_nu6);
/* Zeitschritt 7 */
mpc_dw3_v_init0_6(mpc_dw3_x7);
mpc_dw3_v_init0_1(mpc_dw3_u7);
mpc_dw3_v_init0_8(mpc_dw3_s7);
mpc_dw3_max(&mpc_dw3_s7[0], &mpc_dw3_g7[0], &mpc_dw3_s7[0]);
mpc_dw3_max(&mpc_dw3_s7[1], &mpc_dw3_g7[1], &mpc_dw3_s7[1]);
mpc_dw3_max(&mpc_dw3_s7[2], &mpc_dw3_g7[2], &mpc_dw3_s7[2]);
mpc_dw3_max(&mpc_dw3_s7[3], &mpc_dw3_g7[3], &mpc_dw3_s7[3]);
mpc_dw3_max(&mpc_dw3_s7[4], &mpc_dw3_g7[4], &mpc_dw3_s7[4]);
mpc_dw3_max(&mpc_dw3_s7[5], &mpc_dw3_g7[5], &mpc_dw3_s7[5]);
mpc_dw3_max(&mpc_dw3_s7[6], &mpc_dw3_g7[6], &mpc_dw3_s7[6]);
mpc_dw3_max(&mpc_dw3_s7[7], &mpc_dw3_g7[7], &mpc_dw3_s7[7]);
mpc_dw3_v_init0_6(mpc_dw3_p7);
mpc_dw3_v_init1_16(mpc_dw3_y7);
mpc_dw3_v_init1_16(mpc_dw3_nu7);
/* Zeitschritt 8 */
mpc_dw3_v_init0_6(mpc_dw3_x8);
mpc_dw3_v_init0_1(mpc_dw3_u8);
mpc_dw3_v_init0_8(mpc_dw3_s8);
mpc_dw3_max(&mpc_dw3_s8[0], &mpc_dw3_g8[0], &mpc_dw3_s8[0]);
mpc_dw3_max(&mpc_dw3_s8[1], &mpc_dw3_g8[1], &mpc_dw3_s8[1]);
mpc_dw3_max(&mpc_dw3_s8[2], &mpc_dw3_g8[2], &mpc_dw3_s8[2]);
mpc_dw3_max(&mpc_dw3_s8[3], &mpc_dw3_g8[3], &mpc_dw3_s8[3]);
mpc_dw3_max(&mpc_dw3_s8[4], &mpc_dw3_g8[4], &mpc_dw3_s8[4]);
mpc_dw3_max(&mpc_dw3_s8[5], &mpc_dw3_g8[5], &mpc_dw3_s8[5]);
mpc_dw3_max(&mpc_dw3_s8[6], &mpc_dw3_g8[6], &mpc_dw3_s8[6]);
mpc_dw3_max(&mpc_dw3_s8[7], &mpc_dw3_g8[7], &mpc_dw3_s8[7]);
mpc_dw3_v_init0_6(mpc_dw3_p8);
mpc_dw3_v_init1_16(mpc_dw3_y8);
mpc_dw3_v_init1_16(mpc_dw3_nu8);
/* Zeitschritt 9 */
mpc_dw3_v_init0_6(mpc_dw3_x9);
mpc_dw3_v_init0_1(mpc_dw3_u9);
mpc_dw3_v_init0_8(mpc_dw3_s9);
mpc_dw3_max(&mpc_dw3_s9[0], &mpc_dw3_g9[0], &mpc_dw3_s9[0]);
mpc_dw3_max(&mpc_dw3_s9[1], &mpc_dw3_g9[1], &mpc_dw3_s9[1]);
mpc_dw3_max(&mpc_dw3_s9[2], &mpc_dw3_g9[2], &mpc_dw3_s9[2]);
mpc_dw3_max(&mpc_dw3_s9[3], &mpc_dw3_g9[3], &mpc_dw3_s9[3]);
mpc_dw3_max(&mpc_dw3_s9[4], &mpc_dw3_g9[4], &mpc_dw3_s9[4]);
mpc_dw3_max(&mpc_dw3_s9[5], &mpc_dw3_g9[5], &mpc_dw3_s9[5]);
mpc_dw3_max(&mpc_dw3_s9[6], &mpc_dw3_g9[6], &mpc_dw3_s9[6]);
mpc_dw3_max(&mpc_dw3_s9[7], &mpc_dw3_g9[7], &mpc_dw3_s9[7]);
mpc_dw3_v_init0_6(mpc_dw3_p9);
mpc_dw3_v_init1_16(mpc_dw3_y9);
mpc_dw3_v_init1_16(mpc_dw3_nu9);
/* Zeitschritt 10 */
mpc_dw3_v_init0_6(mpc_dw3_x10);
mpc_dw3_v_init0_1(mpc_dw3_u10);
mpc_dw3_v_init0_8(mpc_dw3_s10);
mpc_dw3_max(&mpc_dw3_s10[0], &mpc_dw3_g10[0], &mpc_dw3_s10[0]);
mpc_dw3_max(&mpc_dw3_s10[1], &mpc_dw3_g10[1], &mpc_dw3_s10[1]);
mpc_dw3_max(&mpc_dw3_s10[2], &mpc_dw3_g10[2], &mpc_dw3_s10[2]);
mpc_dw3_max(&mpc_dw3_s10[3], &mpc_dw3_g10[3], &mpc_dw3_s10[3]);
mpc_dw3_max(&mpc_dw3_s10[4], &mpc_dw3_g10[4], &mpc_dw3_s10[4]);
mpc_dw3_max(&mpc_dw3_s10[5], &mpc_dw3_g10[5], &mpc_dw3_s10[5]);
mpc_dw3_max(&mpc_dw3_s10[6], &mpc_dw3_g10[6], &mpc_dw3_s10[6]);
mpc_dw3_max(&mpc_dw3_s10[7], &mpc_dw3_g10[7], &mpc_dw3_s10[7]);
mpc_dw3_v_init0_6(mpc_dw3_p10);
mpc_dw3_v_init1_16(mpc_dw3_y10);
mpc_dw3_v_init1_16(mpc_dw3_nu10);
/* Zeitschritt 11 */
mpc_dw3_v_init0_6(mpc_dw3_x11);
mpc_dw3_v_init0_1(mpc_dw3_u11);
mpc_dw3_v_init0_4(mpc_dw3_s11);
mpc_dw3_max(&mpc_dw3_s11[0], &mpc_dw3_g11[0], &mpc_dw3_s11[0]);
mpc_dw3_max(&mpc_dw3_s11[1], &mpc_dw3_g11[1], &mpc_dw3_s11[1]);
mpc_dw3_max(&mpc_dw3_s11[2], &mpc_dw3_g11[2], &mpc_dw3_s11[2]);
mpc_dw3_max(&mpc_dw3_s11[3], &mpc_dw3_g11[3], &mpc_dw3_s11[3]);
mpc_dw3_v_init0_6(mpc_dw3_p11);
mpc_dw3_v_init1_8(mpc_dw3_y11);
mpc_dw3_v_init1_8(mpc_dw3_nu11);
/* Methode 5 */
/* Calc one step */
mpc_dw3_glqdocpip_rhs_starting_point_5();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_rhs_reduced();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_factor();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_solve();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_glqdocpip_dereduce();
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_v_copy_6(mpc_dw3_dx0, mpc_dw3_x0);
mpc_dw3_v_copy_1(mpc_dw3_du0, mpc_dw3_u0);
mpc_dw3_v_copy_4(mpc_dw3_ds0, mpc_dw3_s0);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g0[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s0[0], mpc_dw3_tmp1_1, &mpc_dw3_s0[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g0[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s0[1], mpc_dw3_tmp1_1, &mpc_dw3_s0[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g0[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s0[2], mpc_dw3_tmp1_1, &mpc_dw3_s0[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g0[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s0[3], mpc_dw3_tmp1_1, &mpc_dw3_s0[3]);
mpc_dw3_v_copy_6(mpc_dw3_dp0, mpc_dw3_p0);
mpc_dw3_vadd_8(mpc_dw3_y0, mpc_dw3_dy0, mpc_dw3_dy0);
mpc_dw3_vadd_8(mpc_dw3_nu0, mpc_dw3_dnu0, mpc_dw3_dnu0);
mpc_dw3_v_copy_6(mpc_dw3_dx1, mpc_dw3_x1);
mpc_dw3_v_copy_1(mpc_dw3_du1, mpc_dw3_u1);
mpc_dw3_v_copy_8(mpc_dw3_ds1, mpc_dw3_s1);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[0], mpc_dw3_tmp1_1, &mpc_dw3_s1[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[1], mpc_dw3_tmp1_1, &mpc_dw3_s1[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[2], mpc_dw3_tmp1_1, &mpc_dw3_s1[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[3], mpc_dw3_tmp1_1, &mpc_dw3_s1[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[4], mpc_dw3_tmp1_1, &mpc_dw3_s1[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[5], mpc_dw3_tmp1_1, &mpc_dw3_s1[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[6], mpc_dw3_tmp1_1, &mpc_dw3_s1[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g1[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s1[7], mpc_dw3_tmp1_1, &mpc_dw3_s1[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp1, mpc_dw3_p1);
mpc_dw3_vadd_16(mpc_dw3_y1, mpc_dw3_dy1, mpc_dw3_dy1);
mpc_dw3_vadd_16(mpc_dw3_nu1, mpc_dw3_dnu1, mpc_dw3_dnu1);
mpc_dw3_v_copy_6(mpc_dw3_dx2, mpc_dw3_x2);
mpc_dw3_v_copy_1(mpc_dw3_du2, mpc_dw3_u2);
mpc_dw3_v_copy_8(mpc_dw3_ds2, mpc_dw3_s2);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[0], mpc_dw3_tmp1_1, &mpc_dw3_s2[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[1], mpc_dw3_tmp1_1, &mpc_dw3_s2[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[2], mpc_dw3_tmp1_1, &mpc_dw3_s2[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[3], mpc_dw3_tmp1_1, &mpc_dw3_s2[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[4], mpc_dw3_tmp1_1, &mpc_dw3_s2[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[5], mpc_dw3_tmp1_1, &mpc_dw3_s2[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[6], mpc_dw3_tmp1_1, &mpc_dw3_s2[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g2[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s2[7], mpc_dw3_tmp1_1, &mpc_dw3_s2[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp2, mpc_dw3_p2);
mpc_dw3_vadd_16(mpc_dw3_y2, mpc_dw3_dy2, mpc_dw3_dy2);
mpc_dw3_vadd_16(mpc_dw3_nu2, mpc_dw3_dnu2, mpc_dw3_dnu2);
mpc_dw3_v_copy_6(mpc_dw3_dx3, mpc_dw3_x3);
mpc_dw3_v_copy_1(mpc_dw3_du3, mpc_dw3_u3);
mpc_dw3_v_copy_8(mpc_dw3_ds3, mpc_dw3_s3);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[0], mpc_dw3_tmp1_1, &mpc_dw3_s3[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[1], mpc_dw3_tmp1_1, &mpc_dw3_s3[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[2], mpc_dw3_tmp1_1, &mpc_dw3_s3[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[3], mpc_dw3_tmp1_1, &mpc_dw3_s3[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[4], mpc_dw3_tmp1_1, &mpc_dw3_s3[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[5], mpc_dw3_tmp1_1, &mpc_dw3_s3[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[6], mpc_dw3_tmp1_1, &mpc_dw3_s3[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g3[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s3[7], mpc_dw3_tmp1_1, &mpc_dw3_s3[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp3, mpc_dw3_p3);
mpc_dw3_vadd_16(mpc_dw3_y3, mpc_dw3_dy3, mpc_dw3_dy3);
mpc_dw3_vadd_16(mpc_dw3_nu3, mpc_dw3_dnu3, mpc_dw3_dnu3);
mpc_dw3_v_copy_6(mpc_dw3_dx4, mpc_dw3_x4);
mpc_dw3_v_copy_1(mpc_dw3_du4, mpc_dw3_u4);
mpc_dw3_v_copy_8(mpc_dw3_ds4, mpc_dw3_s4);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[0], mpc_dw3_tmp1_1, &mpc_dw3_s4[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[1], mpc_dw3_tmp1_1, &mpc_dw3_s4[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[2], mpc_dw3_tmp1_1, &mpc_dw3_s4[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[3], mpc_dw3_tmp1_1, &mpc_dw3_s4[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[4], mpc_dw3_tmp1_1, &mpc_dw3_s4[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[5], mpc_dw3_tmp1_1, &mpc_dw3_s4[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[6], mpc_dw3_tmp1_1, &mpc_dw3_s4[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g4[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s4[7], mpc_dw3_tmp1_1, &mpc_dw3_s4[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp4, mpc_dw3_p4);
mpc_dw3_vadd_16(mpc_dw3_y4, mpc_dw3_dy4, mpc_dw3_dy4);
mpc_dw3_vadd_16(mpc_dw3_nu4, mpc_dw3_dnu4, mpc_dw3_dnu4);
mpc_dw3_v_copy_6(mpc_dw3_dx5, mpc_dw3_x5);
mpc_dw3_v_copy_1(mpc_dw3_du5, mpc_dw3_u5);
mpc_dw3_v_copy_8(mpc_dw3_ds5, mpc_dw3_s5);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[0], mpc_dw3_tmp1_1, &mpc_dw3_s5[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[1], mpc_dw3_tmp1_1, &mpc_dw3_s5[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[2], mpc_dw3_tmp1_1, &mpc_dw3_s5[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[3], mpc_dw3_tmp1_1, &mpc_dw3_s5[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[4], mpc_dw3_tmp1_1, &mpc_dw3_s5[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[5], mpc_dw3_tmp1_1, &mpc_dw3_s5[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[6], mpc_dw3_tmp1_1, &mpc_dw3_s5[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g5[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s5[7], mpc_dw3_tmp1_1, &mpc_dw3_s5[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp5, mpc_dw3_p5);
mpc_dw3_vadd_16(mpc_dw3_y5, mpc_dw3_dy5, mpc_dw3_dy5);
mpc_dw3_vadd_16(mpc_dw3_nu5, mpc_dw3_dnu5, mpc_dw3_dnu5);
mpc_dw3_v_copy_6(mpc_dw3_dx6, mpc_dw3_x6);
mpc_dw3_v_copy_1(mpc_dw3_du6, mpc_dw3_u6);
mpc_dw3_v_copy_8(mpc_dw3_ds6, mpc_dw3_s6);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[0], mpc_dw3_tmp1_1, &mpc_dw3_s6[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[1], mpc_dw3_tmp1_1, &mpc_dw3_s6[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[2], mpc_dw3_tmp1_1, &mpc_dw3_s6[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[3], mpc_dw3_tmp1_1, &mpc_dw3_s6[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[4], mpc_dw3_tmp1_1, &mpc_dw3_s6[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[5], mpc_dw3_tmp1_1, &mpc_dw3_s6[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[6], mpc_dw3_tmp1_1, &mpc_dw3_s6[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g6[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s6[7], mpc_dw3_tmp1_1, &mpc_dw3_s6[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp6, mpc_dw3_p6);
mpc_dw3_vadd_16(mpc_dw3_y6, mpc_dw3_dy6, mpc_dw3_dy6);
mpc_dw3_vadd_16(mpc_dw3_nu6, mpc_dw3_dnu6, mpc_dw3_dnu6);
mpc_dw3_v_copy_6(mpc_dw3_dx7, mpc_dw3_x7);
mpc_dw3_v_copy_1(mpc_dw3_du7, mpc_dw3_u7);
mpc_dw3_v_copy_8(mpc_dw3_ds7, mpc_dw3_s7);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[0], mpc_dw3_tmp1_1, &mpc_dw3_s7[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[1], mpc_dw3_tmp1_1, &mpc_dw3_s7[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[2], mpc_dw3_tmp1_1, &mpc_dw3_s7[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[3], mpc_dw3_tmp1_1, &mpc_dw3_s7[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[4], mpc_dw3_tmp1_1, &mpc_dw3_s7[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[5], mpc_dw3_tmp1_1, &mpc_dw3_s7[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[6], mpc_dw3_tmp1_1, &mpc_dw3_s7[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g7[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s7[7], mpc_dw3_tmp1_1, &mpc_dw3_s7[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp7, mpc_dw3_p7);
mpc_dw3_vadd_16(mpc_dw3_y7, mpc_dw3_dy7, mpc_dw3_dy7);
mpc_dw3_vadd_16(mpc_dw3_nu7, mpc_dw3_dnu7, mpc_dw3_dnu7);
mpc_dw3_v_copy_6(mpc_dw3_dx8, mpc_dw3_x8);
mpc_dw3_v_copy_1(mpc_dw3_du8, mpc_dw3_u8);
mpc_dw3_v_copy_8(mpc_dw3_ds8, mpc_dw3_s8);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[0], mpc_dw3_tmp1_1, &mpc_dw3_s8[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[1], mpc_dw3_tmp1_1, &mpc_dw3_s8[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[2], mpc_dw3_tmp1_1, &mpc_dw3_s8[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[3], mpc_dw3_tmp1_1, &mpc_dw3_s8[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[4], mpc_dw3_tmp1_1, &mpc_dw3_s8[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[5], mpc_dw3_tmp1_1, &mpc_dw3_s8[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[6], mpc_dw3_tmp1_1, &mpc_dw3_s8[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g8[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s8[7], mpc_dw3_tmp1_1, &mpc_dw3_s8[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp8, mpc_dw3_p8);
mpc_dw3_vadd_16(mpc_dw3_y8, mpc_dw3_dy8, mpc_dw3_dy8);
mpc_dw3_vadd_16(mpc_dw3_nu8, mpc_dw3_dnu8, mpc_dw3_dnu8);
mpc_dw3_v_copy_6(mpc_dw3_dx9, mpc_dw3_x9);
mpc_dw3_v_copy_1(mpc_dw3_du9, mpc_dw3_u9);
mpc_dw3_v_copy_8(mpc_dw3_ds9, mpc_dw3_s9);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[0], mpc_dw3_tmp1_1, &mpc_dw3_s9[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[1], mpc_dw3_tmp1_1, &mpc_dw3_s9[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[2], mpc_dw3_tmp1_1, &mpc_dw3_s9[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[3], mpc_dw3_tmp1_1, &mpc_dw3_s9[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[4], mpc_dw3_tmp1_1, &mpc_dw3_s9[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[5], mpc_dw3_tmp1_1, &mpc_dw3_s9[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[6], mpc_dw3_tmp1_1, &mpc_dw3_s9[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g9[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s9[7], mpc_dw3_tmp1_1, &mpc_dw3_s9[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp9, mpc_dw3_p9);
mpc_dw3_vadd_16(mpc_dw3_y9, mpc_dw3_dy9, mpc_dw3_dy9);
mpc_dw3_vadd_16(mpc_dw3_nu9, mpc_dw3_dnu9, mpc_dw3_dnu9);
mpc_dw3_v_copy_6(mpc_dw3_dx10, mpc_dw3_x10);
mpc_dw3_v_copy_1(mpc_dw3_du10, mpc_dw3_u10);
mpc_dw3_v_copy_8(mpc_dw3_ds10, mpc_dw3_s10);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[0], mpc_dw3_tmp1_1, &mpc_dw3_s10[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[1], mpc_dw3_tmp1_1, &mpc_dw3_s10[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[2], mpc_dw3_tmp1_1, &mpc_dw3_s10[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[3], mpc_dw3_tmp1_1, &mpc_dw3_s10[3]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[4], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[4], mpc_dw3_tmp1_1, &mpc_dw3_s10[4]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[5], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[5], mpc_dw3_tmp1_1, &mpc_dw3_s10[5]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[6], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[6], mpc_dw3_tmp1_1, &mpc_dw3_s10[6]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g10[7], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s10[7], mpc_dw3_tmp1_1, &mpc_dw3_s10[7]);
mpc_dw3_v_copy_6(mpc_dw3_dp10, mpc_dw3_p10);
mpc_dw3_vadd_16(mpc_dw3_y10, mpc_dw3_dy10, mpc_dw3_dy10);
mpc_dw3_vadd_16(mpc_dw3_nu10, mpc_dw3_dnu10, mpc_dw3_dnu10);
mpc_dw3_v_copy_6(mpc_dw3_dx11, mpc_dw3_x11);
mpc_dw3_v_copy_1(mpc_dw3_du11, mpc_dw3_u11);
mpc_dw3_v_copy_4(mpc_dw3_ds11, mpc_dw3_s11);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g11[0], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s11[0], mpc_dw3_tmp1_1, &mpc_dw3_s11[0]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g11[1], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s11[1], mpc_dw3_tmp1_1, &mpc_dw3_s11[1]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g11[2], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s11[2], mpc_dw3_tmp1_1, &mpc_dw3_s11[2]);
mpc_dw3_v_init0_1(mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_g11[3], mpc_dw3_tmp1_1, mpc_dw3_tmp1_1);
mpc_dw3_max(&mpc_dw3_s11[3], mpc_dw3_tmp1_1, &mpc_dw3_s11[3]);
mpc_dw3_v_copy_6(mpc_dw3_dp11, mpc_dw3_p11);
mpc_dw3_vadd_8(mpc_dw3_y11, mpc_dw3_dy11, mpc_dw3_dy11);
mpc_dw3_vadd_8(mpc_dw3_nu11, mpc_dw3_dnu11, mpc_dw3_dnu11);
/* Init delta_y and delta_nu */
mpc_dw3_v_init0_1(mpc_dw3_starting_point_delta_y);
mpc_dw3_v_init0_1(mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp1_1[0] = -1.5;
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_8(mpc_dw3_dy0, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_8(mpc_dw3_dnu0, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy1, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu1, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy2, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu2, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy3, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu3, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy4, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu4, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy5, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu5, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy6, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu6, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy7, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu7, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy8, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu8, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy9, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu9, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dy10, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_16(mpc_dw3_dnu10, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_8(mpc_dw3_dy11, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y, mpc_dw3_starting_point_delta_y);
mpc_dw3_tmp2_1[0] = FLT_MAX;
mpc_dw3_v_min_8(mpc_dw3_dnu11, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vv_elemult_1(mpc_dw3_tmp2_1, mpc_dw3_tmp1_1, mpc_dw3_tmp2_1);
mpc_dw3_max(mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu, mpc_dw3_starting_point_delta_nu);
mpc_dw3_v_init0_1(mpc_dw3_starting_point_sum);
mpc_dw3_v_init0_1(mpc_dw3_starting_point_sum_y);
mpc_dw3_v_init0_1(mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8);
mpc_dw3_v_copy_8(mpc_dw3_dy0, mpc_dw3_tmp2_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_8, mpc_dw3_tmp2_8);
mpc_dw3_v_init1_8(mpc_dw3_tmp3_8);
mpc_dw3_v_copy_8(mpc_dw3_dnu0, mpc_dw3_tmp4_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_8, mpc_dw3_tmp4_8);
mpc_dw3_vtv_8(mpc_dw3_tmp2_8, mpc_dw3_tmp4_8, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_8(mpc_dw3_tmp2_8, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_8(mpc_dw3_tmp4_8, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_copy_16(mpc_dw3_dy1, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp3_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu1, mpc_dw3_tmp4_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_16, mpc_dw3_tmp4_16);
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp2_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp4_16);
mpc_dw3_v_copy_16(mpc_dw3_dy2, mpc_dw3_tmp3_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_16, mpc_dw3_tmp3_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu2, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vtv_16(mpc_dw3_tmp3_16, mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp3_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_copy_16(mpc_dw3_dy3, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp3_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu3, mpc_dw3_tmp4_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_16, mpc_dw3_tmp4_16);
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp2_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp4_16);
mpc_dw3_v_copy_16(mpc_dw3_dy4, mpc_dw3_tmp3_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_16, mpc_dw3_tmp3_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu4, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vtv_16(mpc_dw3_tmp3_16, mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp3_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_copy_16(mpc_dw3_dy5, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp3_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu5, mpc_dw3_tmp4_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_16, mpc_dw3_tmp4_16);
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp2_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp4_16);
mpc_dw3_v_copy_16(mpc_dw3_dy6, mpc_dw3_tmp3_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_16, mpc_dw3_tmp3_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu6, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vtv_16(mpc_dw3_tmp3_16, mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp3_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_copy_16(mpc_dw3_dy7, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp3_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu7, mpc_dw3_tmp4_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_16, mpc_dw3_tmp4_16);
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp2_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp4_16);
mpc_dw3_v_copy_16(mpc_dw3_dy8, mpc_dw3_tmp3_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_16, mpc_dw3_tmp3_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu8, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vtv_16(mpc_dw3_tmp3_16, mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp3_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_copy_16(mpc_dw3_dy9, mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp3_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu9, mpc_dw3_tmp4_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp3_16, mpc_dw3_tmp4_16);
mpc_dw3_vtv_16(mpc_dw3_tmp2_16, mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp2_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp4_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_16(mpc_dw3_tmp4_16);
mpc_dw3_v_copy_16(mpc_dw3_dy10, mpc_dw3_tmp3_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_16, mpc_dw3_tmp3_16);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_copy_16(mpc_dw3_dnu10, mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vtv_16(mpc_dw3_tmp3_16, mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_16(mpc_dw3_tmp3_16, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_16(mpc_dw3_tmp1_16, mpc_dw3_starting_point_sum_nu);
mpc_dw3_v_init1_8(mpc_dw3_tmp4_8);
mpc_dw3_v_copy_8(mpc_dw3_dy11, mpc_dw3_tmp3_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp4_8, mpc_dw3_tmp3_8);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8);
mpc_dw3_v_copy_8(mpc_dw3_dnu11, mpc_dw3_tmp1_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_8, mpc_dw3_tmp1_8);
mpc_dw3_vtv_8(mpc_dw3_tmp3_8, mpc_dw3_tmp1_8, mpc_dw3_starting_point_sum);
mpc_dw3_vsum_8(mpc_dw3_tmp3_8, mpc_dw3_starting_point_sum_y);
mpc_dw3_vsum_8(mpc_dw3_tmp1_8, mpc_dw3_starting_point_sum_nu);
mpc_dw3_tmp1_1[0] = 0.5;
mpc_dw3_vv_elediv_1(mpc_dw3_starting_point_sum, mpc_dw3_starting_point_sum_nu, mpc_dw3_tmp2_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_1(mpc_dw3_tmp1_1, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vadd_1(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_y);
mpc_dw3_vv_elediv_1(mpc_dw3_starting_point_sum, mpc_dw3_starting_point_sum_y, mpc_dw3_tmp2_1);
if(mpc_dw3_termcode > -1){return;}
mpc_dw3_vv_elemult_1(mpc_dw3_tmp1_1, mpc_dw3_tmp2_1, mpc_dw3_tmp2_1);
mpc_dw3_vadd_1(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_1, mpc_dw3_starting_point_delta_nu);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_8, mpc_dw3_tmp2_8);
mpc_dw3_vadd_8(mpc_dw3_dy0, mpc_dw3_tmp2_8, mpc_dw3_y0);
mpc_dw3_v_init1_8(mpc_dw3_tmp1_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp2_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_8, mpc_dw3_tmp2_8);
mpc_dw3_vadd_8(mpc_dw3_dnu0, mpc_dw3_tmp2_8, mpc_dw3_nu0);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dy1, mpc_dw3_tmp2_16, mpc_dw3_y1);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dnu1, mpc_dw3_tmp2_16, mpc_dw3_nu1);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dy2, mpc_dw3_tmp1_16, mpc_dw3_y2);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dnu2, mpc_dw3_tmp1_16, mpc_dw3_nu2);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dy3, mpc_dw3_tmp2_16, mpc_dw3_y3);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dnu3, mpc_dw3_tmp2_16, mpc_dw3_nu3);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dy4, mpc_dw3_tmp1_16, mpc_dw3_y4);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dnu4, mpc_dw3_tmp1_16, mpc_dw3_nu4);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dy5, mpc_dw3_tmp2_16, mpc_dw3_y5);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dnu5, mpc_dw3_tmp2_16, mpc_dw3_nu5);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dy6, mpc_dw3_tmp1_16, mpc_dw3_y6);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dnu6, mpc_dw3_tmp1_16, mpc_dw3_nu6);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dy7, mpc_dw3_tmp2_16, mpc_dw3_y7);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dnu7, mpc_dw3_tmp2_16, mpc_dw3_nu7);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dy8, mpc_dw3_tmp1_16, mpc_dw3_y8);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dnu8, mpc_dw3_tmp1_16, mpc_dw3_nu8);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dy9, mpc_dw3_tmp2_16, mpc_dw3_y9);
mpc_dw3_v_init1_16(mpc_dw3_tmp1_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp2_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp1_16, mpc_dw3_tmp2_16);
mpc_dw3_vadd_16(mpc_dw3_dnu9, mpc_dw3_tmp2_16, mpc_dw3_nu9);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dy10, mpc_dw3_tmp1_16, mpc_dw3_y10);
mpc_dw3_v_init1_16(mpc_dw3_tmp2_16);
mpc_dw3_v_init0_16(mpc_dw3_tmp1_16);
mpc_dw3_sv_16(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_16, mpc_dw3_tmp1_16);
mpc_dw3_vadd_16(mpc_dw3_dnu10, mpc_dw3_tmp1_16, mpc_dw3_nu10);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_y, mpc_dw3_tmp2_8, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_dy11, mpc_dw3_tmp1_8, mpc_dw3_y11);
mpc_dw3_v_init1_8(mpc_dw3_tmp2_8);
mpc_dw3_v_init0_8(mpc_dw3_tmp1_8);
mpc_dw3_sv_8(mpc_dw3_starting_point_delta_nu, mpc_dw3_tmp2_8, mpc_dw3_tmp1_8);
mpc_dw3_vadd_8(mpc_dw3_dnu11, mpc_dw3_tmp1_8, mpc_dw3_nu11);
}


void mpc_dw3_glqdocpip_init()
{
/* ## Parameter INIT ##  */
/* Anzahl Ungleichungsbedingungen */
mpc_dw3_m_ineq[0] = 176;
/* Toleranz (Abbruchkriterium) */
mpc_dw3_tol[0] = 0.0001;
/* Mehrotra Gamma */
mpc_dw3_mehrotra_gamma[0] = 0.01;
/* Machine Epsilon */
/* Init Berechnung */
mpc_dw3_v_init0_1(mpc_dw3_tmp3_1);
mpc_dw3_tmp2_1[0] = 1;
mpc_dw3_tmp1_1[0] = 1.0f - mpc_dw3_tmp2_1[0]/2;
/* Berechnungsschleife: while((1-div/2)!=1){div = div/2} */
while(mpc_dw3_tmp1_1[0] != 1.0f){
mpc_dw3_tmp2_1[0] = mpc_dw3_tmp2_1[0]/2;
mpc_dw3_tmp1_1[0] = 1.0f - mpc_dw3_tmp2_1[0]/2;
mpc_dw3_tmp3_1[0] += 1;
if(mpc_dw3_tmp3_1[0] > 100){
mpc_dw3_termcode = 10;
return;
}
}
mpc_dw3_macheps[0] = mpc_dw3_tmp2_1[0];
/* tau */
mpc_dw3_tau[0] = 3;
/* termcode */
mpc_dw3_termcode = -1;
/* Error Line */
mpc_dw3_error_line = 0;
/* Error Source */
mpc_dw3_error_source = 0;
/* termcode 1 factor */
mpc_dw3_tc1_factor[0] = 10000;
/* termcode 2 factor */
mpc_dw3_tc2_factor[0] = 100000000;
/* tmax */
mpc_dw3_time_max = 1;
/* max_iter */
mpc_dw3_max_iter = 20;
/* num_iter_ref */
mpc_dw3_stat_num_iter_ref = 0;
/* num_factor */
mpc_dw3_stat_num_factor = 0;
/* num_solve */
mpc_dw3_stat_num_solve = 0;
}


int mpc_dw3_glqdocpip()
{

/* High Performance Timer (Windows) */
mpc_dw3_glqdocpip_timer_start();

/* Init */
mpc_dw3_glqdocpip_init();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Anfangsnorm bestimmen (norm_d) */
mpc_dw3_glqdocpip_calc_norm_d();

/* starting point */
mpc_dw3_glqdocpip_starting_point();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Main Iteration Loop */
for(mpc_dw3_iter = 0; mpc_dw3_iter < mpc_dw3_max_iter; mpc_dw3_iter++){

/* Predictor rhs berechnen */
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Konvergenz- und Divergenztests, inkl. Berechnung der dafür nötigen Parameter */
mpc_dw3_glqdocpip_calc_norm_r();
mpc_dw3_glqdocpip_calc_mu();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_calc_duality_gap();
mpc_dw3_glqdocpip_calc_phi();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_stat();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_check_condiv();
/* Bei entsprechendem Termcode Funktion beenden */
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Predictor GLS faktorisieren */
mpc_dw3_glqdocpip_factor();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Predictor GLS lösen */
mpc_dw3_glqdocpip_solve();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_dereduce();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_iter_ref();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Korrekturfaktor für CorrectorGLS berechnen, */
/* inkl der dafür nötigen Parameter */
mpc_dw3_glqdocpip_max_stepsize();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_calc_mu_aff();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_calc_sigma();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Corrector rhs berechnen */
mpc_dw3_glqdocpip_rhs_corrector();
mpc_dw3_glqdocpip_rhs_reduced();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Corrector GLS lösen */
mpc_dw3_glqdocpip_solve();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_dereduce();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_iter_ref();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}

/* Schritt berechnen und durchführen */
mpc_dw3_glqdocpip_max_stepsize();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_calc_mu_aff();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_mehrotra_step();
if(mpc_dw3_termcode > -1){return mpc_dw3_termcode;}
mpc_dw3_glqdocpip_step();

/* Ende - Main Iteration Loop */
}


/* Termcode 3: Max Iterations exceeded */
mpc_dw3_termcode = 3;
return mpc_dw3_termcode;
}


double mpc_dw3_glqdocpip_performance_test_1_iteration()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_calc_norm_d();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_iter = 1;

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_calc_norm_r();
mpc_dw3_glqdocpip_calc_mu();
mpc_dw3_glqdocpip_calc_duality_gap();
mpc_dw3_glqdocpip_calc_phi();
mpc_dw3_glqdocpip_stat();
mpc_dw3_termcode = -1;
mpc_dw3_glqdocpip_factor();
mpc_dw3_glqdocpip_solve();
mpc_dw3_glqdocpip_dereduce();
mpc_dw3_glqdocpip_max_stepsize();
mpc_dw3_glqdocpip_calc_mu_aff();
mpc_dw3_glqdocpip_calc_sigma();
mpc_dw3_glqdocpip_rhs_corrector();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_solve();
mpc_dw3_glqdocpip_dereduce();
mpc_dw3_glqdocpip_max_stepsize();
mpc_dw3_glqdocpip_calc_mu_aff();
mpc_dw3_glqdocpip_mehrotra_step();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_factor()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_factor();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_solve()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_factor();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_solve();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_affine()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_rhs_affine();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_reduced()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_glqdocpip_rhs_affine();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_rhs_reduced();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_dereduce()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_factor();
mpc_dw3_glqdocpip_solve();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_rhs_reduced();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_norm_r()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_calc_norm_r();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_structure_mult_m_fx0()
{
int i;
mpc_dw3_glqdocpip_init();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 1000; i++){
mpc_dw3_mm_sid1_sid42_6_6_6(mpc_dw3_Hxx0, mpc_dw3_fx0, mpc_dw3_Gxx0);
}
return mpc_dw3_glqdocpip_timer_get()/1000*1000;
}


double mpc_dw3_glqdocpip_performance_test_1_iteration_iterref()
{
int i;
mpc_dw3_glqdocpip_init();
mpc_dw3_glqdocpip_calc_norm_d();
mpc_dw3_glqdocpip_starting_point();
mpc_dw3_iter = 1;

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_rhs_affine();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_calc_norm_r();
mpc_dw3_glqdocpip_calc_mu();
mpc_dw3_glqdocpip_calc_duality_gap();
mpc_dw3_glqdocpip_calc_phi();
mpc_dw3_glqdocpip_stat();
mpc_dw3_termcode = -1;
mpc_dw3_iter_ref = 1;
mpc_dw3_glqdocpip_factor();
mpc_dw3_glqdocpip_solve();
mpc_dw3_glqdocpip_dereduce();
mpc_dw3_glqdocpip_iter_ref();
mpc_dw3_glqdocpip_max_stepsize();
mpc_dw3_glqdocpip_calc_mu_aff();
mpc_dw3_glqdocpip_calc_sigma();
mpc_dw3_glqdocpip_rhs_corrector();
mpc_dw3_glqdocpip_rhs_reduced();
mpc_dw3_glqdocpip_solve();
mpc_dw3_glqdocpip_dereduce();
mpc_dw3_glqdocpip_iter_ref();
mpc_dw3_glqdocpip_max_stepsize();
mpc_dw3_glqdocpip_calc_mu_aff();
mpc_dw3_glqdocpip_mehrotra_step();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}


double mpc_dw3_glqdocpip_performance_test_starting()
{
int i;
mpc_dw3_glqdocpip_init();

mpc_dw3_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw3_glqdocpip_starting_point();
}
return mpc_dw3_glqdocpip_timer_get()/10*1000;
}
