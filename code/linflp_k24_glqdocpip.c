/* linflp_k24_glqdocpip.c */
/* Generiert: 22-Oct-2016 19:09:54 */


/* ########### */
/* # INCLUDE # */
/* ########### */
#include "float.h"
#include "math.h"

/* include für Timer (plattformabhängig) */
#if defined(__WIN32__) || defined(WIN32)
/*   Windows */
  #include "windows.h"
#endif


/* ######################## */
/* # Variablendeklaration # */
/* ######################## */
/* Anfangsbedingung */
static double linflp_k24_xinit[3];

/* Variablen für Disketisierungsstelle 0 */
/* Optimierungsvariablen */
static double linflp_k24_x0[3];
static double linflp_k24_u0[2];
static double linflp_k24_s0[1];
static double linflp_k24_p0[3];
static double linflp_k24_y0[10];
static double linflp_k24_nu0[10];
/* Schrittvariablen */
static double linflp_k24_dx0[3];
static double linflp_k24_du0[2];
static double linflp_k24_ds0[1];
static double linflp_k24_dp0[3];
static double linflp_k24_dy0[10];
static double linflp_k24_dnu0[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx0[9];
static double linflp_k24_Hxu0[6];
static double linflp_k24_Huu0[4];
static double linflp_k24_Hss0[1];
static double linflp_k24_f0x0[3];
static double linflp_k24_f0u0[2];
static double linflp_k24_f0s0[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx0[9];
static double linflp_k24_fu0[6];
static double linflp_k24_f0[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx0[30];
static double linflp_k24_gu0[20];
static double linflp_k24_g0[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x0[3];
static double linflp_k24_rf0u0[2];
static double linflp_k24_rf0s0[1];
static double linflp_k24_rf0[3];
static double linflp_k24_rc0[10];
static double linflp_k24_rs0[1];
static double linflp_k24_rk0[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x0[3];
static double linflp_k24_rrf0u0[2];
static double linflp_k24_rhsxs0[1];
static double linflp_k24_yny0[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx0[9];
static double linflp_k24_Gxu0[6];
static double linflp_k24_Guu0[4];
static double linflp_k24_Rux0[6];
static double linflp_k24_Vxx0[9];
static double linflp_k24_Gx0[3];
static double linflp_k24_Gu0[2];
static double linflp_k24_Ru0[2];
static double linflp_k24_Vx0[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir0[3];
static double linflp_k24_du_ir0[2];
static double linflp_k24_ds_ir0[1];
static double linflp_k24_dp_ir0[3];
static double linflp_k24_dy_ir0[10];
static double linflp_k24_dnu_ir0[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir0[3];
static double linflp_k24_rf0u_ir0[2];
static double linflp_k24_rf0s_ir0[1];
static double linflp_k24_rf_ir0[3];
static double linflp_k24_rc_ir0[10];
static double linflp_k24_rs_ir0[1];
static double linflp_k24_rk_ir0[10];

/* Variablen für Disketisierungsstelle 1 */
/* Optimierungsvariablen */
static double linflp_k24_x1[3];
static double linflp_k24_u1[2];
static double linflp_k24_s1[1];
static double linflp_k24_p1[3];
static double linflp_k24_y1[10];
static double linflp_k24_nu1[10];
/* Schrittvariablen */
static double linflp_k24_dx1[3];
static double linflp_k24_du1[2];
static double linflp_k24_ds1[1];
static double linflp_k24_dp1[3];
static double linflp_k24_dy1[10];
static double linflp_k24_dnu1[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx1[9];
static double linflp_k24_Hxu1[6];
static double linflp_k24_Huu1[4];
static double linflp_k24_Hss1[1];
static double linflp_k24_f0x1[3];
static double linflp_k24_f0u1[2];
static double linflp_k24_f0s1[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx1[9];
static double linflp_k24_fu1[6];
static double linflp_k24_f1[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx1[30];
static double linflp_k24_gu1[20];
static double linflp_k24_g1[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x1[3];
static double linflp_k24_rf0u1[2];
static double linflp_k24_rf0s1[1];
static double linflp_k24_rf1[3];
static double linflp_k24_rc1[10];
static double linflp_k24_rs1[1];
static double linflp_k24_rk1[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x1[3];
static double linflp_k24_rrf0u1[2];
static double linflp_k24_rhsxs1[1];
static double linflp_k24_yny1[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx1[9];
static double linflp_k24_Gxu1[6];
static double linflp_k24_Guu1[4];
static double linflp_k24_Rux1[6];
static double linflp_k24_Vxx1[9];
static double linflp_k24_Gx1[3];
static double linflp_k24_Gu1[2];
static double linflp_k24_Ru1[2];
static double linflp_k24_Vx1[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir1[3];
static double linflp_k24_du_ir1[2];
static double linflp_k24_ds_ir1[1];
static double linflp_k24_dp_ir1[3];
static double linflp_k24_dy_ir1[10];
static double linflp_k24_dnu_ir1[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir1[3];
static double linflp_k24_rf0u_ir1[2];
static double linflp_k24_rf0s_ir1[1];
static double linflp_k24_rf_ir1[3];
static double linflp_k24_rc_ir1[10];
static double linflp_k24_rs_ir1[1];
static double linflp_k24_rk_ir1[10];

/* Variablen für Disketisierungsstelle 2 */
/* Optimierungsvariablen */
static double linflp_k24_x2[3];
static double linflp_k24_u2[2];
static double linflp_k24_s2[1];
static double linflp_k24_p2[3];
static double linflp_k24_y2[10];
static double linflp_k24_nu2[10];
/* Schrittvariablen */
static double linflp_k24_dx2[3];
static double linflp_k24_du2[2];
static double linflp_k24_ds2[1];
static double linflp_k24_dp2[3];
static double linflp_k24_dy2[10];
static double linflp_k24_dnu2[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx2[9];
static double linflp_k24_Hxu2[6];
static double linflp_k24_Huu2[4];
static double linflp_k24_Hss2[1];
static double linflp_k24_f0x2[3];
static double linflp_k24_f0u2[2];
static double linflp_k24_f0s2[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx2[9];
static double linflp_k24_fu2[6];
static double linflp_k24_f2[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx2[30];
static double linflp_k24_gu2[20];
static double linflp_k24_g2[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x2[3];
static double linflp_k24_rf0u2[2];
static double linflp_k24_rf0s2[1];
static double linflp_k24_rf2[3];
static double linflp_k24_rc2[10];
static double linflp_k24_rs2[1];
static double linflp_k24_rk2[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x2[3];
static double linflp_k24_rrf0u2[2];
static double linflp_k24_rhsxs2[1];
static double linflp_k24_yny2[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx2[9];
static double linflp_k24_Gxu2[6];
static double linflp_k24_Guu2[4];
static double linflp_k24_Rux2[6];
static double linflp_k24_Vxx2[9];
static double linflp_k24_Gx2[3];
static double linflp_k24_Gu2[2];
static double linflp_k24_Ru2[2];
static double linflp_k24_Vx2[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir2[3];
static double linflp_k24_du_ir2[2];
static double linflp_k24_ds_ir2[1];
static double linflp_k24_dp_ir2[3];
static double linflp_k24_dy_ir2[10];
static double linflp_k24_dnu_ir2[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir2[3];
static double linflp_k24_rf0u_ir2[2];
static double linflp_k24_rf0s_ir2[1];
static double linflp_k24_rf_ir2[3];
static double linflp_k24_rc_ir2[10];
static double linflp_k24_rs_ir2[1];
static double linflp_k24_rk_ir2[10];

/* Variablen für Disketisierungsstelle 3 */
/* Optimierungsvariablen */
static double linflp_k24_x3[3];
static double linflp_k24_u3[2];
static double linflp_k24_s3[1];
static double linflp_k24_p3[3];
static double linflp_k24_y3[10];
static double linflp_k24_nu3[10];
/* Schrittvariablen */
static double linflp_k24_dx3[3];
static double linflp_k24_du3[2];
static double linflp_k24_ds3[1];
static double linflp_k24_dp3[3];
static double linflp_k24_dy3[10];
static double linflp_k24_dnu3[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx3[9];
static double linflp_k24_Hxu3[6];
static double linflp_k24_Huu3[4];
static double linflp_k24_Hss3[1];
static double linflp_k24_f0x3[3];
static double linflp_k24_f0u3[2];
static double linflp_k24_f0s3[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx3[9];
static double linflp_k24_fu3[6];
static double linflp_k24_f3[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx3[30];
static double linflp_k24_gu3[20];
static double linflp_k24_g3[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x3[3];
static double linflp_k24_rf0u3[2];
static double linflp_k24_rf0s3[1];
static double linflp_k24_rf3[3];
static double linflp_k24_rc3[10];
static double linflp_k24_rs3[1];
static double linflp_k24_rk3[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x3[3];
static double linflp_k24_rrf0u3[2];
static double linflp_k24_rhsxs3[1];
static double linflp_k24_yny3[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx3[9];
static double linflp_k24_Gxu3[6];
static double linflp_k24_Guu3[4];
static double linflp_k24_Rux3[6];
static double linflp_k24_Vxx3[9];
static double linflp_k24_Gx3[3];
static double linflp_k24_Gu3[2];
static double linflp_k24_Ru3[2];
static double linflp_k24_Vx3[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir3[3];
static double linflp_k24_du_ir3[2];
static double linflp_k24_ds_ir3[1];
static double linflp_k24_dp_ir3[3];
static double linflp_k24_dy_ir3[10];
static double linflp_k24_dnu_ir3[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir3[3];
static double linflp_k24_rf0u_ir3[2];
static double linflp_k24_rf0s_ir3[1];
static double linflp_k24_rf_ir3[3];
static double linflp_k24_rc_ir3[10];
static double linflp_k24_rs_ir3[1];
static double linflp_k24_rk_ir3[10];

/* Variablen für Disketisierungsstelle 4 */
/* Optimierungsvariablen */
static double linflp_k24_x4[3];
static double linflp_k24_u4[2];
static double linflp_k24_s4[1];
static double linflp_k24_p4[3];
static double linflp_k24_y4[10];
static double linflp_k24_nu4[10];
/* Schrittvariablen */
static double linflp_k24_dx4[3];
static double linflp_k24_du4[2];
static double linflp_k24_ds4[1];
static double linflp_k24_dp4[3];
static double linflp_k24_dy4[10];
static double linflp_k24_dnu4[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx4[9];
static double linflp_k24_Hxu4[6];
static double linflp_k24_Huu4[4];
static double linflp_k24_Hss4[1];
static double linflp_k24_f0x4[3];
static double linflp_k24_f0u4[2];
static double linflp_k24_f0s4[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx4[9];
static double linflp_k24_fu4[6];
static double linflp_k24_f4[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx4[30];
static double linflp_k24_gu4[20];
static double linflp_k24_g4[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x4[3];
static double linflp_k24_rf0u4[2];
static double linflp_k24_rf0s4[1];
static double linflp_k24_rf4[3];
static double linflp_k24_rc4[10];
static double linflp_k24_rs4[1];
static double linflp_k24_rk4[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x4[3];
static double linflp_k24_rrf0u4[2];
static double linflp_k24_rhsxs4[1];
static double linflp_k24_yny4[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx4[9];
static double linflp_k24_Gxu4[6];
static double linflp_k24_Guu4[4];
static double linflp_k24_Rux4[6];
static double linflp_k24_Vxx4[9];
static double linflp_k24_Gx4[3];
static double linflp_k24_Gu4[2];
static double linflp_k24_Ru4[2];
static double linflp_k24_Vx4[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir4[3];
static double linflp_k24_du_ir4[2];
static double linflp_k24_ds_ir4[1];
static double linflp_k24_dp_ir4[3];
static double linflp_k24_dy_ir4[10];
static double linflp_k24_dnu_ir4[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir4[3];
static double linflp_k24_rf0u_ir4[2];
static double linflp_k24_rf0s_ir4[1];
static double linflp_k24_rf_ir4[3];
static double linflp_k24_rc_ir4[10];
static double linflp_k24_rs_ir4[1];
static double linflp_k24_rk_ir4[10];

/* Variablen für Disketisierungsstelle 5 */
/* Optimierungsvariablen */
static double linflp_k24_x5[3];
static double linflp_k24_u5[2];
static double linflp_k24_s5[1];
static double linflp_k24_p5[3];
static double linflp_k24_y5[10];
static double linflp_k24_nu5[10];
/* Schrittvariablen */
static double linflp_k24_dx5[3];
static double linflp_k24_du5[2];
static double linflp_k24_ds5[1];
static double linflp_k24_dp5[3];
static double linflp_k24_dy5[10];
static double linflp_k24_dnu5[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx5[9];
static double linflp_k24_Hxu5[6];
static double linflp_k24_Huu5[4];
static double linflp_k24_Hss5[1];
static double linflp_k24_f0x5[3];
static double linflp_k24_f0u5[2];
static double linflp_k24_f0s5[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx5[9];
static double linflp_k24_fu5[6];
static double linflp_k24_f5[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx5[30];
static double linflp_k24_gu5[20];
static double linflp_k24_g5[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x5[3];
static double linflp_k24_rf0u5[2];
static double linflp_k24_rf0s5[1];
static double linflp_k24_rf5[3];
static double linflp_k24_rc5[10];
static double linflp_k24_rs5[1];
static double linflp_k24_rk5[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x5[3];
static double linflp_k24_rrf0u5[2];
static double linflp_k24_rhsxs5[1];
static double linflp_k24_yny5[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx5[9];
static double linflp_k24_Gxu5[6];
static double linflp_k24_Guu5[4];
static double linflp_k24_Rux5[6];
static double linflp_k24_Vxx5[9];
static double linflp_k24_Gx5[3];
static double linflp_k24_Gu5[2];
static double linflp_k24_Ru5[2];
static double linflp_k24_Vx5[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir5[3];
static double linflp_k24_du_ir5[2];
static double linflp_k24_ds_ir5[1];
static double linflp_k24_dp_ir5[3];
static double linflp_k24_dy_ir5[10];
static double linflp_k24_dnu_ir5[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir5[3];
static double linflp_k24_rf0u_ir5[2];
static double linflp_k24_rf0s_ir5[1];
static double linflp_k24_rf_ir5[3];
static double linflp_k24_rc_ir5[10];
static double linflp_k24_rs_ir5[1];
static double linflp_k24_rk_ir5[10];

/* Variablen für Disketisierungsstelle 6 */
/* Optimierungsvariablen */
static double linflp_k24_x6[3];
static double linflp_k24_u6[2];
static double linflp_k24_s6[1];
static double linflp_k24_p6[3];
static double linflp_k24_y6[10];
static double linflp_k24_nu6[10];
/* Schrittvariablen */
static double linflp_k24_dx6[3];
static double linflp_k24_du6[2];
static double linflp_k24_ds6[1];
static double linflp_k24_dp6[3];
static double linflp_k24_dy6[10];
static double linflp_k24_dnu6[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx6[9];
static double linflp_k24_Hxu6[6];
static double linflp_k24_Huu6[4];
static double linflp_k24_Hss6[1];
static double linflp_k24_f0x6[3];
static double linflp_k24_f0u6[2];
static double linflp_k24_f0s6[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx6[9];
static double linflp_k24_fu6[6];
static double linflp_k24_f6[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx6[30];
static double linflp_k24_gu6[20];
static double linflp_k24_g6[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x6[3];
static double linflp_k24_rf0u6[2];
static double linflp_k24_rf0s6[1];
static double linflp_k24_rf6[3];
static double linflp_k24_rc6[10];
static double linflp_k24_rs6[1];
static double linflp_k24_rk6[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x6[3];
static double linflp_k24_rrf0u6[2];
static double linflp_k24_rhsxs6[1];
static double linflp_k24_yny6[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx6[9];
static double linflp_k24_Gxu6[6];
static double linflp_k24_Guu6[4];
static double linflp_k24_Rux6[6];
static double linflp_k24_Vxx6[9];
static double linflp_k24_Gx6[3];
static double linflp_k24_Gu6[2];
static double linflp_k24_Ru6[2];
static double linflp_k24_Vx6[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir6[3];
static double linflp_k24_du_ir6[2];
static double linflp_k24_ds_ir6[1];
static double linflp_k24_dp_ir6[3];
static double linflp_k24_dy_ir6[10];
static double linflp_k24_dnu_ir6[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir6[3];
static double linflp_k24_rf0u_ir6[2];
static double linflp_k24_rf0s_ir6[1];
static double linflp_k24_rf_ir6[3];
static double linflp_k24_rc_ir6[10];
static double linflp_k24_rs_ir6[1];
static double linflp_k24_rk_ir6[10];

/* Variablen für Disketisierungsstelle 7 */
/* Optimierungsvariablen */
static double linflp_k24_x7[3];
static double linflp_k24_u7[2];
static double linflp_k24_s7[1];
static double linflp_k24_p7[3];
static double linflp_k24_y7[10];
static double linflp_k24_nu7[10];
/* Schrittvariablen */
static double linflp_k24_dx7[3];
static double linflp_k24_du7[2];
static double linflp_k24_ds7[1];
static double linflp_k24_dp7[3];
static double linflp_k24_dy7[10];
static double linflp_k24_dnu7[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx7[9];
static double linflp_k24_Hxu7[6];
static double linflp_k24_Huu7[4];
static double linflp_k24_Hss7[1];
static double linflp_k24_f0x7[3];
static double linflp_k24_f0u7[2];
static double linflp_k24_f0s7[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx7[9];
static double linflp_k24_fu7[6];
static double linflp_k24_f7[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx7[30];
static double linflp_k24_gu7[20];
static double linflp_k24_g7[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x7[3];
static double linflp_k24_rf0u7[2];
static double linflp_k24_rf0s7[1];
static double linflp_k24_rf7[3];
static double linflp_k24_rc7[10];
static double linflp_k24_rs7[1];
static double linflp_k24_rk7[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x7[3];
static double linflp_k24_rrf0u7[2];
static double linflp_k24_rhsxs7[1];
static double linflp_k24_yny7[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx7[9];
static double linflp_k24_Gxu7[6];
static double linflp_k24_Guu7[4];
static double linflp_k24_Rux7[6];
static double linflp_k24_Vxx7[9];
static double linflp_k24_Gx7[3];
static double linflp_k24_Gu7[2];
static double linflp_k24_Ru7[2];
static double linflp_k24_Vx7[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir7[3];
static double linflp_k24_du_ir7[2];
static double linflp_k24_ds_ir7[1];
static double linflp_k24_dp_ir7[3];
static double linflp_k24_dy_ir7[10];
static double linflp_k24_dnu_ir7[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir7[3];
static double linflp_k24_rf0u_ir7[2];
static double linflp_k24_rf0s_ir7[1];
static double linflp_k24_rf_ir7[3];
static double linflp_k24_rc_ir7[10];
static double linflp_k24_rs_ir7[1];
static double linflp_k24_rk_ir7[10];

/* Variablen für Disketisierungsstelle 8 */
/* Optimierungsvariablen */
static double linflp_k24_x8[3];
static double linflp_k24_u8[2];
static double linflp_k24_s8[1];
static double linflp_k24_p8[3];
static double linflp_k24_y8[10];
static double linflp_k24_nu8[10];
/* Schrittvariablen */
static double linflp_k24_dx8[3];
static double linflp_k24_du8[2];
static double linflp_k24_ds8[1];
static double linflp_k24_dp8[3];
static double linflp_k24_dy8[10];
static double linflp_k24_dnu8[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx8[9];
static double linflp_k24_Hxu8[6];
static double linflp_k24_Huu8[4];
static double linflp_k24_Hss8[1];
static double linflp_k24_f0x8[3];
static double linflp_k24_f0u8[2];
static double linflp_k24_f0s8[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx8[9];
static double linflp_k24_fu8[6];
static double linflp_k24_f8[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx8[30];
static double linflp_k24_gu8[20];
static double linflp_k24_g8[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x8[3];
static double linflp_k24_rf0u8[2];
static double linflp_k24_rf0s8[1];
static double linflp_k24_rf8[3];
static double linflp_k24_rc8[10];
static double linflp_k24_rs8[1];
static double linflp_k24_rk8[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x8[3];
static double linflp_k24_rrf0u8[2];
static double linflp_k24_rhsxs8[1];
static double linflp_k24_yny8[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx8[9];
static double linflp_k24_Gxu8[6];
static double linflp_k24_Guu8[4];
static double linflp_k24_Rux8[6];
static double linflp_k24_Vxx8[9];
static double linflp_k24_Gx8[3];
static double linflp_k24_Gu8[2];
static double linflp_k24_Ru8[2];
static double linflp_k24_Vx8[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir8[3];
static double linflp_k24_du_ir8[2];
static double linflp_k24_ds_ir8[1];
static double linflp_k24_dp_ir8[3];
static double linflp_k24_dy_ir8[10];
static double linflp_k24_dnu_ir8[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir8[3];
static double linflp_k24_rf0u_ir8[2];
static double linflp_k24_rf0s_ir8[1];
static double linflp_k24_rf_ir8[3];
static double linflp_k24_rc_ir8[10];
static double linflp_k24_rs_ir8[1];
static double linflp_k24_rk_ir8[10];

/* Variablen für Disketisierungsstelle 9 */
/* Optimierungsvariablen */
static double linflp_k24_x9[3];
static double linflp_k24_u9[2];
static double linflp_k24_s9[1];
static double linflp_k24_p9[3];
static double linflp_k24_y9[10];
static double linflp_k24_nu9[10];
/* Schrittvariablen */
static double linflp_k24_dx9[3];
static double linflp_k24_du9[2];
static double linflp_k24_ds9[1];
static double linflp_k24_dp9[3];
static double linflp_k24_dy9[10];
static double linflp_k24_dnu9[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx9[9];
static double linflp_k24_Hxu9[6];
static double linflp_k24_Huu9[4];
static double linflp_k24_Hss9[1];
static double linflp_k24_f0x9[3];
static double linflp_k24_f0u9[2];
static double linflp_k24_f0s9[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx9[9];
static double linflp_k24_fu9[6];
static double linflp_k24_f9[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx9[30];
static double linflp_k24_gu9[20];
static double linflp_k24_g9[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x9[3];
static double linflp_k24_rf0u9[2];
static double linflp_k24_rf0s9[1];
static double linflp_k24_rf9[3];
static double linflp_k24_rc9[10];
static double linflp_k24_rs9[1];
static double linflp_k24_rk9[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x9[3];
static double linflp_k24_rrf0u9[2];
static double linflp_k24_rhsxs9[1];
static double linflp_k24_yny9[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx9[9];
static double linflp_k24_Gxu9[6];
static double linflp_k24_Guu9[4];
static double linflp_k24_Rux9[6];
static double linflp_k24_Vxx9[9];
static double linflp_k24_Gx9[3];
static double linflp_k24_Gu9[2];
static double linflp_k24_Ru9[2];
static double linflp_k24_Vx9[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir9[3];
static double linflp_k24_du_ir9[2];
static double linflp_k24_ds_ir9[1];
static double linflp_k24_dp_ir9[3];
static double linflp_k24_dy_ir9[10];
static double linflp_k24_dnu_ir9[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir9[3];
static double linflp_k24_rf0u_ir9[2];
static double linflp_k24_rf0s_ir9[1];
static double linflp_k24_rf_ir9[3];
static double linflp_k24_rc_ir9[10];
static double linflp_k24_rs_ir9[1];
static double linflp_k24_rk_ir9[10];

/* Variablen für Disketisierungsstelle 10 */
/* Optimierungsvariablen */
static double linflp_k24_x10[3];
static double linflp_k24_u10[2];
static double linflp_k24_s10[1];
static double linflp_k24_p10[3];
static double linflp_k24_y10[10];
static double linflp_k24_nu10[10];
/* Schrittvariablen */
static double linflp_k24_dx10[3];
static double linflp_k24_du10[2];
static double linflp_k24_ds10[1];
static double linflp_k24_dp10[3];
static double linflp_k24_dy10[10];
static double linflp_k24_dnu10[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx10[9];
static double linflp_k24_Hxu10[6];
static double linflp_k24_Huu10[4];
static double linflp_k24_Hss10[1];
static double linflp_k24_f0x10[3];
static double linflp_k24_f0u10[2];
static double linflp_k24_f0s10[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx10[9];
static double linflp_k24_fu10[6];
static double linflp_k24_f10[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx10[30];
static double linflp_k24_gu10[20];
static double linflp_k24_g10[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x10[3];
static double linflp_k24_rf0u10[2];
static double linflp_k24_rf0s10[1];
static double linflp_k24_rf10[3];
static double linflp_k24_rc10[10];
static double linflp_k24_rs10[1];
static double linflp_k24_rk10[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x10[3];
static double linflp_k24_rrf0u10[2];
static double linflp_k24_rhsxs10[1];
static double linflp_k24_yny10[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx10[9];
static double linflp_k24_Gxu10[6];
static double linflp_k24_Guu10[4];
static double linflp_k24_Rux10[6];
static double linflp_k24_Vxx10[9];
static double linflp_k24_Gx10[3];
static double linflp_k24_Gu10[2];
static double linflp_k24_Ru10[2];
static double linflp_k24_Vx10[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir10[3];
static double linflp_k24_du_ir10[2];
static double linflp_k24_ds_ir10[1];
static double linflp_k24_dp_ir10[3];
static double linflp_k24_dy_ir10[10];
static double linflp_k24_dnu_ir10[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir10[3];
static double linflp_k24_rf0u_ir10[2];
static double linflp_k24_rf0s_ir10[1];
static double linflp_k24_rf_ir10[3];
static double linflp_k24_rc_ir10[10];
static double linflp_k24_rs_ir10[1];
static double linflp_k24_rk_ir10[10];

/* Variablen für Disketisierungsstelle 11 */
/* Optimierungsvariablen */
static double linflp_k24_x11[3];
static double linflp_k24_u11[2];
static double linflp_k24_s11[1];
static double linflp_k24_p11[3];
static double linflp_k24_y11[10];
static double linflp_k24_nu11[10];
/* Schrittvariablen */
static double linflp_k24_dx11[3];
static double linflp_k24_du11[2];
static double linflp_k24_ds11[1];
static double linflp_k24_dp11[3];
static double linflp_k24_dy11[10];
static double linflp_k24_dnu11[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx11[9];
static double linflp_k24_Hxu11[6];
static double linflp_k24_Huu11[4];
static double linflp_k24_Hss11[1];
static double linflp_k24_f0x11[3];
static double linflp_k24_f0u11[2];
static double linflp_k24_f0s11[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx11[9];
static double linflp_k24_fu11[6];
static double linflp_k24_f11[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx11[30];
static double linflp_k24_gu11[20];
static double linflp_k24_g11[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x11[3];
static double linflp_k24_rf0u11[2];
static double linflp_k24_rf0s11[1];
static double linflp_k24_rf11[3];
static double linflp_k24_rc11[10];
static double linflp_k24_rs11[1];
static double linflp_k24_rk11[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x11[3];
static double linflp_k24_rrf0u11[2];
static double linflp_k24_rhsxs11[1];
static double linflp_k24_yny11[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx11[9];
static double linflp_k24_Gxu11[6];
static double linflp_k24_Guu11[4];
static double linflp_k24_Rux11[6];
static double linflp_k24_Vxx11[9];
static double linflp_k24_Gx11[3];
static double linflp_k24_Gu11[2];
static double linflp_k24_Ru11[2];
static double linflp_k24_Vx11[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir11[3];
static double linflp_k24_du_ir11[2];
static double linflp_k24_ds_ir11[1];
static double linflp_k24_dp_ir11[3];
static double linflp_k24_dy_ir11[10];
static double linflp_k24_dnu_ir11[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir11[3];
static double linflp_k24_rf0u_ir11[2];
static double linflp_k24_rf0s_ir11[1];
static double linflp_k24_rf_ir11[3];
static double linflp_k24_rc_ir11[10];
static double linflp_k24_rs_ir11[1];
static double linflp_k24_rk_ir11[10];

/* Variablen für Disketisierungsstelle 12 */
/* Optimierungsvariablen */
static double linflp_k24_x12[3];
static double linflp_k24_u12[2];
static double linflp_k24_s12[1];
static double linflp_k24_p12[3];
static double linflp_k24_y12[10];
static double linflp_k24_nu12[10];
/* Schrittvariablen */
static double linflp_k24_dx12[3];
static double linflp_k24_du12[2];
static double linflp_k24_ds12[1];
static double linflp_k24_dp12[3];
static double linflp_k24_dy12[10];
static double linflp_k24_dnu12[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx12[9];
static double linflp_k24_Hxu12[6];
static double linflp_k24_Huu12[4];
static double linflp_k24_Hss12[1];
static double linflp_k24_f0x12[3];
static double linflp_k24_f0u12[2];
static double linflp_k24_f0s12[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx12[9];
static double linflp_k24_fu12[6];
static double linflp_k24_f12[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx12[30];
static double linflp_k24_gu12[20];
static double linflp_k24_g12[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x12[3];
static double linflp_k24_rf0u12[2];
static double linflp_k24_rf0s12[1];
static double linflp_k24_rf12[3];
static double linflp_k24_rc12[10];
static double linflp_k24_rs12[1];
static double linflp_k24_rk12[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x12[3];
static double linflp_k24_rrf0u12[2];
static double linflp_k24_rhsxs12[1];
static double linflp_k24_yny12[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx12[9];
static double linflp_k24_Gxu12[6];
static double linflp_k24_Guu12[4];
static double linflp_k24_Rux12[6];
static double linflp_k24_Vxx12[9];
static double linflp_k24_Gx12[3];
static double linflp_k24_Gu12[2];
static double linflp_k24_Ru12[2];
static double linflp_k24_Vx12[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir12[3];
static double linflp_k24_du_ir12[2];
static double linflp_k24_ds_ir12[1];
static double linflp_k24_dp_ir12[3];
static double linflp_k24_dy_ir12[10];
static double linflp_k24_dnu_ir12[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir12[3];
static double linflp_k24_rf0u_ir12[2];
static double linflp_k24_rf0s_ir12[1];
static double linflp_k24_rf_ir12[3];
static double linflp_k24_rc_ir12[10];
static double linflp_k24_rs_ir12[1];
static double linflp_k24_rk_ir12[10];

/* Variablen für Disketisierungsstelle 13 */
/* Optimierungsvariablen */
static double linflp_k24_x13[3];
static double linflp_k24_u13[2];
static double linflp_k24_s13[1];
static double linflp_k24_p13[3];
static double linflp_k24_y13[10];
static double linflp_k24_nu13[10];
/* Schrittvariablen */
static double linflp_k24_dx13[3];
static double linflp_k24_du13[2];
static double linflp_k24_ds13[1];
static double linflp_k24_dp13[3];
static double linflp_k24_dy13[10];
static double linflp_k24_dnu13[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx13[9];
static double linflp_k24_Hxu13[6];
static double linflp_k24_Huu13[4];
static double linflp_k24_Hss13[1];
static double linflp_k24_f0x13[3];
static double linflp_k24_f0u13[2];
static double linflp_k24_f0s13[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx13[9];
static double linflp_k24_fu13[6];
static double linflp_k24_f13[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx13[30];
static double linflp_k24_gu13[20];
static double linflp_k24_g13[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x13[3];
static double linflp_k24_rf0u13[2];
static double linflp_k24_rf0s13[1];
static double linflp_k24_rf13[3];
static double linflp_k24_rc13[10];
static double linflp_k24_rs13[1];
static double linflp_k24_rk13[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x13[3];
static double linflp_k24_rrf0u13[2];
static double linflp_k24_rhsxs13[1];
static double linflp_k24_yny13[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx13[9];
static double linflp_k24_Gxu13[6];
static double linflp_k24_Guu13[4];
static double linflp_k24_Rux13[6];
static double linflp_k24_Vxx13[9];
static double linflp_k24_Gx13[3];
static double linflp_k24_Gu13[2];
static double linflp_k24_Ru13[2];
static double linflp_k24_Vx13[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir13[3];
static double linflp_k24_du_ir13[2];
static double linflp_k24_ds_ir13[1];
static double linflp_k24_dp_ir13[3];
static double linflp_k24_dy_ir13[10];
static double linflp_k24_dnu_ir13[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir13[3];
static double linflp_k24_rf0u_ir13[2];
static double linflp_k24_rf0s_ir13[1];
static double linflp_k24_rf_ir13[3];
static double linflp_k24_rc_ir13[10];
static double linflp_k24_rs_ir13[1];
static double linflp_k24_rk_ir13[10];

/* Variablen für Disketisierungsstelle 14 */
/* Optimierungsvariablen */
static double linflp_k24_x14[3];
static double linflp_k24_u14[2];
static double linflp_k24_s14[1];
static double linflp_k24_p14[3];
static double linflp_k24_y14[10];
static double linflp_k24_nu14[10];
/* Schrittvariablen */
static double linflp_k24_dx14[3];
static double linflp_k24_du14[2];
static double linflp_k24_ds14[1];
static double linflp_k24_dp14[3];
static double linflp_k24_dy14[10];
static double linflp_k24_dnu14[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx14[9];
static double linflp_k24_Hxu14[6];
static double linflp_k24_Huu14[4];
static double linflp_k24_Hss14[1];
static double linflp_k24_f0x14[3];
static double linflp_k24_f0u14[2];
static double linflp_k24_f0s14[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx14[9];
static double linflp_k24_fu14[6];
static double linflp_k24_f14[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx14[30];
static double linflp_k24_gu14[20];
static double linflp_k24_g14[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x14[3];
static double linflp_k24_rf0u14[2];
static double linflp_k24_rf0s14[1];
static double linflp_k24_rf14[3];
static double linflp_k24_rc14[10];
static double linflp_k24_rs14[1];
static double linflp_k24_rk14[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x14[3];
static double linflp_k24_rrf0u14[2];
static double linflp_k24_rhsxs14[1];
static double linflp_k24_yny14[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx14[9];
static double linflp_k24_Gxu14[6];
static double linflp_k24_Guu14[4];
static double linflp_k24_Rux14[6];
static double linflp_k24_Vxx14[9];
static double linflp_k24_Gx14[3];
static double linflp_k24_Gu14[2];
static double linflp_k24_Ru14[2];
static double linflp_k24_Vx14[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir14[3];
static double linflp_k24_du_ir14[2];
static double linflp_k24_ds_ir14[1];
static double linflp_k24_dp_ir14[3];
static double linflp_k24_dy_ir14[10];
static double linflp_k24_dnu_ir14[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir14[3];
static double linflp_k24_rf0u_ir14[2];
static double linflp_k24_rf0s_ir14[1];
static double linflp_k24_rf_ir14[3];
static double linflp_k24_rc_ir14[10];
static double linflp_k24_rs_ir14[1];
static double linflp_k24_rk_ir14[10];

/* Variablen für Disketisierungsstelle 15 */
/* Optimierungsvariablen */
static double linflp_k24_x15[3];
static double linflp_k24_u15[2];
static double linflp_k24_s15[1];
static double linflp_k24_p15[3];
static double linflp_k24_y15[10];
static double linflp_k24_nu15[10];
/* Schrittvariablen */
static double linflp_k24_dx15[3];
static double linflp_k24_du15[2];
static double linflp_k24_ds15[1];
static double linflp_k24_dp15[3];
static double linflp_k24_dy15[10];
static double linflp_k24_dnu15[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx15[9];
static double linflp_k24_Hxu15[6];
static double linflp_k24_Huu15[4];
static double linflp_k24_Hss15[1];
static double linflp_k24_f0x15[3];
static double linflp_k24_f0u15[2];
static double linflp_k24_f0s15[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx15[9];
static double linflp_k24_fu15[6];
static double linflp_k24_f15[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx15[30];
static double linflp_k24_gu15[20];
static double linflp_k24_g15[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x15[3];
static double linflp_k24_rf0u15[2];
static double linflp_k24_rf0s15[1];
static double linflp_k24_rf15[3];
static double linflp_k24_rc15[10];
static double linflp_k24_rs15[1];
static double linflp_k24_rk15[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x15[3];
static double linflp_k24_rrf0u15[2];
static double linflp_k24_rhsxs15[1];
static double linflp_k24_yny15[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx15[9];
static double linflp_k24_Gxu15[6];
static double linflp_k24_Guu15[4];
static double linflp_k24_Rux15[6];
static double linflp_k24_Vxx15[9];
static double linflp_k24_Gx15[3];
static double linflp_k24_Gu15[2];
static double linflp_k24_Ru15[2];
static double linflp_k24_Vx15[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir15[3];
static double linflp_k24_du_ir15[2];
static double linflp_k24_ds_ir15[1];
static double linflp_k24_dp_ir15[3];
static double linflp_k24_dy_ir15[10];
static double linflp_k24_dnu_ir15[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir15[3];
static double linflp_k24_rf0u_ir15[2];
static double linflp_k24_rf0s_ir15[1];
static double linflp_k24_rf_ir15[3];
static double linflp_k24_rc_ir15[10];
static double linflp_k24_rs_ir15[1];
static double linflp_k24_rk_ir15[10];

/* Variablen für Disketisierungsstelle 16 */
/* Optimierungsvariablen */
static double linflp_k24_x16[3];
static double linflp_k24_u16[2];
static double linflp_k24_s16[1];
static double linflp_k24_p16[3];
static double linflp_k24_y16[10];
static double linflp_k24_nu16[10];
/* Schrittvariablen */
static double linflp_k24_dx16[3];
static double linflp_k24_du16[2];
static double linflp_k24_ds16[1];
static double linflp_k24_dp16[3];
static double linflp_k24_dy16[10];
static double linflp_k24_dnu16[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx16[9];
static double linflp_k24_Hxu16[6];
static double linflp_k24_Huu16[4];
static double linflp_k24_Hss16[1];
static double linflp_k24_f0x16[3];
static double linflp_k24_f0u16[2];
static double linflp_k24_f0s16[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx16[9];
static double linflp_k24_fu16[6];
static double linflp_k24_f16[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx16[30];
static double linflp_k24_gu16[20];
static double linflp_k24_g16[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x16[3];
static double linflp_k24_rf0u16[2];
static double linflp_k24_rf0s16[1];
static double linflp_k24_rf16[3];
static double linflp_k24_rc16[10];
static double linflp_k24_rs16[1];
static double linflp_k24_rk16[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x16[3];
static double linflp_k24_rrf0u16[2];
static double linflp_k24_rhsxs16[1];
static double linflp_k24_yny16[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx16[9];
static double linflp_k24_Gxu16[6];
static double linflp_k24_Guu16[4];
static double linflp_k24_Rux16[6];
static double linflp_k24_Vxx16[9];
static double linflp_k24_Gx16[3];
static double linflp_k24_Gu16[2];
static double linflp_k24_Ru16[2];
static double linflp_k24_Vx16[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir16[3];
static double linflp_k24_du_ir16[2];
static double linflp_k24_ds_ir16[1];
static double linflp_k24_dp_ir16[3];
static double linflp_k24_dy_ir16[10];
static double linflp_k24_dnu_ir16[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir16[3];
static double linflp_k24_rf0u_ir16[2];
static double linflp_k24_rf0s_ir16[1];
static double linflp_k24_rf_ir16[3];
static double linflp_k24_rc_ir16[10];
static double linflp_k24_rs_ir16[1];
static double linflp_k24_rk_ir16[10];

/* Variablen für Disketisierungsstelle 17 */
/* Optimierungsvariablen */
static double linflp_k24_x17[3];
static double linflp_k24_u17[2];
static double linflp_k24_s17[1];
static double linflp_k24_p17[3];
static double linflp_k24_y17[10];
static double linflp_k24_nu17[10];
/* Schrittvariablen */
static double linflp_k24_dx17[3];
static double linflp_k24_du17[2];
static double linflp_k24_ds17[1];
static double linflp_k24_dp17[3];
static double linflp_k24_dy17[10];
static double linflp_k24_dnu17[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx17[9];
static double linflp_k24_Hxu17[6];
static double linflp_k24_Huu17[4];
static double linflp_k24_Hss17[1];
static double linflp_k24_f0x17[3];
static double linflp_k24_f0u17[2];
static double linflp_k24_f0s17[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx17[9];
static double linflp_k24_fu17[6];
static double linflp_k24_f17[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx17[30];
static double linflp_k24_gu17[20];
static double linflp_k24_g17[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x17[3];
static double linflp_k24_rf0u17[2];
static double linflp_k24_rf0s17[1];
static double linflp_k24_rf17[3];
static double linflp_k24_rc17[10];
static double linflp_k24_rs17[1];
static double linflp_k24_rk17[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x17[3];
static double linflp_k24_rrf0u17[2];
static double linflp_k24_rhsxs17[1];
static double linflp_k24_yny17[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx17[9];
static double linflp_k24_Gxu17[6];
static double linflp_k24_Guu17[4];
static double linflp_k24_Rux17[6];
static double linflp_k24_Vxx17[9];
static double linflp_k24_Gx17[3];
static double linflp_k24_Gu17[2];
static double linflp_k24_Ru17[2];
static double linflp_k24_Vx17[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir17[3];
static double linflp_k24_du_ir17[2];
static double linflp_k24_ds_ir17[1];
static double linflp_k24_dp_ir17[3];
static double linflp_k24_dy_ir17[10];
static double linflp_k24_dnu_ir17[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir17[3];
static double linflp_k24_rf0u_ir17[2];
static double linflp_k24_rf0s_ir17[1];
static double linflp_k24_rf_ir17[3];
static double linflp_k24_rc_ir17[10];
static double linflp_k24_rs_ir17[1];
static double linflp_k24_rk_ir17[10];

/* Variablen für Disketisierungsstelle 18 */
/* Optimierungsvariablen */
static double linflp_k24_x18[3];
static double linflp_k24_u18[2];
static double linflp_k24_s18[1];
static double linflp_k24_p18[3];
static double linflp_k24_y18[10];
static double linflp_k24_nu18[10];
/* Schrittvariablen */
static double linflp_k24_dx18[3];
static double linflp_k24_du18[2];
static double linflp_k24_ds18[1];
static double linflp_k24_dp18[3];
static double linflp_k24_dy18[10];
static double linflp_k24_dnu18[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx18[9];
static double linflp_k24_Hxu18[6];
static double linflp_k24_Huu18[4];
static double linflp_k24_Hss18[1];
static double linflp_k24_f0x18[3];
static double linflp_k24_f0u18[2];
static double linflp_k24_f0s18[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx18[9];
static double linflp_k24_fu18[6];
static double linflp_k24_f18[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx18[30];
static double linflp_k24_gu18[20];
static double linflp_k24_g18[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x18[3];
static double linflp_k24_rf0u18[2];
static double linflp_k24_rf0s18[1];
static double linflp_k24_rf18[3];
static double linflp_k24_rc18[10];
static double linflp_k24_rs18[1];
static double linflp_k24_rk18[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x18[3];
static double linflp_k24_rrf0u18[2];
static double linflp_k24_rhsxs18[1];
static double linflp_k24_yny18[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx18[9];
static double linflp_k24_Gxu18[6];
static double linflp_k24_Guu18[4];
static double linflp_k24_Rux18[6];
static double linflp_k24_Vxx18[9];
static double linflp_k24_Gx18[3];
static double linflp_k24_Gu18[2];
static double linflp_k24_Ru18[2];
static double linflp_k24_Vx18[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir18[3];
static double linflp_k24_du_ir18[2];
static double linflp_k24_ds_ir18[1];
static double linflp_k24_dp_ir18[3];
static double linflp_k24_dy_ir18[10];
static double linflp_k24_dnu_ir18[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir18[3];
static double linflp_k24_rf0u_ir18[2];
static double linflp_k24_rf0s_ir18[1];
static double linflp_k24_rf_ir18[3];
static double linflp_k24_rc_ir18[10];
static double linflp_k24_rs_ir18[1];
static double linflp_k24_rk_ir18[10];

/* Variablen für Disketisierungsstelle 19 */
/* Optimierungsvariablen */
static double linflp_k24_x19[3];
static double linflp_k24_u19[2];
static double linflp_k24_s19[1];
static double linflp_k24_p19[3];
static double linflp_k24_y19[10];
static double linflp_k24_nu19[10];
/* Schrittvariablen */
static double linflp_k24_dx19[3];
static double linflp_k24_du19[2];
static double linflp_k24_ds19[1];
static double linflp_k24_dp19[3];
static double linflp_k24_dy19[10];
static double linflp_k24_dnu19[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx19[9];
static double linflp_k24_Hxu19[6];
static double linflp_k24_Huu19[4];
static double linflp_k24_Hss19[1];
static double linflp_k24_f0x19[3];
static double linflp_k24_f0u19[2];
static double linflp_k24_f0s19[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx19[9];
static double linflp_k24_fu19[6];
static double linflp_k24_f19[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx19[30];
static double linflp_k24_gu19[20];
static double linflp_k24_g19[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x19[3];
static double linflp_k24_rf0u19[2];
static double linflp_k24_rf0s19[1];
static double linflp_k24_rf19[3];
static double linflp_k24_rc19[10];
static double linflp_k24_rs19[1];
static double linflp_k24_rk19[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x19[3];
static double linflp_k24_rrf0u19[2];
static double linflp_k24_rhsxs19[1];
static double linflp_k24_yny19[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx19[9];
static double linflp_k24_Gxu19[6];
static double linflp_k24_Guu19[4];
static double linflp_k24_Rux19[6];
static double linflp_k24_Vxx19[9];
static double linflp_k24_Gx19[3];
static double linflp_k24_Gu19[2];
static double linflp_k24_Ru19[2];
static double linflp_k24_Vx19[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir19[3];
static double linflp_k24_du_ir19[2];
static double linflp_k24_ds_ir19[1];
static double linflp_k24_dp_ir19[3];
static double linflp_k24_dy_ir19[10];
static double linflp_k24_dnu_ir19[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir19[3];
static double linflp_k24_rf0u_ir19[2];
static double linflp_k24_rf0s_ir19[1];
static double linflp_k24_rf_ir19[3];
static double linflp_k24_rc_ir19[10];
static double linflp_k24_rs_ir19[1];
static double linflp_k24_rk_ir19[10];

/* Variablen für Disketisierungsstelle 20 */
/* Optimierungsvariablen */
static double linflp_k24_x20[3];
static double linflp_k24_u20[2];
static double linflp_k24_s20[1];
static double linflp_k24_p20[3];
static double linflp_k24_y20[10];
static double linflp_k24_nu20[10];
/* Schrittvariablen */
static double linflp_k24_dx20[3];
static double linflp_k24_du20[2];
static double linflp_k24_ds20[1];
static double linflp_k24_dp20[3];
static double linflp_k24_dy20[10];
static double linflp_k24_dnu20[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx20[9];
static double linflp_k24_Hxu20[6];
static double linflp_k24_Huu20[4];
static double linflp_k24_Hss20[1];
static double linflp_k24_f0x20[3];
static double linflp_k24_f0u20[2];
static double linflp_k24_f0s20[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx20[9];
static double linflp_k24_fu20[6];
static double linflp_k24_f20[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx20[30];
static double linflp_k24_gu20[20];
static double linflp_k24_g20[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x20[3];
static double linflp_k24_rf0u20[2];
static double linflp_k24_rf0s20[1];
static double linflp_k24_rf20[3];
static double linflp_k24_rc20[10];
static double linflp_k24_rs20[1];
static double linflp_k24_rk20[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x20[3];
static double linflp_k24_rrf0u20[2];
static double linflp_k24_rhsxs20[1];
static double linflp_k24_yny20[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx20[9];
static double linflp_k24_Gxu20[6];
static double linflp_k24_Guu20[4];
static double linflp_k24_Rux20[6];
static double linflp_k24_Vxx20[9];
static double linflp_k24_Gx20[3];
static double linflp_k24_Gu20[2];
static double linflp_k24_Ru20[2];
static double linflp_k24_Vx20[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir20[3];
static double linflp_k24_du_ir20[2];
static double linflp_k24_ds_ir20[1];
static double linflp_k24_dp_ir20[3];
static double linflp_k24_dy_ir20[10];
static double linflp_k24_dnu_ir20[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir20[3];
static double linflp_k24_rf0u_ir20[2];
static double linflp_k24_rf0s_ir20[1];
static double linflp_k24_rf_ir20[3];
static double linflp_k24_rc_ir20[10];
static double linflp_k24_rs_ir20[1];
static double linflp_k24_rk_ir20[10];

/* Variablen für Disketisierungsstelle 21 */
/* Optimierungsvariablen */
static double linflp_k24_x21[3];
static double linflp_k24_u21[2];
static double linflp_k24_s21[1];
static double linflp_k24_p21[3];
static double linflp_k24_y21[10];
static double linflp_k24_nu21[10];
/* Schrittvariablen */
static double linflp_k24_dx21[3];
static double linflp_k24_du21[2];
static double linflp_k24_ds21[1];
static double linflp_k24_dp21[3];
static double linflp_k24_dy21[10];
static double linflp_k24_dnu21[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx21[9];
static double linflp_k24_Hxu21[6];
static double linflp_k24_Huu21[4];
static double linflp_k24_Hss21[1];
static double linflp_k24_f0x21[3];
static double linflp_k24_f0u21[2];
static double linflp_k24_f0s21[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx21[9];
static double linflp_k24_fu21[6];
static double linflp_k24_f21[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx21[30];
static double linflp_k24_gu21[20];
static double linflp_k24_g21[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x21[3];
static double linflp_k24_rf0u21[2];
static double linflp_k24_rf0s21[1];
static double linflp_k24_rf21[3];
static double linflp_k24_rc21[10];
static double linflp_k24_rs21[1];
static double linflp_k24_rk21[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x21[3];
static double linflp_k24_rrf0u21[2];
static double linflp_k24_rhsxs21[1];
static double linflp_k24_yny21[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx21[9];
static double linflp_k24_Gxu21[6];
static double linflp_k24_Guu21[4];
static double linflp_k24_Rux21[6];
static double linflp_k24_Vxx21[9];
static double linflp_k24_Gx21[3];
static double linflp_k24_Gu21[2];
static double linflp_k24_Ru21[2];
static double linflp_k24_Vx21[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir21[3];
static double linflp_k24_du_ir21[2];
static double linflp_k24_ds_ir21[1];
static double linflp_k24_dp_ir21[3];
static double linflp_k24_dy_ir21[10];
static double linflp_k24_dnu_ir21[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir21[3];
static double linflp_k24_rf0u_ir21[2];
static double linflp_k24_rf0s_ir21[1];
static double linflp_k24_rf_ir21[3];
static double linflp_k24_rc_ir21[10];
static double linflp_k24_rs_ir21[1];
static double linflp_k24_rk_ir21[10];

/* Variablen für Disketisierungsstelle 22 */
/* Optimierungsvariablen */
static double linflp_k24_x22[3];
static double linflp_k24_u22[2];
static double linflp_k24_s22[1];
static double linflp_k24_p22[3];
static double linflp_k24_y22[10];
static double linflp_k24_nu22[10];
/* Schrittvariablen */
static double linflp_k24_dx22[3];
static double linflp_k24_du22[2];
static double linflp_k24_ds22[1];
static double linflp_k24_dp22[3];
static double linflp_k24_dy22[10];
static double linflp_k24_dnu22[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx22[9];
static double linflp_k24_Hxu22[6];
static double linflp_k24_Huu22[4];
static double linflp_k24_Hss22[1];
static double linflp_k24_f0x22[3];
static double linflp_k24_f0u22[2];
static double linflp_k24_f0s22[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx22[9];
static double linflp_k24_fu22[6];
static double linflp_k24_f22[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx22[30];
static double linflp_k24_gu22[20];
static double linflp_k24_g22[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x22[3];
static double linflp_k24_rf0u22[2];
static double linflp_k24_rf0s22[1];
static double linflp_k24_rf22[3];
static double linflp_k24_rc22[10];
static double linflp_k24_rs22[1];
static double linflp_k24_rk22[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x22[3];
static double linflp_k24_rrf0u22[2];
static double linflp_k24_rhsxs22[1];
static double linflp_k24_yny22[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx22[9];
static double linflp_k24_Gxu22[6];
static double linflp_k24_Guu22[4];
static double linflp_k24_Rux22[6];
static double linflp_k24_Vxx22[9];
static double linflp_k24_Gx22[3];
static double linflp_k24_Gu22[2];
static double linflp_k24_Ru22[2];
static double linflp_k24_Vx22[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir22[3];
static double linflp_k24_du_ir22[2];
static double linflp_k24_ds_ir22[1];
static double linflp_k24_dp_ir22[3];
static double linflp_k24_dy_ir22[10];
static double linflp_k24_dnu_ir22[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir22[3];
static double linflp_k24_rf0u_ir22[2];
static double linflp_k24_rf0s_ir22[1];
static double linflp_k24_rf_ir22[3];
static double linflp_k24_rc_ir22[10];
static double linflp_k24_rs_ir22[1];
static double linflp_k24_rk_ir22[10];

/* Variablen für Disketisierungsstelle 23 */
/* Optimierungsvariablen */
static double linflp_k24_x23[3];
static double linflp_k24_u23[2];
static double linflp_k24_s23[1];
static double linflp_k24_p23[3];
static double linflp_k24_y23[10];
static double linflp_k24_nu23[10];
/* Schrittvariablen */
static double linflp_k24_dx23[3];
static double linflp_k24_du23[2];
static double linflp_k24_ds23[1];
static double linflp_k24_dp23[3];
static double linflp_k24_dy23[10];
static double linflp_k24_dnu23[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx23[9];
static double linflp_k24_Hxu23[6];
static double linflp_k24_Huu23[4];
static double linflp_k24_Hss23[1];
static double linflp_k24_f0x23[3];
static double linflp_k24_f0u23[2];
static double linflp_k24_f0s23[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx23[9];
static double linflp_k24_fu23[6];
static double linflp_k24_f23[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx23[30];
static double linflp_k24_gu23[20];
static double linflp_k24_g23[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x23[3];
static double linflp_k24_rf0u23[2];
static double linflp_k24_rf0s23[1];
static double linflp_k24_rf23[3];
static double linflp_k24_rc23[10];
static double linflp_k24_rs23[1];
static double linflp_k24_rk23[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x23[3];
static double linflp_k24_rrf0u23[2];
static double linflp_k24_rhsxs23[1];
static double linflp_k24_yny23[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx23[9];
static double linflp_k24_Gxu23[6];
static double linflp_k24_Guu23[4];
static double linflp_k24_Rux23[6];
static double linflp_k24_Vxx23[9];
static double linflp_k24_Gx23[3];
static double linflp_k24_Gu23[2];
static double linflp_k24_Ru23[2];
static double linflp_k24_Vx23[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir23[3];
static double linflp_k24_du_ir23[2];
static double linflp_k24_ds_ir23[1];
static double linflp_k24_dp_ir23[3];
static double linflp_k24_dy_ir23[10];
static double linflp_k24_dnu_ir23[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir23[3];
static double linflp_k24_rf0u_ir23[2];
static double linflp_k24_rf0s_ir23[1];
static double linflp_k24_rf_ir23[3];
static double linflp_k24_rc_ir23[10];
static double linflp_k24_rs_ir23[1];
static double linflp_k24_rk_ir23[10];

/* Variablen für Disketisierungsstelle 24 */
/* Optimierungsvariablen */
static double linflp_k24_x24[3];
static double linflp_k24_u24[2];
static double linflp_k24_s24[1];
static double linflp_k24_p24[3];
static double linflp_k24_y24[10];
static double linflp_k24_nu24[10];
/* Schrittvariablen */
static double linflp_k24_dx24[3];
static double linflp_k24_du24[2];
static double linflp_k24_ds24[1];
static double linflp_k24_dp24[3];
static double linflp_k24_dy24[10];
static double linflp_k24_dnu24[10];
/* Variablen der Guetefunktion */
static double linflp_k24_Hxx24[9];
static double linflp_k24_Hxu24[6];
static double linflp_k24_Huu24[4];
static double linflp_k24_Hss24[1];
static double linflp_k24_f0x24[3];
static double linflp_k24_f0u24[2];
static double linflp_k24_f0s24[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k24_fx24[9];
static double linflp_k24_fu24[6];
static double linflp_k24_f24[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k24_gx24[30];
static double linflp_k24_gu24[20];
static double linflp_k24_g24[10];
/* Variablen der rechten Seiten */
static double linflp_k24_rf0x24[3];
static double linflp_k24_rf0u24[2];
static double linflp_k24_rf0s24[1];
static double linflp_k24_rf24[3];
static double linflp_k24_rc24[10];
static double linflp_k24_rs24[1];
static double linflp_k24_rk24[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k24_rrf0x24[3];
static double linflp_k24_rrf0u24[2];
static double linflp_k24_rhsxs24[1];
static double linflp_k24_yny24[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k24_Gxx24[9];
static double linflp_k24_Gxu24[6];
static double linflp_k24_Guu24[4];
static double linflp_k24_Rux24[6];
static double linflp_k24_Vxx24[9];
static double linflp_k24_Gx24[3];
static double linflp_k24_Gu24[2];
static double linflp_k24_Ru24[2];
static double linflp_k24_Vx24[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k24_dx_ir24[3];
static double linflp_k24_du_ir24[2];
static double linflp_k24_ds_ir24[1];
static double linflp_k24_dp_ir24[3];
static double linflp_k24_dy_ir24[10];
static double linflp_k24_dnu_ir24[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k24_rf0x_ir24[3];
static double linflp_k24_rf0u_ir24[2];
static double linflp_k24_rf0s_ir24[1];
static double linflp_k24_rf_ir24[3];
static double linflp_k24_rc_ir24[10];
static double linflp_k24_rs_ir24[1];
static double linflp_k24_rk_ir24[10];

/* Temporäre Variablen */
static double linflp_k24_tmp1_10_1[10];
static double linflp_k24_tmp2_10_1[10];
static double linflp_k24_tmp1_10[10];
static double linflp_k24_tmp2_10[10];
static double linflp_k24_tmp1_1[1];
static double linflp_k24_tmp2_1[1];
static double linflp_k24_tmp3_1[1];
static double linflp_k24_tmp1_3_3[9];
static double linflp_k24_tmp1_3_10[30];
static double linflp_k24_tmp1_2_3[6];
static double linflp_k24_tmp1_2_10[20];
static double linflp_k24_tmp1_3[3];
static double linflp_k24_tmp1_3_1[3];
static double linflp_k24_tmp1_2_1[2];
static double linflp_k24_tmp1_1_1[1];

/* Temporäre Variablen für Cholesky Zerlegung */
static double linflp_k24_L0[4];
static double linflp_k24_L1[4];
static double linflp_k24_L2[4];
static double linflp_k24_L3[4];
static double linflp_k24_L4[4];
static double linflp_k24_L5[4];
static double linflp_k24_L6[4];
static double linflp_k24_L7[4];
static double linflp_k24_L8[4];
static double linflp_k24_L9[4];
static double linflp_k24_L10[4];
static double linflp_k24_L11[4];
static double linflp_k24_L12[4];
static double linflp_k24_L13[4];
static double linflp_k24_L14[4];
static double linflp_k24_L15[4];
static double linflp_k24_L16[4];
static double linflp_k24_L17[4];
static double linflp_k24_L18[4];
static double linflp_k24_L19[4];
static double linflp_k24_L20[4];
static double linflp_k24_L21[4];
static double linflp_k24_L22[4];
static double linflp_k24_L23[4];
static double linflp_k24_L24[4];

/* Variablen für max_stepsize */
static double linflp_k24_alpha_max[1];
static double linflp_k24_alpha_tmp[1];
static double linflp_k24_alpha_min_y[1];
static double linflp_k24_alpha_min_dy[1];
static double linflp_k24_alpha_min_nu[1];
static double linflp_k24_alpha_min_dnu[1];
static int linflp_k24_alpha_min_source_y;

/* Variablen für mehrotra_step */
static double linflp_k24_mehrotra_alpha[1];
static double linflp_k24_mehrotra_gamma[1];
static double linflp_k24_mehrotra_fpd[1];

/* Verschiedenes */
static int linflp_k24_iter;
static int linflp_k24_max_iter;
static int linflp_k24_termcode;
static int linflp_k24_iter_ref;
static int linflp_k24_error_line;
static int linflp_k24_error_source;
static double linflp_k24_m_ineq[1];
static double linflp_k24_macheps[1];
static double linflp_k24_tau[1];
static double linflp_k24_sigma[1];
static double linflp_k24_norm_d[1];
static double linflp_k24_norm_r[1];
static double linflp_k24_norm_r0[1];
static double linflp_k24_norm_r_prev[1];
static double linflp_k24_mu[1];
static double linflp_k24_mu0[1];
static double linflp_k24_mu_aff[1];
static double linflp_k24_phi[1];
static double linflp_k24_minphi[1];
static double linflp_k24_tol[1];
static double linflp_k24_tc1_factor[1];
static double linflp_k24_tc2_factor[1];
static double linflp_k24_timer_start;
static double linflp_k24_time_max;

/* Variablen für Duality Gap */
static double linflp_k24_dgap[1];

/* Variablen für Starting Point */

/* Variablen für Statistik */
static double linflp_k24_stat_time[100];
static int linflp_k24_stat_iter_ref[100];
static int linflp_k24_stat_num_iter_ref;
static int linflp_k24_stat_num_factor;
static int linflp_k24_stat_num_solve;



double *linflp_k24_get_x0()
{
return linflp_k24_xinit;
}

double *linflp_k24_get_x(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_x0;
    case 1: return linflp_k24_x1;
    case 2: return linflp_k24_x2;
    case 3: return linflp_k24_x3;
    case 4: return linflp_k24_x4;
    case 5: return linflp_k24_x5;
    case 6: return linflp_k24_x6;
    case 7: return linflp_k24_x7;
    case 8: return linflp_k24_x8;
    case 9: return linflp_k24_x9;
    case 10: return linflp_k24_x10;
    case 11: return linflp_k24_x11;
    case 12: return linflp_k24_x12;
    case 13: return linflp_k24_x13;
    case 14: return linflp_k24_x14;
    case 15: return linflp_k24_x15;
    case 16: return linflp_k24_x16;
    case 17: return linflp_k24_x17;
    case 18: return linflp_k24_x18;
    case 19: return linflp_k24_x19;
    case 20: return linflp_k24_x20;
    case 21: return linflp_k24_x21;
    case 22: return linflp_k24_x22;
    case 23: return linflp_k24_x23;
    case 24: return linflp_k24_x24;
    default: return 0;
  }
}

double *linflp_k24_get_u(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_u0;
    case 1: return linflp_k24_u1;
    case 2: return linflp_k24_u2;
    case 3: return linflp_k24_u3;
    case 4: return linflp_k24_u4;
    case 5: return linflp_k24_u5;
    case 6: return linflp_k24_u6;
    case 7: return linflp_k24_u7;
    case 8: return linflp_k24_u8;
    case 9: return linflp_k24_u9;
    case 10: return linflp_k24_u10;
    case 11: return linflp_k24_u11;
    case 12: return linflp_k24_u12;
    case 13: return linflp_k24_u13;
    case 14: return linflp_k24_u14;
    case 15: return linflp_k24_u15;
    case 16: return linflp_k24_u16;
    case 17: return linflp_k24_u17;
    case 18: return linflp_k24_u18;
    case 19: return linflp_k24_u19;
    case 20: return linflp_k24_u20;
    case 21: return linflp_k24_u21;
    case 22: return linflp_k24_u22;
    case 23: return linflp_k24_u23;
    case 24: return linflp_k24_u24;
    default: return 0;
  }
}

double *linflp_k24_get_s(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_s0;
    case 1: return linflp_k24_s1;
    case 2: return linflp_k24_s2;
    case 3: return linflp_k24_s3;
    case 4: return linflp_k24_s4;
    case 5: return linflp_k24_s5;
    case 6: return linflp_k24_s6;
    case 7: return linflp_k24_s7;
    case 8: return linflp_k24_s8;
    case 9: return linflp_k24_s9;
    case 10: return linflp_k24_s10;
    case 11: return linflp_k24_s11;
    case 12: return linflp_k24_s12;
    case 13: return linflp_k24_s13;
    case 14: return linflp_k24_s14;
    case 15: return linflp_k24_s15;
    case 16: return linflp_k24_s16;
    case 17: return linflp_k24_s17;
    case 18: return linflp_k24_s18;
    case 19: return linflp_k24_s19;
    case 20: return linflp_k24_s20;
    case 21: return linflp_k24_s21;
    case 22: return linflp_k24_s22;
    case 23: return linflp_k24_s23;
    case 24: return linflp_k24_s24;
    default: return 0;
  }
}

double *linflp_k24_get_p(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_p0;
    case 1: return linflp_k24_p1;
    case 2: return linflp_k24_p2;
    case 3: return linflp_k24_p3;
    case 4: return linflp_k24_p4;
    case 5: return linflp_k24_p5;
    case 6: return linflp_k24_p6;
    case 7: return linflp_k24_p7;
    case 8: return linflp_k24_p8;
    case 9: return linflp_k24_p9;
    case 10: return linflp_k24_p10;
    case 11: return linflp_k24_p11;
    case 12: return linflp_k24_p12;
    case 13: return linflp_k24_p13;
    case 14: return linflp_k24_p14;
    case 15: return linflp_k24_p15;
    case 16: return linflp_k24_p16;
    case 17: return linflp_k24_p17;
    case 18: return linflp_k24_p18;
    case 19: return linflp_k24_p19;
    case 20: return linflp_k24_p20;
    case 21: return linflp_k24_p21;
    case 22: return linflp_k24_p22;
    case 23: return linflp_k24_p23;
    case 24: return linflp_k24_p24;
    default: return 0;
  }
}

double *linflp_k24_get_y(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_y0;
    case 1: return linflp_k24_y1;
    case 2: return linflp_k24_y2;
    case 3: return linflp_k24_y3;
    case 4: return linflp_k24_y4;
    case 5: return linflp_k24_y5;
    case 6: return linflp_k24_y6;
    case 7: return linflp_k24_y7;
    case 8: return linflp_k24_y8;
    case 9: return linflp_k24_y9;
    case 10: return linflp_k24_y10;
    case 11: return linflp_k24_y11;
    case 12: return linflp_k24_y12;
    case 13: return linflp_k24_y13;
    case 14: return linflp_k24_y14;
    case 15: return linflp_k24_y15;
    case 16: return linflp_k24_y16;
    case 17: return linflp_k24_y17;
    case 18: return linflp_k24_y18;
    case 19: return linflp_k24_y19;
    case 20: return linflp_k24_y20;
    case 21: return linflp_k24_y21;
    case 22: return linflp_k24_y22;
    case 23: return linflp_k24_y23;
    case 24: return linflp_k24_y24;
    default: return 0;
  }
}

double *linflp_k24_get_nu(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_nu0;
    case 1: return linflp_k24_nu1;
    case 2: return linflp_k24_nu2;
    case 3: return linflp_k24_nu3;
    case 4: return linflp_k24_nu4;
    case 5: return linflp_k24_nu5;
    case 6: return linflp_k24_nu6;
    case 7: return linflp_k24_nu7;
    case 8: return linflp_k24_nu8;
    case 9: return linflp_k24_nu9;
    case 10: return linflp_k24_nu10;
    case 11: return linflp_k24_nu11;
    case 12: return linflp_k24_nu12;
    case 13: return linflp_k24_nu13;
    case 14: return linflp_k24_nu14;
    case 15: return linflp_k24_nu15;
    case 16: return linflp_k24_nu16;
    case 17: return linflp_k24_nu17;
    case 18: return linflp_k24_nu18;
    case 19: return linflp_k24_nu19;
    case 20: return linflp_k24_nu20;
    case 21: return linflp_k24_nu21;
    case 22: return linflp_k24_nu22;
    case 23: return linflp_k24_nu23;
    case 24: return linflp_k24_nu24;
    default: return 0;
  }
}

double *linflp_k24_get_Hxx(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_Hxx0;
    case 1: return linflp_k24_Hxx1;
    case 2: return linflp_k24_Hxx2;
    case 3: return linflp_k24_Hxx3;
    case 4: return linflp_k24_Hxx4;
    case 5: return linflp_k24_Hxx5;
    case 6: return linflp_k24_Hxx6;
    case 7: return linflp_k24_Hxx7;
    case 8: return linflp_k24_Hxx8;
    case 9: return linflp_k24_Hxx9;
    case 10: return linflp_k24_Hxx10;
    case 11: return linflp_k24_Hxx11;
    case 12: return linflp_k24_Hxx12;
    case 13: return linflp_k24_Hxx13;
    case 14: return linflp_k24_Hxx14;
    case 15: return linflp_k24_Hxx15;
    case 16: return linflp_k24_Hxx16;
    case 17: return linflp_k24_Hxx17;
    case 18: return linflp_k24_Hxx18;
    case 19: return linflp_k24_Hxx19;
    case 20: return linflp_k24_Hxx20;
    case 21: return linflp_k24_Hxx21;
    case 22: return linflp_k24_Hxx22;
    case 23: return linflp_k24_Hxx23;
    case 24: return linflp_k24_Hxx24;
    default: return 0;
  }
}

double *linflp_k24_get_Hxu(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_Hxu0;
    case 1: return linflp_k24_Hxu1;
    case 2: return linflp_k24_Hxu2;
    case 3: return linflp_k24_Hxu3;
    case 4: return linflp_k24_Hxu4;
    case 5: return linflp_k24_Hxu5;
    case 6: return linflp_k24_Hxu6;
    case 7: return linflp_k24_Hxu7;
    case 8: return linflp_k24_Hxu8;
    case 9: return linflp_k24_Hxu9;
    case 10: return linflp_k24_Hxu10;
    case 11: return linflp_k24_Hxu11;
    case 12: return linflp_k24_Hxu12;
    case 13: return linflp_k24_Hxu13;
    case 14: return linflp_k24_Hxu14;
    case 15: return linflp_k24_Hxu15;
    case 16: return linflp_k24_Hxu16;
    case 17: return linflp_k24_Hxu17;
    case 18: return linflp_k24_Hxu18;
    case 19: return linflp_k24_Hxu19;
    case 20: return linflp_k24_Hxu20;
    case 21: return linflp_k24_Hxu21;
    case 22: return linflp_k24_Hxu22;
    case 23: return linflp_k24_Hxu23;
    case 24: return linflp_k24_Hxu24;
    default: return 0;
  }
}

double *linflp_k24_get_Huu(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_Huu0;
    case 1: return linflp_k24_Huu1;
    case 2: return linflp_k24_Huu2;
    case 3: return linflp_k24_Huu3;
    case 4: return linflp_k24_Huu4;
    case 5: return linflp_k24_Huu5;
    case 6: return linflp_k24_Huu6;
    case 7: return linflp_k24_Huu7;
    case 8: return linflp_k24_Huu8;
    case 9: return linflp_k24_Huu9;
    case 10: return linflp_k24_Huu10;
    case 11: return linflp_k24_Huu11;
    case 12: return linflp_k24_Huu12;
    case 13: return linflp_k24_Huu13;
    case 14: return linflp_k24_Huu14;
    case 15: return linflp_k24_Huu15;
    case 16: return linflp_k24_Huu16;
    case 17: return linflp_k24_Huu17;
    case 18: return linflp_k24_Huu18;
    case 19: return linflp_k24_Huu19;
    case 20: return linflp_k24_Huu20;
    case 21: return linflp_k24_Huu21;
    case 22: return linflp_k24_Huu22;
    case 23: return linflp_k24_Huu23;
    case 24: return linflp_k24_Huu24;
    default: return 0;
  }
}

double *linflp_k24_get_Hss(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_Hss0;
    case 1: return linflp_k24_Hss1;
    case 2: return linflp_k24_Hss2;
    case 3: return linflp_k24_Hss3;
    case 4: return linflp_k24_Hss4;
    case 5: return linflp_k24_Hss5;
    case 6: return linflp_k24_Hss6;
    case 7: return linflp_k24_Hss7;
    case 8: return linflp_k24_Hss8;
    case 9: return linflp_k24_Hss9;
    case 10: return linflp_k24_Hss10;
    case 11: return linflp_k24_Hss11;
    case 12: return linflp_k24_Hss12;
    case 13: return linflp_k24_Hss13;
    case 14: return linflp_k24_Hss14;
    case 15: return linflp_k24_Hss15;
    case 16: return linflp_k24_Hss16;
    case 17: return linflp_k24_Hss17;
    case 18: return linflp_k24_Hss18;
    case 19: return linflp_k24_Hss19;
    case 20: return linflp_k24_Hss20;
    case 21: return linflp_k24_Hss21;
    case 22: return linflp_k24_Hss22;
    case 23: return linflp_k24_Hss23;
    case 24: return linflp_k24_Hss24;
    default: return 0;
  }
}

double *linflp_k24_get_f0x(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_f0x0;
    case 1: return linflp_k24_f0x1;
    case 2: return linflp_k24_f0x2;
    case 3: return linflp_k24_f0x3;
    case 4: return linflp_k24_f0x4;
    case 5: return linflp_k24_f0x5;
    case 6: return linflp_k24_f0x6;
    case 7: return linflp_k24_f0x7;
    case 8: return linflp_k24_f0x8;
    case 9: return linflp_k24_f0x9;
    case 10: return linflp_k24_f0x10;
    case 11: return linflp_k24_f0x11;
    case 12: return linflp_k24_f0x12;
    case 13: return linflp_k24_f0x13;
    case 14: return linflp_k24_f0x14;
    case 15: return linflp_k24_f0x15;
    case 16: return linflp_k24_f0x16;
    case 17: return linflp_k24_f0x17;
    case 18: return linflp_k24_f0x18;
    case 19: return linflp_k24_f0x19;
    case 20: return linflp_k24_f0x20;
    case 21: return linflp_k24_f0x21;
    case 22: return linflp_k24_f0x22;
    case 23: return linflp_k24_f0x23;
    case 24: return linflp_k24_f0x24;
    default: return 0;
  }
}

double *linflp_k24_get_f0u(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_f0u0;
    case 1: return linflp_k24_f0u1;
    case 2: return linflp_k24_f0u2;
    case 3: return linflp_k24_f0u3;
    case 4: return linflp_k24_f0u4;
    case 5: return linflp_k24_f0u5;
    case 6: return linflp_k24_f0u6;
    case 7: return linflp_k24_f0u7;
    case 8: return linflp_k24_f0u8;
    case 9: return linflp_k24_f0u9;
    case 10: return linflp_k24_f0u10;
    case 11: return linflp_k24_f0u11;
    case 12: return linflp_k24_f0u12;
    case 13: return linflp_k24_f0u13;
    case 14: return linflp_k24_f0u14;
    case 15: return linflp_k24_f0u15;
    case 16: return linflp_k24_f0u16;
    case 17: return linflp_k24_f0u17;
    case 18: return linflp_k24_f0u18;
    case 19: return linflp_k24_f0u19;
    case 20: return linflp_k24_f0u20;
    case 21: return linflp_k24_f0u21;
    case 22: return linflp_k24_f0u22;
    case 23: return linflp_k24_f0u23;
    case 24: return linflp_k24_f0u24;
    default: return 0;
  }
}

double *linflp_k24_get_f0s(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_f0s0;
    case 1: return linflp_k24_f0s1;
    case 2: return linflp_k24_f0s2;
    case 3: return linflp_k24_f0s3;
    case 4: return linflp_k24_f0s4;
    case 5: return linflp_k24_f0s5;
    case 6: return linflp_k24_f0s6;
    case 7: return linflp_k24_f0s7;
    case 8: return linflp_k24_f0s8;
    case 9: return linflp_k24_f0s9;
    case 10: return linflp_k24_f0s10;
    case 11: return linflp_k24_f0s11;
    case 12: return linflp_k24_f0s12;
    case 13: return linflp_k24_f0s13;
    case 14: return linflp_k24_f0s14;
    case 15: return linflp_k24_f0s15;
    case 16: return linflp_k24_f0s16;
    case 17: return linflp_k24_f0s17;
    case 18: return linflp_k24_f0s18;
    case 19: return linflp_k24_f0s19;
    case 20: return linflp_k24_f0s20;
    case 21: return linflp_k24_f0s21;
    case 22: return linflp_k24_f0s22;
    case 23: return linflp_k24_f0s23;
    case 24: return linflp_k24_f0s24;
    default: return 0;
  }
}

double *linflp_k24_get_fx(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_fx0;
    case 1: return linflp_k24_fx1;
    case 2: return linflp_k24_fx2;
    case 3: return linflp_k24_fx3;
    case 4: return linflp_k24_fx4;
    case 5: return linflp_k24_fx5;
    case 6: return linflp_k24_fx6;
    case 7: return linflp_k24_fx7;
    case 8: return linflp_k24_fx8;
    case 9: return linflp_k24_fx9;
    case 10: return linflp_k24_fx10;
    case 11: return linflp_k24_fx11;
    case 12: return linflp_k24_fx12;
    case 13: return linflp_k24_fx13;
    case 14: return linflp_k24_fx14;
    case 15: return linflp_k24_fx15;
    case 16: return linflp_k24_fx16;
    case 17: return linflp_k24_fx17;
    case 18: return linflp_k24_fx18;
    case 19: return linflp_k24_fx19;
    case 20: return linflp_k24_fx20;
    case 21: return linflp_k24_fx21;
    case 22: return linflp_k24_fx22;
    case 23: return linflp_k24_fx23;
    case 24: return linflp_k24_fx24;
    default: return 0;
  }
}

double *linflp_k24_get_fu(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_fu0;
    case 1: return linflp_k24_fu1;
    case 2: return linflp_k24_fu2;
    case 3: return linflp_k24_fu3;
    case 4: return linflp_k24_fu4;
    case 5: return linflp_k24_fu5;
    case 6: return linflp_k24_fu6;
    case 7: return linflp_k24_fu7;
    case 8: return linflp_k24_fu8;
    case 9: return linflp_k24_fu9;
    case 10: return linflp_k24_fu10;
    case 11: return linflp_k24_fu11;
    case 12: return linflp_k24_fu12;
    case 13: return linflp_k24_fu13;
    case 14: return linflp_k24_fu14;
    case 15: return linflp_k24_fu15;
    case 16: return linflp_k24_fu16;
    case 17: return linflp_k24_fu17;
    case 18: return linflp_k24_fu18;
    case 19: return linflp_k24_fu19;
    case 20: return linflp_k24_fu20;
    case 21: return linflp_k24_fu21;
    case 22: return linflp_k24_fu22;
    case 23: return linflp_k24_fu23;
    case 24: return linflp_k24_fu24;
    default: return 0;
  }
}

double *linflp_k24_get_f(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_f0;
    case 1: return linflp_k24_f1;
    case 2: return linflp_k24_f2;
    case 3: return linflp_k24_f3;
    case 4: return linflp_k24_f4;
    case 5: return linflp_k24_f5;
    case 6: return linflp_k24_f6;
    case 7: return linflp_k24_f7;
    case 8: return linflp_k24_f8;
    case 9: return linflp_k24_f9;
    case 10: return linflp_k24_f10;
    case 11: return linflp_k24_f11;
    case 12: return linflp_k24_f12;
    case 13: return linflp_k24_f13;
    case 14: return linflp_k24_f14;
    case 15: return linflp_k24_f15;
    case 16: return linflp_k24_f16;
    case 17: return linflp_k24_f17;
    case 18: return linflp_k24_f18;
    case 19: return linflp_k24_f19;
    case 20: return linflp_k24_f20;
    case 21: return linflp_k24_f21;
    case 22: return linflp_k24_f22;
    case 23: return linflp_k24_f23;
    case 24: return linflp_k24_f24;
    default: return 0;
  }
}

double *linflp_k24_get_gx(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_gx0;
    case 1: return linflp_k24_gx1;
    case 2: return linflp_k24_gx2;
    case 3: return linflp_k24_gx3;
    case 4: return linflp_k24_gx4;
    case 5: return linflp_k24_gx5;
    case 6: return linflp_k24_gx6;
    case 7: return linflp_k24_gx7;
    case 8: return linflp_k24_gx8;
    case 9: return linflp_k24_gx9;
    case 10: return linflp_k24_gx10;
    case 11: return linflp_k24_gx11;
    case 12: return linflp_k24_gx12;
    case 13: return linflp_k24_gx13;
    case 14: return linflp_k24_gx14;
    case 15: return linflp_k24_gx15;
    case 16: return linflp_k24_gx16;
    case 17: return linflp_k24_gx17;
    case 18: return linflp_k24_gx18;
    case 19: return linflp_k24_gx19;
    case 20: return linflp_k24_gx20;
    case 21: return linflp_k24_gx21;
    case 22: return linflp_k24_gx22;
    case 23: return linflp_k24_gx23;
    case 24: return linflp_k24_gx24;
    default: return 0;
  }
}

double *linflp_k24_get_gu(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_gu0;
    case 1: return linflp_k24_gu1;
    case 2: return linflp_k24_gu2;
    case 3: return linflp_k24_gu3;
    case 4: return linflp_k24_gu4;
    case 5: return linflp_k24_gu5;
    case 6: return linflp_k24_gu6;
    case 7: return linflp_k24_gu7;
    case 8: return linflp_k24_gu8;
    case 9: return linflp_k24_gu9;
    case 10: return linflp_k24_gu10;
    case 11: return linflp_k24_gu11;
    case 12: return linflp_k24_gu12;
    case 13: return linflp_k24_gu13;
    case 14: return linflp_k24_gu14;
    case 15: return linflp_k24_gu15;
    case 16: return linflp_k24_gu16;
    case 17: return linflp_k24_gu17;
    case 18: return linflp_k24_gu18;
    case 19: return linflp_k24_gu19;
    case 20: return linflp_k24_gu20;
    case 21: return linflp_k24_gu21;
    case 22: return linflp_k24_gu22;
    case 23: return linflp_k24_gu23;
    case 24: return linflp_k24_gu24;
    default: return 0;
  }
}

double *linflp_k24_get_g(int k)
{
  switch(k)
  {
    case 0: return linflp_k24_g0;
    case 1: return linflp_k24_g1;
    case 2: return linflp_k24_g2;
    case 3: return linflp_k24_g3;
    case 4: return linflp_k24_g4;
    case 5: return linflp_k24_g5;
    case 6: return linflp_k24_g6;
    case 7: return linflp_k24_g7;
    case 8: return linflp_k24_g8;
    case 9: return linflp_k24_g9;
    case 10: return linflp_k24_g10;
    case 11: return linflp_k24_g11;
    case 12: return linflp_k24_g12;
    case 13: return linflp_k24_g13;
    case 14: return linflp_k24_g14;
    case 15: return linflp_k24_g15;
    case 16: return linflp_k24_g16;
    case 17: return linflp_k24_g17;
    case 18: return linflp_k24_g18;
    case 19: return linflp_k24_g19;
    case 20: return linflp_k24_g20;
    case 21: return linflp_k24_g21;
    case 22: return linflp_k24_g22;
    case 23: return linflp_k24_g23;
    case 24: return linflp_k24_g24;
    default: return 0;
  }
}

double *linflp_k24_get_stat_time()
{
return linflp_k24_stat_time;
}

int *linflp_k24_get_stat_iter_ref()
{
return &linflp_k24_stat_iter_ref;
}

int *linflp_k24_get_stat_num_factor()
{
return &linflp_k24_stat_num_factor;
}

int *linflp_k24_get_stat_num_solve()
{
return &linflp_k24_stat_num_solve;
}

int *linflp_k24_get_stat_num_iter_ref()
{
return &linflp_k24_stat_num_iter_ref;
}

int *linflp_k24_get_iter()
{
return &linflp_k24_iter;
}

int *linflp_k24_get_termcode()
{
return &linflp_k24_termcode;
}

int *linflp_k24_get_error_line()
{
return &linflp_k24_error_line;
}

int *linflp_k24_get_error_source()
{
return &linflp_k24_error_source;
}

double *linflp_k24_get_norm_d()
{
return linflp_k24_norm_d;
}
double *linflp_k24_get_time_max()
{
return &linflp_k24_time_max;
}

void linflp_k24_set_time_max(double tmax)
{
linflp_k24_time_max = tmax;
}


/* ###################################### */
/* Diese Funktion initialisiert den Timer */
/* ###################################### */
void linflp_k24_glqdocpip_timer_start()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER linflp_k24_tmp_counter, linflp_k24_tmp_frequency;
  QueryPerformanceFrequency(&linflp_k24_tmp_frequency);
  QueryPerformanceCounter(&linflp_k24_tmp_counter);
  linflp_k24_timer_start = (double) linflp_k24_tmp_counter.QuadPart/(double) linflp_k24_tmp_frequency.QuadPart;
#endif
}


/* ################################################### */
/* Diese Funktion gibt die Zeit seit Timerstart zurück */
/* ################################################### */
double linflp_k24_glqdocpip_timer_get()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER linflp_k24_tmp_counter, linflp_k24_tmp_frequency;
  QueryPerformanceFrequency(&linflp_k24_tmp_frequency);
  QueryPerformanceCounter(&linflp_k24_tmp_counter);
  return (double) linflp_k24_tmp_counter.QuadPart/(double) linflp_k24_tmp_frequency.QuadPart - linflp_k24_timer_start;
#endif
}

static void linflp_k24_v_copy_3(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  return;
}

static void linflp_k24_mv_sid21_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid24_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_vsub_3(double *a, double *b, double *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  return;
}

static void linflp_k24_mtv_sid42_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[0];
  out[2] += A[6] * b[0];
  out[1] += A[4] * b[1];
  out[2] += A[7] * b[1];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mtv_sid51_sid15_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[11] * b[1];
  out[2] += A[22] * b[2];
  out[0] += A[3] * b[3];
  out[1] += A[14] * b[4];
  out[2] += A[25] * b[5];
  out[0] += A[8] * b[8];
  out[0] += A[9] * b[9];
  return;
}

static void linflp_k24_v_copy_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  return;
}

static void linflp_k24_mtv_sid24_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid27_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mtv_sid45_sid2_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  return;
}

static void linflp_k24_mtv_sid54_sid15_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k24_v_copy_10(double *a, double *out)
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
  return;
}

static void linflp_k24_mv_sid51_sid2_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[3] += A[3] * b[0];
  out[8] += A[8] * b[0];
  out[9] += A[9] * b[0];
  out[1] += A[11] * b[1];
  out[4] += A[14] * b[1];
  out[2] += A[22] * b[2];
  out[5] += A[25] * b[2];
  return;
}

static void linflp_k24_mv_sid54_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k24_vadd_10(double *a, double *b, double *out)
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
  return;
}

static void linflp_k24_vv_elemult_10(double *a, double *b, double *out)
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
  return;
}

static void linflp_k24_mv_sid22_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid25_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mtv_sid43_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[0];
  out[2] += A[6] * b[0];
  out[1] += A[4] * b[1];
  out[2] += A[7] * b[1];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mtv_sid52_sid16_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[11] * b[1];
  out[2] += A[22] * b[2];
  out[0] += A[3] * b[3];
  out[1] += A[14] * b[4];
  out[2] += A[25] * b[5];
  out[0] += A[8] * b[8];
  out[0] += A[9] * b[9];
  return;
}

static void linflp_k24_mtv_sid25_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid28_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mtv_sid46_sid2_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  return;
}

static void linflp_k24_mtv_sid55_sid16_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k24_mv_sid43_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mv_sid46_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k24_mv_sid52_sid2_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[3] += A[3] * b[0];
  out[8] += A[8] * b[0];
  out[9] += A[9] * b[0];
  out[1] += A[11] * b[1];
  out[4] += A[14] * b[1];
  out[2] += A[22] * b[2];
  out[5] += A[25] * b[2];
  return;
}

static void linflp_k24_mv_sid55_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k24_mv_sid23_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid26_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mtv_sid53_sid17_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[11] * b[1];
  out[2] += A[22] * b[2];
  out[0] += A[3] * b[3];
  out[1] += A[14] * b[4];
  out[2] += A[25] * b[5];
  out[0] += A[8] * b[8];
  out[0] += A[9] * b[9];
  return;
}

static void linflp_k24_mtv_sid26_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mv_sid29_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k24_mtv_sid56_sid17_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k24_mv_sid44_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mv_sid47_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k24_mv_sid53_sid2_10_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[3] += A[3] * b[0];
  out[8] += A[8] * b[0];
  out[9] += A[9] * b[0];
  out[1] += A[11] * b[1];
  out[4] += A[14] * b[1];
  out[2] += A[22] * b[2];
  out[5] += A[25] * b[2];
  return;
}

static void linflp_k24_mv_sid56_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k24_v_init0_10(double *a)
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
  return;
}

static void linflp_k24_vv_elediv_10(double *a, double *b, double *out)
{

  if(b[0] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  if(b[8] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[8] = a[8] / b[8];
  if(b[9] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[9] = a[9] / b[9];
  return;
}

static void linflp_k24_v_copy_0(double *a, double *out)
{

  return;
}

static void linflp_k24_vsub_10(double *a, double *b, double *out)
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
  return;
}

static void linflp_k24_v_init1_10(double *a)
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
  return;
}

static void linflp_k24_vv_elemult_1(double *a, double *b, double *out)
{

  out[0] = a[0] * b[0];
  return;
}

static void linflp_k24_sv_10(double *a, double *b, double *out)
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
  return;
}

static void linflp_k24_m_copy_3_3(double *a, double *out)
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
  return;
}

static void linflp_k24_m_copy_3_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void linflp_k24_m_init0_3_10(double *a)
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
  return;
}

static void linflp_k24_mtd_sid53_sid17_10_3(double *A, double *B, double *out)
{

      out[0] += A[0] * B[0];
      out[4] += A[11] * B[1];
      out[8] += A[22] * B[2];
      out[9] += A[3] * B[3];
      out[13] += A[14] * B[4];
      out[17] += A[25] * B[5];
      out[24] += A[8] * B[8];
      out[27] += A[9] * B[9];
  return;
}

static void linflp_k24_mm_y_sid14_sid53_3_10_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[9] * B[3];
out[0] += A[24] * B[8];
out[0] += A[27] * B[9];
out[1] += A[1] * B[0];
out[1] += A[10] * B[3];
out[1] += A[25] * B[8];
out[1] += A[28] * B[9];
out[2] += A[2] * B[0];
out[2] += A[11] * B[3];
out[2] += A[26] * B[8];
out[2] += A[29] * B[9];
out[4] += A[4] * B[11];
out[4] += A[13] * B[14];
out[5] += A[5] * B[11];
out[5] += A[14] * B[14];
out[8] += A[8] * B[22];
out[8] += A[17] * B[25];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_mm_sid14_sid56_3_10_2(double *A, double *B, double *out)
{

out[0] += A[18] * B[6];
out[1] += A[19] * B[6];
out[2] += A[20] * B[6];
out[0] += A[21] * B[7];
out[1] += A[22] * B[7];
out[2] += A[23] * B[7];
out[3] += A[24] * B[18];
out[4] += A[25] * B[18];
out[5] += A[26] * B[18];
out[3] += A[27] * B[19];
out[4] += A[28] * B[19];
out[5] += A[29] * B[19];
  return;
}

static void linflp_k24_m_copy_2_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void linflp_k24_m_init0_2_10(double *a)
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
  return;
}

static void linflp_k24_mtd_sid56_sid17_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k24_mm_2_10_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[0] * B[10];
out[3] += A[1] * B[10];
out[0] += A[2] * B[1];
out[1] += A[3] * B[1];
out[2] += A[2] * B[11];
out[3] += A[3] * B[11];
out[0] += A[4] * B[2];
out[1] += A[5] * B[2];
out[2] += A[4] * B[12];
out[3] += A[5] * B[12];
out[0] += A[6] * B[3];
out[1] += A[7] * B[3];
out[2] += A[6] * B[13];
out[3] += A[7] * B[13];
out[0] += A[8] * B[4];
out[1] += A[9] * B[4];
out[2] += A[8] * B[14];
out[3] += A[9] * B[14];
out[0] += A[10] * B[5];
out[1] += A[11] * B[5];
out[2] += A[10] * B[15];
out[3] += A[11] * B[15];
out[0] += A[12] * B[6];
out[1] += A[13] * B[6];
out[2] += A[12] * B[16];
out[3] += A[13] * B[16];
out[0] += A[14] * B[7];
out[1] += A[15] * B[7];
out[2] += A[14] * B[17];
out[3] += A[15] * B[17];
out[0] += A[16] * B[8];
out[1] += A[17] * B[8];
out[2] += A[16] * B[18];
out[3] += A[17] * B[18];
out[0] += A[18] * B[9];
out[1] += A[19] * B[9];
out[2] += A[18] * B[19];
out[3] += A[19] * B[19];
  return;
}

static void linflp_k24_mtr_3_2(double *A, double *out)
{

  out[0] = A[0];
  out[1] = A[3];
  out[2] = A[1];
  out[3] = A[4];
  out[4] = A[2];
  out[5] = A[5];
  return;
}

static void linflp_k24_chol_factor_2(double *a, double *out)
{
  int i,j,k;
double sum;

  for(i=0; i<2; i++)
  {
    for(j=0; j<=i; j++)
    {
      sum = a[i+2*j];
      for(k=0; k<j; k++)
        sum = sum - out[i+2*k]*out[j+2*k];
      if (i > j)
      {
        if(out[j+2*j] == 0){
          linflp_k24_termcode = 8;
          linflp_k24_error_line = __LINE__;
          return;
        }
        out[i+2*j] = sum / out[j+2*j];
      }
      else
      {
        if(sum < 0){
          linflp_k24_termcode = 9;
          linflp_k24_error_line = __LINE__;
          return;
        }
        out[i+2*i] = (double)sqrt(sum);
      }
    }
  }
  return;
}

static void linflp_k24_chol_solve_2_3(double *l, double *b, double *out)
{
  int i,j,k;
  double sum;

  for(k=0; k<3; k++)
  {
    for(i=0; i<2; i++)
    {
      sum = b[i+2*k];
      for(j=0; j<i; j++)
      {
        sum = sum - out[j+2*k]*l[i+2*j];
      }
      if(l[i+2*i] == 0){
        linflp_k24_termcode = 8;
        linflp_k24_error_line = __LINE__;
        return;
      }
      out[i+2*k] = sum / l[i+2*i];
    }
  }
  for(k=0; k<3; k++)
  {
    for(i=1; i>=0; i--)
    {
      sum = out[i+2*k];
      for(j=1; j>i; j--)
      {
        sum = sum - out[j+2*k]*l[2*i+j];
      }
      if(l[2*i+i] == 0){
        linflp_k24_termcode = 8;
        return;
      }
        out[i+2*k] = sum / l[2*i+i];
    }
  }
  return;
}

static void linflp_k24_m_init0_3_3(double *a)
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
  return;
}

static void linflp_k24_mm_y_3_2_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[3] * B[1];
out[1] += A[1] * B[0];
out[1] += A[4] * B[1];
out[2] += A[2] * B[0];
out[2] += A[5] * B[1];
out[4] += A[1] * B[2];
out[4] += A[4] * B[3];
out[5] += A[2] * B[2];
out[5] += A[5] * B[3];
out[8] += A[2] * B[4];
out[8] += A[5] * B[5];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_msub_3_3(double *A, double *B, double *out)
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
  return;
}

static void linflp_k24_mtm_sid43_sid1_3_3_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[3] * B[0];
out[1] += A[4] * B[1];
out[2] += A[6] * B[0];
out[2] += A[7] * B[1];
out[2] += A[8] * B[2];
out[3] += A[0] * B[3];
out[4] += A[3] * B[3];
out[4] += A[4] * B[4];
out[5] += A[6] * B[3];
out[5] += A[7] * B[4];
out[5] += A[8] * B[5];
out[6] += A[0] * B[6];
out[7] += A[3] * B[6];
out[7] += A[4] * B[7];
out[8] += A[6] * B[6];
out[8] += A[7] * B[7];
out[8] += A[8] * B[8];
  return;
}

static void linflp_k24_mm_y_sid1_sid43_3_3_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[4] += A[1] * B[3];
out[4] += A[4] * B[4];
out[5] += A[2] * B[3];
out[5] += A[5] * B[4];
out[8] += A[2] * B[6];
out[8] += A[5] * B[7];
out[8] += A[8] * B[8];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_mm_sid1_sid46_3_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[0] += A[3] * B[1];
out[1] += A[4] * B[1];
out[2] += A[5] * B[1];
out[0] += A[6] * B[2];
out[1] += A[7] * B[2];
out[2] += A[8] * B[2];
  return;
}

static void linflp_k24_mtd_sid52_sid16_10_3(double *A, double *B, double *out)
{

      out[0] += A[0] * B[0];
      out[4] += A[11] * B[1];
      out[8] += A[22] * B[2];
      out[9] += A[3] * B[3];
      out[13] += A[14] * B[4];
      out[17] += A[25] * B[5];
      out[24] += A[8] * B[8];
      out[27] += A[9] * B[9];
  return;
}

static void linflp_k24_mm_y_sid13_sid52_3_10_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[9] * B[3];
out[0] += A[24] * B[8];
out[0] += A[27] * B[9];
out[1] += A[1] * B[0];
out[1] += A[10] * B[3];
out[1] += A[25] * B[8];
out[1] += A[28] * B[9];
out[2] += A[2] * B[0];
out[2] += A[11] * B[3];
out[2] += A[26] * B[8];
out[2] += A[29] * B[9];
out[4] += A[4] * B[11];
out[4] += A[13] * B[14];
out[5] += A[5] * B[11];
out[5] += A[14] * B[14];
out[8] += A[8] * B[22];
out[8] += A[17] * B[25];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_mm_sid13_sid55_3_10_2(double *A, double *B, double *out)
{

out[0] += A[18] * B[6];
out[1] += A[19] * B[6];
out[2] += A[20] * B[6];
out[0] += A[21] * B[7];
out[1] += A[22] * B[7];
out[2] += A[23] * B[7];
out[3] += A[24] * B[18];
out[4] += A[25] * B[18];
out[5] += A[26] * B[18];
out[3] += A[27] * B[19];
out[4] += A[28] * B[19];
out[5] += A[29] * B[19];
  return;
}

static void linflp_k24_m_init0_2_3(double *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  return;
}

static void linflp_k24_mtm_sid46_sid1_3_2_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[2] += A[0] * B[3];
out[2] += A[1] * B[4];
out[2] += A[2] * B[5];
out[4] += A[0] * B[6];
out[4] += A[1] * B[7];
out[4] += A[2] * B[8];
  return;
}

static void linflp_k24_mm_sid8_sid46_2_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[0] += A[2] * B[1];
out[1] += A[3] * B[1];
out[0] += A[4] * B[2];
out[1] += A[5] * B[2];
  return;
}

static void linflp_k24_mtd_sid55_sid16_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k24_mtm_sid42_sid1_3_3_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[3] * B[0];
out[1] += A[4] * B[1];
out[2] += A[6] * B[0];
out[2] += A[7] * B[1];
out[2] += A[8] * B[2];
out[3] += A[0] * B[3];
out[4] += A[3] * B[3];
out[4] += A[4] * B[4];
out[5] += A[6] * B[3];
out[5] += A[7] * B[4];
out[5] += A[8] * B[5];
out[6] += A[0] * B[6];
out[7] += A[3] * B[6];
out[7] += A[4] * B[7];
out[8] += A[6] * B[6];
out[8] += A[7] * B[7];
out[8] += A[8] * B[8];
  return;
}

static void linflp_k24_mm_y_sid1_sid42_3_3_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[4] += A[1] * B[3];
out[4] += A[4] * B[4];
out[5] += A[2] * B[3];
out[5] += A[5] * B[4];
out[8] += A[2] * B[6];
out[8] += A[5] * B[7];
out[8] += A[8] * B[8];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_mm_sid1_sid45_3_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[2] += A[2] * B[0];
out[0] += A[3] * B[1];
out[1] += A[4] * B[1];
out[2] += A[5] * B[1];
out[0] += A[6] * B[2];
out[1] += A[7] * B[2];
out[2] += A[8] * B[2];
  return;
}

static void linflp_k24_mtd_sid51_sid15_10_3(double *A, double *B, double *out)
{

      out[0] += A[0] * B[0];
      out[4] += A[11] * B[1];
      out[8] += A[22] * B[2];
      out[9] += A[3] * B[3];
      out[13] += A[14] * B[4];
      out[17] += A[25] * B[5];
      out[24] += A[8] * B[8];
      out[27] += A[9] * B[9];
  return;
}

static void linflp_k24_mm_y_sid12_sid51_3_10_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[9] * B[3];
out[0] += A[24] * B[8];
out[0] += A[27] * B[9];
out[1] += A[1] * B[0];
out[1] += A[10] * B[3];
out[1] += A[25] * B[8];
out[1] += A[28] * B[9];
out[2] += A[2] * B[0];
out[2] += A[11] * B[3];
out[2] += A[26] * B[8];
out[2] += A[29] * B[9];
out[4] += A[4] * B[11];
out[4] += A[13] * B[14];
out[5] += A[5] * B[11];
out[5] += A[14] * B[14];
out[8] += A[8] * B[22];
out[8] += A[17] * B[25];
out[3] = out[1];
out[6] = out[2];
out[7] = out[5];
  return;
}

static void linflp_k24_mm_sid12_sid54_3_10_2(double *A, double *B, double *out)
{

out[0] += A[18] * B[6];
out[1] += A[19] * B[6];
out[2] += A[20] * B[6];
out[0] += A[21] * B[7];
out[1] += A[22] * B[7];
out[2] += A[23] * B[7];
out[3] += A[24] * B[18];
out[4] += A[25] * B[18];
out[5] += A[26] * B[18];
out[3] += A[27] * B[19];
out[4] += A[28] * B[19];
out[5] += A[29] * B[19];
  return;
}

static void linflp_k24_mtm_sid45_sid1_3_2_3(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[0] += A[1] * B[1];
out[0] += A[2] * B[2];
out[2] += A[0] * B[3];
out[2] += A[1] * B[4];
out[2] += A[2] * B[5];
out[4] += A[0] * B[6];
out[4] += A[1] * B[7];
out[4] += A[2] * B[8];
  return;
}

static void linflp_k24_mm_sid8_sid45_2_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[0] += A[2] * B[1];
out[1] += A[3] * B[1];
out[0] += A[4] * B[2];
out[1] += A[5] * B[2];
  return;
}

static void linflp_k24_mtd_sid54_sid15_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k24_chol_solve_2_1(double *l, double *b, double *out)
{
  int i,j,k;
  double sum;

  for(k=0; k<1; k++)
  {
    for(i=0; i<2; i++)
    {
      sum = b[i+2*k];
      for(j=0; j<i; j++)
      {
        sum = sum - out[j+2*k]*l[i+2*j];
      }
      if(l[i+2*i] == 0){
        linflp_k24_termcode = 8;
        linflp_k24_error_line = __LINE__;
        return;
      }
      out[i+2*k] = sum / l[i+2*i];
    }
  }
  for(k=0; k<1; k++)
  {
    for(i=1; i>=0; i--)
    {
      sum = out[i+2*k];
      for(j=1; j>i; j--)
      {
        sum = sum - out[j+2*k]*l[2*i+j];
      }
      if(l[2*i+i] == 0){
        linflp_k24_termcode = 8;
        return;
      }
        out[i+2*k] = sum / l[2*i+i];
    }
  }
  return;
}

static void linflp_k24_v_init0_3(double *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
  return;
}

static void linflp_k24_mv_3_2(double *A, double *b, double *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[0] += A[3] * b[1];
      out[1] += A[4] * b[1];
      out[2] += A[5] * b[1];
  return;
}

static void linflp_k24_mv_3_3(double *A, double *b, double *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[0] += A[3] * b[1];
      out[1] += A[4] * b[1];
      out[2] += A[5] * b[1];
      out[0] += A[6] * b[2];
      out[1] += A[7] * b[2];
      out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mv_2_3(double *A, double *b, double *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[0] += A[2] * b[1];
      out[1] += A[3] * b[1];
      out[0] += A[4] * b[2];
      out[1] += A[5] * b[2];
  return;
}

static void linflp_k24_v_turnsign_2(double *a, double *out)
{

    out[0] = -a[0];
    out[1] = -a[1];
  return;
}

static void linflp_k24_mv_sid42_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k24_mv_sid45_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k24_m_copy_0_1(double *a, double *out)
{

  return;
}

static void linflp_k24_m_copy_10_1(double *a, double *out)
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
  return;
}

static void linflp_k24_v_turnsign_10(double *a, double *out)
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
  return;
}

static void linflp_k24_vadd_3(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  return;
}

static void linflp_k24_vadd_2(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  return;
}

static void linflp_k24_v_init0_1(double *a)
{

    a[0] =0;
  return;
}

static void linflp_k24_vtv_3(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  return;
}

static void linflp_k24_v_init0_2(double *a)
{

    a[0] =0;
    a[1] =0;
  return;
}

static void linflp_k24_vtv_2(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  return;
}

static void linflp_k24_vsub_1(double *a, double *b, double *out)
{

  out[0] = a[0] - b[0];
  return;
}

static void linflp_k24_vtv_10(double *a, double *b, double *out)
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
  return;
}

static void linflp_k24_vv_elediv_1(double *a, double *b, double *out)
{

  if(b[0] == 0){ linflp_k24_termcode = 8; linflp_k24_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  return;
}

static void linflp_k24_v_copy_1(double *a, double *out)
{

  out[0] = a[0];
  return;
}

static void linflp_k24_vadd_1(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  return;
}

static void linflp_k24_min(double *a, double *b, double *out)
{

  if  (a[0] < b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void linflp_k24_v_turnsign_1(double *a, double *out)
{

    out[0] = -a[0];
  return;
}

static void linflp_k24_v_init1_1(double *a)
{

    a[0] =1;
  return;
}

static void linflp_k24_max(double *a, double *b, double *out)
{

  if  (a[0] > b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void linflp_k24_sv_3(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  return;
}

static void linflp_k24_sv_2(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  return;
}

static void linflp_k24_norm_inf_3_3(double *A, double *B, double *out)
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
  return;
}

static void linflp_k24_norm_inf_3_2(double *A, double *B, double *out)
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

static void linflp_k24_norm_inf_2_2(double *A, double *B, double *out)
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

static void linflp_k24_norm_inf_3_1(double *A, double *B, double *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  if (A[2] > out[0]) out[0] = A[2];
  if (-A[2] > out[0]) out[0] = A[2];
  return;
}

static void linflp_k24_norm_inf_2_1(double *A, double *B, double *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  return;
}

static void linflp_k24_norm_inf_10_3(double *A, double *B, double *out)
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
  return;
}

static void linflp_k24_norm_inf_10_2(double *A, double *B, double *out)
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
  return;
}

static void linflp_k24_norm_inf_10_1(double *A, double *B, double *out)
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
  return;
}


/* ########################### */
/* Diese Funktion berechnet mu */
/* ########################### */
static void linflp_k24_glqdocpip_calc_mu()
{
linflp_k24_v_init0_1(linflp_k24_mu);
/* mu = mu + y*nu */
/* Zeitschritt 0 */
linflp_k24_vtv_10(linflp_k24_y0, linflp_k24_nu0, linflp_k24_mu);
/* Zeitschritt 1 */
linflp_k24_vtv_10(linflp_k24_y1, linflp_k24_nu1, linflp_k24_mu);
/* Zeitschritt 2 */
linflp_k24_vtv_10(linflp_k24_y2, linflp_k24_nu2, linflp_k24_mu);
/* Zeitschritt 3 */
linflp_k24_vtv_10(linflp_k24_y3, linflp_k24_nu3, linflp_k24_mu);
/* Zeitschritt 4 */
linflp_k24_vtv_10(linflp_k24_y4, linflp_k24_nu4, linflp_k24_mu);
/* Zeitschritt 5 */
linflp_k24_vtv_10(linflp_k24_y5, linflp_k24_nu5, linflp_k24_mu);
/* Zeitschritt 6 */
linflp_k24_vtv_10(linflp_k24_y6, linflp_k24_nu6, linflp_k24_mu);
/* Zeitschritt 7 */
linflp_k24_vtv_10(linflp_k24_y7, linflp_k24_nu7, linflp_k24_mu);
/* Zeitschritt 8 */
linflp_k24_vtv_10(linflp_k24_y8, linflp_k24_nu8, linflp_k24_mu);
/* Zeitschritt 9 */
linflp_k24_vtv_10(linflp_k24_y9, linflp_k24_nu9, linflp_k24_mu);
/* Zeitschritt 10 */
linflp_k24_vtv_10(linflp_k24_y10, linflp_k24_nu10, linflp_k24_mu);
/* Zeitschritt 11 */
linflp_k24_vtv_10(linflp_k24_y11, linflp_k24_nu11, linflp_k24_mu);
/* Zeitschritt 12 */
linflp_k24_vtv_10(linflp_k24_y12, linflp_k24_nu12, linflp_k24_mu);
/* Zeitschritt 13 */
linflp_k24_vtv_10(linflp_k24_y13, linflp_k24_nu13, linflp_k24_mu);
/* Zeitschritt 14 */
linflp_k24_vtv_10(linflp_k24_y14, linflp_k24_nu14, linflp_k24_mu);
/* Zeitschritt 15 */
linflp_k24_vtv_10(linflp_k24_y15, linflp_k24_nu15, linflp_k24_mu);
/* Zeitschritt 16 */
linflp_k24_vtv_10(linflp_k24_y16, linflp_k24_nu16, linflp_k24_mu);
/* Zeitschritt 17 */
linflp_k24_vtv_10(linflp_k24_y17, linflp_k24_nu17, linflp_k24_mu);
/* Zeitschritt 18 */
linflp_k24_vtv_10(linflp_k24_y18, linflp_k24_nu18, linflp_k24_mu);
/* Zeitschritt 19 */
linflp_k24_vtv_10(linflp_k24_y19, linflp_k24_nu19, linflp_k24_mu);
/* Zeitschritt 20 */
linflp_k24_vtv_10(linflp_k24_y20, linflp_k24_nu20, linflp_k24_mu);
/* Zeitschritt 21 */
linflp_k24_vtv_10(linflp_k24_y21, linflp_k24_nu21, linflp_k24_mu);
/* Zeitschritt 22 */
linflp_k24_vtv_10(linflp_k24_y22, linflp_k24_nu22, linflp_k24_mu);
/* Zeitschritt 23 */
linflp_k24_vtv_10(linflp_k24_y23, linflp_k24_nu23, linflp_k24_mu);
/* Zeitschritt 24 */
linflp_k24_vtv_10(linflp_k24_y24, linflp_k24_nu24, linflp_k24_mu);
linflp_k24_vv_elediv_1(linflp_k24_mu, linflp_k24_m_ineq, linflp_k24_mu);
if(linflp_k24_termcode > -1){return;}

/* mu0 bestimmen */
if(linflp_k24_iter == 0){
linflp_k24_v_copy_1(linflp_k24_mu, linflp_k24_mu0);
}
}


/* ############################### */
/* Diese Funktion berechnet mu_aff */
/* ############################### */
static void linflp_k24_glqdocpip_calc_mu_aff()
{
linflp_k24_v_init0_1(linflp_k24_mu_aff);
/* Zeitschritt 0 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y0, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy0, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu0, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu0, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 1 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y1, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy1, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu1, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu1, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 2 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y2, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy2, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu2, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu2, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 3 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y3, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy3, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu3, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu3, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 4 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y4, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy4, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu4, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu4, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 5 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y5, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy5, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu5, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu5, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 6 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y6, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy6, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu6, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu6, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 7 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y7, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy7, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu7, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu7, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 8 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y8, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy8, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu8, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu8, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 9 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y9, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy9, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu9, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu9, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 10 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y10, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy10, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu10, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu10, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 11 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y11, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy11, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu11, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu11, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 12 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y12, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy12, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu12, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu12, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 13 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y13, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy13, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu13, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu13, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 14 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y14, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy14, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu14, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu14, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 15 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y15, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy15, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu15, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu15, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 16 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y16, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy16, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu16, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu16, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 17 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y17, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy17, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu17, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu17, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 18 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y18, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy18, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu18, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu18, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 19 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y19, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy19, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu19, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu19, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 20 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y20, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy20, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu20, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu20, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 21 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y21, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy21, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu21, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu21, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 22 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y22, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy22, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu22, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu22, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
/* Zeitschritt 23 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y23, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy23, linflp_k24_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu23, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu23, linflp_k24_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp1_10, linflp_k24_tmp2_10, linflp_k24_mu_aff);
/* Zeitschritt 24 */
/* yady = y + alpha_max*dy */
linflp_k24_v_copy_10(linflp_k24_y24, linflp_k24_tmp2_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dy24, linflp_k24_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k24_v_copy_10(linflp_k24_nu24, linflp_k24_tmp1_10);
linflp_k24_sv_10(linflp_k24_alpha_max, linflp_k24_dnu24, linflp_k24_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k24_vtv_10(linflp_k24_tmp2_10, linflp_k24_tmp1_10, linflp_k24_mu_aff);
linflp_k24_vv_elediv_1(linflp_k24_mu_aff, linflp_k24_m_ineq, linflp_k24_mu_aff);
if(linflp_k24_termcode > -1){return;}
}


/* ############################ */
/* Diese Funktion berechnet phi */
/* ############################ */
static void linflp_k24_glqdocpip_calc_phi()
{
linflp_k24_vadd_1(linflp_k24_norm_r, linflp_k24_dgap, linflp_k24_phi);
linflp_k24_vv_elediv_1(linflp_k24_phi, linflp_k24_norm_d, linflp_k24_phi);
if(linflp_k24_termcode > -1){return;}
if (linflp_k24_iter > 0) {

linflp_k24_min(linflp_k24_minphi, linflp_k24_phi, linflp_k24_minphi);
}else{
linflp_k24_v_copy_1(linflp_k24_phi, linflp_k24_minphi);
}
}


/* ######################################################## */
/* Diese Funktion berechnet den Zentrierungsparameter sigma */
/* ######################################################## */
static void linflp_k24_glqdocpip_calc_sigma()
{
linflp_k24_vv_elediv_1(linflp_k24_mu_aff, linflp_k24_mu, linflp_k24_tmp1_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_sigma[0] = pow(*linflp_k24_tmp1_1, *linflp_k24_tau);
}


/* ########################################################### */
/* Diese Funktion berechnet die maximal mögliche Schrittweite, */
/* bei der y und nu noch positiv bleiben */
/* ########################################################### */
static void linflp_k24_glqdocpip_max_stepsize()
{
int i;

linflp_k24_alpha_max[0] = -DBL_MAX;
linflp_k24_alpha_tmp[0] = 0;

/* Zeitschritt 0 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy0[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y0[i], &linflp_k24_dy0[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y0[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy0[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu0[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu0[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu0[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu0[i], &linflp_k24_dnu0[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y0[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy0[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu0[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu0[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 1 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy1[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y1[i], &linflp_k24_dy1[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y1[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy1[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu1[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu1[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu1[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu1[i], &linflp_k24_dnu1[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y1[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy1[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu1[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu1[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 2 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy2[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y2[i], &linflp_k24_dy2[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y2[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy2[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu2[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu2[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu2[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu2[i], &linflp_k24_dnu2[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y2[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy2[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu2[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu2[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 3 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy3[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y3[i], &linflp_k24_dy3[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y3[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy3[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu3[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu3[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu3[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu3[i], &linflp_k24_dnu3[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y3[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy3[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu3[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu3[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 4 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy4[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y4[i], &linflp_k24_dy4[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y4[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy4[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu4[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu4[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu4[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu4[i], &linflp_k24_dnu4[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y4[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy4[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu4[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu4[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 5 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy5[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y5[i], &linflp_k24_dy5[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y5[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy5[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu5[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu5[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu5[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu5[i], &linflp_k24_dnu5[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y5[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy5[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu5[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu5[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 6 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy6[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y6[i], &linflp_k24_dy6[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y6[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy6[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu6[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu6[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu6[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu6[i], &linflp_k24_dnu6[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y6[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy6[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu6[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu6[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 7 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy7[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y7[i], &linflp_k24_dy7[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y7[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy7[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu7[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu7[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu7[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu7[i], &linflp_k24_dnu7[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y7[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy7[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu7[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu7[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 8 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy8[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y8[i], &linflp_k24_dy8[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y8[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy8[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu8[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu8[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu8[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu8[i], &linflp_k24_dnu8[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y8[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy8[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu8[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu8[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 9 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy9[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y9[i], &linflp_k24_dy9[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y9[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy9[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu9[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu9[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu9[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu9[i], &linflp_k24_dnu9[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y9[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy9[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu9[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu9[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 10 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy10[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y10[i], &linflp_k24_dy10[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y10[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy10[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu10[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu10[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu10[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu10[i], &linflp_k24_dnu10[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y10[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy10[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu10[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu10[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 11 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy11[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y11[i], &linflp_k24_dy11[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y11[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy11[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu11[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu11[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu11[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu11[i], &linflp_k24_dnu11[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y11[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy11[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu11[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu11[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 12 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy12[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y12[i], &linflp_k24_dy12[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y12[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy12[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu12[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu12[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu12[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu12[i], &linflp_k24_dnu12[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y12[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy12[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu12[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu12[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 13 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy13[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y13[i], &linflp_k24_dy13[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y13[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy13[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu13[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu13[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu13[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu13[i], &linflp_k24_dnu13[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y13[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy13[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu13[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu13[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 14 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy14[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y14[i], &linflp_k24_dy14[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y14[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy14[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu14[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu14[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu14[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu14[i], &linflp_k24_dnu14[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y14[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy14[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu14[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu14[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 15 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy15[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y15[i], &linflp_k24_dy15[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y15[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy15[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu15[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu15[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu15[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu15[i], &linflp_k24_dnu15[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y15[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy15[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu15[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu15[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 16 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy16[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y16[i], &linflp_k24_dy16[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y16[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy16[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu16[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu16[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu16[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu16[i], &linflp_k24_dnu16[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y16[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy16[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu16[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu16[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 17 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy17[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y17[i], &linflp_k24_dy17[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y17[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy17[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu17[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu17[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu17[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu17[i], &linflp_k24_dnu17[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y17[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy17[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu17[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu17[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 18 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy18[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y18[i], &linflp_k24_dy18[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y18[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy18[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu18[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu18[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu18[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu18[i], &linflp_k24_dnu18[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y18[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy18[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu18[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu18[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 19 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy19[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y19[i], &linflp_k24_dy19[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y19[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy19[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu19[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu19[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu19[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu19[i], &linflp_k24_dnu19[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y19[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy19[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu19[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu19[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 20 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy20[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y20[i], &linflp_k24_dy20[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y20[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy20[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu20[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu20[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu20[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu20[i], &linflp_k24_dnu20[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y20[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy20[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu20[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu20[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 21 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy21[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y21[i], &linflp_k24_dy21[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y21[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy21[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu21[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu21[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu21[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu21[i], &linflp_k24_dnu21[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y21[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy21[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu21[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu21[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 22 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy22[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y22[i], &linflp_k24_dy22[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y22[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy22[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu22[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu22[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu22[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu22[i], &linflp_k24_dnu22[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y22[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy22[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu22[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu22[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 23 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy23[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y23[i], &linflp_k24_dy23[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y23[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy23[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu23[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu23[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu23[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu23[i], &linflp_k24_dnu23[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y23[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy23[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu23[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu23[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 24 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k24_dy24[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_y24[i], &linflp_k24_dy24[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y24[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy24[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu24[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu24[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k24_dnu24[i] < 0)
{
linflp_k24_vv_elediv_1(&linflp_k24_nu24[i], &linflp_k24_dnu24[i], linflp_k24_alpha_tmp);
if(linflp_k24_termcode > -1){return;}
if( *linflp_k24_alpha_tmp > *linflp_k24_alpha_max )
{
linflp_k24_alpha_max[0] = *linflp_k24_alpha_tmp;
linflp_k24_v_copy_1(&linflp_k24_y24[i], &linflp_k24_alpha_min_y[0]);
linflp_k24_v_copy_1(&linflp_k24_dy24[i], &linflp_k24_alpha_min_dy[0]);
linflp_k24_v_copy_1(&linflp_k24_nu24[i], &linflp_k24_alpha_min_nu[0]);
linflp_k24_v_copy_1(&linflp_k24_dnu24[i], &linflp_k24_alpha_min_dnu[0]);
linflp_k24_alpha_min_source_y = 0;
}
}
}

linflp_k24_v_turnsign_1(&linflp_k24_alpha_max[0], &linflp_k24_alpha_max[0]);
}


/* ####################################################### */
/* Diese Funktion berechnet die Schrittweite nach Mehrotra */
/* ####################################################### */
static void linflp_k24_glqdocpip_mehrotra_step()
{

/* FPD */
if (linflp_k24_alpha_min_source_y == 1) {
/* alpha_max durch y verursacht */
linflp_k24_vv_elemult_1(linflp_k24_alpha_max, linflp_k24_alpha_min_dnu, linflp_k24_mehrotra_fpd);
linflp_k24_vadd_1(linflp_k24_mehrotra_fpd, linflp_k24_alpha_min_nu, linflp_k24_mehrotra_fpd);
linflp_k24_vv_elediv_1(linflp_k24_mu_aff, linflp_k24_mehrotra_fpd, linflp_k24_mehrotra_fpd);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vv_elemult_1(linflp_k24_mehrotra_fpd, linflp_k24_mehrotra_gamma, linflp_k24_mehrotra_fpd);
linflp_k24_vsub_1(linflp_k24_mehrotra_fpd, linflp_k24_alpha_min_y, linflp_k24_mehrotra_fpd);
linflp_k24_vv_elemult_1(linflp_k24_alpha_max, linflp_k24_alpha_min_dy, linflp_k24_tmp1_1);
linflp_k24_vv_elediv_1(linflp_k24_mehrotra_fpd, linflp_k24_tmp1_1, linflp_k24_mehrotra_fpd);
if(linflp_k24_termcode > -1){return;}
} else {
/* alpha_max durch nu verursacht */
linflp_k24_vv_elemult_1(linflp_k24_alpha_max, linflp_k24_alpha_min_dy, linflp_k24_mehrotra_fpd);
linflp_k24_vadd_1(linflp_k24_mehrotra_fpd, linflp_k24_alpha_min_y, linflp_k24_mehrotra_fpd);
linflp_k24_vv_elediv_1(linflp_k24_mu_aff, linflp_k24_mehrotra_fpd, linflp_k24_mehrotra_fpd);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vv_elemult_1(linflp_k24_mehrotra_fpd, linflp_k24_mehrotra_gamma, linflp_k24_mehrotra_fpd);
linflp_k24_vsub_1(linflp_k24_mehrotra_fpd, linflp_k24_alpha_min_nu, linflp_k24_mehrotra_fpd);
linflp_k24_vv_elemult_1(linflp_k24_alpha_max, linflp_k24_alpha_min_dnu, linflp_k24_tmp1_1);
linflp_k24_vv_elediv_1(linflp_k24_mehrotra_fpd, linflp_k24_tmp1_1, linflp_k24_mehrotra_fpd);
if(linflp_k24_termcode > -1){return;}
}
/* Schrittweitenfaktor begrenzen */
/* Nach unten limitieren (1-gamma) */
linflp_k24_v_init1_1(linflp_k24_tmp1_1);
linflp_k24_vsub_1(linflp_k24_tmp1_1, linflp_k24_mehrotra_gamma, linflp_k24_tmp1_1);
linflp_k24_max(linflp_k24_mehrotra_fpd, linflp_k24_tmp1_1, linflp_k24_mehrotra_fpd);
/* nach oben limitieren (1-macheps) */
linflp_k24_v_init1_1(linflp_k24_tmp1_1);
linflp_k24_vsub_1(linflp_k24_tmp1_1, linflp_k24_macheps, linflp_k24_tmp1_1);
linflp_k24_min(linflp_k24_mehrotra_fpd, linflp_k24_tmp1_1, linflp_k24_mehrotra_fpd);
/* Schrittweite berechnen */
linflp_k24_vv_elemult_1(linflp_k24_mehrotra_fpd, linflp_k24_alpha_max, linflp_k24_mehrotra_alpha);
/* Schritt begrenzen 0 =< alpha =< 1 */
linflp_k24_v_init0_1(linflp_k24_tmp1_1);
linflp_k24_max(linflp_k24_mehrotra_alpha, linflp_k24_tmp1_1, linflp_k24_mehrotra_alpha);
linflp_k24_v_init1_1(linflp_k24_tmp1_1);
linflp_k24_min(linflp_k24_mehrotra_alpha, linflp_k24_tmp1_1, linflp_k24_mehrotra_alpha);
}


/* ########################################### */
/* Diese Funktion berechnet die Dualitätslücke */
/* ########################################### */
static void linflp_k24_glqdocpip_calc_duality_gap()
{
linflp_k24_v_init0_1(linflp_k24_dgap);
/* Zeitschritt 0 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid21_sid2_3_3(linflp_k24_Hxx0, linflp_k24_x0, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x0, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid24_sid5_3_2(linflp_k24_Hxu0, linflp_k24_u0, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x0, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x0, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid27_sid5_2_2(linflp_k24_Huu0, linflp_k24_u0, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u0, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x0, linflp_k24_x0, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u0, linflp_k24_u0, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_xinit, linflp_k24_p0, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g0, linflp_k24_y0, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 1 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx1, linflp_k24_x1, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x1, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu1, linflp_k24_u1, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x1, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x1, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu1, linflp_k24_u1, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u1, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x1, linflp_k24_x1, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u1, linflp_k24_u1, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f0, linflp_k24_p1, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g1, linflp_k24_y1, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 2 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx2, linflp_k24_x2, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x2, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu2, linflp_k24_u2, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x2, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x2, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu2, linflp_k24_u2, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u2, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x2, linflp_k24_x2, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u2, linflp_k24_u2, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f1, linflp_k24_p2, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g2, linflp_k24_y2, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 3 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx3, linflp_k24_x3, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x3, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu3, linflp_k24_u3, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x3, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x3, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu3, linflp_k24_u3, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u3, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x3, linflp_k24_x3, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u3, linflp_k24_u3, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f2, linflp_k24_p3, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g3, linflp_k24_y3, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 4 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx4, linflp_k24_x4, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x4, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu4, linflp_k24_u4, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x4, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x4, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu4, linflp_k24_u4, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u4, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x4, linflp_k24_x4, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u4, linflp_k24_u4, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f3, linflp_k24_p4, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g4, linflp_k24_y4, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 5 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx5, linflp_k24_x5, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x5, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu5, linflp_k24_u5, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x5, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x5, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu5, linflp_k24_u5, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u5, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x5, linflp_k24_x5, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u5, linflp_k24_u5, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f4, linflp_k24_p5, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g5, linflp_k24_y5, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 6 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx6, linflp_k24_x6, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x6, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu6, linflp_k24_u6, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x6, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x6, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu6, linflp_k24_u6, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u6, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x6, linflp_k24_x6, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u6, linflp_k24_u6, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f5, linflp_k24_p6, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g6, linflp_k24_y6, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 7 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx7, linflp_k24_x7, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x7, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu7, linflp_k24_u7, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x7, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x7, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu7, linflp_k24_u7, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u7, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x7, linflp_k24_x7, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u7, linflp_k24_u7, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f6, linflp_k24_p7, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g7, linflp_k24_y7, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 8 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx8, linflp_k24_x8, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x8, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu8, linflp_k24_u8, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x8, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x8, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu8, linflp_k24_u8, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u8, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x8, linflp_k24_x8, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u8, linflp_k24_u8, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f7, linflp_k24_p8, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g8, linflp_k24_y8, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 9 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx9, linflp_k24_x9, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x9, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu9, linflp_k24_u9, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x9, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x9, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu9, linflp_k24_u9, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u9, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x9, linflp_k24_x9, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u9, linflp_k24_u9, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f8, linflp_k24_p9, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g9, linflp_k24_y9, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 10 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx10, linflp_k24_x10, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x10, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu10, linflp_k24_u10, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x10, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x10, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu10, linflp_k24_u10, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u10, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x10, linflp_k24_x10, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u10, linflp_k24_u10, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f9, linflp_k24_p10, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g10, linflp_k24_y10, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 11 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx11, linflp_k24_x11, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x11, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu11, linflp_k24_u11, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x11, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x11, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu11, linflp_k24_u11, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u11, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x11, linflp_k24_x11, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u11, linflp_k24_u11, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f10, linflp_k24_p11, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g11, linflp_k24_y11, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 12 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx12, linflp_k24_x12, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x12, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu12, linflp_k24_u12, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x12, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x12, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu12, linflp_k24_u12, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u12, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x12, linflp_k24_x12, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u12, linflp_k24_u12, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f11, linflp_k24_p12, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g12, linflp_k24_y12, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 13 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx13, linflp_k24_x13, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x13, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu13, linflp_k24_u13, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x13, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x13, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu13, linflp_k24_u13, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u13, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x13, linflp_k24_x13, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u13, linflp_k24_u13, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f12, linflp_k24_p13, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g13, linflp_k24_y13, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 14 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx14, linflp_k24_x14, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x14, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu14, linflp_k24_u14, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x14, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x14, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu14, linflp_k24_u14, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u14, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x14, linflp_k24_x14, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u14, linflp_k24_u14, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f13, linflp_k24_p14, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g14, linflp_k24_y14, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 15 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx15, linflp_k24_x15, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x15, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu15, linflp_k24_u15, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x15, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x15, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu15, linflp_k24_u15, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u15, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x15, linflp_k24_x15, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u15, linflp_k24_u15, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f14, linflp_k24_p15, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g15, linflp_k24_y15, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 16 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx16, linflp_k24_x16, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x16, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu16, linflp_k24_u16, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x16, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x16, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu16, linflp_k24_u16, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u16, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x16, linflp_k24_x16, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u16, linflp_k24_u16, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f15, linflp_k24_p16, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g16, linflp_k24_y16, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 17 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx17, linflp_k24_x17, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x17, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu17, linflp_k24_u17, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x17, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x17, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu17, linflp_k24_u17, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u17, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x17, linflp_k24_x17, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u17, linflp_k24_u17, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f16, linflp_k24_p17, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g17, linflp_k24_y17, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 18 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx18, linflp_k24_x18, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x18, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu18, linflp_k24_u18, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x18, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x18, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu18, linflp_k24_u18, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u18, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x18, linflp_k24_x18, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u18, linflp_k24_u18, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f17, linflp_k24_p18, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g18, linflp_k24_y18, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 19 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx19, linflp_k24_x19, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x19, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu19, linflp_k24_u19, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x19, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x19, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu19, linflp_k24_u19, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u19, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x19, linflp_k24_x19, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u19, linflp_k24_u19, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f18, linflp_k24_p19, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g19, linflp_k24_y19, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 20 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx20, linflp_k24_x20, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x20, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu20, linflp_k24_u20, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x20, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x20, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu20, linflp_k24_u20, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u20, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x20, linflp_k24_x20, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u20, linflp_k24_u20, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f19, linflp_k24_p20, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g20, linflp_k24_y20, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 21 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx21, linflp_k24_x21, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x21, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu21, linflp_k24_u21, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x21, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x21, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu21, linflp_k24_u21, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u21, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x21, linflp_k24_x21, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u21, linflp_k24_u21, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f20, linflp_k24_p21, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g21, linflp_k24_y21, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 22 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx22, linflp_k24_x22, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x22, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu22, linflp_k24_u22, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x22, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x22, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu22, linflp_k24_u22, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u22, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x22, linflp_k24_x22, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u22, linflp_k24_u22, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f21, linflp_k24_p22, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g22, linflp_k24_y22, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 23 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx23, linflp_k24_x23, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x23, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu23, linflp_k24_u23, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x23, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x23, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu23, linflp_k24_u23, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u23, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x23, linflp_k24_x23, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u23, linflp_k24_u23, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f22, linflp_k24_p23, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g23, linflp_k24_y23, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Zeitschritt 24 */
/* Quadratischer Anteil */
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid23_sid2_3_3(linflp_k24_Hxx24, linflp_k24_x24, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x24, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_3(linflp_k24_tmp1_3_1);
linflp_k24_mv_sid26_sid5_3_2(linflp_k24_Hxu24, linflp_k24_u24, linflp_k24_tmp1_3_1);
linflp_k24_vtv_3(linflp_k24_x24, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_vtv_3(linflp_k24_x24, linflp_k24_tmp1_3_1, linflp_k24_dgap);
linflp_k24_v_init0_2(linflp_k24_tmp1_2_1);
linflp_k24_mv_sid29_sid5_2_2(linflp_k24_Huu24, linflp_k24_u24, linflp_k24_tmp1_2_1);
linflp_k24_vtv_2(linflp_k24_u24, linflp_k24_tmp1_2_1, linflp_k24_dgap);
/* Linearer Anteil */
linflp_k24_vtv_3(linflp_k24_f0x24, linflp_k24_x24, linflp_k24_dgap);
linflp_k24_vtv_2(linflp_k24_f0u24, linflp_k24_u24, linflp_k24_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_3(linflp_k24_f23, linflp_k24_p24, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k24_v_init0_1(linflp_k24_tmp1_1_1);
linflp_k24_vtv_10(linflp_k24_g24, linflp_k24_y24, linflp_k24_tmp1_1_1);
linflp_k24_vsub_1(linflp_k24_dgap, linflp_k24_tmp1_1_1, linflp_k24_dgap);
/* dgap = abs(dgap) */
if(linflp_k24_dgap[0] < 0){
linflp_k24_dgap[0] = -linflp_k24_dgap[0];}
}


/* ############################################################ */
/* Diese Funktion berechnet die Unendlichnorm der Eingangsdaten */
/* ############################################################ */
static void linflp_k24_glqdocpip_calc_norm_d()
{
linflp_k24_v_init0_1(linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u0, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu0, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g0, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u1, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f1, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu1, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g1, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u2, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f2, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu2, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g2, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u3, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f3, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu3, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g3, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u4, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f4, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu4, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g4, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u5, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f5, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu5, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g5, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u6, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f6, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu6, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g6, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u7, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f7, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu7, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g7, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u8, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f8, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu8, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g8, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u9, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f9, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu9, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g9, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u10, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f10, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu10, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g10, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u11, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f11, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu11, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g11, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u12, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f12, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu12, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g12, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u13, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f13, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu13, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g13, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u14, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f14, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu14, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g14, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u15, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f15, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu15, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g15, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u16, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f16, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu16, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g16, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u17, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f17, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu17, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g17, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u18, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f18, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu18, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g18, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u19, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f19, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu19, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g19, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u20, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f20, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu20, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g20, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u21, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f21, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu21, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g21, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u22, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f22, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu22, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g22, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u23, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f23, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu23, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g23, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_3(linflp_k24_Hxx24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_Hxu24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_2(linflp_k24_Huu24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f0x24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_2_1(linflp_k24_f0u24, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k24_norm_inf_3_3(linflp_k24_fx24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_2(linflp_k24_fu24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_3_1(linflp_k24_f24, linflp_k24_norm_d, linflp_k24_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k24_norm_inf_10_3(linflp_k24_gx24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_2(linflp_k24_gu24, linflp_k24_norm_d, linflp_k24_norm_d);
linflp_k24_norm_inf_10_1(linflp_k24_g24, linflp_k24_norm_d, linflp_k24_norm_d);
}


/* ############################################################# */
/* Diese Funktion berechnet die Unendlichnorm der rechten Seiten */
/* ############################################################# */
static void linflp_k24_glqdocpip_calc_norm_r()
{
/* norm_r_prev bestimmen */
if(linflp_k24_iter > 0){
linflp_k24_v_copy_1(linflp_k24_norm_r, linflp_k24_norm_r_prev);
}
linflp_k24_v_init0_1(linflp_k24_norm_r);
/* Zeitschritt 0 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x0, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u0, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf0, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc0, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk0, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 1 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x1, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u1, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf1, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc1, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk1, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 2 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x2, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u2, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf2, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc2, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk2, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 3 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x3, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u3, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf3, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc3, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk3, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 4 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x4, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u4, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf4, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc4, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk4, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 5 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x5, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u5, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf5, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc5, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk5, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 6 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x6, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u6, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf6, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc6, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk6, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 7 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x7, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u7, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf7, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc7, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk7, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 8 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x8, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u8, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf8, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc8, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk8, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 9 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x9, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u9, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf9, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc9, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk9, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 10 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x10, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u10, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf10, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc10, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk10, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 11 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x11, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u11, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf11, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc11, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk11, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 12 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x12, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u12, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf12, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc12, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk12, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 13 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x13, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u13, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf13, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc13, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk13, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 14 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x14, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u14, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf14, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc14, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk14, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 15 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x15, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u15, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf15, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc15, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk15, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 16 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x16, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u16, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf16, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc16, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk16, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 17 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x17, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u17, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf17, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc17, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk17, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 18 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x18, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u18, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf18, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc18, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk18, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 19 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x19, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u19, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf19, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc19, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk19, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 20 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x20, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u20, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf20, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc20, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk20, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 21 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x21, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u21, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf21, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc21, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk21, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 22 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x22, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u22, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf22, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc22, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk22, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 23 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x23, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u23, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf23, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc23, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk23, linflp_k24_norm_r, linflp_k24_norm_r);
/* Zeitschritt 24 */
/* Aus Gütefunktion */
linflp_k24_norm_inf_3_1(linflp_k24_rf0x24, linflp_k24_norm_r, linflp_k24_norm_r);
linflp_k24_norm_inf_2_1(linflp_k24_rf0u24, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k24_norm_inf_3_1(linflp_k24_rf24, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rc24, linflp_k24_norm_r, linflp_k24_norm_r);
/* Aus Komplementaritätsbedingung */
linflp_k24_norm_inf_10_1(linflp_k24_rk24, linflp_k24_norm_r, linflp_k24_norm_r);
/* norm_r0 bestimmen */
if(linflp_k24_iter == 0){
linflp_k24_v_copy_1(linflp_k24_norm_r, linflp_k24_norm_r0);
}
}


/* ###################################### */
/* Diese Funktion führt einen Schritt aus */
/* ###################################### */
static void linflp_k24_glqdocpip_step()
{
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx0, linflp_k24_x0);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du0, linflp_k24_u0);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp0, linflp_k24_p0);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy0, linflp_k24_y0);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu0, linflp_k24_nu0);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx1, linflp_k24_x1);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du1, linflp_k24_u1);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp1, linflp_k24_p1);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy1, linflp_k24_y1);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu1, linflp_k24_nu1);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx2, linflp_k24_x2);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du2, linflp_k24_u2);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp2, linflp_k24_p2);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy2, linflp_k24_y2);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu2, linflp_k24_nu2);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx3, linflp_k24_x3);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du3, linflp_k24_u3);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp3, linflp_k24_p3);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy3, linflp_k24_y3);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu3, linflp_k24_nu3);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx4, linflp_k24_x4);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du4, linflp_k24_u4);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp4, linflp_k24_p4);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy4, linflp_k24_y4);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu4, linflp_k24_nu4);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx5, linflp_k24_x5);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du5, linflp_k24_u5);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp5, linflp_k24_p5);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy5, linflp_k24_y5);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu5, linflp_k24_nu5);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx6, linflp_k24_x6);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du6, linflp_k24_u6);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp6, linflp_k24_p6);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy6, linflp_k24_y6);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu6, linflp_k24_nu6);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx7, linflp_k24_x7);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du7, linflp_k24_u7);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp7, linflp_k24_p7);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy7, linflp_k24_y7);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu7, linflp_k24_nu7);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx8, linflp_k24_x8);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du8, linflp_k24_u8);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp8, linflp_k24_p8);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy8, linflp_k24_y8);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu8, linflp_k24_nu8);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx9, linflp_k24_x9);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du9, linflp_k24_u9);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp9, linflp_k24_p9);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy9, linflp_k24_y9);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu9, linflp_k24_nu9);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx10, linflp_k24_x10);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du10, linflp_k24_u10);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp10, linflp_k24_p10);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy10, linflp_k24_y10);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu10, linflp_k24_nu10);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx11, linflp_k24_x11);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du11, linflp_k24_u11);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp11, linflp_k24_p11);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy11, linflp_k24_y11);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu11, linflp_k24_nu11);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx12, linflp_k24_x12);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du12, linflp_k24_u12);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp12, linflp_k24_p12);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy12, linflp_k24_y12);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu12, linflp_k24_nu12);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx13, linflp_k24_x13);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du13, linflp_k24_u13);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp13, linflp_k24_p13);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy13, linflp_k24_y13);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu13, linflp_k24_nu13);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx14, linflp_k24_x14);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du14, linflp_k24_u14);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp14, linflp_k24_p14);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy14, linflp_k24_y14);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu14, linflp_k24_nu14);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx15, linflp_k24_x15);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du15, linflp_k24_u15);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp15, linflp_k24_p15);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy15, linflp_k24_y15);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu15, linflp_k24_nu15);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx16, linflp_k24_x16);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du16, linflp_k24_u16);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp16, linflp_k24_p16);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy16, linflp_k24_y16);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu16, linflp_k24_nu16);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx17, linflp_k24_x17);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du17, linflp_k24_u17);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp17, linflp_k24_p17);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy17, linflp_k24_y17);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu17, linflp_k24_nu17);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx18, linflp_k24_x18);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du18, linflp_k24_u18);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp18, linflp_k24_p18);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy18, linflp_k24_y18);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu18, linflp_k24_nu18);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx19, linflp_k24_x19);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du19, linflp_k24_u19);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp19, linflp_k24_p19);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy19, linflp_k24_y19);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu19, linflp_k24_nu19);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx20, linflp_k24_x20);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du20, linflp_k24_u20);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp20, linflp_k24_p20);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy20, linflp_k24_y20);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu20, linflp_k24_nu20);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx21, linflp_k24_x21);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du21, linflp_k24_u21);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp21, linflp_k24_p21);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy21, linflp_k24_y21);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu21, linflp_k24_nu21);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx22, linflp_k24_x22);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du22, linflp_k24_u22);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp22, linflp_k24_p22);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy22, linflp_k24_y22);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu22, linflp_k24_nu22);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx23, linflp_k24_x23);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du23, linflp_k24_u23);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp23, linflp_k24_p23);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy23, linflp_k24_y23);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu23, linflp_k24_nu23);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dx24, linflp_k24_x24);
linflp_k24_sv_2(linflp_k24_mehrotra_alpha, linflp_k24_du24, linflp_k24_u24);
linflp_k24_sv_3(linflp_k24_mehrotra_alpha, linflp_k24_dp24, linflp_k24_p24);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dy24, linflp_k24_y24);
linflp_k24_sv_10(linflp_k24_mehrotra_alpha, linflp_k24_dnu24, linflp_k24_nu24);
}


/* ######################################################### */
/* Diese Funktion führt Konvergenz- und Divergenztests durch */
/* ######################################################### */
static void linflp_k24_glqdocpip_check_condiv()
{
/* Termcode 0 - Success */
if(linflp_k24_mu[0] <= linflp_k24_tol[0]){
linflp_k24_vv_elemult_1(linflp_k24_tol, linflp_k24_norm_d, linflp_k24_tmp1_1);
  if(linflp_k24_norm_r[0] <= linflp_k24_tmp1_1[0]){
  linflp_k24_termcode = 0;
  return;
  }
}

/* Termcode 1 - infeasible */
if(linflp_k24_phi[0] > linflp_k24_tol[0]){
linflp_k24_vv_elemult_1(linflp_k24_tc1_factor, linflp_k24_minphi, linflp_k24_tmp1_1);
  if(linflp_k24_phi[0] >= linflp_k24_tmp1_1[0]){
  linflp_k24_termcode = 1;
  return;
  }
}

/* Termcode 2 - slow convergence */
linflp_k24_vv_elemult_1(linflp_k24_tol, linflp_k24_norm_d, linflp_k24_tmp1_1);
if(linflp_k24_norm_r[0] > linflp_k24_tmp1_1[0]){
linflp_k24_vv_elediv_1(linflp_k24_norm_r, linflp_k24_mu, linflp_k24_tmp1_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vv_elediv_1(linflp_k24_norm_r0, linflp_k24_mu0, linflp_k24_tmp2_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vv_elemult_1(linflp_k24_tc2_factor, linflp_k24_tmp2_1, linflp_k24_tmp2_1);
  if(linflp_k24_tmp1_1[0] >= linflp_k24_tmp2_1[0]){
  linflp_k24_termcode = 2;
  return;
  }
}

/* Termcode 7 - calculation time limit exceeded */
if(linflp_k24_iter > 0){
  if(linflp_k24_glqdocpip_timer_get()*(double)linflp_k24_iter/ (double) (linflp_k24_iter + 1) > linflp_k24_time_max){
    linflp_k24_termcode = 7;
    return;
  }
}

/* iterative refinement */
/* ### FLAGS ### */
/* # keep_iterative_refinements_on = 0 */
/* # iterative_refinements_require_norm_r_is_not_too_small = 0 */
/* ############# */
linflp_k24_iter_ref = 0;
if(linflp_k24_iter > 0){
linflp_k24_tmp1_1[0] = 100;
linflp_k24_vv_elemult_1(linflp_k24_tmp1_1, linflp_k24_tol, linflp_k24_tmp2_1);
linflp_k24_vv_elemult_1(linflp_k24_norm_d, linflp_k24_tmp2_1, linflp_k24_tmp2_1);
if(linflp_k24_norm_r_prev[0] > linflp_k24_tmp2_1[0]){
linflp_k24_tmp1_1[0] = 1.001;
linflp_k24_vv_elemult_1(linflp_k24_tmp1_1, linflp_k24_norm_r_prev, linflp_k24_tmp2_1);
if(linflp_k24_norm_r[0] > linflp_k24_tmp2_1[0]){
linflp_k24_iter_ref = 1;
}
}
}

}


/* ################################################ */
/* Diese Funktion speichert Daten für die Statistik */
/* ################################################ */
static void linflp_k24_glqdocpip_stat()
{
/* Zeit */
linflp_k24_stat_time[linflp_k24_iter] = linflp_k24_glqdocpip_timer_get();
}


static void linflp_k24_glqdocpip_factor()
{
linflp_k24_error_source = 1;
linflp_k24_stat_num_factor++;
/* Factor: Rückwärtsiteration */
/* Zeitschritt 24 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx24, linflp_k24_Gxx24);
linflp_k24_m_copy_3_2(linflp_k24_Hxu24, linflp_k24_Gxu24);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid53_sid17_10_3(linflp_k24_gx24, linflp_k24_yny24, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid14_sid53_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx24, linflp_k24_Gxx24);
linflp_k24_mm_sid14_sid56_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu24, linflp_k24_Gxu24);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu24, linflp_k24_Guu24);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid56_sid17_10_2(linflp_k24_gu24, linflp_k24_yny24, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu24, linflp_k24_Guu24);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu24, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu24, linflp_k24_L24);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L24, linflp_k24_tmp1_2_3, linflp_k24_Rux24);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx24);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu24, linflp_k24_Rux24, linflp_k24_Vxx24);
linflp_k24_msub_3_3(linflp_k24_Gxx24, linflp_k24_Vxx24, linflp_k24_Vxx24);
/* Zeitschritt 23 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx23, linflp_k24_Gxx23);
linflp_k24_m_copy_3_2(linflp_k24_Hxu23, linflp_k24_Gxu23);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx23, linflp_k24_Vxx24, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx23, linflp_k24_Gxx23);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu23, linflp_k24_Gxu23);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx23, linflp_k24_yny23, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx23, linflp_k24_Gxx23);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu23, linflp_k24_Gxu23);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu23, linflp_k24_Guu23);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu23, linflp_k24_Vxx24, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu23, linflp_k24_Guu23);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu23, linflp_k24_yny23, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu23, linflp_k24_Guu23);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu23, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu23, linflp_k24_L23);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L23, linflp_k24_tmp1_2_3, linflp_k24_Rux23);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx23);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu23, linflp_k24_Rux23, linflp_k24_Vxx23);
linflp_k24_msub_3_3(linflp_k24_Gxx23, linflp_k24_Vxx23, linflp_k24_Vxx23);
/* Zeitschritt 22 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx22, linflp_k24_Gxx22);
linflp_k24_m_copy_3_2(linflp_k24_Hxu22, linflp_k24_Gxu22);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx22, linflp_k24_Vxx23, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx22, linflp_k24_Gxx22);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu22, linflp_k24_Gxu22);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx22, linflp_k24_yny22, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx22, linflp_k24_Gxx22);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu22, linflp_k24_Gxu22);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu22, linflp_k24_Guu22);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu22, linflp_k24_Vxx23, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu22, linflp_k24_Guu22);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu22, linflp_k24_yny22, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu22, linflp_k24_Guu22);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu22, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu22, linflp_k24_L22);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L22, linflp_k24_tmp1_2_3, linflp_k24_Rux22);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx22);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu22, linflp_k24_Rux22, linflp_k24_Vxx22);
linflp_k24_msub_3_3(linflp_k24_Gxx22, linflp_k24_Vxx22, linflp_k24_Vxx22);
/* Zeitschritt 21 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx21, linflp_k24_Gxx21);
linflp_k24_m_copy_3_2(linflp_k24_Hxu21, linflp_k24_Gxu21);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx21, linflp_k24_Vxx22, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx21, linflp_k24_Gxx21);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu21, linflp_k24_Gxu21);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx21, linflp_k24_yny21, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx21, linflp_k24_Gxx21);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu21, linflp_k24_Gxu21);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu21, linflp_k24_Guu21);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu21, linflp_k24_Vxx22, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu21, linflp_k24_Guu21);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu21, linflp_k24_yny21, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu21, linflp_k24_Guu21);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu21, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu21, linflp_k24_L21);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L21, linflp_k24_tmp1_2_3, linflp_k24_Rux21);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx21);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu21, linflp_k24_Rux21, linflp_k24_Vxx21);
linflp_k24_msub_3_3(linflp_k24_Gxx21, linflp_k24_Vxx21, linflp_k24_Vxx21);
/* Zeitschritt 20 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx20, linflp_k24_Gxx20);
linflp_k24_m_copy_3_2(linflp_k24_Hxu20, linflp_k24_Gxu20);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx20, linflp_k24_Vxx21, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx20, linflp_k24_Gxx20);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu20, linflp_k24_Gxu20);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx20, linflp_k24_yny20, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx20, linflp_k24_Gxx20);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu20, linflp_k24_Gxu20);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu20, linflp_k24_Guu20);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu20, linflp_k24_Vxx21, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu20, linflp_k24_Guu20);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu20, linflp_k24_yny20, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu20, linflp_k24_Guu20);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu20, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu20, linflp_k24_L20);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L20, linflp_k24_tmp1_2_3, linflp_k24_Rux20);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx20);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu20, linflp_k24_Rux20, linflp_k24_Vxx20);
linflp_k24_msub_3_3(linflp_k24_Gxx20, linflp_k24_Vxx20, linflp_k24_Vxx20);
/* Zeitschritt 19 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx19, linflp_k24_Gxx19);
linflp_k24_m_copy_3_2(linflp_k24_Hxu19, linflp_k24_Gxu19);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx19, linflp_k24_Vxx20, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx19, linflp_k24_Gxx19);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu19, linflp_k24_Gxu19);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx19, linflp_k24_yny19, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx19, linflp_k24_Gxx19);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu19, linflp_k24_Gxu19);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu19, linflp_k24_Guu19);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu19, linflp_k24_Vxx20, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu19, linflp_k24_Guu19);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu19, linflp_k24_yny19, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu19, linflp_k24_Guu19);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu19, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu19, linflp_k24_L19);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L19, linflp_k24_tmp1_2_3, linflp_k24_Rux19);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx19);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu19, linflp_k24_Rux19, linflp_k24_Vxx19);
linflp_k24_msub_3_3(linflp_k24_Gxx19, linflp_k24_Vxx19, linflp_k24_Vxx19);
/* Zeitschritt 18 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx18, linflp_k24_Gxx18);
linflp_k24_m_copy_3_2(linflp_k24_Hxu18, linflp_k24_Gxu18);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx18, linflp_k24_Vxx19, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx18, linflp_k24_Gxx18);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu18, linflp_k24_Gxu18);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx18, linflp_k24_yny18, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx18, linflp_k24_Gxx18);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu18, linflp_k24_Gxu18);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu18, linflp_k24_Guu18);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu18, linflp_k24_Vxx19, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu18, linflp_k24_Guu18);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu18, linflp_k24_yny18, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu18, linflp_k24_Guu18);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu18, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu18, linflp_k24_L18);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L18, linflp_k24_tmp1_2_3, linflp_k24_Rux18);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx18);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu18, linflp_k24_Rux18, linflp_k24_Vxx18);
linflp_k24_msub_3_3(linflp_k24_Gxx18, linflp_k24_Vxx18, linflp_k24_Vxx18);
/* Zeitschritt 17 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx17, linflp_k24_Gxx17);
linflp_k24_m_copy_3_2(linflp_k24_Hxu17, linflp_k24_Gxu17);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx17, linflp_k24_Vxx18, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx17, linflp_k24_Gxx17);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu17, linflp_k24_Gxu17);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx17, linflp_k24_yny17, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx17, linflp_k24_Gxx17);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu17, linflp_k24_Gxu17);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu17, linflp_k24_Guu17);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu17, linflp_k24_Vxx18, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu17, linflp_k24_Guu17);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu17, linflp_k24_yny17, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu17, linflp_k24_Guu17);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu17, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu17, linflp_k24_L17);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L17, linflp_k24_tmp1_2_3, linflp_k24_Rux17);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx17);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu17, linflp_k24_Rux17, linflp_k24_Vxx17);
linflp_k24_msub_3_3(linflp_k24_Gxx17, linflp_k24_Vxx17, linflp_k24_Vxx17);
/* Zeitschritt 16 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx16, linflp_k24_Gxx16);
linflp_k24_m_copy_3_2(linflp_k24_Hxu16, linflp_k24_Gxu16);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx16, linflp_k24_Vxx17, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx16, linflp_k24_Gxx16);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu16, linflp_k24_Gxu16);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx16, linflp_k24_yny16, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx16, linflp_k24_Gxx16);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu16, linflp_k24_Gxu16);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu16, linflp_k24_Guu16);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu16, linflp_k24_Vxx17, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu16, linflp_k24_Guu16);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu16, linflp_k24_yny16, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu16, linflp_k24_Guu16);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu16, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu16, linflp_k24_L16);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L16, linflp_k24_tmp1_2_3, linflp_k24_Rux16);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx16);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu16, linflp_k24_Rux16, linflp_k24_Vxx16);
linflp_k24_msub_3_3(linflp_k24_Gxx16, linflp_k24_Vxx16, linflp_k24_Vxx16);
/* Zeitschritt 15 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx15, linflp_k24_Gxx15);
linflp_k24_m_copy_3_2(linflp_k24_Hxu15, linflp_k24_Gxu15);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx15, linflp_k24_Vxx16, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx15, linflp_k24_Gxx15);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu15, linflp_k24_Gxu15);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx15, linflp_k24_yny15, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx15, linflp_k24_Gxx15);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu15, linflp_k24_Gxu15);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu15, linflp_k24_Guu15);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu15, linflp_k24_Vxx16, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu15, linflp_k24_Guu15);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu15, linflp_k24_yny15, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu15, linflp_k24_Guu15);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu15, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu15, linflp_k24_L15);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L15, linflp_k24_tmp1_2_3, linflp_k24_Rux15);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx15);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu15, linflp_k24_Rux15, linflp_k24_Vxx15);
linflp_k24_msub_3_3(linflp_k24_Gxx15, linflp_k24_Vxx15, linflp_k24_Vxx15);
/* Zeitschritt 14 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx14, linflp_k24_Gxx14);
linflp_k24_m_copy_3_2(linflp_k24_Hxu14, linflp_k24_Gxu14);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx14, linflp_k24_Vxx15, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx14, linflp_k24_Gxx14);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu14, linflp_k24_Gxu14);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx14, linflp_k24_yny14, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx14, linflp_k24_Gxx14);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu14, linflp_k24_Gxu14);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu14, linflp_k24_Guu14);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu14, linflp_k24_Vxx15, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu14, linflp_k24_Guu14);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu14, linflp_k24_yny14, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu14, linflp_k24_Guu14);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu14, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu14, linflp_k24_L14);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L14, linflp_k24_tmp1_2_3, linflp_k24_Rux14);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx14);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu14, linflp_k24_Rux14, linflp_k24_Vxx14);
linflp_k24_msub_3_3(linflp_k24_Gxx14, linflp_k24_Vxx14, linflp_k24_Vxx14);
/* Zeitschritt 13 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx13, linflp_k24_Gxx13);
linflp_k24_m_copy_3_2(linflp_k24_Hxu13, linflp_k24_Gxu13);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx13, linflp_k24_Vxx14, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx13, linflp_k24_Gxx13);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu13, linflp_k24_Gxu13);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx13, linflp_k24_yny13, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx13, linflp_k24_Gxx13);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu13, linflp_k24_Gxu13);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu13, linflp_k24_Guu13);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu13, linflp_k24_Vxx14, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu13, linflp_k24_Guu13);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu13, linflp_k24_yny13, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu13, linflp_k24_Guu13);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu13, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu13, linflp_k24_L13);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L13, linflp_k24_tmp1_2_3, linflp_k24_Rux13);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx13);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu13, linflp_k24_Rux13, linflp_k24_Vxx13);
linflp_k24_msub_3_3(linflp_k24_Gxx13, linflp_k24_Vxx13, linflp_k24_Vxx13);
/* Zeitschritt 12 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx12, linflp_k24_Gxx12);
linflp_k24_m_copy_3_2(linflp_k24_Hxu12, linflp_k24_Gxu12);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx12, linflp_k24_Vxx13, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx12, linflp_k24_Gxx12);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu12, linflp_k24_Gxu12);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx12, linflp_k24_yny12, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx12, linflp_k24_Gxx12);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu12, linflp_k24_Gxu12);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu12, linflp_k24_Guu12);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu12, linflp_k24_Vxx13, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu12, linflp_k24_Guu12);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu12, linflp_k24_yny12, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu12, linflp_k24_Guu12);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu12, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu12, linflp_k24_L12);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L12, linflp_k24_tmp1_2_3, linflp_k24_Rux12);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx12);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu12, linflp_k24_Rux12, linflp_k24_Vxx12);
linflp_k24_msub_3_3(linflp_k24_Gxx12, linflp_k24_Vxx12, linflp_k24_Vxx12);
/* Zeitschritt 11 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx11, linflp_k24_Gxx11);
linflp_k24_m_copy_3_2(linflp_k24_Hxu11, linflp_k24_Gxu11);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx11, linflp_k24_Vxx12, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx11, linflp_k24_Gxx11);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu11, linflp_k24_Gxu11);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx11, linflp_k24_yny11, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx11, linflp_k24_Gxx11);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu11, linflp_k24_Gxu11);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu11, linflp_k24_Guu11);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu11, linflp_k24_Vxx12, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu11, linflp_k24_Guu11);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu11, linflp_k24_yny11, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu11, linflp_k24_Guu11);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu11, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu11, linflp_k24_L11);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L11, linflp_k24_tmp1_2_3, linflp_k24_Rux11);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx11);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu11, linflp_k24_Rux11, linflp_k24_Vxx11);
linflp_k24_msub_3_3(linflp_k24_Gxx11, linflp_k24_Vxx11, linflp_k24_Vxx11);
/* Zeitschritt 10 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx10, linflp_k24_Gxx10);
linflp_k24_m_copy_3_2(linflp_k24_Hxu10, linflp_k24_Gxu10);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx10, linflp_k24_Vxx11, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx10, linflp_k24_Gxx10);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu10, linflp_k24_Gxu10);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx10, linflp_k24_yny10, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx10, linflp_k24_Gxx10);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu10, linflp_k24_Gxu10);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu10, linflp_k24_Guu10);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu10, linflp_k24_Vxx11, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu10, linflp_k24_Guu10);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu10, linflp_k24_yny10, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu10, linflp_k24_Guu10);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu10, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu10, linflp_k24_L10);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L10, linflp_k24_tmp1_2_3, linflp_k24_Rux10);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx10);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu10, linflp_k24_Rux10, linflp_k24_Vxx10);
linflp_k24_msub_3_3(linflp_k24_Gxx10, linflp_k24_Vxx10, linflp_k24_Vxx10);
/* Zeitschritt 9 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx9, linflp_k24_Gxx9);
linflp_k24_m_copy_3_2(linflp_k24_Hxu9, linflp_k24_Gxu9);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx9, linflp_k24_Vxx10, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx9, linflp_k24_Gxx9);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu9, linflp_k24_Gxu9);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx9, linflp_k24_yny9, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx9, linflp_k24_Gxx9);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu9, linflp_k24_Gxu9);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu9, linflp_k24_Guu9);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu9, linflp_k24_Vxx10, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu9, linflp_k24_Guu9);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu9, linflp_k24_yny9, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu9, linflp_k24_Guu9);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu9, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu9, linflp_k24_L9);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L9, linflp_k24_tmp1_2_3, linflp_k24_Rux9);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx9);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu9, linflp_k24_Rux9, linflp_k24_Vxx9);
linflp_k24_msub_3_3(linflp_k24_Gxx9, linflp_k24_Vxx9, linflp_k24_Vxx9);
/* Zeitschritt 8 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx8, linflp_k24_Gxx8);
linflp_k24_m_copy_3_2(linflp_k24_Hxu8, linflp_k24_Gxu8);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx8, linflp_k24_Vxx9, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx8, linflp_k24_Gxx8);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu8, linflp_k24_Gxu8);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx8, linflp_k24_yny8, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx8, linflp_k24_Gxx8);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu8, linflp_k24_Gxu8);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu8, linflp_k24_Guu8);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu8, linflp_k24_Vxx9, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu8, linflp_k24_Guu8);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu8, linflp_k24_yny8, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu8, linflp_k24_Guu8);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu8, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu8, linflp_k24_L8);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L8, linflp_k24_tmp1_2_3, linflp_k24_Rux8);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx8);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu8, linflp_k24_Rux8, linflp_k24_Vxx8);
linflp_k24_msub_3_3(linflp_k24_Gxx8, linflp_k24_Vxx8, linflp_k24_Vxx8);
/* Zeitschritt 7 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx7, linflp_k24_Gxx7);
linflp_k24_m_copy_3_2(linflp_k24_Hxu7, linflp_k24_Gxu7);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx7, linflp_k24_Vxx8, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx7, linflp_k24_Gxx7);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu7, linflp_k24_Gxu7);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx7, linflp_k24_yny7, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx7, linflp_k24_Gxx7);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu7, linflp_k24_Gxu7);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu7, linflp_k24_Guu7);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu7, linflp_k24_Vxx8, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu7, linflp_k24_Guu7);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu7, linflp_k24_yny7, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu7, linflp_k24_Guu7);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu7, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu7, linflp_k24_L7);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L7, linflp_k24_tmp1_2_3, linflp_k24_Rux7);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx7);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu7, linflp_k24_Rux7, linflp_k24_Vxx7);
linflp_k24_msub_3_3(linflp_k24_Gxx7, linflp_k24_Vxx7, linflp_k24_Vxx7);
/* Zeitschritt 6 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx6, linflp_k24_Gxx6);
linflp_k24_m_copy_3_2(linflp_k24_Hxu6, linflp_k24_Gxu6);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx6, linflp_k24_Vxx7, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx6, linflp_k24_Gxx6);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu6, linflp_k24_Gxu6);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx6, linflp_k24_yny6, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx6, linflp_k24_Gxx6);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu6, linflp_k24_Gxu6);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu6, linflp_k24_Guu6);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu6, linflp_k24_Vxx7, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu6, linflp_k24_Guu6);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu6, linflp_k24_yny6, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu6, linflp_k24_Guu6);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu6, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu6, linflp_k24_L6);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L6, linflp_k24_tmp1_2_3, linflp_k24_Rux6);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx6);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu6, linflp_k24_Rux6, linflp_k24_Vxx6);
linflp_k24_msub_3_3(linflp_k24_Gxx6, linflp_k24_Vxx6, linflp_k24_Vxx6);
/* Zeitschritt 5 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx5, linflp_k24_Gxx5);
linflp_k24_m_copy_3_2(linflp_k24_Hxu5, linflp_k24_Gxu5);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx5, linflp_k24_Vxx6, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx5, linflp_k24_Gxx5);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu5, linflp_k24_Gxu5);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx5, linflp_k24_yny5, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx5, linflp_k24_Gxx5);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu5, linflp_k24_Gxu5);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu5, linflp_k24_Guu5);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu5, linflp_k24_Vxx6, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu5, linflp_k24_Guu5);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu5, linflp_k24_yny5, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu5, linflp_k24_Guu5);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu5, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu5, linflp_k24_L5);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L5, linflp_k24_tmp1_2_3, linflp_k24_Rux5);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx5);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu5, linflp_k24_Rux5, linflp_k24_Vxx5);
linflp_k24_msub_3_3(linflp_k24_Gxx5, linflp_k24_Vxx5, linflp_k24_Vxx5);
/* Zeitschritt 4 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx4, linflp_k24_Gxx4);
linflp_k24_m_copy_3_2(linflp_k24_Hxu4, linflp_k24_Gxu4);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx4, linflp_k24_Vxx5, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx4, linflp_k24_Gxx4);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu4, linflp_k24_Gxu4);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx4, linflp_k24_yny4, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx4, linflp_k24_Gxx4);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu4, linflp_k24_Gxu4);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu4, linflp_k24_Guu4);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu4, linflp_k24_Vxx5, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu4, linflp_k24_Guu4);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu4, linflp_k24_yny4, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu4, linflp_k24_Guu4);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu4, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu4, linflp_k24_L4);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L4, linflp_k24_tmp1_2_3, linflp_k24_Rux4);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx4);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu4, linflp_k24_Rux4, linflp_k24_Vxx4);
linflp_k24_msub_3_3(linflp_k24_Gxx4, linflp_k24_Vxx4, linflp_k24_Vxx4);
/* Zeitschritt 3 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx3, linflp_k24_Gxx3);
linflp_k24_m_copy_3_2(linflp_k24_Hxu3, linflp_k24_Gxu3);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx3, linflp_k24_Vxx4, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx3, linflp_k24_Gxx3);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu3, linflp_k24_Gxu3);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx3, linflp_k24_yny3, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx3, linflp_k24_Gxx3);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu3, linflp_k24_Gxu3);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu3, linflp_k24_Guu3);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu3, linflp_k24_Vxx4, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu3, linflp_k24_Guu3);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu3, linflp_k24_yny3, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu3, linflp_k24_Guu3);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu3, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu3, linflp_k24_L3);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L3, linflp_k24_tmp1_2_3, linflp_k24_Rux3);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx3);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu3, linflp_k24_Rux3, linflp_k24_Vxx3);
linflp_k24_msub_3_3(linflp_k24_Gxx3, linflp_k24_Vxx3, linflp_k24_Vxx3);
/* Zeitschritt 2 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx2, linflp_k24_Gxx2);
linflp_k24_m_copy_3_2(linflp_k24_Hxu2, linflp_k24_Gxu2);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx2, linflp_k24_Vxx3, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx2, linflp_k24_Gxx2);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu2, linflp_k24_Gxu2);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx2, linflp_k24_yny2, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx2, linflp_k24_Gxx2);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu2, linflp_k24_Gxu2);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu2, linflp_k24_Guu2);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu2, linflp_k24_Vxx3, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu2, linflp_k24_Guu2);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu2, linflp_k24_yny2, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu2, linflp_k24_Guu2);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu2, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu2, linflp_k24_L2);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L2, linflp_k24_tmp1_2_3, linflp_k24_Rux2);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx2);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu2, linflp_k24_Rux2, linflp_k24_Vxx2);
linflp_k24_msub_3_3(linflp_k24_Gxx2, linflp_k24_Vxx2, linflp_k24_Vxx2);
/* Zeitschritt 1 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx1, linflp_k24_Gxx1);
linflp_k24_m_copy_3_2(linflp_k24_Hxu1, linflp_k24_Gxu1);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid43_sid1_3_3_3(linflp_k24_fx1, linflp_k24_Vxx2, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid43_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx1, linflp_k24_Gxx1);
linflp_k24_mm_sid1_sid46_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu1, linflp_k24_Gxu1);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid52_sid16_10_3(linflp_k24_gx1, linflp_k24_yny1, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid13_sid52_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx1, linflp_k24_Gxx1);
linflp_k24_mm_sid13_sid55_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu1, linflp_k24_Gxu1);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu1, linflp_k24_Guu1);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid46_sid1_3_2_3(linflp_k24_fu1, linflp_k24_Vxx2, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid46_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu1, linflp_k24_Guu1);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid55_sid16_10_2(linflp_k24_gu1, linflp_k24_yny1, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu1, linflp_k24_Guu1);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu1, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu1, linflp_k24_L1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L1, linflp_k24_tmp1_2_3, linflp_k24_Rux1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx1);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu1, linflp_k24_Rux1, linflp_k24_Vxx1);
linflp_k24_msub_3_3(linflp_k24_Gxx1, linflp_k24_Vxx1, linflp_k24_Vxx1);
/* Zeitschritt 0 */
/* Gxx und Gxu */
linflp_k24_m_copy_3_3(linflp_k24_Hxx0, linflp_k24_Gxx0);
linflp_k24_m_copy_3_2(linflp_k24_Hxu0, linflp_k24_Gxu0);
linflp_k24_m_init0_3_3(linflp_k24_tmp1_3_3);
linflp_k24_mtm_sid42_sid1_3_3_3(linflp_k24_fx0, linflp_k24_Vxx1, linflp_k24_tmp1_3_3);
linflp_k24_mm_y_sid1_sid42_3_3_3(linflp_k24_tmp1_3_3, linflp_k24_fx0, linflp_k24_Gxx0);
linflp_k24_mm_sid1_sid45_3_3_2(linflp_k24_tmp1_3_3, linflp_k24_fu0, linflp_k24_Gxu0);
linflp_k24_m_init0_3_10(linflp_k24_tmp1_3_10);
linflp_k24_mtd_sid51_sid15_10_3(linflp_k24_gx0, linflp_k24_yny0, linflp_k24_tmp1_3_10);
linflp_k24_mm_y_sid12_sid51_3_10_3(linflp_k24_tmp1_3_10, linflp_k24_gx0, linflp_k24_Gxx0);
linflp_k24_mm_sid12_sid54_3_10_2(linflp_k24_tmp1_3_10, linflp_k24_gu0, linflp_k24_Gxu0);
/* Guu */
linflp_k24_m_copy_2_2(linflp_k24_Huu0, linflp_k24_Guu0);
linflp_k24_m_init0_2_3(linflp_k24_tmp1_2_3);
linflp_k24_mtm_sid45_sid1_3_2_3(linflp_k24_fu0, linflp_k24_Vxx1, linflp_k24_tmp1_2_3);
linflp_k24_mm_sid8_sid45_2_3_2(linflp_k24_tmp1_2_3, linflp_k24_fu0, linflp_k24_Guu0);
linflp_k24_m_init0_2_10(linflp_k24_tmp1_2_10);
linflp_k24_mtd_sid54_sid15_10_2(linflp_k24_gu0, linflp_k24_yny0, linflp_k24_tmp1_2_10);
linflp_k24_mm_2_10_2(linflp_k24_tmp1_2_10, linflp_k24_gu0, linflp_k24_Guu0);
/* Rux */
linflp_k24_mtr_3_2(linflp_k24_Gxu0, linflp_k24_tmp1_2_3);
linflp_k24_chol_factor_2(linflp_k24_Guu0, linflp_k24_L0);
if(linflp_k24_termcode > -1){return;}
linflp_k24_chol_solve_2_3(linflp_k24_L0, linflp_k24_tmp1_2_3, linflp_k24_Rux0);
if(linflp_k24_termcode > -1){return;}
linflp_k24_m_init0_3_3(linflp_k24_Vxx0);
linflp_k24_mm_y_3_2_3(linflp_k24_Gxu0, linflp_k24_Rux0, linflp_k24_Vxx0);
linflp_k24_msub_3_3(linflp_k24_Gxx0, linflp_k24_Vxx0, linflp_k24_Vxx0);
linflp_k24_error_source = 0;

}


static void linflp_k24_glqdocpip_solve()
{
linflp_k24_error_source = 2;
linflp_k24_stat_num_solve++;
/* Solve: Rückwärtsiteration */
/* Zeitschritt 24 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x24, linflp_k24_Gx24);
linflp_k24_v_copy_2(linflp_k24_rrf0u24, linflp_k24_Gu24);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L24, linflp_k24_Gu24, linflp_k24_Ru24);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu24, linflp_k24_Ru24, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx24, linflp_k24_tmp1_3, linflp_k24_Vx24);
/* Zeitschritt 23 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x23, linflp_k24_Gx23);
linflp_k24_v_copy_2(linflp_k24_rrf0u23, linflp_k24_Gu23);
linflp_k24_v_copy_3(linflp_k24_Vx24, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx24, linflp_k24_rf24, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx23, linflp_k24_tmp1_3, linflp_k24_Gx23);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu23, linflp_k24_tmp1_3, linflp_k24_Gu23);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L23, linflp_k24_Gu23, linflp_k24_Ru23);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu23, linflp_k24_Ru23, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx23, linflp_k24_tmp1_3, linflp_k24_Vx23);
/* Zeitschritt 22 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x22, linflp_k24_Gx22);
linflp_k24_v_copy_2(linflp_k24_rrf0u22, linflp_k24_Gu22);
linflp_k24_v_copy_3(linflp_k24_Vx23, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx23, linflp_k24_rf23, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_tmp1_3, linflp_k24_Gx22);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu22, linflp_k24_tmp1_3, linflp_k24_Gu22);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L22, linflp_k24_Gu22, linflp_k24_Ru22);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu22, linflp_k24_Ru22, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx22, linflp_k24_tmp1_3, linflp_k24_Vx22);
/* Zeitschritt 21 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x21, linflp_k24_Gx21);
linflp_k24_v_copy_2(linflp_k24_rrf0u21, linflp_k24_Gu21);
linflp_k24_v_copy_3(linflp_k24_Vx22, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx22, linflp_k24_rf22, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_tmp1_3, linflp_k24_Gx21);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu21, linflp_k24_tmp1_3, linflp_k24_Gu21);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L21, linflp_k24_Gu21, linflp_k24_Ru21);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu21, linflp_k24_Ru21, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx21, linflp_k24_tmp1_3, linflp_k24_Vx21);
/* Zeitschritt 20 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x20, linflp_k24_Gx20);
linflp_k24_v_copy_2(linflp_k24_rrf0u20, linflp_k24_Gu20);
linflp_k24_v_copy_3(linflp_k24_Vx21, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx21, linflp_k24_rf21, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_tmp1_3, linflp_k24_Gx20);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu20, linflp_k24_tmp1_3, linflp_k24_Gu20);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L20, linflp_k24_Gu20, linflp_k24_Ru20);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu20, linflp_k24_Ru20, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx20, linflp_k24_tmp1_3, linflp_k24_Vx20);
/* Zeitschritt 19 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x19, linflp_k24_Gx19);
linflp_k24_v_copy_2(linflp_k24_rrf0u19, linflp_k24_Gu19);
linflp_k24_v_copy_3(linflp_k24_Vx20, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx20, linflp_k24_rf20, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_tmp1_3, linflp_k24_Gx19);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu19, linflp_k24_tmp1_3, linflp_k24_Gu19);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L19, linflp_k24_Gu19, linflp_k24_Ru19);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu19, linflp_k24_Ru19, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx19, linflp_k24_tmp1_3, linflp_k24_Vx19);
/* Zeitschritt 18 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x18, linflp_k24_Gx18);
linflp_k24_v_copy_2(linflp_k24_rrf0u18, linflp_k24_Gu18);
linflp_k24_v_copy_3(linflp_k24_Vx19, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx19, linflp_k24_rf19, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_tmp1_3, linflp_k24_Gx18);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu18, linflp_k24_tmp1_3, linflp_k24_Gu18);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L18, linflp_k24_Gu18, linflp_k24_Ru18);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu18, linflp_k24_Ru18, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx18, linflp_k24_tmp1_3, linflp_k24_Vx18);
/* Zeitschritt 17 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x17, linflp_k24_Gx17);
linflp_k24_v_copy_2(linflp_k24_rrf0u17, linflp_k24_Gu17);
linflp_k24_v_copy_3(linflp_k24_Vx18, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx18, linflp_k24_rf18, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_tmp1_3, linflp_k24_Gx17);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu17, linflp_k24_tmp1_3, linflp_k24_Gu17);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L17, linflp_k24_Gu17, linflp_k24_Ru17);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu17, linflp_k24_Ru17, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx17, linflp_k24_tmp1_3, linflp_k24_Vx17);
/* Zeitschritt 16 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x16, linflp_k24_Gx16);
linflp_k24_v_copy_2(linflp_k24_rrf0u16, linflp_k24_Gu16);
linflp_k24_v_copy_3(linflp_k24_Vx17, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx17, linflp_k24_rf17, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_tmp1_3, linflp_k24_Gx16);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu16, linflp_k24_tmp1_3, linflp_k24_Gu16);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L16, linflp_k24_Gu16, linflp_k24_Ru16);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu16, linflp_k24_Ru16, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx16, linflp_k24_tmp1_3, linflp_k24_Vx16);
/* Zeitschritt 15 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x15, linflp_k24_Gx15);
linflp_k24_v_copy_2(linflp_k24_rrf0u15, linflp_k24_Gu15);
linflp_k24_v_copy_3(linflp_k24_Vx16, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx16, linflp_k24_rf16, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_tmp1_3, linflp_k24_Gx15);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu15, linflp_k24_tmp1_3, linflp_k24_Gu15);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L15, linflp_k24_Gu15, linflp_k24_Ru15);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu15, linflp_k24_Ru15, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx15, linflp_k24_tmp1_3, linflp_k24_Vx15);
/* Zeitschritt 14 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x14, linflp_k24_Gx14);
linflp_k24_v_copy_2(linflp_k24_rrf0u14, linflp_k24_Gu14);
linflp_k24_v_copy_3(linflp_k24_Vx15, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx15, linflp_k24_rf15, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_tmp1_3, linflp_k24_Gx14);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu14, linflp_k24_tmp1_3, linflp_k24_Gu14);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L14, linflp_k24_Gu14, linflp_k24_Ru14);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu14, linflp_k24_Ru14, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx14, linflp_k24_tmp1_3, linflp_k24_Vx14);
/* Zeitschritt 13 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x13, linflp_k24_Gx13);
linflp_k24_v_copy_2(linflp_k24_rrf0u13, linflp_k24_Gu13);
linflp_k24_v_copy_3(linflp_k24_Vx14, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx14, linflp_k24_rf14, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_tmp1_3, linflp_k24_Gx13);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu13, linflp_k24_tmp1_3, linflp_k24_Gu13);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L13, linflp_k24_Gu13, linflp_k24_Ru13);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu13, linflp_k24_Ru13, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx13, linflp_k24_tmp1_3, linflp_k24_Vx13);
/* Zeitschritt 12 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x12, linflp_k24_Gx12);
linflp_k24_v_copy_2(linflp_k24_rrf0u12, linflp_k24_Gu12);
linflp_k24_v_copy_3(linflp_k24_Vx13, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx13, linflp_k24_rf13, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_tmp1_3, linflp_k24_Gx12);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu12, linflp_k24_tmp1_3, linflp_k24_Gu12);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L12, linflp_k24_Gu12, linflp_k24_Ru12);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu12, linflp_k24_Ru12, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx12, linflp_k24_tmp1_3, linflp_k24_Vx12);
/* Zeitschritt 11 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x11, linflp_k24_Gx11);
linflp_k24_v_copy_2(linflp_k24_rrf0u11, linflp_k24_Gu11);
linflp_k24_v_copy_3(linflp_k24_Vx12, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx12, linflp_k24_rf12, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_tmp1_3, linflp_k24_Gx11);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu11, linflp_k24_tmp1_3, linflp_k24_Gu11);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L11, linflp_k24_Gu11, linflp_k24_Ru11);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu11, linflp_k24_Ru11, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx11, linflp_k24_tmp1_3, linflp_k24_Vx11);
/* Zeitschritt 10 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x10, linflp_k24_Gx10);
linflp_k24_v_copy_2(linflp_k24_rrf0u10, linflp_k24_Gu10);
linflp_k24_v_copy_3(linflp_k24_Vx11, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx11, linflp_k24_rf11, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_tmp1_3, linflp_k24_Gx10);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu10, linflp_k24_tmp1_3, linflp_k24_Gu10);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L10, linflp_k24_Gu10, linflp_k24_Ru10);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu10, linflp_k24_Ru10, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx10, linflp_k24_tmp1_3, linflp_k24_Vx10);
/* Zeitschritt 9 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x9, linflp_k24_Gx9);
linflp_k24_v_copy_2(linflp_k24_rrf0u9, linflp_k24_Gu9);
linflp_k24_v_copy_3(linflp_k24_Vx10, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx10, linflp_k24_rf10, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_tmp1_3, linflp_k24_Gx9);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu9, linflp_k24_tmp1_3, linflp_k24_Gu9);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L9, linflp_k24_Gu9, linflp_k24_Ru9);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu9, linflp_k24_Ru9, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx9, linflp_k24_tmp1_3, linflp_k24_Vx9);
/* Zeitschritt 8 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x8, linflp_k24_Gx8);
linflp_k24_v_copy_2(linflp_k24_rrf0u8, linflp_k24_Gu8);
linflp_k24_v_copy_3(linflp_k24_Vx9, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx9, linflp_k24_rf9, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_tmp1_3, linflp_k24_Gx8);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu8, linflp_k24_tmp1_3, linflp_k24_Gu8);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L8, linflp_k24_Gu8, linflp_k24_Ru8);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu8, linflp_k24_Ru8, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx8, linflp_k24_tmp1_3, linflp_k24_Vx8);
/* Zeitschritt 7 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x7, linflp_k24_Gx7);
linflp_k24_v_copy_2(linflp_k24_rrf0u7, linflp_k24_Gu7);
linflp_k24_v_copy_3(linflp_k24_Vx8, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx8, linflp_k24_rf8, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_tmp1_3, linflp_k24_Gx7);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu7, linflp_k24_tmp1_3, linflp_k24_Gu7);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L7, linflp_k24_Gu7, linflp_k24_Ru7);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu7, linflp_k24_Ru7, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx7, linflp_k24_tmp1_3, linflp_k24_Vx7);
/* Zeitschritt 6 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x6, linflp_k24_Gx6);
linflp_k24_v_copy_2(linflp_k24_rrf0u6, linflp_k24_Gu6);
linflp_k24_v_copy_3(linflp_k24_Vx7, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx7, linflp_k24_rf7, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_tmp1_3, linflp_k24_Gx6);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu6, linflp_k24_tmp1_3, linflp_k24_Gu6);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L6, linflp_k24_Gu6, linflp_k24_Ru6);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu6, linflp_k24_Ru6, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx6, linflp_k24_tmp1_3, linflp_k24_Vx6);
/* Zeitschritt 5 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x5, linflp_k24_Gx5);
linflp_k24_v_copy_2(linflp_k24_rrf0u5, linflp_k24_Gu5);
linflp_k24_v_copy_3(linflp_k24_Vx6, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx6, linflp_k24_rf6, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_tmp1_3, linflp_k24_Gx5);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu5, linflp_k24_tmp1_3, linflp_k24_Gu5);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L5, linflp_k24_Gu5, linflp_k24_Ru5);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu5, linflp_k24_Ru5, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx5, linflp_k24_tmp1_3, linflp_k24_Vx5);
/* Zeitschritt 4 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x4, linflp_k24_Gx4);
linflp_k24_v_copy_2(linflp_k24_rrf0u4, linflp_k24_Gu4);
linflp_k24_v_copy_3(linflp_k24_Vx5, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx5, linflp_k24_rf5, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_tmp1_3, linflp_k24_Gx4);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu4, linflp_k24_tmp1_3, linflp_k24_Gu4);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L4, linflp_k24_Gu4, linflp_k24_Ru4);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu4, linflp_k24_Ru4, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx4, linflp_k24_tmp1_3, linflp_k24_Vx4);
/* Zeitschritt 3 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x3, linflp_k24_Gx3);
linflp_k24_v_copy_2(linflp_k24_rrf0u3, linflp_k24_Gu3);
linflp_k24_v_copy_3(linflp_k24_Vx4, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx4, linflp_k24_rf4, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_tmp1_3, linflp_k24_Gx3);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu3, linflp_k24_tmp1_3, linflp_k24_Gu3);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L3, linflp_k24_Gu3, linflp_k24_Ru3);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu3, linflp_k24_Ru3, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx3, linflp_k24_tmp1_3, linflp_k24_Vx3);
/* Zeitschritt 2 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x2, linflp_k24_Gx2);
linflp_k24_v_copy_2(linflp_k24_rrf0u2, linflp_k24_Gu2);
linflp_k24_v_copy_3(linflp_k24_Vx3, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx3, linflp_k24_rf3, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_tmp1_3, linflp_k24_Gx2);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu2, linflp_k24_tmp1_3, linflp_k24_Gu2);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L2, linflp_k24_Gu2, linflp_k24_Ru2);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu2, linflp_k24_Ru2, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx2, linflp_k24_tmp1_3, linflp_k24_Vx2);
/* Zeitschritt 1 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x1, linflp_k24_Gx1);
linflp_k24_v_copy_2(linflp_k24_rrf0u1, linflp_k24_Gu1);
linflp_k24_v_copy_3(linflp_k24_Vx2, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx2, linflp_k24_rf2, linflp_k24_tmp1_3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_tmp1_3, linflp_k24_Gx1);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu1, linflp_k24_tmp1_3, linflp_k24_Gu1);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L1, linflp_k24_Gu1, linflp_k24_Ru1);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu1, linflp_k24_Ru1, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx1, linflp_k24_tmp1_3, linflp_k24_Vx1);
/* Zeitschritt 0 */
/* Gx und Gu */
linflp_k24_v_copy_3(linflp_k24_rrf0x0, linflp_k24_Gx0);
linflp_k24_v_copy_2(linflp_k24_rrf0u0, linflp_k24_Gu0);
linflp_k24_v_copy_3(linflp_k24_Vx1, linflp_k24_tmp1_3);
linflp_k24_mv_3_3(linflp_k24_Vxx1, linflp_k24_rf1, linflp_k24_tmp1_3);
linflp_k24_mtv_sid42_sid2_3_3(linflp_k24_fx0, linflp_k24_tmp1_3, linflp_k24_Gx0);
linflp_k24_mtv_sid45_sid2_3_2(linflp_k24_fu0, linflp_k24_tmp1_3, linflp_k24_Gu0);
/* Ru */
linflp_k24_chol_solve_2_1(linflp_k24_L0, linflp_k24_Gu0, linflp_k24_Ru0);
if(linflp_k24_termcode > -1){return;}
/* Vx */
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_v_init0_3(linflp_k24_tmp1_3);
linflp_k24_mv_3_2(linflp_k24_Gxu0, linflp_k24_Ru0, linflp_k24_tmp1_3);
linflp_k24_vsub_3(linflp_k24_Gx0, linflp_k24_tmp1_3, linflp_k24_Vx0);
/* Solve: Vorwärtsiteration */
/* dx0 */
linflp_k24_v_copy_3(linflp_k24_rf0, linflp_k24_dx0);
/* Zeitschritt 0 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx0, linflp_k24_dp0);
linflp_k24_mv_3_3(linflp_k24_Vxx0, linflp_k24_dx0, linflp_k24_dp0);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru0, linflp_k24_du0);
linflp_k24_mv_2_3(linflp_k24_Rux0, linflp_k24_dx0, linflp_k24_du0);
linflp_k24_v_turnsign_2(linflp_k24_du0, linflp_k24_du0);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf1, linflp_k24_dx1);
linflp_k24_mv_sid42_sid2_3_3(linflp_k24_fx0, linflp_k24_dx0, linflp_k24_dx1);
linflp_k24_mv_sid45_sid5_3_2(linflp_k24_fu0, linflp_k24_du0, linflp_k24_dx1);
/* Zeitschritt 1 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx1, linflp_k24_dp1);
linflp_k24_mv_3_3(linflp_k24_Vxx1, linflp_k24_dx1, linflp_k24_dp1);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru1, linflp_k24_du1);
linflp_k24_mv_2_3(linflp_k24_Rux1, linflp_k24_dx1, linflp_k24_du1);
linflp_k24_v_turnsign_2(linflp_k24_du1, linflp_k24_du1);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf2, linflp_k24_dx2);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_dx1, linflp_k24_dx2);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu1, linflp_k24_du1, linflp_k24_dx2);
/* Zeitschritt 2 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx2, linflp_k24_dp2);
linflp_k24_mv_3_3(linflp_k24_Vxx2, linflp_k24_dx2, linflp_k24_dp2);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru2, linflp_k24_du2);
linflp_k24_mv_2_3(linflp_k24_Rux2, linflp_k24_dx2, linflp_k24_du2);
linflp_k24_v_turnsign_2(linflp_k24_du2, linflp_k24_du2);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf3, linflp_k24_dx3);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_dx2, linflp_k24_dx3);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu2, linflp_k24_du2, linflp_k24_dx3);
/* Zeitschritt 3 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx3, linflp_k24_dp3);
linflp_k24_mv_3_3(linflp_k24_Vxx3, linflp_k24_dx3, linflp_k24_dp3);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru3, linflp_k24_du3);
linflp_k24_mv_2_3(linflp_k24_Rux3, linflp_k24_dx3, linflp_k24_du3);
linflp_k24_v_turnsign_2(linflp_k24_du3, linflp_k24_du3);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf4, linflp_k24_dx4);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_dx3, linflp_k24_dx4);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu3, linflp_k24_du3, linflp_k24_dx4);
/* Zeitschritt 4 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx4, linflp_k24_dp4);
linflp_k24_mv_3_3(linflp_k24_Vxx4, linflp_k24_dx4, linflp_k24_dp4);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru4, linflp_k24_du4);
linflp_k24_mv_2_3(linflp_k24_Rux4, linflp_k24_dx4, linflp_k24_du4);
linflp_k24_v_turnsign_2(linflp_k24_du4, linflp_k24_du4);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf5, linflp_k24_dx5);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_dx4, linflp_k24_dx5);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu4, linflp_k24_du4, linflp_k24_dx5);
/* Zeitschritt 5 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx5, linflp_k24_dp5);
linflp_k24_mv_3_3(linflp_k24_Vxx5, linflp_k24_dx5, linflp_k24_dp5);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru5, linflp_k24_du5);
linflp_k24_mv_2_3(linflp_k24_Rux5, linflp_k24_dx5, linflp_k24_du5);
linflp_k24_v_turnsign_2(linflp_k24_du5, linflp_k24_du5);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf6, linflp_k24_dx6);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_dx5, linflp_k24_dx6);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu5, linflp_k24_du5, linflp_k24_dx6);
/* Zeitschritt 6 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx6, linflp_k24_dp6);
linflp_k24_mv_3_3(linflp_k24_Vxx6, linflp_k24_dx6, linflp_k24_dp6);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru6, linflp_k24_du6);
linflp_k24_mv_2_3(linflp_k24_Rux6, linflp_k24_dx6, linflp_k24_du6);
linflp_k24_v_turnsign_2(linflp_k24_du6, linflp_k24_du6);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf7, linflp_k24_dx7);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_dx6, linflp_k24_dx7);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu6, linflp_k24_du6, linflp_k24_dx7);
/* Zeitschritt 7 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx7, linflp_k24_dp7);
linflp_k24_mv_3_3(linflp_k24_Vxx7, linflp_k24_dx7, linflp_k24_dp7);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru7, linflp_k24_du7);
linflp_k24_mv_2_3(linflp_k24_Rux7, linflp_k24_dx7, linflp_k24_du7);
linflp_k24_v_turnsign_2(linflp_k24_du7, linflp_k24_du7);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf8, linflp_k24_dx8);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_dx7, linflp_k24_dx8);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu7, linflp_k24_du7, linflp_k24_dx8);
/* Zeitschritt 8 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx8, linflp_k24_dp8);
linflp_k24_mv_3_3(linflp_k24_Vxx8, linflp_k24_dx8, linflp_k24_dp8);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru8, linflp_k24_du8);
linflp_k24_mv_2_3(linflp_k24_Rux8, linflp_k24_dx8, linflp_k24_du8);
linflp_k24_v_turnsign_2(linflp_k24_du8, linflp_k24_du8);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf9, linflp_k24_dx9);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_dx8, linflp_k24_dx9);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu8, linflp_k24_du8, linflp_k24_dx9);
/* Zeitschritt 9 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx9, linflp_k24_dp9);
linflp_k24_mv_3_3(linflp_k24_Vxx9, linflp_k24_dx9, linflp_k24_dp9);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru9, linflp_k24_du9);
linflp_k24_mv_2_3(linflp_k24_Rux9, linflp_k24_dx9, linflp_k24_du9);
linflp_k24_v_turnsign_2(linflp_k24_du9, linflp_k24_du9);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf10, linflp_k24_dx10);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_dx9, linflp_k24_dx10);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu9, linflp_k24_du9, linflp_k24_dx10);
/* Zeitschritt 10 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx10, linflp_k24_dp10);
linflp_k24_mv_3_3(linflp_k24_Vxx10, linflp_k24_dx10, linflp_k24_dp10);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru10, linflp_k24_du10);
linflp_k24_mv_2_3(linflp_k24_Rux10, linflp_k24_dx10, linflp_k24_du10);
linflp_k24_v_turnsign_2(linflp_k24_du10, linflp_k24_du10);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf11, linflp_k24_dx11);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_dx10, linflp_k24_dx11);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu10, linflp_k24_du10, linflp_k24_dx11);
/* Zeitschritt 11 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx11, linflp_k24_dp11);
linflp_k24_mv_3_3(linflp_k24_Vxx11, linflp_k24_dx11, linflp_k24_dp11);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru11, linflp_k24_du11);
linflp_k24_mv_2_3(linflp_k24_Rux11, linflp_k24_dx11, linflp_k24_du11);
linflp_k24_v_turnsign_2(linflp_k24_du11, linflp_k24_du11);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf12, linflp_k24_dx12);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_dx11, linflp_k24_dx12);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu11, linflp_k24_du11, linflp_k24_dx12);
/* Zeitschritt 12 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx12, linflp_k24_dp12);
linflp_k24_mv_3_3(linflp_k24_Vxx12, linflp_k24_dx12, linflp_k24_dp12);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru12, linflp_k24_du12);
linflp_k24_mv_2_3(linflp_k24_Rux12, linflp_k24_dx12, linflp_k24_du12);
linflp_k24_v_turnsign_2(linflp_k24_du12, linflp_k24_du12);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf13, linflp_k24_dx13);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_dx12, linflp_k24_dx13);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu12, linflp_k24_du12, linflp_k24_dx13);
/* Zeitschritt 13 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx13, linflp_k24_dp13);
linflp_k24_mv_3_3(linflp_k24_Vxx13, linflp_k24_dx13, linflp_k24_dp13);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru13, linflp_k24_du13);
linflp_k24_mv_2_3(linflp_k24_Rux13, linflp_k24_dx13, linflp_k24_du13);
linflp_k24_v_turnsign_2(linflp_k24_du13, linflp_k24_du13);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf14, linflp_k24_dx14);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_dx13, linflp_k24_dx14);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu13, linflp_k24_du13, linflp_k24_dx14);
/* Zeitschritt 14 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx14, linflp_k24_dp14);
linflp_k24_mv_3_3(linflp_k24_Vxx14, linflp_k24_dx14, linflp_k24_dp14);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru14, linflp_k24_du14);
linflp_k24_mv_2_3(linflp_k24_Rux14, linflp_k24_dx14, linflp_k24_du14);
linflp_k24_v_turnsign_2(linflp_k24_du14, linflp_k24_du14);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf15, linflp_k24_dx15);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_dx14, linflp_k24_dx15);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu14, linflp_k24_du14, linflp_k24_dx15);
/* Zeitschritt 15 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx15, linflp_k24_dp15);
linflp_k24_mv_3_3(linflp_k24_Vxx15, linflp_k24_dx15, linflp_k24_dp15);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru15, linflp_k24_du15);
linflp_k24_mv_2_3(linflp_k24_Rux15, linflp_k24_dx15, linflp_k24_du15);
linflp_k24_v_turnsign_2(linflp_k24_du15, linflp_k24_du15);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf16, linflp_k24_dx16);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_dx15, linflp_k24_dx16);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu15, linflp_k24_du15, linflp_k24_dx16);
/* Zeitschritt 16 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx16, linflp_k24_dp16);
linflp_k24_mv_3_3(linflp_k24_Vxx16, linflp_k24_dx16, linflp_k24_dp16);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru16, linflp_k24_du16);
linflp_k24_mv_2_3(linflp_k24_Rux16, linflp_k24_dx16, linflp_k24_du16);
linflp_k24_v_turnsign_2(linflp_k24_du16, linflp_k24_du16);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf17, linflp_k24_dx17);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_dx16, linflp_k24_dx17);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu16, linflp_k24_du16, linflp_k24_dx17);
/* Zeitschritt 17 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx17, linflp_k24_dp17);
linflp_k24_mv_3_3(linflp_k24_Vxx17, linflp_k24_dx17, linflp_k24_dp17);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru17, linflp_k24_du17);
linflp_k24_mv_2_3(linflp_k24_Rux17, linflp_k24_dx17, linflp_k24_du17);
linflp_k24_v_turnsign_2(linflp_k24_du17, linflp_k24_du17);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf18, linflp_k24_dx18);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_dx17, linflp_k24_dx18);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu17, linflp_k24_du17, linflp_k24_dx18);
/* Zeitschritt 18 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx18, linflp_k24_dp18);
linflp_k24_mv_3_3(linflp_k24_Vxx18, linflp_k24_dx18, linflp_k24_dp18);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru18, linflp_k24_du18);
linflp_k24_mv_2_3(linflp_k24_Rux18, linflp_k24_dx18, linflp_k24_du18);
linflp_k24_v_turnsign_2(linflp_k24_du18, linflp_k24_du18);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf19, linflp_k24_dx19);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_dx18, linflp_k24_dx19);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu18, linflp_k24_du18, linflp_k24_dx19);
/* Zeitschritt 19 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx19, linflp_k24_dp19);
linflp_k24_mv_3_3(linflp_k24_Vxx19, linflp_k24_dx19, linflp_k24_dp19);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru19, linflp_k24_du19);
linflp_k24_mv_2_3(linflp_k24_Rux19, linflp_k24_dx19, linflp_k24_du19);
linflp_k24_v_turnsign_2(linflp_k24_du19, linflp_k24_du19);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf20, linflp_k24_dx20);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_dx19, linflp_k24_dx20);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu19, linflp_k24_du19, linflp_k24_dx20);
/* Zeitschritt 20 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx20, linflp_k24_dp20);
linflp_k24_mv_3_3(linflp_k24_Vxx20, linflp_k24_dx20, linflp_k24_dp20);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru20, linflp_k24_du20);
linflp_k24_mv_2_3(linflp_k24_Rux20, linflp_k24_dx20, linflp_k24_du20);
linflp_k24_v_turnsign_2(linflp_k24_du20, linflp_k24_du20);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf21, linflp_k24_dx21);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_dx20, linflp_k24_dx21);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu20, linflp_k24_du20, linflp_k24_dx21);
/* Zeitschritt 21 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx21, linflp_k24_dp21);
linflp_k24_mv_3_3(linflp_k24_Vxx21, linflp_k24_dx21, linflp_k24_dp21);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru21, linflp_k24_du21);
linflp_k24_mv_2_3(linflp_k24_Rux21, linflp_k24_dx21, linflp_k24_du21);
linflp_k24_v_turnsign_2(linflp_k24_du21, linflp_k24_du21);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf22, linflp_k24_dx22);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_dx21, linflp_k24_dx22);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu21, linflp_k24_du21, linflp_k24_dx22);
/* Zeitschritt 22 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx22, linflp_k24_dp22);
linflp_k24_mv_3_3(linflp_k24_Vxx22, linflp_k24_dx22, linflp_k24_dp22);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru22, linflp_k24_du22);
linflp_k24_mv_2_3(linflp_k24_Rux22, linflp_k24_dx22, linflp_k24_du22);
linflp_k24_v_turnsign_2(linflp_k24_du22, linflp_k24_du22);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf23, linflp_k24_dx23);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_dx22, linflp_k24_dx23);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu22, linflp_k24_du22, linflp_k24_dx23);
/* Zeitschritt 23 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx23, linflp_k24_dp23);
linflp_k24_mv_3_3(linflp_k24_Vxx23, linflp_k24_dx23, linflp_k24_dp23);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru23, linflp_k24_du23);
linflp_k24_mv_2_3(linflp_k24_Rux23, linflp_k24_dx23, linflp_k24_du23);
linflp_k24_v_turnsign_2(linflp_k24_du23, linflp_k24_du23);
/* dx */
linflp_k24_v_copy_3(linflp_k24_rf24, linflp_k24_dx24);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx23, linflp_k24_dx23, linflp_k24_dx24);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu23, linflp_k24_du23, linflp_k24_dx24);
/* Zeitschritt 24 */
/* dp */
linflp_k24_v_copy_3(linflp_k24_Vx24, linflp_k24_dp24);
linflp_k24_mv_3_3(linflp_k24_Vxx24, linflp_k24_dx24, linflp_k24_dp24);
/* du */
linflp_k24_v_copy_2(linflp_k24_Ru24, linflp_k24_du24);
linflp_k24_mv_2_3(linflp_k24_Rux24, linflp_k24_dx24, linflp_k24_du24);
linflp_k24_v_turnsign_2(linflp_k24_du24, linflp_k24_du24);
/* dx */
linflp_k24_error_source = 0;

}


static void linflp_k24_glqdocpip_rhs_affine()
{
/* Zeitschritt 0 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x0, linflp_k24_rf0x0);
linflp_k24_mv_sid21_sid2_3_3(linflp_k24_Hxx0, linflp_k24_x0, linflp_k24_rf0x0);
linflp_k24_mv_sid24_sid5_3_2(linflp_k24_Hxu0, linflp_k24_u0, linflp_k24_rf0x0);
linflp_k24_vsub_3(linflp_k24_rf0x0, linflp_k24_p0, linflp_k24_rf0x0);
linflp_k24_mtv_sid42_sid2_3_3(linflp_k24_fx0, linflp_k24_p1, linflp_k24_rf0x0);
linflp_k24_mtv_sid51_sid15_10_3(linflp_k24_gx0, linflp_k24_y0, linflp_k24_rf0x0);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u0, linflp_k24_rf0u0);
linflp_k24_mtv_sid24_sid2_3_2(linflp_k24_Hxu0, linflp_k24_x0, linflp_k24_rf0u0);
linflp_k24_mv_sid27_sid5_2_2(linflp_k24_Huu0, linflp_k24_u0, linflp_k24_rf0u0);
linflp_k24_mtv_sid45_sid2_3_2(linflp_k24_fu0, linflp_k24_p1, linflp_k24_rf0u0);
linflp_k24_mtv_sid54_sid15_10_2(linflp_k24_gu0, linflp_k24_y0, linflp_k24_rf0u0);
/* rf */
linflp_k24_v_copy_3(linflp_k24_xinit, linflp_k24_rf0);
linflp_k24_vsub_3(linflp_k24_rf0, linflp_k24_x0, linflp_k24_rf0);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g0, linflp_k24_rc0);
linflp_k24_mv_sid51_sid2_10_3(linflp_k24_gx0, linflp_k24_x0, linflp_k24_rc0);
linflp_k24_mv_sid54_sid5_10_2(linflp_k24_gu0, linflp_k24_u0, linflp_k24_rc0);
linflp_k24_vadd_10(linflp_k24_rc0, linflp_k24_nu0, linflp_k24_rc0);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y0, linflp_k24_nu0, linflp_k24_rk0);
/* Zeitschritt 1 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x1, linflp_k24_rf0x1);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx1, linflp_k24_x1, linflp_k24_rf0x1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu1, linflp_k24_u1, linflp_k24_rf0x1);
linflp_k24_vsub_3(linflp_k24_rf0x1, linflp_k24_p1, linflp_k24_rf0x1);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_p2, linflp_k24_rf0x1);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx1, linflp_k24_y1, linflp_k24_rf0x1);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u1, linflp_k24_rf0u1);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu1, linflp_k24_x1, linflp_k24_rf0u1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu1, linflp_k24_u1, linflp_k24_rf0u1);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu1, linflp_k24_p2, linflp_k24_rf0u1);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu1, linflp_k24_y1, linflp_k24_rf0u1);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f0, linflp_k24_rf1);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx0, linflp_k24_x0, linflp_k24_rf1);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu0, linflp_k24_u0, linflp_k24_rf1);
linflp_k24_vsub_3(linflp_k24_rf1, linflp_k24_x1, linflp_k24_rf1);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g1, linflp_k24_rc1);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx1, linflp_k24_x1, linflp_k24_rc1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu1, linflp_k24_u1, linflp_k24_rc1);
linflp_k24_vadd_10(linflp_k24_rc1, linflp_k24_nu1, linflp_k24_rc1);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y1, linflp_k24_nu1, linflp_k24_rk1);
/* Zeitschritt 2 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x2, linflp_k24_rf0x2);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx2, linflp_k24_x2, linflp_k24_rf0x2);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu2, linflp_k24_u2, linflp_k24_rf0x2);
linflp_k24_vsub_3(linflp_k24_rf0x2, linflp_k24_p2, linflp_k24_rf0x2);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_p3, linflp_k24_rf0x2);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx2, linflp_k24_y2, linflp_k24_rf0x2);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u2, linflp_k24_rf0u2);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu2, linflp_k24_x2, linflp_k24_rf0u2);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu2, linflp_k24_u2, linflp_k24_rf0u2);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu2, linflp_k24_p3, linflp_k24_rf0u2);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu2, linflp_k24_y2, linflp_k24_rf0u2);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f1, linflp_k24_rf2);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_x1, linflp_k24_rf2);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu1, linflp_k24_u1, linflp_k24_rf2);
linflp_k24_vsub_3(linflp_k24_rf2, linflp_k24_x2, linflp_k24_rf2);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g2, linflp_k24_rc2);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx2, linflp_k24_x2, linflp_k24_rc2);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu2, linflp_k24_u2, linflp_k24_rc2);
linflp_k24_vadd_10(linflp_k24_rc2, linflp_k24_nu2, linflp_k24_rc2);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y2, linflp_k24_nu2, linflp_k24_rk2);
/* Zeitschritt 3 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x3, linflp_k24_rf0x3);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx3, linflp_k24_x3, linflp_k24_rf0x3);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu3, linflp_k24_u3, linflp_k24_rf0x3);
linflp_k24_vsub_3(linflp_k24_rf0x3, linflp_k24_p3, linflp_k24_rf0x3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_p4, linflp_k24_rf0x3);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx3, linflp_k24_y3, linflp_k24_rf0x3);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u3, linflp_k24_rf0u3);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu3, linflp_k24_x3, linflp_k24_rf0u3);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu3, linflp_k24_u3, linflp_k24_rf0u3);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu3, linflp_k24_p4, linflp_k24_rf0u3);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu3, linflp_k24_y3, linflp_k24_rf0u3);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f2, linflp_k24_rf3);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_x2, linflp_k24_rf3);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu2, linflp_k24_u2, linflp_k24_rf3);
linflp_k24_vsub_3(linflp_k24_rf3, linflp_k24_x3, linflp_k24_rf3);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g3, linflp_k24_rc3);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx3, linflp_k24_x3, linflp_k24_rc3);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu3, linflp_k24_u3, linflp_k24_rc3);
linflp_k24_vadd_10(linflp_k24_rc3, linflp_k24_nu3, linflp_k24_rc3);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y3, linflp_k24_nu3, linflp_k24_rk3);
/* Zeitschritt 4 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x4, linflp_k24_rf0x4);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx4, linflp_k24_x4, linflp_k24_rf0x4);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu4, linflp_k24_u4, linflp_k24_rf0x4);
linflp_k24_vsub_3(linflp_k24_rf0x4, linflp_k24_p4, linflp_k24_rf0x4);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_p5, linflp_k24_rf0x4);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx4, linflp_k24_y4, linflp_k24_rf0x4);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u4, linflp_k24_rf0u4);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu4, linflp_k24_x4, linflp_k24_rf0u4);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu4, linflp_k24_u4, linflp_k24_rf0u4);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu4, linflp_k24_p5, linflp_k24_rf0u4);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu4, linflp_k24_y4, linflp_k24_rf0u4);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f3, linflp_k24_rf4);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_x3, linflp_k24_rf4);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu3, linflp_k24_u3, linflp_k24_rf4);
linflp_k24_vsub_3(linflp_k24_rf4, linflp_k24_x4, linflp_k24_rf4);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g4, linflp_k24_rc4);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx4, linflp_k24_x4, linflp_k24_rc4);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu4, linflp_k24_u4, linflp_k24_rc4);
linflp_k24_vadd_10(linflp_k24_rc4, linflp_k24_nu4, linflp_k24_rc4);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y4, linflp_k24_nu4, linflp_k24_rk4);
/* Zeitschritt 5 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x5, linflp_k24_rf0x5);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx5, linflp_k24_x5, linflp_k24_rf0x5);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu5, linflp_k24_u5, linflp_k24_rf0x5);
linflp_k24_vsub_3(linflp_k24_rf0x5, linflp_k24_p5, linflp_k24_rf0x5);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_p6, linflp_k24_rf0x5);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx5, linflp_k24_y5, linflp_k24_rf0x5);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u5, linflp_k24_rf0u5);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu5, linflp_k24_x5, linflp_k24_rf0u5);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu5, linflp_k24_u5, linflp_k24_rf0u5);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu5, linflp_k24_p6, linflp_k24_rf0u5);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu5, linflp_k24_y5, linflp_k24_rf0u5);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f4, linflp_k24_rf5);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_x4, linflp_k24_rf5);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu4, linflp_k24_u4, linflp_k24_rf5);
linflp_k24_vsub_3(linflp_k24_rf5, linflp_k24_x5, linflp_k24_rf5);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g5, linflp_k24_rc5);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx5, linflp_k24_x5, linflp_k24_rc5);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu5, linflp_k24_u5, linflp_k24_rc5);
linflp_k24_vadd_10(linflp_k24_rc5, linflp_k24_nu5, linflp_k24_rc5);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y5, linflp_k24_nu5, linflp_k24_rk5);
/* Zeitschritt 6 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x6, linflp_k24_rf0x6);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx6, linflp_k24_x6, linflp_k24_rf0x6);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu6, linflp_k24_u6, linflp_k24_rf0x6);
linflp_k24_vsub_3(linflp_k24_rf0x6, linflp_k24_p6, linflp_k24_rf0x6);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_p7, linflp_k24_rf0x6);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx6, linflp_k24_y6, linflp_k24_rf0x6);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u6, linflp_k24_rf0u6);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu6, linflp_k24_x6, linflp_k24_rf0u6);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu6, linflp_k24_u6, linflp_k24_rf0u6);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu6, linflp_k24_p7, linflp_k24_rf0u6);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu6, linflp_k24_y6, linflp_k24_rf0u6);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f5, linflp_k24_rf6);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_x5, linflp_k24_rf6);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu5, linflp_k24_u5, linflp_k24_rf6);
linflp_k24_vsub_3(linflp_k24_rf6, linflp_k24_x6, linflp_k24_rf6);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g6, linflp_k24_rc6);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx6, linflp_k24_x6, linflp_k24_rc6);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu6, linflp_k24_u6, linflp_k24_rc6);
linflp_k24_vadd_10(linflp_k24_rc6, linflp_k24_nu6, linflp_k24_rc6);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y6, linflp_k24_nu6, linflp_k24_rk6);
/* Zeitschritt 7 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x7, linflp_k24_rf0x7);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx7, linflp_k24_x7, linflp_k24_rf0x7);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu7, linflp_k24_u7, linflp_k24_rf0x7);
linflp_k24_vsub_3(linflp_k24_rf0x7, linflp_k24_p7, linflp_k24_rf0x7);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_p8, linflp_k24_rf0x7);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx7, linflp_k24_y7, linflp_k24_rf0x7);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u7, linflp_k24_rf0u7);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu7, linflp_k24_x7, linflp_k24_rf0u7);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu7, linflp_k24_u7, linflp_k24_rf0u7);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu7, linflp_k24_p8, linflp_k24_rf0u7);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu7, linflp_k24_y7, linflp_k24_rf0u7);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f6, linflp_k24_rf7);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_x6, linflp_k24_rf7);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu6, linflp_k24_u6, linflp_k24_rf7);
linflp_k24_vsub_3(linflp_k24_rf7, linflp_k24_x7, linflp_k24_rf7);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g7, linflp_k24_rc7);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx7, linflp_k24_x7, linflp_k24_rc7);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu7, linflp_k24_u7, linflp_k24_rc7);
linflp_k24_vadd_10(linflp_k24_rc7, linflp_k24_nu7, linflp_k24_rc7);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y7, linflp_k24_nu7, linflp_k24_rk7);
/* Zeitschritt 8 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x8, linflp_k24_rf0x8);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx8, linflp_k24_x8, linflp_k24_rf0x8);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu8, linflp_k24_u8, linflp_k24_rf0x8);
linflp_k24_vsub_3(linflp_k24_rf0x8, linflp_k24_p8, linflp_k24_rf0x8);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_p9, linflp_k24_rf0x8);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx8, linflp_k24_y8, linflp_k24_rf0x8);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u8, linflp_k24_rf0u8);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu8, linflp_k24_x8, linflp_k24_rf0u8);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu8, linflp_k24_u8, linflp_k24_rf0u8);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu8, linflp_k24_p9, linflp_k24_rf0u8);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu8, linflp_k24_y8, linflp_k24_rf0u8);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f7, linflp_k24_rf8);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_x7, linflp_k24_rf8);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu7, linflp_k24_u7, linflp_k24_rf8);
linflp_k24_vsub_3(linflp_k24_rf8, linflp_k24_x8, linflp_k24_rf8);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g8, linflp_k24_rc8);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx8, linflp_k24_x8, linflp_k24_rc8);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu8, linflp_k24_u8, linflp_k24_rc8);
linflp_k24_vadd_10(linflp_k24_rc8, linflp_k24_nu8, linflp_k24_rc8);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y8, linflp_k24_nu8, linflp_k24_rk8);
/* Zeitschritt 9 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x9, linflp_k24_rf0x9);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx9, linflp_k24_x9, linflp_k24_rf0x9);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu9, linflp_k24_u9, linflp_k24_rf0x9);
linflp_k24_vsub_3(linflp_k24_rf0x9, linflp_k24_p9, linflp_k24_rf0x9);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_p10, linflp_k24_rf0x9);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx9, linflp_k24_y9, linflp_k24_rf0x9);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u9, linflp_k24_rf0u9);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu9, linflp_k24_x9, linflp_k24_rf0u9);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu9, linflp_k24_u9, linflp_k24_rf0u9);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu9, linflp_k24_p10, linflp_k24_rf0u9);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu9, linflp_k24_y9, linflp_k24_rf0u9);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f8, linflp_k24_rf9);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_x8, linflp_k24_rf9);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu8, linflp_k24_u8, linflp_k24_rf9);
linflp_k24_vsub_3(linflp_k24_rf9, linflp_k24_x9, linflp_k24_rf9);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g9, linflp_k24_rc9);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx9, linflp_k24_x9, linflp_k24_rc9);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu9, linflp_k24_u9, linflp_k24_rc9);
linflp_k24_vadd_10(linflp_k24_rc9, linflp_k24_nu9, linflp_k24_rc9);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y9, linflp_k24_nu9, linflp_k24_rk9);
/* Zeitschritt 10 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x10, linflp_k24_rf0x10);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx10, linflp_k24_x10, linflp_k24_rf0x10);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu10, linflp_k24_u10, linflp_k24_rf0x10);
linflp_k24_vsub_3(linflp_k24_rf0x10, linflp_k24_p10, linflp_k24_rf0x10);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_p11, linflp_k24_rf0x10);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx10, linflp_k24_y10, linflp_k24_rf0x10);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u10, linflp_k24_rf0u10);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu10, linflp_k24_x10, linflp_k24_rf0u10);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu10, linflp_k24_u10, linflp_k24_rf0u10);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu10, linflp_k24_p11, linflp_k24_rf0u10);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu10, linflp_k24_y10, linflp_k24_rf0u10);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f9, linflp_k24_rf10);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_x9, linflp_k24_rf10);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu9, linflp_k24_u9, linflp_k24_rf10);
linflp_k24_vsub_3(linflp_k24_rf10, linflp_k24_x10, linflp_k24_rf10);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g10, linflp_k24_rc10);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx10, linflp_k24_x10, linflp_k24_rc10);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu10, linflp_k24_u10, linflp_k24_rc10);
linflp_k24_vadd_10(linflp_k24_rc10, linflp_k24_nu10, linflp_k24_rc10);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y10, linflp_k24_nu10, linflp_k24_rk10);
/* Zeitschritt 11 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x11, linflp_k24_rf0x11);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx11, linflp_k24_x11, linflp_k24_rf0x11);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu11, linflp_k24_u11, linflp_k24_rf0x11);
linflp_k24_vsub_3(linflp_k24_rf0x11, linflp_k24_p11, linflp_k24_rf0x11);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_p12, linflp_k24_rf0x11);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx11, linflp_k24_y11, linflp_k24_rf0x11);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u11, linflp_k24_rf0u11);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu11, linflp_k24_x11, linflp_k24_rf0u11);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu11, linflp_k24_u11, linflp_k24_rf0u11);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu11, linflp_k24_p12, linflp_k24_rf0u11);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu11, linflp_k24_y11, linflp_k24_rf0u11);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f10, linflp_k24_rf11);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_x10, linflp_k24_rf11);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu10, linflp_k24_u10, linflp_k24_rf11);
linflp_k24_vsub_3(linflp_k24_rf11, linflp_k24_x11, linflp_k24_rf11);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g11, linflp_k24_rc11);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx11, linflp_k24_x11, linflp_k24_rc11);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu11, linflp_k24_u11, linflp_k24_rc11);
linflp_k24_vadd_10(linflp_k24_rc11, linflp_k24_nu11, linflp_k24_rc11);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y11, linflp_k24_nu11, linflp_k24_rk11);
/* Zeitschritt 12 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x12, linflp_k24_rf0x12);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx12, linflp_k24_x12, linflp_k24_rf0x12);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu12, linflp_k24_u12, linflp_k24_rf0x12);
linflp_k24_vsub_3(linflp_k24_rf0x12, linflp_k24_p12, linflp_k24_rf0x12);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_p13, linflp_k24_rf0x12);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx12, linflp_k24_y12, linflp_k24_rf0x12);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u12, linflp_k24_rf0u12);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu12, linflp_k24_x12, linflp_k24_rf0u12);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu12, linflp_k24_u12, linflp_k24_rf0u12);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu12, linflp_k24_p13, linflp_k24_rf0u12);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu12, linflp_k24_y12, linflp_k24_rf0u12);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f11, linflp_k24_rf12);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_x11, linflp_k24_rf12);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu11, linflp_k24_u11, linflp_k24_rf12);
linflp_k24_vsub_3(linflp_k24_rf12, linflp_k24_x12, linflp_k24_rf12);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g12, linflp_k24_rc12);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx12, linflp_k24_x12, linflp_k24_rc12);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu12, linflp_k24_u12, linflp_k24_rc12);
linflp_k24_vadd_10(linflp_k24_rc12, linflp_k24_nu12, linflp_k24_rc12);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y12, linflp_k24_nu12, linflp_k24_rk12);
/* Zeitschritt 13 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x13, linflp_k24_rf0x13);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx13, linflp_k24_x13, linflp_k24_rf0x13);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu13, linflp_k24_u13, linflp_k24_rf0x13);
linflp_k24_vsub_3(linflp_k24_rf0x13, linflp_k24_p13, linflp_k24_rf0x13);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_p14, linflp_k24_rf0x13);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx13, linflp_k24_y13, linflp_k24_rf0x13);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u13, linflp_k24_rf0u13);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu13, linflp_k24_x13, linflp_k24_rf0u13);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu13, linflp_k24_u13, linflp_k24_rf0u13);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu13, linflp_k24_p14, linflp_k24_rf0u13);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu13, linflp_k24_y13, linflp_k24_rf0u13);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f12, linflp_k24_rf13);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_x12, linflp_k24_rf13);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu12, linflp_k24_u12, linflp_k24_rf13);
linflp_k24_vsub_3(linflp_k24_rf13, linflp_k24_x13, linflp_k24_rf13);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g13, linflp_k24_rc13);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx13, linflp_k24_x13, linflp_k24_rc13);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu13, linflp_k24_u13, linflp_k24_rc13);
linflp_k24_vadd_10(linflp_k24_rc13, linflp_k24_nu13, linflp_k24_rc13);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y13, linflp_k24_nu13, linflp_k24_rk13);
/* Zeitschritt 14 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x14, linflp_k24_rf0x14);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx14, linflp_k24_x14, linflp_k24_rf0x14);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu14, linflp_k24_u14, linflp_k24_rf0x14);
linflp_k24_vsub_3(linflp_k24_rf0x14, linflp_k24_p14, linflp_k24_rf0x14);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_p15, linflp_k24_rf0x14);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx14, linflp_k24_y14, linflp_k24_rf0x14);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u14, linflp_k24_rf0u14);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu14, linflp_k24_x14, linflp_k24_rf0u14);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu14, linflp_k24_u14, linflp_k24_rf0u14);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu14, linflp_k24_p15, linflp_k24_rf0u14);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu14, linflp_k24_y14, linflp_k24_rf0u14);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f13, linflp_k24_rf14);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_x13, linflp_k24_rf14);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu13, linflp_k24_u13, linflp_k24_rf14);
linflp_k24_vsub_3(linflp_k24_rf14, linflp_k24_x14, linflp_k24_rf14);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g14, linflp_k24_rc14);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx14, linflp_k24_x14, linflp_k24_rc14);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu14, linflp_k24_u14, linflp_k24_rc14);
linflp_k24_vadd_10(linflp_k24_rc14, linflp_k24_nu14, linflp_k24_rc14);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y14, linflp_k24_nu14, linflp_k24_rk14);
/* Zeitschritt 15 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x15, linflp_k24_rf0x15);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx15, linflp_k24_x15, linflp_k24_rf0x15);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu15, linflp_k24_u15, linflp_k24_rf0x15);
linflp_k24_vsub_3(linflp_k24_rf0x15, linflp_k24_p15, linflp_k24_rf0x15);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_p16, linflp_k24_rf0x15);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx15, linflp_k24_y15, linflp_k24_rf0x15);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u15, linflp_k24_rf0u15);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu15, linflp_k24_x15, linflp_k24_rf0u15);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu15, linflp_k24_u15, linflp_k24_rf0u15);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu15, linflp_k24_p16, linflp_k24_rf0u15);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu15, linflp_k24_y15, linflp_k24_rf0u15);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f14, linflp_k24_rf15);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_x14, linflp_k24_rf15);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu14, linflp_k24_u14, linflp_k24_rf15);
linflp_k24_vsub_3(linflp_k24_rf15, linflp_k24_x15, linflp_k24_rf15);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g15, linflp_k24_rc15);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx15, linflp_k24_x15, linflp_k24_rc15);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu15, linflp_k24_u15, linflp_k24_rc15);
linflp_k24_vadd_10(linflp_k24_rc15, linflp_k24_nu15, linflp_k24_rc15);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y15, linflp_k24_nu15, linflp_k24_rk15);
/* Zeitschritt 16 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x16, linflp_k24_rf0x16);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx16, linflp_k24_x16, linflp_k24_rf0x16);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu16, linflp_k24_u16, linflp_k24_rf0x16);
linflp_k24_vsub_3(linflp_k24_rf0x16, linflp_k24_p16, linflp_k24_rf0x16);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_p17, linflp_k24_rf0x16);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx16, linflp_k24_y16, linflp_k24_rf0x16);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u16, linflp_k24_rf0u16);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu16, linflp_k24_x16, linflp_k24_rf0u16);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu16, linflp_k24_u16, linflp_k24_rf0u16);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu16, linflp_k24_p17, linflp_k24_rf0u16);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu16, linflp_k24_y16, linflp_k24_rf0u16);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f15, linflp_k24_rf16);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_x15, linflp_k24_rf16);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu15, linflp_k24_u15, linflp_k24_rf16);
linflp_k24_vsub_3(linflp_k24_rf16, linflp_k24_x16, linflp_k24_rf16);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g16, linflp_k24_rc16);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx16, linflp_k24_x16, linflp_k24_rc16);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu16, linflp_k24_u16, linflp_k24_rc16);
linflp_k24_vadd_10(linflp_k24_rc16, linflp_k24_nu16, linflp_k24_rc16);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y16, linflp_k24_nu16, linflp_k24_rk16);
/* Zeitschritt 17 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x17, linflp_k24_rf0x17);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx17, linflp_k24_x17, linflp_k24_rf0x17);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu17, linflp_k24_u17, linflp_k24_rf0x17);
linflp_k24_vsub_3(linflp_k24_rf0x17, linflp_k24_p17, linflp_k24_rf0x17);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_p18, linflp_k24_rf0x17);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx17, linflp_k24_y17, linflp_k24_rf0x17);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u17, linflp_k24_rf0u17);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu17, linflp_k24_x17, linflp_k24_rf0u17);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu17, linflp_k24_u17, linflp_k24_rf0u17);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu17, linflp_k24_p18, linflp_k24_rf0u17);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu17, linflp_k24_y17, linflp_k24_rf0u17);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f16, linflp_k24_rf17);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_x16, linflp_k24_rf17);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu16, linflp_k24_u16, linflp_k24_rf17);
linflp_k24_vsub_3(linflp_k24_rf17, linflp_k24_x17, linflp_k24_rf17);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g17, linflp_k24_rc17);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx17, linflp_k24_x17, linflp_k24_rc17);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu17, linflp_k24_u17, linflp_k24_rc17);
linflp_k24_vadd_10(linflp_k24_rc17, linflp_k24_nu17, linflp_k24_rc17);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y17, linflp_k24_nu17, linflp_k24_rk17);
/* Zeitschritt 18 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x18, linflp_k24_rf0x18);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx18, linflp_k24_x18, linflp_k24_rf0x18);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu18, linflp_k24_u18, linflp_k24_rf0x18);
linflp_k24_vsub_3(linflp_k24_rf0x18, linflp_k24_p18, linflp_k24_rf0x18);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_p19, linflp_k24_rf0x18);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx18, linflp_k24_y18, linflp_k24_rf0x18);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u18, linflp_k24_rf0u18);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu18, linflp_k24_x18, linflp_k24_rf0u18);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu18, linflp_k24_u18, linflp_k24_rf0u18);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu18, linflp_k24_p19, linflp_k24_rf0u18);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu18, linflp_k24_y18, linflp_k24_rf0u18);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f17, linflp_k24_rf18);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_x17, linflp_k24_rf18);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu17, linflp_k24_u17, linflp_k24_rf18);
linflp_k24_vsub_3(linflp_k24_rf18, linflp_k24_x18, linflp_k24_rf18);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g18, linflp_k24_rc18);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx18, linflp_k24_x18, linflp_k24_rc18);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu18, linflp_k24_u18, linflp_k24_rc18);
linflp_k24_vadd_10(linflp_k24_rc18, linflp_k24_nu18, linflp_k24_rc18);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y18, linflp_k24_nu18, linflp_k24_rk18);
/* Zeitschritt 19 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x19, linflp_k24_rf0x19);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx19, linflp_k24_x19, linflp_k24_rf0x19);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu19, linflp_k24_u19, linflp_k24_rf0x19);
linflp_k24_vsub_3(linflp_k24_rf0x19, linflp_k24_p19, linflp_k24_rf0x19);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_p20, linflp_k24_rf0x19);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx19, linflp_k24_y19, linflp_k24_rf0x19);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u19, linflp_k24_rf0u19);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu19, linflp_k24_x19, linflp_k24_rf0u19);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu19, linflp_k24_u19, linflp_k24_rf0u19);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu19, linflp_k24_p20, linflp_k24_rf0u19);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu19, linflp_k24_y19, linflp_k24_rf0u19);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f18, linflp_k24_rf19);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_x18, linflp_k24_rf19);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu18, linflp_k24_u18, linflp_k24_rf19);
linflp_k24_vsub_3(linflp_k24_rf19, linflp_k24_x19, linflp_k24_rf19);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g19, linflp_k24_rc19);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx19, linflp_k24_x19, linflp_k24_rc19);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu19, linflp_k24_u19, linflp_k24_rc19);
linflp_k24_vadd_10(linflp_k24_rc19, linflp_k24_nu19, linflp_k24_rc19);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y19, linflp_k24_nu19, linflp_k24_rk19);
/* Zeitschritt 20 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x20, linflp_k24_rf0x20);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx20, linflp_k24_x20, linflp_k24_rf0x20);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu20, linflp_k24_u20, linflp_k24_rf0x20);
linflp_k24_vsub_3(linflp_k24_rf0x20, linflp_k24_p20, linflp_k24_rf0x20);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_p21, linflp_k24_rf0x20);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx20, linflp_k24_y20, linflp_k24_rf0x20);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u20, linflp_k24_rf0u20);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu20, linflp_k24_x20, linflp_k24_rf0u20);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu20, linflp_k24_u20, linflp_k24_rf0u20);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu20, linflp_k24_p21, linflp_k24_rf0u20);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu20, linflp_k24_y20, linflp_k24_rf0u20);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f19, linflp_k24_rf20);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_x19, linflp_k24_rf20);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu19, linflp_k24_u19, linflp_k24_rf20);
linflp_k24_vsub_3(linflp_k24_rf20, linflp_k24_x20, linflp_k24_rf20);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g20, linflp_k24_rc20);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx20, linflp_k24_x20, linflp_k24_rc20);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu20, linflp_k24_u20, linflp_k24_rc20);
linflp_k24_vadd_10(linflp_k24_rc20, linflp_k24_nu20, linflp_k24_rc20);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y20, linflp_k24_nu20, linflp_k24_rk20);
/* Zeitschritt 21 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x21, linflp_k24_rf0x21);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx21, linflp_k24_x21, linflp_k24_rf0x21);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu21, linflp_k24_u21, linflp_k24_rf0x21);
linflp_k24_vsub_3(linflp_k24_rf0x21, linflp_k24_p21, linflp_k24_rf0x21);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_p22, linflp_k24_rf0x21);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx21, linflp_k24_y21, linflp_k24_rf0x21);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u21, linflp_k24_rf0u21);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu21, linflp_k24_x21, linflp_k24_rf0u21);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu21, linflp_k24_u21, linflp_k24_rf0u21);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu21, linflp_k24_p22, linflp_k24_rf0u21);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu21, linflp_k24_y21, linflp_k24_rf0u21);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f20, linflp_k24_rf21);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_x20, linflp_k24_rf21);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu20, linflp_k24_u20, linflp_k24_rf21);
linflp_k24_vsub_3(linflp_k24_rf21, linflp_k24_x21, linflp_k24_rf21);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g21, linflp_k24_rc21);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx21, linflp_k24_x21, linflp_k24_rc21);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu21, linflp_k24_u21, linflp_k24_rc21);
linflp_k24_vadd_10(linflp_k24_rc21, linflp_k24_nu21, linflp_k24_rc21);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y21, linflp_k24_nu21, linflp_k24_rk21);
/* Zeitschritt 22 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x22, linflp_k24_rf0x22);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx22, linflp_k24_x22, linflp_k24_rf0x22);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu22, linflp_k24_u22, linflp_k24_rf0x22);
linflp_k24_vsub_3(linflp_k24_rf0x22, linflp_k24_p22, linflp_k24_rf0x22);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_p23, linflp_k24_rf0x22);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx22, linflp_k24_y22, linflp_k24_rf0x22);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u22, linflp_k24_rf0u22);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu22, linflp_k24_x22, linflp_k24_rf0u22);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu22, linflp_k24_u22, linflp_k24_rf0u22);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu22, linflp_k24_p23, linflp_k24_rf0u22);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu22, linflp_k24_y22, linflp_k24_rf0u22);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f21, linflp_k24_rf22);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_x21, linflp_k24_rf22);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu21, linflp_k24_u21, linflp_k24_rf22);
linflp_k24_vsub_3(linflp_k24_rf22, linflp_k24_x22, linflp_k24_rf22);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g22, linflp_k24_rc22);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx22, linflp_k24_x22, linflp_k24_rc22);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu22, linflp_k24_u22, linflp_k24_rc22);
linflp_k24_vadd_10(linflp_k24_rc22, linflp_k24_nu22, linflp_k24_rc22);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y22, linflp_k24_nu22, linflp_k24_rk22);
/* Zeitschritt 23 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x23, linflp_k24_rf0x23);
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx23, linflp_k24_x23, linflp_k24_rf0x23);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu23, linflp_k24_u23, linflp_k24_rf0x23);
linflp_k24_vsub_3(linflp_k24_rf0x23, linflp_k24_p23, linflp_k24_rf0x23);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx23, linflp_k24_p24, linflp_k24_rf0x23);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx23, linflp_k24_y23, linflp_k24_rf0x23);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u23, linflp_k24_rf0u23);
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu23, linflp_k24_x23, linflp_k24_rf0u23);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu23, linflp_k24_u23, linflp_k24_rf0u23);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu23, linflp_k24_p24, linflp_k24_rf0u23);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu23, linflp_k24_y23, linflp_k24_rf0u23);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f22, linflp_k24_rf23);
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_x22, linflp_k24_rf23);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu22, linflp_k24_u22, linflp_k24_rf23);
linflp_k24_vsub_3(linflp_k24_rf23, linflp_k24_x23, linflp_k24_rf23);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g23, linflp_k24_rc23);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx23, linflp_k24_x23, linflp_k24_rc23);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu23, linflp_k24_u23, linflp_k24_rc23);
linflp_k24_vadd_10(linflp_k24_rc23, linflp_k24_nu23, linflp_k24_rc23);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y23, linflp_k24_nu23, linflp_k24_rk23);
/* Zeitschritt 24 */
/* rf0x */
linflp_k24_v_copy_3(linflp_k24_f0x24, linflp_k24_rf0x24);
linflp_k24_mv_sid23_sid2_3_3(linflp_k24_Hxx24, linflp_k24_x24, linflp_k24_rf0x24);
linflp_k24_mv_sid26_sid5_3_2(linflp_k24_Hxu24, linflp_k24_u24, linflp_k24_rf0x24);
linflp_k24_vsub_3(linflp_k24_rf0x24, linflp_k24_p24, linflp_k24_rf0x24);
linflp_k24_mtv_sid53_sid17_10_3(linflp_k24_gx24, linflp_k24_y24, linflp_k24_rf0x24);
/* rf0u */
linflp_k24_v_copy_2(linflp_k24_f0u24, linflp_k24_rf0u24);
linflp_k24_mtv_sid26_sid2_3_2(linflp_k24_Hxu24, linflp_k24_x24, linflp_k24_rf0u24);
linflp_k24_mv_sid29_sid5_2_2(linflp_k24_Huu24, linflp_k24_u24, linflp_k24_rf0u24);
linflp_k24_mtv_sid56_sid17_10_2(linflp_k24_gu24, linflp_k24_y24, linflp_k24_rf0u24);
/* rf */
linflp_k24_v_copy_3(linflp_k24_f23, linflp_k24_rf24);
linflp_k24_mv_sid44_sid2_3_3(linflp_k24_fx23, linflp_k24_x23, linflp_k24_rf24);
linflp_k24_mv_sid47_sid5_3_2(linflp_k24_fu23, linflp_k24_u23, linflp_k24_rf24);
linflp_k24_vsub_3(linflp_k24_rf24, linflp_k24_x24, linflp_k24_rf24);
/* rc */
linflp_k24_v_copy_10(linflp_k24_g24, linflp_k24_rc24);
linflp_k24_mv_sid53_sid2_10_3(linflp_k24_gx24, linflp_k24_x24, linflp_k24_rc24);
linflp_k24_mv_sid56_sid5_10_2(linflp_k24_gu24, linflp_k24_u24, linflp_k24_rc24);
linflp_k24_vadd_10(linflp_k24_rc24, linflp_k24_nu24, linflp_k24_rc24);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_y24, linflp_k24_nu24, linflp_k24_rk24);
}


static void linflp_k24_glqdocpip_rhs_corrector()
{
/* Zeitschritt 0 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy0, linflp_k24_dnu0, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk0, linflp_k24_tmp1_10, linflp_k24_rk0);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk0, linflp_k24_tmp2_10, linflp_k24_rk0);
/* Zeitschritt 1 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy1, linflp_k24_dnu1, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk1, linflp_k24_tmp2_10, linflp_k24_rk1);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk1, linflp_k24_tmp1_10, linflp_k24_rk1);
/* Zeitschritt 2 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy2, linflp_k24_dnu2, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk2, linflp_k24_tmp1_10, linflp_k24_rk2);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk2, linflp_k24_tmp2_10, linflp_k24_rk2);
/* Zeitschritt 3 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy3, linflp_k24_dnu3, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk3, linflp_k24_tmp2_10, linflp_k24_rk3);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk3, linflp_k24_tmp1_10, linflp_k24_rk3);
/* Zeitschritt 4 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy4, linflp_k24_dnu4, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk4, linflp_k24_tmp1_10, linflp_k24_rk4);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk4, linflp_k24_tmp2_10, linflp_k24_rk4);
/* Zeitschritt 5 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy5, linflp_k24_dnu5, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk5, linflp_k24_tmp2_10, linflp_k24_rk5);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk5, linflp_k24_tmp1_10, linflp_k24_rk5);
/* Zeitschritt 6 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy6, linflp_k24_dnu6, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk6, linflp_k24_tmp1_10, linflp_k24_rk6);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk6, linflp_k24_tmp2_10, linflp_k24_rk6);
/* Zeitschritt 7 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy7, linflp_k24_dnu7, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk7, linflp_k24_tmp2_10, linflp_k24_rk7);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk7, linflp_k24_tmp1_10, linflp_k24_rk7);
/* Zeitschritt 8 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy8, linflp_k24_dnu8, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk8, linflp_k24_tmp1_10, linflp_k24_rk8);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk8, linflp_k24_tmp2_10, linflp_k24_rk8);
/* Zeitschritt 9 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy9, linflp_k24_dnu9, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk9, linflp_k24_tmp2_10, linflp_k24_rk9);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk9, linflp_k24_tmp1_10, linflp_k24_rk9);
/* Zeitschritt 10 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy10, linflp_k24_dnu10, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk10, linflp_k24_tmp1_10, linflp_k24_rk10);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk10, linflp_k24_tmp2_10, linflp_k24_rk10);
/* Zeitschritt 11 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy11, linflp_k24_dnu11, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk11, linflp_k24_tmp2_10, linflp_k24_rk11);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk11, linflp_k24_tmp1_10, linflp_k24_rk11);
/* Zeitschritt 12 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy12, linflp_k24_dnu12, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk12, linflp_k24_tmp1_10, linflp_k24_rk12);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk12, linflp_k24_tmp2_10, linflp_k24_rk12);
/* Zeitschritt 13 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy13, linflp_k24_dnu13, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk13, linflp_k24_tmp2_10, linflp_k24_rk13);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk13, linflp_k24_tmp1_10, linflp_k24_rk13);
/* Zeitschritt 14 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy14, linflp_k24_dnu14, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk14, linflp_k24_tmp1_10, linflp_k24_rk14);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk14, linflp_k24_tmp2_10, linflp_k24_rk14);
/* Zeitschritt 15 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy15, linflp_k24_dnu15, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk15, linflp_k24_tmp2_10, linflp_k24_rk15);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk15, linflp_k24_tmp1_10, linflp_k24_rk15);
/* Zeitschritt 16 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy16, linflp_k24_dnu16, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk16, linflp_k24_tmp1_10, linflp_k24_rk16);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk16, linflp_k24_tmp2_10, linflp_k24_rk16);
/* Zeitschritt 17 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy17, linflp_k24_dnu17, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk17, linflp_k24_tmp2_10, linflp_k24_rk17);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk17, linflp_k24_tmp1_10, linflp_k24_rk17);
/* Zeitschritt 18 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy18, linflp_k24_dnu18, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk18, linflp_k24_tmp1_10, linflp_k24_rk18);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk18, linflp_k24_tmp2_10, linflp_k24_rk18);
/* Zeitschritt 19 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy19, linflp_k24_dnu19, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk19, linflp_k24_tmp2_10, linflp_k24_rk19);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk19, linflp_k24_tmp1_10, linflp_k24_rk19);
/* Zeitschritt 20 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy20, linflp_k24_dnu20, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk20, linflp_k24_tmp1_10, linflp_k24_rk20);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk20, linflp_k24_tmp2_10, linflp_k24_rk20);
/* Zeitschritt 21 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy21, linflp_k24_dnu21, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk21, linflp_k24_tmp2_10, linflp_k24_rk21);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk21, linflp_k24_tmp1_10, linflp_k24_rk21);
/* Zeitschritt 22 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy22, linflp_k24_dnu22, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk22, linflp_k24_tmp1_10, linflp_k24_rk22);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk22, linflp_k24_tmp2_10, linflp_k24_rk22);
/* Zeitschritt 23 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy23, linflp_k24_dnu23, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk23, linflp_k24_tmp2_10, linflp_k24_rk23);
linflp_k24_v_init1_10(linflp_k24_tmp2_10);
linflp_k24_v_init0_10(linflp_k24_tmp1_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp2_10, linflp_k24_tmp1_10);
linflp_k24_vsub_10(linflp_k24_rk23, linflp_k24_tmp1_10, linflp_k24_rk23);
/* Zeitschritt 24 */
/* rk_corr */
linflp_k24_vv_elemult_10(linflp_k24_dy24, linflp_k24_dnu24, linflp_k24_tmp1_10);
linflp_k24_vadd_10(linflp_k24_rk24, linflp_k24_tmp1_10, linflp_k24_rk24);
linflp_k24_v_init1_10(linflp_k24_tmp1_10);
linflp_k24_v_init0_10(linflp_k24_tmp2_10);
linflp_k24_vv_elemult_1(linflp_k24_sigma, linflp_k24_mu, linflp_k24_tmp1_1);
linflp_k24_sv_10(linflp_k24_tmp1_1, linflp_k24_tmp1_10, linflp_k24_tmp2_10);
linflp_k24_vsub_10(linflp_k24_rk24, linflp_k24_tmp2_10, linflp_k24_rk24);
}


static void linflp_k24_glqdocpip_rhs_reduced()
{
linflp_k24_error_source = 3;
/* Zeitschritt 0 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny0);
linflp_k24_vv_elediv_10(&linflp_k24_y0[0], &linflp_k24_nu0[0], &linflp_k24_yny0[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs0, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk0[0], &linflp_k24_y0[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc0[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny0, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x0, linflp_k24_rrf0x0);
linflp_k24_mtv_sid51_sid15_10_3(linflp_k24_gx0, linflp_k24_tmp1_10_1, linflp_k24_rrf0x0);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u0, linflp_k24_rrf0u0);
linflp_k24_mtv_sid54_sid15_10_2(linflp_k24_gu0, linflp_k24_tmp1_10_1, linflp_k24_rrf0u0);
/* Zeitschritt 1 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny1);
linflp_k24_vv_elediv_10(&linflp_k24_y1[0], &linflp_k24_nu1[0], &linflp_k24_yny1[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs1, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk1[0], &linflp_k24_y1[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny1, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x1, linflp_k24_rrf0x1);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx1, linflp_k24_tmp1_10_1, linflp_k24_rrf0x1);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u1, linflp_k24_rrf0u1);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu1, linflp_k24_tmp1_10_1, linflp_k24_rrf0u1);
/* Zeitschritt 2 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny2);
linflp_k24_vv_elediv_10(&linflp_k24_y2[0], &linflp_k24_nu2[0], &linflp_k24_yny2[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs2, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk2[0], &linflp_k24_y2[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc2[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny2, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x2, linflp_k24_rrf0x2);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx2, linflp_k24_tmp1_10_1, linflp_k24_rrf0x2);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u2, linflp_k24_rrf0u2);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu2, linflp_k24_tmp1_10_1, linflp_k24_rrf0u2);
/* Zeitschritt 3 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny3);
linflp_k24_vv_elediv_10(&linflp_k24_y3[0], &linflp_k24_nu3[0], &linflp_k24_yny3[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs3, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk3[0], &linflp_k24_y3[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc3[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny3, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x3, linflp_k24_rrf0x3);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx3, linflp_k24_tmp1_10_1, linflp_k24_rrf0x3);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u3, linflp_k24_rrf0u3);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu3, linflp_k24_tmp1_10_1, linflp_k24_rrf0u3);
/* Zeitschritt 4 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny4);
linflp_k24_vv_elediv_10(&linflp_k24_y4[0], &linflp_k24_nu4[0], &linflp_k24_yny4[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs4, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk4[0], &linflp_k24_y4[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc4[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny4, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x4, linflp_k24_rrf0x4);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx4, linflp_k24_tmp1_10_1, linflp_k24_rrf0x4);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u4, linflp_k24_rrf0u4);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu4, linflp_k24_tmp1_10_1, linflp_k24_rrf0u4);
/* Zeitschritt 5 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny5);
linflp_k24_vv_elediv_10(&linflp_k24_y5[0], &linflp_k24_nu5[0], &linflp_k24_yny5[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs5, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk5[0], &linflp_k24_y5[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc5[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny5, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x5, linflp_k24_rrf0x5);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx5, linflp_k24_tmp1_10_1, linflp_k24_rrf0x5);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u5, linflp_k24_rrf0u5);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu5, linflp_k24_tmp1_10_1, linflp_k24_rrf0u5);
/* Zeitschritt 6 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny6);
linflp_k24_vv_elediv_10(&linflp_k24_y6[0], &linflp_k24_nu6[0], &linflp_k24_yny6[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs6, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk6[0], &linflp_k24_y6[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc6[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny6, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x6, linflp_k24_rrf0x6);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx6, linflp_k24_tmp1_10_1, linflp_k24_rrf0x6);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u6, linflp_k24_rrf0u6);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu6, linflp_k24_tmp1_10_1, linflp_k24_rrf0u6);
/* Zeitschritt 7 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny7);
linflp_k24_vv_elediv_10(&linflp_k24_y7[0], &linflp_k24_nu7[0], &linflp_k24_yny7[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs7, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk7[0], &linflp_k24_y7[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc7[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny7, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x7, linflp_k24_rrf0x7);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx7, linflp_k24_tmp1_10_1, linflp_k24_rrf0x7);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u7, linflp_k24_rrf0u7);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu7, linflp_k24_tmp1_10_1, linflp_k24_rrf0u7);
/* Zeitschritt 8 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny8);
linflp_k24_vv_elediv_10(&linflp_k24_y8[0], &linflp_k24_nu8[0], &linflp_k24_yny8[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs8, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk8[0], &linflp_k24_y8[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc8[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny8, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x8, linflp_k24_rrf0x8);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx8, linflp_k24_tmp1_10_1, linflp_k24_rrf0x8);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u8, linflp_k24_rrf0u8);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu8, linflp_k24_tmp1_10_1, linflp_k24_rrf0u8);
/* Zeitschritt 9 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny9);
linflp_k24_vv_elediv_10(&linflp_k24_y9[0], &linflp_k24_nu9[0], &linflp_k24_yny9[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs9, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk9[0], &linflp_k24_y9[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc9[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny9, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x9, linflp_k24_rrf0x9);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx9, linflp_k24_tmp1_10_1, linflp_k24_rrf0x9);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u9, linflp_k24_rrf0u9);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu9, linflp_k24_tmp1_10_1, linflp_k24_rrf0u9);
/* Zeitschritt 10 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny10);
linflp_k24_vv_elediv_10(&linflp_k24_y10[0], &linflp_k24_nu10[0], &linflp_k24_yny10[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs10, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk10[0], &linflp_k24_y10[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc10[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny10, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x10, linflp_k24_rrf0x10);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx10, linflp_k24_tmp1_10_1, linflp_k24_rrf0x10);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u10, linflp_k24_rrf0u10);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu10, linflp_k24_tmp1_10_1, linflp_k24_rrf0u10);
/* Zeitschritt 11 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny11);
linflp_k24_vv_elediv_10(&linflp_k24_y11[0], &linflp_k24_nu11[0], &linflp_k24_yny11[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs11, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk11[0], &linflp_k24_y11[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc11[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny11, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x11, linflp_k24_rrf0x11);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx11, linflp_k24_tmp1_10_1, linflp_k24_rrf0x11);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u11, linflp_k24_rrf0u11);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu11, linflp_k24_tmp1_10_1, linflp_k24_rrf0u11);
/* Zeitschritt 12 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny12);
linflp_k24_vv_elediv_10(&linflp_k24_y12[0], &linflp_k24_nu12[0], &linflp_k24_yny12[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs12, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk12[0], &linflp_k24_y12[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc12[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny12, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x12, linflp_k24_rrf0x12);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx12, linflp_k24_tmp1_10_1, linflp_k24_rrf0x12);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u12, linflp_k24_rrf0u12);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu12, linflp_k24_tmp1_10_1, linflp_k24_rrf0u12);
/* Zeitschritt 13 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny13);
linflp_k24_vv_elediv_10(&linflp_k24_y13[0], &linflp_k24_nu13[0], &linflp_k24_yny13[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs13, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk13[0], &linflp_k24_y13[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc13[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny13, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x13, linflp_k24_rrf0x13);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx13, linflp_k24_tmp1_10_1, linflp_k24_rrf0x13);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u13, linflp_k24_rrf0u13);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu13, linflp_k24_tmp1_10_1, linflp_k24_rrf0u13);
/* Zeitschritt 14 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny14);
linflp_k24_vv_elediv_10(&linflp_k24_y14[0], &linflp_k24_nu14[0], &linflp_k24_yny14[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs14, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk14[0], &linflp_k24_y14[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc14[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny14, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x14, linflp_k24_rrf0x14);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx14, linflp_k24_tmp1_10_1, linflp_k24_rrf0x14);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u14, linflp_k24_rrf0u14);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu14, linflp_k24_tmp1_10_1, linflp_k24_rrf0u14);
/* Zeitschritt 15 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny15);
linflp_k24_vv_elediv_10(&linflp_k24_y15[0], &linflp_k24_nu15[0], &linflp_k24_yny15[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs15, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk15[0], &linflp_k24_y15[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc15[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny15, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x15, linflp_k24_rrf0x15);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx15, linflp_k24_tmp1_10_1, linflp_k24_rrf0x15);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u15, linflp_k24_rrf0u15);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu15, linflp_k24_tmp1_10_1, linflp_k24_rrf0u15);
/* Zeitschritt 16 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny16);
linflp_k24_vv_elediv_10(&linflp_k24_y16[0], &linflp_k24_nu16[0], &linflp_k24_yny16[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs16, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk16[0], &linflp_k24_y16[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc16[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny16, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x16, linflp_k24_rrf0x16);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx16, linflp_k24_tmp1_10_1, linflp_k24_rrf0x16);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u16, linflp_k24_rrf0u16);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu16, linflp_k24_tmp1_10_1, linflp_k24_rrf0u16);
/* Zeitschritt 17 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny17);
linflp_k24_vv_elediv_10(&linflp_k24_y17[0], &linflp_k24_nu17[0], &linflp_k24_yny17[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs17, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk17[0], &linflp_k24_y17[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc17[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny17, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x17, linflp_k24_rrf0x17);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx17, linflp_k24_tmp1_10_1, linflp_k24_rrf0x17);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u17, linflp_k24_rrf0u17);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu17, linflp_k24_tmp1_10_1, linflp_k24_rrf0u17);
/* Zeitschritt 18 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny18);
linflp_k24_vv_elediv_10(&linflp_k24_y18[0], &linflp_k24_nu18[0], &linflp_k24_yny18[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs18, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk18[0], &linflp_k24_y18[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc18[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny18, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x18, linflp_k24_rrf0x18);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx18, linflp_k24_tmp1_10_1, linflp_k24_rrf0x18);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u18, linflp_k24_rrf0u18);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu18, linflp_k24_tmp1_10_1, linflp_k24_rrf0u18);
/* Zeitschritt 19 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny19);
linflp_k24_vv_elediv_10(&linflp_k24_y19[0], &linflp_k24_nu19[0], &linflp_k24_yny19[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs19, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk19[0], &linflp_k24_y19[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc19[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny19, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x19, linflp_k24_rrf0x19);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx19, linflp_k24_tmp1_10_1, linflp_k24_rrf0x19);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u19, linflp_k24_rrf0u19);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu19, linflp_k24_tmp1_10_1, linflp_k24_rrf0u19);
/* Zeitschritt 20 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny20);
linflp_k24_vv_elediv_10(&linflp_k24_y20[0], &linflp_k24_nu20[0], &linflp_k24_yny20[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs20, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk20[0], &linflp_k24_y20[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc20[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny20, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x20, linflp_k24_rrf0x20);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx20, linflp_k24_tmp1_10_1, linflp_k24_rrf0x20);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u20, linflp_k24_rrf0u20);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu20, linflp_k24_tmp1_10_1, linflp_k24_rrf0u20);
/* Zeitschritt 21 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny21);
linflp_k24_vv_elediv_10(&linflp_k24_y21[0], &linflp_k24_nu21[0], &linflp_k24_yny21[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs21, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk21[0], &linflp_k24_y21[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc21[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny21, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x21, linflp_k24_rrf0x21);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx21, linflp_k24_tmp1_10_1, linflp_k24_rrf0x21);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u21, linflp_k24_rrf0u21);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu21, linflp_k24_tmp1_10_1, linflp_k24_rrf0u21);
/* Zeitschritt 22 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny22);
linflp_k24_vv_elediv_10(&linflp_k24_y22[0], &linflp_k24_nu22[0], &linflp_k24_yny22[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs22, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk22[0], &linflp_k24_y22[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc22[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny22, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x22, linflp_k24_rrf0x22);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx22, linflp_k24_tmp1_10_1, linflp_k24_rrf0x22);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u22, linflp_k24_rrf0u22);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu22, linflp_k24_tmp1_10_1, linflp_k24_rrf0u22);
/* Zeitschritt 23 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny23);
linflp_k24_vv_elediv_10(&linflp_k24_y23[0], &linflp_k24_nu23[0], &linflp_k24_yny23[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs23, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk23[0], &linflp_k24_y23[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc23[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny23, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x23, linflp_k24_rrf0x23);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx23, linflp_k24_tmp1_10_1, linflp_k24_rrf0x23);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u23, linflp_k24_rrf0u23);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu23, linflp_k24_tmp1_10_1, linflp_k24_rrf0u23);
/* Zeitschritt 24 */
/* yny */
linflp_k24_v_init0_10(linflp_k24_yny24);
linflp_k24_vv_elediv_10(&linflp_k24_y24[0], &linflp_k24_nu24[0], &linflp_k24_yny24[0]);
if(linflp_k24_termcode > -1){return;}
/* v1 */
linflp_k24_v_copy_0(linflp_k24_rhsxs24, linflp_k24_tmp1_10_1);
linflp_k24_vv_elediv_10(&linflp_k24_rk24[0], &linflp_k24_y24[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_rc24[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny24, linflp_k24_tmp1_10_1, linflp_k24_tmp1_10_1);
/* rrf0x */
linflp_k24_v_copy_3(linflp_k24_rf0x24, linflp_k24_rrf0x24);
linflp_k24_mtv_sid53_sid17_10_3(linflp_k24_gx24, linflp_k24_tmp1_10_1, linflp_k24_rrf0x24);
/* rrf0u */
linflp_k24_v_copy_2(linflp_k24_rf0u24, linflp_k24_rrf0u24);
linflp_k24_mtv_sid56_sid17_10_2(linflp_k24_gu24, linflp_k24_tmp1_10_1, linflp_k24_rrf0u24);
linflp_k24_error_source = 0;
}


static void linflp_k24_glqdocpip_rhs_iter_ref()
{
/* Zeitschritt 0 */
/* rf0x */
linflp_k24_mv_sid21_sid2_3_3(linflp_k24_Hxx0, linflp_k24_dx0, linflp_k24_rf0x0);
linflp_k24_mv_sid24_sid5_3_2(linflp_k24_Hxu0, linflp_k24_du0, linflp_k24_rf0x0);
linflp_k24_vsub_3(linflp_k24_rf0x0, linflp_k24_dp0, linflp_k24_rf0x0);
linflp_k24_mtv_sid42_sid2_3_3(linflp_k24_fx0, linflp_k24_dp1, linflp_k24_rf0x0);
linflp_k24_mtv_sid51_sid15_10_3(linflp_k24_gx0, linflp_k24_dy0, linflp_k24_rf0x0);
/* rf0u */
linflp_k24_mtv_sid24_sid2_3_2(linflp_k24_Hxu0, linflp_k24_dx0, linflp_k24_rf0u0);
linflp_k24_mv_sid27_sid5_2_2(linflp_k24_Huu0, linflp_k24_du0, linflp_k24_rf0u0);
linflp_k24_mtv_sid45_sid2_3_2(linflp_k24_fu0, linflp_k24_dp1, linflp_k24_rf0u0);
linflp_k24_mtv_sid54_sid15_10_2(linflp_k24_gu0, linflp_k24_dy0, linflp_k24_rf0u0);
/* rf */
linflp_k24_vsub_3(linflp_k24_rf0, linflp_k24_dx0, linflp_k24_rf0);
/* rc */
linflp_k24_mv_sid51_sid2_10_3(linflp_k24_gx0, linflp_k24_dx0, linflp_k24_rc0);
linflp_k24_mv_sid54_sid5_10_2(linflp_k24_gu0, linflp_k24_du0, linflp_k24_rc0);
linflp_k24_vadd_10(linflp_k24_rc0, linflp_k24_dnu0, linflp_k24_rc0);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy0, linflp_k24_nu0, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk0, linflp_k24_tmp2_10, linflp_k24_rk0);
linflp_k24_vv_elemult_10(linflp_k24_dnu0, linflp_k24_y0, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk0, linflp_k24_tmp2_10, linflp_k24_rk0);
/* Zeitschritt 1 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx1, linflp_k24_dx1, linflp_k24_rf0x1);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu1, linflp_k24_du1, linflp_k24_rf0x1);
linflp_k24_vsub_3(linflp_k24_rf0x1, linflp_k24_dp1, linflp_k24_rf0x1);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_dp2, linflp_k24_rf0x1);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx1, linflp_k24_dy1, linflp_k24_rf0x1);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu1, linflp_k24_dx1, linflp_k24_rf0u1);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu1, linflp_k24_du1, linflp_k24_rf0u1);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu1, linflp_k24_dp2, linflp_k24_rf0u1);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu1, linflp_k24_dy1, linflp_k24_rf0u1);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx0, linflp_k24_dx0, linflp_k24_rf1);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu0, linflp_k24_du0, linflp_k24_rf1);
linflp_k24_vsub_3(linflp_k24_rf1, linflp_k24_dx1, linflp_k24_rf1);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx1, linflp_k24_dx1, linflp_k24_rc1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu1, linflp_k24_du1, linflp_k24_rc1);
linflp_k24_vadd_10(linflp_k24_rc1, linflp_k24_dnu1, linflp_k24_rc1);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy1, linflp_k24_nu1, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk1, linflp_k24_tmp2_10, linflp_k24_rk1);
linflp_k24_vv_elemult_10(linflp_k24_dnu1, linflp_k24_y1, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk1, linflp_k24_tmp2_10, linflp_k24_rk1);
/* Zeitschritt 2 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx2, linflp_k24_dx2, linflp_k24_rf0x2);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu2, linflp_k24_du2, linflp_k24_rf0x2);
linflp_k24_vsub_3(linflp_k24_rf0x2, linflp_k24_dp2, linflp_k24_rf0x2);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_dp3, linflp_k24_rf0x2);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx2, linflp_k24_dy2, linflp_k24_rf0x2);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu2, linflp_k24_dx2, linflp_k24_rf0u2);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu2, linflp_k24_du2, linflp_k24_rf0u2);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu2, linflp_k24_dp3, linflp_k24_rf0u2);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu2, linflp_k24_dy2, linflp_k24_rf0u2);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx1, linflp_k24_dx1, linflp_k24_rf2);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu1, linflp_k24_du1, linflp_k24_rf2);
linflp_k24_vsub_3(linflp_k24_rf2, linflp_k24_dx2, linflp_k24_rf2);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx2, linflp_k24_dx2, linflp_k24_rc2);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu2, linflp_k24_du2, linflp_k24_rc2);
linflp_k24_vadd_10(linflp_k24_rc2, linflp_k24_dnu2, linflp_k24_rc2);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy2, linflp_k24_nu2, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk2, linflp_k24_tmp2_10, linflp_k24_rk2);
linflp_k24_vv_elemult_10(linflp_k24_dnu2, linflp_k24_y2, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk2, linflp_k24_tmp2_10, linflp_k24_rk2);
/* Zeitschritt 3 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx3, linflp_k24_dx3, linflp_k24_rf0x3);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu3, linflp_k24_du3, linflp_k24_rf0x3);
linflp_k24_vsub_3(linflp_k24_rf0x3, linflp_k24_dp3, linflp_k24_rf0x3);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_dp4, linflp_k24_rf0x3);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx3, linflp_k24_dy3, linflp_k24_rf0x3);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu3, linflp_k24_dx3, linflp_k24_rf0u3);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu3, linflp_k24_du3, linflp_k24_rf0u3);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu3, linflp_k24_dp4, linflp_k24_rf0u3);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu3, linflp_k24_dy3, linflp_k24_rf0u3);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx2, linflp_k24_dx2, linflp_k24_rf3);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu2, linflp_k24_du2, linflp_k24_rf3);
linflp_k24_vsub_3(linflp_k24_rf3, linflp_k24_dx3, linflp_k24_rf3);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx3, linflp_k24_dx3, linflp_k24_rc3);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu3, linflp_k24_du3, linflp_k24_rc3);
linflp_k24_vadd_10(linflp_k24_rc3, linflp_k24_dnu3, linflp_k24_rc3);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy3, linflp_k24_nu3, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk3, linflp_k24_tmp2_10, linflp_k24_rk3);
linflp_k24_vv_elemult_10(linflp_k24_dnu3, linflp_k24_y3, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk3, linflp_k24_tmp2_10, linflp_k24_rk3);
/* Zeitschritt 4 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx4, linflp_k24_dx4, linflp_k24_rf0x4);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu4, linflp_k24_du4, linflp_k24_rf0x4);
linflp_k24_vsub_3(linflp_k24_rf0x4, linflp_k24_dp4, linflp_k24_rf0x4);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_dp5, linflp_k24_rf0x4);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx4, linflp_k24_dy4, linflp_k24_rf0x4);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu4, linflp_k24_dx4, linflp_k24_rf0u4);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu4, linflp_k24_du4, linflp_k24_rf0u4);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu4, linflp_k24_dp5, linflp_k24_rf0u4);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu4, linflp_k24_dy4, linflp_k24_rf0u4);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx3, linflp_k24_dx3, linflp_k24_rf4);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu3, linflp_k24_du3, linflp_k24_rf4);
linflp_k24_vsub_3(linflp_k24_rf4, linflp_k24_dx4, linflp_k24_rf4);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx4, linflp_k24_dx4, linflp_k24_rc4);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu4, linflp_k24_du4, linflp_k24_rc4);
linflp_k24_vadd_10(linflp_k24_rc4, linflp_k24_dnu4, linflp_k24_rc4);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy4, linflp_k24_nu4, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk4, linflp_k24_tmp2_10, linflp_k24_rk4);
linflp_k24_vv_elemult_10(linflp_k24_dnu4, linflp_k24_y4, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk4, linflp_k24_tmp2_10, linflp_k24_rk4);
/* Zeitschritt 5 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx5, linflp_k24_dx5, linflp_k24_rf0x5);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu5, linflp_k24_du5, linflp_k24_rf0x5);
linflp_k24_vsub_3(linflp_k24_rf0x5, linflp_k24_dp5, linflp_k24_rf0x5);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_dp6, linflp_k24_rf0x5);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx5, linflp_k24_dy5, linflp_k24_rf0x5);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu5, linflp_k24_dx5, linflp_k24_rf0u5);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu5, linflp_k24_du5, linflp_k24_rf0u5);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu5, linflp_k24_dp6, linflp_k24_rf0u5);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu5, linflp_k24_dy5, linflp_k24_rf0u5);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx4, linflp_k24_dx4, linflp_k24_rf5);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu4, linflp_k24_du4, linflp_k24_rf5);
linflp_k24_vsub_3(linflp_k24_rf5, linflp_k24_dx5, linflp_k24_rf5);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx5, linflp_k24_dx5, linflp_k24_rc5);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu5, linflp_k24_du5, linflp_k24_rc5);
linflp_k24_vadd_10(linflp_k24_rc5, linflp_k24_dnu5, linflp_k24_rc5);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy5, linflp_k24_nu5, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk5, linflp_k24_tmp2_10, linflp_k24_rk5);
linflp_k24_vv_elemult_10(linflp_k24_dnu5, linflp_k24_y5, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk5, linflp_k24_tmp2_10, linflp_k24_rk5);
/* Zeitschritt 6 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx6, linflp_k24_dx6, linflp_k24_rf0x6);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu6, linflp_k24_du6, linflp_k24_rf0x6);
linflp_k24_vsub_3(linflp_k24_rf0x6, linflp_k24_dp6, linflp_k24_rf0x6);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_dp7, linflp_k24_rf0x6);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx6, linflp_k24_dy6, linflp_k24_rf0x6);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu6, linflp_k24_dx6, linflp_k24_rf0u6);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu6, linflp_k24_du6, linflp_k24_rf0u6);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu6, linflp_k24_dp7, linflp_k24_rf0u6);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu6, linflp_k24_dy6, linflp_k24_rf0u6);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx5, linflp_k24_dx5, linflp_k24_rf6);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu5, linflp_k24_du5, linflp_k24_rf6);
linflp_k24_vsub_3(linflp_k24_rf6, linflp_k24_dx6, linflp_k24_rf6);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx6, linflp_k24_dx6, linflp_k24_rc6);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu6, linflp_k24_du6, linflp_k24_rc6);
linflp_k24_vadd_10(linflp_k24_rc6, linflp_k24_dnu6, linflp_k24_rc6);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy6, linflp_k24_nu6, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk6, linflp_k24_tmp2_10, linflp_k24_rk6);
linflp_k24_vv_elemult_10(linflp_k24_dnu6, linflp_k24_y6, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk6, linflp_k24_tmp2_10, linflp_k24_rk6);
/* Zeitschritt 7 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx7, linflp_k24_dx7, linflp_k24_rf0x7);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu7, linflp_k24_du7, linflp_k24_rf0x7);
linflp_k24_vsub_3(linflp_k24_rf0x7, linflp_k24_dp7, linflp_k24_rf0x7);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_dp8, linflp_k24_rf0x7);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx7, linflp_k24_dy7, linflp_k24_rf0x7);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu7, linflp_k24_dx7, linflp_k24_rf0u7);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu7, linflp_k24_du7, linflp_k24_rf0u7);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu7, linflp_k24_dp8, linflp_k24_rf0u7);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu7, linflp_k24_dy7, linflp_k24_rf0u7);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx6, linflp_k24_dx6, linflp_k24_rf7);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu6, linflp_k24_du6, linflp_k24_rf7);
linflp_k24_vsub_3(linflp_k24_rf7, linflp_k24_dx7, linflp_k24_rf7);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx7, linflp_k24_dx7, linflp_k24_rc7);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu7, linflp_k24_du7, linflp_k24_rc7);
linflp_k24_vadd_10(linflp_k24_rc7, linflp_k24_dnu7, linflp_k24_rc7);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy7, linflp_k24_nu7, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk7, linflp_k24_tmp2_10, linflp_k24_rk7);
linflp_k24_vv_elemult_10(linflp_k24_dnu7, linflp_k24_y7, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk7, linflp_k24_tmp2_10, linflp_k24_rk7);
/* Zeitschritt 8 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx8, linflp_k24_dx8, linflp_k24_rf0x8);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu8, linflp_k24_du8, linflp_k24_rf0x8);
linflp_k24_vsub_3(linflp_k24_rf0x8, linflp_k24_dp8, linflp_k24_rf0x8);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_dp9, linflp_k24_rf0x8);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx8, linflp_k24_dy8, linflp_k24_rf0x8);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu8, linflp_k24_dx8, linflp_k24_rf0u8);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu8, linflp_k24_du8, linflp_k24_rf0u8);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu8, linflp_k24_dp9, linflp_k24_rf0u8);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu8, linflp_k24_dy8, linflp_k24_rf0u8);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx7, linflp_k24_dx7, linflp_k24_rf8);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu7, linflp_k24_du7, linflp_k24_rf8);
linflp_k24_vsub_3(linflp_k24_rf8, linflp_k24_dx8, linflp_k24_rf8);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx8, linflp_k24_dx8, linflp_k24_rc8);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu8, linflp_k24_du8, linflp_k24_rc8);
linflp_k24_vadd_10(linflp_k24_rc8, linflp_k24_dnu8, linflp_k24_rc8);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy8, linflp_k24_nu8, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk8, linflp_k24_tmp2_10, linflp_k24_rk8);
linflp_k24_vv_elemult_10(linflp_k24_dnu8, linflp_k24_y8, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk8, linflp_k24_tmp2_10, linflp_k24_rk8);
/* Zeitschritt 9 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx9, linflp_k24_dx9, linflp_k24_rf0x9);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu9, linflp_k24_du9, linflp_k24_rf0x9);
linflp_k24_vsub_3(linflp_k24_rf0x9, linflp_k24_dp9, linflp_k24_rf0x9);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_dp10, linflp_k24_rf0x9);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx9, linflp_k24_dy9, linflp_k24_rf0x9);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu9, linflp_k24_dx9, linflp_k24_rf0u9);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu9, linflp_k24_du9, linflp_k24_rf0u9);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu9, linflp_k24_dp10, linflp_k24_rf0u9);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu9, linflp_k24_dy9, linflp_k24_rf0u9);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx8, linflp_k24_dx8, linflp_k24_rf9);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu8, linflp_k24_du8, linflp_k24_rf9);
linflp_k24_vsub_3(linflp_k24_rf9, linflp_k24_dx9, linflp_k24_rf9);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx9, linflp_k24_dx9, linflp_k24_rc9);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu9, linflp_k24_du9, linflp_k24_rc9);
linflp_k24_vadd_10(linflp_k24_rc9, linflp_k24_dnu9, linflp_k24_rc9);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy9, linflp_k24_nu9, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk9, linflp_k24_tmp2_10, linflp_k24_rk9);
linflp_k24_vv_elemult_10(linflp_k24_dnu9, linflp_k24_y9, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk9, linflp_k24_tmp2_10, linflp_k24_rk9);
/* Zeitschritt 10 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx10, linflp_k24_dx10, linflp_k24_rf0x10);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu10, linflp_k24_du10, linflp_k24_rf0x10);
linflp_k24_vsub_3(linflp_k24_rf0x10, linflp_k24_dp10, linflp_k24_rf0x10);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_dp11, linflp_k24_rf0x10);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx10, linflp_k24_dy10, linflp_k24_rf0x10);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu10, linflp_k24_dx10, linflp_k24_rf0u10);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu10, linflp_k24_du10, linflp_k24_rf0u10);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu10, linflp_k24_dp11, linflp_k24_rf0u10);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu10, linflp_k24_dy10, linflp_k24_rf0u10);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx9, linflp_k24_dx9, linflp_k24_rf10);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu9, linflp_k24_du9, linflp_k24_rf10);
linflp_k24_vsub_3(linflp_k24_rf10, linflp_k24_dx10, linflp_k24_rf10);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx10, linflp_k24_dx10, linflp_k24_rc10);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu10, linflp_k24_du10, linflp_k24_rc10);
linflp_k24_vadd_10(linflp_k24_rc10, linflp_k24_dnu10, linflp_k24_rc10);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy10, linflp_k24_nu10, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk10, linflp_k24_tmp2_10, linflp_k24_rk10);
linflp_k24_vv_elemult_10(linflp_k24_dnu10, linflp_k24_y10, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk10, linflp_k24_tmp2_10, linflp_k24_rk10);
/* Zeitschritt 11 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx11, linflp_k24_dx11, linflp_k24_rf0x11);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu11, linflp_k24_du11, linflp_k24_rf0x11);
linflp_k24_vsub_3(linflp_k24_rf0x11, linflp_k24_dp11, linflp_k24_rf0x11);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_dp12, linflp_k24_rf0x11);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx11, linflp_k24_dy11, linflp_k24_rf0x11);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu11, linflp_k24_dx11, linflp_k24_rf0u11);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu11, linflp_k24_du11, linflp_k24_rf0u11);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu11, linflp_k24_dp12, linflp_k24_rf0u11);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu11, linflp_k24_dy11, linflp_k24_rf0u11);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx10, linflp_k24_dx10, linflp_k24_rf11);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu10, linflp_k24_du10, linflp_k24_rf11);
linflp_k24_vsub_3(linflp_k24_rf11, linflp_k24_dx11, linflp_k24_rf11);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx11, linflp_k24_dx11, linflp_k24_rc11);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu11, linflp_k24_du11, linflp_k24_rc11);
linflp_k24_vadd_10(linflp_k24_rc11, linflp_k24_dnu11, linflp_k24_rc11);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy11, linflp_k24_nu11, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk11, linflp_k24_tmp2_10, linflp_k24_rk11);
linflp_k24_vv_elemult_10(linflp_k24_dnu11, linflp_k24_y11, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk11, linflp_k24_tmp2_10, linflp_k24_rk11);
/* Zeitschritt 12 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx12, linflp_k24_dx12, linflp_k24_rf0x12);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu12, linflp_k24_du12, linflp_k24_rf0x12);
linflp_k24_vsub_3(linflp_k24_rf0x12, linflp_k24_dp12, linflp_k24_rf0x12);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_dp13, linflp_k24_rf0x12);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx12, linflp_k24_dy12, linflp_k24_rf0x12);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu12, linflp_k24_dx12, linflp_k24_rf0u12);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu12, linflp_k24_du12, linflp_k24_rf0u12);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu12, linflp_k24_dp13, linflp_k24_rf0u12);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu12, linflp_k24_dy12, linflp_k24_rf0u12);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx11, linflp_k24_dx11, linflp_k24_rf12);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu11, linflp_k24_du11, linflp_k24_rf12);
linflp_k24_vsub_3(linflp_k24_rf12, linflp_k24_dx12, linflp_k24_rf12);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx12, linflp_k24_dx12, linflp_k24_rc12);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu12, linflp_k24_du12, linflp_k24_rc12);
linflp_k24_vadd_10(linflp_k24_rc12, linflp_k24_dnu12, linflp_k24_rc12);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy12, linflp_k24_nu12, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk12, linflp_k24_tmp2_10, linflp_k24_rk12);
linflp_k24_vv_elemult_10(linflp_k24_dnu12, linflp_k24_y12, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk12, linflp_k24_tmp2_10, linflp_k24_rk12);
/* Zeitschritt 13 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx13, linflp_k24_dx13, linflp_k24_rf0x13);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu13, linflp_k24_du13, linflp_k24_rf0x13);
linflp_k24_vsub_3(linflp_k24_rf0x13, linflp_k24_dp13, linflp_k24_rf0x13);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_dp14, linflp_k24_rf0x13);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx13, linflp_k24_dy13, linflp_k24_rf0x13);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu13, linflp_k24_dx13, linflp_k24_rf0u13);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu13, linflp_k24_du13, linflp_k24_rf0u13);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu13, linflp_k24_dp14, linflp_k24_rf0u13);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu13, linflp_k24_dy13, linflp_k24_rf0u13);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx12, linflp_k24_dx12, linflp_k24_rf13);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu12, linflp_k24_du12, linflp_k24_rf13);
linflp_k24_vsub_3(linflp_k24_rf13, linflp_k24_dx13, linflp_k24_rf13);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx13, linflp_k24_dx13, linflp_k24_rc13);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu13, linflp_k24_du13, linflp_k24_rc13);
linflp_k24_vadd_10(linflp_k24_rc13, linflp_k24_dnu13, linflp_k24_rc13);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy13, linflp_k24_nu13, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk13, linflp_k24_tmp2_10, linflp_k24_rk13);
linflp_k24_vv_elemult_10(linflp_k24_dnu13, linflp_k24_y13, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk13, linflp_k24_tmp2_10, linflp_k24_rk13);
/* Zeitschritt 14 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx14, linflp_k24_dx14, linflp_k24_rf0x14);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu14, linflp_k24_du14, linflp_k24_rf0x14);
linflp_k24_vsub_3(linflp_k24_rf0x14, linflp_k24_dp14, linflp_k24_rf0x14);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_dp15, linflp_k24_rf0x14);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx14, linflp_k24_dy14, linflp_k24_rf0x14);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu14, linflp_k24_dx14, linflp_k24_rf0u14);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu14, linflp_k24_du14, linflp_k24_rf0u14);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu14, linflp_k24_dp15, linflp_k24_rf0u14);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu14, linflp_k24_dy14, linflp_k24_rf0u14);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx13, linflp_k24_dx13, linflp_k24_rf14);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu13, linflp_k24_du13, linflp_k24_rf14);
linflp_k24_vsub_3(linflp_k24_rf14, linflp_k24_dx14, linflp_k24_rf14);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx14, linflp_k24_dx14, linflp_k24_rc14);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu14, linflp_k24_du14, linflp_k24_rc14);
linflp_k24_vadd_10(linflp_k24_rc14, linflp_k24_dnu14, linflp_k24_rc14);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy14, linflp_k24_nu14, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk14, linflp_k24_tmp2_10, linflp_k24_rk14);
linflp_k24_vv_elemult_10(linflp_k24_dnu14, linflp_k24_y14, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk14, linflp_k24_tmp2_10, linflp_k24_rk14);
/* Zeitschritt 15 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx15, linflp_k24_dx15, linflp_k24_rf0x15);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu15, linflp_k24_du15, linflp_k24_rf0x15);
linflp_k24_vsub_3(linflp_k24_rf0x15, linflp_k24_dp15, linflp_k24_rf0x15);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_dp16, linflp_k24_rf0x15);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx15, linflp_k24_dy15, linflp_k24_rf0x15);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu15, linflp_k24_dx15, linflp_k24_rf0u15);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu15, linflp_k24_du15, linflp_k24_rf0u15);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu15, linflp_k24_dp16, linflp_k24_rf0u15);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu15, linflp_k24_dy15, linflp_k24_rf0u15);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx14, linflp_k24_dx14, linflp_k24_rf15);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu14, linflp_k24_du14, linflp_k24_rf15);
linflp_k24_vsub_3(linflp_k24_rf15, linflp_k24_dx15, linflp_k24_rf15);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx15, linflp_k24_dx15, linflp_k24_rc15);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu15, linflp_k24_du15, linflp_k24_rc15);
linflp_k24_vadd_10(linflp_k24_rc15, linflp_k24_dnu15, linflp_k24_rc15);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy15, linflp_k24_nu15, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk15, linflp_k24_tmp2_10, linflp_k24_rk15);
linflp_k24_vv_elemult_10(linflp_k24_dnu15, linflp_k24_y15, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk15, linflp_k24_tmp2_10, linflp_k24_rk15);
/* Zeitschritt 16 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx16, linflp_k24_dx16, linflp_k24_rf0x16);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu16, linflp_k24_du16, linflp_k24_rf0x16);
linflp_k24_vsub_3(linflp_k24_rf0x16, linflp_k24_dp16, linflp_k24_rf0x16);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_dp17, linflp_k24_rf0x16);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx16, linflp_k24_dy16, linflp_k24_rf0x16);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu16, linflp_k24_dx16, linflp_k24_rf0u16);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu16, linflp_k24_du16, linflp_k24_rf0u16);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu16, linflp_k24_dp17, linflp_k24_rf0u16);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu16, linflp_k24_dy16, linflp_k24_rf0u16);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx15, linflp_k24_dx15, linflp_k24_rf16);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu15, linflp_k24_du15, linflp_k24_rf16);
linflp_k24_vsub_3(linflp_k24_rf16, linflp_k24_dx16, linflp_k24_rf16);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx16, linflp_k24_dx16, linflp_k24_rc16);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu16, linflp_k24_du16, linflp_k24_rc16);
linflp_k24_vadd_10(linflp_k24_rc16, linflp_k24_dnu16, linflp_k24_rc16);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy16, linflp_k24_nu16, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk16, linflp_k24_tmp2_10, linflp_k24_rk16);
linflp_k24_vv_elemult_10(linflp_k24_dnu16, linflp_k24_y16, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk16, linflp_k24_tmp2_10, linflp_k24_rk16);
/* Zeitschritt 17 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx17, linflp_k24_dx17, linflp_k24_rf0x17);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu17, linflp_k24_du17, linflp_k24_rf0x17);
linflp_k24_vsub_3(linflp_k24_rf0x17, linflp_k24_dp17, linflp_k24_rf0x17);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_dp18, linflp_k24_rf0x17);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx17, linflp_k24_dy17, linflp_k24_rf0x17);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu17, linflp_k24_dx17, linflp_k24_rf0u17);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu17, linflp_k24_du17, linflp_k24_rf0u17);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu17, linflp_k24_dp18, linflp_k24_rf0u17);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu17, linflp_k24_dy17, linflp_k24_rf0u17);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx16, linflp_k24_dx16, linflp_k24_rf17);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu16, linflp_k24_du16, linflp_k24_rf17);
linflp_k24_vsub_3(linflp_k24_rf17, linflp_k24_dx17, linflp_k24_rf17);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx17, linflp_k24_dx17, linflp_k24_rc17);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu17, linflp_k24_du17, linflp_k24_rc17);
linflp_k24_vadd_10(linflp_k24_rc17, linflp_k24_dnu17, linflp_k24_rc17);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy17, linflp_k24_nu17, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk17, linflp_k24_tmp2_10, linflp_k24_rk17);
linflp_k24_vv_elemult_10(linflp_k24_dnu17, linflp_k24_y17, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk17, linflp_k24_tmp2_10, linflp_k24_rk17);
/* Zeitschritt 18 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx18, linflp_k24_dx18, linflp_k24_rf0x18);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu18, linflp_k24_du18, linflp_k24_rf0x18);
linflp_k24_vsub_3(linflp_k24_rf0x18, linflp_k24_dp18, linflp_k24_rf0x18);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_dp19, linflp_k24_rf0x18);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx18, linflp_k24_dy18, linflp_k24_rf0x18);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu18, linflp_k24_dx18, linflp_k24_rf0u18);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu18, linflp_k24_du18, linflp_k24_rf0u18);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu18, linflp_k24_dp19, linflp_k24_rf0u18);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu18, linflp_k24_dy18, linflp_k24_rf0u18);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx17, linflp_k24_dx17, linflp_k24_rf18);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu17, linflp_k24_du17, linflp_k24_rf18);
linflp_k24_vsub_3(linflp_k24_rf18, linflp_k24_dx18, linflp_k24_rf18);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx18, linflp_k24_dx18, linflp_k24_rc18);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu18, linflp_k24_du18, linflp_k24_rc18);
linflp_k24_vadd_10(linflp_k24_rc18, linflp_k24_dnu18, linflp_k24_rc18);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy18, linflp_k24_nu18, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk18, linflp_k24_tmp2_10, linflp_k24_rk18);
linflp_k24_vv_elemult_10(linflp_k24_dnu18, linflp_k24_y18, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk18, linflp_k24_tmp2_10, linflp_k24_rk18);
/* Zeitschritt 19 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx19, linflp_k24_dx19, linflp_k24_rf0x19);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu19, linflp_k24_du19, linflp_k24_rf0x19);
linflp_k24_vsub_3(linflp_k24_rf0x19, linflp_k24_dp19, linflp_k24_rf0x19);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_dp20, linflp_k24_rf0x19);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx19, linflp_k24_dy19, linflp_k24_rf0x19);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu19, linflp_k24_dx19, linflp_k24_rf0u19);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu19, linflp_k24_du19, linflp_k24_rf0u19);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu19, linflp_k24_dp20, linflp_k24_rf0u19);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu19, linflp_k24_dy19, linflp_k24_rf0u19);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx18, linflp_k24_dx18, linflp_k24_rf19);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu18, linflp_k24_du18, linflp_k24_rf19);
linflp_k24_vsub_3(linflp_k24_rf19, linflp_k24_dx19, linflp_k24_rf19);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx19, linflp_k24_dx19, linflp_k24_rc19);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu19, linflp_k24_du19, linflp_k24_rc19);
linflp_k24_vadd_10(linflp_k24_rc19, linflp_k24_dnu19, linflp_k24_rc19);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy19, linflp_k24_nu19, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk19, linflp_k24_tmp2_10, linflp_k24_rk19);
linflp_k24_vv_elemult_10(linflp_k24_dnu19, linflp_k24_y19, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk19, linflp_k24_tmp2_10, linflp_k24_rk19);
/* Zeitschritt 20 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx20, linflp_k24_dx20, linflp_k24_rf0x20);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu20, linflp_k24_du20, linflp_k24_rf0x20);
linflp_k24_vsub_3(linflp_k24_rf0x20, linflp_k24_dp20, linflp_k24_rf0x20);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_dp21, linflp_k24_rf0x20);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx20, linflp_k24_dy20, linflp_k24_rf0x20);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu20, linflp_k24_dx20, linflp_k24_rf0u20);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu20, linflp_k24_du20, linflp_k24_rf0u20);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu20, linflp_k24_dp21, linflp_k24_rf0u20);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu20, linflp_k24_dy20, linflp_k24_rf0u20);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx19, linflp_k24_dx19, linflp_k24_rf20);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu19, linflp_k24_du19, linflp_k24_rf20);
linflp_k24_vsub_3(linflp_k24_rf20, linflp_k24_dx20, linflp_k24_rf20);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx20, linflp_k24_dx20, linflp_k24_rc20);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu20, linflp_k24_du20, linflp_k24_rc20);
linflp_k24_vadd_10(linflp_k24_rc20, linflp_k24_dnu20, linflp_k24_rc20);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy20, linflp_k24_nu20, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk20, linflp_k24_tmp2_10, linflp_k24_rk20);
linflp_k24_vv_elemult_10(linflp_k24_dnu20, linflp_k24_y20, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk20, linflp_k24_tmp2_10, linflp_k24_rk20);
/* Zeitschritt 21 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx21, linflp_k24_dx21, linflp_k24_rf0x21);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu21, linflp_k24_du21, linflp_k24_rf0x21);
linflp_k24_vsub_3(linflp_k24_rf0x21, linflp_k24_dp21, linflp_k24_rf0x21);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_dp22, linflp_k24_rf0x21);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx21, linflp_k24_dy21, linflp_k24_rf0x21);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu21, linflp_k24_dx21, linflp_k24_rf0u21);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu21, linflp_k24_du21, linflp_k24_rf0u21);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu21, linflp_k24_dp22, linflp_k24_rf0u21);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu21, linflp_k24_dy21, linflp_k24_rf0u21);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx20, linflp_k24_dx20, linflp_k24_rf21);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu20, linflp_k24_du20, linflp_k24_rf21);
linflp_k24_vsub_3(linflp_k24_rf21, linflp_k24_dx21, linflp_k24_rf21);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx21, linflp_k24_dx21, linflp_k24_rc21);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu21, linflp_k24_du21, linflp_k24_rc21);
linflp_k24_vadd_10(linflp_k24_rc21, linflp_k24_dnu21, linflp_k24_rc21);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy21, linflp_k24_nu21, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk21, linflp_k24_tmp2_10, linflp_k24_rk21);
linflp_k24_vv_elemult_10(linflp_k24_dnu21, linflp_k24_y21, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk21, linflp_k24_tmp2_10, linflp_k24_rk21);
/* Zeitschritt 22 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx22, linflp_k24_dx22, linflp_k24_rf0x22);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu22, linflp_k24_du22, linflp_k24_rf0x22);
linflp_k24_vsub_3(linflp_k24_rf0x22, linflp_k24_dp22, linflp_k24_rf0x22);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_dp23, linflp_k24_rf0x22);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx22, linflp_k24_dy22, linflp_k24_rf0x22);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu22, linflp_k24_dx22, linflp_k24_rf0u22);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu22, linflp_k24_du22, linflp_k24_rf0u22);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu22, linflp_k24_dp23, linflp_k24_rf0u22);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu22, linflp_k24_dy22, linflp_k24_rf0u22);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx21, linflp_k24_dx21, linflp_k24_rf22);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu21, linflp_k24_du21, linflp_k24_rf22);
linflp_k24_vsub_3(linflp_k24_rf22, linflp_k24_dx22, linflp_k24_rf22);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx22, linflp_k24_dx22, linflp_k24_rc22);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu22, linflp_k24_du22, linflp_k24_rc22);
linflp_k24_vadd_10(linflp_k24_rc22, linflp_k24_dnu22, linflp_k24_rc22);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy22, linflp_k24_nu22, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk22, linflp_k24_tmp2_10, linflp_k24_rk22);
linflp_k24_vv_elemult_10(linflp_k24_dnu22, linflp_k24_y22, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk22, linflp_k24_tmp2_10, linflp_k24_rk22);
/* Zeitschritt 23 */
/* rf0x */
linflp_k24_mv_sid22_sid2_3_3(linflp_k24_Hxx23, linflp_k24_dx23, linflp_k24_rf0x23);
linflp_k24_mv_sid25_sid5_3_2(linflp_k24_Hxu23, linflp_k24_du23, linflp_k24_rf0x23);
linflp_k24_vsub_3(linflp_k24_rf0x23, linflp_k24_dp23, linflp_k24_rf0x23);
linflp_k24_mtv_sid43_sid2_3_3(linflp_k24_fx23, linflp_k24_dp24, linflp_k24_rf0x23);
linflp_k24_mtv_sid52_sid16_10_3(linflp_k24_gx23, linflp_k24_dy23, linflp_k24_rf0x23);
/* rf0u */
linflp_k24_mtv_sid25_sid2_3_2(linflp_k24_Hxu23, linflp_k24_dx23, linflp_k24_rf0u23);
linflp_k24_mv_sid28_sid5_2_2(linflp_k24_Huu23, linflp_k24_du23, linflp_k24_rf0u23);
linflp_k24_mtv_sid46_sid2_3_2(linflp_k24_fu23, linflp_k24_dp24, linflp_k24_rf0u23);
linflp_k24_mtv_sid55_sid16_10_2(linflp_k24_gu23, linflp_k24_dy23, linflp_k24_rf0u23);
/* rf */
linflp_k24_mv_sid43_sid2_3_3(linflp_k24_fx22, linflp_k24_dx22, linflp_k24_rf23);
linflp_k24_mv_sid46_sid5_3_2(linflp_k24_fu22, linflp_k24_du22, linflp_k24_rf23);
linflp_k24_vsub_3(linflp_k24_rf23, linflp_k24_dx23, linflp_k24_rf23);
/* rc */
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx23, linflp_k24_dx23, linflp_k24_rc23);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu23, linflp_k24_du23, linflp_k24_rc23);
linflp_k24_vadd_10(linflp_k24_rc23, linflp_k24_dnu23, linflp_k24_rc23);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy23, linflp_k24_nu23, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk23, linflp_k24_tmp2_10, linflp_k24_rk23);
linflp_k24_vv_elemult_10(linflp_k24_dnu23, linflp_k24_y23, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk23, linflp_k24_tmp2_10, linflp_k24_rk23);
/* Zeitschritt 24 */
/* rf0x */
linflp_k24_mv_sid23_sid2_3_3(linflp_k24_Hxx24, linflp_k24_dx24, linflp_k24_rf0x24);
linflp_k24_mv_sid26_sid5_3_2(linflp_k24_Hxu24, linflp_k24_du24, linflp_k24_rf0x24);
linflp_k24_vsub_3(linflp_k24_rf0x24, linflp_k24_dp24, linflp_k24_rf0x24);
linflp_k24_mtv_sid53_sid17_10_3(linflp_k24_gx24, linflp_k24_dy24, linflp_k24_rf0x24);
/* rf0u */
linflp_k24_mtv_sid26_sid2_3_2(linflp_k24_Hxu24, linflp_k24_dx24, linflp_k24_rf0u24);
linflp_k24_mv_sid29_sid5_2_2(linflp_k24_Huu24, linflp_k24_du24, linflp_k24_rf0u24);
linflp_k24_mtv_sid56_sid17_10_2(linflp_k24_gu24, linflp_k24_dy24, linflp_k24_rf0u24);
/* rf */
linflp_k24_mv_sid44_sid2_3_3(linflp_k24_fx23, linflp_k24_dx23, linflp_k24_rf24);
linflp_k24_mv_sid47_sid5_3_2(linflp_k24_fu23, linflp_k24_du23, linflp_k24_rf24);
linflp_k24_vsub_3(linflp_k24_rf24, linflp_k24_dx24, linflp_k24_rf24);
/* rc */
linflp_k24_mv_sid53_sid2_10_3(linflp_k24_gx24, linflp_k24_dx24, linflp_k24_rc24);
linflp_k24_mv_sid56_sid5_10_2(linflp_k24_gu24, linflp_k24_du24, linflp_k24_rc24);
linflp_k24_vadd_10(linflp_k24_rc24, linflp_k24_dnu24, linflp_k24_rc24);
/* rk */
linflp_k24_vv_elemult_10(linflp_k24_dy24, linflp_k24_nu24, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk24, linflp_k24_tmp2_10, linflp_k24_rk24);
linflp_k24_vv_elemult_10(linflp_k24_dnu24, linflp_k24_y24, linflp_k24_tmp2_10);
linflp_k24_vadd_10(linflp_k24_rk24, linflp_k24_tmp2_10, linflp_k24_rk24);
}


static void linflp_k24_glqdocpip_dereduce()
{
linflp_k24_error_source = 4;
/* Zeitschritt 0 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs0, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc0[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid51_sid2_10_3(linflp_k24_gx0, linflp_k24_dx0, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid54_sid5_10_2(linflp_k24_gu0, linflp_k24_du0, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk0[0], &linflp_k24_y0[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny0, linflp_k24_tmp1_10_1, linflp_k24_dy0);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu0, linflp_k24_dy0, linflp_k24_dnu0);
linflp_k24_vadd_10(linflp_k24_dnu0, linflp_k24_rk0, linflp_k24_dnu0);
linflp_k24_vv_elediv_10(linflp_k24_dnu0, linflp_k24_y0, linflp_k24_dnu0);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu0, linflp_k24_dnu0);
/* Zeitschritt 1 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs1, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc1[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx1, linflp_k24_dx1, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu1, linflp_k24_du1, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk1[0], &linflp_k24_y1[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny1, linflp_k24_tmp1_10_1, linflp_k24_dy1);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu1, linflp_k24_dy1, linflp_k24_dnu1);
linflp_k24_vadd_10(linflp_k24_dnu1, linflp_k24_rk1, linflp_k24_dnu1);
linflp_k24_vv_elediv_10(linflp_k24_dnu1, linflp_k24_y1, linflp_k24_dnu1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu1, linflp_k24_dnu1);
/* Zeitschritt 2 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs2, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc2[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx2, linflp_k24_dx2, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu2, linflp_k24_du2, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk2[0], &linflp_k24_y2[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny2, linflp_k24_tmp1_10_1, linflp_k24_dy2);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu2, linflp_k24_dy2, linflp_k24_dnu2);
linflp_k24_vadd_10(linflp_k24_dnu2, linflp_k24_rk2, linflp_k24_dnu2);
linflp_k24_vv_elediv_10(linflp_k24_dnu2, linflp_k24_y2, linflp_k24_dnu2);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu2, linflp_k24_dnu2);
/* Zeitschritt 3 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs3, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc3[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx3, linflp_k24_dx3, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu3, linflp_k24_du3, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk3[0], &linflp_k24_y3[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny3, linflp_k24_tmp1_10_1, linflp_k24_dy3);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu3, linflp_k24_dy3, linflp_k24_dnu3);
linflp_k24_vadd_10(linflp_k24_dnu3, linflp_k24_rk3, linflp_k24_dnu3);
linflp_k24_vv_elediv_10(linflp_k24_dnu3, linflp_k24_y3, linflp_k24_dnu3);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu3, linflp_k24_dnu3);
/* Zeitschritt 4 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs4, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc4[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx4, linflp_k24_dx4, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu4, linflp_k24_du4, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk4[0], &linflp_k24_y4[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny4, linflp_k24_tmp1_10_1, linflp_k24_dy4);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu4, linflp_k24_dy4, linflp_k24_dnu4);
linflp_k24_vadd_10(linflp_k24_dnu4, linflp_k24_rk4, linflp_k24_dnu4);
linflp_k24_vv_elediv_10(linflp_k24_dnu4, linflp_k24_y4, linflp_k24_dnu4);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu4, linflp_k24_dnu4);
/* Zeitschritt 5 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs5, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc5[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx5, linflp_k24_dx5, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu5, linflp_k24_du5, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk5[0], &linflp_k24_y5[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny5, linflp_k24_tmp1_10_1, linflp_k24_dy5);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu5, linflp_k24_dy5, linflp_k24_dnu5);
linflp_k24_vadd_10(linflp_k24_dnu5, linflp_k24_rk5, linflp_k24_dnu5);
linflp_k24_vv_elediv_10(linflp_k24_dnu5, linflp_k24_y5, linflp_k24_dnu5);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu5, linflp_k24_dnu5);
/* Zeitschritt 6 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs6, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc6[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx6, linflp_k24_dx6, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu6, linflp_k24_du6, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk6[0], &linflp_k24_y6[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny6, linflp_k24_tmp1_10_1, linflp_k24_dy6);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu6, linflp_k24_dy6, linflp_k24_dnu6);
linflp_k24_vadd_10(linflp_k24_dnu6, linflp_k24_rk6, linflp_k24_dnu6);
linflp_k24_vv_elediv_10(linflp_k24_dnu6, linflp_k24_y6, linflp_k24_dnu6);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu6, linflp_k24_dnu6);
/* Zeitschritt 7 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs7, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc7[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx7, linflp_k24_dx7, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu7, linflp_k24_du7, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk7[0], &linflp_k24_y7[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny7, linflp_k24_tmp1_10_1, linflp_k24_dy7);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu7, linflp_k24_dy7, linflp_k24_dnu7);
linflp_k24_vadd_10(linflp_k24_dnu7, linflp_k24_rk7, linflp_k24_dnu7);
linflp_k24_vv_elediv_10(linflp_k24_dnu7, linflp_k24_y7, linflp_k24_dnu7);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu7, linflp_k24_dnu7);
/* Zeitschritt 8 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs8, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc8[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx8, linflp_k24_dx8, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu8, linflp_k24_du8, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk8[0], &linflp_k24_y8[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny8, linflp_k24_tmp1_10_1, linflp_k24_dy8);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu8, linflp_k24_dy8, linflp_k24_dnu8);
linflp_k24_vadd_10(linflp_k24_dnu8, linflp_k24_rk8, linflp_k24_dnu8);
linflp_k24_vv_elediv_10(linflp_k24_dnu8, linflp_k24_y8, linflp_k24_dnu8);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu8, linflp_k24_dnu8);
/* Zeitschritt 9 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs9, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc9[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx9, linflp_k24_dx9, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu9, linflp_k24_du9, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk9[0], &linflp_k24_y9[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny9, linflp_k24_tmp1_10_1, linflp_k24_dy9);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu9, linflp_k24_dy9, linflp_k24_dnu9);
linflp_k24_vadd_10(linflp_k24_dnu9, linflp_k24_rk9, linflp_k24_dnu9);
linflp_k24_vv_elediv_10(linflp_k24_dnu9, linflp_k24_y9, linflp_k24_dnu9);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu9, linflp_k24_dnu9);
/* Zeitschritt 10 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs10, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc10[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx10, linflp_k24_dx10, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu10, linflp_k24_du10, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk10[0], &linflp_k24_y10[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny10, linflp_k24_tmp1_10_1, linflp_k24_dy10);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu10, linflp_k24_dy10, linflp_k24_dnu10);
linflp_k24_vadd_10(linflp_k24_dnu10, linflp_k24_rk10, linflp_k24_dnu10);
linflp_k24_vv_elediv_10(linflp_k24_dnu10, linflp_k24_y10, linflp_k24_dnu10);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu10, linflp_k24_dnu10);
/* Zeitschritt 11 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs11, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc11[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx11, linflp_k24_dx11, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu11, linflp_k24_du11, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk11[0], &linflp_k24_y11[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny11, linflp_k24_tmp1_10_1, linflp_k24_dy11);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu11, linflp_k24_dy11, linflp_k24_dnu11);
linflp_k24_vadd_10(linflp_k24_dnu11, linflp_k24_rk11, linflp_k24_dnu11);
linflp_k24_vv_elediv_10(linflp_k24_dnu11, linflp_k24_y11, linflp_k24_dnu11);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu11, linflp_k24_dnu11);
/* Zeitschritt 12 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs12, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc12[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx12, linflp_k24_dx12, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu12, linflp_k24_du12, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk12[0], &linflp_k24_y12[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny12, linflp_k24_tmp1_10_1, linflp_k24_dy12);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu12, linflp_k24_dy12, linflp_k24_dnu12);
linflp_k24_vadd_10(linflp_k24_dnu12, linflp_k24_rk12, linflp_k24_dnu12);
linflp_k24_vv_elediv_10(linflp_k24_dnu12, linflp_k24_y12, linflp_k24_dnu12);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu12, linflp_k24_dnu12);
/* Zeitschritt 13 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs13, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc13[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx13, linflp_k24_dx13, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu13, linflp_k24_du13, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk13[0], &linflp_k24_y13[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny13, linflp_k24_tmp1_10_1, linflp_k24_dy13);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu13, linflp_k24_dy13, linflp_k24_dnu13);
linflp_k24_vadd_10(linflp_k24_dnu13, linflp_k24_rk13, linflp_k24_dnu13);
linflp_k24_vv_elediv_10(linflp_k24_dnu13, linflp_k24_y13, linflp_k24_dnu13);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu13, linflp_k24_dnu13);
/* Zeitschritt 14 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs14, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc14[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx14, linflp_k24_dx14, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu14, linflp_k24_du14, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk14[0], &linflp_k24_y14[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny14, linflp_k24_tmp1_10_1, linflp_k24_dy14);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu14, linflp_k24_dy14, linflp_k24_dnu14);
linflp_k24_vadd_10(linflp_k24_dnu14, linflp_k24_rk14, linflp_k24_dnu14);
linflp_k24_vv_elediv_10(linflp_k24_dnu14, linflp_k24_y14, linflp_k24_dnu14);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu14, linflp_k24_dnu14);
/* Zeitschritt 15 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs15, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc15[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx15, linflp_k24_dx15, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu15, linflp_k24_du15, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk15[0], &linflp_k24_y15[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny15, linflp_k24_tmp1_10_1, linflp_k24_dy15);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu15, linflp_k24_dy15, linflp_k24_dnu15);
linflp_k24_vadd_10(linflp_k24_dnu15, linflp_k24_rk15, linflp_k24_dnu15);
linflp_k24_vv_elediv_10(linflp_k24_dnu15, linflp_k24_y15, linflp_k24_dnu15);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu15, linflp_k24_dnu15);
/* Zeitschritt 16 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs16, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc16[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx16, linflp_k24_dx16, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu16, linflp_k24_du16, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk16[0], &linflp_k24_y16[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny16, linflp_k24_tmp1_10_1, linflp_k24_dy16);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu16, linflp_k24_dy16, linflp_k24_dnu16);
linflp_k24_vadd_10(linflp_k24_dnu16, linflp_k24_rk16, linflp_k24_dnu16);
linflp_k24_vv_elediv_10(linflp_k24_dnu16, linflp_k24_y16, linflp_k24_dnu16);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu16, linflp_k24_dnu16);
/* Zeitschritt 17 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs17, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc17[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx17, linflp_k24_dx17, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu17, linflp_k24_du17, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk17[0], &linflp_k24_y17[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny17, linflp_k24_tmp1_10_1, linflp_k24_dy17);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu17, linflp_k24_dy17, linflp_k24_dnu17);
linflp_k24_vadd_10(linflp_k24_dnu17, linflp_k24_rk17, linflp_k24_dnu17);
linflp_k24_vv_elediv_10(linflp_k24_dnu17, linflp_k24_y17, linflp_k24_dnu17);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu17, linflp_k24_dnu17);
/* Zeitschritt 18 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs18, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc18[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx18, linflp_k24_dx18, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu18, linflp_k24_du18, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk18[0], &linflp_k24_y18[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny18, linflp_k24_tmp1_10_1, linflp_k24_dy18);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu18, linflp_k24_dy18, linflp_k24_dnu18);
linflp_k24_vadd_10(linflp_k24_dnu18, linflp_k24_rk18, linflp_k24_dnu18);
linflp_k24_vv_elediv_10(linflp_k24_dnu18, linflp_k24_y18, linflp_k24_dnu18);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu18, linflp_k24_dnu18);
/* Zeitschritt 19 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs19, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc19[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx19, linflp_k24_dx19, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu19, linflp_k24_du19, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk19[0], &linflp_k24_y19[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny19, linflp_k24_tmp1_10_1, linflp_k24_dy19);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu19, linflp_k24_dy19, linflp_k24_dnu19);
linflp_k24_vadd_10(linflp_k24_dnu19, linflp_k24_rk19, linflp_k24_dnu19);
linflp_k24_vv_elediv_10(linflp_k24_dnu19, linflp_k24_y19, linflp_k24_dnu19);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu19, linflp_k24_dnu19);
/* Zeitschritt 20 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs20, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc20[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx20, linflp_k24_dx20, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu20, linflp_k24_du20, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk20[0], &linflp_k24_y20[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny20, linflp_k24_tmp1_10_1, linflp_k24_dy20);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu20, linflp_k24_dy20, linflp_k24_dnu20);
linflp_k24_vadd_10(linflp_k24_dnu20, linflp_k24_rk20, linflp_k24_dnu20);
linflp_k24_vv_elediv_10(linflp_k24_dnu20, linflp_k24_y20, linflp_k24_dnu20);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu20, linflp_k24_dnu20);
/* Zeitschritt 21 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs21, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc21[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx21, linflp_k24_dx21, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu21, linflp_k24_du21, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk21[0], &linflp_k24_y21[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny21, linflp_k24_tmp1_10_1, linflp_k24_dy21);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu21, linflp_k24_dy21, linflp_k24_dnu21);
linflp_k24_vadd_10(linflp_k24_dnu21, linflp_k24_rk21, linflp_k24_dnu21);
linflp_k24_vv_elediv_10(linflp_k24_dnu21, linflp_k24_y21, linflp_k24_dnu21);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu21, linflp_k24_dnu21);
/* Zeitschritt 22 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs22, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc22[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx22, linflp_k24_dx22, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu22, linflp_k24_du22, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk22[0], &linflp_k24_y22[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny22, linflp_k24_tmp1_10_1, linflp_k24_dy22);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu22, linflp_k24_dy22, linflp_k24_dnu22);
linflp_k24_vadd_10(linflp_k24_dnu22, linflp_k24_rk22, linflp_k24_dnu22);
linflp_k24_vv_elediv_10(linflp_k24_dnu22, linflp_k24_y22, linflp_k24_dnu22);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu22, linflp_k24_dnu22);
/* Zeitschritt 23 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs23, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc23[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid52_sid2_10_3(linflp_k24_gx23, linflp_k24_dx23, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid55_sid5_10_2(linflp_k24_gu23, linflp_k24_du23, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk23[0], &linflp_k24_y23[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny23, linflp_k24_tmp1_10_1, linflp_k24_dy23);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu23, linflp_k24_dy23, linflp_k24_dnu23);
linflp_k24_vadd_10(linflp_k24_dnu23, linflp_k24_rk23, linflp_k24_dnu23);
linflp_k24_vv_elediv_10(linflp_k24_dnu23, linflp_k24_y23, linflp_k24_dnu23);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu23, linflp_k24_dnu23);
/* Zeitschritt 24 */
/* dy */
/* Hilfsvektor */
linflp_k24_v_init0_10(linflp_k24_tmp1_10_1);
linflp_k24_m_copy_0_1(linflp_k24_rhsxs24, linflp_k24_tmp1_10_1);
linflp_k24_m_copy_10_1(&linflp_k24_rc24[0], &linflp_k24_tmp1_10_1[0]);
linflp_k24_mv_sid53_sid2_10_3(linflp_k24_gx24, linflp_k24_dx24, linflp_k24_tmp1_10_1);
linflp_k24_mv_sid56_sid5_10_2(linflp_k24_gu24, linflp_k24_du24, linflp_k24_tmp1_10_1);
/* dy_u */
linflp_k24_vv_elediv_10(&linflp_k24_rk24[0], &linflp_k24_y24[0], linflp_k24_tmp2_10_1);
if(linflp_k24_termcode > -1){return;}
linflp_k24_vsub_10(&linflp_k24_tmp1_10_1[0], linflp_k24_tmp2_10_1, &linflp_k24_tmp1_10_1[0]);
linflp_k24_vv_elemult_10(linflp_k24_yny24, linflp_k24_tmp1_10_1, linflp_k24_dy24);
/* dnu */
linflp_k24_vv_elemult_10(linflp_k24_nu24, linflp_k24_dy24, linflp_k24_dnu24);
linflp_k24_vadd_10(linflp_k24_dnu24, linflp_k24_rk24, linflp_k24_dnu24);
linflp_k24_vv_elediv_10(linflp_k24_dnu24, linflp_k24_y24, linflp_k24_dnu24);
if(linflp_k24_termcode > -1){return;}
linflp_k24_v_turnsign_10(linflp_k24_dnu24, linflp_k24_dnu24);
linflp_k24_error_source = 0;

}


/* ###################################################### */
/* Diese Funktion berechnet führt die Nachiteration durch */
/* ###################################################### */
static void linflp_k24_glqdocpip_iter_ref()
{
if(linflp_k24_iter_ref == 1){
linflp_k24_stat_num_iter_ref++;
linflp_k24_stat_iter_ref[linflp_k24_iter] = 1;
/* Lösung sichern */
linflp_k24_v_copy_3(linflp_k24_dx0, linflp_k24_dx_ir0);
linflp_k24_v_copy_2(linflp_k24_du0, linflp_k24_du_ir0);
linflp_k24_v_copy_3(linflp_k24_dp0, linflp_k24_dp_ir0);
linflp_k24_v_copy_10(linflp_k24_dy0, linflp_k24_dy_ir0);
linflp_k24_v_copy_10(linflp_k24_dnu0, linflp_k24_dnu_ir0);
linflp_k24_v_copy_3(linflp_k24_dx1, linflp_k24_dx_ir1);
linflp_k24_v_copy_2(linflp_k24_du1, linflp_k24_du_ir1);
linflp_k24_v_copy_3(linflp_k24_dp1, linflp_k24_dp_ir1);
linflp_k24_v_copy_10(linflp_k24_dy1, linflp_k24_dy_ir1);
linflp_k24_v_copy_10(linflp_k24_dnu1, linflp_k24_dnu_ir1);
linflp_k24_v_copy_3(linflp_k24_dx2, linflp_k24_dx_ir2);
linflp_k24_v_copy_2(linflp_k24_du2, linflp_k24_du_ir2);
linflp_k24_v_copy_3(linflp_k24_dp2, linflp_k24_dp_ir2);
linflp_k24_v_copy_10(linflp_k24_dy2, linflp_k24_dy_ir2);
linflp_k24_v_copy_10(linflp_k24_dnu2, linflp_k24_dnu_ir2);
linflp_k24_v_copy_3(linflp_k24_dx3, linflp_k24_dx_ir3);
linflp_k24_v_copy_2(linflp_k24_du3, linflp_k24_du_ir3);
linflp_k24_v_copy_3(linflp_k24_dp3, linflp_k24_dp_ir3);
linflp_k24_v_copy_10(linflp_k24_dy3, linflp_k24_dy_ir3);
linflp_k24_v_copy_10(linflp_k24_dnu3, linflp_k24_dnu_ir3);
linflp_k24_v_copy_3(linflp_k24_dx4, linflp_k24_dx_ir4);
linflp_k24_v_copy_2(linflp_k24_du4, linflp_k24_du_ir4);
linflp_k24_v_copy_3(linflp_k24_dp4, linflp_k24_dp_ir4);
linflp_k24_v_copy_10(linflp_k24_dy4, linflp_k24_dy_ir4);
linflp_k24_v_copy_10(linflp_k24_dnu4, linflp_k24_dnu_ir4);
linflp_k24_v_copy_3(linflp_k24_dx5, linflp_k24_dx_ir5);
linflp_k24_v_copy_2(linflp_k24_du5, linflp_k24_du_ir5);
linflp_k24_v_copy_3(linflp_k24_dp5, linflp_k24_dp_ir5);
linflp_k24_v_copy_10(linflp_k24_dy5, linflp_k24_dy_ir5);
linflp_k24_v_copy_10(linflp_k24_dnu5, linflp_k24_dnu_ir5);
linflp_k24_v_copy_3(linflp_k24_dx6, linflp_k24_dx_ir6);
linflp_k24_v_copy_2(linflp_k24_du6, linflp_k24_du_ir6);
linflp_k24_v_copy_3(linflp_k24_dp6, linflp_k24_dp_ir6);
linflp_k24_v_copy_10(linflp_k24_dy6, linflp_k24_dy_ir6);
linflp_k24_v_copy_10(linflp_k24_dnu6, linflp_k24_dnu_ir6);
linflp_k24_v_copy_3(linflp_k24_dx7, linflp_k24_dx_ir7);
linflp_k24_v_copy_2(linflp_k24_du7, linflp_k24_du_ir7);
linflp_k24_v_copy_3(linflp_k24_dp7, linflp_k24_dp_ir7);
linflp_k24_v_copy_10(linflp_k24_dy7, linflp_k24_dy_ir7);
linflp_k24_v_copy_10(linflp_k24_dnu7, linflp_k24_dnu_ir7);
linflp_k24_v_copy_3(linflp_k24_dx8, linflp_k24_dx_ir8);
linflp_k24_v_copy_2(linflp_k24_du8, linflp_k24_du_ir8);
linflp_k24_v_copy_3(linflp_k24_dp8, linflp_k24_dp_ir8);
linflp_k24_v_copy_10(linflp_k24_dy8, linflp_k24_dy_ir8);
linflp_k24_v_copy_10(linflp_k24_dnu8, linflp_k24_dnu_ir8);
linflp_k24_v_copy_3(linflp_k24_dx9, linflp_k24_dx_ir9);
linflp_k24_v_copy_2(linflp_k24_du9, linflp_k24_du_ir9);
linflp_k24_v_copy_3(linflp_k24_dp9, linflp_k24_dp_ir9);
linflp_k24_v_copy_10(linflp_k24_dy9, linflp_k24_dy_ir9);
linflp_k24_v_copy_10(linflp_k24_dnu9, linflp_k24_dnu_ir9);
linflp_k24_v_copy_3(linflp_k24_dx10, linflp_k24_dx_ir10);
linflp_k24_v_copy_2(linflp_k24_du10, linflp_k24_du_ir10);
linflp_k24_v_copy_3(linflp_k24_dp10, linflp_k24_dp_ir10);
linflp_k24_v_copy_10(linflp_k24_dy10, linflp_k24_dy_ir10);
linflp_k24_v_copy_10(linflp_k24_dnu10, linflp_k24_dnu_ir10);
linflp_k24_v_copy_3(linflp_k24_dx11, linflp_k24_dx_ir11);
linflp_k24_v_copy_2(linflp_k24_du11, linflp_k24_du_ir11);
linflp_k24_v_copy_3(linflp_k24_dp11, linflp_k24_dp_ir11);
linflp_k24_v_copy_10(linflp_k24_dy11, linflp_k24_dy_ir11);
linflp_k24_v_copy_10(linflp_k24_dnu11, linflp_k24_dnu_ir11);
linflp_k24_v_copy_3(linflp_k24_dx12, linflp_k24_dx_ir12);
linflp_k24_v_copy_2(linflp_k24_du12, linflp_k24_du_ir12);
linflp_k24_v_copy_3(linflp_k24_dp12, linflp_k24_dp_ir12);
linflp_k24_v_copy_10(linflp_k24_dy12, linflp_k24_dy_ir12);
linflp_k24_v_copy_10(linflp_k24_dnu12, linflp_k24_dnu_ir12);
linflp_k24_v_copy_3(linflp_k24_dx13, linflp_k24_dx_ir13);
linflp_k24_v_copy_2(linflp_k24_du13, linflp_k24_du_ir13);
linflp_k24_v_copy_3(linflp_k24_dp13, linflp_k24_dp_ir13);
linflp_k24_v_copy_10(linflp_k24_dy13, linflp_k24_dy_ir13);
linflp_k24_v_copy_10(linflp_k24_dnu13, linflp_k24_dnu_ir13);
linflp_k24_v_copy_3(linflp_k24_dx14, linflp_k24_dx_ir14);
linflp_k24_v_copy_2(linflp_k24_du14, linflp_k24_du_ir14);
linflp_k24_v_copy_3(linflp_k24_dp14, linflp_k24_dp_ir14);
linflp_k24_v_copy_10(linflp_k24_dy14, linflp_k24_dy_ir14);
linflp_k24_v_copy_10(linflp_k24_dnu14, linflp_k24_dnu_ir14);
linflp_k24_v_copy_3(linflp_k24_dx15, linflp_k24_dx_ir15);
linflp_k24_v_copy_2(linflp_k24_du15, linflp_k24_du_ir15);
linflp_k24_v_copy_3(linflp_k24_dp15, linflp_k24_dp_ir15);
linflp_k24_v_copy_10(linflp_k24_dy15, linflp_k24_dy_ir15);
linflp_k24_v_copy_10(linflp_k24_dnu15, linflp_k24_dnu_ir15);
linflp_k24_v_copy_3(linflp_k24_dx16, linflp_k24_dx_ir16);
linflp_k24_v_copy_2(linflp_k24_du16, linflp_k24_du_ir16);
linflp_k24_v_copy_3(linflp_k24_dp16, linflp_k24_dp_ir16);
linflp_k24_v_copy_10(linflp_k24_dy16, linflp_k24_dy_ir16);
linflp_k24_v_copy_10(linflp_k24_dnu16, linflp_k24_dnu_ir16);
linflp_k24_v_copy_3(linflp_k24_dx17, linflp_k24_dx_ir17);
linflp_k24_v_copy_2(linflp_k24_du17, linflp_k24_du_ir17);
linflp_k24_v_copy_3(linflp_k24_dp17, linflp_k24_dp_ir17);
linflp_k24_v_copy_10(linflp_k24_dy17, linflp_k24_dy_ir17);
linflp_k24_v_copy_10(linflp_k24_dnu17, linflp_k24_dnu_ir17);
linflp_k24_v_copy_3(linflp_k24_dx18, linflp_k24_dx_ir18);
linflp_k24_v_copy_2(linflp_k24_du18, linflp_k24_du_ir18);
linflp_k24_v_copy_3(linflp_k24_dp18, linflp_k24_dp_ir18);
linflp_k24_v_copy_10(linflp_k24_dy18, linflp_k24_dy_ir18);
linflp_k24_v_copy_10(linflp_k24_dnu18, linflp_k24_dnu_ir18);
linflp_k24_v_copy_3(linflp_k24_dx19, linflp_k24_dx_ir19);
linflp_k24_v_copy_2(linflp_k24_du19, linflp_k24_du_ir19);
linflp_k24_v_copy_3(linflp_k24_dp19, linflp_k24_dp_ir19);
linflp_k24_v_copy_10(linflp_k24_dy19, linflp_k24_dy_ir19);
linflp_k24_v_copy_10(linflp_k24_dnu19, linflp_k24_dnu_ir19);
linflp_k24_v_copy_3(linflp_k24_dx20, linflp_k24_dx_ir20);
linflp_k24_v_copy_2(linflp_k24_du20, linflp_k24_du_ir20);
linflp_k24_v_copy_3(linflp_k24_dp20, linflp_k24_dp_ir20);
linflp_k24_v_copy_10(linflp_k24_dy20, linflp_k24_dy_ir20);
linflp_k24_v_copy_10(linflp_k24_dnu20, linflp_k24_dnu_ir20);
linflp_k24_v_copy_3(linflp_k24_dx21, linflp_k24_dx_ir21);
linflp_k24_v_copy_2(linflp_k24_du21, linflp_k24_du_ir21);
linflp_k24_v_copy_3(linflp_k24_dp21, linflp_k24_dp_ir21);
linflp_k24_v_copy_10(linflp_k24_dy21, linflp_k24_dy_ir21);
linflp_k24_v_copy_10(linflp_k24_dnu21, linflp_k24_dnu_ir21);
linflp_k24_v_copy_3(linflp_k24_dx22, linflp_k24_dx_ir22);
linflp_k24_v_copy_2(linflp_k24_du22, linflp_k24_du_ir22);
linflp_k24_v_copy_3(linflp_k24_dp22, linflp_k24_dp_ir22);
linflp_k24_v_copy_10(linflp_k24_dy22, linflp_k24_dy_ir22);
linflp_k24_v_copy_10(linflp_k24_dnu22, linflp_k24_dnu_ir22);
linflp_k24_v_copy_3(linflp_k24_dx23, linflp_k24_dx_ir23);
linflp_k24_v_copy_2(linflp_k24_du23, linflp_k24_du_ir23);
linflp_k24_v_copy_3(linflp_k24_dp23, linflp_k24_dp_ir23);
linflp_k24_v_copy_10(linflp_k24_dy23, linflp_k24_dy_ir23);
linflp_k24_v_copy_10(linflp_k24_dnu23, linflp_k24_dnu_ir23);
linflp_k24_v_copy_3(linflp_k24_dx24, linflp_k24_dx_ir24);
linflp_k24_v_copy_2(linflp_k24_du24, linflp_k24_du_ir24);
linflp_k24_v_copy_3(linflp_k24_dp24, linflp_k24_dp_ir24);
linflp_k24_v_copy_10(linflp_k24_dy24, linflp_k24_dy_ir24);
linflp_k24_v_copy_10(linflp_k24_dnu24, linflp_k24_dnu_ir24);
/* rhs sichern */
linflp_k24_v_copy_3(linflp_k24_rf0x0, linflp_k24_rf0x_ir0);
linflp_k24_v_copy_2(linflp_k24_rf0u0, linflp_k24_rf0u_ir0);
linflp_k24_v_copy_3(linflp_k24_rf0, linflp_k24_rf_ir0);
linflp_k24_v_copy_10(linflp_k24_rc0, linflp_k24_rc_ir0);
linflp_k24_v_copy_0(linflp_k24_rs0, linflp_k24_rs_ir0);
linflp_k24_v_copy_10(linflp_k24_rk0, linflp_k24_rk_ir0);
linflp_k24_v_copy_3(linflp_k24_rf0x1, linflp_k24_rf0x_ir1);
linflp_k24_v_copy_2(linflp_k24_rf0u1, linflp_k24_rf0u_ir1);
linflp_k24_v_copy_3(linflp_k24_rf1, linflp_k24_rf_ir1);
linflp_k24_v_copy_10(linflp_k24_rc1, linflp_k24_rc_ir1);
linflp_k24_v_copy_0(linflp_k24_rs1, linflp_k24_rs_ir1);
linflp_k24_v_copy_10(linflp_k24_rk1, linflp_k24_rk_ir1);
linflp_k24_v_copy_3(linflp_k24_rf0x2, linflp_k24_rf0x_ir2);
linflp_k24_v_copy_2(linflp_k24_rf0u2, linflp_k24_rf0u_ir2);
linflp_k24_v_copy_3(linflp_k24_rf2, linflp_k24_rf_ir2);
linflp_k24_v_copy_10(linflp_k24_rc2, linflp_k24_rc_ir2);
linflp_k24_v_copy_0(linflp_k24_rs2, linflp_k24_rs_ir2);
linflp_k24_v_copy_10(linflp_k24_rk2, linflp_k24_rk_ir2);
linflp_k24_v_copy_3(linflp_k24_rf0x3, linflp_k24_rf0x_ir3);
linflp_k24_v_copy_2(linflp_k24_rf0u3, linflp_k24_rf0u_ir3);
linflp_k24_v_copy_3(linflp_k24_rf3, linflp_k24_rf_ir3);
linflp_k24_v_copy_10(linflp_k24_rc3, linflp_k24_rc_ir3);
linflp_k24_v_copy_0(linflp_k24_rs3, linflp_k24_rs_ir3);
linflp_k24_v_copy_10(linflp_k24_rk3, linflp_k24_rk_ir3);
linflp_k24_v_copy_3(linflp_k24_rf0x4, linflp_k24_rf0x_ir4);
linflp_k24_v_copy_2(linflp_k24_rf0u4, linflp_k24_rf0u_ir4);
linflp_k24_v_copy_3(linflp_k24_rf4, linflp_k24_rf_ir4);
linflp_k24_v_copy_10(linflp_k24_rc4, linflp_k24_rc_ir4);
linflp_k24_v_copy_0(linflp_k24_rs4, linflp_k24_rs_ir4);
linflp_k24_v_copy_10(linflp_k24_rk4, linflp_k24_rk_ir4);
linflp_k24_v_copy_3(linflp_k24_rf0x5, linflp_k24_rf0x_ir5);
linflp_k24_v_copy_2(linflp_k24_rf0u5, linflp_k24_rf0u_ir5);
linflp_k24_v_copy_3(linflp_k24_rf5, linflp_k24_rf_ir5);
linflp_k24_v_copy_10(linflp_k24_rc5, linflp_k24_rc_ir5);
linflp_k24_v_copy_0(linflp_k24_rs5, linflp_k24_rs_ir5);
linflp_k24_v_copy_10(linflp_k24_rk5, linflp_k24_rk_ir5);
linflp_k24_v_copy_3(linflp_k24_rf0x6, linflp_k24_rf0x_ir6);
linflp_k24_v_copy_2(linflp_k24_rf0u6, linflp_k24_rf0u_ir6);
linflp_k24_v_copy_3(linflp_k24_rf6, linflp_k24_rf_ir6);
linflp_k24_v_copy_10(linflp_k24_rc6, linflp_k24_rc_ir6);
linflp_k24_v_copy_0(linflp_k24_rs6, linflp_k24_rs_ir6);
linflp_k24_v_copy_10(linflp_k24_rk6, linflp_k24_rk_ir6);
linflp_k24_v_copy_3(linflp_k24_rf0x7, linflp_k24_rf0x_ir7);
linflp_k24_v_copy_2(linflp_k24_rf0u7, linflp_k24_rf0u_ir7);
linflp_k24_v_copy_3(linflp_k24_rf7, linflp_k24_rf_ir7);
linflp_k24_v_copy_10(linflp_k24_rc7, linflp_k24_rc_ir7);
linflp_k24_v_copy_0(linflp_k24_rs7, linflp_k24_rs_ir7);
linflp_k24_v_copy_10(linflp_k24_rk7, linflp_k24_rk_ir7);
linflp_k24_v_copy_3(linflp_k24_rf0x8, linflp_k24_rf0x_ir8);
linflp_k24_v_copy_2(linflp_k24_rf0u8, linflp_k24_rf0u_ir8);
linflp_k24_v_copy_3(linflp_k24_rf8, linflp_k24_rf_ir8);
linflp_k24_v_copy_10(linflp_k24_rc8, linflp_k24_rc_ir8);
linflp_k24_v_copy_0(linflp_k24_rs8, linflp_k24_rs_ir8);
linflp_k24_v_copy_10(linflp_k24_rk8, linflp_k24_rk_ir8);
linflp_k24_v_copy_3(linflp_k24_rf0x9, linflp_k24_rf0x_ir9);
linflp_k24_v_copy_2(linflp_k24_rf0u9, linflp_k24_rf0u_ir9);
linflp_k24_v_copy_3(linflp_k24_rf9, linflp_k24_rf_ir9);
linflp_k24_v_copy_10(linflp_k24_rc9, linflp_k24_rc_ir9);
linflp_k24_v_copy_0(linflp_k24_rs9, linflp_k24_rs_ir9);
linflp_k24_v_copy_10(linflp_k24_rk9, linflp_k24_rk_ir9);
linflp_k24_v_copy_3(linflp_k24_rf0x10, linflp_k24_rf0x_ir10);
linflp_k24_v_copy_2(linflp_k24_rf0u10, linflp_k24_rf0u_ir10);
linflp_k24_v_copy_3(linflp_k24_rf10, linflp_k24_rf_ir10);
linflp_k24_v_copy_10(linflp_k24_rc10, linflp_k24_rc_ir10);
linflp_k24_v_copy_0(linflp_k24_rs10, linflp_k24_rs_ir10);
linflp_k24_v_copy_10(linflp_k24_rk10, linflp_k24_rk_ir10);
linflp_k24_v_copy_3(linflp_k24_rf0x11, linflp_k24_rf0x_ir11);
linflp_k24_v_copy_2(linflp_k24_rf0u11, linflp_k24_rf0u_ir11);
linflp_k24_v_copy_3(linflp_k24_rf11, linflp_k24_rf_ir11);
linflp_k24_v_copy_10(linflp_k24_rc11, linflp_k24_rc_ir11);
linflp_k24_v_copy_0(linflp_k24_rs11, linflp_k24_rs_ir11);
linflp_k24_v_copy_10(linflp_k24_rk11, linflp_k24_rk_ir11);
linflp_k24_v_copy_3(linflp_k24_rf0x12, linflp_k24_rf0x_ir12);
linflp_k24_v_copy_2(linflp_k24_rf0u12, linflp_k24_rf0u_ir12);
linflp_k24_v_copy_3(linflp_k24_rf12, linflp_k24_rf_ir12);
linflp_k24_v_copy_10(linflp_k24_rc12, linflp_k24_rc_ir12);
linflp_k24_v_copy_0(linflp_k24_rs12, linflp_k24_rs_ir12);
linflp_k24_v_copy_10(linflp_k24_rk12, linflp_k24_rk_ir12);
linflp_k24_v_copy_3(linflp_k24_rf0x13, linflp_k24_rf0x_ir13);
linflp_k24_v_copy_2(linflp_k24_rf0u13, linflp_k24_rf0u_ir13);
linflp_k24_v_copy_3(linflp_k24_rf13, linflp_k24_rf_ir13);
linflp_k24_v_copy_10(linflp_k24_rc13, linflp_k24_rc_ir13);
linflp_k24_v_copy_0(linflp_k24_rs13, linflp_k24_rs_ir13);
linflp_k24_v_copy_10(linflp_k24_rk13, linflp_k24_rk_ir13);
linflp_k24_v_copy_3(linflp_k24_rf0x14, linflp_k24_rf0x_ir14);
linflp_k24_v_copy_2(linflp_k24_rf0u14, linflp_k24_rf0u_ir14);
linflp_k24_v_copy_3(linflp_k24_rf14, linflp_k24_rf_ir14);
linflp_k24_v_copy_10(linflp_k24_rc14, linflp_k24_rc_ir14);
linflp_k24_v_copy_0(linflp_k24_rs14, linflp_k24_rs_ir14);
linflp_k24_v_copy_10(linflp_k24_rk14, linflp_k24_rk_ir14);
linflp_k24_v_copy_3(linflp_k24_rf0x15, linflp_k24_rf0x_ir15);
linflp_k24_v_copy_2(linflp_k24_rf0u15, linflp_k24_rf0u_ir15);
linflp_k24_v_copy_3(linflp_k24_rf15, linflp_k24_rf_ir15);
linflp_k24_v_copy_10(linflp_k24_rc15, linflp_k24_rc_ir15);
linflp_k24_v_copy_0(linflp_k24_rs15, linflp_k24_rs_ir15);
linflp_k24_v_copy_10(linflp_k24_rk15, linflp_k24_rk_ir15);
linflp_k24_v_copy_3(linflp_k24_rf0x16, linflp_k24_rf0x_ir16);
linflp_k24_v_copy_2(linflp_k24_rf0u16, linflp_k24_rf0u_ir16);
linflp_k24_v_copy_3(linflp_k24_rf16, linflp_k24_rf_ir16);
linflp_k24_v_copy_10(linflp_k24_rc16, linflp_k24_rc_ir16);
linflp_k24_v_copy_0(linflp_k24_rs16, linflp_k24_rs_ir16);
linflp_k24_v_copy_10(linflp_k24_rk16, linflp_k24_rk_ir16);
linflp_k24_v_copy_3(linflp_k24_rf0x17, linflp_k24_rf0x_ir17);
linflp_k24_v_copy_2(linflp_k24_rf0u17, linflp_k24_rf0u_ir17);
linflp_k24_v_copy_3(linflp_k24_rf17, linflp_k24_rf_ir17);
linflp_k24_v_copy_10(linflp_k24_rc17, linflp_k24_rc_ir17);
linflp_k24_v_copy_0(linflp_k24_rs17, linflp_k24_rs_ir17);
linflp_k24_v_copy_10(linflp_k24_rk17, linflp_k24_rk_ir17);
linflp_k24_v_copy_3(linflp_k24_rf0x18, linflp_k24_rf0x_ir18);
linflp_k24_v_copy_2(linflp_k24_rf0u18, linflp_k24_rf0u_ir18);
linflp_k24_v_copy_3(linflp_k24_rf18, linflp_k24_rf_ir18);
linflp_k24_v_copy_10(linflp_k24_rc18, linflp_k24_rc_ir18);
linflp_k24_v_copy_0(linflp_k24_rs18, linflp_k24_rs_ir18);
linflp_k24_v_copy_10(linflp_k24_rk18, linflp_k24_rk_ir18);
linflp_k24_v_copy_3(linflp_k24_rf0x19, linflp_k24_rf0x_ir19);
linflp_k24_v_copy_2(linflp_k24_rf0u19, linflp_k24_rf0u_ir19);
linflp_k24_v_copy_3(linflp_k24_rf19, linflp_k24_rf_ir19);
linflp_k24_v_copy_10(linflp_k24_rc19, linflp_k24_rc_ir19);
linflp_k24_v_copy_0(linflp_k24_rs19, linflp_k24_rs_ir19);
linflp_k24_v_copy_10(linflp_k24_rk19, linflp_k24_rk_ir19);
linflp_k24_v_copy_3(linflp_k24_rf0x20, linflp_k24_rf0x_ir20);
linflp_k24_v_copy_2(linflp_k24_rf0u20, linflp_k24_rf0u_ir20);
linflp_k24_v_copy_3(linflp_k24_rf20, linflp_k24_rf_ir20);
linflp_k24_v_copy_10(linflp_k24_rc20, linflp_k24_rc_ir20);
linflp_k24_v_copy_0(linflp_k24_rs20, linflp_k24_rs_ir20);
linflp_k24_v_copy_10(linflp_k24_rk20, linflp_k24_rk_ir20);
linflp_k24_v_copy_3(linflp_k24_rf0x21, linflp_k24_rf0x_ir21);
linflp_k24_v_copy_2(linflp_k24_rf0u21, linflp_k24_rf0u_ir21);
linflp_k24_v_copy_3(linflp_k24_rf21, linflp_k24_rf_ir21);
linflp_k24_v_copy_10(linflp_k24_rc21, linflp_k24_rc_ir21);
linflp_k24_v_copy_0(linflp_k24_rs21, linflp_k24_rs_ir21);
linflp_k24_v_copy_10(linflp_k24_rk21, linflp_k24_rk_ir21);
linflp_k24_v_copy_3(linflp_k24_rf0x22, linflp_k24_rf0x_ir22);
linflp_k24_v_copy_2(linflp_k24_rf0u22, linflp_k24_rf0u_ir22);
linflp_k24_v_copy_3(linflp_k24_rf22, linflp_k24_rf_ir22);
linflp_k24_v_copy_10(linflp_k24_rc22, linflp_k24_rc_ir22);
linflp_k24_v_copy_0(linflp_k24_rs22, linflp_k24_rs_ir22);
linflp_k24_v_copy_10(linflp_k24_rk22, linflp_k24_rk_ir22);
linflp_k24_v_copy_3(linflp_k24_rf0x23, linflp_k24_rf0x_ir23);
linflp_k24_v_copy_2(linflp_k24_rf0u23, linflp_k24_rf0u_ir23);
linflp_k24_v_copy_3(linflp_k24_rf23, linflp_k24_rf_ir23);
linflp_k24_v_copy_10(linflp_k24_rc23, linflp_k24_rc_ir23);
linflp_k24_v_copy_0(linflp_k24_rs23, linflp_k24_rs_ir23);
linflp_k24_v_copy_10(linflp_k24_rk23, linflp_k24_rk_ir23);
linflp_k24_v_copy_3(linflp_k24_rf0x24, linflp_k24_rf0x_ir24);
linflp_k24_v_copy_2(linflp_k24_rf0u24, linflp_k24_rf0u_ir24);
linflp_k24_v_copy_3(linflp_k24_rf24, linflp_k24_rf_ir24);
linflp_k24_v_copy_10(linflp_k24_rc24, linflp_k24_rc_ir24);
linflp_k24_v_copy_0(linflp_k24_rs24, linflp_k24_rs_ir24);
linflp_k24_v_copy_10(linflp_k24_rk24, linflp_k24_rk_ir24);
/* Residuum berechnen */
linflp_k24_glqdocpip_rhs_iter_ref();
if(linflp_k24_termcode > -1){return;}
linflp_k24_glqdocpip_rhs_reduced();
if(linflp_k24_termcode > -1){return;}
/* GLS mit Residuum als rechte Seite lösen */
linflp_k24_glqdocpip_solve();
if(linflp_k24_termcode > -1){return;}
linflp_k24_glqdocpip_dereduce();
if(linflp_k24_termcode > -1){return;}
/* Lösung aktualisieren */
linflp_k24_vadd_3(linflp_k24_dx_ir0, linflp_k24_dx0, linflp_k24_dx0);
linflp_k24_vadd_2(linflp_k24_du_ir0, linflp_k24_du0, linflp_k24_du0);
linflp_k24_vadd_3(linflp_k24_dp_ir0, linflp_k24_dp0, linflp_k24_dp0);
linflp_k24_vadd_10(linflp_k24_dy_ir0, linflp_k24_dy0, linflp_k24_dy0);
linflp_k24_vadd_10(linflp_k24_dnu_ir0, linflp_k24_dnu0, linflp_k24_dnu0);
linflp_k24_vadd_3(linflp_k24_dx_ir1, linflp_k24_dx1, linflp_k24_dx1);
linflp_k24_vadd_2(linflp_k24_du_ir1, linflp_k24_du1, linflp_k24_du1);
linflp_k24_vadd_3(linflp_k24_dp_ir1, linflp_k24_dp1, linflp_k24_dp1);
linflp_k24_vadd_10(linflp_k24_dy_ir1, linflp_k24_dy1, linflp_k24_dy1);
linflp_k24_vadd_10(linflp_k24_dnu_ir1, linflp_k24_dnu1, linflp_k24_dnu1);
linflp_k24_vadd_3(linflp_k24_dx_ir2, linflp_k24_dx2, linflp_k24_dx2);
linflp_k24_vadd_2(linflp_k24_du_ir2, linflp_k24_du2, linflp_k24_du2);
linflp_k24_vadd_3(linflp_k24_dp_ir2, linflp_k24_dp2, linflp_k24_dp2);
linflp_k24_vadd_10(linflp_k24_dy_ir2, linflp_k24_dy2, linflp_k24_dy2);
linflp_k24_vadd_10(linflp_k24_dnu_ir2, linflp_k24_dnu2, linflp_k24_dnu2);
linflp_k24_vadd_3(linflp_k24_dx_ir3, linflp_k24_dx3, linflp_k24_dx3);
linflp_k24_vadd_2(linflp_k24_du_ir3, linflp_k24_du3, linflp_k24_du3);
linflp_k24_vadd_3(linflp_k24_dp_ir3, linflp_k24_dp3, linflp_k24_dp3);
linflp_k24_vadd_10(linflp_k24_dy_ir3, linflp_k24_dy3, linflp_k24_dy3);
linflp_k24_vadd_10(linflp_k24_dnu_ir3, linflp_k24_dnu3, linflp_k24_dnu3);
linflp_k24_vadd_3(linflp_k24_dx_ir4, linflp_k24_dx4, linflp_k24_dx4);
linflp_k24_vadd_2(linflp_k24_du_ir4, linflp_k24_du4, linflp_k24_du4);
linflp_k24_vadd_3(linflp_k24_dp_ir4, linflp_k24_dp4, linflp_k24_dp4);
linflp_k24_vadd_10(linflp_k24_dy_ir4, linflp_k24_dy4, linflp_k24_dy4);
linflp_k24_vadd_10(linflp_k24_dnu_ir4, linflp_k24_dnu4, linflp_k24_dnu4);
linflp_k24_vadd_3(linflp_k24_dx_ir5, linflp_k24_dx5, linflp_k24_dx5);
linflp_k24_vadd_2(linflp_k24_du_ir5, linflp_k24_du5, linflp_k24_du5);
linflp_k24_vadd_3(linflp_k24_dp_ir5, linflp_k24_dp5, linflp_k24_dp5);
linflp_k24_vadd_10(linflp_k24_dy_ir5, linflp_k24_dy5, linflp_k24_dy5);
linflp_k24_vadd_10(linflp_k24_dnu_ir5, linflp_k24_dnu5, linflp_k24_dnu5);
linflp_k24_vadd_3(linflp_k24_dx_ir6, linflp_k24_dx6, linflp_k24_dx6);
linflp_k24_vadd_2(linflp_k24_du_ir6, linflp_k24_du6, linflp_k24_du6);
linflp_k24_vadd_3(linflp_k24_dp_ir6, linflp_k24_dp6, linflp_k24_dp6);
linflp_k24_vadd_10(linflp_k24_dy_ir6, linflp_k24_dy6, linflp_k24_dy6);
linflp_k24_vadd_10(linflp_k24_dnu_ir6, linflp_k24_dnu6, linflp_k24_dnu6);
linflp_k24_vadd_3(linflp_k24_dx_ir7, linflp_k24_dx7, linflp_k24_dx7);
linflp_k24_vadd_2(linflp_k24_du_ir7, linflp_k24_du7, linflp_k24_du7);
linflp_k24_vadd_3(linflp_k24_dp_ir7, linflp_k24_dp7, linflp_k24_dp7);
linflp_k24_vadd_10(linflp_k24_dy_ir7, linflp_k24_dy7, linflp_k24_dy7);
linflp_k24_vadd_10(linflp_k24_dnu_ir7, linflp_k24_dnu7, linflp_k24_dnu7);
linflp_k24_vadd_3(linflp_k24_dx_ir8, linflp_k24_dx8, linflp_k24_dx8);
linflp_k24_vadd_2(linflp_k24_du_ir8, linflp_k24_du8, linflp_k24_du8);
linflp_k24_vadd_3(linflp_k24_dp_ir8, linflp_k24_dp8, linflp_k24_dp8);
linflp_k24_vadd_10(linflp_k24_dy_ir8, linflp_k24_dy8, linflp_k24_dy8);
linflp_k24_vadd_10(linflp_k24_dnu_ir8, linflp_k24_dnu8, linflp_k24_dnu8);
linflp_k24_vadd_3(linflp_k24_dx_ir9, linflp_k24_dx9, linflp_k24_dx9);
linflp_k24_vadd_2(linflp_k24_du_ir9, linflp_k24_du9, linflp_k24_du9);
linflp_k24_vadd_3(linflp_k24_dp_ir9, linflp_k24_dp9, linflp_k24_dp9);
linflp_k24_vadd_10(linflp_k24_dy_ir9, linflp_k24_dy9, linflp_k24_dy9);
linflp_k24_vadd_10(linflp_k24_dnu_ir9, linflp_k24_dnu9, linflp_k24_dnu9);
linflp_k24_vadd_3(linflp_k24_dx_ir10, linflp_k24_dx10, linflp_k24_dx10);
linflp_k24_vadd_2(linflp_k24_du_ir10, linflp_k24_du10, linflp_k24_du10);
linflp_k24_vadd_3(linflp_k24_dp_ir10, linflp_k24_dp10, linflp_k24_dp10);
linflp_k24_vadd_10(linflp_k24_dy_ir10, linflp_k24_dy10, linflp_k24_dy10);
linflp_k24_vadd_10(linflp_k24_dnu_ir10, linflp_k24_dnu10, linflp_k24_dnu10);
linflp_k24_vadd_3(linflp_k24_dx_ir11, linflp_k24_dx11, linflp_k24_dx11);
linflp_k24_vadd_2(linflp_k24_du_ir11, linflp_k24_du11, linflp_k24_du11);
linflp_k24_vadd_3(linflp_k24_dp_ir11, linflp_k24_dp11, linflp_k24_dp11);
linflp_k24_vadd_10(linflp_k24_dy_ir11, linflp_k24_dy11, linflp_k24_dy11);
linflp_k24_vadd_10(linflp_k24_dnu_ir11, linflp_k24_dnu11, linflp_k24_dnu11);
linflp_k24_vadd_3(linflp_k24_dx_ir12, linflp_k24_dx12, linflp_k24_dx12);
linflp_k24_vadd_2(linflp_k24_du_ir12, linflp_k24_du12, linflp_k24_du12);
linflp_k24_vadd_3(linflp_k24_dp_ir12, linflp_k24_dp12, linflp_k24_dp12);
linflp_k24_vadd_10(linflp_k24_dy_ir12, linflp_k24_dy12, linflp_k24_dy12);
linflp_k24_vadd_10(linflp_k24_dnu_ir12, linflp_k24_dnu12, linflp_k24_dnu12);
linflp_k24_vadd_3(linflp_k24_dx_ir13, linflp_k24_dx13, linflp_k24_dx13);
linflp_k24_vadd_2(linflp_k24_du_ir13, linflp_k24_du13, linflp_k24_du13);
linflp_k24_vadd_3(linflp_k24_dp_ir13, linflp_k24_dp13, linflp_k24_dp13);
linflp_k24_vadd_10(linflp_k24_dy_ir13, linflp_k24_dy13, linflp_k24_dy13);
linflp_k24_vadd_10(linflp_k24_dnu_ir13, linflp_k24_dnu13, linflp_k24_dnu13);
linflp_k24_vadd_3(linflp_k24_dx_ir14, linflp_k24_dx14, linflp_k24_dx14);
linflp_k24_vadd_2(linflp_k24_du_ir14, linflp_k24_du14, linflp_k24_du14);
linflp_k24_vadd_3(linflp_k24_dp_ir14, linflp_k24_dp14, linflp_k24_dp14);
linflp_k24_vadd_10(linflp_k24_dy_ir14, linflp_k24_dy14, linflp_k24_dy14);
linflp_k24_vadd_10(linflp_k24_dnu_ir14, linflp_k24_dnu14, linflp_k24_dnu14);
linflp_k24_vadd_3(linflp_k24_dx_ir15, linflp_k24_dx15, linflp_k24_dx15);
linflp_k24_vadd_2(linflp_k24_du_ir15, linflp_k24_du15, linflp_k24_du15);
linflp_k24_vadd_3(linflp_k24_dp_ir15, linflp_k24_dp15, linflp_k24_dp15);
linflp_k24_vadd_10(linflp_k24_dy_ir15, linflp_k24_dy15, linflp_k24_dy15);
linflp_k24_vadd_10(linflp_k24_dnu_ir15, linflp_k24_dnu15, linflp_k24_dnu15);
linflp_k24_vadd_3(linflp_k24_dx_ir16, linflp_k24_dx16, linflp_k24_dx16);
linflp_k24_vadd_2(linflp_k24_du_ir16, linflp_k24_du16, linflp_k24_du16);
linflp_k24_vadd_3(linflp_k24_dp_ir16, linflp_k24_dp16, linflp_k24_dp16);
linflp_k24_vadd_10(linflp_k24_dy_ir16, linflp_k24_dy16, linflp_k24_dy16);
linflp_k24_vadd_10(linflp_k24_dnu_ir16, linflp_k24_dnu16, linflp_k24_dnu16);
linflp_k24_vadd_3(linflp_k24_dx_ir17, linflp_k24_dx17, linflp_k24_dx17);
linflp_k24_vadd_2(linflp_k24_du_ir17, linflp_k24_du17, linflp_k24_du17);
linflp_k24_vadd_3(linflp_k24_dp_ir17, linflp_k24_dp17, linflp_k24_dp17);
linflp_k24_vadd_10(linflp_k24_dy_ir17, linflp_k24_dy17, linflp_k24_dy17);
linflp_k24_vadd_10(linflp_k24_dnu_ir17, linflp_k24_dnu17, linflp_k24_dnu17);
linflp_k24_vadd_3(linflp_k24_dx_ir18, linflp_k24_dx18, linflp_k24_dx18);
linflp_k24_vadd_2(linflp_k24_du_ir18, linflp_k24_du18, linflp_k24_du18);
linflp_k24_vadd_3(linflp_k24_dp_ir18, linflp_k24_dp18, linflp_k24_dp18);
linflp_k24_vadd_10(linflp_k24_dy_ir18, linflp_k24_dy18, linflp_k24_dy18);
linflp_k24_vadd_10(linflp_k24_dnu_ir18, linflp_k24_dnu18, linflp_k24_dnu18);
linflp_k24_vadd_3(linflp_k24_dx_ir19, linflp_k24_dx19, linflp_k24_dx19);
linflp_k24_vadd_2(linflp_k24_du_ir19, linflp_k24_du19, linflp_k24_du19);
linflp_k24_vadd_3(linflp_k24_dp_ir19, linflp_k24_dp19, linflp_k24_dp19);
linflp_k24_vadd_10(linflp_k24_dy_ir19, linflp_k24_dy19, linflp_k24_dy19);
linflp_k24_vadd_10(linflp_k24_dnu_ir19, linflp_k24_dnu19, linflp_k24_dnu19);
linflp_k24_vadd_3(linflp_k24_dx_ir20, linflp_k24_dx20, linflp_k24_dx20);
linflp_k24_vadd_2(linflp_k24_du_ir20, linflp_k24_du20, linflp_k24_du20);
linflp_k24_vadd_3(linflp_k24_dp_ir20, linflp_k24_dp20, linflp_k24_dp20);
linflp_k24_vadd_10(linflp_k24_dy_ir20, linflp_k24_dy20, linflp_k24_dy20);
linflp_k24_vadd_10(linflp_k24_dnu_ir20, linflp_k24_dnu20, linflp_k24_dnu20);
linflp_k24_vadd_3(linflp_k24_dx_ir21, linflp_k24_dx21, linflp_k24_dx21);
linflp_k24_vadd_2(linflp_k24_du_ir21, linflp_k24_du21, linflp_k24_du21);
linflp_k24_vadd_3(linflp_k24_dp_ir21, linflp_k24_dp21, linflp_k24_dp21);
linflp_k24_vadd_10(linflp_k24_dy_ir21, linflp_k24_dy21, linflp_k24_dy21);
linflp_k24_vadd_10(linflp_k24_dnu_ir21, linflp_k24_dnu21, linflp_k24_dnu21);
linflp_k24_vadd_3(linflp_k24_dx_ir22, linflp_k24_dx22, linflp_k24_dx22);
linflp_k24_vadd_2(linflp_k24_du_ir22, linflp_k24_du22, linflp_k24_du22);
linflp_k24_vadd_3(linflp_k24_dp_ir22, linflp_k24_dp22, linflp_k24_dp22);
linflp_k24_vadd_10(linflp_k24_dy_ir22, linflp_k24_dy22, linflp_k24_dy22);
linflp_k24_vadd_10(linflp_k24_dnu_ir22, linflp_k24_dnu22, linflp_k24_dnu22);
linflp_k24_vadd_3(linflp_k24_dx_ir23, linflp_k24_dx23, linflp_k24_dx23);
linflp_k24_vadd_2(linflp_k24_du_ir23, linflp_k24_du23, linflp_k24_du23);
linflp_k24_vadd_3(linflp_k24_dp_ir23, linflp_k24_dp23, linflp_k24_dp23);
linflp_k24_vadd_10(linflp_k24_dy_ir23, linflp_k24_dy23, linflp_k24_dy23);
linflp_k24_vadd_10(linflp_k24_dnu_ir23, linflp_k24_dnu23, linflp_k24_dnu23);
linflp_k24_vadd_3(linflp_k24_dx_ir24, linflp_k24_dx24, linflp_k24_dx24);
linflp_k24_vadd_2(linflp_k24_du_ir24, linflp_k24_du24, linflp_k24_du24);
linflp_k24_vadd_3(linflp_k24_dp_ir24, linflp_k24_dp24, linflp_k24_dp24);
linflp_k24_vadd_10(linflp_k24_dy_ir24, linflp_k24_dy24, linflp_k24_dy24);
linflp_k24_vadd_10(linflp_k24_dnu_ir24, linflp_k24_dnu24, linflp_k24_dnu24);
/* rhs wiederherstellen */
linflp_k24_v_copy_3(linflp_k24_rf0x_ir0, linflp_k24_rf0x0);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir0, linflp_k24_rf0u0);
linflp_k24_v_copy_3(linflp_k24_rf_ir0, linflp_k24_rf0);
linflp_k24_v_copy_10(linflp_k24_rc_ir0, linflp_k24_rc0);
linflp_k24_v_copy_0(linflp_k24_rs_ir0, linflp_k24_rs0);
linflp_k24_v_copy_10(linflp_k24_rk_ir0, linflp_k24_rk0);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir1, linflp_k24_rf0x1);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir1, linflp_k24_rf0u1);
linflp_k24_v_copy_3(linflp_k24_rf_ir1, linflp_k24_rf1);
linflp_k24_v_copy_10(linflp_k24_rc_ir1, linflp_k24_rc1);
linflp_k24_v_copy_0(linflp_k24_rs_ir1, linflp_k24_rs1);
linflp_k24_v_copy_10(linflp_k24_rk_ir1, linflp_k24_rk1);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir2, linflp_k24_rf0x2);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir2, linflp_k24_rf0u2);
linflp_k24_v_copy_3(linflp_k24_rf_ir2, linflp_k24_rf2);
linflp_k24_v_copy_10(linflp_k24_rc_ir2, linflp_k24_rc2);
linflp_k24_v_copy_0(linflp_k24_rs_ir2, linflp_k24_rs2);
linflp_k24_v_copy_10(linflp_k24_rk_ir2, linflp_k24_rk2);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir3, linflp_k24_rf0x3);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir3, linflp_k24_rf0u3);
linflp_k24_v_copy_3(linflp_k24_rf_ir3, linflp_k24_rf3);
linflp_k24_v_copy_10(linflp_k24_rc_ir3, linflp_k24_rc3);
linflp_k24_v_copy_0(linflp_k24_rs_ir3, linflp_k24_rs3);
linflp_k24_v_copy_10(linflp_k24_rk_ir3, linflp_k24_rk3);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir4, linflp_k24_rf0x4);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir4, linflp_k24_rf0u4);
linflp_k24_v_copy_3(linflp_k24_rf_ir4, linflp_k24_rf4);
linflp_k24_v_copy_10(linflp_k24_rc_ir4, linflp_k24_rc4);
linflp_k24_v_copy_0(linflp_k24_rs_ir4, linflp_k24_rs4);
linflp_k24_v_copy_10(linflp_k24_rk_ir4, linflp_k24_rk4);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir5, linflp_k24_rf0x5);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir5, linflp_k24_rf0u5);
linflp_k24_v_copy_3(linflp_k24_rf_ir5, linflp_k24_rf5);
linflp_k24_v_copy_10(linflp_k24_rc_ir5, linflp_k24_rc5);
linflp_k24_v_copy_0(linflp_k24_rs_ir5, linflp_k24_rs5);
linflp_k24_v_copy_10(linflp_k24_rk_ir5, linflp_k24_rk5);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir6, linflp_k24_rf0x6);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir6, linflp_k24_rf0u6);
linflp_k24_v_copy_3(linflp_k24_rf_ir6, linflp_k24_rf6);
linflp_k24_v_copy_10(linflp_k24_rc_ir6, linflp_k24_rc6);
linflp_k24_v_copy_0(linflp_k24_rs_ir6, linflp_k24_rs6);
linflp_k24_v_copy_10(linflp_k24_rk_ir6, linflp_k24_rk6);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir7, linflp_k24_rf0x7);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir7, linflp_k24_rf0u7);
linflp_k24_v_copy_3(linflp_k24_rf_ir7, linflp_k24_rf7);
linflp_k24_v_copy_10(linflp_k24_rc_ir7, linflp_k24_rc7);
linflp_k24_v_copy_0(linflp_k24_rs_ir7, linflp_k24_rs7);
linflp_k24_v_copy_10(linflp_k24_rk_ir7, linflp_k24_rk7);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir8, linflp_k24_rf0x8);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir8, linflp_k24_rf0u8);
linflp_k24_v_copy_3(linflp_k24_rf_ir8, linflp_k24_rf8);
linflp_k24_v_copy_10(linflp_k24_rc_ir8, linflp_k24_rc8);
linflp_k24_v_copy_0(linflp_k24_rs_ir8, linflp_k24_rs8);
linflp_k24_v_copy_10(linflp_k24_rk_ir8, linflp_k24_rk8);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir9, linflp_k24_rf0x9);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir9, linflp_k24_rf0u9);
linflp_k24_v_copy_3(linflp_k24_rf_ir9, linflp_k24_rf9);
linflp_k24_v_copy_10(linflp_k24_rc_ir9, linflp_k24_rc9);
linflp_k24_v_copy_0(linflp_k24_rs_ir9, linflp_k24_rs9);
linflp_k24_v_copy_10(linflp_k24_rk_ir9, linflp_k24_rk9);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir10, linflp_k24_rf0x10);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir10, linflp_k24_rf0u10);
linflp_k24_v_copy_3(linflp_k24_rf_ir10, linflp_k24_rf10);
linflp_k24_v_copy_10(linflp_k24_rc_ir10, linflp_k24_rc10);
linflp_k24_v_copy_0(linflp_k24_rs_ir10, linflp_k24_rs10);
linflp_k24_v_copy_10(linflp_k24_rk_ir10, linflp_k24_rk10);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir11, linflp_k24_rf0x11);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir11, linflp_k24_rf0u11);
linflp_k24_v_copy_3(linflp_k24_rf_ir11, linflp_k24_rf11);
linflp_k24_v_copy_10(linflp_k24_rc_ir11, linflp_k24_rc11);
linflp_k24_v_copy_0(linflp_k24_rs_ir11, linflp_k24_rs11);
linflp_k24_v_copy_10(linflp_k24_rk_ir11, linflp_k24_rk11);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir12, linflp_k24_rf0x12);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir12, linflp_k24_rf0u12);
linflp_k24_v_copy_3(linflp_k24_rf_ir12, linflp_k24_rf12);
linflp_k24_v_copy_10(linflp_k24_rc_ir12, linflp_k24_rc12);
linflp_k24_v_copy_0(linflp_k24_rs_ir12, linflp_k24_rs12);
linflp_k24_v_copy_10(linflp_k24_rk_ir12, linflp_k24_rk12);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir13, linflp_k24_rf0x13);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir13, linflp_k24_rf0u13);
linflp_k24_v_copy_3(linflp_k24_rf_ir13, linflp_k24_rf13);
linflp_k24_v_copy_10(linflp_k24_rc_ir13, linflp_k24_rc13);
linflp_k24_v_copy_0(linflp_k24_rs_ir13, linflp_k24_rs13);
linflp_k24_v_copy_10(linflp_k24_rk_ir13, linflp_k24_rk13);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir14, linflp_k24_rf0x14);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir14, linflp_k24_rf0u14);
linflp_k24_v_copy_3(linflp_k24_rf_ir14, linflp_k24_rf14);
linflp_k24_v_copy_10(linflp_k24_rc_ir14, linflp_k24_rc14);
linflp_k24_v_copy_0(linflp_k24_rs_ir14, linflp_k24_rs14);
linflp_k24_v_copy_10(linflp_k24_rk_ir14, linflp_k24_rk14);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir15, linflp_k24_rf0x15);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir15, linflp_k24_rf0u15);
linflp_k24_v_copy_3(linflp_k24_rf_ir15, linflp_k24_rf15);
linflp_k24_v_copy_10(linflp_k24_rc_ir15, linflp_k24_rc15);
linflp_k24_v_copy_0(linflp_k24_rs_ir15, linflp_k24_rs15);
linflp_k24_v_copy_10(linflp_k24_rk_ir15, linflp_k24_rk15);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir16, linflp_k24_rf0x16);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir16, linflp_k24_rf0u16);
linflp_k24_v_copy_3(linflp_k24_rf_ir16, linflp_k24_rf16);
linflp_k24_v_copy_10(linflp_k24_rc_ir16, linflp_k24_rc16);
linflp_k24_v_copy_0(linflp_k24_rs_ir16, linflp_k24_rs16);
linflp_k24_v_copy_10(linflp_k24_rk_ir16, linflp_k24_rk16);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir17, linflp_k24_rf0x17);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir17, linflp_k24_rf0u17);
linflp_k24_v_copy_3(linflp_k24_rf_ir17, linflp_k24_rf17);
linflp_k24_v_copy_10(linflp_k24_rc_ir17, linflp_k24_rc17);
linflp_k24_v_copy_0(linflp_k24_rs_ir17, linflp_k24_rs17);
linflp_k24_v_copy_10(linflp_k24_rk_ir17, linflp_k24_rk17);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir18, linflp_k24_rf0x18);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir18, linflp_k24_rf0u18);
linflp_k24_v_copy_3(linflp_k24_rf_ir18, linflp_k24_rf18);
linflp_k24_v_copy_10(linflp_k24_rc_ir18, linflp_k24_rc18);
linflp_k24_v_copy_0(linflp_k24_rs_ir18, linflp_k24_rs18);
linflp_k24_v_copy_10(linflp_k24_rk_ir18, linflp_k24_rk18);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir19, linflp_k24_rf0x19);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir19, linflp_k24_rf0u19);
linflp_k24_v_copy_3(linflp_k24_rf_ir19, linflp_k24_rf19);
linflp_k24_v_copy_10(linflp_k24_rc_ir19, linflp_k24_rc19);
linflp_k24_v_copy_0(linflp_k24_rs_ir19, linflp_k24_rs19);
linflp_k24_v_copy_10(linflp_k24_rk_ir19, linflp_k24_rk19);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir20, linflp_k24_rf0x20);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir20, linflp_k24_rf0u20);
linflp_k24_v_copy_3(linflp_k24_rf_ir20, linflp_k24_rf20);
linflp_k24_v_copy_10(linflp_k24_rc_ir20, linflp_k24_rc20);
linflp_k24_v_copy_0(linflp_k24_rs_ir20, linflp_k24_rs20);
linflp_k24_v_copy_10(linflp_k24_rk_ir20, linflp_k24_rk20);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir21, linflp_k24_rf0x21);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir21, linflp_k24_rf0u21);
linflp_k24_v_copy_3(linflp_k24_rf_ir21, linflp_k24_rf21);
linflp_k24_v_copy_10(linflp_k24_rc_ir21, linflp_k24_rc21);
linflp_k24_v_copy_0(linflp_k24_rs_ir21, linflp_k24_rs21);
linflp_k24_v_copy_10(linflp_k24_rk_ir21, linflp_k24_rk21);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir22, linflp_k24_rf0x22);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir22, linflp_k24_rf0u22);
linflp_k24_v_copy_3(linflp_k24_rf_ir22, linflp_k24_rf22);
linflp_k24_v_copy_10(linflp_k24_rc_ir22, linflp_k24_rc22);
linflp_k24_v_copy_0(linflp_k24_rs_ir22, linflp_k24_rs22);
linflp_k24_v_copy_10(linflp_k24_rk_ir22, linflp_k24_rk22);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir23, linflp_k24_rf0x23);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir23, linflp_k24_rf0u23);
linflp_k24_v_copy_3(linflp_k24_rf_ir23, linflp_k24_rf23);
linflp_k24_v_copy_10(linflp_k24_rc_ir23, linflp_k24_rc23);
linflp_k24_v_copy_0(linflp_k24_rs_ir23, linflp_k24_rs23);
linflp_k24_v_copy_10(linflp_k24_rk_ir23, linflp_k24_rk23);
linflp_k24_v_copy_3(linflp_k24_rf0x_ir24, linflp_k24_rf0x24);
linflp_k24_v_copy_2(linflp_k24_rf0u_ir24, linflp_k24_rf0u24);
linflp_k24_v_copy_3(linflp_k24_rf_ir24, linflp_k24_rf24);
linflp_k24_v_copy_10(linflp_k24_rc_ir24, linflp_k24_rc24);
linflp_k24_v_copy_0(linflp_k24_rs_ir24, linflp_k24_rs24);
linflp_k24_v_copy_10(linflp_k24_rk_ir24, linflp_k24_rk24);
}
}


/* ####################################### */
/* Diese Funktion berechnet den Startpunkt */
/*           Startpunktmethode: 0          */
/* ####################################### */
static void linflp_k24_glqdocpip_starting_point()
{
/* Very Cold Start */
/* Zeitschritt 0 */
linflp_k24_v_init0_3(linflp_k24_x0);
linflp_k24_v_init0_2(linflp_k24_u0);
linflp_k24_v_init0_3(linflp_k24_p0);
linflp_k24_v_init1_10(linflp_k24_y0);
linflp_k24_v_init1_10(linflp_k24_nu0);
/* Zeitschritt 1 */
linflp_k24_v_init0_3(linflp_k24_x1);
linflp_k24_v_init0_2(linflp_k24_u1);
linflp_k24_v_init0_3(linflp_k24_p1);
linflp_k24_v_init1_10(linflp_k24_y1);
linflp_k24_v_init1_10(linflp_k24_nu1);
/* Zeitschritt 2 */
linflp_k24_v_init0_3(linflp_k24_x2);
linflp_k24_v_init0_2(linflp_k24_u2);
linflp_k24_v_init0_3(linflp_k24_p2);
linflp_k24_v_init1_10(linflp_k24_y2);
linflp_k24_v_init1_10(linflp_k24_nu2);
/* Zeitschritt 3 */
linflp_k24_v_init0_3(linflp_k24_x3);
linflp_k24_v_init0_2(linflp_k24_u3);
linflp_k24_v_init0_3(linflp_k24_p3);
linflp_k24_v_init1_10(linflp_k24_y3);
linflp_k24_v_init1_10(linflp_k24_nu3);
/* Zeitschritt 4 */
linflp_k24_v_init0_3(linflp_k24_x4);
linflp_k24_v_init0_2(linflp_k24_u4);
linflp_k24_v_init0_3(linflp_k24_p4);
linflp_k24_v_init1_10(linflp_k24_y4);
linflp_k24_v_init1_10(linflp_k24_nu4);
/* Zeitschritt 5 */
linflp_k24_v_init0_3(linflp_k24_x5);
linflp_k24_v_init0_2(linflp_k24_u5);
linflp_k24_v_init0_3(linflp_k24_p5);
linflp_k24_v_init1_10(linflp_k24_y5);
linflp_k24_v_init1_10(linflp_k24_nu5);
/* Zeitschritt 6 */
linflp_k24_v_init0_3(linflp_k24_x6);
linflp_k24_v_init0_2(linflp_k24_u6);
linflp_k24_v_init0_3(linflp_k24_p6);
linflp_k24_v_init1_10(linflp_k24_y6);
linflp_k24_v_init1_10(linflp_k24_nu6);
/* Zeitschritt 7 */
linflp_k24_v_init0_3(linflp_k24_x7);
linflp_k24_v_init0_2(linflp_k24_u7);
linflp_k24_v_init0_3(linflp_k24_p7);
linflp_k24_v_init1_10(linflp_k24_y7);
linflp_k24_v_init1_10(linflp_k24_nu7);
/* Zeitschritt 8 */
linflp_k24_v_init0_3(linflp_k24_x8);
linflp_k24_v_init0_2(linflp_k24_u8);
linflp_k24_v_init0_3(linflp_k24_p8);
linflp_k24_v_init1_10(linflp_k24_y8);
linflp_k24_v_init1_10(linflp_k24_nu8);
/* Zeitschritt 9 */
linflp_k24_v_init0_3(linflp_k24_x9);
linflp_k24_v_init0_2(linflp_k24_u9);
linflp_k24_v_init0_3(linflp_k24_p9);
linflp_k24_v_init1_10(linflp_k24_y9);
linflp_k24_v_init1_10(linflp_k24_nu9);
/* Zeitschritt 10 */
linflp_k24_v_init0_3(linflp_k24_x10);
linflp_k24_v_init0_2(linflp_k24_u10);
linflp_k24_v_init0_3(linflp_k24_p10);
linflp_k24_v_init1_10(linflp_k24_y10);
linflp_k24_v_init1_10(linflp_k24_nu10);
/* Zeitschritt 11 */
linflp_k24_v_init0_3(linflp_k24_x11);
linflp_k24_v_init0_2(linflp_k24_u11);
linflp_k24_v_init0_3(linflp_k24_p11);
linflp_k24_v_init1_10(linflp_k24_y11);
linflp_k24_v_init1_10(linflp_k24_nu11);
/* Zeitschritt 12 */
linflp_k24_v_init0_3(linflp_k24_x12);
linflp_k24_v_init0_2(linflp_k24_u12);
linflp_k24_v_init0_3(linflp_k24_p12);
linflp_k24_v_init1_10(linflp_k24_y12);
linflp_k24_v_init1_10(linflp_k24_nu12);
/* Zeitschritt 13 */
linflp_k24_v_init0_3(linflp_k24_x13);
linflp_k24_v_init0_2(linflp_k24_u13);
linflp_k24_v_init0_3(linflp_k24_p13);
linflp_k24_v_init1_10(linflp_k24_y13);
linflp_k24_v_init1_10(linflp_k24_nu13);
/* Zeitschritt 14 */
linflp_k24_v_init0_3(linflp_k24_x14);
linflp_k24_v_init0_2(linflp_k24_u14);
linflp_k24_v_init0_3(linflp_k24_p14);
linflp_k24_v_init1_10(linflp_k24_y14);
linflp_k24_v_init1_10(linflp_k24_nu14);
/* Zeitschritt 15 */
linflp_k24_v_init0_3(linflp_k24_x15);
linflp_k24_v_init0_2(linflp_k24_u15);
linflp_k24_v_init0_3(linflp_k24_p15);
linflp_k24_v_init1_10(linflp_k24_y15);
linflp_k24_v_init1_10(linflp_k24_nu15);
/* Zeitschritt 16 */
linflp_k24_v_init0_3(linflp_k24_x16);
linflp_k24_v_init0_2(linflp_k24_u16);
linflp_k24_v_init0_3(linflp_k24_p16);
linflp_k24_v_init1_10(linflp_k24_y16);
linflp_k24_v_init1_10(linflp_k24_nu16);
/* Zeitschritt 17 */
linflp_k24_v_init0_3(linflp_k24_x17);
linflp_k24_v_init0_2(linflp_k24_u17);
linflp_k24_v_init0_3(linflp_k24_p17);
linflp_k24_v_init1_10(linflp_k24_y17);
linflp_k24_v_init1_10(linflp_k24_nu17);
/* Zeitschritt 18 */
linflp_k24_v_init0_3(linflp_k24_x18);
linflp_k24_v_init0_2(linflp_k24_u18);
linflp_k24_v_init0_3(linflp_k24_p18);
linflp_k24_v_init1_10(linflp_k24_y18);
linflp_k24_v_init1_10(linflp_k24_nu18);
/* Zeitschritt 19 */
linflp_k24_v_init0_3(linflp_k24_x19);
linflp_k24_v_init0_2(linflp_k24_u19);
linflp_k24_v_init0_3(linflp_k24_p19);
linflp_k24_v_init1_10(linflp_k24_y19);
linflp_k24_v_init1_10(linflp_k24_nu19);
/* Zeitschritt 20 */
linflp_k24_v_init0_3(linflp_k24_x20);
linflp_k24_v_init0_2(linflp_k24_u20);
linflp_k24_v_init0_3(linflp_k24_p20);
linflp_k24_v_init1_10(linflp_k24_y20);
linflp_k24_v_init1_10(linflp_k24_nu20);
/* Zeitschritt 21 */
linflp_k24_v_init0_3(linflp_k24_x21);
linflp_k24_v_init0_2(linflp_k24_u21);
linflp_k24_v_init0_3(linflp_k24_p21);
linflp_k24_v_init1_10(linflp_k24_y21);
linflp_k24_v_init1_10(linflp_k24_nu21);
/* Zeitschritt 22 */
linflp_k24_v_init0_3(linflp_k24_x22);
linflp_k24_v_init0_2(linflp_k24_u22);
linflp_k24_v_init0_3(linflp_k24_p22);
linflp_k24_v_init1_10(linflp_k24_y22);
linflp_k24_v_init1_10(linflp_k24_nu22);
/* Zeitschritt 23 */
linflp_k24_v_init0_3(linflp_k24_x23);
linflp_k24_v_init0_2(linflp_k24_u23);
linflp_k24_v_init0_3(linflp_k24_p23);
linflp_k24_v_init1_10(linflp_k24_y23);
linflp_k24_v_init1_10(linflp_k24_nu23);
/* Zeitschritt 24 */
linflp_k24_v_init0_3(linflp_k24_x24);
linflp_k24_v_init0_2(linflp_k24_u24);
linflp_k24_v_init0_3(linflp_k24_p24);
linflp_k24_v_init1_10(linflp_k24_y24);
linflp_k24_v_init1_10(linflp_k24_nu24);
}


void linflp_k24_glqdocpip_init()
{
/* ## Parameter INIT ##  */
/* Anzahl Ungleichungsbedingungen */
linflp_k24_m_ineq[0] = 250;
/* Toleranz (Abbruchkriterium) */
linflp_k24_tol[0] = 0.0001;
/* Mehrotra Gamma */
linflp_k24_mehrotra_gamma[0] = 0.01;
/* Machine Epsilon */
/* Init Berechnung */
linflp_k24_v_init0_1(linflp_k24_tmp3_1);
linflp_k24_tmp1_1[0] = 1;
linflp_k24_tmp2_1[0] = 1.0f - linflp_k24_tmp1_1[0]/2;
/* Berechnungsschleife: while((1-div/2)!=1){div = div/2} */
while(linflp_k24_tmp2_1[0] != 1.0f){
linflp_k24_tmp1_1[0] = linflp_k24_tmp1_1[0]/2;
linflp_k24_tmp2_1[0] = 1.0f - linflp_k24_tmp1_1[0]/2;
linflp_k24_tmp3_1[0] += 1;
if(linflp_k24_tmp3_1[0] > 100){
linflp_k24_termcode = 10;
return;
}
}
linflp_k24_macheps[0] = linflp_k24_tmp1_1[0];
/* tau */
linflp_k24_tau[0] = 3;
/* termcode */
linflp_k24_termcode = -1;
/* Error Line */
linflp_k24_error_line = 0;
/* Error Source */
linflp_k24_error_source = 0;
/* termcode 1 factor */
linflp_k24_tc1_factor[0] = 10000;
/* termcode 2 factor */
linflp_k24_tc2_factor[0] = 100000000;
/* tmax */
linflp_k24_time_max = 1;
/* max_iter */
linflp_k24_max_iter = 100;
/* num_iter_ref */
linflp_k24_stat_num_iter_ref = 0;
/* num_factor */
linflp_k24_stat_num_factor = 0;
/* num_solve */
linflp_k24_stat_num_solve = 0;
}


int linflp_k24_glqdocpip()
{

/* High Performance Timer (Windows) */
linflp_k24_glqdocpip_timer_start();

/* Init */
linflp_k24_glqdocpip_init();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Anfangsnorm bestimmen (norm_d) */
linflp_k24_glqdocpip_calc_norm_d();

/* starting point */
linflp_k24_glqdocpip_starting_point();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Main Iteration Loop */
for(linflp_k24_iter = 0; linflp_k24_iter < linflp_k24_max_iter; linflp_k24_iter++){

/* Predictor rhs berechnen */
linflp_k24_glqdocpip_rhs_affine();
linflp_k24_glqdocpip_rhs_reduced();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Konvergenz- und Divergenztests, inkl. Berechnung der dafür nötigen Parameter */
linflp_k24_glqdocpip_calc_norm_r();
linflp_k24_glqdocpip_calc_mu();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_calc_duality_gap();
linflp_k24_glqdocpip_calc_phi();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_stat();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_check_condiv();
/* Bei entsprechendem Termcode Funktion beenden */
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Predictor GLS faktorisieren */
linflp_k24_glqdocpip_factor();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Predictor GLS lösen */
linflp_k24_glqdocpip_solve();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_dereduce();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_iter_ref();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Korrekturfaktor für CorrectorGLS berechnen, */
/* inkl der dafür nötigen Parameter */
linflp_k24_glqdocpip_max_stepsize();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_calc_mu_aff();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_calc_sigma();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Corrector rhs berechnen */
linflp_k24_glqdocpip_rhs_corrector();
linflp_k24_glqdocpip_rhs_reduced();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Corrector GLS lösen */
linflp_k24_glqdocpip_solve();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_dereduce();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_iter_ref();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}

/* Schritt berechnen und durchführen */
linflp_k24_glqdocpip_max_stepsize();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_calc_mu_aff();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_mehrotra_step();
if(linflp_k24_termcode > -1){return linflp_k24_termcode;}
linflp_k24_glqdocpip_step();

/* Ende - Main Iteration Loop */
}


/* Termcode 3: Max Iterations exceeded */
linflp_k24_termcode = 3;
return linflp_k24_termcode;
}
