/* mpc_dw0_glqdocpip.c */
/* Generiert: 07-Jul-2016 13:14:55 */


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
static float mpc_dw0_xinit[6];

/* Variablen für Disketisierungsstelle 0 */
/* Optimierungsvariablen */
static float mpc_dw0_x0[6];
static float mpc_dw0_u0[1];
static float mpc_dw0_s0[2];
static float mpc_dw0_p0[6];
static float mpc_dw0_y0[4];
static float mpc_dw0_nu0[4];
/* Schrittvariablen */
static float mpc_dw0_dx0[6];
static float mpc_dw0_du0[1];
static float mpc_dw0_ds0[2];
static float mpc_dw0_dp0[6];
static float mpc_dw0_dy0[4];
static float mpc_dw0_dnu0[4];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx0[36];
static float mpc_dw0_Hxu0[6];
static float mpc_dw0_Huu0[1];
static float mpc_dw0_Hss0[4];
static float mpc_dw0_f0x0[6];
static float mpc_dw0_f0u0[1];
static float mpc_dw0_f0s0[2];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx0[36];
static float mpc_dw0_fu0[6];
static float mpc_dw0_f0[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx0[12];
static float mpc_dw0_gu0[2];
static float mpc_dw0_g0[2];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x0[6];
static float mpc_dw0_rf0u0[1];
static float mpc_dw0_rf0s0[2];
static float mpc_dw0_rf0[6];
static float mpc_dw0_rc0[2];
static float mpc_dw0_rs0[2];
static float mpc_dw0_rk0[4];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x0[6];
static float mpc_dw0_rrf0u0[1];
static float mpc_dw0_rhsxs0[2];
static float mpc_dw0_yny0[2];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx0[36];
static float mpc_dw0_Gxu0[6];
static float mpc_dw0_Guu0[1];
static float mpc_dw0_Rux0[6];
static float mpc_dw0_Vxx0[36];
static float mpc_dw0_Gx0[6];
static float mpc_dw0_Gu0[1];
static float mpc_dw0_Ru0[1];
static float mpc_dw0_Vx0[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir0[6];
static float mpc_dw0_du_ir0[1];
static float mpc_dw0_ds_ir0[2];
static float mpc_dw0_dp_ir0[6];
static float mpc_dw0_dy_ir0[4];
static float mpc_dw0_dnu_ir0[4];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir0[6];
static float mpc_dw0_rf0u_ir0[1];
static float mpc_dw0_rf0s_ir0[2];
static float mpc_dw0_rf_ir0[6];
static float mpc_dw0_rc_ir0[2];
static float mpc_dw0_rs_ir0[2];
static float mpc_dw0_rk_ir0[4];

/* Variablen für Disketisierungsstelle 1 */
/* Optimierungsvariablen */
static float mpc_dw0_x1[6];
static float mpc_dw0_u1[1];
static float mpc_dw0_s1[4];
static float mpc_dw0_p1[6];
static float mpc_dw0_y1[8];
static float mpc_dw0_nu1[8];
/* Schrittvariablen */
static float mpc_dw0_dx1[6];
static float mpc_dw0_du1[1];
static float mpc_dw0_ds1[4];
static float mpc_dw0_dp1[6];
static float mpc_dw0_dy1[8];
static float mpc_dw0_dnu1[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx1[36];
static float mpc_dw0_Hxu1[6];
static float mpc_dw0_Huu1[1];
static float mpc_dw0_Hss1[16];
static float mpc_dw0_f0x1[6];
static float mpc_dw0_f0u1[1];
static float mpc_dw0_f0s1[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx1[36];
static float mpc_dw0_fu1[6];
static float mpc_dw0_f1[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx1[24];
static float mpc_dw0_gu1[4];
static float mpc_dw0_g1[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x1[6];
static float mpc_dw0_rf0u1[1];
static float mpc_dw0_rf0s1[4];
static float mpc_dw0_rf1[6];
static float mpc_dw0_rc1[4];
static float mpc_dw0_rs1[4];
static float mpc_dw0_rk1[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x1[6];
static float mpc_dw0_rrf0u1[1];
static float mpc_dw0_rhsxs1[4];
static float mpc_dw0_yny1[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx1[36];
static float mpc_dw0_Gxu1[6];
static float mpc_dw0_Guu1[1];
static float mpc_dw0_Rux1[6];
static float mpc_dw0_Vxx1[36];
static float mpc_dw0_Gx1[6];
static float mpc_dw0_Gu1[1];
static float mpc_dw0_Ru1[1];
static float mpc_dw0_Vx1[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir1[6];
static float mpc_dw0_du_ir1[1];
static float mpc_dw0_ds_ir1[4];
static float mpc_dw0_dp_ir1[6];
static float mpc_dw0_dy_ir1[8];
static float mpc_dw0_dnu_ir1[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir1[6];
static float mpc_dw0_rf0u_ir1[1];
static float mpc_dw0_rf0s_ir1[4];
static float mpc_dw0_rf_ir1[6];
static float mpc_dw0_rc_ir1[4];
static float mpc_dw0_rs_ir1[4];
static float mpc_dw0_rk_ir1[8];

/* Variablen für Disketisierungsstelle 2 */
/* Optimierungsvariablen */
static float mpc_dw0_x2[6];
static float mpc_dw0_u2[1];
static float mpc_dw0_s2[4];
static float mpc_dw0_p2[6];
static float mpc_dw0_y2[8];
static float mpc_dw0_nu2[8];
/* Schrittvariablen */
static float mpc_dw0_dx2[6];
static float mpc_dw0_du2[1];
static float mpc_dw0_ds2[4];
static float mpc_dw0_dp2[6];
static float mpc_dw0_dy2[8];
static float mpc_dw0_dnu2[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx2[36];
static float mpc_dw0_Hxu2[6];
static float mpc_dw0_Huu2[1];
static float mpc_dw0_Hss2[16];
static float mpc_dw0_f0x2[6];
static float mpc_dw0_f0u2[1];
static float mpc_dw0_f0s2[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx2[36];
static float mpc_dw0_fu2[6];
static float mpc_dw0_f2[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx2[24];
static float mpc_dw0_gu2[4];
static float mpc_dw0_g2[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x2[6];
static float mpc_dw0_rf0u2[1];
static float mpc_dw0_rf0s2[4];
static float mpc_dw0_rf2[6];
static float mpc_dw0_rc2[4];
static float mpc_dw0_rs2[4];
static float mpc_dw0_rk2[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x2[6];
static float mpc_dw0_rrf0u2[1];
static float mpc_dw0_rhsxs2[4];
static float mpc_dw0_yny2[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx2[36];
static float mpc_dw0_Gxu2[6];
static float mpc_dw0_Guu2[1];
static float mpc_dw0_Rux2[6];
static float mpc_dw0_Vxx2[36];
static float mpc_dw0_Gx2[6];
static float mpc_dw0_Gu2[1];
static float mpc_dw0_Ru2[1];
static float mpc_dw0_Vx2[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir2[6];
static float mpc_dw0_du_ir2[1];
static float mpc_dw0_ds_ir2[4];
static float mpc_dw0_dp_ir2[6];
static float mpc_dw0_dy_ir2[8];
static float mpc_dw0_dnu_ir2[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir2[6];
static float mpc_dw0_rf0u_ir2[1];
static float mpc_dw0_rf0s_ir2[4];
static float mpc_dw0_rf_ir2[6];
static float mpc_dw0_rc_ir2[4];
static float mpc_dw0_rs_ir2[4];
static float mpc_dw0_rk_ir2[8];

/* Variablen für Disketisierungsstelle 3 */
/* Optimierungsvariablen */
static float mpc_dw0_x3[6];
static float mpc_dw0_u3[1];
static float mpc_dw0_s3[4];
static float mpc_dw0_p3[6];
static float mpc_dw0_y3[8];
static float mpc_dw0_nu3[8];
/* Schrittvariablen */
static float mpc_dw0_dx3[6];
static float mpc_dw0_du3[1];
static float mpc_dw0_ds3[4];
static float mpc_dw0_dp3[6];
static float mpc_dw0_dy3[8];
static float mpc_dw0_dnu3[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx3[36];
static float mpc_dw0_Hxu3[6];
static float mpc_dw0_Huu3[1];
static float mpc_dw0_Hss3[16];
static float mpc_dw0_f0x3[6];
static float mpc_dw0_f0u3[1];
static float mpc_dw0_f0s3[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx3[36];
static float mpc_dw0_fu3[6];
static float mpc_dw0_f3[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx3[24];
static float mpc_dw0_gu3[4];
static float mpc_dw0_g3[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x3[6];
static float mpc_dw0_rf0u3[1];
static float mpc_dw0_rf0s3[4];
static float mpc_dw0_rf3[6];
static float mpc_dw0_rc3[4];
static float mpc_dw0_rs3[4];
static float mpc_dw0_rk3[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x3[6];
static float mpc_dw0_rrf0u3[1];
static float mpc_dw0_rhsxs3[4];
static float mpc_dw0_yny3[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx3[36];
static float mpc_dw0_Gxu3[6];
static float mpc_dw0_Guu3[1];
static float mpc_dw0_Rux3[6];
static float mpc_dw0_Vxx3[36];
static float mpc_dw0_Gx3[6];
static float mpc_dw0_Gu3[1];
static float mpc_dw0_Ru3[1];
static float mpc_dw0_Vx3[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir3[6];
static float mpc_dw0_du_ir3[1];
static float mpc_dw0_ds_ir3[4];
static float mpc_dw0_dp_ir3[6];
static float mpc_dw0_dy_ir3[8];
static float mpc_dw0_dnu_ir3[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir3[6];
static float mpc_dw0_rf0u_ir3[1];
static float mpc_dw0_rf0s_ir3[4];
static float mpc_dw0_rf_ir3[6];
static float mpc_dw0_rc_ir3[4];
static float mpc_dw0_rs_ir3[4];
static float mpc_dw0_rk_ir3[8];

/* Variablen für Disketisierungsstelle 4 */
/* Optimierungsvariablen */
static float mpc_dw0_x4[6];
static float mpc_dw0_u4[1];
static float mpc_dw0_s4[4];
static float mpc_dw0_p4[6];
static float mpc_dw0_y4[8];
static float mpc_dw0_nu4[8];
/* Schrittvariablen */
static float mpc_dw0_dx4[6];
static float mpc_dw0_du4[1];
static float mpc_dw0_ds4[4];
static float mpc_dw0_dp4[6];
static float mpc_dw0_dy4[8];
static float mpc_dw0_dnu4[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx4[36];
static float mpc_dw0_Hxu4[6];
static float mpc_dw0_Huu4[1];
static float mpc_dw0_Hss4[16];
static float mpc_dw0_f0x4[6];
static float mpc_dw0_f0u4[1];
static float mpc_dw0_f0s4[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx4[36];
static float mpc_dw0_fu4[6];
static float mpc_dw0_f4[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx4[24];
static float mpc_dw0_gu4[4];
static float mpc_dw0_g4[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x4[6];
static float mpc_dw0_rf0u4[1];
static float mpc_dw0_rf0s4[4];
static float mpc_dw0_rf4[6];
static float mpc_dw0_rc4[4];
static float mpc_dw0_rs4[4];
static float mpc_dw0_rk4[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x4[6];
static float mpc_dw0_rrf0u4[1];
static float mpc_dw0_rhsxs4[4];
static float mpc_dw0_yny4[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx4[36];
static float mpc_dw0_Gxu4[6];
static float mpc_dw0_Guu4[1];
static float mpc_dw0_Rux4[6];
static float mpc_dw0_Vxx4[36];
static float mpc_dw0_Gx4[6];
static float mpc_dw0_Gu4[1];
static float mpc_dw0_Ru4[1];
static float mpc_dw0_Vx4[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir4[6];
static float mpc_dw0_du_ir4[1];
static float mpc_dw0_ds_ir4[4];
static float mpc_dw0_dp_ir4[6];
static float mpc_dw0_dy_ir4[8];
static float mpc_dw0_dnu_ir4[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir4[6];
static float mpc_dw0_rf0u_ir4[1];
static float mpc_dw0_rf0s_ir4[4];
static float mpc_dw0_rf_ir4[6];
static float mpc_dw0_rc_ir4[4];
static float mpc_dw0_rs_ir4[4];
static float mpc_dw0_rk_ir4[8];

/* Variablen für Disketisierungsstelle 5 */
/* Optimierungsvariablen */
static float mpc_dw0_x5[6];
static float mpc_dw0_u5[1];
static float mpc_dw0_s5[4];
static float mpc_dw0_p5[6];
static float mpc_dw0_y5[8];
static float mpc_dw0_nu5[8];
/* Schrittvariablen */
static float mpc_dw0_dx5[6];
static float mpc_dw0_du5[1];
static float mpc_dw0_ds5[4];
static float mpc_dw0_dp5[6];
static float mpc_dw0_dy5[8];
static float mpc_dw0_dnu5[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx5[36];
static float mpc_dw0_Hxu5[6];
static float mpc_dw0_Huu5[1];
static float mpc_dw0_Hss5[16];
static float mpc_dw0_f0x5[6];
static float mpc_dw0_f0u5[1];
static float mpc_dw0_f0s5[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx5[36];
static float mpc_dw0_fu5[6];
static float mpc_dw0_f5[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx5[24];
static float mpc_dw0_gu5[4];
static float mpc_dw0_g5[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x5[6];
static float mpc_dw0_rf0u5[1];
static float mpc_dw0_rf0s5[4];
static float mpc_dw0_rf5[6];
static float mpc_dw0_rc5[4];
static float mpc_dw0_rs5[4];
static float mpc_dw0_rk5[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x5[6];
static float mpc_dw0_rrf0u5[1];
static float mpc_dw0_rhsxs5[4];
static float mpc_dw0_yny5[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx5[36];
static float mpc_dw0_Gxu5[6];
static float mpc_dw0_Guu5[1];
static float mpc_dw0_Rux5[6];
static float mpc_dw0_Vxx5[36];
static float mpc_dw0_Gx5[6];
static float mpc_dw0_Gu5[1];
static float mpc_dw0_Ru5[1];
static float mpc_dw0_Vx5[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir5[6];
static float mpc_dw0_du_ir5[1];
static float mpc_dw0_ds_ir5[4];
static float mpc_dw0_dp_ir5[6];
static float mpc_dw0_dy_ir5[8];
static float mpc_dw0_dnu_ir5[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir5[6];
static float mpc_dw0_rf0u_ir5[1];
static float mpc_dw0_rf0s_ir5[4];
static float mpc_dw0_rf_ir5[6];
static float mpc_dw0_rc_ir5[4];
static float mpc_dw0_rs_ir5[4];
static float mpc_dw0_rk_ir5[8];

/* Variablen für Disketisierungsstelle 6 */
/* Optimierungsvariablen */
static float mpc_dw0_x6[6];
static float mpc_dw0_u6[1];
static float mpc_dw0_s6[4];
static float mpc_dw0_p6[6];
static float mpc_dw0_y6[8];
static float mpc_dw0_nu6[8];
/* Schrittvariablen */
static float mpc_dw0_dx6[6];
static float mpc_dw0_du6[1];
static float mpc_dw0_ds6[4];
static float mpc_dw0_dp6[6];
static float mpc_dw0_dy6[8];
static float mpc_dw0_dnu6[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx6[36];
static float mpc_dw0_Hxu6[6];
static float mpc_dw0_Huu6[1];
static float mpc_dw0_Hss6[16];
static float mpc_dw0_f0x6[6];
static float mpc_dw0_f0u6[1];
static float mpc_dw0_f0s6[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx6[36];
static float mpc_dw0_fu6[6];
static float mpc_dw0_f6[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx6[24];
static float mpc_dw0_gu6[4];
static float mpc_dw0_g6[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x6[6];
static float mpc_dw0_rf0u6[1];
static float mpc_dw0_rf0s6[4];
static float mpc_dw0_rf6[6];
static float mpc_dw0_rc6[4];
static float mpc_dw0_rs6[4];
static float mpc_dw0_rk6[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x6[6];
static float mpc_dw0_rrf0u6[1];
static float mpc_dw0_rhsxs6[4];
static float mpc_dw0_yny6[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx6[36];
static float mpc_dw0_Gxu6[6];
static float mpc_dw0_Guu6[1];
static float mpc_dw0_Rux6[6];
static float mpc_dw0_Vxx6[36];
static float mpc_dw0_Gx6[6];
static float mpc_dw0_Gu6[1];
static float mpc_dw0_Ru6[1];
static float mpc_dw0_Vx6[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir6[6];
static float mpc_dw0_du_ir6[1];
static float mpc_dw0_ds_ir6[4];
static float mpc_dw0_dp_ir6[6];
static float mpc_dw0_dy_ir6[8];
static float mpc_dw0_dnu_ir6[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir6[6];
static float mpc_dw0_rf0u_ir6[1];
static float mpc_dw0_rf0s_ir6[4];
static float mpc_dw0_rf_ir6[6];
static float mpc_dw0_rc_ir6[4];
static float mpc_dw0_rs_ir6[4];
static float mpc_dw0_rk_ir6[8];

/* Variablen für Disketisierungsstelle 7 */
/* Optimierungsvariablen */
static float mpc_dw0_x7[6];
static float mpc_dw0_u7[1];
static float mpc_dw0_s7[4];
static float mpc_dw0_p7[6];
static float mpc_dw0_y7[8];
static float mpc_dw0_nu7[8];
/* Schrittvariablen */
static float mpc_dw0_dx7[6];
static float mpc_dw0_du7[1];
static float mpc_dw0_ds7[4];
static float mpc_dw0_dp7[6];
static float mpc_dw0_dy7[8];
static float mpc_dw0_dnu7[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx7[36];
static float mpc_dw0_Hxu7[6];
static float mpc_dw0_Huu7[1];
static float mpc_dw0_Hss7[16];
static float mpc_dw0_f0x7[6];
static float mpc_dw0_f0u7[1];
static float mpc_dw0_f0s7[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx7[36];
static float mpc_dw0_fu7[6];
static float mpc_dw0_f7[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx7[24];
static float mpc_dw0_gu7[4];
static float mpc_dw0_g7[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x7[6];
static float mpc_dw0_rf0u7[1];
static float mpc_dw0_rf0s7[4];
static float mpc_dw0_rf7[6];
static float mpc_dw0_rc7[4];
static float mpc_dw0_rs7[4];
static float mpc_dw0_rk7[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x7[6];
static float mpc_dw0_rrf0u7[1];
static float mpc_dw0_rhsxs7[4];
static float mpc_dw0_yny7[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx7[36];
static float mpc_dw0_Gxu7[6];
static float mpc_dw0_Guu7[1];
static float mpc_dw0_Rux7[6];
static float mpc_dw0_Vxx7[36];
static float mpc_dw0_Gx7[6];
static float mpc_dw0_Gu7[1];
static float mpc_dw0_Ru7[1];
static float mpc_dw0_Vx7[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir7[6];
static float mpc_dw0_du_ir7[1];
static float mpc_dw0_ds_ir7[4];
static float mpc_dw0_dp_ir7[6];
static float mpc_dw0_dy_ir7[8];
static float mpc_dw0_dnu_ir7[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir7[6];
static float mpc_dw0_rf0u_ir7[1];
static float mpc_dw0_rf0s_ir7[4];
static float mpc_dw0_rf_ir7[6];
static float mpc_dw0_rc_ir7[4];
static float mpc_dw0_rs_ir7[4];
static float mpc_dw0_rk_ir7[8];

/* Variablen für Disketisierungsstelle 8 */
/* Optimierungsvariablen */
static float mpc_dw0_x8[6];
static float mpc_dw0_u8[1];
static float mpc_dw0_s8[4];
static float mpc_dw0_p8[6];
static float mpc_dw0_y8[8];
static float mpc_dw0_nu8[8];
/* Schrittvariablen */
static float mpc_dw0_dx8[6];
static float mpc_dw0_du8[1];
static float mpc_dw0_ds8[4];
static float mpc_dw0_dp8[6];
static float mpc_dw0_dy8[8];
static float mpc_dw0_dnu8[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx8[36];
static float mpc_dw0_Hxu8[6];
static float mpc_dw0_Huu8[1];
static float mpc_dw0_Hss8[16];
static float mpc_dw0_f0x8[6];
static float mpc_dw0_f0u8[1];
static float mpc_dw0_f0s8[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx8[36];
static float mpc_dw0_fu8[6];
static float mpc_dw0_f8[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx8[24];
static float mpc_dw0_gu8[4];
static float mpc_dw0_g8[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x8[6];
static float mpc_dw0_rf0u8[1];
static float mpc_dw0_rf0s8[4];
static float mpc_dw0_rf8[6];
static float mpc_dw0_rc8[4];
static float mpc_dw0_rs8[4];
static float mpc_dw0_rk8[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x8[6];
static float mpc_dw0_rrf0u8[1];
static float mpc_dw0_rhsxs8[4];
static float mpc_dw0_yny8[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx8[36];
static float mpc_dw0_Gxu8[6];
static float mpc_dw0_Guu8[1];
static float mpc_dw0_Rux8[6];
static float mpc_dw0_Vxx8[36];
static float mpc_dw0_Gx8[6];
static float mpc_dw0_Gu8[1];
static float mpc_dw0_Ru8[1];
static float mpc_dw0_Vx8[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir8[6];
static float mpc_dw0_du_ir8[1];
static float mpc_dw0_ds_ir8[4];
static float mpc_dw0_dp_ir8[6];
static float mpc_dw0_dy_ir8[8];
static float mpc_dw0_dnu_ir8[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir8[6];
static float mpc_dw0_rf0u_ir8[1];
static float mpc_dw0_rf0s_ir8[4];
static float mpc_dw0_rf_ir8[6];
static float mpc_dw0_rc_ir8[4];
static float mpc_dw0_rs_ir8[4];
static float mpc_dw0_rk_ir8[8];

/* Variablen für Disketisierungsstelle 9 */
/* Optimierungsvariablen */
static float mpc_dw0_x9[6];
static float mpc_dw0_u9[1];
static float mpc_dw0_s9[4];
static float mpc_dw0_p9[6];
static float mpc_dw0_y9[8];
static float mpc_dw0_nu9[8];
/* Schrittvariablen */
static float mpc_dw0_dx9[6];
static float mpc_dw0_du9[1];
static float mpc_dw0_ds9[4];
static float mpc_dw0_dp9[6];
static float mpc_dw0_dy9[8];
static float mpc_dw0_dnu9[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx9[36];
static float mpc_dw0_Hxu9[6];
static float mpc_dw0_Huu9[1];
static float mpc_dw0_Hss9[16];
static float mpc_dw0_f0x9[6];
static float mpc_dw0_f0u9[1];
static float mpc_dw0_f0s9[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx9[36];
static float mpc_dw0_fu9[6];
static float mpc_dw0_f9[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx9[24];
static float mpc_dw0_gu9[4];
static float mpc_dw0_g9[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x9[6];
static float mpc_dw0_rf0u9[1];
static float mpc_dw0_rf0s9[4];
static float mpc_dw0_rf9[6];
static float mpc_dw0_rc9[4];
static float mpc_dw0_rs9[4];
static float mpc_dw0_rk9[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x9[6];
static float mpc_dw0_rrf0u9[1];
static float mpc_dw0_rhsxs9[4];
static float mpc_dw0_yny9[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx9[36];
static float mpc_dw0_Gxu9[6];
static float mpc_dw0_Guu9[1];
static float mpc_dw0_Rux9[6];
static float mpc_dw0_Vxx9[36];
static float mpc_dw0_Gx9[6];
static float mpc_dw0_Gu9[1];
static float mpc_dw0_Ru9[1];
static float mpc_dw0_Vx9[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir9[6];
static float mpc_dw0_du_ir9[1];
static float mpc_dw0_ds_ir9[4];
static float mpc_dw0_dp_ir9[6];
static float mpc_dw0_dy_ir9[8];
static float mpc_dw0_dnu_ir9[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir9[6];
static float mpc_dw0_rf0u_ir9[1];
static float mpc_dw0_rf0s_ir9[4];
static float mpc_dw0_rf_ir9[6];
static float mpc_dw0_rc_ir9[4];
static float mpc_dw0_rs_ir9[4];
static float mpc_dw0_rk_ir9[8];

/* Variablen für Disketisierungsstelle 10 */
/* Optimierungsvariablen */
static float mpc_dw0_x10[6];
static float mpc_dw0_u10[1];
static float mpc_dw0_s10[4];
static float mpc_dw0_p10[6];
static float mpc_dw0_y10[8];
static float mpc_dw0_nu10[8];
/* Schrittvariablen */
static float mpc_dw0_dx10[6];
static float mpc_dw0_du10[1];
static float mpc_dw0_ds10[4];
static float mpc_dw0_dp10[6];
static float mpc_dw0_dy10[8];
static float mpc_dw0_dnu10[8];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx10[36];
static float mpc_dw0_Hxu10[6];
static float mpc_dw0_Huu10[1];
static float mpc_dw0_Hss10[16];
static float mpc_dw0_f0x10[6];
static float mpc_dw0_f0u10[1];
static float mpc_dw0_f0s10[4];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx10[36];
static float mpc_dw0_fu10[6];
static float mpc_dw0_f10[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx10[24];
static float mpc_dw0_gu10[4];
static float mpc_dw0_g10[4];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x10[6];
static float mpc_dw0_rf0u10[1];
static float mpc_dw0_rf0s10[4];
static float mpc_dw0_rf10[6];
static float mpc_dw0_rc10[4];
static float mpc_dw0_rs10[4];
static float mpc_dw0_rk10[8];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x10[6];
static float mpc_dw0_rrf0u10[1];
static float mpc_dw0_rhsxs10[4];
static float mpc_dw0_yny10[4];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx10[36];
static float mpc_dw0_Gxu10[6];
static float mpc_dw0_Guu10[1];
static float mpc_dw0_Rux10[6];
static float mpc_dw0_Vxx10[36];
static float mpc_dw0_Gx10[6];
static float mpc_dw0_Gu10[1];
static float mpc_dw0_Ru10[1];
static float mpc_dw0_Vx10[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir10[6];
static float mpc_dw0_du_ir10[1];
static float mpc_dw0_ds_ir10[4];
static float mpc_dw0_dp_ir10[6];
static float mpc_dw0_dy_ir10[8];
static float mpc_dw0_dnu_ir10[8];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir10[6];
static float mpc_dw0_rf0u_ir10[1];
static float mpc_dw0_rf0s_ir10[4];
static float mpc_dw0_rf_ir10[6];
static float mpc_dw0_rc_ir10[4];
static float mpc_dw0_rs_ir10[4];
static float mpc_dw0_rk_ir10[8];

/* Variablen für Disketisierungsstelle 11 */
/* Optimierungsvariablen */
static float mpc_dw0_x11[6];
static float mpc_dw0_u11[1];
static float mpc_dw0_s11[2];
static float mpc_dw0_p11[6];
static float mpc_dw0_y11[4];
static float mpc_dw0_nu11[4];
/* Schrittvariablen */
static float mpc_dw0_dx11[6];
static float mpc_dw0_du11[1];
static float mpc_dw0_ds11[2];
static float mpc_dw0_dp11[6];
static float mpc_dw0_dy11[4];
static float mpc_dw0_dnu11[4];
/* Variablen der Guetefunktion */
static float mpc_dw0_Hxx11[36];
static float mpc_dw0_Hxu11[6];
static float mpc_dw0_Huu11[1];
static float mpc_dw0_Hss11[4];
static float mpc_dw0_f0x11[6];
static float mpc_dw0_f0u11[1];
static float mpc_dw0_f0s11[2];
/* Variablen der Gleichungsnebenbedingungen */
static float mpc_dw0_fx11[36];
static float mpc_dw0_fu11[6];
static float mpc_dw0_f11[6];
/* Variablen der Ungleichungsnebenbedingungen */
static float mpc_dw0_gx11[12];
static float mpc_dw0_gu11[2];
static float mpc_dw0_g11[2];
/* Variablen der rechten Seiten */
static float mpc_dw0_rf0x11[6];
static float mpc_dw0_rf0u11[1];
static float mpc_dw0_rf0s11[2];
static float mpc_dw0_rf11[6];
static float mpc_dw0_rc11[2];
static float mpc_dw0_rs11[2];
static float mpc_dw0_rk11[4];
/* Variablen der reduzierten rechten Seiten */
static float mpc_dw0_rrf0x11[6];
static float mpc_dw0_rrf0u11[1];
static float mpc_dw0_rhsxs11[2];
static float mpc_dw0_yny11[2];
/* Variablen fuer das Blockeliminationsverfahren */
static float mpc_dw0_Gxx11[36];
static float mpc_dw0_Gxu11[6];
static float mpc_dw0_Guu11[1];
static float mpc_dw0_Rux11[6];
static float mpc_dw0_Vxx11[36];
static float mpc_dw0_Gx11[6];
static float mpc_dw0_Gu11[1];
static float mpc_dw0_Ru11[1];
static float mpc_dw0_Vx11[6];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static float mpc_dw0_dx_ir11[6];
static float mpc_dw0_du_ir11[1];
static float mpc_dw0_ds_ir11[2];
static float mpc_dw0_dp_ir11[6];
static float mpc_dw0_dy_ir11[4];
static float mpc_dw0_dnu_ir11[4];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static float mpc_dw0_rf0x_ir11[6];
static float mpc_dw0_rf0u_ir11[1];
static float mpc_dw0_rf0s_ir11[2];
static float mpc_dw0_rf_ir11[6];
static float mpc_dw0_rc_ir11[2];
static float mpc_dw0_rs_ir11[2];
static float mpc_dw0_rk_ir11[4];

/* Temporäre Variablen */
static float mpc_dw0_tmp1_2_1[2];
static float mpc_dw0_tmp2_2_1[2];
static float mpc_dw0_tmp3_2_1[2];
static float mpc_dw0_tmp1_0_1[1];
static float mpc_dw0_tmp1_4_1[4];
static float mpc_dw0_tmp2_4_1[4];
static float mpc_dw0_tmp3_4_1[4];
static float mpc_dw0_tmp1_4[4];
static float mpc_dw0_tmp2_4[4];
static float mpc_dw0_tmp3_4[4];
static float mpc_dw0_tmp4_4[4];
static float mpc_dw0_tmp1_1[1];
static float mpc_dw0_tmp2_1[1];
static float mpc_dw0_tmp3_1[1];
static float mpc_dw0_tmp1_8[8];
static float mpc_dw0_tmp2_8[8];
static float mpc_dw0_tmp3_8[8];
static float mpc_dw0_tmp4_8[8];
static float mpc_dw0_tmp1_6_6[36];
static float mpc_dw0_tmp1_6_2[12];
static float mpc_dw0_tmp1_1_6[6];
static float mpc_dw0_tmp1_1_2[2];
static float mpc_dw0_tmp1_6_4[24];
static float mpc_dw0_tmp1_1_4[4];
static float mpc_dw0_tmp1_6[6];
static float mpc_dw0_tmp1_6_1[6];
static float mpc_dw0_tmp1_1_1[1];
static float mpc_dw0_tmp2_1_1[1];

/* Temporäre Variablen für Cholesky Zerlegung */
static float mpc_dw0_L0[1];
static float mpc_dw0_L1[1];
static float mpc_dw0_L2[1];
static float mpc_dw0_L3[1];
static float mpc_dw0_L4[1];
static float mpc_dw0_L5[1];
static float mpc_dw0_L6[1];
static float mpc_dw0_L7[1];
static float mpc_dw0_L8[1];
static float mpc_dw0_L9[1];
static float mpc_dw0_L10[1];
static float mpc_dw0_L11[1];

/* Variablen für max_stepsize */
static float mpc_dw0_alpha_max[1];
static float mpc_dw0_alpha_tmp[1];
static float mpc_dw0_alpha_min_y[1];
static float mpc_dw0_alpha_min_dy[1];
static float mpc_dw0_alpha_min_nu[1];
static float mpc_dw0_alpha_min_dnu[1];
static int mpc_dw0_alpha_min_source_y;

/* Variablen für mehrotra_step */
static float mpc_dw0_mehrotra_alpha[1];
static float mpc_dw0_mehrotra_gamma[1];
static float mpc_dw0_mehrotra_fpd[1];

/* Verschiedenes */
static int mpc_dw0_iter;
static int mpc_dw0_max_iter;
static int mpc_dw0_termcode;
static int mpc_dw0_iter_ref;
static int mpc_dw0_error_line;
static int mpc_dw0_error_source;
static float mpc_dw0_m_ineq[1];
static float mpc_dw0_macheps[1];
static float mpc_dw0_tau[1];
static float mpc_dw0_sigma[1];
static float mpc_dw0_norm_d[1];
static float mpc_dw0_norm_r[1];
static float mpc_dw0_norm_r0[1];
static float mpc_dw0_norm_r_prev[1];
static float mpc_dw0_mu[1];
static float mpc_dw0_mu0[1];
static float mpc_dw0_mu_aff[1];
static float mpc_dw0_phi[1];
static float mpc_dw0_minphi[1];
static float mpc_dw0_tol[1];
static float mpc_dw0_tc1_factor[1];
static float mpc_dw0_tc2_factor[1];
static double mpc_dw0_timer_start;
static double mpc_dw0_time_max;

/* Variablen für Duality Gap */
static float mpc_dw0_dgap[1];

/* Variablen für Starting Point */
static float mpc_dw0_starting_point_delta_y[1];
static float mpc_dw0_starting_point_delta_nu[1];
static float mpc_dw0_starting_point_sum[1];
static float mpc_dw0_starting_point_sum_y[1];
static float mpc_dw0_starting_point_sum_nu[1];

/* Variablen für Statistik */
static float mpc_dw0_stat_time[20];
static int mpc_dw0_stat_iter_ref[20];
static int mpc_dw0_stat_num_iter_ref;
static int mpc_dw0_stat_num_factor;
static int mpc_dw0_stat_num_solve;



float *mpc_dw0_get_x0()
{
return mpc_dw0_xinit;
}

float *mpc_dw0_get_x(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_x0;
    case 1: return mpc_dw0_x1;
    case 2: return mpc_dw0_x2;
    case 3: return mpc_dw0_x3;
    case 4: return mpc_dw0_x4;
    case 5: return mpc_dw0_x5;
    case 6: return mpc_dw0_x6;
    case 7: return mpc_dw0_x7;
    case 8: return mpc_dw0_x8;
    case 9: return mpc_dw0_x9;
    case 10: return mpc_dw0_x10;
    case 11: return mpc_dw0_x11;
    default: return 0;
  }
}

float *mpc_dw0_get_u(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_u0;
    case 1: return mpc_dw0_u1;
    case 2: return mpc_dw0_u2;
    case 3: return mpc_dw0_u3;
    case 4: return mpc_dw0_u4;
    case 5: return mpc_dw0_u5;
    case 6: return mpc_dw0_u6;
    case 7: return mpc_dw0_u7;
    case 8: return mpc_dw0_u8;
    case 9: return mpc_dw0_u9;
    case 10: return mpc_dw0_u10;
    case 11: return mpc_dw0_u11;
    default: return 0;
  }
}

float *mpc_dw0_get_s(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_s0;
    case 1: return mpc_dw0_s1;
    case 2: return mpc_dw0_s2;
    case 3: return mpc_dw0_s3;
    case 4: return mpc_dw0_s4;
    case 5: return mpc_dw0_s5;
    case 6: return mpc_dw0_s6;
    case 7: return mpc_dw0_s7;
    case 8: return mpc_dw0_s8;
    case 9: return mpc_dw0_s9;
    case 10: return mpc_dw0_s10;
    case 11: return mpc_dw0_s11;
    default: return 0;
  }
}

float *mpc_dw0_get_p(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_p0;
    case 1: return mpc_dw0_p1;
    case 2: return mpc_dw0_p2;
    case 3: return mpc_dw0_p3;
    case 4: return mpc_dw0_p4;
    case 5: return mpc_dw0_p5;
    case 6: return mpc_dw0_p6;
    case 7: return mpc_dw0_p7;
    case 8: return mpc_dw0_p8;
    case 9: return mpc_dw0_p9;
    case 10: return mpc_dw0_p10;
    case 11: return mpc_dw0_p11;
    default: return 0;
  }
}

float *mpc_dw0_get_y(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_y0;
    case 1: return mpc_dw0_y1;
    case 2: return mpc_dw0_y2;
    case 3: return mpc_dw0_y3;
    case 4: return mpc_dw0_y4;
    case 5: return mpc_dw0_y5;
    case 6: return mpc_dw0_y6;
    case 7: return mpc_dw0_y7;
    case 8: return mpc_dw0_y8;
    case 9: return mpc_dw0_y9;
    case 10: return mpc_dw0_y10;
    case 11: return mpc_dw0_y11;
    default: return 0;
  }
}

float *mpc_dw0_get_nu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_nu0;
    case 1: return mpc_dw0_nu1;
    case 2: return mpc_dw0_nu2;
    case 3: return mpc_dw0_nu3;
    case 4: return mpc_dw0_nu4;
    case 5: return mpc_dw0_nu5;
    case 6: return mpc_dw0_nu6;
    case 7: return mpc_dw0_nu7;
    case 8: return mpc_dw0_nu8;
    case 9: return mpc_dw0_nu9;
    case 10: return mpc_dw0_nu10;
    case 11: return mpc_dw0_nu11;
    default: return 0;
  }
}

float *mpc_dw0_get_Hxx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_Hxx0;
    case 1: return mpc_dw0_Hxx1;
    case 2: return mpc_dw0_Hxx2;
    case 3: return mpc_dw0_Hxx3;
    case 4: return mpc_dw0_Hxx4;
    case 5: return mpc_dw0_Hxx5;
    case 6: return mpc_dw0_Hxx6;
    case 7: return mpc_dw0_Hxx7;
    case 8: return mpc_dw0_Hxx8;
    case 9: return mpc_dw0_Hxx9;
    case 10: return mpc_dw0_Hxx10;
    case 11: return mpc_dw0_Hxx11;
    default: return 0;
  }
}

float *mpc_dw0_get_Hxu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_Hxu0;
    case 1: return mpc_dw0_Hxu1;
    case 2: return mpc_dw0_Hxu2;
    case 3: return mpc_dw0_Hxu3;
    case 4: return mpc_dw0_Hxu4;
    case 5: return mpc_dw0_Hxu5;
    case 6: return mpc_dw0_Hxu6;
    case 7: return mpc_dw0_Hxu7;
    case 8: return mpc_dw0_Hxu8;
    case 9: return mpc_dw0_Hxu9;
    case 10: return mpc_dw0_Hxu10;
    case 11: return mpc_dw0_Hxu11;
    default: return 0;
  }
}

float *mpc_dw0_get_Huu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_Huu0;
    case 1: return mpc_dw0_Huu1;
    case 2: return mpc_dw0_Huu2;
    case 3: return mpc_dw0_Huu3;
    case 4: return mpc_dw0_Huu4;
    case 5: return mpc_dw0_Huu5;
    case 6: return mpc_dw0_Huu6;
    case 7: return mpc_dw0_Huu7;
    case 8: return mpc_dw0_Huu8;
    case 9: return mpc_dw0_Huu9;
    case 10: return mpc_dw0_Huu10;
    case 11: return mpc_dw0_Huu11;
    default: return 0;
  }
}

float *mpc_dw0_get_Hss(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_Hss0;
    case 1: return mpc_dw0_Hss1;
    case 2: return mpc_dw0_Hss2;
    case 3: return mpc_dw0_Hss3;
    case 4: return mpc_dw0_Hss4;
    case 5: return mpc_dw0_Hss5;
    case 6: return mpc_dw0_Hss6;
    case 7: return mpc_dw0_Hss7;
    case 8: return mpc_dw0_Hss8;
    case 9: return mpc_dw0_Hss9;
    case 10: return mpc_dw0_Hss10;
    case 11: return mpc_dw0_Hss11;
    default: return 0;
  }
}

float *mpc_dw0_get_f0x(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_f0x0;
    case 1: return mpc_dw0_f0x1;
    case 2: return mpc_dw0_f0x2;
    case 3: return mpc_dw0_f0x3;
    case 4: return mpc_dw0_f0x4;
    case 5: return mpc_dw0_f0x5;
    case 6: return mpc_dw0_f0x6;
    case 7: return mpc_dw0_f0x7;
    case 8: return mpc_dw0_f0x8;
    case 9: return mpc_dw0_f0x9;
    case 10: return mpc_dw0_f0x10;
    case 11: return mpc_dw0_f0x11;
    default: return 0;
  }
}

float *mpc_dw0_get_f0u(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_f0u0;
    case 1: return mpc_dw0_f0u1;
    case 2: return mpc_dw0_f0u2;
    case 3: return mpc_dw0_f0u3;
    case 4: return mpc_dw0_f0u4;
    case 5: return mpc_dw0_f0u5;
    case 6: return mpc_dw0_f0u6;
    case 7: return mpc_dw0_f0u7;
    case 8: return mpc_dw0_f0u8;
    case 9: return mpc_dw0_f0u9;
    case 10: return mpc_dw0_f0u10;
    case 11: return mpc_dw0_f0u11;
    default: return 0;
  }
}

float *mpc_dw0_get_f0s(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_f0s0;
    case 1: return mpc_dw0_f0s1;
    case 2: return mpc_dw0_f0s2;
    case 3: return mpc_dw0_f0s3;
    case 4: return mpc_dw0_f0s4;
    case 5: return mpc_dw0_f0s5;
    case 6: return mpc_dw0_f0s6;
    case 7: return mpc_dw0_f0s7;
    case 8: return mpc_dw0_f0s8;
    case 9: return mpc_dw0_f0s9;
    case 10: return mpc_dw0_f0s10;
    case 11: return mpc_dw0_f0s11;
    default: return 0;
  }
}

float *mpc_dw0_get_fx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_fx0;
    case 1: return mpc_dw0_fx1;
    case 2: return mpc_dw0_fx2;
    case 3: return mpc_dw0_fx3;
    case 4: return mpc_dw0_fx4;
    case 5: return mpc_dw0_fx5;
    case 6: return mpc_dw0_fx6;
    case 7: return mpc_dw0_fx7;
    case 8: return mpc_dw0_fx8;
    case 9: return mpc_dw0_fx9;
    case 10: return mpc_dw0_fx10;
    case 11: return mpc_dw0_fx11;
    default: return 0;
  }
}

float *mpc_dw0_get_fu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_fu0;
    case 1: return mpc_dw0_fu1;
    case 2: return mpc_dw0_fu2;
    case 3: return mpc_dw0_fu3;
    case 4: return mpc_dw0_fu4;
    case 5: return mpc_dw0_fu5;
    case 6: return mpc_dw0_fu6;
    case 7: return mpc_dw0_fu7;
    case 8: return mpc_dw0_fu8;
    case 9: return mpc_dw0_fu9;
    case 10: return mpc_dw0_fu10;
    case 11: return mpc_dw0_fu11;
    default: return 0;
  }
}

float *mpc_dw0_get_f(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_f0;
    case 1: return mpc_dw0_f1;
    case 2: return mpc_dw0_f2;
    case 3: return mpc_dw0_f3;
    case 4: return mpc_dw0_f4;
    case 5: return mpc_dw0_f5;
    case 6: return mpc_dw0_f6;
    case 7: return mpc_dw0_f7;
    case 8: return mpc_dw0_f8;
    case 9: return mpc_dw0_f9;
    case 10: return mpc_dw0_f10;
    case 11: return mpc_dw0_f11;
    default: return 0;
  }
}

float *mpc_dw0_get_gx(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_gx0;
    case 1: return mpc_dw0_gx1;
    case 2: return mpc_dw0_gx2;
    case 3: return mpc_dw0_gx3;
    case 4: return mpc_dw0_gx4;
    case 5: return mpc_dw0_gx5;
    case 6: return mpc_dw0_gx6;
    case 7: return mpc_dw0_gx7;
    case 8: return mpc_dw0_gx8;
    case 9: return mpc_dw0_gx9;
    case 10: return mpc_dw0_gx10;
    case 11: return mpc_dw0_gx11;
    default: return 0;
  }
}

float *mpc_dw0_get_gu(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_gu0;
    case 1: return mpc_dw0_gu1;
    case 2: return mpc_dw0_gu2;
    case 3: return mpc_dw0_gu3;
    case 4: return mpc_dw0_gu4;
    case 5: return mpc_dw0_gu5;
    case 6: return mpc_dw0_gu6;
    case 7: return mpc_dw0_gu7;
    case 8: return mpc_dw0_gu8;
    case 9: return mpc_dw0_gu9;
    case 10: return mpc_dw0_gu10;
    case 11: return mpc_dw0_gu11;
    default: return 0;
  }
}

float *mpc_dw0_get_g(int k)
{
  switch(k)
  {
    case 0: return mpc_dw0_g0;
    case 1: return mpc_dw0_g1;
    case 2: return mpc_dw0_g2;
    case 3: return mpc_dw0_g3;
    case 4: return mpc_dw0_g4;
    case 5: return mpc_dw0_g5;
    case 6: return mpc_dw0_g6;
    case 7: return mpc_dw0_g7;
    case 8: return mpc_dw0_g8;
    case 9: return mpc_dw0_g9;
    case 10: return mpc_dw0_g10;
    case 11: return mpc_dw0_g11;
    default: return 0;
  }
}

float *mpc_dw0_get_stat_time()
{
return mpc_dw0_stat_time;
}

int *mpc_dw0_get_stat_iter_ref()
{
return &mpc_dw0_stat_iter_ref;
}

int *mpc_dw0_get_stat_num_factor()
{
return &mpc_dw0_stat_num_factor;
}

int *mpc_dw0_get_stat_num_solve()
{
return &mpc_dw0_stat_num_solve;
}

int *mpc_dw0_get_stat_num_iter_ref()
{
return &mpc_dw0_stat_num_iter_ref;
}

int *mpc_dw0_get_iter()
{
return &mpc_dw0_iter;
}

int *mpc_dw0_get_termcode()
{
return &mpc_dw0_termcode;
}

int *mpc_dw0_get_error_line()
{
return &mpc_dw0_error_line;
}

int *mpc_dw0_get_error_source()
{
return &mpc_dw0_error_source;
}

float *mpc_dw0_get_norm_d()
{
return mpc_dw0_norm_d;
}
double *mpc_dw0_get_time_max()
{
return &mpc_dw0_time_max;
}

void mpc_dw0_set_time_max(double tmax)
{
mpc_dw0_time_max = tmax;
}


/* ###################################### */
/* Diese Funktion initialisiert den Timer */
/* ###################################### */
void mpc_dw0_glqdocpip_timer_start()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER mpc_dw0_tmp_counter, mpc_dw0_tmp_frequency;
  QueryPerformanceFrequency(&mpc_dw0_tmp_frequency);
  QueryPerformanceCounter(&mpc_dw0_tmp_counter);
  mpc_dw0_timer_start = (double) mpc_dw0_tmp_counter.QuadPart/(double) mpc_dw0_tmp_frequency.QuadPart;
#elif defined(_DS1103)
  mpc_dw0_timer_start = (double) ds1103_timebase_fltread();
#endif
}


/* ################################################### */
/* Diese Funktion gibt die Zeit seit Timerstart zurück */
/* ################################################### */
double mpc_dw0_glqdocpip_timer_get()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER mpc_dw0_tmp_counter, mpc_dw0_tmp_frequency;
  QueryPerformanceFrequency(&mpc_dw0_tmp_frequency);
  QueryPerformanceCounter(&mpc_dw0_tmp_counter);
  return (double) mpc_dw0_tmp_counter.QuadPart/(double) mpc_dw0_tmp_frequency.QuadPart - mpc_dw0_timer_start;
#elif defined(_DS1103)
  return (double) ds1103_timebase_fltread()- mpc_dw0_timer_start;
#endif
}

static void mpc_dw0_v_copy_6(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc_dw0_mv_sid21_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid24_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_vsub_6(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  out[4] = a[4] - b[4];
  out[5] = a[5] - b[5];
  return;
}

static void mpc_dw0_mtv_sid42_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mtv_sid51_sid15_2_6(float *A, float *b, float *out)
{

  out[5] += A[10] * b[0];
  out[5] += A[11] * b[1];
  return;
}

static void mpc_dw0_v_copy_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc_dw0_mtv_sid24_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_mv_sid27_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw0_mtv_sid45_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw0_mtv_sid54_sid15_2_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  return;
}

static void mpc_dw0_v_copy_2(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  return;
}

static void mpc_dw0_mv_sid30_sid18_2_2(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[1];
  return;
}

static void mpc_dw0_vsub_2(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  return;
}

static void mpc_dw0_mv_sid51_sid2_2_6(float *A, float *b, float *out)
{

  out[0] += A[10] * b[5];
  out[1] += A[11] * b[5];
  return;
}

static void mpc_dw0_mv_sid54_sid5_2_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  return;
}

static void mpc_dw0_vadd_2(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  return;
}

static void mpc_dw0_v_init0_2(float *a)
{

    a[0] =0;
    a[1] =0;
  return;
}

static void mpc_dw0_vv_elemult_4(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  out[2] = a[2] * b[2];
  out[3] = a[3] * b[3];
  return;
}

static void mpc_dw0_mv_sid22_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid25_sid5_6_1(float *A, float *b, float *out)
{

  out[4] += A[4] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw0_mtv_sid43_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mtv_sid52_sid16_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[8] * b[0];
  out[0] += A[1] * b[1];
  out[2] += A[9] * b[1];
  out[5] += A[22] * b[2];
  out[5] += A[23] * b[3];
  return;
}

static void mpc_dw0_mtv_sid25_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[4] * b[4];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw0_mv_sid28_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw0_mtv_sid46_sid2_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  out[0] += A[5] * b[5];
  return;
}

static void mpc_dw0_mtv_sid55_sid16_4_1(float *A, float *b, float *out)
{

  out[0] += A[2] * b[2];
  out[0] += A[3] * b[3];
  return;
}

static void mpc_dw0_v_copy_4(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc_dw0_mv_sid31_sid19_4_4(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[5] * b[1];
  out[2] += A[10] * b[2];
  out[3] += A[15] * b[3];
  return;
}

static void mpc_dw0_vsub_4(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  out[3] = a[3] - b[3];
  return;
}

static void mpc_dw0_mv_sid43_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid46_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw0_mv_sid52_sid2_4_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[0] += A[8] * b[2];
  out[1] += A[9] * b[2];
  out[2] += A[22] * b[5];
  out[3] += A[23] * b[5];
  return;
}

static void mpc_dw0_mv_sid55_sid5_4_1(float *A, float *b, float *out)
{

  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  return;
}

static void mpc_dw0_vadd_4(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  return;
}

static void mpc_dw0_v_init0_4(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
  return;
}

static void mpc_dw0_vv_elemult_8(float *a, float *b, float *out)
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

static void mpc_dw0_mv_sid23_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid26_sid5_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_mtv_sid53_sid17_2_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[2] += A[4] * b[0];
  out[0] += A[1] * b[1];
  out[2] += A[5] * b[1];
  return;
}

static void mpc_dw0_mtv_sid26_sid2_6_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_mv_sid29_sid5_1_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  return;
}

static void mpc_dw0_mtv_sid56_sid17_2_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_mv_sid32_sid20_2_2(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[1];
  return;
}

static void mpc_dw0_mv_sid44_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid47_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw0_mv_sid53_sid2_2_6(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[0] += A[4] * b[2];
  out[1] += A[5] * b[2];
  return;
}

static void mpc_dw0_mv_sid56_sid5_2_1(float *A, float *b, float *out)
{

  return;
}

static void mpc_dw0_vv_elediv_2(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  return;
}

static void mpc_dw0_mv_2_2(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[0] += A[2] * b[1];
      out[1] += A[3] * b[1];
  return;
}

static void mpc_dw0_v_init1_2(float *a)
{

    a[0] =1;
    a[1] =1;
  return;
}

static void mpc_dw0_vv_elemult_2(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  out[1] = a[1] * b[1];
  return;
}

static void mpc_dw0_vv_elediv_4(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  return;
}

static void mpc_dw0_mv_4_4(float *A, float *b, float *out)
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

static void mpc_dw0_v_init1_4(float *a)
{

    a[0] =1;
    a[1] =1;
    a[2] =1;
    a[3] =1;
  return;
}

static void mpc_dw0_vv_elemult_1(float *a, float *b, float *out)
{

  out[0] = a[0] * b[0];
  return;
}

static void mpc_dw0_sv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  return;
}

static void mpc_dw0_vadd_8(float *a, float *b, float *out)
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

static void mpc_dw0_v_init1_8(float *a)
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

static void mpc_dw0_v_init0_8(float *a)
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

static void mpc_dw0_sv_8(float *a, float *b, float *out)
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

static void mpc_dw0_vsub_8(float *a, float *b, float *out)
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

static void mpc_dw0_m_copy_6_6(float *a, float *out)
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

static void mpc_dw0_m_copy_6_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void mpc_dw0_m_init0_6_2(float *a)
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
  return;
}

static void mpc_dw0_mtd_sid53_sid17_2_6(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[2] += A[4] * B[0];
      out[6] += A[1] * B[1];
      out[8] += A[5] * B[1];
  return;
}

static void mpc_dw0_mm_y_sid14_sid53_6_2_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[14] += A[2] * B[4];
out[14] += A[8] * B[5];
out[15] += A[3] * B[4];
out[15] += A[9] * B[5];
out[16] += A[4] * B[4];
out[16] += A[10] * B[5];
out[17] += A[5] * B[4];
out[17] += A[11] * B[5];
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

static void mpc_dw0_mm_sid14_sid56_6_2_1(float *A, float *B, float *out)
{

  return;
}

static void mpc_dw0_m_copy_1_1(float *a, float *out)
{

  out[0] = a[0];
  return;
}

static void mpc_dw0_m_init0_1_2(float *a)
{

  a[0] =0;
  a[1] =0;
  return;
}

static void mpc_dw0_mtd_sid56_sid17_2_1(float *A, float *B, float *out)
{

  return;
}

static void mpc_dw0_mm_1_2_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
  return;
}

static void mpc_dw0_mtr_6_1(float *A, float *out)
{

  out[0] = A[0];
  out[1] = A[1];
  out[2] = A[2];
  out[3] = A[3];
  out[4] = A[4];
  out[5] = A[5];
  return;
}

static void mpc_dw0_chol_factor_1(float *a, float *out)
{
  if(a[0] == 0){
    mpc_dw0_termcode = 8;
    mpc_dw0_error_line = __LINE__;
    return;
  }
  out[0] = 1/a[0];
  return;
}

static void mpc_dw0_chol_solve_1_6(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<6; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc_dw0_m_init0_6_6(float *a)
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

static void mpc_dw0_mm_y_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw0_msub_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_mtm_sid43_sid1_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_y_sid1_sid43_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_sid1_sid46_6_6_1(float *A, float *B, float *out)
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

static void mpc_dw0_m_init0_6_4(float *a)
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

static void mpc_dw0_mtd_sid52_sid16_4_6(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[2] += A[8] * B[0];
      out[6] += A[1] * B[1];
      out[8] += A[9] * B[1];
      out[17] += A[22] * B[2];
      out[23] += A[23] * B[3];
  return;
}

static void mpc_dw0_mm_y_sid13_sid52_6_4_6(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
out[14] += A[2] * B[8];
out[14] += A[8] * B[9];
out[15] += A[3] * B[8];
out[15] += A[9] * B[9];
out[16] += A[4] * B[8];
out[16] += A[10] * B[9];
out[17] += A[5] * B[8];
out[17] += A[11] * B[9];
out[35] += A[17] * B[22];
out[35] += A[23] * B[23];
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

static void mpc_dw0_mm_sid13_sid55_6_4_1(float *A, float *B, float *out)
{

out[0] += A[12] * B[2];
out[0] += A[18] * B[3];
out[1] += A[13] * B[2];
out[1] += A[19] * B[3];
out[2] += A[14] * B[2];
out[2] += A[20] * B[3];
out[3] += A[15] * B[2];
out[3] += A[21] * B[3];
out[4] += A[16] * B[2];
out[4] += A[22] * B[3];
out[5] += A[17] * B[2];
out[5] += A[23] * B[3];
  return;
}

static void mpc_dw0_m_init0_1_6(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  return;
}

static void mpc_dw0_mtm_sid46_sid1_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_sid8_sid46_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc_dw0_m_init0_1_4(float *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  return;
}

static void mpc_dw0_mtd_sid55_sid16_4_1(float *A, float *B, float *out)
{

      out[2] += A[2] * B[2];
      out[3] += A[3] * B[3];
  return;
}

static void mpc_dw0_mm_1_4_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
  return;
}

static void mpc_dw0_mtm_sid42_sid1_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_y_sid1_sid42_6_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_sid1_sid45_6_6_1(float *A, float *B, float *out)
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

static void mpc_dw0_mtd_sid51_sid15_2_6(float *A, float *B, float *out)
{

      out[5] += A[10] * B[0];
      out[11] += A[11] * B[1];
  return;
}

static void mpc_dw0_mm_y_sid12_sid51_6_2_6(float *A, float *B, float *out)
{

out[35] += A[5] * B[10];
out[35] += A[11] * B[11];
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

static void mpc_dw0_mm_sid12_sid54_6_2_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[6] * B[1];
out[1] += A[1] * B[0];
out[1] += A[7] * B[1];
out[2] += A[2] * B[0];
out[2] += A[8] * B[1];
out[3] += A[3] * B[0];
out[3] += A[9] * B[1];
out[4] += A[4] * B[0];
out[4] += A[10] * B[1];
out[5] += A[5] * B[0];
out[5] += A[11] * B[1];
  return;
}

static void mpc_dw0_mtm_sid45_sid1_6_1_6(float *A, float *B, float *out)
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

static void mpc_dw0_mm_sid8_sid45_1_6_1(float *A, float *B, float *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[0] += A[3] * B[3];
out[0] += A[5] * B[5];
  return;
}

static void mpc_dw0_mtd_sid54_sid15_2_1(float *A, float *B, float *out)
{

      out[0] += A[0] * B[0];
      out[1] += A[1] * B[1];
  return;
}

static void mpc_dw0_chol_solve_1_1(float *l, float *b, float *out)
{
  int i;
  for(i=0; i<1; i++)
  {
    out[i] = b[i] * l[0];
  }
  return;
}

static void mpc_dw0_v_init0_6(float *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
    a[3] =0;
    a[4] =0;
    a[5] =0;
  return;
}

static void mpc_dw0_mv_6_1(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[3] += A[3] * b[0];
      out[4] += A[4] * b[0];
      out[5] += A[5] * b[0];
  return;
}

static void mpc_dw0_mv_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_1_6(float *A, float *b, float *out)
{

      out[0] += A[0] * b[0];
      out[0] += A[1] * b[1];
      out[0] += A[2] * b[2];
      out[0] += A[3] * b[3];
      out[0] += A[4] * b[4];
      out[0] += A[5] * b[5];
  return;
}

static void mpc_dw0_v_turnsign_1(float *a, float *out)
{

    out[0] = -a[0];
  return;
}

static void mpc_dw0_mv_sid42_sid2_6_6(float *A, float *b, float *out)
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

static void mpc_dw0_mv_sid45_sid5_6_1(float *A, float *b, float *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  out[3] += A[3] * b[0];
  out[5] += A[5] * b[0];
  return;
}

static void mpc_dw0_m_copy_2_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  return;
}

static void mpc_dw0_v_turnsign_4(float *a, float *out)
{

    out[0] = -a[0];
    out[1] = -a[1];
    out[2] = -a[2];
    out[3] = -a[3];
  return;
}

static void mpc_dw0_m_copy_4_1(float *a, float *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void mpc_dw0_vv_elediv_8(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  return;
}

static void mpc_dw0_v_turnsign_8(float *a, float *out)
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

static void mpc_dw0_v_copy_8(float *a, float *out)
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

static void mpc_dw0_vadd_6(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  out[3] = a[3] + b[3];
  out[4] = a[4] + b[4];
  out[5] = a[5] + b[5];
  return;
}

static void mpc_dw0_vadd_1(float *a, float *b, float *out)
{

  out[0] = a[0] + b[0];
  return;
}

static void mpc_dw0_v_init0_1(float *a)
{

    a[0] =0;
  return;
}

static void mpc_dw0_vtv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  out[0] += a[4] * b[4];
  out[0] += a[5] * b[5];
  return;
}

static void mpc_dw0_vtv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc_dw0_vtv_2(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  return;
}

static void mpc_dw0_vsub_1(float *a, float *b, float *out)
{

  out[0] = a[0] - b[0];
  return;
}

static void mpc_dw0_vtv_4(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  out[0] += a[3] * b[3];
  return;
}

static void mpc_dw0_vtv_8(float *a, float *b, float *out)
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

static void mpc_dw0_vv_elediv_1(float *a, float *b, float *out)
{

  if(b[0] == 0){ mpc_dw0_termcode = 8; mpc_dw0_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  return;
}

static void mpc_dw0_min(float *a, float *b, float *out)
{

  if  (a[0] < b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc_dw0_v_init1_1(float *a)
{

    a[0] =1;
  return;
}

static void mpc_dw0_max(float *a, float *b, float *out)
{

  if  (a[0] > b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void mpc_dw0_sv_6(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  out[3] += a[0] * b[3];
  out[4] += a[0] * b[4];
  out[5] += a[0] * b[5];
  return;
}

static void mpc_dw0_sv_1(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  return;
}

static void mpc_dw0_sv_2(float *a, float *b, float *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  return;
}

static void mpc_dw0_norm_inf_6_6(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_6_1(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_1_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  return;
}

static void mpc_dw0_norm_inf_2_2(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_2_1(float *A, float *B, float *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  return;
}

static void mpc_dw0_norm_inf_2_6(float *A, float *B, float *out)
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
  return;
}

static void mpc_dw0_norm_inf_4_4(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_4_1(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_4_6(float *A, float *B, float *out)
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

static void mpc_dw0_norm_inf_8_1(float *A, float *B, float *out)
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

static void mpc_dw0_v_min_4(float *A, float *B, float *out)
{
  int i;
  out[0] = B[0];

  for(i=0;i<4;i++)
  {
    if (A[i] < out[0])
    {
      out[0] = A[i];
    }
  }
  return;
}

static void mpc_dw0_v_min_8(float *A, float *B, float *out)
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

static void mpc_dw0_vsum_4(float *a, float *out)
{

  out[0] = out[0] + a[0];
  out[0] = out[0] + a[1];
  out[0] = out[0] + a[2];
  out[0] = out[0] + a[3];
  return;
}

static void mpc_dw0_vsum_8(float *a, float *out)
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

static void mpc_dw0_mm_sid1_sid42_6_6_6(float *A, float *B, float *out)
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
static void mpc_dw0_glqdocpip_calc_mu()
{
mpc_dw0_v_init0_1(mpc_dw0_mu);
/* mu = mu + y*nu */
/* Zeitschritt 0 */
mpc_dw0_vtv_4(mpc_dw0_y0, mpc_dw0_nu0, mpc_dw0_mu);
/* Zeitschritt 1 */
mpc_dw0_vtv_8(mpc_dw0_y1, mpc_dw0_nu1, mpc_dw0_mu);
/* Zeitschritt 2 */
mpc_dw0_vtv_8(mpc_dw0_y2, mpc_dw0_nu2, mpc_dw0_mu);
/* Zeitschritt 3 */
mpc_dw0_vtv_8(mpc_dw0_y3, mpc_dw0_nu3, mpc_dw0_mu);
/* Zeitschritt 4 */
mpc_dw0_vtv_8(mpc_dw0_y4, mpc_dw0_nu4, mpc_dw0_mu);
/* Zeitschritt 5 */
mpc_dw0_vtv_8(mpc_dw0_y5, mpc_dw0_nu5, mpc_dw0_mu);
/* Zeitschritt 6 */
mpc_dw0_vtv_8(mpc_dw0_y6, mpc_dw0_nu6, mpc_dw0_mu);
/* Zeitschritt 7 */
mpc_dw0_vtv_8(mpc_dw0_y7, mpc_dw0_nu7, mpc_dw0_mu);
/* Zeitschritt 8 */
mpc_dw0_vtv_8(mpc_dw0_y8, mpc_dw0_nu8, mpc_dw0_mu);
/* Zeitschritt 9 */
mpc_dw0_vtv_8(mpc_dw0_y9, mpc_dw0_nu9, mpc_dw0_mu);
/* Zeitschritt 10 */
mpc_dw0_vtv_8(mpc_dw0_y10, mpc_dw0_nu10, mpc_dw0_mu);
/* Zeitschritt 11 */
mpc_dw0_vtv_4(mpc_dw0_y11, mpc_dw0_nu11, mpc_dw0_mu);
mpc_dw0_vv_elediv_1(mpc_dw0_mu, mpc_dw0_m_ineq, mpc_dw0_mu);
if(mpc_dw0_termcode > -1){return;}

/* mu0 bestimmen */
if(mpc_dw0_iter == 0){
mpc_dw0_v_copy_1(mpc_dw0_mu, mpc_dw0_mu0);
}
}


/* ############################### */
/* Diese Funktion berechnet mu_aff */
/* ############################### */
static void mpc_dw0_glqdocpip_calc_mu_aff()
{
mpc_dw0_v_init0_1(mpc_dw0_mu_aff);
/* Zeitschritt 0 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_4(mpc_dw0_y0, mpc_dw0_tmp1_4);
mpc_dw0_sv_4(mpc_dw0_alpha_max, mpc_dw0_dy0, mpc_dw0_tmp1_4);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_4(mpc_dw0_nu0, mpc_dw0_tmp2_4);
mpc_dw0_sv_4(mpc_dw0_alpha_max, mpc_dw0_dnu0, mpc_dw0_tmp2_4);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_4(mpc_dw0_tmp1_4, mpc_dw0_tmp2_4, mpc_dw0_mu_aff);
/* Zeitschritt 1 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y1, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy1, mpc_dw0_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu1, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu1, mpc_dw0_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp1_8, mpc_dw0_tmp2_8, mpc_dw0_mu_aff);
/* Zeitschritt 2 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y2, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy2, mpc_dw0_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu2, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu2, mpc_dw0_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp1_8, mpc_dw0_mu_aff);
/* Zeitschritt 3 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y3, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy3, mpc_dw0_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu3, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu3, mpc_dw0_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp1_8, mpc_dw0_tmp2_8, mpc_dw0_mu_aff);
/* Zeitschritt 4 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y4, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy4, mpc_dw0_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu4, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu4, mpc_dw0_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp1_8, mpc_dw0_mu_aff);
/* Zeitschritt 5 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y5, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy5, mpc_dw0_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu5, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu5, mpc_dw0_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp1_8, mpc_dw0_tmp2_8, mpc_dw0_mu_aff);
/* Zeitschritt 6 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y6, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy6, mpc_dw0_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu6, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu6, mpc_dw0_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp1_8, mpc_dw0_mu_aff);
/* Zeitschritt 7 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y7, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy7, mpc_dw0_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu7, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu7, mpc_dw0_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp1_8, mpc_dw0_tmp2_8, mpc_dw0_mu_aff);
/* Zeitschritt 8 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y8, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy8, mpc_dw0_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu8, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu8, mpc_dw0_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp1_8, mpc_dw0_mu_aff);
/* Zeitschritt 9 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y9, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy9, mpc_dw0_tmp1_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu9, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu9, mpc_dw0_tmp2_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp1_8, mpc_dw0_tmp2_8, mpc_dw0_mu_aff);
/* Zeitschritt 10 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_8(mpc_dw0_y10, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dy10, mpc_dw0_tmp2_8);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_8(mpc_dw0_nu10, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_alpha_max, mpc_dw0_dnu10, mpc_dw0_tmp1_8);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp1_8, mpc_dw0_mu_aff);
/* Zeitschritt 11 */
/* yady = y + alpha_max*dy */
mpc_dw0_v_copy_4(mpc_dw0_y11, mpc_dw0_tmp2_4);
mpc_dw0_sv_4(mpc_dw0_alpha_max, mpc_dw0_dy11, mpc_dw0_tmp2_4);
/* nuadnu = nu + alpha_max*dnu */
mpc_dw0_v_copy_4(mpc_dw0_nu11, mpc_dw0_tmp1_4);
mpc_dw0_sv_4(mpc_dw0_alpha_max, mpc_dw0_dnu11, mpc_dw0_tmp1_4);
/* mu_aff = mu_aff + yady.*nuadnu) */
mpc_dw0_vtv_4(mpc_dw0_tmp2_4, mpc_dw0_tmp1_4, mpc_dw0_mu_aff);
mpc_dw0_vv_elediv_1(mpc_dw0_mu_aff, mpc_dw0_m_ineq, mpc_dw0_mu_aff);
if(mpc_dw0_termcode > -1){return;}
}


/* ############################ */
/* Diese Funktion berechnet phi */
/* ############################ */
static void mpc_dw0_glqdocpip_calc_phi()
{
mpc_dw0_vadd_1(mpc_dw0_norm_r, mpc_dw0_dgap, mpc_dw0_phi);
mpc_dw0_vv_elediv_1(mpc_dw0_phi, mpc_dw0_norm_d, mpc_dw0_phi);
if(mpc_dw0_termcode > -1){return;}
if (mpc_dw0_iter > 0) {

mpc_dw0_min(mpc_dw0_minphi, mpc_dw0_phi, mpc_dw0_minphi);
}else{
mpc_dw0_v_copy_1(mpc_dw0_phi, mpc_dw0_minphi);
}
}


/* ######################################################## */
/* Diese Funktion berechnet den Zentrierungsparameter sigma */
/* ######################################################## */
static void mpc_dw0_glqdocpip_calc_sigma()
{
mpc_dw0_vv_elediv_1(mpc_dw0_mu_aff, mpc_dw0_mu, mpc_dw0_tmp1_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_sigma[0] = pow(*mpc_dw0_tmp1_1, *mpc_dw0_tau);
}


/* ########################################################### */
/* Diese Funktion berechnet die maximal mögliche Schrittweite, */
/* bei der y und nu noch positiv bleiben */
/* ########################################################### */
static void mpc_dw0_glqdocpip_max_stepsize()
{
int i;

mpc_dw0_alpha_max[0] = -FLT_MAX;
mpc_dw0_alpha_tmp[0] = 0;

/* Zeitschritt 0 */
for(i=0;i<4;i++)
{
/* dy-check */
if( mpc_dw0_dy0[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y0[i], &mpc_dw0_dy0[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y0[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy0[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu0[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu0[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu0[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu0[i], &mpc_dw0_dnu0[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y0[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy0[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu0[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu0[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 1 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy1[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y1[i], &mpc_dw0_dy1[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y1[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy1[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu1[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu1[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu1[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu1[i], &mpc_dw0_dnu1[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y1[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy1[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu1[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu1[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 2 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy2[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y2[i], &mpc_dw0_dy2[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y2[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy2[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu2[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu2[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu2[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu2[i], &mpc_dw0_dnu2[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y2[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy2[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu2[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu2[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 3 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy3[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y3[i], &mpc_dw0_dy3[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y3[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy3[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu3[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu3[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu3[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu3[i], &mpc_dw0_dnu3[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y3[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy3[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu3[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu3[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 4 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy4[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y4[i], &mpc_dw0_dy4[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y4[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy4[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu4[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu4[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu4[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu4[i], &mpc_dw0_dnu4[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y4[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy4[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu4[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu4[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 5 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy5[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y5[i], &mpc_dw0_dy5[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y5[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy5[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu5[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu5[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu5[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu5[i], &mpc_dw0_dnu5[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y5[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy5[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu5[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu5[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 6 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy6[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y6[i], &mpc_dw0_dy6[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y6[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy6[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu6[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu6[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu6[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu6[i], &mpc_dw0_dnu6[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y6[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy6[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu6[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu6[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 7 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy7[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y7[i], &mpc_dw0_dy7[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y7[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy7[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu7[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu7[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu7[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu7[i], &mpc_dw0_dnu7[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y7[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy7[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu7[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu7[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 8 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy8[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y8[i], &mpc_dw0_dy8[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y8[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy8[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu8[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu8[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu8[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu8[i], &mpc_dw0_dnu8[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y8[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy8[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu8[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu8[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 9 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy9[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y9[i], &mpc_dw0_dy9[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y9[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy9[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu9[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu9[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu9[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu9[i], &mpc_dw0_dnu9[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y9[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy9[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu9[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu9[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 10 */
for(i=0;i<8;i++)
{
/* dy-check */
if( mpc_dw0_dy10[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y10[i], &mpc_dw0_dy10[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y10[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy10[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu10[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu10[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu10[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu10[i], &mpc_dw0_dnu10[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y10[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy10[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu10[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu10[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 11 */
for(i=0;i<4;i++)
{
/* dy-check */
if( mpc_dw0_dy11[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_y11[i], &mpc_dw0_dy11[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y11[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy11[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu11[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu11[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( mpc_dw0_dnu11[i] < 0)
{
mpc_dw0_vv_elediv_1(&mpc_dw0_nu11[i], &mpc_dw0_dnu11[i], mpc_dw0_alpha_tmp);
if(mpc_dw0_termcode > -1){return;}
if( *mpc_dw0_alpha_tmp > *mpc_dw0_alpha_max )
{
mpc_dw0_alpha_max[0] = *mpc_dw0_alpha_tmp;
mpc_dw0_v_copy_1(&mpc_dw0_y11[i], &mpc_dw0_alpha_min_y[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dy11[i], &mpc_dw0_alpha_min_dy[0]);
mpc_dw0_v_copy_1(&mpc_dw0_nu11[i], &mpc_dw0_alpha_min_nu[0]);
mpc_dw0_v_copy_1(&mpc_dw0_dnu11[i], &mpc_dw0_alpha_min_dnu[0]);
mpc_dw0_alpha_min_source_y = 0;
}
}
}

mpc_dw0_v_turnsign_1(&mpc_dw0_alpha_max[0], &mpc_dw0_alpha_max[0]);
}


/* ####################################################### */
/* Diese Funktion berechnet die Schrittweite nach Mehrotra */
/* ####################################################### */
static void mpc_dw0_glqdocpip_mehrotra_step()
{

/* FPD */
if (mpc_dw0_alpha_min_source_y == 1) {
/* alpha_max durch y verursacht */
mpc_dw0_vv_elemult_1(mpc_dw0_alpha_max, mpc_dw0_alpha_min_dnu, mpc_dw0_mehrotra_fpd);
mpc_dw0_vadd_1(mpc_dw0_mehrotra_fpd, mpc_dw0_alpha_min_nu, mpc_dw0_mehrotra_fpd);
mpc_dw0_vv_elediv_1(mpc_dw0_mu_aff, mpc_dw0_mehrotra_fpd, mpc_dw0_mehrotra_fpd);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_1(mpc_dw0_mehrotra_fpd, mpc_dw0_mehrotra_gamma, mpc_dw0_mehrotra_fpd);
mpc_dw0_vsub_1(mpc_dw0_mehrotra_fpd, mpc_dw0_alpha_min_y, mpc_dw0_mehrotra_fpd);
mpc_dw0_vv_elemult_1(mpc_dw0_alpha_max, mpc_dw0_alpha_min_dy, mpc_dw0_tmp1_1);
mpc_dw0_vv_elediv_1(mpc_dw0_mehrotra_fpd, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_fpd);
if(mpc_dw0_termcode > -1){return;}
} else {
/* alpha_max durch nu verursacht */
mpc_dw0_vv_elemult_1(mpc_dw0_alpha_max, mpc_dw0_alpha_min_dy, mpc_dw0_mehrotra_fpd);
mpc_dw0_vadd_1(mpc_dw0_mehrotra_fpd, mpc_dw0_alpha_min_y, mpc_dw0_mehrotra_fpd);
mpc_dw0_vv_elediv_1(mpc_dw0_mu_aff, mpc_dw0_mehrotra_fpd, mpc_dw0_mehrotra_fpd);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_1(mpc_dw0_mehrotra_fpd, mpc_dw0_mehrotra_gamma, mpc_dw0_mehrotra_fpd);
mpc_dw0_vsub_1(mpc_dw0_mehrotra_fpd, mpc_dw0_alpha_min_nu, mpc_dw0_mehrotra_fpd);
mpc_dw0_vv_elemult_1(mpc_dw0_alpha_max, mpc_dw0_alpha_min_dnu, mpc_dw0_tmp1_1);
mpc_dw0_vv_elediv_1(mpc_dw0_mehrotra_fpd, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_fpd);
if(mpc_dw0_termcode > -1){return;}
}
/* Schrittweitenfaktor begrenzen */
/* Nach unten limitieren (1-gamma) */
mpc_dw0_v_init1_1(mpc_dw0_tmp1_1);
mpc_dw0_vsub_1(mpc_dw0_tmp1_1, mpc_dw0_mehrotra_gamma, mpc_dw0_tmp1_1);
mpc_dw0_max(mpc_dw0_mehrotra_fpd, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_fpd);
/* nach oben limitieren (1-macheps) */
mpc_dw0_v_init1_1(mpc_dw0_tmp1_1);
mpc_dw0_vsub_1(mpc_dw0_tmp1_1, mpc_dw0_macheps, mpc_dw0_tmp1_1);
mpc_dw0_min(mpc_dw0_mehrotra_fpd, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_fpd);
/* Schrittweite berechnen */
mpc_dw0_vv_elemult_1(mpc_dw0_mehrotra_fpd, mpc_dw0_alpha_max, mpc_dw0_mehrotra_alpha);
/* Schritt begrenzen 0 =< alpha =< 1 */
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(mpc_dw0_mehrotra_alpha, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_alpha);
mpc_dw0_v_init1_1(mpc_dw0_tmp1_1);
mpc_dw0_min(mpc_dw0_mehrotra_alpha, mpc_dw0_tmp1_1, mpc_dw0_mehrotra_alpha);
}


/* ########################################### */
/* Diese Funktion berechnet die Dualitätslücke */
/* ########################################### */
static void mpc_dw0_glqdocpip_calc_duality_gap()
{
mpc_dw0_v_init0_1(mpc_dw0_dgap);
/* Zeitschritt 0 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid21_sid2_6_6(mpc_dw0_Hxx0, mpc_dw0_x0, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x0, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid24_sid5_6_1(mpc_dw0_Hxu0, mpc_dw0_u0, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x0, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x0, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid27_sid5_1_1(mpc_dw0_Huu0, mpc_dw0_u0, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u0, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss0, mpc_dw0_s0, mpc_dw0_tmp3_2_1);
mpc_dw0_vtv_2(mpc_dw0_s0, mpc_dw0_tmp3_2_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x0, mpc_dw0_x0, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u0, mpc_dw0_u0, mpc_dw0_dgap);
mpc_dw0_vtv_2(mpc_dw0_f0s0, mpc_dw0_s0, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_xinit, mpc_dw0_p0, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_2(mpc_dw0_g0, mpc_dw0_y0, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 1 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx1, mpc_dw0_x1, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x1, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu1, mpc_dw0_u1, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x1, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x1, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu1, mpc_dw0_u1, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u1, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss1, mpc_dw0_s1, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s1, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x1, mpc_dw0_x1, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u1, mpc_dw0_u1, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s1, mpc_dw0_s1, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f0, mpc_dw0_p1, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g1, mpc_dw0_y1, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 2 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx2, mpc_dw0_x2, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x2, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu2, mpc_dw0_u2, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x2, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x2, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu2, mpc_dw0_u2, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u2, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss2, mpc_dw0_s2, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s2, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x2, mpc_dw0_x2, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u2, mpc_dw0_u2, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s2, mpc_dw0_s2, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f1, mpc_dw0_p2, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g2, mpc_dw0_y2, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 3 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx3, mpc_dw0_x3, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x3, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu3, mpc_dw0_u3, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x3, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x3, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu3, mpc_dw0_u3, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u3, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss3, mpc_dw0_s3, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s3, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x3, mpc_dw0_x3, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u3, mpc_dw0_u3, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s3, mpc_dw0_s3, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f2, mpc_dw0_p3, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g3, mpc_dw0_y3, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 4 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx4, mpc_dw0_x4, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x4, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu4, mpc_dw0_u4, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x4, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x4, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu4, mpc_dw0_u4, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u4, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss4, mpc_dw0_s4, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s4, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x4, mpc_dw0_x4, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u4, mpc_dw0_u4, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s4, mpc_dw0_s4, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f3, mpc_dw0_p4, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g4, mpc_dw0_y4, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 5 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx5, mpc_dw0_x5, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x5, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu5, mpc_dw0_u5, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x5, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x5, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu5, mpc_dw0_u5, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u5, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss5, mpc_dw0_s5, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s5, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x5, mpc_dw0_x5, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u5, mpc_dw0_u5, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s5, mpc_dw0_s5, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f4, mpc_dw0_p5, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g5, mpc_dw0_y5, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 6 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx6, mpc_dw0_x6, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x6, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu6, mpc_dw0_u6, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x6, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x6, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu6, mpc_dw0_u6, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u6, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss6, mpc_dw0_s6, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s6, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x6, mpc_dw0_x6, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u6, mpc_dw0_u6, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s6, mpc_dw0_s6, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f5, mpc_dw0_p6, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g6, mpc_dw0_y6, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 7 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx7, mpc_dw0_x7, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x7, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu7, mpc_dw0_u7, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x7, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x7, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu7, mpc_dw0_u7, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u7, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss7, mpc_dw0_s7, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s7, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x7, mpc_dw0_x7, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u7, mpc_dw0_u7, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s7, mpc_dw0_s7, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f6, mpc_dw0_p7, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g7, mpc_dw0_y7, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 8 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx8, mpc_dw0_x8, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x8, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu8, mpc_dw0_u8, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x8, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x8, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu8, mpc_dw0_u8, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u8, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss8, mpc_dw0_s8, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s8, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x8, mpc_dw0_x8, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u8, mpc_dw0_u8, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s8, mpc_dw0_s8, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f7, mpc_dw0_p8, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g8, mpc_dw0_y8, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 9 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx9, mpc_dw0_x9, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x9, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu9, mpc_dw0_u9, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x9, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x9, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu9, mpc_dw0_u9, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u9, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss9, mpc_dw0_s9, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s9, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x9, mpc_dw0_x9, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u9, mpc_dw0_u9, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s9, mpc_dw0_s9, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f8, mpc_dw0_p9, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g9, mpc_dw0_y9, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 10 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx10, mpc_dw0_x10, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x10, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu10, mpc_dw0_u10, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x10, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x10, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu10, mpc_dw0_u10, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u10, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss10, mpc_dw0_s10, mpc_dw0_tmp2_4_1);
mpc_dw0_vtv_4(mpc_dw0_s10, mpc_dw0_tmp2_4_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x10, mpc_dw0_x10, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u10, mpc_dw0_u10, mpc_dw0_dgap);
mpc_dw0_vtv_4(mpc_dw0_f0s10, mpc_dw0_s10, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f9, mpc_dw0_p10, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_4(mpc_dw0_g10, mpc_dw0_y10, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Zeitschritt 11 */
/* Quadratischer Anteil */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid23_sid2_6_6(mpc_dw0_Hxx11, mpc_dw0_x11, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x11, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6_1);
mpc_dw0_mv_sid26_sid5_6_1(mpc_dw0_Hxu11, mpc_dw0_u11, mpc_dw0_tmp1_6_1);
mpc_dw0_vtv_6(mpc_dw0_x11, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_vtv_6(mpc_dw0_x11, mpc_dw0_tmp1_6_1, mpc_dw0_dgap);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1_1);
mpc_dw0_mv_sid29_sid5_1_1(mpc_dw0_Huu11, mpc_dw0_u11, mpc_dw0_tmp1_1_1);
mpc_dw0_vtv_1(mpc_dw0_u11, mpc_dw0_tmp1_1_1, mpc_dw0_dgap);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss11, mpc_dw0_s11, mpc_dw0_tmp3_2_1);
mpc_dw0_vtv_2(mpc_dw0_s11, mpc_dw0_tmp3_2_1, mpc_dw0_dgap);
/* Linearer Anteil */
mpc_dw0_vtv_6(mpc_dw0_f0x11, mpc_dw0_x11, mpc_dw0_dgap);
mpc_dw0_vtv_1(mpc_dw0_f0u11, mpc_dw0_u11, mpc_dw0_dgap);
mpc_dw0_vtv_2(mpc_dw0_f0s11, mpc_dw0_s11, mpc_dw0_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_6(mpc_dw0_f10, mpc_dw0_p11, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
mpc_dw0_v_init0_1(mpc_dw0_tmp2_1_1);
mpc_dw0_vtv_2(mpc_dw0_g11, mpc_dw0_y11, mpc_dw0_tmp2_1_1);
mpc_dw0_vsub_1(mpc_dw0_dgap, mpc_dw0_tmp2_1_1, mpc_dw0_dgap);
/* dgap = abs(dgap) */
if(mpc_dw0_dgap[0] < 0){
mpc_dw0_dgap[0] = -mpc_dw0_dgap[0];}
}


/* ############################################################ */
/* Diese Funktion berechnet die Unendlichnorm der Eingangsdaten */
/* ############################################################ */
static void mpc_dw0_glqdocpip_calc_norm_d()
{
mpc_dw0_v_init1_1(mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_2(mpc_dw0_Hss0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_f0s0, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_2_6(mpc_dw0_gx0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_gu0, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_g0, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s1, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f1, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu1, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g1, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s2, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f2, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu2, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g2, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s3, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f3, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu3, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g3, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s4, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f4, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu4, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g4, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s5, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f5, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu5, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g5, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s6, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f6, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu6, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g6, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s7, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f7, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu7, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g7, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s8, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f8, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu8, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g8, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s9, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f9, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu9, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g9, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_4(mpc_dw0_Hss10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_f0s10, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f10, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_4_6(mpc_dw0_gx10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_gu10, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_4_1(mpc_dw0_g10, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_6(mpc_dw0_Hxx11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_Hxu11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_Huu11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_2(mpc_dw0_Hss11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f0x11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_1_1(mpc_dw0_f0u11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_f0s11, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Gleichungsnebenbedingungen */
mpc_dw0_norm_inf_6_6(mpc_dw0_fx11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_fu11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_6_1(mpc_dw0_f11, mpc_dw0_norm_d, mpc_dw0_norm_d);
/* Aus Ungleichungsnebenbedingungen */
mpc_dw0_norm_inf_2_6(mpc_dw0_gx11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_gu11, mpc_dw0_norm_d, mpc_dw0_norm_d);
mpc_dw0_norm_inf_2_1(mpc_dw0_g11, mpc_dw0_norm_d, mpc_dw0_norm_d);
}


/* ############################################################# */
/* Diese Funktion berechnet die Unendlichnorm der rechten Seiten */
/* ############################################################# */
static void mpc_dw0_glqdocpip_calc_norm_r()
{
/* norm_r_prev bestimmen */
if(mpc_dw0_iter > 0){
mpc_dw0_v_copy_1(mpc_dw0_norm_r, mpc_dw0_norm_r_prev);
}
mpc_dw0_v_init0_1(mpc_dw0_norm_r);
/* Zeitschritt 0 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x0, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u0, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_2_1(mpc_dw0_rf0s0, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_2_1(mpc_dw0_rc0, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_2_1(mpc_dw0_rs0, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rk0, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 1 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x1, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u1, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s1, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf1, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc1, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs1, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk1, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 2 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x2, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u2, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s2, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf2, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc2, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs2, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk2, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 3 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x3, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u3, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s3, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf3, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc3, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs3, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk3, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 4 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x4, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u4, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s4, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf4, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc4, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs4, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk4, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 5 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x5, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u5, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s5, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf5, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc5, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs5, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk5, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 6 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x6, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u6, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s6, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf6, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc6, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs6, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk6, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 7 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x7, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u7, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s7, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf7, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc7, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs7, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk7, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 8 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x8, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u8, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s8, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf8, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc8, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs8, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk8, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 9 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x9, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u9, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s9, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf9, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc9, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs9, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk9, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 10 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x10, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u10, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rf0s10, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf10, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rc10, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_4_1(mpc_dw0_rs10, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_8_1(mpc_dw0_rk10, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Zeitschritt 11 */
/* Aus Gütefunktion */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf0x11, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_1_1(mpc_dw0_rf0u11, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_2_1(mpc_dw0_rf0s11, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Gleichungsnebenbedingung */
mpc_dw0_norm_inf_6_1(mpc_dw0_rf11, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Ungleichungsnebenbedingung */
mpc_dw0_norm_inf_2_1(mpc_dw0_rc11, mpc_dw0_norm_r, mpc_dw0_norm_r);
mpc_dw0_norm_inf_2_1(mpc_dw0_rs11, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* Aus Komplementaritätsbedingung */
mpc_dw0_norm_inf_4_1(mpc_dw0_rk11, mpc_dw0_norm_r, mpc_dw0_norm_r);
/* norm_r0 bestimmen */
if(mpc_dw0_iter == 0){
mpc_dw0_v_copy_1(mpc_dw0_norm_r, mpc_dw0_norm_r0);
}
}


/* ###################################### */
/* Diese Funktion führt einen Schritt aus */
/* ###################################### */
static void mpc_dw0_glqdocpip_step()
{
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx0, mpc_dw0_x0);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du0, mpc_dw0_u0);
mpc_dw0_sv_2(mpc_dw0_mehrotra_alpha, mpc_dw0_ds0, mpc_dw0_s0);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp0, mpc_dw0_p0);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_dy0, mpc_dw0_y0);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu0, mpc_dw0_nu0);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx1, mpc_dw0_x1);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du1, mpc_dw0_u1);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds1, mpc_dw0_s1);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp1, mpc_dw0_p1);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy1, mpc_dw0_y1);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu1, mpc_dw0_nu1);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx2, mpc_dw0_x2);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du2, mpc_dw0_u2);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds2, mpc_dw0_s2);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp2, mpc_dw0_p2);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy2, mpc_dw0_y2);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu2, mpc_dw0_nu2);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx3, mpc_dw0_x3);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du3, mpc_dw0_u3);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds3, mpc_dw0_s3);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp3, mpc_dw0_p3);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy3, mpc_dw0_y3);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu3, mpc_dw0_nu3);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx4, mpc_dw0_x4);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du4, mpc_dw0_u4);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds4, mpc_dw0_s4);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp4, mpc_dw0_p4);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy4, mpc_dw0_y4);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu4, mpc_dw0_nu4);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx5, mpc_dw0_x5);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du5, mpc_dw0_u5);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds5, mpc_dw0_s5);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp5, mpc_dw0_p5);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy5, mpc_dw0_y5);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu5, mpc_dw0_nu5);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx6, mpc_dw0_x6);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du6, mpc_dw0_u6);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds6, mpc_dw0_s6);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp6, mpc_dw0_p6);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy6, mpc_dw0_y6);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu6, mpc_dw0_nu6);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx7, mpc_dw0_x7);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du7, mpc_dw0_u7);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds7, mpc_dw0_s7);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp7, mpc_dw0_p7);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy7, mpc_dw0_y7);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu7, mpc_dw0_nu7);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx8, mpc_dw0_x8);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du8, mpc_dw0_u8);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds8, mpc_dw0_s8);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp8, mpc_dw0_p8);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy8, mpc_dw0_y8);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu8, mpc_dw0_nu8);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx9, mpc_dw0_x9);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du9, mpc_dw0_u9);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds9, mpc_dw0_s9);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp9, mpc_dw0_p9);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy9, mpc_dw0_y9);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu9, mpc_dw0_nu9);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx10, mpc_dw0_x10);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du10, mpc_dw0_u10);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_ds10, mpc_dw0_s10);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp10, mpc_dw0_p10);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dy10, mpc_dw0_y10);
mpc_dw0_sv_8(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu10, mpc_dw0_nu10);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dx11, mpc_dw0_x11);
mpc_dw0_sv_1(mpc_dw0_mehrotra_alpha, mpc_dw0_du11, mpc_dw0_u11);
mpc_dw0_sv_2(mpc_dw0_mehrotra_alpha, mpc_dw0_ds11, mpc_dw0_s11);
mpc_dw0_sv_6(mpc_dw0_mehrotra_alpha, mpc_dw0_dp11, mpc_dw0_p11);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_dy11, mpc_dw0_y11);
mpc_dw0_sv_4(mpc_dw0_mehrotra_alpha, mpc_dw0_dnu11, mpc_dw0_nu11);
}


/* ######################################################### */
/* Diese Funktion führt Konvergenz- und Divergenztests durch */
/* ######################################################### */
static void mpc_dw0_glqdocpip_check_condiv()
{
/* Termcode 0 - Success */
if(mpc_dw0_mu[0] <= mpc_dw0_tol[0]){
mpc_dw0_vv_elemult_1(mpc_dw0_tol, mpc_dw0_norm_d, mpc_dw0_tmp1_1);
  if(mpc_dw0_norm_r[0] <= mpc_dw0_tmp1_1[0]){
  mpc_dw0_termcode = 0;
  return;
  }
}

/* Termcode 1 - infeasible */
if(mpc_dw0_phi[0] > mpc_dw0_tol[0]){
mpc_dw0_vv_elemult_1(mpc_dw0_tc1_factor, mpc_dw0_minphi, mpc_dw0_tmp1_1);
  if(mpc_dw0_phi[0] >= mpc_dw0_tmp1_1[0]){
  mpc_dw0_termcode = 1;
  return;
  }
}

/* Termcode 2 - slow convergence */
mpc_dw0_vv_elemult_1(mpc_dw0_tol, mpc_dw0_norm_d, mpc_dw0_tmp1_1);
if(mpc_dw0_norm_r[0] > mpc_dw0_tmp1_1[0]){
mpc_dw0_vv_elediv_1(mpc_dw0_norm_r, mpc_dw0_mu, mpc_dw0_tmp1_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_1(mpc_dw0_norm_r0, mpc_dw0_mu0, mpc_dw0_tmp2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_1(mpc_dw0_tc2_factor, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
  if(mpc_dw0_tmp1_1[0] >= mpc_dw0_tmp2_1[0]){
  mpc_dw0_termcode = 2;
  return;
  }
}

/* Termcode 7 - calculation time limit exceeded */
if(mpc_dw0_iter > 0){
  if(mpc_dw0_glqdocpip_timer_get()*(double)mpc_dw0_iter/ (double) (mpc_dw0_iter + 1) > mpc_dw0_time_max){
    mpc_dw0_termcode = 7;
    return;
  }
}

/* iterative refinement */
/* ### FLAGS ### */
/* # keep_iterative_refinements_on = 0 */
/* # iterative_refinements_require_norm_r_is_not_too_small = 0 */
/* ############# */
mpc_dw0_iter_ref = 0;
if(mpc_dw0_iter > 0){
mpc_dw0_tmp1_1[0] = 100;
mpc_dw0_vv_elemult_1(mpc_dw0_tmp1_1, mpc_dw0_tol, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_norm_d, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
if(mpc_dw0_norm_r_prev[0] > mpc_dw0_tmp2_1[0]){
mpc_dw0_tmp1_1[0] = 1.001;
mpc_dw0_vv_elemult_1(mpc_dw0_tmp1_1, mpc_dw0_norm_r_prev, mpc_dw0_tmp2_1);
if(mpc_dw0_norm_r[0] > mpc_dw0_tmp2_1[0]){
mpc_dw0_iter_ref = 1;
}
}
}

}


/* ################################################ */
/* Diese Funktion speichert Daten für die Statistik */
/* ################################################ */
static void mpc_dw0_glqdocpip_stat()
{
/* Zeit */
mpc_dw0_stat_time[mpc_dw0_iter] = mpc_dw0_glqdocpip_timer_get();
}


static void mpc_dw0_glqdocpip_factor()
{
mpc_dw0_error_source = 1;
mpc_dw0_stat_num_factor++;
/* Factor: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx11, mpc_dw0_Gxx11);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu11, mpc_dw0_Gxu11);
mpc_dw0_m_init0_6_2(mpc_dw0_tmp1_6_2);
mpc_dw0_mtd_sid53_sid17_2_6(mpc_dw0_gx11, mpc_dw0_yny11, mpc_dw0_tmp1_6_2);
mpc_dw0_mm_y_sid14_sid53_6_2_6(mpc_dw0_tmp1_6_2, mpc_dw0_gx11, mpc_dw0_Gxx11);
mpc_dw0_mm_sid14_sid56_6_2_1(mpc_dw0_tmp1_6_2, mpc_dw0_gu11, mpc_dw0_Gxu11);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu11, mpc_dw0_Guu11);
mpc_dw0_m_init0_1_2(mpc_dw0_tmp1_1_2);
mpc_dw0_mtd_sid56_sid17_2_1(mpc_dw0_gu11, mpc_dw0_yny11, mpc_dw0_tmp1_1_2);
mpc_dw0_mm_1_2_1(mpc_dw0_tmp1_1_2, mpc_dw0_gu11, mpc_dw0_Guu11);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu11, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu11, mpc_dw0_L11);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L11, mpc_dw0_tmp1_1_6, mpc_dw0_Rux11);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx11);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu11, mpc_dw0_Rux11, mpc_dw0_Vxx11);
mpc_dw0_msub_6_6(mpc_dw0_Gxx11, mpc_dw0_Vxx11, mpc_dw0_Vxx11);
/* Zeitschritt 10 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx10, mpc_dw0_Gxx10);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu10, mpc_dw0_Gxu10);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx10, mpc_dw0_Vxx11, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx10, mpc_dw0_Gxx10);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu10, mpc_dw0_Gxu10);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx10, mpc_dw0_yny10, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx10, mpc_dw0_Gxx10);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu10, mpc_dw0_Gxu10);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu10, mpc_dw0_Guu10);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu10, mpc_dw0_Vxx11, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu10, mpc_dw0_Guu10);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu10, mpc_dw0_yny10, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu10, mpc_dw0_Guu10);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu10, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu10, mpc_dw0_L10);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L10, mpc_dw0_tmp1_1_6, mpc_dw0_Rux10);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx10);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu10, mpc_dw0_Rux10, mpc_dw0_Vxx10);
mpc_dw0_msub_6_6(mpc_dw0_Gxx10, mpc_dw0_Vxx10, mpc_dw0_Vxx10);
/* Zeitschritt 9 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx9, mpc_dw0_Gxx9);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu9, mpc_dw0_Gxu9);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx9, mpc_dw0_Vxx10, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx9, mpc_dw0_Gxx9);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu9, mpc_dw0_Gxu9);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx9, mpc_dw0_yny9, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx9, mpc_dw0_Gxx9);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu9, mpc_dw0_Gxu9);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu9, mpc_dw0_Guu9);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu9, mpc_dw0_Vxx10, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu9, mpc_dw0_Guu9);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu9, mpc_dw0_yny9, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu9, mpc_dw0_Guu9);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu9, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu9, mpc_dw0_L9);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L9, mpc_dw0_tmp1_1_6, mpc_dw0_Rux9);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx9);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu9, mpc_dw0_Rux9, mpc_dw0_Vxx9);
mpc_dw0_msub_6_6(mpc_dw0_Gxx9, mpc_dw0_Vxx9, mpc_dw0_Vxx9);
/* Zeitschritt 8 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx8, mpc_dw0_Gxx8);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu8, mpc_dw0_Gxu8);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx8, mpc_dw0_Vxx9, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx8, mpc_dw0_Gxx8);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu8, mpc_dw0_Gxu8);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx8, mpc_dw0_yny8, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx8, mpc_dw0_Gxx8);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu8, mpc_dw0_Gxu8);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu8, mpc_dw0_Guu8);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu8, mpc_dw0_Vxx9, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu8, mpc_dw0_Guu8);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu8, mpc_dw0_yny8, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu8, mpc_dw0_Guu8);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu8, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu8, mpc_dw0_L8);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L8, mpc_dw0_tmp1_1_6, mpc_dw0_Rux8);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx8);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu8, mpc_dw0_Rux8, mpc_dw0_Vxx8);
mpc_dw0_msub_6_6(mpc_dw0_Gxx8, mpc_dw0_Vxx8, mpc_dw0_Vxx8);
/* Zeitschritt 7 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx7, mpc_dw0_Gxx7);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu7, mpc_dw0_Gxu7);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx7, mpc_dw0_Vxx8, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx7, mpc_dw0_Gxx7);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu7, mpc_dw0_Gxu7);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx7, mpc_dw0_yny7, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx7, mpc_dw0_Gxx7);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu7, mpc_dw0_Gxu7);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu7, mpc_dw0_Guu7);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu7, mpc_dw0_Vxx8, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu7, mpc_dw0_Guu7);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu7, mpc_dw0_yny7, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu7, mpc_dw0_Guu7);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu7, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu7, mpc_dw0_L7);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L7, mpc_dw0_tmp1_1_6, mpc_dw0_Rux7);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx7);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu7, mpc_dw0_Rux7, mpc_dw0_Vxx7);
mpc_dw0_msub_6_6(mpc_dw0_Gxx7, mpc_dw0_Vxx7, mpc_dw0_Vxx7);
/* Zeitschritt 6 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx6, mpc_dw0_Gxx6);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu6, mpc_dw0_Gxu6);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx6, mpc_dw0_Vxx7, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx6, mpc_dw0_Gxx6);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu6, mpc_dw0_Gxu6);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx6, mpc_dw0_yny6, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx6, mpc_dw0_Gxx6);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu6, mpc_dw0_Gxu6);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu6, mpc_dw0_Guu6);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu6, mpc_dw0_Vxx7, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu6, mpc_dw0_Guu6);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu6, mpc_dw0_yny6, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu6, mpc_dw0_Guu6);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu6, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu6, mpc_dw0_L6);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L6, mpc_dw0_tmp1_1_6, mpc_dw0_Rux6);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx6);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu6, mpc_dw0_Rux6, mpc_dw0_Vxx6);
mpc_dw0_msub_6_6(mpc_dw0_Gxx6, mpc_dw0_Vxx6, mpc_dw0_Vxx6);
/* Zeitschritt 5 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx5, mpc_dw0_Gxx5);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu5, mpc_dw0_Gxu5);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx5, mpc_dw0_Vxx6, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx5, mpc_dw0_Gxx5);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu5, mpc_dw0_Gxu5);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx5, mpc_dw0_yny5, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx5, mpc_dw0_Gxx5);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu5, mpc_dw0_Gxu5);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu5, mpc_dw0_Guu5);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu5, mpc_dw0_Vxx6, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu5, mpc_dw0_Guu5);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu5, mpc_dw0_yny5, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu5, mpc_dw0_Guu5);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu5, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu5, mpc_dw0_L5);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L5, mpc_dw0_tmp1_1_6, mpc_dw0_Rux5);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx5);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu5, mpc_dw0_Rux5, mpc_dw0_Vxx5);
mpc_dw0_msub_6_6(mpc_dw0_Gxx5, mpc_dw0_Vxx5, mpc_dw0_Vxx5);
/* Zeitschritt 4 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx4, mpc_dw0_Gxx4);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu4, mpc_dw0_Gxu4);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx4, mpc_dw0_Vxx5, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx4, mpc_dw0_Gxx4);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu4, mpc_dw0_Gxu4);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx4, mpc_dw0_yny4, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx4, mpc_dw0_Gxx4);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu4, mpc_dw0_Gxu4);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu4, mpc_dw0_Guu4);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu4, mpc_dw0_Vxx5, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu4, mpc_dw0_Guu4);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu4, mpc_dw0_yny4, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu4, mpc_dw0_Guu4);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu4, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu4, mpc_dw0_L4);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L4, mpc_dw0_tmp1_1_6, mpc_dw0_Rux4);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx4);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu4, mpc_dw0_Rux4, mpc_dw0_Vxx4);
mpc_dw0_msub_6_6(mpc_dw0_Gxx4, mpc_dw0_Vxx4, mpc_dw0_Vxx4);
/* Zeitschritt 3 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx3, mpc_dw0_Gxx3);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu3, mpc_dw0_Gxu3);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx3, mpc_dw0_Vxx4, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx3, mpc_dw0_Gxx3);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu3, mpc_dw0_Gxu3);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx3, mpc_dw0_yny3, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx3, mpc_dw0_Gxx3);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu3, mpc_dw0_Gxu3);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu3, mpc_dw0_Guu3);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu3, mpc_dw0_Vxx4, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu3, mpc_dw0_Guu3);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu3, mpc_dw0_yny3, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu3, mpc_dw0_Guu3);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu3, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu3, mpc_dw0_L3);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L3, mpc_dw0_tmp1_1_6, mpc_dw0_Rux3);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx3);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu3, mpc_dw0_Rux3, mpc_dw0_Vxx3);
mpc_dw0_msub_6_6(mpc_dw0_Gxx3, mpc_dw0_Vxx3, mpc_dw0_Vxx3);
/* Zeitschritt 2 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx2, mpc_dw0_Gxx2);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu2, mpc_dw0_Gxu2);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx2, mpc_dw0_Vxx3, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx2, mpc_dw0_Gxx2);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu2, mpc_dw0_Gxu2);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx2, mpc_dw0_yny2, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx2, mpc_dw0_Gxx2);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu2, mpc_dw0_Gxu2);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu2, mpc_dw0_Guu2);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu2, mpc_dw0_Vxx3, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu2, mpc_dw0_Guu2);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu2, mpc_dw0_yny2, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu2, mpc_dw0_Guu2);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu2, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu2, mpc_dw0_L2);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L2, mpc_dw0_tmp1_1_6, mpc_dw0_Rux2);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx2);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu2, mpc_dw0_Rux2, mpc_dw0_Vxx2);
mpc_dw0_msub_6_6(mpc_dw0_Gxx2, mpc_dw0_Vxx2, mpc_dw0_Vxx2);
/* Zeitschritt 1 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx1, mpc_dw0_Gxx1);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu1, mpc_dw0_Gxu1);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid43_sid1_6_6_6(mpc_dw0_fx1, mpc_dw0_Vxx2, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid43_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx1, mpc_dw0_Gxx1);
mpc_dw0_mm_sid1_sid46_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu1, mpc_dw0_Gxu1);
mpc_dw0_m_init0_6_4(mpc_dw0_tmp1_6_4);
mpc_dw0_mtd_sid52_sid16_4_6(mpc_dw0_gx1, mpc_dw0_yny1, mpc_dw0_tmp1_6_4);
mpc_dw0_mm_y_sid13_sid52_6_4_6(mpc_dw0_tmp1_6_4, mpc_dw0_gx1, mpc_dw0_Gxx1);
mpc_dw0_mm_sid13_sid55_6_4_1(mpc_dw0_tmp1_6_4, mpc_dw0_gu1, mpc_dw0_Gxu1);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu1, mpc_dw0_Guu1);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid46_sid1_6_1_6(mpc_dw0_fu1, mpc_dw0_Vxx2, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid46_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu1, mpc_dw0_Guu1);
mpc_dw0_m_init0_1_4(mpc_dw0_tmp1_1_4);
mpc_dw0_mtd_sid55_sid16_4_1(mpc_dw0_gu1, mpc_dw0_yny1, mpc_dw0_tmp1_1_4);
mpc_dw0_mm_1_4_1(mpc_dw0_tmp1_1_4, mpc_dw0_gu1, mpc_dw0_Guu1);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu1, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu1, mpc_dw0_L1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L1, mpc_dw0_tmp1_1_6, mpc_dw0_Rux1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx1);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu1, mpc_dw0_Rux1, mpc_dw0_Vxx1);
mpc_dw0_msub_6_6(mpc_dw0_Gxx1, mpc_dw0_Vxx1, mpc_dw0_Vxx1);
/* Zeitschritt 0 */
/* Gxx und Gxu */
mpc_dw0_m_copy_6_6(mpc_dw0_Hxx0, mpc_dw0_Gxx0);
mpc_dw0_m_copy_6_1(mpc_dw0_Hxu0, mpc_dw0_Gxu0);
mpc_dw0_m_init0_6_6(mpc_dw0_tmp1_6_6);
mpc_dw0_mtm_sid42_sid1_6_6_6(mpc_dw0_fx0, mpc_dw0_Vxx1, mpc_dw0_tmp1_6_6);
mpc_dw0_mm_y_sid1_sid42_6_6_6(mpc_dw0_tmp1_6_6, mpc_dw0_fx0, mpc_dw0_Gxx0);
mpc_dw0_mm_sid1_sid45_6_6_1(mpc_dw0_tmp1_6_6, mpc_dw0_fu0, mpc_dw0_Gxu0);
mpc_dw0_m_init0_6_2(mpc_dw0_tmp1_6_2);
mpc_dw0_mtd_sid51_sid15_2_6(mpc_dw0_gx0, mpc_dw0_yny0, mpc_dw0_tmp1_6_2);
mpc_dw0_mm_y_sid12_sid51_6_2_6(mpc_dw0_tmp1_6_2, mpc_dw0_gx0, mpc_dw0_Gxx0);
mpc_dw0_mm_sid12_sid54_6_2_1(mpc_dw0_tmp1_6_2, mpc_dw0_gu0, mpc_dw0_Gxu0);
/* Guu */
mpc_dw0_m_copy_1_1(mpc_dw0_Huu0, mpc_dw0_Guu0);
mpc_dw0_m_init0_1_6(mpc_dw0_tmp1_1_6);
mpc_dw0_mtm_sid45_sid1_6_1_6(mpc_dw0_fu0, mpc_dw0_Vxx1, mpc_dw0_tmp1_1_6);
mpc_dw0_mm_sid8_sid45_1_6_1(mpc_dw0_tmp1_1_6, mpc_dw0_fu0, mpc_dw0_Guu0);
mpc_dw0_m_init0_1_2(mpc_dw0_tmp1_1_2);
mpc_dw0_mtd_sid54_sid15_2_1(mpc_dw0_gu0, mpc_dw0_yny0, mpc_dw0_tmp1_1_2);
mpc_dw0_mm_1_2_1(mpc_dw0_tmp1_1_2, mpc_dw0_gu0, mpc_dw0_Guu0);
/* Rux */
mpc_dw0_mtr_6_1(mpc_dw0_Gxu0, mpc_dw0_tmp1_1_6);
mpc_dw0_chol_factor_1(mpc_dw0_Guu0, mpc_dw0_L0);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_chol_solve_1_6(mpc_dw0_L0, mpc_dw0_tmp1_1_6, mpc_dw0_Rux0);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_m_init0_6_6(mpc_dw0_Vxx0);
mpc_dw0_mm_y_6_1_6(mpc_dw0_Gxu0, mpc_dw0_Rux0, mpc_dw0_Vxx0);
mpc_dw0_msub_6_6(mpc_dw0_Gxx0, mpc_dw0_Vxx0, mpc_dw0_Vxx0);
mpc_dw0_error_source = 0;

}


static void mpc_dw0_glqdocpip_solve()
{
mpc_dw0_error_source = 2;
mpc_dw0_stat_num_solve++;
/* Solve: Rückwärtsiteration */
/* Zeitschritt 11 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x11, mpc_dw0_Gx11);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u11, mpc_dw0_Gu11);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L11, mpc_dw0_Gu11, mpc_dw0_Ru11);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu11, mpc_dw0_Ru11, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx11, mpc_dw0_tmp1_6, mpc_dw0_Vx11);
/* Zeitschritt 10 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x10, mpc_dw0_Gx10);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u10, mpc_dw0_Gu10);
mpc_dw0_v_copy_6(mpc_dw0_Vx11, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx11, mpc_dw0_rf11, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx10, mpc_dw0_tmp1_6, mpc_dw0_Gx10);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu10, mpc_dw0_tmp1_6, mpc_dw0_Gu10);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L10, mpc_dw0_Gu10, mpc_dw0_Ru10);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu10, mpc_dw0_Ru10, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx10, mpc_dw0_tmp1_6, mpc_dw0_Vx10);
/* Zeitschritt 9 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x9, mpc_dw0_Gx9);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u9, mpc_dw0_Gu9);
mpc_dw0_v_copy_6(mpc_dw0_Vx10, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx10, mpc_dw0_rf10, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_tmp1_6, mpc_dw0_Gx9);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu9, mpc_dw0_tmp1_6, mpc_dw0_Gu9);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L9, mpc_dw0_Gu9, mpc_dw0_Ru9);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu9, mpc_dw0_Ru9, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx9, mpc_dw0_tmp1_6, mpc_dw0_Vx9);
/* Zeitschritt 8 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x8, mpc_dw0_Gx8);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u8, mpc_dw0_Gu8);
mpc_dw0_v_copy_6(mpc_dw0_Vx9, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx9, mpc_dw0_rf9, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_tmp1_6, mpc_dw0_Gx8);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu8, mpc_dw0_tmp1_6, mpc_dw0_Gu8);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L8, mpc_dw0_Gu8, mpc_dw0_Ru8);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu8, mpc_dw0_Ru8, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx8, mpc_dw0_tmp1_6, mpc_dw0_Vx8);
/* Zeitschritt 7 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x7, mpc_dw0_Gx7);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u7, mpc_dw0_Gu7);
mpc_dw0_v_copy_6(mpc_dw0_Vx8, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx8, mpc_dw0_rf8, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_tmp1_6, mpc_dw0_Gx7);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu7, mpc_dw0_tmp1_6, mpc_dw0_Gu7);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L7, mpc_dw0_Gu7, mpc_dw0_Ru7);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu7, mpc_dw0_Ru7, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx7, mpc_dw0_tmp1_6, mpc_dw0_Vx7);
/* Zeitschritt 6 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x6, mpc_dw0_Gx6);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u6, mpc_dw0_Gu6);
mpc_dw0_v_copy_6(mpc_dw0_Vx7, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx7, mpc_dw0_rf7, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_tmp1_6, mpc_dw0_Gx6);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu6, mpc_dw0_tmp1_6, mpc_dw0_Gu6);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L6, mpc_dw0_Gu6, mpc_dw0_Ru6);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu6, mpc_dw0_Ru6, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx6, mpc_dw0_tmp1_6, mpc_dw0_Vx6);
/* Zeitschritt 5 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x5, mpc_dw0_Gx5);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u5, mpc_dw0_Gu5);
mpc_dw0_v_copy_6(mpc_dw0_Vx6, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx6, mpc_dw0_rf6, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_tmp1_6, mpc_dw0_Gx5);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu5, mpc_dw0_tmp1_6, mpc_dw0_Gu5);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L5, mpc_dw0_Gu5, mpc_dw0_Ru5);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu5, mpc_dw0_Ru5, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx5, mpc_dw0_tmp1_6, mpc_dw0_Vx5);
/* Zeitschritt 4 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x4, mpc_dw0_Gx4);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u4, mpc_dw0_Gu4);
mpc_dw0_v_copy_6(mpc_dw0_Vx5, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx5, mpc_dw0_rf5, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_tmp1_6, mpc_dw0_Gx4);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu4, mpc_dw0_tmp1_6, mpc_dw0_Gu4);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L4, mpc_dw0_Gu4, mpc_dw0_Ru4);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu4, mpc_dw0_Ru4, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx4, mpc_dw0_tmp1_6, mpc_dw0_Vx4);
/* Zeitschritt 3 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x3, mpc_dw0_Gx3);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u3, mpc_dw0_Gu3);
mpc_dw0_v_copy_6(mpc_dw0_Vx4, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx4, mpc_dw0_rf4, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_tmp1_6, mpc_dw0_Gx3);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu3, mpc_dw0_tmp1_6, mpc_dw0_Gu3);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L3, mpc_dw0_Gu3, mpc_dw0_Ru3);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu3, mpc_dw0_Ru3, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx3, mpc_dw0_tmp1_6, mpc_dw0_Vx3);
/* Zeitschritt 2 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x2, mpc_dw0_Gx2);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u2, mpc_dw0_Gu2);
mpc_dw0_v_copy_6(mpc_dw0_Vx3, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx3, mpc_dw0_rf3, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_tmp1_6, mpc_dw0_Gx2);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu2, mpc_dw0_tmp1_6, mpc_dw0_Gu2);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L2, mpc_dw0_Gu2, mpc_dw0_Ru2);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu2, mpc_dw0_Ru2, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx2, mpc_dw0_tmp1_6, mpc_dw0_Vx2);
/* Zeitschritt 1 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x1, mpc_dw0_Gx1);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u1, mpc_dw0_Gu1);
mpc_dw0_v_copy_6(mpc_dw0_Vx2, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx2, mpc_dw0_rf2, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_tmp1_6, mpc_dw0_Gx1);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu1, mpc_dw0_tmp1_6, mpc_dw0_Gu1);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L1, mpc_dw0_Gu1, mpc_dw0_Ru1);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu1, mpc_dw0_Ru1, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx1, mpc_dw0_tmp1_6, mpc_dw0_Vx1);
/* Zeitschritt 0 */
/* Gx und Gu */
mpc_dw0_v_copy_6(mpc_dw0_rrf0x0, mpc_dw0_Gx0);
mpc_dw0_v_copy_1(mpc_dw0_rrf0u0, mpc_dw0_Gu0);
mpc_dw0_v_copy_6(mpc_dw0_Vx1, mpc_dw0_tmp1_6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx1, mpc_dw0_rf1, mpc_dw0_tmp1_6);
mpc_dw0_mtv_sid42_sid2_6_6(mpc_dw0_fx0, mpc_dw0_tmp1_6, mpc_dw0_Gx0);
mpc_dw0_mtv_sid45_sid2_6_1(mpc_dw0_fu0, mpc_dw0_tmp1_6, mpc_dw0_Gu0);
/* Ru */
mpc_dw0_chol_solve_1_1(mpc_dw0_L0, mpc_dw0_Gu0, mpc_dw0_Ru0);
if(mpc_dw0_termcode > -1){return;}
/* Vx */
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_v_init0_6(mpc_dw0_tmp1_6);
mpc_dw0_mv_6_1(mpc_dw0_Gxu0, mpc_dw0_Ru0, mpc_dw0_tmp1_6);
mpc_dw0_vsub_6(mpc_dw0_Gx0, mpc_dw0_tmp1_6, mpc_dw0_Vx0);
/* Solve: Vorwärtsiteration */
/* dx0 */
mpc_dw0_v_copy_6(mpc_dw0_rf0, mpc_dw0_dx0);
/* Zeitschritt 0 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx0, mpc_dw0_dp0);
mpc_dw0_mv_6_6(mpc_dw0_Vxx0, mpc_dw0_dx0, mpc_dw0_dp0);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru0, mpc_dw0_du0);
mpc_dw0_mv_1_6(mpc_dw0_Rux0, mpc_dw0_dx0, mpc_dw0_du0);
mpc_dw0_v_turnsign_1(mpc_dw0_du0, mpc_dw0_du0);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf1, mpc_dw0_dx1);
mpc_dw0_mv_sid42_sid2_6_6(mpc_dw0_fx0, mpc_dw0_dx0, mpc_dw0_dx1);
mpc_dw0_mv_sid45_sid5_6_1(mpc_dw0_fu0, mpc_dw0_du0, mpc_dw0_dx1);
/* Zeitschritt 1 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx1, mpc_dw0_dp1);
mpc_dw0_mv_6_6(mpc_dw0_Vxx1, mpc_dw0_dx1, mpc_dw0_dp1);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru1, mpc_dw0_du1);
mpc_dw0_mv_1_6(mpc_dw0_Rux1, mpc_dw0_dx1, mpc_dw0_du1);
mpc_dw0_v_turnsign_1(mpc_dw0_du1, mpc_dw0_du1);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf2, mpc_dw0_dx2);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_dx1, mpc_dw0_dx2);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu1, mpc_dw0_du1, mpc_dw0_dx2);
/* Zeitschritt 2 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx2, mpc_dw0_dp2);
mpc_dw0_mv_6_6(mpc_dw0_Vxx2, mpc_dw0_dx2, mpc_dw0_dp2);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru2, mpc_dw0_du2);
mpc_dw0_mv_1_6(mpc_dw0_Rux2, mpc_dw0_dx2, mpc_dw0_du2);
mpc_dw0_v_turnsign_1(mpc_dw0_du2, mpc_dw0_du2);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf3, mpc_dw0_dx3);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_dx2, mpc_dw0_dx3);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu2, mpc_dw0_du2, mpc_dw0_dx3);
/* Zeitschritt 3 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx3, mpc_dw0_dp3);
mpc_dw0_mv_6_6(mpc_dw0_Vxx3, mpc_dw0_dx3, mpc_dw0_dp3);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru3, mpc_dw0_du3);
mpc_dw0_mv_1_6(mpc_dw0_Rux3, mpc_dw0_dx3, mpc_dw0_du3);
mpc_dw0_v_turnsign_1(mpc_dw0_du3, mpc_dw0_du3);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf4, mpc_dw0_dx4);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_dx3, mpc_dw0_dx4);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu3, mpc_dw0_du3, mpc_dw0_dx4);
/* Zeitschritt 4 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx4, mpc_dw0_dp4);
mpc_dw0_mv_6_6(mpc_dw0_Vxx4, mpc_dw0_dx4, mpc_dw0_dp4);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru4, mpc_dw0_du4);
mpc_dw0_mv_1_6(mpc_dw0_Rux4, mpc_dw0_dx4, mpc_dw0_du4);
mpc_dw0_v_turnsign_1(mpc_dw0_du4, mpc_dw0_du4);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf5, mpc_dw0_dx5);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_dx4, mpc_dw0_dx5);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu4, mpc_dw0_du4, mpc_dw0_dx5);
/* Zeitschritt 5 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx5, mpc_dw0_dp5);
mpc_dw0_mv_6_6(mpc_dw0_Vxx5, mpc_dw0_dx5, mpc_dw0_dp5);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru5, mpc_dw0_du5);
mpc_dw0_mv_1_6(mpc_dw0_Rux5, mpc_dw0_dx5, mpc_dw0_du5);
mpc_dw0_v_turnsign_1(mpc_dw0_du5, mpc_dw0_du5);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf6, mpc_dw0_dx6);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_dx5, mpc_dw0_dx6);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu5, mpc_dw0_du5, mpc_dw0_dx6);
/* Zeitschritt 6 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx6, mpc_dw0_dp6);
mpc_dw0_mv_6_6(mpc_dw0_Vxx6, mpc_dw0_dx6, mpc_dw0_dp6);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru6, mpc_dw0_du6);
mpc_dw0_mv_1_6(mpc_dw0_Rux6, mpc_dw0_dx6, mpc_dw0_du6);
mpc_dw0_v_turnsign_1(mpc_dw0_du6, mpc_dw0_du6);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf7, mpc_dw0_dx7);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_dx6, mpc_dw0_dx7);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu6, mpc_dw0_du6, mpc_dw0_dx7);
/* Zeitschritt 7 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx7, mpc_dw0_dp7);
mpc_dw0_mv_6_6(mpc_dw0_Vxx7, mpc_dw0_dx7, mpc_dw0_dp7);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru7, mpc_dw0_du7);
mpc_dw0_mv_1_6(mpc_dw0_Rux7, mpc_dw0_dx7, mpc_dw0_du7);
mpc_dw0_v_turnsign_1(mpc_dw0_du7, mpc_dw0_du7);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf8, mpc_dw0_dx8);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_dx7, mpc_dw0_dx8);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu7, mpc_dw0_du7, mpc_dw0_dx8);
/* Zeitschritt 8 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx8, mpc_dw0_dp8);
mpc_dw0_mv_6_6(mpc_dw0_Vxx8, mpc_dw0_dx8, mpc_dw0_dp8);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru8, mpc_dw0_du8);
mpc_dw0_mv_1_6(mpc_dw0_Rux8, mpc_dw0_dx8, mpc_dw0_du8);
mpc_dw0_v_turnsign_1(mpc_dw0_du8, mpc_dw0_du8);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf9, mpc_dw0_dx9);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_dx8, mpc_dw0_dx9);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu8, mpc_dw0_du8, mpc_dw0_dx9);
/* Zeitschritt 9 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx9, mpc_dw0_dp9);
mpc_dw0_mv_6_6(mpc_dw0_Vxx9, mpc_dw0_dx9, mpc_dw0_dp9);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru9, mpc_dw0_du9);
mpc_dw0_mv_1_6(mpc_dw0_Rux9, mpc_dw0_dx9, mpc_dw0_du9);
mpc_dw0_v_turnsign_1(mpc_dw0_du9, mpc_dw0_du9);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf10, mpc_dw0_dx10);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_dx9, mpc_dw0_dx10);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu9, mpc_dw0_du9, mpc_dw0_dx10);
/* Zeitschritt 10 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx10, mpc_dw0_dp10);
mpc_dw0_mv_6_6(mpc_dw0_Vxx10, mpc_dw0_dx10, mpc_dw0_dp10);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru10, mpc_dw0_du10);
mpc_dw0_mv_1_6(mpc_dw0_Rux10, mpc_dw0_dx10, mpc_dw0_du10);
mpc_dw0_v_turnsign_1(mpc_dw0_du10, mpc_dw0_du10);
/* dx */
mpc_dw0_v_copy_6(mpc_dw0_rf11, mpc_dw0_dx11);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx10, mpc_dw0_dx10, mpc_dw0_dx11);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu10, mpc_dw0_du10, mpc_dw0_dx11);
/* Zeitschritt 11 */
/* dp */
mpc_dw0_v_copy_6(mpc_dw0_Vx11, mpc_dw0_dp11);
mpc_dw0_mv_6_6(mpc_dw0_Vxx11, mpc_dw0_dx11, mpc_dw0_dp11);
/* du */
mpc_dw0_v_copy_1(mpc_dw0_Ru11, mpc_dw0_du11);
mpc_dw0_mv_1_6(mpc_dw0_Rux11, mpc_dw0_dx11, mpc_dw0_du11);
mpc_dw0_v_turnsign_1(mpc_dw0_du11, mpc_dw0_du11);
/* dx */
mpc_dw0_error_source = 0;

}


static void mpc_dw0_glqdocpip_rhs_starting_point_5()
{
/* Zeitschritt 0 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x0);
mpc_dw0_v_init0_1(mpc_dw0_rf0u0);
mpc_dw0_v_copy_2(mpc_dw0_f0s0, mpc_dw0_rf0s0);
mpc_dw0_v_copy_6(mpc_dw0_xinit, mpc_dw0_rf0);
mpc_dw0_v_copy_2(mpc_dw0_g0, mpc_dw0_rc0);
mpc_dw0_v_init0_2(mpc_dw0_rs0);
mpc_dw0_vsub_2(&mpc_dw0_nu0[2], mpc_dw0_s0, mpc_dw0_rs0);
mpc_dw0_vv_elemult_4(mpc_dw0_y0, mpc_dw0_nu0, mpc_dw0_rk0);
/* Zeitschritt 1 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x1);
mpc_dw0_v_init0_1(mpc_dw0_rf0u1);
mpc_dw0_v_copy_4(mpc_dw0_f0s1, mpc_dw0_rf0s1);
mpc_dw0_v_copy_6(mpc_dw0_f0, mpc_dw0_rf1);
mpc_dw0_v_copy_4(mpc_dw0_g1, mpc_dw0_rc1);
mpc_dw0_v_init0_4(mpc_dw0_rs1);
mpc_dw0_vsub_4(&mpc_dw0_nu1[4], mpc_dw0_s1, mpc_dw0_rs1);
mpc_dw0_vv_elemult_8(mpc_dw0_y1, mpc_dw0_nu1, mpc_dw0_rk1);
/* Zeitschritt 2 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x2);
mpc_dw0_v_init0_1(mpc_dw0_rf0u2);
mpc_dw0_v_copy_4(mpc_dw0_f0s2, mpc_dw0_rf0s2);
mpc_dw0_v_copy_6(mpc_dw0_f1, mpc_dw0_rf2);
mpc_dw0_v_copy_4(mpc_dw0_g2, mpc_dw0_rc2);
mpc_dw0_v_init0_4(mpc_dw0_rs2);
mpc_dw0_vsub_4(&mpc_dw0_nu2[4], mpc_dw0_s2, mpc_dw0_rs2);
mpc_dw0_vv_elemult_8(mpc_dw0_y2, mpc_dw0_nu2, mpc_dw0_rk2);
/* Zeitschritt 3 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x3);
mpc_dw0_v_init0_1(mpc_dw0_rf0u3);
mpc_dw0_v_copy_4(mpc_dw0_f0s3, mpc_dw0_rf0s3);
mpc_dw0_v_copy_6(mpc_dw0_f2, mpc_dw0_rf3);
mpc_dw0_v_copy_4(mpc_dw0_g3, mpc_dw0_rc3);
mpc_dw0_v_init0_4(mpc_dw0_rs3);
mpc_dw0_vsub_4(&mpc_dw0_nu3[4], mpc_dw0_s3, mpc_dw0_rs3);
mpc_dw0_vv_elemult_8(mpc_dw0_y3, mpc_dw0_nu3, mpc_dw0_rk3);
/* Zeitschritt 4 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x4);
mpc_dw0_v_init0_1(mpc_dw0_rf0u4);
mpc_dw0_v_copy_4(mpc_dw0_f0s4, mpc_dw0_rf0s4);
mpc_dw0_v_copy_6(mpc_dw0_f3, mpc_dw0_rf4);
mpc_dw0_v_copy_4(mpc_dw0_g4, mpc_dw0_rc4);
mpc_dw0_v_init0_4(mpc_dw0_rs4);
mpc_dw0_vsub_4(&mpc_dw0_nu4[4], mpc_dw0_s4, mpc_dw0_rs4);
mpc_dw0_vv_elemult_8(mpc_dw0_y4, mpc_dw0_nu4, mpc_dw0_rk4);
/* Zeitschritt 5 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x5);
mpc_dw0_v_init0_1(mpc_dw0_rf0u5);
mpc_dw0_v_copy_4(mpc_dw0_f0s5, mpc_dw0_rf0s5);
mpc_dw0_v_copy_6(mpc_dw0_f4, mpc_dw0_rf5);
mpc_dw0_v_copy_4(mpc_dw0_g5, mpc_dw0_rc5);
mpc_dw0_v_init0_4(mpc_dw0_rs5);
mpc_dw0_vsub_4(&mpc_dw0_nu5[4], mpc_dw0_s5, mpc_dw0_rs5);
mpc_dw0_vv_elemult_8(mpc_dw0_y5, mpc_dw0_nu5, mpc_dw0_rk5);
/* Zeitschritt 6 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x6);
mpc_dw0_v_init0_1(mpc_dw0_rf0u6);
mpc_dw0_v_copy_4(mpc_dw0_f0s6, mpc_dw0_rf0s6);
mpc_dw0_v_copy_6(mpc_dw0_f5, mpc_dw0_rf6);
mpc_dw0_v_copy_4(mpc_dw0_g6, mpc_dw0_rc6);
mpc_dw0_v_init0_4(mpc_dw0_rs6);
mpc_dw0_vsub_4(&mpc_dw0_nu6[4], mpc_dw0_s6, mpc_dw0_rs6);
mpc_dw0_vv_elemult_8(mpc_dw0_y6, mpc_dw0_nu6, mpc_dw0_rk6);
/* Zeitschritt 7 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x7);
mpc_dw0_v_init0_1(mpc_dw0_rf0u7);
mpc_dw0_v_copy_4(mpc_dw0_f0s7, mpc_dw0_rf0s7);
mpc_dw0_v_copy_6(mpc_dw0_f6, mpc_dw0_rf7);
mpc_dw0_v_copy_4(mpc_dw0_g7, mpc_dw0_rc7);
mpc_dw0_v_init0_4(mpc_dw0_rs7);
mpc_dw0_vsub_4(&mpc_dw0_nu7[4], mpc_dw0_s7, mpc_dw0_rs7);
mpc_dw0_vv_elemult_8(mpc_dw0_y7, mpc_dw0_nu7, mpc_dw0_rk7);
/* Zeitschritt 8 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x8);
mpc_dw0_v_init0_1(mpc_dw0_rf0u8);
mpc_dw0_v_copy_4(mpc_dw0_f0s8, mpc_dw0_rf0s8);
mpc_dw0_v_copy_6(mpc_dw0_f7, mpc_dw0_rf8);
mpc_dw0_v_copy_4(mpc_dw0_g8, mpc_dw0_rc8);
mpc_dw0_v_init0_4(mpc_dw0_rs8);
mpc_dw0_vsub_4(&mpc_dw0_nu8[4], mpc_dw0_s8, mpc_dw0_rs8);
mpc_dw0_vv_elemult_8(mpc_dw0_y8, mpc_dw0_nu8, mpc_dw0_rk8);
/* Zeitschritt 9 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x9);
mpc_dw0_v_init0_1(mpc_dw0_rf0u9);
mpc_dw0_v_copy_4(mpc_dw0_f0s9, mpc_dw0_rf0s9);
mpc_dw0_v_copy_6(mpc_dw0_f8, mpc_dw0_rf9);
mpc_dw0_v_copy_4(mpc_dw0_g9, mpc_dw0_rc9);
mpc_dw0_v_init0_4(mpc_dw0_rs9);
mpc_dw0_vsub_4(&mpc_dw0_nu9[4], mpc_dw0_s9, mpc_dw0_rs9);
mpc_dw0_vv_elemult_8(mpc_dw0_y9, mpc_dw0_nu9, mpc_dw0_rk9);
/* Zeitschritt 10 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x10);
mpc_dw0_v_init0_1(mpc_dw0_rf0u10);
mpc_dw0_v_copy_4(mpc_dw0_f0s10, mpc_dw0_rf0s10);
mpc_dw0_v_copy_6(mpc_dw0_f9, mpc_dw0_rf10);
mpc_dw0_v_copy_4(mpc_dw0_g10, mpc_dw0_rc10);
mpc_dw0_v_init0_4(mpc_dw0_rs10);
mpc_dw0_vsub_4(&mpc_dw0_nu10[4], mpc_dw0_s10, mpc_dw0_rs10);
mpc_dw0_vv_elemult_8(mpc_dw0_y10, mpc_dw0_nu10, mpc_dw0_rk10);
/* Zeitschritt 11 */
mpc_dw0_v_init0_6(mpc_dw0_rf0x11);
mpc_dw0_v_init0_1(mpc_dw0_rf0u11);
mpc_dw0_v_copy_2(mpc_dw0_f0s11, mpc_dw0_rf0s11);
mpc_dw0_v_copy_6(mpc_dw0_f10, mpc_dw0_rf11);
mpc_dw0_v_copy_2(mpc_dw0_g11, mpc_dw0_rc11);
mpc_dw0_v_init0_2(mpc_dw0_rs11);
mpc_dw0_vsub_2(&mpc_dw0_nu11[2], mpc_dw0_s11, mpc_dw0_rs11);
mpc_dw0_vv_elemult_4(mpc_dw0_y11, mpc_dw0_nu11, mpc_dw0_rk11);
}


static void mpc_dw0_glqdocpip_rhs_affine()
{
/* Zeitschritt 0 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x0, mpc_dw0_rf0x0);
mpc_dw0_mv_sid21_sid2_6_6(mpc_dw0_Hxx0, mpc_dw0_x0, mpc_dw0_rf0x0);
mpc_dw0_mv_sid24_sid5_6_1(mpc_dw0_Hxu0, mpc_dw0_u0, mpc_dw0_rf0x0);
mpc_dw0_vsub_6(mpc_dw0_rf0x0, mpc_dw0_p0, mpc_dw0_rf0x0);
mpc_dw0_mtv_sid42_sid2_6_6(mpc_dw0_fx0, mpc_dw0_p1, mpc_dw0_rf0x0);
mpc_dw0_mtv_sid51_sid15_2_6(mpc_dw0_gx0, mpc_dw0_y0, mpc_dw0_rf0x0);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u0, mpc_dw0_rf0u0);
mpc_dw0_mtv_sid24_sid2_6_1(mpc_dw0_Hxu0, mpc_dw0_x0, mpc_dw0_rf0u0);
mpc_dw0_mv_sid27_sid5_1_1(mpc_dw0_Huu0, mpc_dw0_u0, mpc_dw0_rf0u0);
mpc_dw0_mtv_sid45_sid2_6_1(mpc_dw0_fu0, mpc_dw0_p1, mpc_dw0_rf0u0);
mpc_dw0_mtv_sid54_sid15_2_1(mpc_dw0_gu0, mpc_dw0_y0, mpc_dw0_rf0u0);
/* rf0s */
mpc_dw0_v_copy_2(mpc_dw0_f0s0, mpc_dw0_rf0s0);
mpc_dw0_mv_sid30_sid18_2_2(mpc_dw0_Hss0, mpc_dw0_s0, mpc_dw0_rf0s0);
mpc_dw0_vsub_2(mpc_dw0_rf0s0, &mpc_dw0_y0[0], mpc_dw0_rf0s0);
mpc_dw0_vsub_2(mpc_dw0_rf0s0, &mpc_dw0_y0[2], mpc_dw0_rf0s0);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_xinit, mpc_dw0_rf0);
mpc_dw0_vsub_6(mpc_dw0_rf0, mpc_dw0_x0, mpc_dw0_rf0);
/* rc */
mpc_dw0_v_copy_2(mpc_dw0_g0, mpc_dw0_rc0);
mpc_dw0_mv_sid51_sid2_2_6(mpc_dw0_gx0, mpc_dw0_x0, mpc_dw0_rc0);
mpc_dw0_mv_sid54_sid5_2_1(mpc_dw0_gu0, mpc_dw0_u0, mpc_dw0_rc0);
mpc_dw0_vadd_2(mpc_dw0_rc0, mpc_dw0_nu0, mpc_dw0_rc0);
mpc_dw0_vsub_2(mpc_dw0_rc0, mpc_dw0_s0, mpc_dw0_rc0);
/* rs */
mpc_dw0_v_init0_2(mpc_dw0_rs0);
mpc_dw0_vsub_2(&mpc_dw0_nu0[2], mpc_dw0_s0, mpc_dw0_rs0);
/* rk */
mpc_dw0_vv_elemult_4(mpc_dw0_y0, mpc_dw0_nu0, mpc_dw0_rk0);
/* Zeitschritt 1 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x1, mpc_dw0_rf0x1);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx1, mpc_dw0_x1, mpc_dw0_rf0x1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu1, mpc_dw0_u1, mpc_dw0_rf0x1);
mpc_dw0_vsub_6(mpc_dw0_rf0x1, mpc_dw0_p1, mpc_dw0_rf0x1);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_p2, mpc_dw0_rf0x1);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx1, mpc_dw0_y1, mpc_dw0_rf0x1);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u1, mpc_dw0_rf0u1);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu1, mpc_dw0_x1, mpc_dw0_rf0u1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu1, mpc_dw0_u1, mpc_dw0_rf0u1);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu1, mpc_dw0_p2, mpc_dw0_rf0u1);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu1, mpc_dw0_y1, mpc_dw0_rf0u1);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s1, mpc_dw0_rf0s1);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss1, mpc_dw0_s1, mpc_dw0_rf0s1);
mpc_dw0_vsub_4(mpc_dw0_rf0s1, &mpc_dw0_y1[0], mpc_dw0_rf0s1);
mpc_dw0_vsub_4(mpc_dw0_rf0s1, &mpc_dw0_y1[4], mpc_dw0_rf0s1);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f0, mpc_dw0_rf1);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx0, mpc_dw0_x0, mpc_dw0_rf1);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu0, mpc_dw0_u0, mpc_dw0_rf1);
mpc_dw0_vsub_6(mpc_dw0_rf1, mpc_dw0_x1, mpc_dw0_rf1);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g1, mpc_dw0_rc1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx1, mpc_dw0_x1, mpc_dw0_rc1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu1, mpc_dw0_u1, mpc_dw0_rc1);
mpc_dw0_vadd_4(mpc_dw0_rc1, mpc_dw0_nu1, mpc_dw0_rc1);
mpc_dw0_vsub_4(mpc_dw0_rc1, mpc_dw0_s1, mpc_dw0_rc1);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs1);
mpc_dw0_vsub_4(&mpc_dw0_nu1[4], mpc_dw0_s1, mpc_dw0_rs1);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y1, mpc_dw0_nu1, mpc_dw0_rk1);
/* Zeitschritt 2 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x2, mpc_dw0_rf0x2);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx2, mpc_dw0_x2, mpc_dw0_rf0x2);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu2, mpc_dw0_u2, mpc_dw0_rf0x2);
mpc_dw0_vsub_6(mpc_dw0_rf0x2, mpc_dw0_p2, mpc_dw0_rf0x2);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_p3, mpc_dw0_rf0x2);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx2, mpc_dw0_y2, mpc_dw0_rf0x2);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u2, mpc_dw0_rf0u2);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu2, mpc_dw0_x2, mpc_dw0_rf0u2);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu2, mpc_dw0_u2, mpc_dw0_rf0u2);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu2, mpc_dw0_p3, mpc_dw0_rf0u2);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu2, mpc_dw0_y2, mpc_dw0_rf0u2);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s2, mpc_dw0_rf0s2);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss2, mpc_dw0_s2, mpc_dw0_rf0s2);
mpc_dw0_vsub_4(mpc_dw0_rf0s2, &mpc_dw0_y2[0], mpc_dw0_rf0s2);
mpc_dw0_vsub_4(mpc_dw0_rf0s2, &mpc_dw0_y2[4], mpc_dw0_rf0s2);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f1, mpc_dw0_rf2);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_x1, mpc_dw0_rf2);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu1, mpc_dw0_u1, mpc_dw0_rf2);
mpc_dw0_vsub_6(mpc_dw0_rf2, mpc_dw0_x2, mpc_dw0_rf2);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g2, mpc_dw0_rc2);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx2, mpc_dw0_x2, mpc_dw0_rc2);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu2, mpc_dw0_u2, mpc_dw0_rc2);
mpc_dw0_vadd_4(mpc_dw0_rc2, mpc_dw0_nu2, mpc_dw0_rc2);
mpc_dw0_vsub_4(mpc_dw0_rc2, mpc_dw0_s2, mpc_dw0_rc2);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs2);
mpc_dw0_vsub_4(&mpc_dw0_nu2[4], mpc_dw0_s2, mpc_dw0_rs2);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y2, mpc_dw0_nu2, mpc_dw0_rk2);
/* Zeitschritt 3 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x3, mpc_dw0_rf0x3);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx3, mpc_dw0_x3, mpc_dw0_rf0x3);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu3, mpc_dw0_u3, mpc_dw0_rf0x3);
mpc_dw0_vsub_6(mpc_dw0_rf0x3, mpc_dw0_p3, mpc_dw0_rf0x3);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_p4, mpc_dw0_rf0x3);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx3, mpc_dw0_y3, mpc_dw0_rf0x3);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u3, mpc_dw0_rf0u3);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu3, mpc_dw0_x3, mpc_dw0_rf0u3);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu3, mpc_dw0_u3, mpc_dw0_rf0u3);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu3, mpc_dw0_p4, mpc_dw0_rf0u3);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu3, mpc_dw0_y3, mpc_dw0_rf0u3);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s3, mpc_dw0_rf0s3);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss3, mpc_dw0_s3, mpc_dw0_rf0s3);
mpc_dw0_vsub_4(mpc_dw0_rf0s3, &mpc_dw0_y3[0], mpc_dw0_rf0s3);
mpc_dw0_vsub_4(mpc_dw0_rf0s3, &mpc_dw0_y3[4], mpc_dw0_rf0s3);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f2, mpc_dw0_rf3);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_x2, mpc_dw0_rf3);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu2, mpc_dw0_u2, mpc_dw0_rf3);
mpc_dw0_vsub_6(mpc_dw0_rf3, mpc_dw0_x3, mpc_dw0_rf3);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g3, mpc_dw0_rc3);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx3, mpc_dw0_x3, mpc_dw0_rc3);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu3, mpc_dw0_u3, mpc_dw0_rc3);
mpc_dw0_vadd_4(mpc_dw0_rc3, mpc_dw0_nu3, mpc_dw0_rc3);
mpc_dw0_vsub_4(mpc_dw0_rc3, mpc_dw0_s3, mpc_dw0_rc3);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs3);
mpc_dw0_vsub_4(&mpc_dw0_nu3[4], mpc_dw0_s3, mpc_dw0_rs3);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y3, mpc_dw0_nu3, mpc_dw0_rk3);
/* Zeitschritt 4 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x4, mpc_dw0_rf0x4);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx4, mpc_dw0_x4, mpc_dw0_rf0x4);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu4, mpc_dw0_u4, mpc_dw0_rf0x4);
mpc_dw0_vsub_6(mpc_dw0_rf0x4, mpc_dw0_p4, mpc_dw0_rf0x4);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_p5, mpc_dw0_rf0x4);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx4, mpc_dw0_y4, mpc_dw0_rf0x4);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u4, mpc_dw0_rf0u4);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu4, mpc_dw0_x4, mpc_dw0_rf0u4);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu4, mpc_dw0_u4, mpc_dw0_rf0u4);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu4, mpc_dw0_p5, mpc_dw0_rf0u4);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu4, mpc_dw0_y4, mpc_dw0_rf0u4);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s4, mpc_dw0_rf0s4);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss4, mpc_dw0_s4, mpc_dw0_rf0s4);
mpc_dw0_vsub_4(mpc_dw0_rf0s4, &mpc_dw0_y4[0], mpc_dw0_rf0s4);
mpc_dw0_vsub_4(mpc_dw0_rf0s4, &mpc_dw0_y4[4], mpc_dw0_rf0s4);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f3, mpc_dw0_rf4);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_x3, mpc_dw0_rf4);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu3, mpc_dw0_u3, mpc_dw0_rf4);
mpc_dw0_vsub_6(mpc_dw0_rf4, mpc_dw0_x4, mpc_dw0_rf4);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g4, mpc_dw0_rc4);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx4, mpc_dw0_x4, mpc_dw0_rc4);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu4, mpc_dw0_u4, mpc_dw0_rc4);
mpc_dw0_vadd_4(mpc_dw0_rc4, mpc_dw0_nu4, mpc_dw0_rc4);
mpc_dw0_vsub_4(mpc_dw0_rc4, mpc_dw0_s4, mpc_dw0_rc4);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs4);
mpc_dw0_vsub_4(&mpc_dw0_nu4[4], mpc_dw0_s4, mpc_dw0_rs4);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y4, mpc_dw0_nu4, mpc_dw0_rk4);
/* Zeitschritt 5 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x5, mpc_dw0_rf0x5);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx5, mpc_dw0_x5, mpc_dw0_rf0x5);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu5, mpc_dw0_u5, mpc_dw0_rf0x5);
mpc_dw0_vsub_6(mpc_dw0_rf0x5, mpc_dw0_p5, mpc_dw0_rf0x5);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_p6, mpc_dw0_rf0x5);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx5, mpc_dw0_y5, mpc_dw0_rf0x5);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u5, mpc_dw0_rf0u5);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu5, mpc_dw0_x5, mpc_dw0_rf0u5);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu5, mpc_dw0_u5, mpc_dw0_rf0u5);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu5, mpc_dw0_p6, mpc_dw0_rf0u5);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu5, mpc_dw0_y5, mpc_dw0_rf0u5);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s5, mpc_dw0_rf0s5);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss5, mpc_dw0_s5, mpc_dw0_rf0s5);
mpc_dw0_vsub_4(mpc_dw0_rf0s5, &mpc_dw0_y5[0], mpc_dw0_rf0s5);
mpc_dw0_vsub_4(mpc_dw0_rf0s5, &mpc_dw0_y5[4], mpc_dw0_rf0s5);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f4, mpc_dw0_rf5);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_x4, mpc_dw0_rf5);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu4, mpc_dw0_u4, mpc_dw0_rf5);
mpc_dw0_vsub_6(mpc_dw0_rf5, mpc_dw0_x5, mpc_dw0_rf5);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g5, mpc_dw0_rc5);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx5, mpc_dw0_x5, mpc_dw0_rc5);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu5, mpc_dw0_u5, mpc_dw0_rc5);
mpc_dw0_vadd_4(mpc_dw0_rc5, mpc_dw0_nu5, mpc_dw0_rc5);
mpc_dw0_vsub_4(mpc_dw0_rc5, mpc_dw0_s5, mpc_dw0_rc5);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs5);
mpc_dw0_vsub_4(&mpc_dw0_nu5[4], mpc_dw0_s5, mpc_dw0_rs5);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y5, mpc_dw0_nu5, mpc_dw0_rk5);
/* Zeitschritt 6 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x6, mpc_dw0_rf0x6);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx6, mpc_dw0_x6, mpc_dw0_rf0x6);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu6, mpc_dw0_u6, mpc_dw0_rf0x6);
mpc_dw0_vsub_6(mpc_dw0_rf0x6, mpc_dw0_p6, mpc_dw0_rf0x6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_p7, mpc_dw0_rf0x6);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx6, mpc_dw0_y6, mpc_dw0_rf0x6);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u6, mpc_dw0_rf0u6);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu6, mpc_dw0_x6, mpc_dw0_rf0u6);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu6, mpc_dw0_u6, mpc_dw0_rf0u6);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu6, mpc_dw0_p7, mpc_dw0_rf0u6);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu6, mpc_dw0_y6, mpc_dw0_rf0u6);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s6, mpc_dw0_rf0s6);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss6, mpc_dw0_s6, mpc_dw0_rf0s6);
mpc_dw0_vsub_4(mpc_dw0_rf0s6, &mpc_dw0_y6[0], mpc_dw0_rf0s6);
mpc_dw0_vsub_4(mpc_dw0_rf0s6, &mpc_dw0_y6[4], mpc_dw0_rf0s6);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f5, mpc_dw0_rf6);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_x5, mpc_dw0_rf6);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu5, mpc_dw0_u5, mpc_dw0_rf6);
mpc_dw0_vsub_6(mpc_dw0_rf6, mpc_dw0_x6, mpc_dw0_rf6);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g6, mpc_dw0_rc6);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx6, mpc_dw0_x6, mpc_dw0_rc6);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu6, mpc_dw0_u6, mpc_dw0_rc6);
mpc_dw0_vadd_4(mpc_dw0_rc6, mpc_dw0_nu6, mpc_dw0_rc6);
mpc_dw0_vsub_4(mpc_dw0_rc6, mpc_dw0_s6, mpc_dw0_rc6);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs6);
mpc_dw0_vsub_4(&mpc_dw0_nu6[4], mpc_dw0_s6, mpc_dw0_rs6);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y6, mpc_dw0_nu6, mpc_dw0_rk6);
/* Zeitschritt 7 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x7, mpc_dw0_rf0x7);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx7, mpc_dw0_x7, mpc_dw0_rf0x7);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu7, mpc_dw0_u7, mpc_dw0_rf0x7);
mpc_dw0_vsub_6(mpc_dw0_rf0x7, mpc_dw0_p7, mpc_dw0_rf0x7);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_p8, mpc_dw0_rf0x7);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx7, mpc_dw0_y7, mpc_dw0_rf0x7);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u7, mpc_dw0_rf0u7);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu7, mpc_dw0_x7, mpc_dw0_rf0u7);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu7, mpc_dw0_u7, mpc_dw0_rf0u7);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu7, mpc_dw0_p8, mpc_dw0_rf0u7);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu7, mpc_dw0_y7, mpc_dw0_rf0u7);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s7, mpc_dw0_rf0s7);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss7, mpc_dw0_s7, mpc_dw0_rf0s7);
mpc_dw0_vsub_4(mpc_dw0_rf0s7, &mpc_dw0_y7[0], mpc_dw0_rf0s7);
mpc_dw0_vsub_4(mpc_dw0_rf0s7, &mpc_dw0_y7[4], mpc_dw0_rf0s7);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f6, mpc_dw0_rf7);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_x6, mpc_dw0_rf7);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu6, mpc_dw0_u6, mpc_dw0_rf7);
mpc_dw0_vsub_6(mpc_dw0_rf7, mpc_dw0_x7, mpc_dw0_rf7);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g7, mpc_dw0_rc7);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx7, mpc_dw0_x7, mpc_dw0_rc7);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu7, mpc_dw0_u7, mpc_dw0_rc7);
mpc_dw0_vadd_4(mpc_dw0_rc7, mpc_dw0_nu7, mpc_dw0_rc7);
mpc_dw0_vsub_4(mpc_dw0_rc7, mpc_dw0_s7, mpc_dw0_rc7);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs7);
mpc_dw0_vsub_4(&mpc_dw0_nu7[4], mpc_dw0_s7, mpc_dw0_rs7);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y7, mpc_dw0_nu7, mpc_dw0_rk7);
/* Zeitschritt 8 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x8, mpc_dw0_rf0x8);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx8, mpc_dw0_x8, mpc_dw0_rf0x8);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu8, mpc_dw0_u8, mpc_dw0_rf0x8);
mpc_dw0_vsub_6(mpc_dw0_rf0x8, mpc_dw0_p8, mpc_dw0_rf0x8);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_p9, mpc_dw0_rf0x8);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx8, mpc_dw0_y8, mpc_dw0_rf0x8);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u8, mpc_dw0_rf0u8);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu8, mpc_dw0_x8, mpc_dw0_rf0u8);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu8, mpc_dw0_u8, mpc_dw0_rf0u8);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu8, mpc_dw0_p9, mpc_dw0_rf0u8);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu8, mpc_dw0_y8, mpc_dw0_rf0u8);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s8, mpc_dw0_rf0s8);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss8, mpc_dw0_s8, mpc_dw0_rf0s8);
mpc_dw0_vsub_4(mpc_dw0_rf0s8, &mpc_dw0_y8[0], mpc_dw0_rf0s8);
mpc_dw0_vsub_4(mpc_dw0_rf0s8, &mpc_dw0_y8[4], mpc_dw0_rf0s8);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f7, mpc_dw0_rf8);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_x7, mpc_dw0_rf8);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu7, mpc_dw0_u7, mpc_dw0_rf8);
mpc_dw0_vsub_6(mpc_dw0_rf8, mpc_dw0_x8, mpc_dw0_rf8);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g8, mpc_dw0_rc8);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx8, mpc_dw0_x8, mpc_dw0_rc8);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu8, mpc_dw0_u8, mpc_dw0_rc8);
mpc_dw0_vadd_4(mpc_dw0_rc8, mpc_dw0_nu8, mpc_dw0_rc8);
mpc_dw0_vsub_4(mpc_dw0_rc8, mpc_dw0_s8, mpc_dw0_rc8);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs8);
mpc_dw0_vsub_4(&mpc_dw0_nu8[4], mpc_dw0_s8, mpc_dw0_rs8);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y8, mpc_dw0_nu8, mpc_dw0_rk8);
/* Zeitschritt 9 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x9, mpc_dw0_rf0x9);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx9, mpc_dw0_x9, mpc_dw0_rf0x9);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu9, mpc_dw0_u9, mpc_dw0_rf0x9);
mpc_dw0_vsub_6(mpc_dw0_rf0x9, mpc_dw0_p9, mpc_dw0_rf0x9);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_p10, mpc_dw0_rf0x9);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx9, mpc_dw0_y9, mpc_dw0_rf0x9);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u9, mpc_dw0_rf0u9);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu9, mpc_dw0_x9, mpc_dw0_rf0u9);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu9, mpc_dw0_u9, mpc_dw0_rf0u9);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu9, mpc_dw0_p10, mpc_dw0_rf0u9);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu9, mpc_dw0_y9, mpc_dw0_rf0u9);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s9, mpc_dw0_rf0s9);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss9, mpc_dw0_s9, mpc_dw0_rf0s9);
mpc_dw0_vsub_4(mpc_dw0_rf0s9, &mpc_dw0_y9[0], mpc_dw0_rf0s9);
mpc_dw0_vsub_4(mpc_dw0_rf0s9, &mpc_dw0_y9[4], mpc_dw0_rf0s9);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f8, mpc_dw0_rf9);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_x8, mpc_dw0_rf9);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu8, mpc_dw0_u8, mpc_dw0_rf9);
mpc_dw0_vsub_6(mpc_dw0_rf9, mpc_dw0_x9, mpc_dw0_rf9);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g9, mpc_dw0_rc9);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx9, mpc_dw0_x9, mpc_dw0_rc9);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu9, mpc_dw0_u9, mpc_dw0_rc9);
mpc_dw0_vadd_4(mpc_dw0_rc9, mpc_dw0_nu9, mpc_dw0_rc9);
mpc_dw0_vsub_4(mpc_dw0_rc9, mpc_dw0_s9, mpc_dw0_rc9);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs9);
mpc_dw0_vsub_4(&mpc_dw0_nu9[4], mpc_dw0_s9, mpc_dw0_rs9);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y9, mpc_dw0_nu9, mpc_dw0_rk9);
/* Zeitschritt 10 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x10, mpc_dw0_rf0x10);
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx10, mpc_dw0_x10, mpc_dw0_rf0x10);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu10, mpc_dw0_u10, mpc_dw0_rf0x10);
mpc_dw0_vsub_6(mpc_dw0_rf0x10, mpc_dw0_p10, mpc_dw0_rf0x10);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx10, mpc_dw0_p11, mpc_dw0_rf0x10);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx10, mpc_dw0_y10, mpc_dw0_rf0x10);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u10, mpc_dw0_rf0u10);
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu10, mpc_dw0_x10, mpc_dw0_rf0u10);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu10, mpc_dw0_u10, mpc_dw0_rf0u10);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu10, mpc_dw0_p11, mpc_dw0_rf0u10);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu10, mpc_dw0_y10, mpc_dw0_rf0u10);
/* rf0s */
mpc_dw0_v_copy_4(mpc_dw0_f0s10, mpc_dw0_rf0s10);
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss10, mpc_dw0_s10, mpc_dw0_rf0s10);
mpc_dw0_vsub_4(mpc_dw0_rf0s10, &mpc_dw0_y10[0], mpc_dw0_rf0s10);
mpc_dw0_vsub_4(mpc_dw0_rf0s10, &mpc_dw0_y10[4], mpc_dw0_rf0s10);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f9, mpc_dw0_rf10);
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_x9, mpc_dw0_rf10);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu9, mpc_dw0_u9, mpc_dw0_rf10);
mpc_dw0_vsub_6(mpc_dw0_rf10, mpc_dw0_x10, mpc_dw0_rf10);
/* rc */
mpc_dw0_v_copy_4(mpc_dw0_g10, mpc_dw0_rc10);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx10, mpc_dw0_x10, mpc_dw0_rc10);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu10, mpc_dw0_u10, mpc_dw0_rc10);
mpc_dw0_vadd_4(mpc_dw0_rc10, mpc_dw0_nu10, mpc_dw0_rc10);
mpc_dw0_vsub_4(mpc_dw0_rc10, mpc_dw0_s10, mpc_dw0_rc10);
/* rs */
mpc_dw0_v_init0_4(mpc_dw0_rs10);
mpc_dw0_vsub_4(&mpc_dw0_nu10[4], mpc_dw0_s10, mpc_dw0_rs10);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_y10, mpc_dw0_nu10, mpc_dw0_rk10);
/* Zeitschritt 11 */
/* rf0x */
mpc_dw0_v_copy_6(mpc_dw0_f0x11, mpc_dw0_rf0x11);
mpc_dw0_mv_sid23_sid2_6_6(mpc_dw0_Hxx11, mpc_dw0_x11, mpc_dw0_rf0x11);
mpc_dw0_mv_sid26_sid5_6_1(mpc_dw0_Hxu11, mpc_dw0_u11, mpc_dw0_rf0x11);
mpc_dw0_vsub_6(mpc_dw0_rf0x11, mpc_dw0_p11, mpc_dw0_rf0x11);
mpc_dw0_mtv_sid53_sid17_2_6(mpc_dw0_gx11, mpc_dw0_y11, mpc_dw0_rf0x11);
/* rf0u */
mpc_dw0_v_copy_1(mpc_dw0_f0u11, mpc_dw0_rf0u11);
mpc_dw0_mtv_sid26_sid2_6_1(mpc_dw0_Hxu11, mpc_dw0_x11, mpc_dw0_rf0u11);
mpc_dw0_mv_sid29_sid5_1_1(mpc_dw0_Huu11, mpc_dw0_u11, mpc_dw0_rf0u11);
mpc_dw0_mtv_sid56_sid17_2_1(mpc_dw0_gu11, mpc_dw0_y11, mpc_dw0_rf0u11);
/* rf0s */
mpc_dw0_v_copy_2(mpc_dw0_f0s11, mpc_dw0_rf0s11);
mpc_dw0_mv_sid32_sid20_2_2(mpc_dw0_Hss11, mpc_dw0_s11, mpc_dw0_rf0s11);
mpc_dw0_vsub_2(mpc_dw0_rf0s11, &mpc_dw0_y11[0], mpc_dw0_rf0s11);
mpc_dw0_vsub_2(mpc_dw0_rf0s11, &mpc_dw0_y11[2], mpc_dw0_rf0s11);
/* rf */
mpc_dw0_v_copy_6(mpc_dw0_f10, mpc_dw0_rf11);
mpc_dw0_mv_sid44_sid2_6_6(mpc_dw0_fx10, mpc_dw0_x10, mpc_dw0_rf11);
mpc_dw0_mv_sid47_sid5_6_1(mpc_dw0_fu10, mpc_dw0_u10, mpc_dw0_rf11);
mpc_dw0_vsub_6(mpc_dw0_rf11, mpc_dw0_x11, mpc_dw0_rf11);
/* rc */
mpc_dw0_v_copy_2(mpc_dw0_g11, mpc_dw0_rc11);
mpc_dw0_mv_sid53_sid2_2_6(mpc_dw0_gx11, mpc_dw0_x11, mpc_dw0_rc11);
mpc_dw0_mv_sid56_sid5_2_1(mpc_dw0_gu11, mpc_dw0_u11, mpc_dw0_rc11);
mpc_dw0_vadd_2(mpc_dw0_rc11, mpc_dw0_nu11, mpc_dw0_rc11);
mpc_dw0_vsub_2(mpc_dw0_rc11, mpc_dw0_s11, mpc_dw0_rc11);
/* rs */
mpc_dw0_v_init0_2(mpc_dw0_rs11);
mpc_dw0_vsub_2(&mpc_dw0_nu11[2], mpc_dw0_s11, mpc_dw0_rs11);
/* rk */
mpc_dw0_vv_elemult_4(mpc_dw0_y11, mpc_dw0_nu11, mpc_dw0_rk11);
}


static void mpc_dw0_glqdocpip_rhs_corrector()
{
/* Zeitschritt 0 */
/* rk_corr */
mpc_dw0_vv_elemult_4(mpc_dw0_dy0, mpc_dw0_dnu0, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_rk0, mpc_dw0_tmp1_4, mpc_dw0_rk0);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_4(mpc_dw0_tmp1_1, mpc_dw0_tmp1_4, mpc_dw0_tmp2_4);
mpc_dw0_vsub_4(mpc_dw0_rk0, mpc_dw0_tmp2_4, mpc_dw0_rk0);
/* Zeitschritt 1 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy1, mpc_dw0_dnu1, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk1, mpc_dw0_tmp1_8, mpc_dw0_rk1);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vsub_8(mpc_dw0_rk1, mpc_dw0_tmp2_8, mpc_dw0_rk1);
/* Zeitschritt 2 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy2, mpc_dw0_dnu2, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_rk2, mpc_dw0_tmp2_8, mpc_dw0_rk2);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vsub_8(mpc_dw0_rk2, mpc_dw0_tmp1_8, mpc_dw0_rk2);
/* Zeitschritt 3 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy3, mpc_dw0_dnu3, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk3, mpc_dw0_tmp1_8, mpc_dw0_rk3);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vsub_8(mpc_dw0_rk3, mpc_dw0_tmp2_8, mpc_dw0_rk3);
/* Zeitschritt 4 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy4, mpc_dw0_dnu4, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_rk4, mpc_dw0_tmp2_8, mpc_dw0_rk4);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vsub_8(mpc_dw0_rk4, mpc_dw0_tmp1_8, mpc_dw0_rk4);
/* Zeitschritt 5 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy5, mpc_dw0_dnu5, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk5, mpc_dw0_tmp1_8, mpc_dw0_rk5);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vsub_8(mpc_dw0_rk5, mpc_dw0_tmp2_8, mpc_dw0_rk5);
/* Zeitschritt 6 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy6, mpc_dw0_dnu6, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_rk6, mpc_dw0_tmp2_8, mpc_dw0_rk6);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vsub_8(mpc_dw0_rk6, mpc_dw0_tmp1_8, mpc_dw0_rk6);
/* Zeitschritt 7 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy7, mpc_dw0_dnu7, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk7, mpc_dw0_tmp1_8, mpc_dw0_rk7);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vsub_8(mpc_dw0_rk7, mpc_dw0_tmp2_8, mpc_dw0_rk7);
/* Zeitschritt 8 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy8, mpc_dw0_dnu8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_rk8, mpc_dw0_tmp2_8, mpc_dw0_rk8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vsub_8(mpc_dw0_rk8, mpc_dw0_tmp1_8, mpc_dw0_rk8);
/* Zeitschritt 9 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy9, mpc_dw0_dnu9, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk9, mpc_dw0_tmp1_8, mpc_dw0_rk9);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vsub_8(mpc_dw0_rk9, mpc_dw0_tmp2_8, mpc_dw0_rk9);
/* Zeitschritt 10 */
/* rk_corr */
mpc_dw0_vv_elemult_8(mpc_dw0_dy10, mpc_dw0_dnu10, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_rk10, mpc_dw0_tmp2_8, mpc_dw0_rk10);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_8(mpc_dw0_tmp1_1, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vsub_8(mpc_dw0_rk10, mpc_dw0_tmp1_8, mpc_dw0_rk10);
/* Zeitschritt 11 */
/* rk_corr */
mpc_dw0_vv_elemult_4(mpc_dw0_dy11, mpc_dw0_dnu11, mpc_dw0_tmp2_4);
mpc_dw0_vadd_4(mpc_dw0_rk11, mpc_dw0_tmp2_4, mpc_dw0_rk11);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4);
mpc_dw0_vv_elemult_1(mpc_dw0_sigma, mpc_dw0_mu, mpc_dw0_tmp1_1);
mpc_dw0_sv_4(mpc_dw0_tmp1_1, mpc_dw0_tmp2_4, mpc_dw0_tmp1_4);
mpc_dw0_vsub_4(mpc_dw0_rk11, mpc_dw0_tmp1_4, mpc_dw0_rk11);
}


static void mpc_dw0_glqdocpip_rhs_reduced()
{
mpc_dw0_error_source = 3;
/* Zeitschritt 0 */
/* rhsxs */
mpc_dw0_v_init0_2(mpc_dw0_rhsxs0);
mpc_dw0_vsub_2(mpc_dw0_rc0, mpc_dw0_rs0, mpc_dw0_rhsxs0);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk0[0], &mpc_dw0_y0[0], mpc_dw0_tmp1_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_2(mpc_dw0_rhsxs0, mpc_dw0_tmp1_2_1, mpc_dw0_rhsxs0);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk0[2], &mpc_dw0_y0[2], mpc_dw0_tmp1_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_rhsxs0, mpc_dw0_tmp1_2_1, mpc_dw0_rhsxs0);
mpc_dw0_v_init0_2(mpc_dw0_tmp2_2_1);
mpc_dw0_vsub_2(mpc_dw0_rs0, mpc_dw0_tmp1_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_v_copy_2(mpc_dw0_rf0s0, mpc_dw0_tmp1_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss0, mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp2_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss0, mpc_dw0_tmp2_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_y0[2], &mpc_dw0_nu0[2], mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_rhsxs0, mpc_dw0_tmp1_2_1, mpc_dw0_rhsxs0);
/* yny */
mpc_dw0_v_init0_2(mpc_dw0_yny0);
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp2_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss0, mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_y0[2], &mpc_dw0_nu0[2], mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp2_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_2(&mpc_dw0_nu0[0], &mpc_dw0_y0[0], mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1, &mpc_dw0_yny0[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_2(mpc_dw0_rhsxs0, mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_yny0, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x0, mpc_dw0_rrf0x0);
mpc_dw0_mtv_sid51_sid15_2_6(mpc_dw0_gx0, mpc_dw0_tmp2_2_1, mpc_dw0_rrf0x0);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u0, mpc_dw0_rrf0u0);
mpc_dw0_mtv_sid54_sid15_2_1(mpc_dw0_gu0, mpc_dw0_tmp2_2_1, mpc_dw0_rrf0u0);
/* Zeitschritt 1 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs1);
mpc_dw0_vsub_4(mpc_dw0_rc1, mpc_dw0_rs1, mpc_dw0_rhsxs1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk1[0], &mpc_dw0_y1[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs1, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk1[4], &mpc_dw0_y1[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs1, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s1, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y1[4], &mpc_dw0_nu1[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs1, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs1);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y1[4], &mpc_dw0_nu1[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu1[0], &mpc_dw0_y1[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, &mpc_dw0_yny1[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x1, mpc_dw0_rrf0x1);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx1, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0x1);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u1, mpc_dw0_rrf0u1);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu1, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0u1);
/* Zeitschritt 2 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs2);
mpc_dw0_vsub_4(mpc_dw0_rc2, mpc_dw0_rs2, mpc_dw0_rhsxs2);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk2[0], &mpc_dw0_y2[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs2, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs2);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk2[4], &mpc_dw0_y2[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs2, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs2);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs2, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s2, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss2, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss2, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y2[4], &mpc_dw0_nu2[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs2, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs2);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny2);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss2, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y2[4], &mpc_dw0_nu2[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu2[0], &mpc_dw0_y2[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_yny2[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs2, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny2, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x2, mpc_dw0_rrf0x2);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx2, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0x2);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u2, mpc_dw0_rrf0u2);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu2, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0u2);
/* Zeitschritt 3 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs3);
mpc_dw0_vsub_4(mpc_dw0_rc3, mpc_dw0_rs3, mpc_dw0_rhsxs3);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk3[0], &mpc_dw0_y3[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs3, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs3);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk3[4], &mpc_dw0_y3[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs3, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs3);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs3, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s3, mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss3, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss3, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y3[4], &mpc_dw0_nu3[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs3, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs3);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny3);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss3, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y3[4], &mpc_dw0_nu3[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu3[0], &mpc_dw0_y3[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, &mpc_dw0_yny3[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs3, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny3, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x3, mpc_dw0_rrf0x3);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx3, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0x3);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u3, mpc_dw0_rrf0u3);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu3, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0u3);
/* Zeitschritt 4 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs4);
mpc_dw0_vsub_4(mpc_dw0_rc4, mpc_dw0_rs4, mpc_dw0_rhsxs4);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk4[0], &mpc_dw0_y4[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs4, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs4);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk4[4], &mpc_dw0_y4[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs4, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs4);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs4, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s4, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss4, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss4, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y4[4], &mpc_dw0_nu4[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs4, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs4);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny4);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss4, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y4[4], &mpc_dw0_nu4[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu4[0], &mpc_dw0_y4[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, &mpc_dw0_yny4[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs4, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny4, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x4, mpc_dw0_rrf0x4);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx4, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0x4);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u4, mpc_dw0_rrf0u4);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu4, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0u4);
/* Zeitschritt 5 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs5);
mpc_dw0_vsub_4(mpc_dw0_rc5, mpc_dw0_rs5, mpc_dw0_rhsxs5);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk5[0], &mpc_dw0_y5[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs5, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs5);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk5[4], &mpc_dw0_y5[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs5, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs5);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs5, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s5, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss5, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss5, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y5[4], &mpc_dw0_nu5[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs5, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs5);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny5);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss5, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y5[4], &mpc_dw0_nu5[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu5[0], &mpc_dw0_y5[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_yny5[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs5, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny5, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x5, mpc_dw0_rrf0x5);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx5, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0x5);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u5, mpc_dw0_rrf0u5);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu5, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0u5);
/* Zeitschritt 6 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs6);
mpc_dw0_vsub_4(mpc_dw0_rc6, mpc_dw0_rs6, mpc_dw0_rhsxs6);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk6[0], &mpc_dw0_y6[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs6, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs6);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk6[4], &mpc_dw0_y6[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs6, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs6);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs6, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s6, mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss6, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss6, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y6[4], &mpc_dw0_nu6[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs6, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs6);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny6);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss6, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y6[4], &mpc_dw0_nu6[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu6[0], &mpc_dw0_y6[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, &mpc_dw0_yny6[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs6, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny6, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x6, mpc_dw0_rrf0x6);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx6, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0x6);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u6, mpc_dw0_rrf0u6);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu6, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0u6);
/* Zeitschritt 7 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs7);
mpc_dw0_vsub_4(mpc_dw0_rc7, mpc_dw0_rs7, mpc_dw0_rhsxs7);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk7[0], &mpc_dw0_y7[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs7, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs7);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk7[4], &mpc_dw0_y7[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs7, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs7);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs7, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s7, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss7, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss7, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y7[4], &mpc_dw0_nu7[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs7, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs7);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny7);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss7, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y7[4], &mpc_dw0_nu7[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu7[0], &mpc_dw0_y7[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, &mpc_dw0_yny7[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs7, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny7, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x7, mpc_dw0_rrf0x7);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx7, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0x7);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u7, mpc_dw0_rrf0u7);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu7, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0u7);
/* Zeitschritt 8 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs8);
mpc_dw0_vsub_4(mpc_dw0_rc8, mpc_dw0_rs8, mpc_dw0_rhsxs8);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk8[0], &mpc_dw0_y8[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs8, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs8);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk8[4], &mpc_dw0_y8[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs8, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs8);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs8, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s8, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss8, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss8, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y8[4], &mpc_dw0_nu8[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs8, mpc_dw0_tmp2_4_1, mpc_dw0_rhsxs8);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny8);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss8, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y8[4], &mpc_dw0_nu8[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu8[0], &mpc_dw0_y8[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_yny8[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs8, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny8, mpc_dw0_tmp3_4_1, mpc_dw0_tmp3_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x8, mpc_dw0_rrf0x8);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx8, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0x8);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u8, mpc_dw0_rrf0u8);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu8, mpc_dw0_tmp3_4_1, mpc_dw0_rrf0u8);
/* Zeitschritt 9 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs9);
mpc_dw0_vsub_4(mpc_dw0_rc9, mpc_dw0_rs9, mpc_dw0_rhsxs9);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk9[0], &mpc_dw0_y9[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs9, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs9);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk9[4], &mpc_dw0_y9[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs9, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs9);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs9, mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s9, mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss9, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss9, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y9[4], &mpc_dw0_nu9[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs9, mpc_dw0_tmp3_4_1, mpc_dw0_rhsxs9);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny9);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss9, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y9[4], &mpc_dw0_nu9[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu9[0], &mpc_dw0_y9[0], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1, &mpc_dw0_yny9[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs9, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny9, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x9, mpc_dw0_rrf0x9);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx9, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0x9);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u9, mpc_dw0_rrf0u9);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu9, mpc_dw0_tmp1_4_1, mpc_dw0_rrf0u9);
/* Zeitschritt 10 */
/* rhsxs */
mpc_dw0_v_init0_4(mpc_dw0_rhsxs10);
mpc_dw0_vsub_4(mpc_dw0_rc10, mpc_dw0_rs10, mpc_dw0_rhsxs10);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk10[0], &mpc_dw0_y10[0], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rhsxs10, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs10);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk10[4], &mpc_dw0_y10[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs10, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs10);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_rs10, mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s10, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss10, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss10, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y10[4], &mpc_dw0_nu10[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_rhsxs10, mpc_dw0_tmp1_4_1, mpc_dw0_rhsxs10);
/* yny */
mpc_dw0_v_init0_4(mpc_dw0_yny10);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss10, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_y10[4], &mpc_dw0_nu10[4], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_4(&mpc_dw0_nu10[0], &mpc_dw0_y10[0], mpc_dw0_tmp3_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, &mpc_dw0_yny10[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_4(mpc_dw0_rhsxs10, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny10, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x10, mpc_dw0_rrf0x10);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx10, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0x10);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u10, mpc_dw0_rrf0u10);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu10, mpc_dw0_tmp2_4_1, mpc_dw0_rrf0u10);
/* Zeitschritt 11 */
/* rhsxs */
mpc_dw0_v_init0_2(mpc_dw0_rhsxs11);
mpc_dw0_vsub_2(mpc_dw0_rc11, mpc_dw0_rs11, mpc_dw0_rhsxs11);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk11[0], &mpc_dw0_y11[0], mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_2(mpc_dw0_rhsxs11, mpc_dw0_tmp2_2_1, mpc_dw0_rhsxs11);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk11[2], &mpc_dw0_y11[2], mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_rhsxs11, mpc_dw0_tmp2_2_1, mpc_dw0_rhsxs11);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_vsub_2(mpc_dw0_rs11, mpc_dw0_tmp2_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_v_copy_2(mpc_dw0_rf0s11, mpc_dw0_tmp2_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss11, mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp1_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss11, mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_y11[2], &mpc_dw0_nu11[2], mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp2_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_rhsxs11, mpc_dw0_tmp2_2_1, mpc_dw0_rhsxs11);
/* yny */
mpc_dw0_v_init0_2(mpc_dw0_yny11);
mpc_dw0_v_init1_2(mpc_dw0_tmp1_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss11, mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_y11[2], &mpc_dw0_nu11[2], mpc_dw0_tmp1_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elediv_2(&mpc_dw0_nu11[0], &mpc_dw0_y11[0], mpc_dw0_tmp1_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vadd_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, &mpc_dw0_yny11[0]);
if(mpc_dw0_termcode > -1){return;}
/* v1 */
mpc_dw0_v_copy_2(mpc_dw0_rhsxs11, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_yny11, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
/* rrf0x */
mpc_dw0_v_copy_6(mpc_dw0_rf0x11, mpc_dw0_rrf0x11);
mpc_dw0_mtv_sid53_sid17_2_6(mpc_dw0_gx11, mpc_dw0_tmp3_2_1, mpc_dw0_rrf0x11);
/* rrf0u */
mpc_dw0_v_copy_1(mpc_dw0_rf0u11, mpc_dw0_rrf0u11);
mpc_dw0_mtv_sid56_sid17_2_1(mpc_dw0_gu11, mpc_dw0_tmp3_2_1, mpc_dw0_rrf0u11);
mpc_dw0_error_source = 0;
}


static void mpc_dw0_glqdocpip_rhs_iter_ref()
{
/* Zeitschritt 0 */
/* rf0x */
mpc_dw0_mv_sid21_sid2_6_6(mpc_dw0_Hxx0, mpc_dw0_dx0, mpc_dw0_rf0x0);
mpc_dw0_mv_sid24_sid5_6_1(mpc_dw0_Hxu0, mpc_dw0_du0, mpc_dw0_rf0x0);
mpc_dw0_vsub_6(mpc_dw0_rf0x0, mpc_dw0_dp0, mpc_dw0_rf0x0);
mpc_dw0_mtv_sid42_sid2_6_6(mpc_dw0_fx0, mpc_dw0_dp1, mpc_dw0_rf0x0);
mpc_dw0_mtv_sid51_sid15_2_6(mpc_dw0_gx0, mpc_dw0_dy0, mpc_dw0_rf0x0);
/* rf0u */
mpc_dw0_mtv_sid24_sid2_6_1(mpc_dw0_Hxu0, mpc_dw0_dx0, mpc_dw0_rf0u0);
mpc_dw0_mv_sid27_sid5_1_1(mpc_dw0_Huu0, mpc_dw0_du0, mpc_dw0_rf0u0);
mpc_dw0_mtv_sid45_sid2_6_1(mpc_dw0_fu0, mpc_dw0_dp1, mpc_dw0_rf0u0);
mpc_dw0_mtv_sid54_sid15_2_1(mpc_dw0_gu0, mpc_dw0_dy0, mpc_dw0_rf0u0);
/* rf0s */
mpc_dw0_mv_sid30_sid18_2_2(mpc_dw0_Hss0, mpc_dw0_ds0, mpc_dw0_rf0s0);
mpc_dw0_vsub_2(mpc_dw0_rf0s0, &mpc_dw0_dy0[0], mpc_dw0_rf0s0);
mpc_dw0_vsub_2(mpc_dw0_rf0s0, &mpc_dw0_dy0[2], mpc_dw0_rf0s0);
/* rf */
mpc_dw0_vsub_6(mpc_dw0_rf0, mpc_dw0_dx0, mpc_dw0_rf0);
/* rc */
mpc_dw0_mv_sid51_sid2_2_6(mpc_dw0_gx0, mpc_dw0_dx0, mpc_dw0_rc0);
mpc_dw0_mv_sid54_sid5_2_1(mpc_dw0_gu0, mpc_dw0_du0, mpc_dw0_rc0);
mpc_dw0_vadd_2(mpc_dw0_rc0, mpc_dw0_dnu0, mpc_dw0_rc0);
mpc_dw0_vsub_2(mpc_dw0_rc0, mpc_dw0_ds0, mpc_dw0_rc0);
/* rs */
mpc_dw0_vadd_2(mpc_dw0_rs0, &mpc_dw0_dnu0[2], mpc_dw0_rs0);
mpc_dw0_vsub_2(mpc_dw0_rs0, mpc_dw0_ds0, mpc_dw0_rs0);
/* rk */
mpc_dw0_vv_elemult_4(mpc_dw0_dy0, mpc_dw0_nu0, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_rk0, mpc_dw0_tmp1_4, mpc_dw0_rk0);
mpc_dw0_vv_elemult_4(mpc_dw0_dnu0, mpc_dw0_y0, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_rk0, mpc_dw0_tmp1_4, mpc_dw0_rk0);
/* Zeitschritt 1 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx1, mpc_dw0_dx1, mpc_dw0_rf0x1);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu1, mpc_dw0_du1, mpc_dw0_rf0x1);
mpc_dw0_vsub_6(mpc_dw0_rf0x1, mpc_dw0_dp1, mpc_dw0_rf0x1);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_dp2, mpc_dw0_rf0x1);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx1, mpc_dw0_dy1, mpc_dw0_rf0x1);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu1, mpc_dw0_dx1, mpc_dw0_rf0u1);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu1, mpc_dw0_du1, mpc_dw0_rf0u1);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu1, mpc_dw0_dp2, mpc_dw0_rf0u1);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu1, mpc_dw0_dy1, mpc_dw0_rf0u1);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss1, mpc_dw0_ds1, mpc_dw0_rf0s1);
mpc_dw0_vsub_4(mpc_dw0_rf0s1, &mpc_dw0_dy1[0], mpc_dw0_rf0s1);
mpc_dw0_vsub_4(mpc_dw0_rf0s1, &mpc_dw0_dy1[4], mpc_dw0_rf0s1);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx0, mpc_dw0_dx0, mpc_dw0_rf1);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu0, mpc_dw0_du0, mpc_dw0_rf1);
mpc_dw0_vsub_6(mpc_dw0_rf1, mpc_dw0_dx1, mpc_dw0_rf1);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx1, mpc_dw0_dx1, mpc_dw0_rc1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu1, mpc_dw0_du1, mpc_dw0_rc1);
mpc_dw0_vadd_4(mpc_dw0_rc1, mpc_dw0_dnu1, mpc_dw0_rc1);
mpc_dw0_vsub_4(mpc_dw0_rc1, mpc_dw0_ds1, mpc_dw0_rc1);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs1, &mpc_dw0_dnu1[4], mpc_dw0_rs1);
mpc_dw0_vsub_4(mpc_dw0_rs1, mpc_dw0_ds1, mpc_dw0_rs1);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy1, mpc_dw0_nu1, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk1, mpc_dw0_tmp1_8, mpc_dw0_rk1);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu1, mpc_dw0_y1, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk1, mpc_dw0_tmp1_8, mpc_dw0_rk1);
/* Zeitschritt 2 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx2, mpc_dw0_dx2, mpc_dw0_rf0x2);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu2, mpc_dw0_du2, mpc_dw0_rf0x2);
mpc_dw0_vsub_6(mpc_dw0_rf0x2, mpc_dw0_dp2, mpc_dw0_rf0x2);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_dp3, mpc_dw0_rf0x2);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx2, mpc_dw0_dy2, mpc_dw0_rf0x2);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu2, mpc_dw0_dx2, mpc_dw0_rf0u2);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu2, mpc_dw0_du2, mpc_dw0_rf0u2);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu2, mpc_dw0_dp3, mpc_dw0_rf0u2);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu2, mpc_dw0_dy2, mpc_dw0_rf0u2);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss2, mpc_dw0_ds2, mpc_dw0_rf0s2);
mpc_dw0_vsub_4(mpc_dw0_rf0s2, &mpc_dw0_dy2[0], mpc_dw0_rf0s2);
mpc_dw0_vsub_4(mpc_dw0_rf0s2, &mpc_dw0_dy2[4], mpc_dw0_rf0s2);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx1, mpc_dw0_dx1, mpc_dw0_rf2);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu1, mpc_dw0_du1, mpc_dw0_rf2);
mpc_dw0_vsub_6(mpc_dw0_rf2, mpc_dw0_dx2, mpc_dw0_rf2);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx2, mpc_dw0_dx2, mpc_dw0_rc2);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu2, mpc_dw0_du2, mpc_dw0_rc2);
mpc_dw0_vadd_4(mpc_dw0_rc2, mpc_dw0_dnu2, mpc_dw0_rc2);
mpc_dw0_vsub_4(mpc_dw0_rc2, mpc_dw0_ds2, mpc_dw0_rc2);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs2, &mpc_dw0_dnu2[4], mpc_dw0_rs2);
mpc_dw0_vsub_4(mpc_dw0_rs2, mpc_dw0_ds2, mpc_dw0_rs2);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy2, mpc_dw0_nu2, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk2, mpc_dw0_tmp1_8, mpc_dw0_rk2);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu2, mpc_dw0_y2, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk2, mpc_dw0_tmp1_8, mpc_dw0_rk2);
/* Zeitschritt 3 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx3, mpc_dw0_dx3, mpc_dw0_rf0x3);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu3, mpc_dw0_du3, mpc_dw0_rf0x3);
mpc_dw0_vsub_6(mpc_dw0_rf0x3, mpc_dw0_dp3, mpc_dw0_rf0x3);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_dp4, mpc_dw0_rf0x3);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx3, mpc_dw0_dy3, mpc_dw0_rf0x3);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu3, mpc_dw0_dx3, mpc_dw0_rf0u3);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu3, mpc_dw0_du3, mpc_dw0_rf0u3);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu3, mpc_dw0_dp4, mpc_dw0_rf0u3);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu3, mpc_dw0_dy3, mpc_dw0_rf0u3);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss3, mpc_dw0_ds3, mpc_dw0_rf0s3);
mpc_dw0_vsub_4(mpc_dw0_rf0s3, &mpc_dw0_dy3[0], mpc_dw0_rf0s3);
mpc_dw0_vsub_4(mpc_dw0_rf0s3, &mpc_dw0_dy3[4], mpc_dw0_rf0s3);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx2, mpc_dw0_dx2, mpc_dw0_rf3);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu2, mpc_dw0_du2, mpc_dw0_rf3);
mpc_dw0_vsub_6(mpc_dw0_rf3, mpc_dw0_dx3, mpc_dw0_rf3);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx3, mpc_dw0_dx3, mpc_dw0_rc3);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu3, mpc_dw0_du3, mpc_dw0_rc3);
mpc_dw0_vadd_4(mpc_dw0_rc3, mpc_dw0_dnu3, mpc_dw0_rc3);
mpc_dw0_vsub_4(mpc_dw0_rc3, mpc_dw0_ds3, mpc_dw0_rc3);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs3, &mpc_dw0_dnu3[4], mpc_dw0_rs3);
mpc_dw0_vsub_4(mpc_dw0_rs3, mpc_dw0_ds3, mpc_dw0_rs3);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy3, mpc_dw0_nu3, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk3, mpc_dw0_tmp1_8, mpc_dw0_rk3);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu3, mpc_dw0_y3, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk3, mpc_dw0_tmp1_8, mpc_dw0_rk3);
/* Zeitschritt 4 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx4, mpc_dw0_dx4, mpc_dw0_rf0x4);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu4, mpc_dw0_du4, mpc_dw0_rf0x4);
mpc_dw0_vsub_6(mpc_dw0_rf0x4, mpc_dw0_dp4, mpc_dw0_rf0x4);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_dp5, mpc_dw0_rf0x4);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx4, mpc_dw0_dy4, mpc_dw0_rf0x4);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu4, mpc_dw0_dx4, mpc_dw0_rf0u4);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu4, mpc_dw0_du4, mpc_dw0_rf0u4);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu4, mpc_dw0_dp5, mpc_dw0_rf0u4);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu4, mpc_dw0_dy4, mpc_dw0_rf0u4);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss4, mpc_dw0_ds4, mpc_dw0_rf0s4);
mpc_dw0_vsub_4(mpc_dw0_rf0s4, &mpc_dw0_dy4[0], mpc_dw0_rf0s4);
mpc_dw0_vsub_4(mpc_dw0_rf0s4, &mpc_dw0_dy4[4], mpc_dw0_rf0s4);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx3, mpc_dw0_dx3, mpc_dw0_rf4);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu3, mpc_dw0_du3, mpc_dw0_rf4);
mpc_dw0_vsub_6(mpc_dw0_rf4, mpc_dw0_dx4, mpc_dw0_rf4);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx4, mpc_dw0_dx4, mpc_dw0_rc4);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu4, mpc_dw0_du4, mpc_dw0_rc4);
mpc_dw0_vadd_4(mpc_dw0_rc4, mpc_dw0_dnu4, mpc_dw0_rc4);
mpc_dw0_vsub_4(mpc_dw0_rc4, mpc_dw0_ds4, mpc_dw0_rc4);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs4, &mpc_dw0_dnu4[4], mpc_dw0_rs4);
mpc_dw0_vsub_4(mpc_dw0_rs4, mpc_dw0_ds4, mpc_dw0_rs4);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy4, mpc_dw0_nu4, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk4, mpc_dw0_tmp1_8, mpc_dw0_rk4);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu4, mpc_dw0_y4, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk4, mpc_dw0_tmp1_8, mpc_dw0_rk4);
/* Zeitschritt 5 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx5, mpc_dw0_dx5, mpc_dw0_rf0x5);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu5, mpc_dw0_du5, mpc_dw0_rf0x5);
mpc_dw0_vsub_6(mpc_dw0_rf0x5, mpc_dw0_dp5, mpc_dw0_rf0x5);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_dp6, mpc_dw0_rf0x5);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx5, mpc_dw0_dy5, mpc_dw0_rf0x5);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu5, mpc_dw0_dx5, mpc_dw0_rf0u5);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu5, mpc_dw0_du5, mpc_dw0_rf0u5);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu5, mpc_dw0_dp6, mpc_dw0_rf0u5);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu5, mpc_dw0_dy5, mpc_dw0_rf0u5);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss5, mpc_dw0_ds5, mpc_dw0_rf0s5);
mpc_dw0_vsub_4(mpc_dw0_rf0s5, &mpc_dw0_dy5[0], mpc_dw0_rf0s5);
mpc_dw0_vsub_4(mpc_dw0_rf0s5, &mpc_dw0_dy5[4], mpc_dw0_rf0s5);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx4, mpc_dw0_dx4, mpc_dw0_rf5);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu4, mpc_dw0_du4, mpc_dw0_rf5);
mpc_dw0_vsub_6(mpc_dw0_rf5, mpc_dw0_dx5, mpc_dw0_rf5);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx5, mpc_dw0_dx5, mpc_dw0_rc5);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu5, mpc_dw0_du5, mpc_dw0_rc5);
mpc_dw0_vadd_4(mpc_dw0_rc5, mpc_dw0_dnu5, mpc_dw0_rc5);
mpc_dw0_vsub_4(mpc_dw0_rc5, mpc_dw0_ds5, mpc_dw0_rc5);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs5, &mpc_dw0_dnu5[4], mpc_dw0_rs5);
mpc_dw0_vsub_4(mpc_dw0_rs5, mpc_dw0_ds5, mpc_dw0_rs5);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy5, mpc_dw0_nu5, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk5, mpc_dw0_tmp1_8, mpc_dw0_rk5);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu5, mpc_dw0_y5, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk5, mpc_dw0_tmp1_8, mpc_dw0_rk5);
/* Zeitschritt 6 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx6, mpc_dw0_dx6, mpc_dw0_rf0x6);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu6, mpc_dw0_du6, mpc_dw0_rf0x6);
mpc_dw0_vsub_6(mpc_dw0_rf0x6, mpc_dw0_dp6, mpc_dw0_rf0x6);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_dp7, mpc_dw0_rf0x6);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx6, mpc_dw0_dy6, mpc_dw0_rf0x6);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu6, mpc_dw0_dx6, mpc_dw0_rf0u6);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu6, mpc_dw0_du6, mpc_dw0_rf0u6);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu6, mpc_dw0_dp7, mpc_dw0_rf0u6);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu6, mpc_dw0_dy6, mpc_dw0_rf0u6);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss6, mpc_dw0_ds6, mpc_dw0_rf0s6);
mpc_dw0_vsub_4(mpc_dw0_rf0s6, &mpc_dw0_dy6[0], mpc_dw0_rf0s6);
mpc_dw0_vsub_4(mpc_dw0_rf0s6, &mpc_dw0_dy6[4], mpc_dw0_rf0s6);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx5, mpc_dw0_dx5, mpc_dw0_rf6);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu5, mpc_dw0_du5, mpc_dw0_rf6);
mpc_dw0_vsub_6(mpc_dw0_rf6, mpc_dw0_dx6, mpc_dw0_rf6);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx6, mpc_dw0_dx6, mpc_dw0_rc6);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu6, mpc_dw0_du6, mpc_dw0_rc6);
mpc_dw0_vadd_4(mpc_dw0_rc6, mpc_dw0_dnu6, mpc_dw0_rc6);
mpc_dw0_vsub_4(mpc_dw0_rc6, mpc_dw0_ds6, mpc_dw0_rc6);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs6, &mpc_dw0_dnu6[4], mpc_dw0_rs6);
mpc_dw0_vsub_4(mpc_dw0_rs6, mpc_dw0_ds6, mpc_dw0_rs6);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy6, mpc_dw0_nu6, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk6, mpc_dw0_tmp1_8, mpc_dw0_rk6);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu6, mpc_dw0_y6, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk6, mpc_dw0_tmp1_8, mpc_dw0_rk6);
/* Zeitschritt 7 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx7, mpc_dw0_dx7, mpc_dw0_rf0x7);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu7, mpc_dw0_du7, mpc_dw0_rf0x7);
mpc_dw0_vsub_6(mpc_dw0_rf0x7, mpc_dw0_dp7, mpc_dw0_rf0x7);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_dp8, mpc_dw0_rf0x7);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx7, mpc_dw0_dy7, mpc_dw0_rf0x7);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu7, mpc_dw0_dx7, mpc_dw0_rf0u7);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu7, mpc_dw0_du7, mpc_dw0_rf0u7);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu7, mpc_dw0_dp8, mpc_dw0_rf0u7);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu7, mpc_dw0_dy7, mpc_dw0_rf0u7);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss7, mpc_dw0_ds7, mpc_dw0_rf0s7);
mpc_dw0_vsub_4(mpc_dw0_rf0s7, &mpc_dw0_dy7[0], mpc_dw0_rf0s7);
mpc_dw0_vsub_4(mpc_dw0_rf0s7, &mpc_dw0_dy7[4], mpc_dw0_rf0s7);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx6, mpc_dw0_dx6, mpc_dw0_rf7);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu6, mpc_dw0_du6, mpc_dw0_rf7);
mpc_dw0_vsub_6(mpc_dw0_rf7, mpc_dw0_dx7, mpc_dw0_rf7);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx7, mpc_dw0_dx7, mpc_dw0_rc7);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu7, mpc_dw0_du7, mpc_dw0_rc7);
mpc_dw0_vadd_4(mpc_dw0_rc7, mpc_dw0_dnu7, mpc_dw0_rc7);
mpc_dw0_vsub_4(mpc_dw0_rc7, mpc_dw0_ds7, mpc_dw0_rc7);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs7, &mpc_dw0_dnu7[4], mpc_dw0_rs7);
mpc_dw0_vsub_4(mpc_dw0_rs7, mpc_dw0_ds7, mpc_dw0_rs7);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy7, mpc_dw0_nu7, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk7, mpc_dw0_tmp1_8, mpc_dw0_rk7);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu7, mpc_dw0_y7, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk7, mpc_dw0_tmp1_8, mpc_dw0_rk7);
/* Zeitschritt 8 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx8, mpc_dw0_dx8, mpc_dw0_rf0x8);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu8, mpc_dw0_du8, mpc_dw0_rf0x8);
mpc_dw0_vsub_6(mpc_dw0_rf0x8, mpc_dw0_dp8, mpc_dw0_rf0x8);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_dp9, mpc_dw0_rf0x8);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx8, mpc_dw0_dy8, mpc_dw0_rf0x8);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu8, mpc_dw0_dx8, mpc_dw0_rf0u8);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu8, mpc_dw0_du8, mpc_dw0_rf0u8);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu8, mpc_dw0_dp9, mpc_dw0_rf0u8);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu8, mpc_dw0_dy8, mpc_dw0_rf0u8);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss8, mpc_dw0_ds8, mpc_dw0_rf0s8);
mpc_dw0_vsub_4(mpc_dw0_rf0s8, &mpc_dw0_dy8[0], mpc_dw0_rf0s8);
mpc_dw0_vsub_4(mpc_dw0_rf0s8, &mpc_dw0_dy8[4], mpc_dw0_rf0s8);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx7, mpc_dw0_dx7, mpc_dw0_rf8);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu7, mpc_dw0_du7, mpc_dw0_rf8);
mpc_dw0_vsub_6(mpc_dw0_rf8, mpc_dw0_dx8, mpc_dw0_rf8);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx8, mpc_dw0_dx8, mpc_dw0_rc8);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu8, mpc_dw0_du8, mpc_dw0_rc8);
mpc_dw0_vadd_4(mpc_dw0_rc8, mpc_dw0_dnu8, mpc_dw0_rc8);
mpc_dw0_vsub_4(mpc_dw0_rc8, mpc_dw0_ds8, mpc_dw0_rc8);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs8, &mpc_dw0_dnu8[4], mpc_dw0_rs8);
mpc_dw0_vsub_4(mpc_dw0_rs8, mpc_dw0_ds8, mpc_dw0_rs8);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy8, mpc_dw0_nu8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk8, mpc_dw0_tmp1_8, mpc_dw0_rk8);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu8, mpc_dw0_y8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk8, mpc_dw0_tmp1_8, mpc_dw0_rk8);
/* Zeitschritt 9 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx9, mpc_dw0_dx9, mpc_dw0_rf0x9);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu9, mpc_dw0_du9, mpc_dw0_rf0x9);
mpc_dw0_vsub_6(mpc_dw0_rf0x9, mpc_dw0_dp9, mpc_dw0_rf0x9);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_dp10, mpc_dw0_rf0x9);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx9, mpc_dw0_dy9, mpc_dw0_rf0x9);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu9, mpc_dw0_dx9, mpc_dw0_rf0u9);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu9, mpc_dw0_du9, mpc_dw0_rf0u9);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu9, mpc_dw0_dp10, mpc_dw0_rf0u9);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu9, mpc_dw0_dy9, mpc_dw0_rf0u9);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss9, mpc_dw0_ds9, mpc_dw0_rf0s9);
mpc_dw0_vsub_4(mpc_dw0_rf0s9, &mpc_dw0_dy9[0], mpc_dw0_rf0s9);
mpc_dw0_vsub_4(mpc_dw0_rf0s9, &mpc_dw0_dy9[4], mpc_dw0_rf0s9);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx8, mpc_dw0_dx8, mpc_dw0_rf9);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu8, mpc_dw0_du8, mpc_dw0_rf9);
mpc_dw0_vsub_6(mpc_dw0_rf9, mpc_dw0_dx9, mpc_dw0_rf9);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx9, mpc_dw0_dx9, mpc_dw0_rc9);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu9, mpc_dw0_du9, mpc_dw0_rc9);
mpc_dw0_vadd_4(mpc_dw0_rc9, mpc_dw0_dnu9, mpc_dw0_rc9);
mpc_dw0_vsub_4(mpc_dw0_rc9, mpc_dw0_ds9, mpc_dw0_rc9);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs9, &mpc_dw0_dnu9[4], mpc_dw0_rs9);
mpc_dw0_vsub_4(mpc_dw0_rs9, mpc_dw0_ds9, mpc_dw0_rs9);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy9, mpc_dw0_nu9, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk9, mpc_dw0_tmp1_8, mpc_dw0_rk9);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu9, mpc_dw0_y9, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk9, mpc_dw0_tmp1_8, mpc_dw0_rk9);
/* Zeitschritt 10 */
/* rf0x */
mpc_dw0_mv_sid22_sid2_6_6(mpc_dw0_Hxx10, mpc_dw0_dx10, mpc_dw0_rf0x10);
mpc_dw0_mv_sid25_sid5_6_1(mpc_dw0_Hxu10, mpc_dw0_du10, mpc_dw0_rf0x10);
mpc_dw0_vsub_6(mpc_dw0_rf0x10, mpc_dw0_dp10, mpc_dw0_rf0x10);
mpc_dw0_mtv_sid43_sid2_6_6(mpc_dw0_fx10, mpc_dw0_dp11, mpc_dw0_rf0x10);
mpc_dw0_mtv_sid52_sid16_4_6(mpc_dw0_gx10, mpc_dw0_dy10, mpc_dw0_rf0x10);
/* rf0u */
mpc_dw0_mtv_sid25_sid2_6_1(mpc_dw0_Hxu10, mpc_dw0_dx10, mpc_dw0_rf0u10);
mpc_dw0_mv_sid28_sid5_1_1(mpc_dw0_Huu10, mpc_dw0_du10, mpc_dw0_rf0u10);
mpc_dw0_mtv_sid46_sid2_6_1(mpc_dw0_fu10, mpc_dw0_dp11, mpc_dw0_rf0u10);
mpc_dw0_mtv_sid55_sid16_4_1(mpc_dw0_gu10, mpc_dw0_dy10, mpc_dw0_rf0u10);
/* rf0s */
mpc_dw0_mv_sid31_sid19_4_4(mpc_dw0_Hss10, mpc_dw0_ds10, mpc_dw0_rf0s10);
mpc_dw0_vsub_4(mpc_dw0_rf0s10, &mpc_dw0_dy10[0], mpc_dw0_rf0s10);
mpc_dw0_vsub_4(mpc_dw0_rf0s10, &mpc_dw0_dy10[4], mpc_dw0_rf0s10);
/* rf */
mpc_dw0_mv_sid43_sid2_6_6(mpc_dw0_fx9, mpc_dw0_dx9, mpc_dw0_rf10);
mpc_dw0_mv_sid46_sid5_6_1(mpc_dw0_fu9, mpc_dw0_du9, mpc_dw0_rf10);
mpc_dw0_vsub_6(mpc_dw0_rf10, mpc_dw0_dx10, mpc_dw0_rf10);
/* rc */
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx10, mpc_dw0_dx10, mpc_dw0_rc10);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu10, mpc_dw0_du10, mpc_dw0_rc10);
mpc_dw0_vadd_4(mpc_dw0_rc10, mpc_dw0_dnu10, mpc_dw0_rc10);
mpc_dw0_vsub_4(mpc_dw0_rc10, mpc_dw0_ds10, mpc_dw0_rc10);
/* rs */
mpc_dw0_vadd_4(mpc_dw0_rs10, &mpc_dw0_dnu10[4], mpc_dw0_rs10);
mpc_dw0_vsub_4(mpc_dw0_rs10, mpc_dw0_ds10, mpc_dw0_rs10);
/* rk */
mpc_dw0_vv_elemult_8(mpc_dw0_dy10, mpc_dw0_nu10, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk10, mpc_dw0_tmp1_8, mpc_dw0_rk10);
mpc_dw0_vv_elemult_8(mpc_dw0_dnu10, mpc_dw0_y10, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_rk10, mpc_dw0_tmp1_8, mpc_dw0_rk10);
/* Zeitschritt 11 */
/* rf0x */
mpc_dw0_mv_sid23_sid2_6_6(mpc_dw0_Hxx11, mpc_dw0_dx11, mpc_dw0_rf0x11);
mpc_dw0_mv_sid26_sid5_6_1(mpc_dw0_Hxu11, mpc_dw0_du11, mpc_dw0_rf0x11);
mpc_dw0_vsub_6(mpc_dw0_rf0x11, mpc_dw0_dp11, mpc_dw0_rf0x11);
mpc_dw0_mtv_sid53_sid17_2_6(mpc_dw0_gx11, mpc_dw0_dy11, mpc_dw0_rf0x11);
/* rf0u */
mpc_dw0_mtv_sid26_sid2_6_1(mpc_dw0_Hxu11, mpc_dw0_dx11, mpc_dw0_rf0u11);
mpc_dw0_mv_sid29_sid5_1_1(mpc_dw0_Huu11, mpc_dw0_du11, mpc_dw0_rf0u11);
mpc_dw0_mtv_sid56_sid17_2_1(mpc_dw0_gu11, mpc_dw0_dy11, mpc_dw0_rf0u11);
/* rf0s */
mpc_dw0_mv_sid32_sid20_2_2(mpc_dw0_Hss11, mpc_dw0_ds11, mpc_dw0_rf0s11);
mpc_dw0_vsub_2(mpc_dw0_rf0s11, &mpc_dw0_dy11[0], mpc_dw0_rf0s11);
mpc_dw0_vsub_2(mpc_dw0_rf0s11, &mpc_dw0_dy11[2], mpc_dw0_rf0s11);
/* rf */
mpc_dw0_mv_sid44_sid2_6_6(mpc_dw0_fx10, mpc_dw0_dx10, mpc_dw0_rf11);
mpc_dw0_mv_sid47_sid5_6_1(mpc_dw0_fu10, mpc_dw0_du10, mpc_dw0_rf11);
mpc_dw0_vsub_6(mpc_dw0_rf11, mpc_dw0_dx11, mpc_dw0_rf11);
/* rc */
mpc_dw0_mv_sid53_sid2_2_6(mpc_dw0_gx11, mpc_dw0_dx11, mpc_dw0_rc11);
mpc_dw0_mv_sid56_sid5_2_1(mpc_dw0_gu11, mpc_dw0_du11, mpc_dw0_rc11);
mpc_dw0_vadd_2(mpc_dw0_rc11, mpc_dw0_dnu11, mpc_dw0_rc11);
mpc_dw0_vsub_2(mpc_dw0_rc11, mpc_dw0_ds11, mpc_dw0_rc11);
/* rs */
mpc_dw0_vadd_2(mpc_dw0_rs11, &mpc_dw0_dnu11[2], mpc_dw0_rs11);
mpc_dw0_vsub_2(mpc_dw0_rs11, mpc_dw0_ds11, mpc_dw0_rs11);
/* rk */
mpc_dw0_vv_elemult_4(mpc_dw0_dy11, mpc_dw0_nu11, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_rk11, mpc_dw0_tmp1_4, mpc_dw0_rk11);
mpc_dw0_vv_elemult_4(mpc_dw0_dnu11, mpc_dw0_y11, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_rk11, mpc_dw0_tmp1_4, mpc_dw0_rk11);
}


static void mpc_dw0_glqdocpip_dereduce()
{
mpc_dw0_error_source = 4;
/* Zeitschritt 0 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_m_copy_2_1(mpc_dw0_rhsxs0, mpc_dw0_tmp3_2_1);
mpc_dw0_mv_sid51_sid2_2_6(mpc_dw0_gx0, mpc_dw0_dx0, mpc_dw0_tmp3_2_1);
mpc_dw0_mv_sid54_sid5_2_1(mpc_dw0_gu0, mpc_dw0_du0, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_yny0, mpc_dw0_tmp3_2_1, mpc_dw0_dy0);
/* dy_ss */
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp1_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss0, mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk0[2], &mpc_dw0_y0[2], mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_2(mpc_dw0_rs0, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp3_2_1);
mpc_dw0_vadd_2(mpc_dw0_tmp3_2_1, mpc_dw0_rf0s0, mpc_dw0_tmp3_2_1);
mpc_dw0_vsub_2(mpc_dw0_tmp3_2_1, mpc_dw0_dy0, mpc_dw0_tmp3_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_nu0[2], &mpc_dw0_y0[2], mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp2_2_1);
mpc_dw0_vadd_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1, &mpc_dw0_dy0[2]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_4(mpc_dw0_nu0, mpc_dw0_dy0, mpc_dw0_dnu0);
mpc_dw0_vadd_4(mpc_dw0_dnu0, mpc_dw0_rk0, mpc_dw0_dnu0);
mpc_dw0_vv_elediv_4(mpc_dw0_dnu0, mpc_dw0_y0, mpc_dw0_dnu0);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_4(mpc_dw0_dnu0, mpc_dw0_dnu0);
/* ds */
mpc_dw0_v_init0_2(mpc_dw0_ds0);
mpc_dw0_vadd_2(mpc_dw0_rs0, &mpc_dw0_dnu0[2], mpc_dw0_ds0);
/* Zeitschritt 1 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs1, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx1, mpc_dw0_dx1, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu1, mpc_dw0_du1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny1, mpc_dw0_tmp2_4_1, mpc_dw0_dy1);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk1[4], &mpc_dw0_y1[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_rf0s1, mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp2_4_1, mpc_dw0_dy1, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu1[4], &mpc_dw0_y1[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy1[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu1, mpc_dw0_dy1, mpc_dw0_dnu1);
mpc_dw0_vadd_8(mpc_dw0_dnu1, mpc_dw0_rk1, mpc_dw0_dnu1);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu1, mpc_dw0_y1, mpc_dw0_dnu1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu1, mpc_dw0_dnu1);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds1);
mpc_dw0_vadd_4(mpc_dw0_rs1, &mpc_dw0_dnu1[4], mpc_dw0_ds1);
/* Zeitschritt 2 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs2, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx2, mpc_dw0_dx2, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu2, mpc_dw0_du2, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny2, mpc_dw0_tmp1_4_1, mpc_dw0_dy2);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss2, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk2[4], &mpc_dw0_y2[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs2, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_rf0s2, mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp1_4_1, mpc_dw0_dy2, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu2[4], &mpc_dw0_y2[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy2[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu2, mpc_dw0_dy2, mpc_dw0_dnu2);
mpc_dw0_vadd_8(mpc_dw0_dnu2, mpc_dw0_rk2, mpc_dw0_dnu2);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu2, mpc_dw0_y2, mpc_dw0_dnu2);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu2, mpc_dw0_dnu2);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds2);
mpc_dw0_vadd_4(mpc_dw0_rs2, &mpc_dw0_dnu2[4], mpc_dw0_ds2);
/* Zeitschritt 3 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs3, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx3, mpc_dw0_dx3, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu3, mpc_dw0_du3, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny3, mpc_dw0_tmp2_4_1, mpc_dw0_dy3);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss3, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk3[4], &mpc_dw0_y3[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs3, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_rf0s3, mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp2_4_1, mpc_dw0_dy3, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu3[4], &mpc_dw0_y3[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy3[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu3, mpc_dw0_dy3, mpc_dw0_dnu3);
mpc_dw0_vadd_8(mpc_dw0_dnu3, mpc_dw0_rk3, mpc_dw0_dnu3);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu3, mpc_dw0_y3, mpc_dw0_dnu3);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu3, mpc_dw0_dnu3);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds3);
mpc_dw0_vadd_4(mpc_dw0_rs3, &mpc_dw0_dnu3[4], mpc_dw0_ds3);
/* Zeitschritt 4 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs4, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx4, mpc_dw0_dx4, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu4, mpc_dw0_du4, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny4, mpc_dw0_tmp1_4_1, mpc_dw0_dy4);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss4, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk4[4], &mpc_dw0_y4[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs4, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_rf0s4, mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp1_4_1, mpc_dw0_dy4, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu4[4], &mpc_dw0_y4[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy4[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu4, mpc_dw0_dy4, mpc_dw0_dnu4);
mpc_dw0_vadd_8(mpc_dw0_dnu4, mpc_dw0_rk4, mpc_dw0_dnu4);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu4, mpc_dw0_y4, mpc_dw0_dnu4);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu4, mpc_dw0_dnu4);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds4);
mpc_dw0_vadd_4(mpc_dw0_rs4, &mpc_dw0_dnu4[4], mpc_dw0_ds4);
/* Zeitschritt 5 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs5, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx5, mpc_dw0_dx5, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu5, mpc_dw0_du5, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny5, mpc_dw0_tmp2_4_1, mpc_dw0_dy5);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss5, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk5[4], &mpc_dw0_y5[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs5, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_rf0s5, mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp2_4_1, mpc_dw0_dy5, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu5[4], &mpc_dw0_y5[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy5[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu5, mpc_dw0_dy5, mpc_dw0_dnu5);
mpc_dw0_vadd_8(mpc_dw0_dnu5, mpc_dw0_rk5, mpc_dw0_dnu5);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu5, mpc_dw0_y5, mpc_dw0_dnu5);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu5, mpc_dw0_dnu5);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds5);
mpc_dw0_vadd_4(mpc_dw0_rs5, &mpc_dw0_dnu5[4], mpc_dw0_ds5);
/* Zeitschritt 6 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs6, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx6, mpc_dw0_dx6, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu6, mpc_dw0_du6, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny6, mpc_dw0_tmp1_4_1, mpc_dw0_dy6);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss6, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk6[4], &mpc_dw0_y6[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs6, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_rf0s6, mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp1_4_1, mpc_dw0_dy6, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu6[4], &mpc_dw0_y6[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy6[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu6, mpc_dw0_dy6, mpc_dw0_dnu6);
mpc_dw0_vadd_8(mpc_dw0_dnu6, mpc_dw0_rk6, mpc_dw0_dnu6);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu6, mpc_dw0_y6, mpc_dw0_dnu6);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu6, mpc_dw0_dnu6);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds6);
mpc_dw0_vadd_4(mpc_dw0_rs6, &mpc_dw0_dnu6[4], mpc_dw0_ds6);
/* Zeitschritt 7 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs7, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx7, mpc_dw0_dx7, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu7, mpc_dw0_du7, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny7, mpc_dw0_tmp2_4_1, mpc_dw0_dy7);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss7, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk7[4], &mpc_dw0_y7[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs7, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_rf0s7, mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp2_4_1, mpc_dw0_dy7, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu7[4], &mpc_dw0_y7[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy7[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu7, mpc_dw0_dy7, mpc_dw0_dnu7);
mpc_dw0_vadd_8(mpc_dw0_dnu7, mpc_dw0_rk7, mpc_dw0_dnu7);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu7, mpc_dw0_y7, mpc_dw0_dnu7);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu7, mpc_dw0_dnu7);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds7);
mpc_dw0_vadd_4(mpc_dw0_rs7, &mpc_dw0_dnu7[4], mpc_dw0_ds7);
/* Zeitschritt 8 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs8, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx8, mpc_dw0_dx8, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu8, mpc_dw0_du8, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny8, mpc_dw0_tmp1_4_1, mpc_dw0_dy8);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss8, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk8[4], &mpc_dw0_y8[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs8, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_rf0s8, mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp1_4_1, mpc_dw0_dy8, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu8[4], &mpc_dw0_y8[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy8[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu8, mpc_dw0_dy8, mpc_dw0_dnu8);
mpc_dw0_vadd_8(mpc_dw0_dnu8, mpc_dw0_rk8, mpc_dw0_dnu8);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu8, mpc_dw0_y8, mpc_dw0_dnu8);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu8, mpc_dw0_dnu8);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds8);
mpc_dw0_vadd_4(mpc_dw0_rs8, &mpc_dw0_dnu8[4], mpc_dw0_ds8);
/* Zeitschritt 9 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs9, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx9, mpc_dw0_dx9, mpc_dw0_tmp2_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu9, mpc_dw0_du9, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny9, mpc_dw0_tmp2_4_1, mpc_dw0_dy9);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss9, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk9[4], &mpc_dw0_y9[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs9, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp2_4_1, mpc_dw0_rf0s9, mpc_dw0_tmp2_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp2_4_1, mpc_dw0_dy9, mpc_dw0_tmp2_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu9[4], &mpc_dw0_y9[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy9[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu9, mpc_dw0_dy9, mpc_dw0_dnu9);
mpc_dw0_vadd_8(mpc_dw0_dnu9, mpc_dw0_rk9, mpc_dw0_dnu9);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu9, mpc_dw0_y9, mpc_dw0_dnu9);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu9, mpc_dw0_dnu9);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds9);
mpc_dw0_vadd_4(mpc_dw0_rs9, &mpc_dw0_dnu9[4], mpc_dw0_ds9);
/* Zeitschritt 10 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4_1);
mpc_dw0_m_copy_4_1(mpc_dw0_rhsxs10, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid52_sid2_4_6(mpc_dw0_gx10, mpc_dw0_dx10, mpc_dw0_tmp1_4_1);
mpc_dw0_mv_sid55_sid5_4_1(mpc_dw0_gu10, mpc_dw0_du10, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_yny10, mpc_dw0_tmp1_4_1, mpc_dw0_dy10);
/* dy_ss */
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp3_4_1);
mpc_dw0_mv_4_4(mpc_dw0_Hss10, mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_rk10[4], &mpc_dw0_y10[4], mpc_dw0_tmp1_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_4(mpc_dw0_rs10, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp1_4_1, mpc_dw0_tmp1_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp1_4_1, mpc_dw0_rf0s10, mpc_dw0_tmp1_4_1);
mpc_dw0_vsub_4(mpc_dw0_tmp1_4_1, mpc_dw0_dy10, mpc_dw0_tmp1_4_1);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vv_elediv_4(&mpc_dw0_nu10[4], &mpc_dw0_y10[4], mpc_dw0_tmp2_4_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4_1);
mpc_dw0_vadd_4(mpc_dw0_tmp3_4_1, mpc_dw0_tmp2_4_1, mpc_dw0_tmp3_4_1);
mpc_dw0_vv_elediv_4(mpc_dw0_tmp1_4_1, mpc_dw0_tmp3_4_1, &mpc_dw0_dy10[4]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_8(mpc_dw0_nu10, mpc_dw0_dy10, mpc_dw0_dnu10);
mpc_dw0_vadd_8(mpc_dw0_dnu10, mpc_dw0_rk10, mpc_dw0_dnu10);
mpc_dw0_vv_elediv_8(mpc_dw0_dnu10, mpc_dw0_y10, mpc_dw0_dnu10);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_8(mpc_dw0_dnu10, mpc_dw0_dnu10);
/* ds */
mpc_dw0_v_init0_4(mpc_dw0_ds10);
mpc_dw0_vadd_4(mpc_dw0_rs10, &mpc_dw0_dnu10[4], mpc_dw0_ds10);
/* Zeitschritt 11 */
/* dy */
/* Hilfsvektor */
mpc_dw0_v_init0_2(mpc_dw0_tmp2_2_1);
mpc_dw0_m_copy_2_1(mpc_dw0_rhsxs11, mpc_dw0_tmp2_2_1);
mpc_dw0_mv_sid53_sid2_2_6(mpc_dw0_gx11, mpc_dw0_dx11, mpc_dw0_tmp2_2_1);
mpc_dw0_mv_sid56_sid5_2_1(mpc_dw0_gu11, mpc_dw0_du11, mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_yny11, mpc_dw0_tmp2_2_1, mpc_dw0_dy11);
/* dy_ss */
mpc_dw0_v_init1_2(mpc_dw0_tmp2_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp1_2_1);
mpc_dw0_mv_2_2(mpc_dw0_Hss11, mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_rk11[2], &mpc_dw0_y11[2], mpc_dw0_tmp2_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vsub_2(mpc_dw0_rs11, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_vv_elemult_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp2_2_1, mpc_dw0_tmp2_2_1);
mpc_dw0_vadd_2(mpc_dw0_tmp2_2_1, mpc_dw0_rf0s11, mpc_dw0_tmp2_2_1);
mpc_dw0_vsub_2(mpc_dw0_tmp2_2_1, mpc_dw0_dy11, mpc_dw0_tmp2_2_1);
mpc_dw0_v_init0_2(mpc_dw0_tmp3_2_1);
mpc_dw0_vv_elediv_2(&mpc_dw0_nu11[2], &mpc_dw0_y11[2], mpc_dw0_tmp3_2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_v_init1_2(mpc_dw0_tmp3_2_1);
mpc_dw0_vadd_2(mpc_dw0_tmp1_2_1, mpc_dw0_tmp3_2_1, mpc_dw0_tmp1_2_1);
mpc_dw0_vv_elediv_2(mpc_dw0_tmp2_2_1, mpc_dw0_tmp1_2_1, &mpc_dw0_dy11[2]);
if(mpc_dw0_termcode > -1){return;}
/* dnu */
mpc_dw0_vv_elemult_4(mpc_dw0_nu11, mpc_dw0_dy11, mpc_dw0_dnu11);
mpc_dw0_vadd_4(mpc_dw0_dnu11, mpc_dw0_rk11, mpc_dw0_dnu11);
mpc_dw0_vv_elediv_4(mpc_dw0_dnu11, mpc_dw0_y11, mpc_dw0_dnu11);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_turnsign_4(mpc_dw0_dnu11, mpc_dw0_dnu11);
/* ds */
mpc_dw0_v_init0_2(mpc_dw0_ds11);
mpc_dw0_vadd_2(mpc_dw0_rs11, &mpc_dw0_dnu11[2], mpc_dw0_ds11);
mpc_dw0_error_source = 0;

}


/* ###################################################### */
/* Diese Funktion berechnet führt die Nachiteration durch */
/* ###################################################### */
static void mpc_dw0_glqdocpip_iter_ref()
{
if(mpc_dw0_iter_ref == 1){
mpc_dw0_stat_num_iter_ref++;
mpc_dw0_stat_iter_ref[mpc_dw0_iter] = 1;
/* Lösung sichern */
mpc_dw0_v_copy_6(mpc_dw0_dx0, mpc_dw0_dx_ir0);
mpc_dw0_v_copy_1(mpc_dw0_du0, mpc_dw0_du_ir0);
mpc_dw0_v_copy_2(mpc_dw0_ds0, mpc_dw0_ds_ir0);
mpc_dw0_v_copy_6(mpc_dw0_dp0, mpc_dw0_dp_ir0);
mpc_dw0_v_copy_4(mpc_dw0_dy0, mpc_dw0_dy_ir0);
mpc_dw0_v_copy_4(mpc_dw0_dnu0, mpc_dw0_dnu_ir0);
mpc_dw0_v_copy_6(mpc_dw0_dx1, mpc_dw0_dx_ir1);
mpc_dw0_v_copy_1(mpc_dw0_du1, mpc_dw0_du_ir1);
mpc_dw0_v_copy_4(mpc_dw0_ds1, mpc_dw0_ds_ir1);
mpc_dw0_v_copy_6(mpc_dw0_dp1, mpc_dw0_dp_ir1);
mpc_dw0_v_copy_8(mpc_dw0_dy1, mpc_dw0_dy_ir1);
mpc_dw0_v_copy_8(mpc_dw0_dnu1, mpc_dw0_dnu_ir1);
mpc_dw0_v_copy_6(mpc_dw0_dx2, mpc_dw0_dx_ir2);
mpc_dw0_v_copy_1(mpc_dw0_du2, mpc_dw0_du_ir2);
mpc_dw0_v_copy_4(mpc_dw0_ds2, mpc_dw0_ds_ir2);
mpc_dw0_v_copy_6(mpc_dw0_dp2, mpc_dw0_dp_ir2);
mpc_dw0_v_copy_8(mpc_dw0_dy2, mpc_dw0_dy_ir2);
mpc_dw0_v_copy_8(mpc_dw0_dnu2, mpc_dw0_dnu_ir2);
mpc_dw0_v_copy_6(mpc_dw0_dx3, mpc_dw0_dx_ir3);
mpc_dw0_v_copy_1(mpc_dw0_du3, mpc_dw0_du_ir3);
mpc_dw0_v_copy_4(mpc_dw0_ds3, mpc_dw0_ds_ir3);
mpc_dw0_v_copy_6(mpc_dw0_dp3, mpc_dw0_dp_ir3);
mpc_dw0_v_copy_8(mpc_dw0_dy3, mpc_dw0_dy_ir3);
mpc_dw0_v_copy_8(mpc_dw0_dnu3, mpc_dw0_dnu_ir3);
mpc_dw0_v_copy_6(mpc_dw0_dx4, mpc_dw0_dx_ir4);
mpc_dw0_v_copy_1(mpc_dw0_du4, mpc_dw0_du_ir4);
mpc_dw0_v_copy_4(mpc_dw0_ds4, mpc_dw0_ds_ir4);
mpc_dw0_v_copy_6(mpc_dw0_dp4, mpc_dw0_dp_ir4);
mpc_dw0_v_copy_8(mpc_dw0_dy4, mpc_dw0_dy_ir4);
mpc_dw0_v_copy_8(mpc_dw0_dnu4, mpc_dw0_dnu_ir4);
mpc_dw0_v_copy_6(mpc_dw0_dx5, mpc_dw0_dx_ir5);
mpc_dw0_v_copy_1(mpc_dw0_du5, mpc_dw0_du_ir5);
mpc_dw0_v_copy_4(mpc_dw0_ds5, mpc_dw0_ds_ir5);
mpc_dw0_v_copy_6(mpc_dw0_dp5, mpc_dw0_dp_ir5);
mpc_dw0_v_copy_8(mpc_dw0_dy5, mpc_dw0_dy_ir5);
mpc_dw0_v_copy_8(mpc_dw0_dnu5, mpc_dw0_dnu_ir5);
mpc_dw0_v_copy_6(mpc_dw0_dx6, mpc_dw0_dx_ir6);
mpc_dw0_v_copy_1(mpc_dw0_du6, mpc_dw0_du_ir6);
mpc_dw0_v_copy_4(mpc_dw0_ds6, mpc_dw0_ds_ir6);
mpc_dw0_v_copy_6(mpc_dw0_dp6, mpc_dw0_dp_ir6);
mpc_dw0_v_copy_8(mpc_dw0_dy6, mpc_dw0_dy_ir6);
mpc_dw0_v_copy_8(mpc_dw0_dnu6, mpc_dw0_dnu_ir6);
mpc_dw0_v_copy_6(mpc_dw0_dx7, mpc_dw0_dx_ir7);
mpc_dw0_v_copy_1(mpc_dw0_du7, mpc_dw0_du_ir7);
mpc_dw0_v_copy_4(mpc_dw0_ds7, mpc_dw0_ds_ir7);
mpc_dw0_v_copy_6(mpc_dw0_dp7, mpc_dw0_dp_ir7);
mpc_dw0_v_copy_8(mpc_dw0_dy7, mpc_dw0_dy_ir7);
mpc_dw0_v_copy_8(mpc_dw0_dnu7, mpc_dw0_dnu_ir7);
mpc_dw0_v_copy_6(mpc_dw0_dx8, mpc_dw0_dx_ir8);
mpc_dw0_v_copy_1(mpc_dw0_du8, mpc_dw0_du_ir8);
mpc_dw0_v_copy_4(mpc_dw0_ds8, mpc_dw0_ds_ir8);
mpc_dw0_v_copy_6(mpc_dw0_dp8, mpc_dw0_dp_ir8);
mpc_dw0_v_copy_8(mpc_dw0_dy8, mpc_dw0_dy_ir8);
mpc_dw0_v_copy_8(mpc_dw0_dnu8, mpc_dw0_dnu_ir8);
mpc_dw0_v_copy_6(mpc_dw0_dx9, mpc_dw0_dx_ir9);
mpc_dw0_v_copy_1(mpc_dw0_du9, mpc_dw0_du_ir9);
mpc_dw0_v_copy_4(mpc_dw0_ds9, mpc_dw0_ds_ir9);
mpc_dw0_v_copy_6(mpc_dw0_dp9, mpc_dw0_dp_ir9);
mpc_dw0_v_copy_8(mpc_dw0_dy9, mpc_dw0_dy_ir9);
mpc_dw0_v_copy_8(mpc_dw0_dnu9, mpc_dw0_dnu_ir9);
mpc_dw0_v_copy_6(mpc_dw0_dx10, mpc_dw0_dx_ir10);
mpc_dw0_v_copy_1(mpc_dw0_du10, mpc_dw0_du_ir10);
mpc_dw0_v_copy_4(mpc_dw0_ds10, mpc_dw0_ds_ir10);
mpc_dw0_v_copy_6(mpc_dw0_dp10, mpc_dw0_dp_ir10);
mpc_dw0_v_copy_8(mpc_dw0_dy10, mpc_dw0_dy_ir10);
mpc_dw0_v_copy_8(mpc_dw0_dnu10, mpc_dw0_dnu_ir10);
mpc_dw0_v_copy_6(mpc_dw0_dx11, mpc_dw0_dx_ir11);
mpc_dw0_v_copy_1(mpc_dw0_du11, mpc_dw0_du_ir11);
mpc_dw0_v_copy_2(mpc_dw0_ds11, mpc_dw0_ds_ir11);
mpc_dw0_v_copy_6(mpc_dw0_dp11, mpc_dw0_dp_ir11);
mpc_dw0_v_copy_4(mpc_dw0_dy11, mpc_dw0_dy_ir11);
mpc_dw0_v_copy_4(mpc_dw0_dnu11, mpc_dw0_dnu_ir11);
/* rhs sichern */
mpc_dw0_v_copy_6(mpc_dw0_rf0x0, mpc_dw0_rf0x_ir0);
mpc_dw0_v_copy_1(mpc_dw0_rf0u0, mpc_dw0_rf0u_ir0);
mpc_dw0_v_copy_2(mpc_dw0_rf0s0, mpc_dw0_rf0s_ir0);
mpc_dw0_v_copy_6(mpc_dw0_rf0, mpc_dw0_rf_ir0);
mpc_dw0_v_copy_4(mpc_dw0_rc0, mpc_dw0_rc_ir0);
mpc_dw0_v_copy_2(mpc_dw0_rs0, mpc_dw0_rs_ir0);
mpc_dw0_v_copy_4(mpc_dw0_rk0, mpc_dw0_rk_ir0);
mpc_dw0_v_copy_6(mpc_dw0_rf0x1, mpc_dw0_rf0x_ir1);
mpc_dw0_v_copy_1(mpc_dw0_rf0u1, mpc_dw0_rf0u_ir1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s1, mpc_dw0_rf0s_ir1);
mpc_dw0_v_copy_6(mpc_dw0_rf1, mpc_dw0_rf_ir1);
mpc_dw0_v_copy_8(mpc_dw0_rc1, mpc_dw0_rc_ir1);
mpc_dw0_v_copy_4(mpc_dw0_rs1, mpc_dw0_rs_ir1);
mpc_dw0_v_copy_8(mpc_dw0_rk1, mpc_dw0_rk_ir1);
mpc_dw0_v_copy_6(mpc_dw0_rf0x2, mpc_dw0_rf0x_ir2);
mpc_dw0_v_copy_1(mpc_dw0_rf0u2, mpc_dw0_rf0u_ir2);
mpc_dw0_v_copy_4(mpc_dw0_rf0s2, mpc_dw0_rf0s_ir2);
mpc_dw0_v_copy_6(mpc_dw0_rf2, mpc_dw0_rf_ir2);
mpc_dw0_v_copy_8(mpc_dw0_rc2, mpc_dw0_rc_ir2);
mpc_dw0_v_copy_4(mpc_dw0_rs2, mpc_dw0_rs_ir2);
mpc_dw0_v_copy_8(mpc_dw0_rk2, mpc_dw0_rk_ir2);
mpc_dw0_v_copy_6(mpc_dw0_rf0x3, mpc_dw0_rf0x_ir3);
mpc_dw0_v_copy_1(mpc_dw0_rf0u3, mpc_dw0_rf0u_ir3);
mpc_dw0_v_copy_4(mpc_dw0_rf0s3, mpc_dw0_rf0s_ir3);
mpc_dw0_v_copy_6(mpc_dw0_rf3, mpc_dw0_rf_ir3);
mpc_dw0_v_copy_8(mpc_dw0_rc3, mpc_dw0_rc_ir3);
mpc_dw0_v_copy_4(mpc_dw0_rs3, mpc_dw0_rs_ir3);
mpc_dw0_v_copy_8(mpc_dw0_rk3, mpc_dw0_rk_ir3);
mpc_dw0_v_copy_6(mpc_dw0_rf0x4, mpc_dw0_rf0x_ir4);
mpc_dw0_v_copy_1(mpc_dw0_rf0u4, mpc_dw0_rf0u_ir4);
mpc_dw0_v_copy_4(mpc_dw0_rf0s4, mpc_dw0_rf0s_ir4);
mpc_dw0_v_copy_6(mpc_dw0_rf4, mpc_dw0_rf_ir4);
mpc_dw0_v_copy_8(mpc_dw0_rc4, mpc_dw0_rc_ir4);
mpc_dw0_v_copy_4(mpc_dw0_rs4, mpc_dw0_rs_ir4);
mpc_dw0_v_copy_8(mpc_dw0_rk4, mpc_dw0_rk_ir4);
mpc_dw0_v_copy_6(mpc_dw0_rf0x5, mpc_dw0_rf0x_ir5);
mpc_dw0_v_copy_1(mpc_dw0_rf0u5, mpc_dw0_rf0u_ir5);
mpc_dw0_v_copy_4(mpc_dw0_rf0s5, mpc_dw0_rf0s_ir5);
mpc_dw0_v_copy_6(mpc_dw0_rf5, mpc_dw0_rf_ir5);
mpc_dw0_v_copy_8(mpc_dw0_rc5, mpc_dw0_rc_ir5);
mpc_dw0_v_copy_4(mpc_dw0_rs5, mpc_dw0_rs_ir5);
mpc_dw0_v_copy_8(mpc_dw0_rk5, mpc_dw0_rk_ir5);
mpc_dw0_v_copy_6(mpc_dw0_rf0x6, mpc_dw0_rf0x_ir6);
mpc_dw0_v_copy_1(mpc_dw0_rf0u6, mpc_dw0_rf0u_ir6);
mpc_dw0_v_copy_4(mpc_dw0_rf0s6, mpc_dw0_rf0s_ir6);
mpc_dw0_v_copy_6(mpc_dw0_rf6, mpc_dw0_rf_ir6);
mpc_dw0_v_copy_8(mpc_dw0_rc6, mpc_dw0_rc_ir6);
mpc_dw0_v_copy_4(mpc_dw0_rs6, mpc_dw0_rs_ir6);
mpc_dw0_v_copy_8(mpc_dw0_rk6, mpc_dw0_rk_ir6);
mpc_dw0_v_copy_6(mpc_dw0_rf0x7, mpc_dw0_rf0x_ir7);
mpc_dw0_v_copy_1(mpc_dw0_rf0u7, mpc_dw0_rf0u_ir7);
mpc_dw0_v_copy_4(mpc_dw0_rf0s7, mpc_dw0_rf0s_ir7);
mpc_dw0_v_copy_6(mpc_dw0_rf7, mpc_dw0_rf_ir7);
mpc_dw0_v_copy_8(mpc_dw0_rc7, mpc_dw0_rc_ir7);
mpc_dw0_v_copy_4(mpc_dw0_rs7, mpc_dw0_rs_ir7);
mpc_dw0_v_copy_8(mpc_dw0_rk7, mpc_dw0_rk_ir7);
mpc_dw0_v_copy_6(mpc_dw0_rf0x8, mpc_dw0_rf0x_ir8);
mpc_dw0_v_copy_1(mpc_dw0_rf0u8, mpc_dw0_rf0u_ir8);
mpc_dw0_v_copy_4(mpc_dw0_rf0s8, mpc_dw0_rf0s_ir8);
mpc_dw0_v_copy_6(mpc_dw0_rf8, mpc_dw0_rf_ir8);
mpc_dw0_v_copy_8(mpc_dw0_rc8, mpc_dw0_rc_ir8);
mpc_dw0_v_copy_4(mpc_dw0_rs8, mpc_dw0_rs_ir8);
mpc_dw0_v_copy_8(mpc_dw0_rk8, mpc_dw0_rk_ir8);
mpc_dw0_v_copy_6(mpc_dw0_rf0x9, mpc_dw0_rf0x_ir9);
mpc_dw0_v_copy_1(mpc_dw0_rf0u9, mpc_dw0_rf0u_ir9);
mpc_dw0_v_copy_4(mpc_dw0_rf0s9, mpc_dw0_rf0s_ir9);
mpc_dw0_v_copy_6(mpc_dw0_rf9, mpc_dw0_rf_ir9);
mpc_dw0_v_copy_8(mpc_dw0_rc9, mpc_dw0_rc_ir9);
mpc_dw0_v_copy_4(mpc_dw0_rs9, mpc_dw0_rs_ir9);
mpc_dw0_v_copy_8(mpc_dw0_rk9, mpc_dw0_rk_ir9);
mpc_dw0_v_copy_6(mpc_dw0_rf0x10, mpc_dw0_rf0x_ir10);
mpc_dw0_v_copy_1(mpc_dw0_rf0u10, mpc_dw0_rf0u_ir10);
mpc_dw0_v_copy_4(mpc_dw0_rf0s10, mpc_dw0_rf0s_ir10);
mpc_dw0_v_copy_6(mpc_dw0_rf10, mpc_dw0_rf_ir10);
mpc_dw0_v_copy_8(mpc_dw0_rc10, mpc_dw0_rc_ir10);
mpc_dw0_v_copy_4(mpc_dw0_rs10, mpc_dw0_rs_ir10);
mpc_dw0_v_copy_8(mpc_dw0_rk10, mpc_dw0_rk_ir10);
mpc_dw0_v_copy_6(mpc_dw0_rf0x11, mpc_dw0_rf0x_ir11);
mpc_dw0_v_copy_1(mpc_dw0_rf0u11, mpc_dw0_rf0u_ir11);
mpc_dw0_v_copy_2(mpc_dw0_rf0s11, mpc_dw0_rf0s_ir11);
mpc_dw0_v_copy_6(mpc_dw0_rf11, mpc_dw0_rf_ir11);
mpc_dw0_v_copy_4(mpc_dw0_rc11, mpc_dw0_rc_ir11);
mpc_dw0_v_copy_2(mpc_dw0_rs11, mpc_dw0_rs_ir11);
mpc_dw0_v_copy_4(mpc_dw0_rk11, mpc_dw0_rk_ir11);
/* Residuum berechnen */
mpc_dw0_glqdocpip_rhs_iter_ref();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_rhs_reduced();
if(mpc_dw0_termcode > -1){return;}
/* GLS mit Residuum als rechte Seite lösen */
mpc_dw0_glqdocpip_solve();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_dereduce();
if(mpc_dw0_termcode > -1){return;}
/* Lösung aktualisieren */
mpc_dw0_vadd_6(mpc_dw0_dx_ir0, mpc_dw0_dx0, mpc_dw0_dx0);
mpc_dw0_vadd_1(mpc_dw0_du_ir0, mpc_dw0_du0, mpc_dw0_du0);
mpc_dw0_vadd_2(mpc_dw0_ds_ir0, mpc_dw0_ds0, mpc_dw0_ds0);
mpc_dw0_vadd_6(mpc_dw0_dp_ir0, mpc_dw0_dp0, mpc_dw0_dp0);
mpc_dw0_vadd_4(mpc_dw0_dy_ir0, mpc_dw0_dy0, mpc_dw0_dy0);
mpc_dw0_vadd_4(mpc_dw0_dnu_ir0, mpc_dw0_dnu0, mpc_dw0_dnu0);
mpc_dw0_vadd_6(mpc_dw0_dx_ir1, mpc_dw0_dx1, mpc_dw0_dx1);
mpc_dw0_vadd_1(mpc_dw0_du_ir1, mpc_dw0_du1, mpc_dw0_du1);
mpc_dw0_vadd_4(mpc_dw0_ds_ir1, mpc_dw0_ds1, mpc_dw0_ds1);
mpc_dw0_vadd_6(mpc_dw0_dp_ir1, mpc_dw0_dp1, mpc_dw0_dp1);
mpc_dw0_vadd_8(mpc_dw0_dy_ir1, mpc_dw0_dy1, mpc_dw0_dy1);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir1, mpc_dw0_dnu1, mpc_dw0_dnu1);
mpc_dw0_vadd_6(mpc_dw0_dx_ir2, mpc_dw0_dx2, mpc_dw0_dx2);
mpc_dw0_vadd_1(mpc_dw0_du_ir2, mpc_dw0_du2, mpc_dw0_du2);
mpc_dw0_vadd_4(mpc_dw0_ds_ir2, mpc_dw0_ds2, mpc_dw0_ds2);
mpc_dw0_vadd_6(mpc_dw0_dp_ir2, mpc_dw0_dp2, mpc_dw0_dp2);
mpc_dw0_vadd_8(mpc_dw0_dy_ir2, mpc_dw0_dy2, mpc_dw0_dy2);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir2, mpc_dw0_dnu2, mpc_dw0_dnu2);
mpc_dw0_vadd_6(mpc_dw0_dx_ir3, mpc_dw0_dx3, mpc_dw0_dx3);
mpc_dw0_vadd_1(mpc_dw0_du_ir3, mpc_dw0_du3, mpc_dw0_du3);
mpc_dw0_vadd_4(mpc_dw0_ds_ir3, mpc_dw0_ds3, mpc_dw0_ds3);
mpc_dw0_vadd_6(mpc_dw0_dp_ir3, mpc_dw0_dp3, mpc_dw0_dp3);
mpc_dw0_vadd_8(mpc_dw0_dy_ir3, mpc_dw0_dy3, mpc_dw0_dy3);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir3, mpc_dw0_dnu3, mpc_dw0_dnu3);
mpc_dw0_vadd_6(mpc_dw0_dx_ir4, mpc_dw0_dx4, mpc_dw0_dx4);
mpc_dw0_vadd_1(mpc_dw0_du_ir4, mpc_dw0_du4, mpc_dw0_du4);
mpc_dw0_vadd_4(mpc_dw0_ds_ir4, mpc_dw0_ds4, mpc_dw0_ds4);
mpc_dw0_vadd_6(mpc_dw0_dp_ir4, mpc_dw0_dp4, mpc_dw0_dp4);
mpc_dw0_vadd_8(mpc_dw0_dy_ir4, mpc_dw0_dy4, mpc_dw0_dy4);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir4, mpc_dw0_dnu4, mpc_dw0_dnu4);
mpc_dw0_vadd_6(mpc_dw0_dx_ir5, mpc_dw0_dx5, mpc_dw0_dx5);
mpc_dw0_vadd_1(mpc_dw0_du_ir5, mpc_dw0_du5, mpc_dw0_du5);
mpc_dw0_vadd_4(mpc_dw0_ds_ir5, mpc_dw0_ds5, mpc_dw0_ds5);
mpc_dw0_vadd_6(mpc_dw0_dp_ir5, mpc_dw0_dp5, mpc_dw0_dp5);
mpc_dw0_vadd_8(mpc_dw0_dy_ir5, mpc_dw0_dy5, mpc_dw0_dy5);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir5, mpc_dw0_dnu5, mpc_dw0_dnu5);
mpc_dw0_vadd_6(mpc_dw0_dx_ir6, mpc_dw0_dx6, mpc_dw0_dx6);
mpc_dw0_vadd_1(mpc_dw0_du_ir6, mpc_dw0_du6, mpc_dw0_du6);
mpc_dw0_vadd_4(mpc_dw0_ds_ir6, mpc_dw0_ds6, mpc_dw0_ds6);
mpc_dw0_vadd_6(mpc_dw0_dp_ir6, mpc_dw0_dp6, mpc_dw0_dp6);
mpc_dw0_vadd_8(mpc_dw0_dy_ir6, mpc_dw0_dy6, mpc_dw0_dy6);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir6, mpc_dw0_dnu6, mpc_dw0_dnu6);
mpc_dw0_vadd_6(mpc_dw0_dx_ir7, mpc_dw0_dx7, mpc_dw0_dx7);
mpc_dw0_vadd_1(mpc_dw0_du_ir7, mpc_dw0_du7, mpc_dw0_du7);
mpc_dw0_vadd_4(mpc_dw0_ds_ir7, mpc_dw0_ds7, mpc_dw0_ds7);
mpc_dw0_vadd_6(mpc_dw0_dp_ir7, mpc_dw0_dp7, mpc_dw0_dp7);
mpc_dw0_vadd_8(mpc_dw0_dy_ir7, mpc_dw0_dy7, mpc_dw0_dy7);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir7, mpc_dw0_dnu7, mpc_dw0_dnu7);
mpc_dw0_vadd_6(mpc_dw0_dx_ir8, mpc_dw0_dx8, mpc_dw0_dx8);
mpc_dw0_vadd_1(mpc_dw0_du_ir8, mpc_dw0_du8, mpc_dw0_du8);
mpc_dw0_vadd_4(mpc_dw0_ds_ir8, mpc_dw0_ds8, mpc_dw0_ds8);
mpc_dw0_vadd_6(mpc_dw0_dp_ir8, mpc_dw0_dp8, mpc_dw0_dp8);
mpc_dw0_vadd_8(mpc_dw0_dy_ir8, mpc_dw0_dy8, mpc_dw0_dy8);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir8, mpc_dw0_dnu8, mpc_dw0_dnu8);
mpc_dw0_vadd_6(mpc_dw0_dx_ir9, mpc_dw0_dx9, mpc_dw0_dx9);
mpc_dw0_vadd_1(mpc_dw0_du_ir9, mpc_dw0_du9, mpc_dw0_du9);
mpc_dw0_vadd_4(mpc_dw0_ds_ir9, mpc_dw0_ds9, mpc_dw0_ds9);
mpc_dw0_vadd_6(mpc_dw0_dp_ir9, mpc_dw0_dp9, mpc_dw0_dp9);
mpc_dw0_vadd_8(mpc_dw0_dy_ir9, mpc_dw0_dy9, mpc_dw0_dy9);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir9, mpc_dw0_dnu9, mpc_dw0_dnu9);
mpc_dw0_vadd_6(mpc_dw0_dx_ir10, mpc_dw0_dx10, mpc_dw0_dx10);
mpc_dw0_vadd_1(mpc_dw0_du_ir10, mpc_dw0_du10, mpc_dw0_du10);
mpc_dw0_vadd_4(mpc_dw0_ds_ir10, mpc_dw0_ds10, mpc_dw0_ds10);
mpc_dw0_vadd_6(mpc_dw0_dp_ir10, mpc_dw0_dp10, mpc_dw0_dp10);
mpc_dw0_vadd_8(mpc_dw0_dy_ir10, mpc_dw0_dy10, mpc_dw0_dy10);
mpc_dw0_vadd_8(mpc_dw0_dnu_ir10, mpc_dw0_dnu10, mpc_dw0_dnu10);
mpc_dw0_vadd_6(mpc_dw0_dx_ir11, mpc_dw0_dx11, mpc_dw0_dx11);
mpc_dw0_vadd_1(mpc_dw0_du_ir11, mpc_dw0_du11, mpc_dw0_du11);
mpc_dw0_vadd_2(mpc_dw0_ds_ir11, mpc_dw0_ds11, mpc_dw0_ds11);
mpc_dw0_vadd_6(mpc_dw0_dp_ir11, mpc_dw0_dp11, mpc_dw0_dp11);
mpc_dw0_vadd_4(mpc_dw0_dy_ir11, mpc_dw0_dy11, mpc_dw0_dy11);
mpc_dw0_vadd_4(mpc_dw0_dnu_ir11, mpc_dw0_dnu11, mpc_dw0_dnu11);
/* rhs wiederherstellen */
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir0, mpc_dw0_rf0x0);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir0, mpc_dw0_rf0u0);
mpc_dw0_v_copy_2(mpc_dw0_rf0s_ir0, mpc_dw0_rf0s0);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir0, mpc_dw0_rf0);
mpc_dw0_v_copy_4(mpc_dw0_rc_ir0, mpc_dw0_rc0);
mpc_dw0_v_copy_2(mpc_dw0_rs_ir0, mpc_dw0_rs0);
mpc_dw0_v_copy_4(mpc_dw0_rk_ir0, mpc_dw0_rk0);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir1, mpc_dw0_rf0x1);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir1, mpc_dw0_rf0u1);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir1, mpc_dw0_rf0s1);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir1, mpc_dw0_rf1);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir1, mpc_dw0_rc1);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir1, mpc_dw0_rs1);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir1, mpc_dw0_rk1);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir2, mpc_dw0_rf0x2);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir2, mpc_dw0_rf0u2);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir2, mpc_dw0_rf0s2);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir2, mpc_dw0_rf2);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir2, mpc_dw0_rc2);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir2, mpc_dw0_rs2);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir2, mpc_dw0_rk2);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir3, mpc_dw0_rf0x3);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir3, mpc_dw0_rf0u3);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir3, mpc_dw0_rf0s3);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir3, mpc_dw0_rf3);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir3, mpc_dw0_rc3);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir3, mpc_dw0_rs3);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir3, mpc_dw0_rk3);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir4, mpc_dw0_rf0x4);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir4, mpc_dw0_rf0u4);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir4, mpc_dw0_rf0s4);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir4, mpc_dw0_rf4);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir4, mpc_dw0_rc4);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir4, mpc_dw0_rs4);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir4, mpc_dw0_rk4);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir5, mpc_dw0_rf0x5);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir5, mpc_dw0_rf0u5);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir5, mpc_dw0_rf0s5);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir5, mpc_dw0_rf5);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir5, mpc_dw0_rc5);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir5, mpc_dw0_rs5);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir5, mpc_dw0_rk5);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir6, mpc_dw0_rf0x6);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir6, mpc_dw0_rf0u6);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir6, mpc_dw0_rf0s6);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir6, mpc_dw0_rf6);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir6, mpc_dw0_rc6);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir6, mpc_dw0_rs6);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir6, mpc_dw0_rk6);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir7, mpc_dw0_rf0x7);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir7, mpc_dw0_rf0u7);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir7, mpc_dw0_rf0s7);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir7, mpc_dw0_rf7);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir7, mpc_dw0_rc7);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir7, mpc_dw0_rs7);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir7, mpc_dw0_rk7);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir8, mpc_dw0_rf0x8);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir8, mpc_dw0_rf0u8);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir8, mpc_dw0_rf0s8);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir8, mpc_dw0_rf8);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir8, mpc_dw0_rc8);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir8, mpc_dw0_rs8);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir8, mpc_dw0_rk8);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir9, mpc_dw0_rf0x9);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir9, mpc_dw0_rf0u9);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir9, mpc_dw0_rf0s9);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir9, mpc_dw0_rf9);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir9, mpc_dw0_rc9);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir9, mpc_dw0_rs9);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir9, mpc_dw0_rk9);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir10, mpc_dw0_rf0x10);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir10, mpc_dw0_rf0u10);
mpc_dw0_v_copy_4(mpc_dw0_rf0s_ir10, mpc_dw0_rf0s10);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir10, mpc_dw0_rf10);
mpc_dw0_v_copy_8(mpc_dw0_rc_ir10, mpc_dw0_rc10);
mpc_dw0_v_copy_4(mpc_dw0_rs_ir10, mpc_dw0_rs10);
mpc_dw0_v_copy_8(mpc_dw0_rk_ir10, mpc_dw0_rk10);
mpc_dw0_v_copy_6(mpc_dw0_rf0x_ir11, mpc_dw0_rf0x11);
mpc_dw0_v_copy_1(mpc_dw0_rf0u_ir11, mpc_dw0_rf0u11);
mpc_dw0_v_copy_2(mpc_dw0_rf0s_ir11, mpc_dw0_rf0s11);
mpc_dw0_v_copy_6(mpc_dw0_rf_ir11, mpc_dw0_rf11);
mpc_dw0_v_copy_4(mpc_dw0_rc_ir11, mpc_dw0_rc11);
mpc_dw0_v_copy_2(mpc_dw0_rs_ir11, mpc_dw0_rs11);
mpc_dw0_v_copy_4(mpc_dw0_rk_ir11, mpc_dw0_rk11);
}
}


/* ####################################### */
/* Diese Funktion berechnet den Startpunkt */
/*           Startpunktmethode: 5          */
/* ####################################### */
static void mpc_dw0_glqdocpip_starting_point()
{
/* Very Cold Start */
/* Zeitschritt 0 */
mpc_dw0_v_init0_6(mpc_dw0_x0);
mpc_dw0_v_init0_1(mpc_dw0_u0);
mpc_dw0_v_init0_2(mpc_dw0_s0);
mpc_dw0_max(&mpc_dw0_s0[0], &mpc_dw0_g0[0], &mpc_dw0_s0[0]);
mpc_dw0_max(&mpc_dw0_s0[1], &mpc_dw0_g0[1], &mpc_dw0_s0[1]);
mpc_dw0_v_init0_6(mpc_dw0_p0);
mpc_dw0_v_init1_4(mpc_dw0_y0);
mpc_dw0_v_init1_4(mpc_dw0_nu0);
/* Zeitschritt 1 */
mpc_dw0_v_init0_6(mpc_dw0_x1);
mpc_dw0_v_init0_1(mpc_dw0_u1);
mpc_dw0_v_init0_4(mpc_dw0_s1);
mpc_dw0_max(&mpc_dw0_s1[0], &mpc_dw0_g1[0], &mpc_dw0_s1[0]);
mpc_dw0_max(&mpc_dw0_s1[1], &mpc_dw0_g1[1], &mpc_dw0_s1[1]);
mpc_dw0_max(&mpc_dw0_s1[2], &mpc_dw0_g1[2], &mpc_dw0_s1[2]);
mpc_dw0_max(&mpc_dw0_s1[3], &mpc_dw0_g1[3], &mpc_dw0_s1[3]);
mpc_dw0_v_init0_6(mpc_dw0_p1);
mpc_dw0_v_init1_8(mpc_dw0_y1);
mpc_dw0_v_init1_8(mpc_dw0_nu1);
/* Zeitschritt 2 */
mpc_dw0_v_init0_6(mpc_dw0_x2);
mpc_dw0_v_init0_1(mpc_dw0_u2);
mpc_dw0_v_init0_4(mpc_dw0_s2);
mpc_dw0_max(&mpc_dw0_s2[0], &mpc_dw0_g2[0], &mpc_dw0_s2[0]);
mpc_dw0_max(&mpc_dw0_s2[1], &mpc_dw0_g2[1], &mpc_dw0_s2[1]);
mpc_dw0_max(&mpc_dw0_s2[2], &mpc_dw0_g2[2], &mpc_dw0_s2[2]);
mpc_dw0_max(&mpc_dw0_s2[3], &mpc_dw0_g2[3], &mpc_dw0_s2[3]);
mpc_dw0_v_init0_6(mpc_dw0_p2);
mpc_dw0_v_init1_8(mpc_dw0_y2);
mpc_dw0_v_init1_8(mpc_dw0_nu2);
/* Zeitschritt 3 */
mpc_dw0_v_init0_6(mpc_dw0_x3);
mpc_dw0_v_init0_1(mpc_dw0_u3);
mpc_dw0_v_init0_4(mpc_dw0_s3);
mpc_dw0_max(&mpc_dw0_s3[0], &mpc_dw0_g3[0], &mpc_dw0_s3[0]);
mpc_dw0_max(&mpc_dw0_s3[1], &mpc_dw0_g3[1], &mpc_dw0_s3[1]);
mpc_dw0_max(&mpc_dw0_s3[2], &mpc_dw0_g3[2], &mpc_dw0_s3[2]);
mpc_dw0_max(&mpc_dw0_s3[3], &mpc_dw0_g3[3], &mpc_dw0_s3[3]);
mpc_dw0_v_init0_6(mpc_dw0_p3);
mpc_dw0_v_init1_8(mpc_dw0_y3);
mpc_dw0_v_init1_8(mpc_dw0_nu3);
/* Zeitschritt 4 */
mpc_dw0_v_init0_6(mpc_dw0_x4);
mpc_dw0_v_init0_1(mpc_dw0_u4);
mpc_dw0_v_init0_4(mpc_dw0_s4);
mpc_dw0_max(&mpc_dw0_s4[0], &mpc_dw0_g4[0], &mpc_dw0_s4[0]);
mpc_dw0_max(&mpc_dw0_s4[1], &mpc_dw0_g4[1], &mpc_dw0_s4[1]);
mpc_dw0_max(&mpc_dw0_s4[2], &mpc_dw0_g4[2], &mpc_dw0_s4[2]);
mpc_dw0_max(&mpc_dw0_s4[3], &mpc_dw0_g4[3], &mpc_dw0_s4[3]);
mpc_dw0_v_init0_6(mpc_dw0_p4);
mpc_dw0_v_init1_8(mpc_dw0_y4);
mpc_dw0_v_init1_8(mpc_dw0_nu4);
/* Zeitschritt 5 */
mpc_dw0_v_init0_6(mpc_dw0_x5);
mpc_dw0_v_init0_1(mpc_dw0_u5);
mpc_dw0_v_init0_4(mpc_dw0_s5);
mpc_dw0_max(&mpc_dw0_s5[0], &mpc_dw0_g5[0], &mpc_dw0_s5[0]);
mpc_dw0_max(&mpc_dw0_s5[1], &mpc_dw0_g5[1], &mpc_dw0_s5[1]);
mpc_dw0_max(&mpc_dw0_s5[2], &mpc_dw0_g5[2], &mpc_dw0_s5[2]);
mpc_dw0_max(&mpc_dw0_s5[3], &mpc_dw0_g5[3], &mpc_dw0_s5[3]);
mpc_dw0_v_init0_6(mpc_dw0_p5);
mpc_dw0_v_init1_8(mpc_dw0_y5);
mpc_dw0_v_init1_8(mpc_dw0_nu5);
/* Zeitschritt 6 */
mpc_dw0_v_init0_6(mpc_dw0_x6);
mpc_dw0_v_init0_1(mpc_dw0_u6);
mpc_dw0_v_init0_4(mpc_dw0_s6);
mpc_dw0_max(&mpc_dw0_s6[0], &mpc_dw0_g6[0], &mpc_dw0_s6[0]);
mpc_dw0_max(&mpc_dw0_s6[1], &mpc_dw0_g6[1], &mpc_dw0_s6[1]);
mpc_dw0_max(&mpc_dw0_s6[2], &mpc_dw0_g6[2], &mpc_dw0_s6[2]);
mpc_dw0_max(&mpc_dw0_s6[3], &mpc_dw0_g6[3], &mpc_dw0_s6[3]);
mpc_dw0_v_init0_6(mpc_dw0_p6);
mpc_dw0_v_init1_8(mpc_dw0_y6);
mpc_dw0_v_init1_8(mpc_dw0_nu6);
/* Zeitschritt 7 */
mpc_dw0_v_init0_6(mpc_dw0_x7);
mpc_dw0_v_init0_1(mpc_dw0_u7);
mpc_dw0_v_init0_4(mpc_dw0_s7);
mpc_dw0_max(&mpc_dw0_s7[0], &mpc_dw0_g7[0], &mpc_dw0_s7[0]);
mpc_dw0_max(&mpc_dw0_s7[1], &mpc_dw0_g7[1], &mpc_dw0_s7[1]);
mpc_dw0_max(&mpc_dw0_s7[2], &mpc_dw0_g7[2], &mpc_dw0_s7[2]);
mpc_dw0_max(&mpc_dw0_s7[3], &mpc_dw0_g7[3], &mpc_dw0_s7[3]);
mpc_dw0_v_init0_6(mpc_dw0_p7);
mpc_dw0_v_init1_8(mpc_dw0_y7);
mpc_dw0_v_init1_8(mpc_dw0_nu7);
/* Zeitschritt 8 */
mpc_dw0_v_init0_6(mpc_dw0_x8);
mpc_dw0_v_init0_1(mpc_dw0_u8);
mpc_dw0_v_init0_4(mpc_dw0_s8);
mpc_dw0_max(&mpc_dw0_s8[0], &mpc_dw0_g8[0], &mpc_dw0_s8[0]);
mpc_dw0_max(&mpc_dw0_s8[1], &mpc_dw0_g8[1], &mpc_dw0_s8[1]);
mpc_dw0_max(&mpc_dw0_s8[2], &mpc_dw0_g8[2], &mpc_dw0_s8[2]);
mpc_dw0_max(&mpc_dw0_s8[3], &mpc_dw0_g8[3], &mpc_dw0_s8[3]);
mpc_dw0_v_init0_6(mpc_dw0_p8);
mpc_dw0_v_init1_8(mpc_dw0_y8);
mpc_dw0_v_init1_8(mpc_dw0_nu8);
/* Zeitschritt 9 */
mpc_dw0_v_init0_6(mpc_dw0_x9);
mpc_dw0_v_init0_1(mpc_dw0_u9);
mpc_dw0_v_init0_4(mpc_dw0_s9);
mpc_dw0_max(&mpc_dw0_s9[0], &mpc_dw0_g9[0], &mpc_dw0_s9[0]);
mpc_dw0_max(&mpc_dw0_s9[1], &mpc_dw0_g9[1], &mpc_dw0_s9[1]);
mpc_dw0_max(&mpc_dw0_s9[2], &mpc_dw0_g9[2], &mpc_dw0_s9[2]);
mpc_dw0_max(&mpc_dw0_s9[3], &mpc_dw0_g9[3], &mpc_dw0_s9[3]);
mpc_dw0_v_init0_6(mpc_dw0_p9);
mpc_dw0_v_init1_8(mpc_dw0_y9);
mpc_dw0_v_init1_8(mpc_dw0_nu9);
/* Zeitschritt 10 */
mpc_dw0_v_init0_6(mpc_dw0_x10);
mpc_dw0_v_init0_1(mpc_dw0_u10);
mpc_dw0_v_init0_4(mpc_dw0_s10);
mpc_dw0_max(&mpc_dw0_s10[0], &mpc_dw0_g10[0], &mpc_dw0_s10[0]);
mpc_dw0_max(&mpc_dw0_s10[1], &mpc_dw0_g10[1], &mpc_dw0_s10[1]);
mpc_dw0_max(&mpc_dw0_s10[2], &mpc_dw0_g10[2], &mpc_dw0_s10[2]);
mpc_dw0_max(&mpc_dw0_s10[3], &mpc_dw0_g10[3], &mpc_dw0_s10[3]);
mpc_dw0_v_init0_6(mpc_dw0_p10);
mpc_dw0_v_init1_8(mpc_dw0_y10);
mpc_dw0_v_init1_8(mpc_dw0_nu10);
/* Zeitschritt 11 */
mpc_dw0_v_init0_6(mpc_dw0_x11);
mpc_dw0_v_init0_1(mpc_dw0_u11);
mpc_dw0_v_init0_2(mpc_dw0_s11);
mpc_dw0_max(&mpc_dw0_s11[0], &mpc_dw0_g11[0], &mpc_dw0_s11[0]);
mpc_dw0_max(&mpc_dw0_s11[1], &mpc_dw0_g11[1], &mpc_dw0_s11[1]);
mpc_dw0_v_init0_6(mpc_dw0_p11);
mpc_dw0_v_init1_4(mpc_dw0_y11);
mpc_dw0_v_init1_4(mpc_dw0_nu11);
/* Methode 5 */
/* Calc one step */
mpc_dw0_glqdocpip_rhs_starting_point_5();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_rhs_reduced();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_factor();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_solve();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_glqdocpip_dereduce();
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_v_copy_6(mpc_dw0_dx0, mpc_dw0_x0);
mpc_dw0_v_copy_1(mpc_dw0_du0, mpc_dw0_u0);
mpc_dw0_v_copy_2(mpc_dw0_ds0, mpc_dw0_s0);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g0[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s0[0], mpc_dw0_tmp1_1, &mpc_dw0_s0[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g0[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s0[1], mpc_dw0_tmp1_1, &mpc_dw0_s0[1]);
mpc_dw0_v_copy_6(mpc_dw0_dp0, mpc_dw0_p0);
mpc_dw0_vadd_4(mpc_dw0_y0, mpc_dw0_dy0, mpc_dw0_dy0);
mpc_dw0_vadd_4(mpc_dw0_nu0, mpc_dw0_dnu0, mpc_dw0_dnu0);
mpc_dw0_v_copy_6(mpc_dw0_dx1, mpc_dw0_x1);
mpc_dw0_v_copy_1(mpc_dw0_du1, mpc_dw0_u1);
mpc_dw0_v_copy_4(mpc_dw0_ds1, mpc_dw0_s1);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g1[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s1[0], mpc_dw0_tmp1_1, &mpc_dw0_s1[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g1[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s1[1], mpc_dw0_tmp1_1, &mpc_dw0_s1[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g1[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s1[2], mpc_dw0_tmp1_1, &mpc_dw0_s1[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g1[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s1[3], mpc_dw0_tmp1_1, &mpc_dw0_s1[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp1, mpc_dw0_p1);
mpc_dw0_vadd_8(mpc_dw0_y1, mpc_dw0_dy1, mpc_dw0_dy1);
mpc_dw0_vadd_8(mpc_dw0_nu1, mpc_dw0_dnu1, mpc_dw0_dnu1);
mpc_dw0_v_copy_6(mpc_dw0_dx2, mpc_dw0_x2);
mpc_dw0_v_copy_1(mpc_dw0_du2, mpc_dw0_u2);
mpc_dw0_v_copy_4(mpc_dw0_ds2, mpc_dw0_s2);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g2[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s2[0], mpc_dw0_tmp1_1, &mpc_dw0_s2[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g2[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s2[1], mpc_dw0_tmp1_1, &mpc_dw0_s2[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g2[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s2[2], mpc_dw0_tmp1_1, &mpc_dw0_s2[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g2[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s2[3], mpc_dw0_tmp1_1, &mpc_dw0_s2[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp2, mpc_dw0_p2);
mpc_dw0_vadd_8(mpc_dw0_y2, mpc_dw0_dy2, mpc_dw0_dy2);
mpc_dw0_vadd_8(mpc_dw0_nu2, mpc_dw0_dnu2, mpc_dw0_dnu2);
mpc_dw0_v_copy_6(mpc_dw0_dx3, mpc_dw0_x3);
mpc_dw0_v_copy_1(mpc_dw0_du3, mpc_dw0_u3);
mpc_dw0_v_copy_4(mpc_dw0_ds3, mpc_dw0_s3);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g3[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s3[0], mpc_dw0_tmp1_1, &mpc_dw0_s3[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g3[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s3[1], mpc_dw0_tmp1_1, &mpc_dw0_s3[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g3[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s3[2], mpc_dw0_tmp1_1, &mpc_dw0_s3[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g3[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s3[3], mpc_dw0_tmp1_1, &mpc_dw0_s3[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp3, mpc_dw0_p3);
mpc_dw0_vadd_8(mpc_dw0_y3, mpc_dw0_dy3, mpc_dw0_dy3);
mpc_dw0_vadd_8(mpc_dw0_nu3, mpc_dw0_dnu3, mpc_dw0_dnu3);
mpc_dw0_v_copy_6(mpc_dw0_dx4, mpc_dw0_x4);
mpc_dw0_v_copy_1(mpc_dw0_du4, mpc_dw0_u4);
mpc_dw0_v_copy_4(mpc_dw0_ds4, mpc_dw0_s4);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g4[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s4[0], mpc_dw0_tmp1_1, &mpc_dw0_s4[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g4[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s4[1], mpc_dw0_tmp1_1, &mpc_dw0_s4[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g4[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s4[2], mpc_dw0_tmp1_1, &mpc_dw0_s4[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g4[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s4[3], mpc_dw0_tmp1_1, &mpc_dw0_s4[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp4, mpc_dw0_p4);
mpc_dw0_vadd_8(mpc_dw0_y4, mpc_dw0_dy4, mpc_dw0_dy4);
mpc_dw0_vadd_8(mpc_dw0_nu4, mpc_dw0_dnu4, mpc_dw0_dnu4);
mpc_dw0_v_copy_6(mpc_dw0_dx5, mpc_dw0_x5);
mpc_dw0_v_copy_1(mpc_dw0_du5, mpc_dw0_u5);
mpc_dw0_v_copy_4(mpc_dw0_ds5, mpc_dw0_s5);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g5[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s5[0], mpc_dw0_tmp1_1, &mpc_dw0_s5[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g5[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s5[1], mpc_dw0_tmp1_1, &mpc_dw0_s5[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g5[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s5[2], mpc_dw0_tmp1_1, &mpc_dw0_s5[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g5[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s5[3], mpc_dw0_tmp1_1, &mpc_dw0_s5[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp5, mpc_dw0_p5);
mpc_dw0_vadd_8(mpc_dw0_y5, mpc_dw0_dy5, mpc_dw0_dy5);
mpc_dw0_vadd_8(mpc_dw0_nu5, mpc_dw0_dnu5, mpc_dw0_dnu5);
mpc_dw0_v_copy_6(mpc_dw0_dx6, mpc_dw0_x6);
mpc_dw0_v_copy_1(mpc_dw0_du6, mpc_dw0_u6);
mpc_dw0_v_copy_4(mpc_dw0_ds6, mpc_dw0_s6);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g6[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s6[0], mpc_dw0_tmp1_1, &mpc_dw0_s6[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g6[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s6[1], mpc_dw0_tmp1_1, &mpc_dw0_s6[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g6[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s6[2], mpc_dw0_tmp1_1, &mpc_dw0_s6[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g6[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s6[3], mpc_dw0_tmp1_1, &mpc_dw0_s6[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp6, mpc_dw0_p6);
mpc_dw0_vadd_8(mpc_dw0_y6, mpc_dw0_dy6, mpc_dw0_dy6);
mpc_dw0_vadd_8(mpc_dw0_nu6, mpc_dw0_dnu6, mpc_dw0_dnu6);
mpc_dw0_v_copy_6(mpc_dw0_dx7, mpc_dw0_x7);
mpc_dw0_v_copy_1(mpc_dw0_du7, mpc_dw0_u7);
mpc_dw0_v_copy_4(mpc_dw0_ds7, mpc_dw0_s7);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g7[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s7[0], mpc_dw0_tmp1_1, &mpc_dw0_s7[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g7[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s7[1], mpc_dw0_tmp1_1, &mpc_dw0_s7[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g7[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s7[2], mpc_dw0_tmp1_1, &mpc_dw0_s7[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g7[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s7[3], mpc_dw0_tmp1_1, &mpc_dw0_s7[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp7, mpc_dw0_p7);
mpc_dw0_vadd_8(mpc_dw0_y7, mpc_dw0_dy7, mpc_dw0_dy7);
mpc_dw0_vadd_8(mpc_dw0_nu7, mpc_dw0_dnu7, mpc_dw0_dnu7);
mpc_dw0_v_copy_6(mpc_dw0_dx8, mpc_dw0_x8);
mpc_dw0_v_copy_1(mpc_dw0_du8, mpc_dw0_u8);
mpc_dw0_v_copy_4(mpc_dw0_ds8, mpc_dw0_s8);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g8[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s8[0], mpc_dw0_tmp1_1, &mpc_dw0_s8[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g8[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s8[1], mpc_dw0_tmp1_1, &mpc_dw0_s8[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g8[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s8[2], mpc_dw0_tmp1_1, &mpc_dw0_s8[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g8[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s8[3], mpc_dw0_tmp1_1, &mpc_dw0_s8[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp8, mpc_dw0_p8);
mpc_dw0_vadd_8(mpc_dw0_y8, mpc_dw0_dy8, mpc_dw0_dy8);
mpc_dw0_vadd_8(mpc_dw0_nu8, mpc_dw0_dnu8, mpc_dw0_dnu8);
mpc_dw0_v_copy_6(mpc_dw0_dx9, mpc_dw0_x9);
mpc_dw0_v_copy_1(mpc_dw0_du9, mpc_dw0_u9);
mpc_dw0_v_copy_4(mpc_dw0_ds9, mpc_dw0_s9);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g9[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s9[0], mpc_dw0_tmp1_1, &mpc_dw0_s9[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g9[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s9[1], mpc_dw0_tmp1_1, &mpc_dw0_s9[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g9[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s9[2], mpc_dw0_tmp1_1, &mpc_dw0_s9[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g9[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s9[3], mpc_dw0_tmp1_1, &mpc_dw0_s9[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp9, mpc_dw0_p9);
mpc_dw0_vadd_8(mpc_dw0_y9, mpc_dw0_dy9, mpc_dw0_dy9);
mpc_dw0_vadd_8(mpc_dw0_nu9, mpc_dw0_dnu9, mpc_dw0_dnu9);
mpc_dw0_v_copy_6(mpc_dw0_dx10, mpc_dw0_x10);
mpc_dw0_v_copy_1(mpc_dw0_du10, mpc_dw0_u10);
mpc_dw0_v_copy_4(mpc_dw0_ds10, mpc_dw0_s10);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g10[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s10[0], mpc_dw0_tmp1_1, &mpc_dw0_s10[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g10[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s10[1], mpc_dw0_tmp1_1, &mpc_dw0_s10[1]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g10[2], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s10[2], mpc_dw0_tmp1_1, &mpc_dw0_s10[2]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g10[3], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s10[3], mpc_dw0_tmp1_1, &mpc_dw0_s10[3]);
mpc_dw0_v_copy_6(mpc_dw0_dp10, mpc_dw0_p10);
mpc_dw0_vadd_8(mpc_dw0_y10, mpc_dw0_dy10, mpc_dw0_dy10);
mpc_dw0_vadd_8(mpc_dw0_nu10, mpc_dw0_dnu10, mpc_dw0_dnu10);
mpc_dw0_v_copy_6(mpc_dw0_dx11, mpc_dw0_x11);
mpc_dw0_v_copy_1(mpc_dw0_du11, mpc_dw0_u11);
mpc_dw0_v_copy_2(mpc_dw0_ds11, mpc_dw0_s11);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g11[0], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s11[0], mpc_dw0_tmp1_1, &mpc_dw0_s11[0]);
mpc_dw0_v_init0_1(mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_g11[1], mpc_dw0_tmp1_1, mpc_dw0_tmp1_1);
mpc_dw0_max(&mpc_dw0_s11[1], mpc_dw0_tmp1_1, &mpc_dw0_s11[1]);
mpc_dw0_v_copy_6(mpc_dw0_dp11, mpc_dw0_p11);
mpc_dw0_vadd_4(mpc_dw0_y11, mpc_dw0_dy11, mpc_dw0_dy11);
mpc_dw0_vadd_4(mpc_dw0_nu11, mpc_dw0_dnu11, mpc_dw0_dnu11);
/* Init delta_y and delta_nu */
mpc_dw0_v_init0_1(mpc_dw0_starting_point_delta_y);
mpc_dw0_v_init0_1(mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp1_1[0] = -1.5;
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_4(mpc_dw0_dy0, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_4(mpc_dw0_dnu0, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy1, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu1, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy2, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu2, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy3, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu3, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy4, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu4, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy5, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu5, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy6, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu6, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy7, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu7, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy8, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu8, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy9, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu9, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dy10, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_8(mpc_dw0_dnu10, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_4(mpc_dw0_dy11, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y, mpc_dw0_starting_point_delta_y);
mpc_dw0_tmp2_1[0] = FLT_MAX;
mpc_dw0_v_min_4(mpc_dw0_dnu11, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vv_elemult_1(mpc_dw0_tmp2_1, mpc_dw0_tmp1_1, mpc_dw0_tmp2_1);
mpc_dw0_max(mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu, mpc_dw0_starting_point_delta_nu);
mpc_dw0_v_init0_1(mpc_dw0_starting_point_sum);
mpc_dw0_v_init0_1(mpc_dw0_starting_point_sum_y);
mpc_dw0_v_init0_1(mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4);
mpc_dw0_v_copy_4(mpc_dw0_dy0, mpc_dw0_tmp2_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_4, mpc_dw0_tmp2_4);
mpc_dw0_v_init1_4(mpc_dw0_tmp3_4);
mpc_dw0_v_copy_4(mpc_dw0_dnu0, mpc_dw0_tmp4_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_4, mpc_dw0_tmp4_4);
mpc_dw0_vtv_4(mpc_dw0_tmp2_4, mpc_dw0_tmp4_4, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_4(mpc_dw0_tmp2_4, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_4(mpc_dw0_tmp4_4, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_copy_8(mpc_dw0_dy1, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp3_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu1, mpc_dw0_tmp4_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_8, mpc_dw0_tmp4_8);
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp2_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp4_8);
mpc_dw0_v_copy_8(mpc_dw0_dy2, mpc_dw0_tmp3_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_8, mpc_dw0_tmp3_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu2, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vtv_8(mpc_dw0_tmp3_8, mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp3_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_copy_8(mpc_dw0_dy3, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp3_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu3, mpc_dw0_tmp4_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_8, mpc_dw0_tmp4_8);
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp2_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp4_8);
mpc_dw0_v_copy_8(mpc_dw0_dy4, mpc_dw0_tmp3_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_8, mpc_dw0_tmp3_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu4, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vtv_8(mpc_dw0_tmp3_8, mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp3_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_copy_8(mpc_dw0_dy5, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp3_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu5, mpc_dw0_tmp4_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_8, mpc_dw0_tmp4_8);
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp2_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp4_8);
mpc_dw0_v_copy_8(mpc_dw0_dy6, mpc_dw0_tmp3_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_8, mpc_dw0_tmp3_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu6, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vtv_8(mpc_dw0_tmp3_8, mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp3_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_copy_8(mpc_dw0_dy7, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp3_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu7, mpc_dw0_tmp4_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_8, mpc_dw0_tmp4_8);
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp2_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp4_8);
mpc_dw0_v_copy_8(mpc_dw0_dy8, mpc_dw0_tmp3_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_8, mpc_dw0_tmp3_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu8, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vtv_8(mpc_dw0_tmp3_8, mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp3_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_copy_8(mpc_dw0_dy9, mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp3_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu9, mpc_dw0_tmp4_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp3_8, mpc_dw0_tmp4_8);
mpc_dw0_vtv_8(mpc_dw0_tmp2_8, mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp2_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp4_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_8(mpc_dw0_tmp4_8);
mpc_dw0_v_copy_8(mpc_dw0_dy10, mpc_dw0_tmp3_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_8, mpc_dw0_tmp3_8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_copy_8(mpc_dw0_dnu10, mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vtv_8(mpc_dw0_tmp3_8, mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_8(mpc_dw0_tmp3_8, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_8(mpc_dw0_tmp1_8, mpc_dw0_starting_point_sum_nu);
mpc_dw0_v_init1_4(mpc_dw0_tmp4_4);
mpc_dw0_v_copy_4(mpc_dw0_dy11, mpc_dw0_tmp3_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp4_4, mpc_dw0_tmp3_4);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4);
mpc_dw0_v_copy_4(mpc_dw0_dnu11, mpc_dw0_tmp1_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_4, mpc_dw0_tmp1_4);
mpc_dw0_vtv_4(mpc_dw0_tmp3_4, mpc_dw0_tmp1_4, mpc_dw0_starting_point_sum);
mpc_dw0_vsum_4(mpc_dw0_tmp3_4, mpc_dw0_starting_point_sum_y);
mpc_dw0_vsum_4(mpc_dw0_tmp1_4, mpc_dw0_starting_point_sum_nu);
mpc_dw0_tmp1_1[0] = 0.5;
mpc_dw0_vv_elediv_1(mpc_dw0_starting_point_sum, mpc_dw0_starting_point_sum_nu, mpc_dw0_tmp2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_1(mpc_dw0_tmp1_1, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vadd_1(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_y);
mpc_dw0_vv_elediv_1(mpc_dw0_starting_point_sum, mpc_dw0_starting_point_sum_y, mpc_dw0_tmp2_1);
if(mpc_dw0_termcode > -1){return;}
mpc_dw0_vv_elemult_1(mpc_dw0_tmp1_1, mpc_dw0_tmp2_1, mpc_dw0_tmp2_1);
mpc_dw0_vadd_1(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_1, mpc_dw0_starting_point_delta_nu);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_4, mpc_dw0_tmp2_4);
mpc_dw0_vadd_4(mpc_dw0_dy0, mpc_dw0_tmp2_4, mpc_dw0_y0);
mpc_dw0_v_init1_4(mpc_dw0_tmp1_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp2_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_4, mpc_dw0_tmp2_4);
mpc_dw0_vadd_4(mpc_dw0_dnu0, mpc_dw0_tmp2_4, mpc_dw0_nu0);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dy1, mpc_dw0_tmp2_8, mpc_dw0_y1);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dnu1, mpc_dw0_tmp2_8, mpc_dw0_nu1);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dy2, mpc_dw0_tmp1_8, mpc_dw0_y2);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dnu2, mpc_dw0_tmp1_8, mpc_dw0_nu2);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dy3, mpc_dw0_tmp2_8, mpc_dw0_y3);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dnu3, mpc_dw0_tmp2_8, mpc_dw0_nu3);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dy4, mpc_dw0_tmp1_8, mpc_dw0_y4);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dnu4, mpc_dw0_tmp1_8, mpc_dw0_nu4);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dy5, mpc_dw0_tmp2_8, mpc_dw0_y5);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dnu5, mpc_dw0_tmp2_8, mpc_dw0_nu5);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dy6, mpc_dw0_tmp1_8, mpc_dw0_y6);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dnu6, mpc_dw0_tmp1_8, mpc_dw0_nu6);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dy7, mpc_dw0_tmp2_8, mpc_dw0_y7);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dnu7, mpc_dw0_tmp2_8, mpc_dw0_nu7);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dy8, mpc_dw0_tmp1_8, mpc_dw0_y8);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dnu8, mpc_dw0_tmp1_8, mpc_dw0_nu8);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dy9, mpc_dw0_tmp2_8, mpc_dw0_y9);
mpc_dw0_v_init1_8(mpc_dw0_tmp1_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp2_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp1_8, mpc_dw0_tmp2_8);
mpc_dw0_vadd_8(mpc_dw0_dnu9, mpc_dw0_tmp2_8, mpc_dw0_nu9);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dy10, mpc_dw0_tmp1_8, mpc_dw0_y10);
mpc_dw0_v_init1_8(mpc_dw0_tmp2_8);
mpc_dw0_v_init0_8(mpc_dw0_tmp1_8);
mpc_dw0_sv_8(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_8, mpc_dw0_tmp1_8);
mpc_dw0_vadd_8(mpc_dw0_dnu10, mpc_dw0_tmp1_8, mpc_dw0_nu10);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_y, mpc_dw0_tmp2_4, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_dy11, mpc_dw0_tmp1_4, mpc_dw0_y11);
mpc_dw0_v_init1_4(mpc_dw0_tmp2_4);
mpc_dw0_v_init0_4(mpc_dw0_tmp1_4);
mpc_dw0_sv_4(mpc_dw0_starting_point_delta_nu, mpc_dw0_tmp2_4, mpc_dw0_tmp1_4);
mpc_dw0_vadd_4(mpc_dw0_dnu11, mpc_dw0_tmp1_4, mpc_dw0_nu11);
}


void mpc_dw0_glqdocpip_init()
{
/* ## Parameter INIT ##  */
/* Anzahl Ungleichungsbedingungen */
mpc_dw0_m_ineq[0] = 88;
/* Toleranz (Abbruchkriterium) */
mpc_dw0_tol[0] = 0.0001;
/* Mehrotra Gamma */
mpc_dw0_mehrotra_gamma[0] = 0.01;
/* Machine Epsilon */
/* Init Berechnung */
mpc_dw0_v_init0_1(mpc_dw0_tmp3_1);
mpc_dw0_tmp2_1[0] = 1;
mpc_dw0_tmp1_1[0] = 1.0f - mpc_dw0_tmp2_1[0]/2;
/* Berechnungsschleife: while((1-div/2)!=1){div = div/2} */
while(mpc_dw0_tmp1_1[0] != 1.0f){
mpc_dw0_tmp2_1[0] = mpc_dw0_tmp2_1[0]/2;
mpc_dw0_tmp1_1[0] = 1.0f - mpc_dw0_tmp2_1[0]/2;
mpc_dw0_tmp3_1[0] += 1;
if(mpc_dw0_tmp3_1[0] > 100){
mpc_dw0_termcode = 10;
return;
}
}
mpc_dw0_macheps[0] = mpc_dw0_tmp2_1[0];
/* tau */
mpc_dw0_tau[0] = 3;
/* termcode */
mpc_dw0_termcode = -1;
/* Error Line */
mpc_dw0_error_line = 0;
/* Error Source */
mpc_dw0_error_source = 0;
/* termcode 1 factor */
mpc_dw0_tc1_factor[0] = 10000;
/* termcode 2 factor */
mpc_dw0_tc2_factor[0] = 100000000;
/* tmax */
mpc_dw0_time_max = 1;
/* max_iter */
mpc_dw0_max_iter = 20;
/* num_iter_ref */
mpc_dw0_stat_num_iter_ref = 0;
/* num_factor */
mpc_dw0_stat_num_factor = 0;
/* num_solve */
mpc_dw0_stat_num_solve = 0;
}


int mpc_dw0_glqdocpip()
{

/* High Performance Timer (Windows) */
mpc_dw0_glqdocpip_timer_start();

/* Init */
mpc_dw0_glqdocpip_init();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Anfangsnorm bestimmen (norm_d) */
mpc_dw0_glqdocpip_calc_norm_d();

/* starting point */
mpc_dw0_glqdocpip_starting_point();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Main Iteration Loop */
for(mpc_dw0_iter = 0; mpc_dw0_iter < mpc_dw0_max_iter; mpc_dw0_iter++){

/* Predictor rhs berechnen */
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Konvergenz- und Divergenztests, inkl. Berechnung der dafür nötigen Parameter */
mpc_dw0_glqdocpip_calc_norm_r();
mpc_dw0_glqdocpip_calc_mu();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_calc_duality_gap();
mpc_dw0_glqdocpip_calc_phi();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_stat();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_check_condiv();
/* Bei entsprechendem Termcode Funktion beenden */
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Predictor GLS faktorisieren */
mpc_dw0_glqdocpip_factor();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Predictor GLS lösen */
mpc_dw0_glqdocpip_solve();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_dereduce();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_iter_ref();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Korrekturfaktor für CorrectorGLS berechnen, */
/* inkl der dafür nötigen Parameter */
mpc_dw0_glqdocpip_max_stepsize();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_calc_mu_aff();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_calc_sigma();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Corrector rhs berechnen */
mpc_dw0_glqdocpip_rhs_corrector();
mpc_dw0_glqdocpip_rhs_reduced();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Corrector GLS lösen */
mpc_dw0_glqdocpip_solve();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_dereduce();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_iter_ref();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}

/* Schritt berechnen und durchführen */
mpc_dw0_glqdocpip_max_stepsize();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_calc_mu_aff();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_mehrotra_step();
if(mpc_dw0_termcode > -1){return mpc_dw0_termcode;}
mpc_dw0_glqdocpip_step();

/* Ende - Main Iteration Loop */
}


/* Termcode 3: Max Iterations exceeded */
mpc_dw0_termcode = 3;
return mpc_dw0_termcode;
}


double mpc_dw0_glqdocpip_performance_test_1_iteration()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_calc_norm_d();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_iter = 1;

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_calc_norm_r();
mpc_dw0_glqdocpip_calc_mu();
mpc_dw0_glqdocpip_calc_duality_gap();
mpc_dw0_glqdocpip_calc_phi();
mpc_dw0_glqdocpip_stat();
mpc_dw0_termcode = -1;
mpc_dw0_glqdocpip_factor();
mpc_dw0_glqdocpip_solve();
mpc_dw0_glqdocpip_dereduce();
mpc_dw0_glqdocpip_max_stepsize();
mpc_dw0_glqdocpip_calc_mu_aff();
mpc_dw0_glqdocpip_calc_sigma();
mpc_dw0_glqdocpip_rhs_corrector();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_solve();
mpc_dw0_glqdocpip_dereduce();
mpc_dw0_glqdocpip_max_stepsize();
mpc_dw0_glqdocpip_calc_mu_aff();
mpc_dw0_glqdocpip_mehrotra_step();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_factor()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_factor();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_solve()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_factor();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_solve();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_affine()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_rhs_affine();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_reduced()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_glqdocpip_rhs_affine();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_rhs_reduced();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_dereduce()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_factor();
mpc_dw0_glqdocpip_solve();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_rhs_reduced();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_norm_r()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_calc_norm_r();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_structure_mult_m_fx0()
{
int i;
mpc_dw0_glqdocpip_init();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 1000; i++){
mpc_dw0_mm_sid1_sid42_6_6_6(mpc_dw0_Hxx0, mpc_dw0_fx0, mpc_dw0_Gxx0);
}
return mpc_dw0_glqdocpip_timer_get()/1000*1000;
}


double mpc_dw0_glqdocpip_performance_test_1_iteration_iterref()
{
int i;
mpc_dw0_glqdocpip_init();
mpc_dw0_glqdocpip_calc_norm_d();
mpc_dw0_glqdocpip_starting_point();
mpc_dw0_iter = 1;

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_rhs_affine();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_calc_norm_r();
mpc_dw0_glqdocpip_calc_mu();
mpc_dw0_glqdocpip_calc_duality_gap();
mpc_dw0_glqdocpip_calc_phi();
mpc_dw0_glqdocpip_stat();
mpc_dw0_termcode = -1;
mpc_dw0_iter_ref = 1;
mpc_dw0_glqdocpip_factor();
mpc_dw0_glqdocpip_solve();
mpc_dw0_glqdocpip_dereduce();
mpc_dw0_glqdocpip_iter_ref();
mpc_dw0_glqdocpip_max_stepsize();
mpc_dw0_glqdocpip_calc_mu_aff();
mpc_dw0_glqdocpip_calc_sigma();
mpc_dw0_glqdocpip_rhs_corrector();
mpc_dw0_glqdocpip_rhs_reduced();
mpc_dw0_glqdocpip_solve();
mpc_dw0_glqdocpip_dereduce();
mpc_dw0_glqdocpip_iter_ref();
mpc_dw0_glqdocpip_max_stepsize();
mpc_dw0_glqdocpip_calc_mu_aff();
mpc_dw0_glqdocpip_mehrotra_step();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}


double mpc_dw0_glqdocpip_performance_test_starting()
{
int i;
mpc_dw0_glqdocpip_init();

mpc_dw0_glqdocpip_timer_start();
for(i = 0; i < 10; i++){
mpc_dw0_glqdocpip_starting_point();
}
return mpc_dw0_glqdocpip_timer_get()/10*1000;
}
