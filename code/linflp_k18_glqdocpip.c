/* linflp_k18_glqdocpip.c */
/* Generiert: 22-Oct-2016 19:09:48 */


/* ########### */
/* # INCLUDE # */
/* ########### */
#include "float.h"
#include "math.h"

/* include f�r Timer (plattformabh�ngig) */
#if defined(__WIN32__) || defined(WIN32)
/*   Windows */
  #include "windows.h"
#endif


/* ######################## */
/* # Variablendeklaration # */
/* ######################## */
/* Anfangsbedingung */
static double linflp_k18_xinit[3];

/* Variablen f�r Disketisierungsstelle 0 */
/* Optimierungsvariablen */
static double linflp_k18_x0[3];
static double linflp_k18_u0[2];
static double linflp_k18_s0[1];
static double linflp_k18_p0[3];
static double linflp_k18_y0[10];
static double linflp_k18_nu0[10];
/* Schrittvariablen */
static double linflp_k18_dx0[3];
static double linflp_k18_du0[2];
static double linflp_k18_ds0[1];
static double linflp_k18_dp0[3];
static double linflp_k18_dy0[10];
static double linflp_k18_dnu0[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx0[9];
static double linflp_k18_Hxu0[6];
static double linflp_k18_Huu0[4];
static double linflp_k18_Hss0[1];
static double linflp_k18_f0x0[3];
static double linflp_k18_f0u0[2];
static double linflp_k18_f0s0[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx0[9];
static double linflp_k18_fu0[6];
static double linflp_k18_f0[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx0[30];
static double linflp_k18_gu0[20];
static double linflp_k18_g0[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x0[3];
static double linflp_k18_rf0u0[2];
static double linflp_k18_rf0s0[1];
static double linflp_k18_rf0[3];
static double linflp_k18_rc0[10];
static double linflp_k18_rs0[1];
static double linflp_k18_rk0[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x0[3];
static double linflp_k18_rrf0u0[2];
static double linflp_k18_rhsxs0[1];
static double linflp_k18_yny0[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx0[9];
static double linflp_k18_Gxu0[6];
static double linflp_k18_Guu0[4];
static double linflp_k18_Rux0[6];
static double linflp_k18_Vxx0[9];
static double linflp_k18_Gx0[3];
static double linflp_k18_Gu0[2];
static double linflp_k18_Ru0[2];
static double linflp_k18_Vx0[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir0[3];
static double linflp_k18_du_ir0[2];
static double linflp_k18_ds_ir0[1];
static double linflp_k18_dp_ir0[3];
static double linflp_k18_dy_ir0[10];
static double linflp_k18_dnu_ir0[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir0[3];
static double linflp_k18_rf0u_ir0[2];
static double linflp_k18_rf0s_ir0[1];
static double linflp_k18_rf_ir0[3];
static double linflp_k18_rc_ir0[10];
static double linflp_k18_rs_ir0[1];
static double linflp_k18_rk_ir0[10];

/* Variablen f�r Disketisierungsstelle 1 */
/* Optimierungsvariablen */
static double linflp_k18_x1[3];
static double linflp_k18_u1[2];
static double linflp_k18_s1[1];
static double linflp_k18_p1[3];
static double linflp_k18_y1[10];
static double linflp_k18_nu1[10];
/* Schrittvariablen */
static double linflp_k18_dx1[3];
static double linflp_k18_du1[2];
static double linflp_k18_ds1[1];
static double linflp_k18_dp1[3];
static double linflp_k18_dy1[10];
static double linflp_k18_dnu1[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx1[9];
static double linflp_k18_Hxu1[6];
static double linflp_k18_Huu1[4];
static double linflp_k18_Hss1[1];
static double linflp_k18_f0x1[3];
static double linflp_k18_f0u1[2];
static double linflp_k18_f0s1[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx1[9];
static double linflp_k18_fu1[6];
static double linflp_k18_f1[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx1[30];
static double linflp_k18_gu1[20];
static double linflp_k18_g1[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x1[3];
static double linflp_k18_rf0u1[2];
static double linflp_k18_rf0s1[1];
static double linflp_k18_rf1[3];
static double linflp_k18_rc1[10];
static double linflp_k18_rs1[1];
static double linflp_k18_rk1[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x1[3];
static double linflp_k18_rrf0u1[2];
static double linflp_k18_rhsxs1[1];
static double linflp_k18_yny1[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx1[9];
static double linflp_k18_Gxu1[6];
static double linflp_k18_Guu1[4];
static double linflp_k18_Rux1[6];
static double linflp_k18_Vxx1[9];
static double linflp_k18_Gx1[3];
static double linflp_k18_Gu1[2];
static double linflp_k18_Ru1[2];
static double linflp_k18_Vx1[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir1[3];
static double linflp_k18_du_ir1[2];
static double linflp_k18_ds_ir1[1];
static double linflp_k18_dp_ir1[3];
static double linflp_k18_dy_ir1[10];
static double linflp_k18_dnu_ir1[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir1[3];
static double linflp_k18_rf0u_ir1[2];
static double linflp_k18_rf0s_ir1[1];
static double linflp_k18_rf_ir1[3];
static double linflp_k18_rc_ir1[10];
static double linflp_k18_rs_ir1[1];
static double linflp_k18_rk_ir1[10];

/* Variablen f�r Disketisierungsstelle 2 */
/* Optimierungsvariablen */
static double linflp_k18_x2[3];
static double linflp_k18_u2[2];
static double linflp_k18_s2[1];
static double linflp_k18_p2[3];
static double linflp_k18_y2[10];
static double linflp_k18_nu2[10];
/* Schrittvariablen */
static double linflp_k18_dx2[3];
static double linflp_k18_du2[2];
static double linflp_k18_ds2[1];
static double linflp_k18_dp2[3];
static double linflp_k18_dy2[10];
static double linflp_k18_dnu2[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx2[9];
static double linflp_k18_Hxu2[6];
static double linflp_k18_Huu2[4];
static double linflp_k18_Hss2[1];
static double linflp_k18_f0x2[3];
static double linflp_k18_f0u2[2];
static double linflp_k18_f0s2[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx2[9];
static double linflp_k18_fu2[6];
static double linflp_k18_f2[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx2[30];
static double linflp_k18_gu2[20];
static double linflp_k18_g2[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x2[3];
static double linflp_k18_rf0u2[2];
static double linflp_k18_rf0s2[1];
static double linflp_k18_rf2[3];
static double linflp_k18_rc2[10];
static double linflp_k18_rs2[1];
static double linflp_k18_rk2[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x2[3];
static double linflp_k18_rrf0u2[2];
static double linflp_k18_rhsxs2[1];
static double linflp_k18_yny2[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx2[9];
static double linflp_k18_Gxu2[6];
static double linflp_k18_Guu2[4];
static double linflp_k18_Rux2[6];
static double linflp_k18_Vxx2[9];
static double linflp_k18_Gx2[3];
static double linflp_k18_Gu2[2];
static double linflp_k18_Ru2[2];
static double linflp_k18_Vx2[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir2[3];
static double linflp_k18_du_ir2[2];
static double linflp_k18_ds_ir2[1];
static double linflp_k18_dp_ir2[3];
static double linflp_k18_dy_ir2[10];
static double linflp_k18_dnu_ir2[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir2[3];
static double linflp_k18_rf0u_ir2[2];
static double linflp_k18_rf0s_ir2[1];
static double linflp_k18_rf_ir2[3];
static double linflp_k18_rc_ir2[10];
static double linflp_k18_rs_ir2[1];
static double linflp_k18_rk_ir2[10];

/* Variablen f�r Disketisierungsstelle 3 */
/* Optimierungsvariablen */
static double linflp_k18_x3[3];
static double linflp_k18_u3[2];
static double linflp_k18_s3[1];
static double linflp_k18_p3[3];
static double linflp_k18_y3[10];
static double linflp_k18_nu3[10];
/* Schrittvariablen */
static double linflp_k18_dx3[3];
static double linflp_k18_du3[2];
static double linflp_k18_ds3[1];
static double linflp_k18_dp3[3];
static double linflp_k18_dy3[10];
static double linflp_k18_dnu3[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx3[9];
static double linflp_k18_Hxu3[6];
static double linflp_k18_Huu3[4];
static double linflp_k18_Hss3[1];
static double linflp_k18_f0x3[3];
static double linflp_k18_f0u3[2];
static double linflp_k18_f0s3[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx3[9];
static double linflp_k18_fu3[6];
static double linflp_k18_f3[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx3[30];
static double linflp_k18_gu3[20];
static double linflp_k18_g3[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x3[3];
static double linflp_k18_rf0u3[2];
static double linflp_k18_rf0s3[1];
static double linflp_k18_rf3[3];
static double linflp_k18_rc3[10];
static double linflp_k18_rs3[1];
static double linflp_k18_rk3[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x3[3];
static double linflp_k18_rrf0u3[2];
static double linflp_k18_rhsxs3[1];
static double linflp_k18_yny3[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx3[9];
static double linflp_k18_Gxu3[6];
static double linflp_k18_Guu3[4];
static double linflp_k18_Rux3[6];
static double linflp_k18_Vxx3[9];
static double linflp_k18_Gx3[3];
static double linflp_k18_Gu3[2];
static double linflp_k18_Ru3[2];
static double linflp_k18_Vx3[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir3[3];
static double linflp_k18_du_ir3[2];
static double linflp_k18_ds_ir3[1];
static double linflp_k18_dp_ir3[3];
static double linflp_k18_dy_ir3[10];
static double linflp_k18_dnu_ir3[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir3[3];
static double linflp_k18_rf0u_ir3[2];
static double linflp_k18_rf0s_ir3[1];
static double linflp_k18_rf_ir3[3];
static double linflp_k18_rc_ir3[10];
static double linflp_k18_rs_ir3[1];
static double linflp_k18_rk_ir3[10];

/* Variablen f�r Disketisierungsstelle 4 */
/* Optimierungsvariablen */
static double linflp_k18_x4[3];
static double linflp_k18_u4[2];
static double linflp_k18_s4[1];
static double linflp_k18_p4[3];
static double linflp_k18_y4[10];
static double linflp_k18_nu4[10];
/* Schrittvariablen */
static double linflp_k18_dx4[3];
static double linflp_k18_du4[2];
static double linflp_k18_ds4[1];
static double linflp_k18_dp4[3];
static double linflp_k18_dy4[10];
static double linflp_k18_dnu4[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx4[9];
static double linflp_k18_Hxu4[6];
static double linflp_k18_Huu4[4];
static double linflp_k18_Hss4[1];
static double linflp_k18_f0x4[3];
static double linflp_k18_f0u4[2];
static double linflp_k18_f0s4[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx4[9];
static double linflp_k18_fu4[6];
static double linflp_k18_f4[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx4[30];
static double linflp_k18_gu4[20];
static double linflp_k18_g4[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x4[3];
static double linflp_k18_rf0u4[2];
static double linflp_k18_rf0s4[1];
static double linflp_k18_rf4[3];
static double linflp_k18_rc4[10];
static double linflp_k18_rs4[1];
static double linflp_k18_rk4[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x4[3];
static double linflp_k18_rrf0u4[2];
static double linflp_k18_rhsxs4[1];
static double linflp_k18_yny4[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx4[9];
static double linflp_k18_Gxu4[6];
static double linflp_k18_Guu4[4];
static double linflp_k18_Rux4[6];
static double linflp_k18_Vxx4[9];
static double linflp_k18_Gx4[3];
static double linflp_k18_Gu4[2];
static double linflp_k18_Ru4[2];
static double linflp_k18_Vx4[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir4[3];
static double linflp_k18_du_ir4[2];
static double linflp_k18_ds_ir4[1];
static double linflp_k18_dp_ir4[3];
static double linflp_k18_dy_ir4[10];
static double linflp_k18_dnu_ir4[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir4[3];
static double linflp_k18_rf0u_ir4[2];
static double linflp_k18_rf0s_ir4[1];
static double linflp_k18_rf_ir4[3];
static double linflp_k18_rc_ir4[10];
static double linflp_k18_rs_ir4[1];
static double linflp_k18_rk_ir4[10];

/* Variablen f�r Disketisierungsstelle 5 */
/* Optimierungsvariablen */
static double linflp_k18_x5[3];
static double linflp_k18_u5[2];
static double linflp_k18_s5[1];
static double linflp_k18_p5[3];
static double linflp_k18_y5[10];
static double linflp_k18_nu5[10];
/* Schrittvariablen */
static double linflp_k18_dx5[3];
static double linflp_k18_du5[2];
static double linflp_k18_ds5[1];
static double linflp_k18_dp5[3];
static double linflp_k18_dy5[10];
static double linflp_k18_dnu5[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx5[9];
static double linflp_k18_Hxu5[6];
static double linflp_k18_Huu5[4];
static double linflp_k18_Hss5[1];
static double linflp_k18_f0x5[3];
static double linflp_k18_f0u5[2];
static double linflp_k18_f0s5[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx5[9];
static double linflp_k18_fu5[6];
static double linflp_k18_f5[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx5[30];
static double linflp_k18_gu5[20];
static double linflp_k18_g5[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x5[3];
static double linflp_k18_rf0u5[2];
static double linflp_k18_rf0s5[1];
static double linflp_k18_rf5[3];
static double linflp_k18_rc5[10];
static double linflp_k18_rs5[1];
static double linflp_k18_rk5[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x5[3];
static double linflp_k18_rrf0u5[2];
static double linflp_k18_rhsxs5[1];
static double linflp_k18_yny5[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx5[9];
static double linflp_k18_Gxu5[6];
static double linflp_k18_Guu5[4];
static double linflp_k18_Rux5[6];
static double linflp_k18_Vxx5[9];
static double linflp_k18_Gx5[3];
static double linflp_k18_Gu5[2];
static double linflp_k18_Ru5[2];
static double linflp_k18_Vx5[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir5[3];
static double linflp_k18_du_ir5[2];
static double linflp_k18_ds_ir5[1];
static double linflp_k18_dp_ir5[3];
static double linflp_k18_dy_ir5[10];
static double linflp_k18_dnu_ir5[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir5[3];
static double linflp_k18_rf0u_ir5[2];
static double linflp_k18_rf0s_ir5[1];
static double linflp_k18_rf_ir5[3];
static double linflp_k18_rc_ir5[10];
static double linflp_k18_rs_ir5[1];
static double linflp_k18_rk_ir5[10];

/* Variablen f�r Disketisierungsstelle 6 */
/* Optimierungsvariablen */
static double linflp_k18_x6[3];
static double linflp_k18_u6[2];
static double linflp_k18_s6[1];
static double linflp_k18_p6[3];
static double linflp_k18_y6[10];
static double linflp_k18_nu6[10];
/* Schrittvariablen */
static double linflp_k18_dx6[3];
static double linflp_k18_du6[2];
static double linflp_k18_ds6[1];
static double linflp_k18_dp6[3];
static double linflp_k18_dy6[10];
static double linflp_k18_dnu6[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx6[9];
static double linflp_k18_Hxu6[6];
static double linflp_k18_Huu6[4];
static double linflp_k18_Hss6[1];
static double linflp_k18_f0x6[3];
static double linflp_k18_f0u6[2];
static double linflp_k18_f0s6[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx6[9];
static double linflp_k18_fu6[6];
static double linflp_k18_f6[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx6[30];
static double linflp_k18_gu6[20];
static double linflp_k18_g6[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x6[3];
static double linflp_k18_rf0u6[2];
static double linflp_k18_rf0s6[1];
static double linflp_k18_rf6[3];
static double linflp_k18_rc6[10];
static double linflp_k18_rs6[1];
static double linflp_k18_rk6[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x6[3];
static double linflp_k18_rrf0u6[2];
static double linflp_k18_rhsxs6[1];
static double linflp_k18_yny6[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx6[9];
static double linflp_k18_Gxu6[6];
static double linflp_k18_Guu6[4];
static double linflp_k18_Rux6[6];
static double linflp_k18_Vxx6[9];
static double linflp_k18_Gx6[3];
static double linflp_k18_Gu6[2];
static double linflp_k18_Ru6[2];
static double linflp_k18_Vx6[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir6[3];
static double linflp_k18_du_ir6[2];
static double linflp_k18_ds_ir6[1];
static double linflp_k18_dp_ir6[3];
static double linflp_k18_dy_ir6[10];
static double linflp_k18_dnu_ir6[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir6[3];
static double linflp_k18_rf0u_ir6[2];
static double linflp_k18_rf0s_ir6[1];
static double linflp_k18_rf_ir6[3];
static double linflp_k18_rc_ir6[10];
static double linflp_k18_rs_ir6[1];
static double linflp_k18_rk_ir6[10];

/* Variablen f�r Disketisierungsstelle 7 */
/* Optimierungsvariablen */
static double linflp_k18_x7[3];
static double linflp_k18_u7[2];
static double linflp_k18_s7[1];
static double linflp_k18_p7[3];
static double linflp_k18_y7[10];
static double linflp_k18_nu7[10];
/* Schrittvariablen */
static double linflp_k18_dx7[3];
static double linflp_k18_du7[2];
static double linflp_k18_ds7[1];
static double linflp_k18_dp7[3];
static double linflp_k18_dy7[10];
static double linflp_k18_dnu7[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx7[9];
static double linflp_k18_Hxu7[6];
static double linflp_k18_Huu7[4];
static double linflp_k18_Hss7[1];
static double linflp_k18_f0x7[3];
static double linflp_k18_f0u7[2];
static double linflp_k18_f0s7[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx7[9];
static double linflp_k18_fu7[6];
static double linflp_k18_f7[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx7[30];
static double linflp_k18_gu7[20];
static double linflp_k18_g7[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x7[3];
static double linflp_k18_rf0u7[2];
static double linflp_k18_rf0s7[1];
static double linflp_k18_rf7[3];
static double linflp_k18_rc7[10];
static double linflp_k18_rs7[1];
static double linflp_k18_rk7[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x7[3];
static double linflp_k18_rrf0u7[2];
static double linflp_k18_rhsxs7[1];
static double linflp_k18_yny7[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx7[9];
static double linflp_k18_Gxu7[6];
static double linflp_k18_Guu7[4];
static double linflp_k18_Rux7[6];
static double linflp_k18_Vxx7[9];
static double linflp_k18_Gx7[3];
static double linflp_k18_Gu7[2];
static double linflp_k18_Ru7[2];
static double linflp_k18_Vx7[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir7[3];
static double linflp_k18_du_ir7[2];
static double linflp_k18_ds_ir7[1];
static double linflp_k18_dp_ir7[3];
static double linflp_k18_dy_ir7[10];
static double linflp_k18_dnu_ir7[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir7[3];
static double linflp_k18_rf0u_ir7[2];
static double linflp_k18_rf0s_ir7[1];
static double linflp_k18_rf_ir7[3];
static double linflp_k18_rc_ir7[10];
static double linflp_k18_rs_ir7[1];
static double linflp_k18_rk_ir7[10];

/* Variablen f�r Disketisierungsstelle 8 */
/* Optimierungsvariablen */
static double linflp_k18_x8[3];
static double linflp_k18_u8[2];
static double linflp_k18_s8[1];
static double linflp_k18_p8[3];
static double linflp_k18_y8[10];
static double linflp_k18_nu8[10];
/* Schrittvariablen */
static double linflp_k18_dx8[3];
static double linflp_k18_du8[2];
static double linflp_k18_ds8[1];
static double linflp_k18_dp8[3];
static double linflp_k18_dy8[10];
static double linflp_k18_dnu8[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx8[9];
static double linflp_k18_Hxu8[6];
static double linflp_k18_Huu8[4];
static double linflp_k18_Hss8[1];
static double linflp_k18_f0x8[3];
static double linflp_k18_f0u8[2];
static double linflp_k18_f0s8[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx8[9];
static double linflp_k18_fu8[6];
static double linflp_k18_f8[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx8[30];
static double linflp_k18_gu8[20];
static double linflp_k18_g8[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x8[3];
static double linflp_k18_rf0u8[2];
static double linflp_k18_rf0s8[1];
static double linflp_k18_rf8[3];
static double linflp_k18_rc8[10];
static double linflp_k18_rs8[1];
static double linflp_k18_rk8[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x8[3];
static double linflp_k18_rrf0u8[2];
static double linflp_k18_rhsxs8[1];
static double linflp_k18_yny8[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx8[9];
static double linflp_k18_Gxu8[6];
static double linflp_k18_Guu8[4];
static double linflp_k18_Rux8[6];
static double linflp_k18_Vxx8[9];
static double linflp_k18_Gx8[3];
static double linflp_k18_Gu8[2];
static double linflp_k18_Ru8[2];
static double linflp_k18_Vx8[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir8[3];
static double linflp_k18_du_ir8[2];
static double linflp_k18_ds_ir8[1];
static double linflp_k18_dp_ir8[3];
static double linflp_k18_dy_ir8[10];
static double linflp_k18_dnu_ir8[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir8[3];
static double linflp_k18_rf0u_ir8[2];
static double linflp_k18_rf0s_ir8[1];
static double linflp_k18_rf_ir8[3];
static double linflp_k18_rc_ir8[10];
static double linflp_k18_rs_ir8[1];
static double linflp_k18_rk_ir8[10];

/* Variablen f�r Disketisierungsstelle 9 */
/* Optimierungsvariablen */
static double linflp_k18_x9[3];
static double linflp_k18_u9[2];
static double linflp_k18_s9[1];
static double linflp_k18_p9[3];
static double linflp_k18_y9[10];
static double linflp_k18_nu9[10];
/* Schrittvariablen */
static double linflp_k18_dx9[3];
static double linflp_k18_du9[2];
static double linflp_k18_ds9[1];
static double linflp_k18_dp9[3];
static double linflp_k18_dy9[10];
static double linflp_k18_dnu9[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx9[9];
static double linflp_k18_Hxu9[6];
static double linflp_k18_Huu9[4];
static double linflp_k18_Hss9[1];
static double linflp_k18_f0x9[3];
static double linflp_k18_f0u9[2];
static double linflp_k18_f0s9[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx9[9];
static double linflp_k18_fu9[6];
static double linflp_k18_f9[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx9[30];
static double linflp_k18_gu9[20];
static double linflp_k18_g9[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x9[3];
static double linflp_k18_rf0u9[2];
static double linflp_k18_rf0s9[1];
static double linflp_k18_rf9[3];
static double linflp_k18_rc9[10];
static double linflp_k18_rs9[1];
static double linflp_k18_rk9[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x9[3];
static double linflp_k18_rrf0u9[2];
static double linflp_k18_rhsxs9[1];
static double linflp_k18_yny9[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx9[9];
static double linflp_k18_Gxu9[6];
static double linflp_k18_Guu9[4];
static double linflp_k18_Rux9[6];
static double linflp_k18_Vxx9[9];
static double linflp_k18_Gx9[3];
static double linflp_k18_Gu9[2];
static double linflp_k18_Ru9[2];
static double linflp_k18_Vx9[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir9[3];
static double linflp_k18_du_ir9[2];
static double linflp_k18_ds_ir9[1];
static double linflp_k18_dp_ir9[3];
static double linflp_k18_dy_ir9[10];
static double linflp_k18_dnu_ir9[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir9[3];
static double linflp_k18_rf0u_ir9[2];
static double linflp_k18_rf0s_ir9[1];
static double linflp_k18_rf_ir9[3];
static double linflp_k18_rc_ir9[10];
static double linflp_k18_rs_ir9[1];
static double linflp_k18_rk_ir9[10];

/* Variablen f�r Disketisierungsstelle 10 */
/* Optimierungsvariablen */
static double linflp_k18_x10[3];
static double linflp_k18_u10[2];
static double linflp_k18_s10[1];
static double linflp_k18_p10[3];
static double linflp_k18_y10[10];
static double linflp_k18_nu10[10];
/* Schrittvariablen */
static double linflp_k18_dx10[3];
static double linflp_k18_du10[2];
static double linflp_k18_ds10[1];
static double linflp_k18_dp10[3];
static double linflp_k18_dy10[10];
static double linflp_k18_dnu10[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx10[9];
static double linflp_k18_Hxu10[6];
static double linflp_k18_Huu10[4];
static double linflp_k18_Hss10[1];
static double linflp_k18_f0x10[3];
static double linflp_k18_f0u10[2];
static double linflp_k18_f0s10[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx10[9];
static double linflp_k18_fu10[6];
static double linflp_k18_f10[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx10[30];
static double linflp_k18_gu10[20];
static double linflp_k18_g10[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x10[3];
static double linflp_k18_rf0u10[2];
static double linflp_k18_rf0s10[1];
static double linflp_k18_rf10[3];
static double linflp_k18_rc10[10];
static double linflp_k18_rs10[1];
static double linflp_k18_rk10[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x10[3];
static double linflp_k18_rrf0u10[2];
static double linflp_k18_rhsxs10[1];
static double linflp_k18_yny10[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx10[9];
static double linflp_k18_Gxu10[6];
static double linflp_k18_Guu10[4];
static double linflp_k18_Rux10[6];
static double linflp_k18_Vxx10[9];
static double linflp_k18_Gx10[3];
static double linflp_k18_Gu10[2];
static double linflp_k18_Ru10[2];
static double linflp_k18_Vx10[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir10[3];
static double linflp_k18_du_ir10[2];
static double linflp_k18_ds_ir10[1];
static double linflp_k18_dp_ir10[3];
static double linflp_k18_dy_ir10[10];
static double linflp_k18_dnu_ir10[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir10[3];
static double linflp_k18_rf0u_ir10[2];
static double linflp_k18_rf0s_ir10[1];
static double linflp_k18_rf_ir10[3];
static double linflp_k18_rc_ir10[10];
static double linflp_k18_rs_ir10[1];
static double linflp_k18_rk_ir10[10];

/* Variablen f�r Disketisierungsstelle 11 */
/* Optimierungsvariablen */
static double linflp_k18_x11[3];
static double linflp_k18_u11[2];
static double linflp_k18_s11[1];
static double linflp_k18_p11[3];
static double linflp_k18_y11[10];
static double linflp_k18_nu11[10];
/* Schrittvariablen */
static double linflp_k18_dx11[3];
static double linflp_k18_du11[2];
static double linflp_k18_ds11[1];
static double linflp_k18_dp11[3];
static double linflp_k18_dy11[10];
static double linflp_k18_dnu11[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx11[9];
static double linflp_k18_Hxu11[6];
static double linflp_k18_Huu11[4];
static double linflp_k18_Hss11[1];
static double linflp_k18_f0x11[3];
static double linflp_k18_f0u11[2];
static double linflp_k18_f0s11[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx11[9];
static double linflp_k18_fu11[6];
static double linflp_k18_f11[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx11[30];
static double linflp_k18_gu11[20];
static double linflp_k18_g11[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x11[3];
static double linflp_k18_rf0u11[2];
static double linflp_k18_rf0s11[1];
static double linflp_k18_rf11[3];
static double linflp_k18_rc11[10];
static double linflp_k18_rs11[1];
static double linflp_k18_rk11[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x11[3];
static double linflp_k18_rrf0u11[2];
static double linflp_k18_rhsxs11[1];
static double linflp_k18_yny11[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx11[9];
static double linflp_k18_Gxu11[6];
static double linflp_k18_Guu11[4];
static double linflp_k18_Rux11[6];
static double linflp_k18_Vxx11[9];
static double linflp_k18_Gx11[3];
static double linflp_k18_Gu11[2];
static double linflp_k18_Ru11[2];
static double linflp_k18_Vx11[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir11[3];
static double linflp_k18_du_ir11[2];
static double linflp_k18_ds_ir11[1];
static double linflp_k18_dp_ir11[3];
static double linflp_k18_dy_ir11[10];
static double linflp_k18_dnu_ir11[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir11[3];
static double linflp_k18_rf0u_ir11[2];
static double linflp_k18_rf0s_ir11[1];
static double linflp_k18_rf_ir11[3];
static double linflp_k18_rc_ir11[10];
static double linflp_k18_rs_ir11[1];
static double linflp_k18_rk_ir11[10];

/* Variablen f�r Disketisierungsstelle 12 */
/* Optimierungsvariablen */
static double linflp_k18_x12[3];
static double linflp_k18_u12[2];
static double linflp_k18_s12[1];
static double linflp_k18_p12[3];
static double linflp_k18_y12[10];
static double linflp_k18_nu12[10];
/* Schrittvariablen */
static double linflp_k18_dx12[3];
static double linflp_k18_du12[2];
static double linflp_k18_ds12[1];
static double linflp_k18_dp12[3];
static double linflp_k18_dy12[10];
static double linflp_k18_dnu12[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx12[9];
static double linflp_k18_Hxu12[6];
static double linflp_k18_Huu12[4];
static double linflp_k18_Hss12[1];
static double linflp_k18_f0x12[3];
static double linflp_k18_f0u12[2];
static double linflp_k18_f0s12[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx12[9];
static double linflp_k18_fu12[6];
static double linflp_k18_f12[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx12[30];
static double linflp_k18_gu12[20];
static double linflp_k18_g12[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x12[3];
static double linflp_k18_rf0u12[2];
static double linflp_k18_rf0s12[1];
static double linflp_k18_rf12[3];
static double linflp_k18_rc12[10];
static double linflp_k18_rs12[1];
static double linflp_k18_rk12[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x12[3];
static double linflp_k18_rrf0u12[2];
static double linflp_k18_rhsxs12[1];
static double linflp_k18_yny12[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx12[9];
static double linflp_k18_Gxu12[6];
static double linflp_k18_Guu12[4];
static double linflp_k18_Rux12[6];
static double linflp_k18_Vxx12[9];
static double linflp_k18_Gx12[3];
static double linflp_k18_Gu12[2];
static double linflp_k18_Ru12[2];
static double linflp_k18_Vx12[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir12[3];
static double linflp_k18_du_ir12[2];
static double linflp_k18_ds_ir12[1];
static double linflp_k18_dp_ir12[3];
static double linflp_k18_dy_ir12[10];
static double linflp_k18_dnu_ir12[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir12[3];
static double linflp_k18_rf0u_ir12[2];
static double linflp_k18_rf0s_ir12[1];
static double linflp_k18_rf_ir12[3];
static double linflp_k18_rc_ir12[10];
static double linflp_k18_rs_ir12[1];
static double linflp_k18_rk_ir12[10];

/* Variablen f�r Disketisierungsstelle 13 */
/* Optimierungsvariablen */
static double linflp_k18_x13[3];
static double linflp_k18_u13[2];
static double linflp_k18_s13[1];
static double linflp_k18_p13[3];
static double linflp_k18_y13[10];
static double linflp_k18_nu13[10];
/* Schrittvariablen */
static double linflp_k18_dx13[3];
static double linflp_k18_du13[2];
static double linflp_k18_ds13[1];
static double linflp_k18_dp13[3];
static double linflp_k18_dy13[10];
static double linflp_k18_dnu13[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx13[9];
static double linflp_k18_Hxu13[6];
static double linflp_k18_Huu13[4];
static double linflp_k18_Hss13[1];
static double linflp_k18_f0x13[3];
static double linflp_k18_f0u13[2];
static double linflp_k18_f0s13[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx13[9];
static double linflp_k18_fu13[6];
static double linflp_k18_f13[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx13[30];
static double linflp_k18_gu13[20];
static double linflp_k18_g13[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x13[3];
static double linflp_k18_rf0u13[2];
static double linflp_k18_rf0s13[1];
static double linflp_k18_rf13[3];
static double linflp_k18_rc13[10];
static double linflp_k18_rs13[1];
static double linflp_k18_rk13[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x13[3];
static double linflp_k18_rrf0u13[2];
static double linflp_k18_rhsxs13[1];
static double linflp_k18_yny13[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx13[9];
static double linflp_k18_Gxu13[6];
static double linflp_k18_Guu13[4];
static double linflp_k18_Rux13[6];
static double linflp_k18_Vxx13[9];
static double linflp_k18_Gx13[3];
static double linflp_k18_Gu13[2];
static double linflp_k18_Ru13[2];
static double linflp_k18_Vx13[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir13[3];
static double linflp_k18_du_ir13[2];
static double linflp_k18_ds_ir13[1];
static double linflp_k18_dp_ir13[3];
static double linflp_k18_dy_ir13[10];
static double linflp_k18_dnu_ir13[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir13[3];
static double linflp_k18_rf0u_ir13[2];
static double linflp_k18_rf0s_ir13[1];
static double linflp_k18_rf_ir13[3];
static double linflp_k18_rc_ir13[10];
static double linflp_k18_rs_ir13[1];
static double linflp_k18_rk_ir13[10];

/* Variablen f�r Disketisierungsstelle 14 */
/* Optimierungsvariablen */
static double linflp_k18_x14[3];
static double linflp_k18_u14[2];
static double linflp_k18_s14[1];
static double linflp_k18_p14[3];
static double linflp_k18_y14[10];
static double linflp_k18_nu14[10];
/* Schrittvariablen */
static double linflp_k18_dx14[3];
static double linflp_k18_du14[2];
static double linflp_k18_ds14[1];
static double linflp_k18_dp14[3];
static double linflp_k18_dy14[10];
static double linflp_k18_dnu14[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx14[9];
static double linflp_k18_Hxu14[6];
static double linflp_k18_Huu14[4];
static double linflp_k18_Hss14[1];
static double linflp_k18_f0x14[3];
static double linflp_k18_f0u14[2];
static double linflp_k18_f0s14[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx14[9];
static double linflp_k18_fu14[6];
static double linflp_k18_f14[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx14[30];
static double linflp_k18_gu14[20];
static double linflp_k18_g14[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x14[3];
static double linflp_k18_rf0u14[2];
static double linflp_k18_rf0s14[1];
static double linflp_k18_rf14[3];
static double linflp_k18_rc14[10];
static double linflp_k18_rs14[1];
static double linflp_k18_rk14[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x14[3];
static double linflp_k18_rrf0u14[2];
static double linflp_k18_rhsxs14[1];
static double linflp_k18_yny14[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx14[9];
static double linflp_k18_Gxu14[6];
static double linflp_k18_Guu14[4];
static double linflp_k18_Rux14[6];
static double linflp_k18_Vxx14[9];
static double linflp_k18_Gx14[3];
static double linflp_k18_Gu14[2];
static double linflp_k18_Ru14[2];
static double linflp_k18_Vx14[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir14[3];
static double linflp_k18_du_ir14[2];
static double linflp_k18_ds_ir14[1];
static double linflp_k18_dp_ir14[3];
static double linflp_k18_dy_ir14[10];
static double linflp_k18_dnu_ir14[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir14[3];
static double linflp_k18_rf0u_ir14[2];
static double linflp_k18_rf0s_ir14[1];
static double linflp_k18_rf_ir14[3];
static double linflp_k18_rc_ir14[10];
static double linflp_k18_rs_ir14[1];
static double linflp_k18_rk_ir14[10];

/* Variablen f�r Disketisierungsstelle 15 */
/* Optimierungsvariablen */
static double linflp_k18_x15[3];
static double linflp_k18_u15[2];
static double linflp_k18_s15[1];
static double linflp_k18_p15[3];
static double linflp_k18_y15[10];
static double linflp_k18_nu15[10];
/* Schrittvariablen */
static double linflp_k18_dx15[3];
static double linflp_k18_du15[2];
static double linflp_k18_ds15[1];
static double linflp_k18_dp15[3];
static double linflp_k18_dy15[10];
static double linflp_k18_dnu15[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx15[9];
static double linflp_k18_Hxu15[6];
static double linflp_k18_Huu15[4];
static double linflp_k18_Hss15[1];
static double linflp_k18_f0x15[3];
static double linflp_k18_f0u15[2];
static double linflp_k18_f0s15[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx15[9];
static double linflp_k18_fu15[6];
static double linflp_k18_f15[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx15[30];
static double linflp_k18_gu15[20];
static double linflp_k18_g15[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x15[3];
static double linflp_k18_rf0u15[2];
static double linflp_k18_rf0s15[1];
static double linflp_k18_rf15[3];
static double linflp_k18_rc15[10];
static double linflp_k18_rs15[1];
static double linflp_k18_rk15[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x15[3];
static double linflp_k18_rrf0u15[2];
static double linflp_k18_rhsxs15[1];
static double linflp_k18_yny15[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx15[9];
static double linflp_k18_Gxu15[6];
static double linflp_k18_Guu15[4];
static double linflp_k18_Rux15[6];
static double linflp_k18_Vxx15[9];
static double linflp_k18_Gx15[3];
static double linflp_k18_Gu15[2];
static double linflp_k18_Ru15[2];
static double linflp_k18_Vx15[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir15[3];
static double linflp_k18_du_ir15[2];
static double linflp_k18_ds_ir15[1];
static double linflp_k18_dp_ir15[3];
static double linflp_k18_dy_ir15[10];
static double linflp_k18_dnu_ir15[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir15[3];
static double linflp_k18_rf0u_ir15[2];
static double linflp_k18_rf0s_ir15[1];
static double linflp_k18_rf_ir15[3];
static double linflp_k18_rc_ir15[10];
static double linflp_k18_rs_ir15[1];
static double linflp_k18_rk_ir15[10];

/* Variablen f�r Disketisierungsstelle 16 */
/* Optimierungsvariablen */
static double linflp_k18_x16[3];
static double linflp_k18_u16[2];
static double linflp_k18_s16[1];
static double linflp_k18_p16[3];
static double linflp_k18_y16[10];
static double linflp_k18_nu16[10];
/* Schrittvariablen */
static double linflp_k18_dx16[3];
static double linflp_k18_du16[2];
static double linflp_k18_ds16[1];
static double linflp_k18_dp16[3];
static double linflp_k18_dy16[10];
static double linflp_k18_dnu16[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx16[9];
static double linflp_k18_Hxu16[6];
static double linflp_k18_Huu16[4];
static double linflp_k18_Hss16[1];
static double linflp_k18_f0x16[3];
static double linflp_k18_f0u16[2];
static double linflp_k18_f0s16[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx16[9];
static double linflp_k18_fu16[6];
static double linflp_k18_f16[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx16[30];
static double linflp_k18_gu16[20];
static double linflp_k18_g16[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x16[3];
static double linflp_k18_rf0u16[2];
static double linflp_k18_rf0s16[1];
static double linflp_k18_rf16[3];
static double linflp_k18_rc16[10];
static double linflp_k18_rs16[1];
static double linflp_k18_rk16[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x16[3];
static double linflp_k18_rrf0u16[2];
static double linflp_k18_rhsxs16[1];
static double linflp_k18_yny16[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx16[9];
static double linflp_k18_Gxu16[6];
static double linflp_k18_Guu16[4];
static double linflp_k18_Rux16[6];
static double linflp_k18_Vxx16[9];
static double linflp_k18_Gx16[3];
static double linflp_k18_Gu16[2];
static double linflp_k18_Ru16[2];
static double linflp_k18_Vx16[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir16[3];
static double linflp_k18_du_ir16[2];
static double linflp_k18_ds_ir16[1];
static double linflp_k18_dp_ir16[3];
static double linflp_k18_dy_ir16[10];
static double linflp_k18_dnu_ir16[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir16[3];
static double linflp_k18_rf0u_ir16[2];
static double linflp_k18_rf0s_ir16[1];
static double linflp_k18_rf_ir16[3];
static double linflp_k18_rc_ir16[10];
static double linflp_k18_rs_ir16[1];
static double linflp_k18_rk_ir16[10];

/* Variablen f�r Disketisierungsstelle 17 */
/* Optimierungsvariablen */
static double linflp_k18_x17[3];
static double linflp_k18_u17[2];
static double linflp_k18_s17[1];
static double linflp_k18_p17[3];
static double linflp_k18_y17[10];
static double linflp_k18_nu17[10];
/* Schrittvariablen */
static double linflp_k18_dx17[3];
static double linflp_k18_du17[2];
static double linflp_k18_ds17[1];
static double linflp_k18_dp17[3];
static double linflp_k18_dy17[10];
static double linflp_k18_dnu17[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx17[9];
static double linflp_k18_Hxu17[6];
static double linflp_k18_Huu17[4];
static double linflp_k18_Hss17[1];
static double linflp_k18_f0x17[3];
static double linflp_k18_f0u17[2];
static double linflp_k18_f0s17[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx17[9];
static double linflp_k18_fu17[6];
static double linflp_k18_f17[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx17[30];
static double linflp_k18_gu17[20];
static double linflp_k18_g17[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x17[3];
static double linflp_k18_rf0u17[2];
static double linflp_k18_rf0s17[1];
static double linflp_k18_rf17[3];
static double linflp_k18_rc17[10];
static double linflp_k18_rs17[1];
static double linflp_k18_rk17[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x17[3];
static double linflp_k18_rrf0u17[2];
static double linflp_k18_rhsxs17[1];
static double linflp_k18_yny17[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx17[9];
static double linflp_k18_Gxu17[6];
static double linflp_k18_Guu17[4];
static double linflp_k18_Rux17[6];
static double linflp_k18_Vxx17[9];
static double linflp_k18_Gx17[3];
static double linflp_k18_Gu17[2];
static double linflp_k18_Ru17[2];
static double linflp_k18_Vx17[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir17[3];
static double linflp_k18_du_ir17[2];
static double linflp_k18_ds_ir17[1];
static double linflp_k18_dp_ir17[3];
static double linflp_k18_dy_ir17[10];
static double linflp_k18_dnu_ir17[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir17[3];
static double linflp_k18_rf0u_ir17[2];
static double linflp_k18_rf0s_ir17[1];
static double linflp_k18_rf_ir17[3];
static double linflp_k18_rc_ir17[10];
static double linflp_k18_rs_ir17[1];
static double linflp_k18_rk_ir17[10];

/* Variablen f�r Disketisierungsstelle 18 */
/* Optimierungsvariablen */
static double linflp_k18_x18[3];
static double linflp_k18_u18[2];
static double linflp_k18_s18[1];
static double linflp_k18_p18[3];
static double linflp_k18_y18[10];
static double linflp_k18_nu18[10];
/* Schrittvariablen */
static double linflp_k18_dx18[3];
static double linflp_k18_du18[2];
static double linflp_k18_ds18[1];
static double linflp_k18_dp18[3];
static double linflp_k18_dy18[10];
static double linflp_k18_dnu18[10];
/* Variablen der Guetefunktion */
static double linflp_k18_Hxx18[9];
static double linflp_k18_Hxu18[6];
static double linflp_k18_Huu18[4];
static double linflp_k18_Hss18[1];
static double linflp_k18_f0x18[3];
static double linflp_k18_f0u18[2];
static double linflp_k18_f0s18[1];
/* Variablen der Gleichungsnebenbedingungen */
static double linflp_k18_fx18[9];
static double linflp_k18_fu18[6];
static double linflp_k18_f18[3];
/* Variablen der Ungleichungsnebenbedingungen */
static double linflp_k18_gx18[30];
static double linflp_k18_gu18[20];
static double linflp_k18_g18[10];
/* Variablen der rechten Seiten */
static double linflp_k18_rf0x18[3];
static double linflp_k18_rf0u18[2];
static double linflp_k18_rf0s18[1];
static double linflp_k18_rf18[3];
static double linflp_k18_rc18[10];
static double linflp_k18_rs18[1];
static double linflp_k18_rk18[10];
/* Variablen der reduzierten rechten Seiten */
static double linflp_k18_rrf0x18[3];
static double linflp_k18_rrf0u18[2];
static double linflp_k18_rhsxs18[1];
static double linflp_k18_yny18[10];
/* Variablen fuer das Blockeliminationsverfahren */
static double linflp_k18_Gxx18[9];
static double linflp_k18_Gxu18[6];
static double linflp_k18_Guu18[4];
static double linflp_k18_Rux18[6];
static double linflp_k18_Vxx18[9];
static double linflp_k18_Gx18[3];
static double linflp_k18_Gu18[2];
static double linflp_k18_Ru18[2];
static double linflp_k18_Vx18[3];
/* Variablen fuer iter_ref: Schrittvariablenspeicher */
static double linflp_k18_dx_ir18[3];
static double linflp_k18_du_ir18[2];
static double linflp_k18_ds_ir18[1];
static double linflp_k18_dp_ir18[3];
static double linflp_k18_dy_ir18[10];
static double linflp_k18_dnu_ir18[10];
/* Variablen fuer iter_ref: rhs-Variablenspeicher */
static double linflp_k18_rf0x_ir18[3];
static double linflp_k18_rf0u_ir18[2];
static double linflp_k18_rf0s_ir18[1];
static double linflp_k18_rf_ir18[3];
static double linflp_k18_rc_ir18[10];
static double linflp_k18_rs_ir18[1];
static double linflp_k18_rk_ir18[10];

/* Tempor�re Variablen */
static double linflp_k18_tmp1_10_1[10];
static double linflp_k18_tmp2_10_1[10];
static double linflp_k18_tmp1_10[10];
static double linflp_k18_tmp2_10[10];
static double linflp_k18_tmp1_1[1];
static double linflp_k18_tmp2_1[1];
static double linflp_k18_tmp3_1[1];
static double linflp_k18_tmp1_3_3[9];
static double linflp_k18_tmp1_3_10[30];
static double linflp_k18_tmp1_2_3[6];
static double linflp_k18_tmp1_2_10[20];
static double linflp_k18_tmp1_3[3];
static double linflp_k18_tmp1_3_1[3];
static double linflp_k18_tmp1_2_1[2];
static double linflp_k18_tmp1_1_1[1];

/* Tempor�re Variablen f�r Cholesky Zerlegung */
static double linflp_k18_L0[4];
static double linflp_k18_L1[4];
static double linflp_k18_L2[4];
static double linflp_k18_L3[4];
static double linflp_k18_L4[4];
static double linflp_k18_L5[4];
static double linflp_k18_L6[4];
static double linflp_k18_L7[4];
static double linflp_k18_L8[4];
static double linflp_k18_L9[4];
static double linflp_k18_L10[4];
static double linflp_k18_L11[4];
static double linflp_k18_L12[4];
static double linflp_k18_L13[4];
static double linflp_k18_L14[4];
static double linflp_k18_L15[4];
static double linflp_k18_L16[4];
static double linflp_k18_L17[4];
static double linflp_k18_L18[4];

/* Variablen f�r max_stepsize */
static double linflp_k18_alpha_max[1];
static double linflp_k18_alpha_tmp[1];
static double linflp_k18_alpha_min_y[1];
static double linflp_k18_alpha_min_dy[1];
static double linflp_k18_alpha_min_nu[1];
static double linflp_k18_alpha_min_dnu[1];
static int linflp_k18_alpha_min_source_y;

/* Variablen f�r mehrotra_step */
static double linflp_k18_mehrotra_alpha[1];
static double linflp_k18_mehrotra_gamma[1];
static double linflp_k18_mehrotra_fpd[1];

/* Verschiedenes */
static int linflp_k18_iter;
static int linflp_k18_max_iter;
static int linflp_k18_termcode;
static int linflp_k18_iter_ref;
static int linflp_k18_error_line;
static int linflp_k18_error_source;
static double linflp_k18_m_ineq[1];
static double linflp_k18_macheps[1];
static double linflp_k18_tau[1];
static double linflp_k18_sigma[1];
static double linflp_k18_norm_d[1];
static double linflp_k18_norm_r[1];
static double linflp_k18_norm_r0[1];
static double linflp_k18_norm_r_prev[1];
static double linflp_k18_mu[1];
static double linflp_k18_mu0[1];
static double linflp_k18_mu_aff[1];
static double linflp_k18_phi[1];
static double linflp_k18_minphi[1];
static double linflp_k18_tol[1];
static double linflp_k18_tc1_factor[1];
static double linflp_k18_tc2_factor[1];
static double linflp_k18_timer_start;
static double linflp_k18_time_max;

/* Variablen f�r Duality Gap */
static double linflp_k18_dgap[1];

/* Variablen f�r Starting Point */

/* Variablen f�r Statistik */
static double linflp_k18_stat_time[100];
static int linflp_k18_stat_iter_ref[100];
static int linflp_k18_stat_num_iter_ref;
static int linflp_k18_stat_num_factor;
static int linflp_k18_stat_num_solve;



double *linflp_k18_get_x0()
{
return linflp_k18_xinit;
}

double *linflp_k18_get_x(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_x0;
    case 1: return linflp_k18_x1;
    case 2: return linflp_k18_x2;
    case 3: return linflp_k18_x3;
    case 4: return linflp_k18_x4;
    case 5: return linflp_k18_x5;
    case 6: return linflp_k18_x6;
    case 7: return linflp_k18_x7;
    case 8: return linflp_k18_x8;
    case 9: return linflp_k18_x9;
    case 10: return linflp_k18_x10;
    case 11: return linflp_k18_x11;
    case 12: return linflp_k18_x12;
    case 13: return linflp_k18_x13;
    case 14: return linflp_k18_x14;
    case 15: return linflp_k18_x15;
    case 16: return linflp_k18_x16;
    case 17: return linflp_k18_x17;
    case 18: return linflp_k18_x18;
    default: return 0;
  }
}

double *linflp_k18_get_u(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_u0;
    case 1: return linflp_k18_u1;
    case 2: return linflp_k18_u2;
    case 3: return linflp_k18_u3;
    case 4: return linflp_k18_u4;
    case 5: return linflp_k18_u5;
    case 6: return linflp_k18_u6;
    case 7: return linflp_k18_u7;
    case 8: return linflp_k18_u8;
    case 9: return linflp_k18_u9;
    case 10: return linflp_k18_u10;
    case 11: return linflp_k18_u11;
    case 12: return linflp_k18_u12;
    case 13: return linflp_k18_u13;
    case 14: return linflp_k18_u14;
    case 15: return linflp_k18_u15;
    case 16: return linflp_k18_u16;
    case 17: return linflp_k18_u17;
    case 18: return linflp_k18_u18;
    default: return 0;
  }
}

double *linflp_k18_get_s(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_s0;
    case 1: return linflp_k18_s1;
    case 2: return linflp_k18_s2;
    case 3: return linflp_k18_s3;
    case 4: return linflp_k18_s4;
    case 5: return linflp_k18_s5;
    case 6: return linflp_k18_s6;
    case 7: return linflp_k18_s7;
    case 8: return linflp_k18_s8;
    case 9: return linflp_k18_s9;
    case 10: return linflp_k18_s10;
    case 11: return linflp_k18_s11;
    case 12: return linflp_k18_s12;
    case 13: return linflp_k18_s13;
    case 14: return linflp_k18_s14;
    case 15: return linflp_k18_s15;
    case 16: return linflp_k18_s16;
    case 17: return linflp_k18_s17;
    case 18: return linflp_k18_s18;
    default: return 0;
  }
}

double *linflp_k18_get_p(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_p0;
    case 1: return linflp_k18_p1;
    case 2: return linflp_k18_p2;
    case 3: return linflp_k18_p3;
    case 4: return linflp_k18_p4;
    case 5: return linflp_k18_p5;
    case 6: return linflp_k18_p6;
    case 7: return linflp_k18_p7;
    case 8: return linflp_k18_p8;
    case 9: return linflp_k18_p9;
    case 10: return linflp_k18_p10;
    case 11: return linflp_k18_p11;
    case 12: return linflp_k18_p12;
    case 13: return linflp_k18_p13;
    case 14: return linflp_k18_p14;
    case 15: return linflp_k18_p15;
    case 16: return linflp_k18_p16;
    case 17: return linflp_k18_p17;
    case 18: return linflp_k18_p18;
    default: return 0;
  }
}

double *linflp_k18_get_y(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_y0;
    case 1: return linflp_k18_y1;
    case 2: return linflp_k18_y2;
    case 3: return linflp_k18_y3;
    case 4: return linflp_k18_y4;
    case 5: return linflp_k18_y5;
    case 6: return linflp_k18_y6;
    case 7: return linflp_k18_y7;
    case 8: return linflp_k18_y8;
    case 9: return linflp_k18_y9;
    case 10: return linflp_k18_y10;
    case 11: return linflp_k18_y11;
    case 12: return linflp_k18_y12;
    case 13: return linflp_k18_y13;
    case 14: return linflp_k18_y14;
    case 15: return linflp_k18_y15;
    case 16: return linflp_k18_y16;
    case 17: return linflp_k18_y17;
    case 18: return linflp_k18_y18;
    default: return 0;
  }
}

double *linflp_k18_get_nu(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_nu0;
    case 1: return linflp_k18_nu1;
    case 2: return linflp_k18_nu2;
    case 3: return linflp_k18_nu3;
    case 4: return linflp_k18_nu4;
    case 5: return linflp_k18_nu5;
    case 6: return linflp_k18_nu6;
    case 7: return linflp_k18_nu7;
    case 8: return linflp_k18_nu8;
    case 9: return linflp_k18_nu9;
    case 10: return linflp_k18_nu10;
    case 11: return linflp_k18_nu11;
    case 12: return linflp_k18_nu12;
    case 13: return linflp_k18_nu13;
    case 14: return linflp_k18_nu14;
    case 15: return linflp_k18_nu15;
    case 16: return linflp_k18_nu16;
    case 17: return linflp_k18_nu17;
    case 18: return linflp_k18_nu18;
    default: return 0;
  }
}

double *linflp_k18_get_Hxx(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_Hxx0;
    case 1: return linflp_k18_Hxx1;
    case 2: return linflp_k18_Hxx2;
    case 3: return linflp_k18_Hxx3;
    case 4: return linflp_k18_Hxx4;
    case 5: return linflp_k18_Hxx5;
    case 6: return linflp_k18_Hxx6;
    case 7: return linflp_k18_Hxx7;
    case 8: return linflp_k18_Hxx8;
    case 9: return linflp_k18_Hxx9;
    case 10: return linflp_k18_Hxx10;
    case 11: return linflp_k18_Hxx11;
    case 12: return linflp_k18_Hxx12;
    case 13: return linflp_k18_Hxx13;
    case 14: return linflp_k18_Hxx14;
    case 15: return linflp_k18_Hxx15;
    case 16: return linflp_k18_Hxx16;
    case 17: return linflp_k18_Hxx17;
    case 18: return linflp_k18_Hxx18;
    default: return 0;
  }
}

double *linflp_k18_get_Hxu(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_Hxu0;
    case 1: return linflp_k18_Hxu1;
    case 2: return linflp_k18_Hxu2;
    case 3: return linflp_k18_Hxu3;
    case 4: return linflp_k18_Hxu4;
    case 5: return linflp_k18_Hxu5;
    case 6: return linflp_k18_Hxu6;
    case 7: return linflp_k18_Hxu7;
    case 8: return linflp_k18_Hxu8;
    case 9: return linflp_k18_Hxu9;
    case 10: return linflp_k18_Hxu10;
    case 11: return linflp_k18_Hxu11;
    case 12: return linflp_k18_Hxu12;
    case 13: return linflp_k18_Hxu13;
    case 14: return linflp_k18_Hxu14;
    case 15: return linflp_k18_Hxu15;
    case 16: return linflp_k18_Hxu16;
    case 17: return linflp_k18_Hxu17;
    case 18: return linflp_k18_Hxu18;
    default: return 0;
  }
}

double *linflp_k18_get_Huu(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_Huu0;
    case 1: return linflp_k18_Huu1;
    case 2: return linflp_k18_Huu2;
    case 3: return linflp_k18_Huu3;
    case 4: return linflp_k18_Huu4;
    case 5: return linflp_k18_Huu5;
    case 6: return linflp_k18_Huu6;
    case 7: return linflp_k18_Huu7;
    case 8: return linflp_k18_Huu8;
    case 9: return linflp_k18_Huu9;
    case 10: return linflp_k18_Huu10;
    case 11: return linflp_k18_Huu11;
    case 12: return linflp_k18_Huu12;
    case 13: return linflp_k18_Huu13;
    case 14: return linflp_k18_Huu14;
    case 15: return linflp_k18_Huu15;
    case 16: return linflp_k18_Huu16;
    case 17: return linflp_k18_Huu17;
    case 18: return linflp_k18_Huu18;
    default: return 0;
  }
}

double *linflp_k18_get_Hss(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_Hss0;
    case 1: return linflp_k18_Hss1;
    case 2: return linflp_k18_Hss2;
    case 3: return linflp_k18_Hss3;
    case 4: return linflp_k18_Hss4;
    case 5: return linflp_k18_Hss5;
    case 6: return linflp_k18_Hss6;
    case 7: return linflp_k18_Hss7;
    case 8: return linflp_k18_Hss8;
    case 9: return linflp_k18_Hss9;
    case 10: return linflp_k18_Hss10;
    case 11: return linflp_k18_Hss11;
    case 12: return linflp_k18_Hss12;
    case 13: return linflp_k18_Hss13;
    case 14: return linflp_k18_Hss14;
    case 15: return linflp_k18_Hss15;
    case 16: return linflp_k18_Hss16;
    case 17: return linflp_k18_Hss17;
    case 18: return linflp_k18_Hss18;
    default: return 0;
  }
}

double *linflp_k18_get_f0x(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_f0x0;
    case 1: return linflp_k18_f0x1;
    case 2: return linflp_k18_f0x2;
    case 3: return linflp_k18_f0x3;
    case 4: return linflp_k18_f0x4;
    case 5: return linflp_k18_f0x5;
    case 6: return linflp_k18_f0x6;
    case 7: return linflp_k18_f0x7;
    case 8: return linflp_k18_f0x8;
    case 9: return linflp_k18_f0x9;
    case 10: return linflp_k18_f0x10;
    case 11: return linflp_k18_f0x11;
    case 12: return linflp_k18_f0x12;
    case 13: return linflp_k18_f0x13;
    case 14: return linflp_k18_f0x14;
    case 15: return linflp_k18_f0x15;
    case 16: return linflp_k18_f0x16;
    case 17: return linflp_k18_f0x17;
    case 18: return linflp_k18_f0x18;
    default: return 0;
  }
}

double *linflp_k18_get_f0u(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_f0u0;
    case 1: return linflp_k18_f0u1;
    case 2: return linflp_k18_f0u2;
    case 3: return linflp_k18_f0u3;
    case 4: return linflp_k18_f0u4;
    case 5: return linflp_k18_f0u5;
    case 6: return linflp_k18_f0u6;
    case 7: return linflp_k18_f0u7;
    case 8: return linflp_k18_f0u8;
    case 9: return linflp_k18_f0u9;
    case 10: return linflp_k18_f0u10;
    case 11: return linflp_k18_f0u11;
    case 12: return linflp_k18_f0u12;
    case 13: return linflp_k18_f0u13;
    case 14: return linflp_k18_f0u14;
    case 15: return linflp_k18_f0u15;
    case 16: return linflp_k18_f0u16;
    case 17: return linflp_k18_f0u17;
    case 18: return linflp_k18_f0u18;
    default: return 0;
  }
}

double *linflp_k18_get_f0s(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_f0s0;
    case 1: return linflp_k18_f0s1;
    case 2: return linflp_k18_f0s2;
    case 3: return linflp_k18_f0s3;
    case 4: return linflp_k18_f0s4;
    case 5: return linflp_k18_f0s5;
    case 6: return linflp_k18_f0s6;
    case 7: return linflp_k18_f0s7;
    case 8: return linflp_k18_f0s8;
    case 9: return linflp_k18_f0s9;
    case 10: return linflp_k18_f0s10;
    case 11: return linflp_k18_f0s11;
    case 12: return linflp_k18_f0s12;
    case 13: return linflp_k18_f0s13;
    case 14: return linflp_k18_f0s14;
    case 15: return linflp_k18_f0s15;
    case 16: return linflp_k18_f0s16;
    case 17: return linflp_k18_f0s17;
    case 18: return linflp_k18_f0s18;
    default: return 0;
  }
}

double *linflp_k18_get_fx(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_fx0;
    case 1: return linflp_k18_fx1;
    case 2: return linflp_k18_fx2;
    case 3: return linflp_k18_fx3;
    case 4: return linflp_k18_fx4;
    case 5: return linflp_k18_fx5;
    case 6: return linflp_k18_fx6;
    case 7: return linflp_k18_fx7;
    case 8: return linflp_k18_fx8;
    case 9: return linflp_k18_fx9;
    case 10: return linflp_k18_fx10;
    case 11: return linflp_k18_fx11;
    case 12: return linflp_k18_fx12;
    case 13: return linflp_k18_fx13;
    case 14: return linflp_k18_fx14;
    case 15: return linflp_k18_fx15;
    case 16: return linflp_k18_fx16;
    case 17: return linflp_k18_fx17;
    case 18: return linflp_k18_fx18;
    default: return 0;
  }
}

double *linflp_k18_get_fu(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_fu0;
    case 1: return linflp_k18_fu1;
    case 2: return linflp_k18_fu2;
    case 3: return linflp_k18_fu3;
    case 4: return linflp_k18_fu4;
    case 5: return linflp_k18_fu5;
    case 6: return linflp_k18_fu6;
    case 7: return linflp_k18_fu7;
    case 8: return linflp_k18_fu8;
    case 9: return linflp_k18_fu9;
    case 10: return linflp_k18_fu10;
    case 11: return linflp_k18_fu11;
    case 12: return linflp_k18_fu12;
    case 13: return linflp_k18_fu13;
    case 14: return linflp_k18_fu14;
    case 15: return linflp_k18_fu15;
    case 16: return linflp_k18_fu16;
    case 17: return linflp_k18_fu17;
    case 18: return linflp_k18_fu18;
    default: return 0;
  }
}

double *linflp_k18_get_f(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_f0;
    case 1: return linflp_k18_f1;
    case 2: return linflp_k18_f2;
    case 3: return linflp_k18_f3;
    case 4: return linflp_k18_f4;
    case 5: return linflp_k18_f5;
    case 6: return linflp_k18_f6;
    case 7: return linflp_k18_f7;
    case 8: return linflp_k18_f8;
    case 9: return linflp_k18_f9;
    case 10: return linflp_k18_f10;
    case 11: return linflp_k18_f11;
    case 12: return linflp_k18_f12;
    case 13: return linflp_k18_f13;
    case 14: return linflp_k18_f14;
    case 15: return linflp_k18_f15;
    case 16: return linflp_k18_f16;
    case 17: return linflp_k18_f17;
    case 18: return linflp_k18_f18;
    default: return 0;
  }
}

double *linflp_k18_get_gx(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_gx0;
    case 1: return linflp_k18_gx1;
    case 2: return linflp_k18_gx2;
    case 3: return linflp_k18_gx3;
    case 4: return linflp_k18_gx4;
    case 5: return linflp_k18_gx5;
    case 6: return linflp_k18_gx6;
    case 7: return linflp_k18_gx7;
    case 8: return linflp_k18_gx8;
    case 9: return linflp_k18_gx9;
    case 10: return linflp_k18_gx10;
    case 11: return linflp_k18_gx11;
    case 12: return linflp_k18_gx12;
    case 13: return linflp_k18_gx13;
    case 14: return linflp_k18_gx14;
    case 15: return linflp_k18_gx15;
    case 16: return linflp_k18_gx16;
    case 17: return linflp_k18_gx17;
    case 18: return linflp_k18_gx18;
    default: return 0;
  }
}

double *linflp_k18_get_gu(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_gu0;
    case 1: return linflp_k18_gu1;
    case 2: return linflp_k18_gu2;
    case 3: return linflp_k18_gu3;
    case 4: return linflp_k18_gu4;
    case 5: return linflp_k18_gu5;
    case 6: return linflp_k18_gu6;
    case 7: return linflp_k18_gu7;
    case 8: return linflp_k18_gu8;
    case 9: return linflp_k18_gu9;
    case 10: return linflp_k18_gu10;
    case 11: return linflp_k18_gu11;
    case 12: return linflp_k18_gu12;
    case 13: return linflp_k18_gu13;
    case 14: return linflp_k18_gu14;
    case 15: return linflp_k18_gu15;
    case 16: return linflp_k18_gu16;
    case 17: return linflp_k18_gu17;
    case 18: return linflp_k18_gu18;
    default: return 0;
  }
}

double *linflp_k18_get_g(int k)
{
  switch(k)
  {
    case 0: return linflp_k18_g0;
    case 1: return linflp_k18_g1;
    case 2: return linflp_k18_g2;
    case 3: return linflp_k18_g3;
    case 4: return linflp_k18_g4;
    case 5: return linflp_k18_g5;
    case 6: return linflp_k18_g6;
    case 7: return linflp_k18_g7;
    case 8: return linflp_k18_g8;
    case 9: return linflp_k18_g9;
    case 10: return linflp_k18_g10;
    case 11: return linflp_k18_g11;
    case 12: return linflp_k18_g12;
    case 13: return linflp_k18_g13;
    case 14: return linflp_k18_g14;
    case 15: return linflp_k18_g15;
    case 16: return linflp_k18_g16;
    case 17: return linflp_k18_g17;
    case 18: return linflp_k18_g18;
    default: return 0;
  }
}

double *linflp_k18_get_stat_time()
{
return linflp_k18_stat_time;
}

int *linflp_k18_get_stat_iter_ref()
{
return &linflp_k18_stat_iter_ref;
}

int *linflp_k18_get_stat_num_factor()
{
return &linflp_k18_stat_num_factor;
}

int *linflp_k18_get_stat_num_solve()
{
return &linflp_k18_stat_num_solve;
}

int *linflp_k18_get_stat_num_iter_ref()
{
return &linflp_k18_stat_num_iter_ref;
}

int *linflp_k18_get_iter()
{
return &linflp_k18_iter;
}

int *linflp_k18_get_termcode()
{
return &linflp_k18_termcode;
}

int *linflp_k18_get_error_line()
{
return &linflp_k18_error_line;
}

int *linflp_k18_get_error_source()
{
return &linflp_k18_error_source;
}

double *linflp_k18_get_norm_d()
{
return linflp_k18_norm_d;
}
double *linflp_k18_get_time_max()
{
return &linflp_k18_time_max;
}

void linflp_k18_set_time_max(double tmax)
{
linflp_k18_time_max = tmax;
}


/* ###################################### */
/* Diese Funktion initialisiert den Timer */
/* ###################################### */
void linflp_k18_glqdocpip_timer_start()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER linflp_k18_tmp_counter, linflp_k18_tmp_frequency;
  QueryPerformanceFrequency(&linflp_k18_tmp_frequency);
  QueryPerformanceCounter(&linflp_k18_tmp_counter);
  linflp_k18_timer_start = (double) linflp_k18_tmp_counter.QuadPart/(double) linflp_k18_tmp_frequency.QuadPart;
#endif
}


/* ################################################### */
/* Diese Funktion gibt die Zeit seit Timerstart zur�ck */
/* ################################################### */
double linflp_k18_glqdocpip_timer_get()
{
#if defined(__WIN32__) || defined(WIN32)
  LARGE_INTEGER linflp_k18_tmp_counter, linflp_k18_tmp_frequency;
  QueryPerformanceFrequency(&linflp_k18_tmp_frequency);
  QueryPerformanceCounter(&linflp_k18_tmp_counter);
  return (double) linflp_k18_tmp_counter.QuadPart/(double) linflp_k18_tmp_frequency.QuadPart - linflp_k18_timer_start;
#endif
}

static void linflp_k18_v_copy_3(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  return;
}

static void linflp_k18_mv_sid21_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid24_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_vsub_3(double *a, double *b, double *out)
{

  out[0] = a[0] - b[0];
  out[1] = a[1] - b[1];
  out[2] = a[2] - b[2];
  return;
}

static void linflp_k18_mtv_sid42_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[0];
  out[2] += A[6] * b[0];
  out[1] += A[4] * b[1];
  out[2] += A[7] * b[1];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k18_mtv_sid51_sid15_10_3(double *A, double *b, double *out)
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

static void linflp_k18_v_copy_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  return;
}

static void linflp_k18_mtv_sid24_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid27_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mtv_sid45_sid2_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  return;
}

static void linflp_k18_mtv_sid54_sid15_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k18_v_copy_10(double *a, double *out)
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

static void linflp_k18_mv_sid51_sid2_10_3(double *A, double *b, double *out)
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

static void linflp_k18_mv_sid54_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k18_vadd_10(double *a, double *b, double *out)
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

static void linflp_k18_vv_elemult_10(double *a, double *b, double *out)
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

static void linflp_k18_mv_sid22_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid25_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mtv_sid43_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[3] * b[0];
  out[2] += A[6] * b[0];
  out[1] += A[4] * b[1];
  out[2] += A[7] * b[1];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k18_mtv_sid52_sid16_10_3(double *A, double *b, double *out)
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

static void linflp_k18_mtv_sid25_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid28_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mtv_sid46_sid2_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[1] * b[1];
  out[0] += A[2] * b[2];
  return;
}

static void linflp_k18_mtv_sid55_sid16_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k18_mv_sid43_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k18_mv_sid46_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k18_mv_sid52_sid2_10_3(double *A, double *b, double *out)
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

static void linflp_k18_mv_sid55_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k18_mv_sid23_sid2_3_3(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid26_sid5_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mtv_sid53_sid17_10_3(double *A, double *b, double *out)
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

static void linflp_k18_mtv_sid26_sid2_3_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mv_sid29_sid5_2_2(double *A, double *b, double *out)
{

  return;
}

static void linflp_k18_mtv_sid56_sid17_10_2(double *A, double *b, double *out)
{

  out[0] += A[6] * b[6];
  out[0] += A[7] * b[7];
  out[1] += A[18] * b[8];
  out[1] += A[19] * b[9];
  return;
}

static void linflp_k18_mv_sid44_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k18_mv_sid47_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k18_mv_sid53_sid2_10_3(double *A, double *b, double *out)
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

static void linflp_k18_mv_sid56_sid5_10_2(double *A, double *b, double *out)
{

  out[6] += A[6] * b[0];
  out[7] += A[7] * b[0];
  out[8] += A[18] * b[1];
  out[9] += A[19] * b[1];
  return;
}

static void linflp_k18_v_init0_10(double *a)
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

static void linflp_k18_vv_elediv_10(double *a, double *b, double *out)
{

  if(b[0] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  if(b[1] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[1] = a[1] / b[1];
  if(b[2] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[2] = a[2] / b[2];
  if(b[3] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[3] = a[3] / b[3];
  if(b[4] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[4] = a[4] / b[4];
  if(b[5] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[5] = a[5] / b[5];
  if(b[6] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[6] = a[6] / b[6];
  if(b[7] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[7] = a[7] / b[7];
  if(b[8] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[8] = a[8] / b[8];
  if(b[9] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[9] = a[9] / b[9];
  return;
}

static void linflp_k18_v_copy_0(double *a, double *out)
{

  return;
}

static void linflp_k18_vsub_10(double *a, double *b, double *out)
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

static void linflp_k18_v_init1_10(double *a)
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

static void linflp_k18_vv_elemult_1(double *a, double *b, double *out)
{

  out[0] = a[0] * b[0];
  return;
}

static void linflp_k18_sv_10(double *a, double *b, double *out)
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

static void linflp_k18_m_copy_3_3(double *a, double *out)
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

static void linflp_k18_m_copy_3_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  out[4] = a[4];
  out[5] = a[5];
  return;
}

static void linflp_k18_m_init0_3_10(double *a)
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

static void linflp_k18_mtd_sid53_sid17_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_y_sid14_sid53_3_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid14_sid56_3_10_2(double *A, double *B, double *out)
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

static void linflp_k18_m_copy_2_2(double *a, double *out)
{

  out[0] = a[0];
  out[1] = a[1];
  out[2] = a[2];
  out[3] = a[3];
  return;
}

static void linflp_k18_m_init0_2_10(double *a)
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

static void linflp_k18_mtd_sid56_sid17_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k18_mm_2_10_2(double *A, double *B, double *out)
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

static void linflp_k18_mtr_3_2(double *A, double *out)
{

  out[0] = A[0];
  out[1] = A[3];
  out[2] = A[1];
  out[3] = A[4];
  out[4] = A[2];
  out[5] = A[5];
  return;
}

static void linflp_k18_chol_factor_2(double *a, double *out)
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
          linflp_k18_termcode = 8;
          linflp_k18_error_line = __LINE__;
          return;
        }
        out[i+2*j] = sum / out[j+2*j];
      }
      else
      {
        if(sum < 0){
          linflp_k18_termcode = 9;
          linflp_k18_error_line = __LINE__;
          return;
        }
        out[i+2*i] = (double)sqrt(sum);
      }
    }
  }
  return;
}

static void linflp_k18_chol_solve_2_3(double *l, double *b, double *out)
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
        linflp_k18_termcode = 8;
        linflp_k18_error_line = __LINE__;
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
        linflp_k18_termcode = 8;
        return;
      }
        out[i+2*k] = sum / l[2*i+i];
    }
  }
  return;
}

static void linflp_k18_m_init0_3_3(double *a)
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

static void linflp_k18_mm_y_3_2_3(double *A, double *B, double *out)
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

static void linflp_k18_msub_3_3(double *A, double *B, double *out)
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

static void linflp_k18_mtm_sid43_sid1_3_3_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_y_sid1_sid43_3_3_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid1_sid46_3_3_2(double *A, double *B, double *out)
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

static void linflp_k18_mtd_sid52_sid16_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_y_sid13_sid52_3_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid13_sid55_3_10_2(double *A, double *B, double *out)
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

static void linflp_k18_m_init0_2_3(double *a)
{

  a[0] =0;
  a[1] =0;
  a[2] =0;
  a[3] =0;
  a[4] =0;
  a[5] =0;
  return;
}

static void linflp_k18_mtm_sid46_sid1_3_2_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid8_sid46_2_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[0] += A[2] * B[1];
out[1] += A[3] * B[1];
out[0] += A[4] * B[2];
out[1] += A[5] * B[2];
  return;
}

static void linflp_k18_mtd_sid55_sid16_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k18_mtm_sid42_sid1_3_3_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_y_sid1_sid42_3_3_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid1_sid45_3_3_2(double *A, double *B, double *out)
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

static void linflp_k18_mtd_sid51_sid15_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_y_sid12_sid51_3_10_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid12_sid54_3_10_2(double *A, double *B, double *out)
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

static void linflp_k18_mtm_sid45_sid1_3_2_3(double *A, double *B, double *out)
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

static void linflp_k18_mm_sid8_sid45_2_3_2(double *A, double *B, double *out)
{

out[0] += A[0] * B[0];
out[1] += A[1] * B[0];
out[0] += A[2] * B[1];
out[1] += A[3] * B[1];
out[0] += A[4] * B[2];
out[1] += A[5] * B[2];
  return;
}

static void linflp_k18_mtd_sid54_sid15_10_2(double *A, double *B, double *out)
{

      out[12] += A[6] * B[6];
      out[14] += A[7] * B[7];
      out[17] += A[18] * B[8];
      out[19] += A[19] * B[9];
  return;
}

static void linflp_k18_chol_solve_2_1(double *l, double *b, double *out)
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
        linflp_k18_termcode = 8;
        linflp_k18_error_line = __LINE__;
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
        linflp_k18_termcode = 8;
        return;
      }
        out[i+2*k] = sum / l[2*i+i];
    }
  }
  return;
}

static void linflp_k18_v_init0_3(double *a)
{

    a[0] =0;
    a[1] =0;
    a[2] =0;
  return;
}

static void linflp_k18_mv_3_2(double *A, double *b, double *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[2] += A[2] * b[0];
      out[0] += A[3] * b[1];
      out[1] += A[4] * b[1];
      out[2] += A[5] * b[1];
  return;
}

static void linflp_k18_mv_3_3(double *A, double *b, double *out)
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

static void linflp_k18_mv_2_3(double *A, double *b, double *out)
{

      out[0] += A[0] * b[0];
      out[1] += A[1] * b[0];
      out[0] += A[2] * b[1];
      out[1] += A[3] * b[1];
      out[0] += A[4] * b[2];
      out[1] += A[5] * b[2];
  return;
}

static void linflp_k18_v_turnsign_2(double *a, double *out)
{

    out[0] = -a[0];
    out[1] = -a[1];
  return;
}

static void linflp_k18_mv_sid42_sid2_3_3(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[0] += A[3] * b[1];
  out[1] += A[4] * b[1];
  out[0] += A[6] * b[2];
  out[1] += A[7] * b[2];
  out[2] += A[8] * b[2];
  return;
}

static void linflp_k18_mv_sid45_sid5_3_2(double *A, double *b, double *out)
{

  out[0] += A[0] * b[0];
  out[1] += A[1] * b[0];
  out[2] += A[2] * b[0];
  return;
}

static void linflp_k18_m_copy_0_1(double *a, double *out)
{

  return;
}

static void linflp_k18_m_copy_10_1(double *a, double *out)
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

static void linflp_k18_v_turnsign_10(double *a, double *out)
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

static void linflp_k18_vadd_3(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  out[2] = a[2] + b[2];
  return;
}

static void linflp_k18_vadd_2(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  out[1] = a[1] + b[1];
  return;
}

static void linflp_k18_v_init0_1(double *a)
{

    a[0] =0;
  return;
}

static void linflp_k18_vtv_3(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  out[0] += a[2] * b[2];
  return;
}

static void linflp_k18_v_init0_2(double *a)
{

    a[0] =0;
    a[1] =0;
  return;
}

static void linflp_k18_vtv_2(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[0] += a[1] * b[1];
  return;
}

static void linflp_k18_vsub_1(double *a, double *b, double *out)
{

  out[0] = a[0] - b[0];
  return;
}

static void linflp_k18_vtv_10(double *a, double *b, double *out)
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

static void linflp_k18_vv_elediv_1(double *a, double *b, double *out)
{

  if(b[0] == 0){ linflp_k18_termcode = 8; linflp_k18_error_line = __LINE__; return;}
  out[0] = a[0] / b[0];
  return;
}

static void linflp_k18_v_copy_1(double *a, double *out)
{

  out[0] = a[0];
  return;
}

static void linflp_k18_vadd_1(double *a, double *b, double *out)
{

  out[0] = a[0] + b[0];
  return;
}

static void linflp_k18_min(double *a, double *b, double *out)
{

  if  (a[0] < b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void linflp_k18_v_turnsign_1(double *a, double *out)
{

    out[0] = -a[0];
  return;
}

static void linflp_k18_v_init1_1(double *a)
{

    a[0] =1;
  return;
}

static void linflp_k18_max(double *a, double *b, double *out)
{

  if  (a[0] > b[0])
  {
    out[0] = a[0];
  } else {
    out[0] = b[0];
  }
  return;
}

static void linflp_k18_sv_3(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  out[2] += a[0] * b[2];
  return;
}

static void linflp_k18_sv_2(double *a, double *b, double *out)
{

  out[0] += a[0] * b[0];
  out[1] += a[0] * b[1];
  return;
}

static void linflp_k18_norm_inf_3_3(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_3_2(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_2_2(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_3_1(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_2_1(double *A, double *B, double *out)
{
  out[0] = B[0];

  if (A[0] > out[0]) out[0] = A[0];
  if (-A[0] > out[0]) out[0] = A[0];
  if (A[1] > out[0]) out[0] = A[1];
  if (-A[1] > out[0]) out[0] = A[1];
  return;
}

static void linflp_k18_norm_inf_10_3(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_10_2(double *A, double *B, double *out)
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

static void linflp_k18_norm_inf_10_1(double *A, double *B, double *out)
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
static void linflp_k18_glqdocpip_calc_mu()
{
linflp_k18_v_init0_1(linflp_k18_mu);
/* mu = mu + y*nu */
/* Zeitschritt 0 */
linflp_k18_vtv_10(linflp_k18_y0, linflp_k18_nu0, linflp_k18_mu);
/* Zeitschritt 1 */
linflp_k18_vtv_10(linflp_k18_y1, linflp_k18_nu1, linflp_k18_mu);
/* Zeitschritt 2 */
linflp_k18_vtv_10(linflp_k18_y2, linflp_k18_nu2, linflp_k18_mu);
/* Zeitschritt 3 */
linflp_k18_vtv_10(linflp_k18_y3, linflp_k18_nu3, linflp_k18_mu);
/* Zeitschritt 4 */
linflp_k18_vtv_10(linflp_k18_y4, linflp_k18_nu4, linflp_k18_mu);
/* Zeitschritt 5 */
linflp_k18_vtv_10(linflp_k18_y5, linflp_k18_nu5, linflp_k18_mu);
/* Zeitschritt 6 */
linflp_k18_vtv_10(linflp_k18_y6, linflp_k18_nu6, linflp_k18_mu);
/* Zeitschritt 7 */
linflp_k18_vtv_10(linflp_k18_y7, linflp_k18_nu7, linflp_k18_mu);
/* Zeitschritt 8 */
linflp_k18_vtv_10(linflp_k18_y8, linflp_k18_nu8, linflp_k18_mu);
/* Zeitschritt 9 */
linflp_k18_vtv_10(linflp_k18_y9, linflp_k18_nu9, linflp_k18_mu);
/* Zeitschritt 10 */
linflp_k18_vtv_10(linflp_k18_y10, linflp_k18_nu10, linflp_k18_mu);
/* Zeitschritt 11 */
linflp_k18_vtv_10(linflp_k18_y11, linflp_k18_nu11, linflp_k18_mu);
/* Zeitschritt 12 */
linflp_k18_vtv_10(linflp_k18_y12, linflp_k18_nu12, linflp_k18_mu);
/* Zeitschritt 13 */
linflp_k18_vtv_10(linflp_k18_y13, linflp_k18_nu13, linflp_k18_mu);
/* Zeitschritt 14 */
linflp_k18_vtv_10(linflp_k18_y14, linflp_k18_nu14, linflp_k18_mu);
/* Zeitschritt 15 */
linflp_k18_vtv_10(linflp_k18_y15, linflp_k18_nu15, linflp_k18_mu);
/* Zeitschritt 16 */
linflp_k18_vtv_10(linflp_k18_y16, linflp_k18_nu16, linflp_k18_mu);
/* Zeitschritt 17 */
linflp_k18_vtv_10(linflp_k18_y17, linflp_k18_nu17, linflp_k18_mu);
/* Zeitschritt 18 */
linflp_k18_vtv_10(linflp_k18_y18, linflp_k18_nu18, linflp_k18_mu);
linflp_k18_vv_elediv_1(linflp_k18_mu, linflp_k18_m_ineq, linflp_k18_mu);
if(linflp_k18_termcode > -1){return;}

/* mu0 bestimmen */
if(linflp_k18_iter == 0){
linflp_k18_v_copy_1(linflp_k18_mu, linflp_k18_mu0);
}
}


/* ############################### */
/* Diese Funktion berechnet mu_aff */
/* ############################### */
static void linflp_k18_glqdocpip_calc_mu_aff()
{
linflp_k18_v_init0_1(linflp_k18_mu_aff);
/* Zeitschritt 0 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y0, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy0, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu0, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu0, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 1 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y1, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy1, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu1, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu1, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 2 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y2, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy2, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu2, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu2, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 3 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y3, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy3, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu3, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu3, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 4 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y4, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy4, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu4, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu4, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 5 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y5, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy5, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu5, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu5, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 6 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y6, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy6, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu6, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu6, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 7 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y7, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy7, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu7, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu7, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 8 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y8, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy8, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu8, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu8, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 9 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y9, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy9, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu9, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu9, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 10 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y10, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy10, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu10, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu10, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 11 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y11, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy11, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu11, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu11, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 12 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y12, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy12, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu12, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu12, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 13 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y13, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy13, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu13, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu13, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 14 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y14, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy14, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu14, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu14, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 15 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y15, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy15, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu15, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu15, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 16 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y16, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy16, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu16, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu16, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
/* Zeitschritt 17 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y17, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy17, linflp_k18_tmp1_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu17, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu17, linflp_k18_tmp2_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp1_10, linflp_k18_tmp2_10, linflp_k18_mu_aff);
/* Zeitschritt 18 */
/* yady = y + alpha_max*dy */
linflp_k18_v_copy_10(linflp_k18_y18, linflp_k18_tmp2_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dy18, linflp_k18_tmp2_10);
/* nuadnu = nu + alpha_max*dnu */
linflp_k18_v_copy_10(linflp_k18_nu18, linflp_k18_tmp1_10);
linflp_k18_sv_10(linflp_k18_alpha_max, linflp_k18_dnu18, linflp_k18_tmp1_10);
/* mu_aff = mu_aff + yady.*nuadnu) */
linflp_k18_vtv_10(linflp_k18_tmp2_10, linflp_k18_tmp1_10, linflp_k18_mu_aff);
linflp_k18_vv_elediv_1(linflp_k18_mu_aff, linflp_k18_m_ineq, linflp_k18_mu_aff);
if(linflp_k18_termcode > -1){return;}
}


/* ############################ */
/* Diese Funktion berechnet phi */
/* ############################ */
static void linflp_k18_glqdocpip_calc_phi()
{
linflp_k18_vadd_1(linflp_k18_norm_r, linflp_k18_dgap, linflp_k18_phi);
linflp_k18_vv_elediv_1(linflp_k18_phi, linflp_k18_norm_d, linflp_k18_phi);
if(linflp_k18_termcode > -1){return;}
if (linflp_k18_iter > 0) {

linflp_k18_min(linflp_k18_minphi, linflp_k18_phi, linflp_k18_minphi);
}else{
linflp_k18_v_copy_1(linflp_k18_phi, linflp_k18_minphi);
}
}


/* ######################################################## */
/* Diese Funktion berechnet den Zentrierungsparameter sigma */
/* ######################################################## */
static void linflp_k18_glqdocpip_calc_sigma()
{
linflp_k18_vv_elediv_1(linflp_k18_mu_aff, linflp_k18_mu, linflp_k18_tmp1_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_sigma[0] = pow(*linflp_k18_tmp1_1, *linflp_k18_tau);
}


/* ########################################################### */
/* Diese Funktion berechnet die maximal m�gliche Schrittweite, */
/* bei der y und nu noch positiv bleiben */
/* ########################################################### */
static void linflp_k18_glqdocpip_max_stepsize()
{
int i;

linflp_k18_alpha_max[0] = -DBL_MAX;
linflp_k18_alpha_tmp[0] = 0;

/* Zeitschritt 0 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy0[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y0[i], &linflp_k18_dy0[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y0[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy0[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu0[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu0[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu0[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu0[i], &linflp_k18_dnu0[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y0[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy0[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu0[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu0[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 1 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy1[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y1[i], &linflp_k18_dy1[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y1[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy1[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu1[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu1[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu1[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu1[i], &linflp_k18_dnu1[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y1[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy1[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu1[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu1[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 2 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy2[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y2[i], &linflp_k18_dy2[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y2[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy2[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu2[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu2[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu2[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu2[i], &linflp_k18_dnu2[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y2[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy2[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu2[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu2[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 3 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy3[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y3[i], &linflp_k18_dy3[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y3[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy3[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu3[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu3[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu3[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu3[i], &linflp_k18_dnu3[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y3[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy3[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu3[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu3[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 4 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy4[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y4[i], &linflp_k18_dy4[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y4[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy4[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu4[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu4[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu4[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu4[i], &linflp_k18_dnu4[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y4[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy4[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu4[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu4[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 5 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy5[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y5[i], &linflp_k18_dy5[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y5[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy5[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu5[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu5[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu5[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu5[i], &linflp_k18_dnu5[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y5[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy5[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu5[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu5[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 6 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy6[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y6[i], &linflp_k18_dy6[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y6[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy6[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu6[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu6[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu6[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu6[i], &linflp_k18_dnu6[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y6[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy6[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu6[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu6[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 7 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy7[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y7[i], &linflp_k18_dy7[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y7[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy7[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu7[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu7[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu7[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu7[i], &linflp_k18_dnu7[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y7[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy7[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu7[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu7[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 8 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy8[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y8[i], &linflp_k18_dy8[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y8[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy8[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu8[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu8[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu8[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu8[i], &linflp_k18_dnu8[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y8[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy8[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu8[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu8[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 9 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy9[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y9[i], &linflp_k18_dy9[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y9[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy9[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu9[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu9[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu9[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu9[i], &linflp_k18_dnu9[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y9[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy9[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu9[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu9[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 10 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy10[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y10[i], &linflp_k18_dy10[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y10[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy10[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu10[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu10[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu10[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu10[i], &linflp_k18_dnu10[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y10[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy10[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu10[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu10[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 11 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy11[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y11[i], &linflp_k18_dy11[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y11[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy11[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu11[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu11[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu11[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu11[i], &linflp_k18_dnu11[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y11[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy11[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu11[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu11[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 12 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy12[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y12[i], &linflp_k18_dy12[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y12[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy12[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu12[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu12[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu12[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu12[i], &linflp_k18_dnu12[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y12[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy12[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu12[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu12[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 13 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy13[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y13[i], &linflp_k18_dy13[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y13[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy13[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu13[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu13[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu13[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu13[i], &linflp_k18_dnu13[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y13[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy13[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu13[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu13[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 14 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy14[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y14[i], &linflp_k18_dy14[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y14[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy14[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu14[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu14[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu14[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu14[i], &linflp_k18_dnu14[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y14[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy14[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu14[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu14[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 15 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy15[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y15[i], &linflp_k18_dy15[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y15[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy15[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu15[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu15[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu15[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu15[i], &linflp_k18_dnu15[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y15[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy15[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu15[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu15[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 16 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy16[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y16[i], &linflp_k18_dy16[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y16[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy16[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu16[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu16[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu16[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu16[i], &linflp_k18_dnu16[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y16[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy16[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu16[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu16[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 17 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy17[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y17[i], &linflp_k18_dy17[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y17[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy17[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu17[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu17[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu17[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu17[i], &linflp_k18_dnu17[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y17[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy17[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu17[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu17[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}
/* Zeitschritt 18 */
for(i=0;i<10;i++)
{
/* dy-check */
if( linflp_k18_dy18[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_y18[i], &linflp_k18_dy18[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y18[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy18[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu18[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu18[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 1;
}
}
/* dnu-check */
if( linflp_k18_dnu18[i] < 0)
{
linflp_k18_vv_elediv_1(&linflp_k18_nu18[i], &linflp_k18_dnu18[i], linflp_k18_alpha_tmp);
if(linflp_k18_termcode > -1){return;}
if( *linflp_k18_alpha_tmp > *linflp_k18_alpha_max )
{
linflp_k18_alpha_max[0] = *linflp_k18_alpha_tmp;
linflp_k18_v_copy_1(&linflp_k18_y18[i], &linflp_k18_alpha_min_y[0]);
linflp_k18_v_copy_1(&linflp_k18_dy18[i], &linflp_k18_alpha_min_dy[0]);
linflp_k18_v_copy_1(&linflp_k18_nu18[i], &linflp_k18_alpha_min_nu[0]);
linflp_k18_v_copy_1(&linflp_k18_dnu18[i], &linflp_k18_alpha_min_dnu[0]);
linflp_k18_alpha_min_source_y = 0;
}
}
}

linflp_k18_v_turnsign_1(&linflp_k18_alpha_max[0], &linflp_k18_alpha_max[0]);
}


/* ####################################################### */
/* Diese Funktion berechnet die Schrittweite nach Mehrotra */
/* ####################################################### */
static void linflp_k18_glqdocpip_mehrotra_step()
{

/* FPD */
if (linflp_k18_alpha_min_source_y == 1) {
/* alpha_max durch y verursacht */
linflp_k18_vv_elemult_1(linflp_k18_alpha_max, linflp_k18_alpha_min_dnu, linflp_k18_mehrotra_fpd);
linflp_k18_vadd_1(linflp_k18_mehrotra_fpd, linflp_k18_alpha_min_nu, linflp_k18_mehrotra_fpd);
linflp_k18_vv_elediv_1(linflp_k18_mu_aff, linflp_k18_mehrotra_fpd, linflp_k18_mehrotra_fpd);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vv_elemult_1(linflp_k18_mehrotra_fpd, linflp_k18_mehrotra_gamma, linflp_k18_mehrotra_fpd);
linflp_k18_vsub_1(linflp_k18_mehrotra_fpd, linflp_k18_alpha_min_y, linflp_k18_mehrotra_fpd);
linflp_k18_vv_elemult_1(linflp_k18_alpha_max, linflp_k18_alpha_min_dy, linflp_k18_tmp1_1);
linflp_k18_vv_elediv_1(linflp_k18_mehrotra_fpd, linflp_k18_tmp1_1, linflp_k18_mehrotra_fpd);
if(linflp_k18_termcode > -1){return;}
} else {
/* alpha_max durch nu verursacht */
linflp_k18_vv_elemult_1(linflp_k18_alpha_max, linflp_k18_alpha_min_dy, linflp_k18_mehrotra_fpd);
linflp_k18_vadd_1(linflp_k18_mehrotra_fpd, linflp_k18_alpha_min_y, linflp_k18_mehrotra_fpd);
linflp_k18_vv_elediv_1(linflp_k18_mu_aff, linflp_k18_mehrotra_fpd, linflp_k18_mehrotra_fpd);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vv_elemult_1(linflp_k18_mehrotra_fpd, linflp_k18_mehrotra_gamma, linflp_k18_mehrotra_fpd);
linflp_k18_vsub_1(linflp_k18_mehrotra_fpd, linflp_k18_alpha_min_nu, linflp_k18_mehrotra_fpd);
linflp_k18_vv_elemult_1(linflp_k18_alpha_max, linflp_k18_alpha_min_dnu, linflp_k18_tmp1_1);
linflp_k18_vv_elediv_1(linflp_k18_mehrotra_fpd, linflp_k18_tmp1_1, linflp_k18_mehrotra_fpd);
if(linflp_k18_termcode > -1){return;}
}
/* Schrittweitenfaktor begrenzen */
/* Nach unten limitieren (1-gamma) */
linflp_k18_v_init1_1(linflp_k18_tmp1_1);
linflp_k18_vsub_1(linflp_k18_tmp1_1, linflp_k18_mehrotra_gamma, linflp_k18_tmp1_1);
linflp_k18_max(linflp_k18_mehrotra_fpd, linflp_k18_tmp1_1, linflp_k18_mehrotra_fpd);
/* nach oben limitieren (1-macheps) */
linflp_k18_v_init1_1(linflp_k18_tmp1_1);
linflp_k18_vsub_1(linflp_k18_tmp1_1, linflp_k18_macheps, linflp_k18_tmp1_1);
linflp_k18_min(linflp_k18_mehrotra_fpd, linflp_k18_tmp1_1, linflp_k18_mehrotra_fpd);
/* Schrittweite berechnen */
linflp_k18_vv_elemult_1(linflp_k18_mehrotra_fpd, linflp_k18_alpha_max, linflp_k18_mehrotra_alpha);
/* Schritt begrenzen 0 =< alpha =< 1 */
linflp_k18_v_init0_1(linflp_k18_tmp1_1);
linflp_k18_max(linflp_k18_mehrotra_alpha, linflp_k18_tmp1_1, linflp_k18_mehrotra_alpha);
linflp_k18_v_init1_1(linflp_k18_tmp1_1);
linflp_k18_min(linflp_k18_mehrotra_alpha, linflp_k18_tmp1_1, linflp_k18_mehrotra_alpha);
}


/* ########################################### */
/* Diese Funktion berechnet die Dualit�tsl�cke */
/* ########################################### */
static void linflp_k18_glqdocpip_calc_duality_gap()
{
linflp_k18_v_init0_1(linflp_k18_dgap);
/* Zeitschritt 0 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid21_sid2_3_3(linflp_k18_Hxx0, linflp_k18_x0, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x0, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid24_sid5_3_2(linflp_k18_Hxu0, linflp_k18_u0, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x0, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x0, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid27_sid5_2_2(linflp_k18_Huu0, linflp_k18_u0, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u0, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x0, linflp_k18_x0, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u0, linflp_k18_u0, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_xinit, linflp_k18_p0, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g0, linflp_k18_y0, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 1 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx1, linflp_k18_x1, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x1, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu1, linflp_k18_u1, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x1, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x1, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu1, linflp_k18_u1, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u1, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x1, linflp_k18_x1, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u1, linflp_k18_u1, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f0, linflp_k18_p1, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g1, linflp_k18_y1, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 2 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx2, linflp_k18_x2, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x2, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu2, linflp_k18_u2, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x2, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x2, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu2, linflp_k18_u2, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u2, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x2, linflp_k18_x2, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u2, linflp_k18_u2, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f1, linflp_k18_p2, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g2, linflp_k18_y2, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 3 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx3, linflp_k18_x3, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x3, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu3, linflp_k18_u3, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x3, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x3, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu3, linflp_k18_u3, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u3, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x3, linflp_k18_x3, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u3, linflp_k18_u3, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f2, linflp_k18_p3, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g3, linflp_k18_y3, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 4 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx4, linflp_k18_x4, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x4, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu4, linflp_k18_u4, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x4, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x4, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu4, linflp_k18_u4, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u4, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x4, linflp_k18_x4, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u4, linflp_k18_u4, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f3, linflp_k18_p4, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g4, linflp_k18_y4, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 5 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx5, linflp_k18_x5, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x5, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu5, linflp_k18_u5, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x5, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x5, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu5, linflp_k18_u5, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u5, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x5, linflp_k18_x5, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u5, linflp_k18_u5, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f4, linflp_k18_p5, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g5, linflp_k18_y5, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 6 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx6, linflp_k18_x6, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x6, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu6, linflp_k18_u6, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x6, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x6, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu6, linflp_k18_u6, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u6, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x6, linflp_k18_x6, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u6, linflp_k18_u6, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f5, linflp_k18_p6, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g6, linflp_k18_y6, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 7 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx7, linflp_k18_x7, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x7, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu7, linflp_k18_u7, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x7, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x7, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu7, linflp_k18_u7, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u7, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x7, linflp_k18_x7, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u7, linflp_k18_u7, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f6, linflp_k18_p7, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g7, linflp_k18_y7, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 8 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx8, linflp_k18_x8, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x8, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu8, linflp_k18_u8, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x8, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x8, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu8, linflp_k18_u8, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u8, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x8, linflp_k18_x8, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u8, linflp_k18_u8, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f7, linflp_k18_p8, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g8, linflp_k18_y8, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 9 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx9, linflp_k18_x9, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x9, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu9, linflp_k18_u9, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x9, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x9, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu9, linflp_k18_u9, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u9, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x9, linflp_k18_x9, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u9, linflp_k18_u9, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f8, linflp_k18_p9, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g9, linflp_k18_y9, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 10 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx10, linflp_k18_x10, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x10, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu10, linflp_k18_u10, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x10, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x10, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu10, linflp_k18_u10, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u10, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x10, linflp_k18_x10, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u10, linflp_k18_u10, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f9, linflp_k18_p10, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g10, linflp_k18_y10, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 11 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx11, linflp_k18_x11, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x11, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu11, linflp_k18_u11, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x11, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x11, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu11, linflp_k18_u11, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u11, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x11, linflp_k18_x11, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u11, linflp_k18_u11, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f10, linflp_k18_p11, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g11, linflp_k18_y11, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 12 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx12, linflp_k18_x12, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x12, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu12, linflp_k18_u12, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x12, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x12, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu12, linflp_k18_u12, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u12, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x12, linflp_k18_x12, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u12, linflp_k18_u12, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f11, linflp_k18_p12, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g12, linflp_k18_y12, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 13 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx13, linflp_k18_x13, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x13, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu13, linflp_k18_u13, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x13, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x13, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu13, linflp_k18_u13, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u13, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x13, linflp_k18_x13, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u13, linflp_k18_u13, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f12, linflp_k18_p13, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g13, linflp_k18_y13, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 14 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx14, linflp_k18_x14, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x14, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu14, linflp_k18_u14, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x14, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x14, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu14, linflp_k18_u14, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u14, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x14, linflp_k18_x14, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u14, linflp_k18_u14, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f13, linflp_k18_p14, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g14, linflp_k18_y14, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 15 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx15, linflp_k18_x15, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x15, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu15, linflp_k18_u15, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x15, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x15, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu15, linflp_k18_u15, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u15, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x15, linflp_k18_x15, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u15, linflp_k18_u15, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f14, linflp_k18_p15, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g15, linflp_k18_y15, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 16 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx16, linflp_k18_x16, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x16, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu16, linflp_k18_u16, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x16, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x16, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu16, linflp_k18_u16, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u16, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x16, linflp_k18_x16, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u16, linflp_k18_u16, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f15, linflp_k18_p16, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g16, linflp_k18_y16, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 17 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx17, linflp_k18_x17, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x17, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu17, linflp_k18_u17, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x17, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x17, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu17, linflp_k18_u17, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u17, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x17, linflp_k18_x17, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u17, linflp_k18_u17, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f16, linflp_k18_p17, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g17, linflp_k18_y17, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Zeitschritt 18 */
/* Quadratischer Anteil */
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid23_sid2_3_3(linflp_k18_Hxx18, linflp_k18_x18, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x18, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_3(linflp_k18_tmp1_3_1);
linflp_k18_mv_sid26_sid5_3_2(linflp_k18_Hxu18, linflp_k18_u18, linflp_k18_tmp1_3_1);
linflp_k18_vtv_3(linflp_k18_x18, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_vtv_3(linflp_k18_x18, linflp_k18_tmp1_3_1, linflp_k18_dgap);
linflp_k18_v_init0_2(linflp_k18_tmp1_2_1);
linflp_k18_mv_sid29_sid5_2_2(linflp_k18_Huu18, linflp_k18_u18, linflp_k18_tmp1_2_1);
linflp_k18_vtv_2(linflp_k18_u18, linflp_k18_tmp1_2_1, linflp_k18_dgap);
/* Linearer Anteil */
linflp_k18_vtv_3(linflp_k18_f0x18, linflp_k18_x18, linflp_k18_dgap);
linflp_k18_vtv_2(linflp_k18_f0u18, linflp_k18_u18, linflp_k18_dgap);
/* Anteil durch Gleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_3(linflp_k18_f17, linflp_k18_p18, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* Anteil durch Ungleichungsnebenbedingungen */
linflp_k18_v_init0_1(linflp_k18_tmp1_1_1);
linflp_k18_vtv_10(linflp_k18_g18, linflp_k18_y18, linflp_k18_tmp1_1_1);
linflp_k18_vsub_1(linflp_k18_dgap, linflp_k18_tmp1_1_1, linflp_k18_dgap);
/* dgap = abs(dgap) */
if(linflp_k18_dgap[0] < 0){
linflp_k18_dgap[0] = -linflp_k18_dgap[0];}
}


/* ############################################################ */
/* Diese Funktion berechnet die Unendlichnorm der Eingangsdaten */
/* ############################################################ */
static void linflp_k18_glqdocpip_calc_norm_d()
{
linflp_k18_v_init0_1(linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u0, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu0, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g0, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u1, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f1, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu1, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g1, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u2, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f2, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu2, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g2, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u3, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f3, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu3, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g3, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u4, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f4, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu4, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g4, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u5, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f5, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu5, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g5, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u6, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f6, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu6, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g6, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u7, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f7, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu7, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g7, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u8, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f8, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu8, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g8, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u9, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f9, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu9, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g9, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u10, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f10, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu10, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g10, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u11, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f11, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu11, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g11, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u12, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f12, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu12, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g12, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u13, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f13, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu13, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g13, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u14, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f14, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu14, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g14, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u15, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f15, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu15, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g15, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u16, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f16, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu16, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g16, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u17, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f17, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu17, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g17, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_3(linflp_k18_Hxx18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_Hxu18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_2(linflp_k18_Huu18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f0x18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_2_1(linflp_k18_f0u18, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Gleichungsnebenbedingungen */
linflp_k18_norm_inf_3_3(linflp_k18_fx18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_2(linflp_k18_fu18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_3_1(linflp_k18_f18, linflp_k18_norm_d, linflp_k18_norm_d);
/* Aus Ungleichungsnebenbedingungen */
linflp_k18_norm_inf_10_3(linflp_k18_gx18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_2(linflp_k18_gu18, linflp_k18_norm_d, linflp_k18_norm_d);
linflp_k18_norm_inf_10_1(linflp_k18_g18, linflp_k18_norm_d, linflp_k18_norm_d);
}


/* ############################################################# */
/* Diese Funktion berechnet die Unendlichnorm der rechten Seiten */
/* ############################################################# */
static void linflp_k18_glqdocpip_calc_norm_r()
{
/* norm_r_prev bestimmen */
if(linflp_k18_iter > 0){
linflp_k18_v_copy_1(linflp_k18_norm_r, linflp_k18_norm_r_prev);
}
linflp_k18_v_init0_1(linflp_k18_norm_r);
/* Zeitschritt 0 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x0, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u0, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf0, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc0, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk0, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 1 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x1, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u1, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf1, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc1, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk1, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 2 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x2, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u2, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf2, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc2, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk2, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 3 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x3, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u3, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf3, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc3, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk3, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 4 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x4, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u4, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf4, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc4, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk4, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 5 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x5, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u5, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf5, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc5, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk5, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 6 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x6, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u6, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf6, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc6, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk6, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 7 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x7, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u7, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf7, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc7, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk7, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 8 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x8, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u8, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf8, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc8, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk8, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 9 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x9, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u9, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf9, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc9, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk9, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 10 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x10, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u10, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf10, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc10, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk10, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 11 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x11, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u11, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf11, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc11, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk11, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 12 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x12, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u12, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf12, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc12, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk12, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 13 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x13, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u13, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf13, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc13, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk13, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 14 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x14, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u14, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf14, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc14, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk14, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 15 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x15, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u15, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf15, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc15, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk15, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 16 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x16, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u16, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf16, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc16, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk16, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 17 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x17, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u17, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf17, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc17, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk17, linflp_k18_norm_r, linflp_k18_norm_r);
/* Zeitschritt 18 */
/* Aus G�tefunktion */
linflp_k18_norm_inf_3_1(linflp_k18_rf0x18, linflp_k18_norm_r, linflp_k18_norm_r);
linflp_k18_norm_inf_2_1(linflp_k18_rf0u18, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Gleichungsnebenbedingung */
linflp_k18_norm_inf_3_1(linflp_k18_rf18, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Ungleichungsnebenbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rc18, linflp_k18_norm_r, linflp_k18_norm_r);
/* Aus Komplementarit�tsbedingung */
linflp_k18_norm_inf_10_1(linflp_k18_rk18, linflp_k18_norm_r, linflp_k18_norm_r);
/* norm_r0 bestimmen */
if(linflp_k18_iter == 0){
linflp_k18_v_copy_1(linflp_k18_norm_r, linflp_k18_norm_r0);
}
}


/* ###################################### */
/* Diese Funktion f�hrt einen Schritt aus */
/* ###################################### */
static void linflp_k18_glqdocpip_step()
{
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx0, linflp_k18_x0);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du0, linflp_k18_u0);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp0, linflp_k18_p0);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy0, linflp_k18_y0);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu0, linflp_k18_nu0);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx1, linflp_k18_x1);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du1, linflp_k18_u1);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp1, linflp_k18_p1);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy1, linflp_k18_y1);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu1, linflp_k18_nu1);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx2, linflp_k18_x2);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du2, linflp_k18_u2);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp2, linflp_k18_p2);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy2, linflp_k18_y2);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu2, linflp_k18_nu2);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx3, linflp_k18_x3);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du3, linflp_k18_u3);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp3, linflp_k18_p3);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy3, linflp_k18_y3);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu3, linflp_k18_nu3);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx4, linflp_k18_x4);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du4, linflp_k18_u4);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp4, linflp_k18_p4);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy4, linflp_k18_y4);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu4, linflp_k18_nu4);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx5, linflp_k18_x5);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du5, linflp_k18_u5);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp5, linflp_k18_p5);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy5, linflp_k18_y5);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu5, linflp_k18_nu5);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx6, linflp_k18_x6);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du6, linflp_k18_u6);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp6, linflp_k18_p6);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy6, linflp_k18_y6);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu6, linflp_k18_nu6);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx7, linflp_k18_x7);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du7, linflp_k18_u7);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp7, linflp_k18_p7);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy7, linflp_k18_y7);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu7, linflp_k18_nu7);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx8, linflp_k18_x8);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du8, linflp_k18_u8);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp8, linflp_k18_p8);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy8, linflp_k18_y8);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu8, linflp_k18_nu8);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx9, linflp_k18_x9);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du9, linflp_k18_u9);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp9, linflp_k18_p9);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy9, linflp_k18_y9);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu9, linflp_k18_nu9);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx10, linflp_k18_x10);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du10, linflp_k18_u10);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp10, linflp_k18_p10);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy10, linflp_k18_y10);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu10, linflp_k18_nu10);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx11, linflp_k18_x11);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du11, linflp_k18_u11);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp11, linflp_k18_p11);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy11, linflp_k18_y11);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu11, linflp_k18_nu11);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx12, linflp_k18_x12);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du12, linflp_k18_u12);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp12, linflp_k18_p12);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy12, linflp_k18_y12);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu12, linflp_k18_nu12);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx13, linflp_k18_x13);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du13, linflp_k18_u13);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp13, linflp_k18_p13);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy13, linflp_k18_y13);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu13, linflp_k18_nu13);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx14, linflp_k18_x14);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du14, linflp_k18_u14);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp14, linflp_k18_p14);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy14, linflp_k18_y14);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu14, linflp_k18_nu14);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx15, linflp_k18_x15);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du15, linflp_k18_u15);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp15, linflp_k18_p15);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy15, linflp_k18_y15);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu15, linflp_k18_nu15);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx16, linflp_k18_x16);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du16, linflp_k18_u16);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp16, linflp_k18_p16);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy16, linflp_k18_y16);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu16, linflp_k18_nu16);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx17, linflp_k18_x17);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du17, linflp_k18_u17);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp17, linflp_k18_p17);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy17, linflp_k18_y17);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu17, linflp_k18_nu17);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dx18, linflp_k18_x18);
linflp_k18_sv_2(linflp_k18_mehrotra_alpha, linflp_k18_du18, linflp_k18_u18);
linflp_k18_sv_3(linflp_k18_mehrotra_alpha, linflp_k18_dp18, linflp_k18_p18);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dy18, linflp_k18_y18);
linflp_k18_sv_10(linflp_k18_mehrotra_alpha, linflp_k18_dnu18, linflp_k18_nu18);
}


/* ######################################################### */
/* Diese Funktion f�hrt Konvergenz- und Divergenztests durch */
/* ######################################################### */
static void linflp_k18_glqdocpip_check_condiv()
{
/* Termcode 0 - Success */
if(linflp_k18_mu[0] <= linflp_k18_tol[0]){
linflp_k18_vv_elemult_1(linflp_k18_tol, linflp_k18_norm_d, linflp_k18_tmp1_1);
  if(linflp_k18_norm_r[0] <= linflp_k18_tmp1_1[0]){
  linflp_k18_termcode = 0;
  return;
  }
}

/* Termcode 1 - infeasible */
if(linflp_k18_phi[0] > linflp_k18_tol[0]){
linflp_k18_vv_elemult_1(linflp_k18_tc1_factor, linflp_k18_minphi, linflp_k18_tmp1_1);
  if(linflp_k18_phi[0] >= linflp_k18_tmp1_1[0]){
  linflp_k18_termcode = 1;
  return;
  }
}

/* Termcode 2 - slow convergence */
linflp_k18_vv_elemult_1(linflp_k18_tol, linflp_k18_norm_d, linflp_k18_tmp1_1);
if(linflp_k18_norm_r[0] > linflp_k18_tmp1_1[0]){
linflp_k18_vv_elediv_1(linflp_k18_norm_r, linflp_k18_mu, linflp_k18_tmp1_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vv_elediv_1(linflp_k18_norm_r0, linflp_k18_mu0, linflp_k18_tmp2_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vv_elemult_1(linflp_k18_tc2_factor, linflp_k18_tmp2_1, linflp_k18_tmp2_1);
  if(linflp_k18_tmp1_1[0] >= linflp_k18_tmp2_1[0]){
  linflp_k18_termcode = 2;
  return;
  }
}

/* Termcode 7 - calculation time limit exceeded */
if(linflp_k18_iter > 0){
  if(linflp_k18_glqdocpip_timer_get()*(double)linflp_k18_iter/ (double) (linflp_k18_iter + 1) > linflp_k18_time_max){
    linflp_k18_termcode = 7;
    return;
  }
}

/* iterative refinement */
/* ### FLAGS ### */
/* # keep_iterative_refinements_on = 0 */
/* # iterative_refinements_require_norm_r_is_not_too_small = 0 */
/* ############# */
linflp_k18_iter_ref = 0;
if(linflp_k18_iter > 0){
linflp_k18_tmp1_1[0] = 100;
linflp_k18_vv_elemult_1(linflp_k18_tmp1_1, linflp_k18_tol, linflp_k18_tmp2_1);
linflp_k18_vv_elemult_1(linflp_k18_norm_d, linflp_k18_tmp2_1, linflp_k18_tmp2_1);
if(linflp_k18_norm_r_prev[0] > linflp_k18_tmp2_1[0]){
linflp_k18_tmp1_1[0] = 1.001;
linflp_k18_vv_elemult_1(linflp_k18_tmp1_1, linflp_k18_norm_r_prev, linflp_k18_tmp2_1);
if(linflp_k18_norm_r[0] > linflp_k18_tmp2_1[0]){
linflp_k18_iter_ref = 1;
}
}
}

}


/* ################################################ */
/* Diese Funktion speichert Daten f�r die Statistik */
/* ################################################ */
static void linflp_k18_glqdocpip_stat()
{
/* Zeit */
linflp_k18_stat_time[linflp_k18_iter] = linflp_k18_glqdocpip_timer_get();
}


static void linflp_k18_glqdocpip_factor()
{
linflp_k18_error_source = 1;
linflp_k18_stat_num_factor++;
/* Factor: R�ckw�rtsiteration */
/* Zeitschritt 18 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx18, linflp_k18_Gxx18);
linflp_k18_m_copy_3_2(linflp_k18_Hxu18, linflp_k18_Gxu18);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid53_sid17_10_3(linflp_k18_gx18, linflp_k18_yny18, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid14_sid53_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx18, linflp_k18_Gxx18);
linflp_k18_mm_sid14_sid56_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu18, linflp_k18_Gxu18);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu18, linflp_k18_Guu18);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid56_sid17_10_2(linflp_k18_gu18, linflp_k18_yny18, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu18, linflp_k18_Guu18);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu18, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu18, linflp_k18_L18);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L18, linflp_k18_tmp1_2_3, linflp_k18_Rux18);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx18);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu18, linflp_k18_Rux18, linflp_k18_Vxx18);
linflp_k18_msub_3_3(linflp_k18_Gxx18, linflp_k18_Vxx18, linflp_k18_Vxx18);
/* Zeitschritt 17 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx17, linflp_k18_Gxx17);
linflp_k18_m_copy_3_2(linflp_k18_Hxu17, linflp_k18_Gxu17);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx17, linflp_k18_Vxx18, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx17, linflp_k18_Gxx17);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu17, linflp_k18_Gxu17);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx17, linflp_k18_yny17, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx17, linflp_k18_Gxx17);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu17, linflp_k18_Gxu17);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu17, linflp_k18_Guu17);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu17, linflp_k18_Vxx18, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu17, linflp_k18_Guu17);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu17, linflp_k18_yny17, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu17, linflp_k18_Guu17);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu17, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu17, linflp_k18_L17);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L17, linflp_k18_tmp1_2_3, linflp_k18_Rux17);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx17);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu17, linflp_k18_Rux17, linflp_k18_Vxx17);
linflp_k18_msub_3_3(linflp_k18_Gxx17, linflp_k18_Vxx17, linflp_k18_Vxx17);
/* Zeitschritt 16 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx16, linflp_k18_Gxx16);
linflp_k18_m_copy_3_2(linflp_k18_Hxu16, linflp_k18_Gxu16);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx16, linflp_k18_Vxx17, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx16, linflp_k18_Gxx16);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu16, linflp_k18_Gxu16);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx16, linflp_k18_yny16, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx16, linflp_k18_Gxx16);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu16, linflp_k18_Gxu16);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu16, linflp_k18_Guu16);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu16, linflp_k18_Vxx17, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu16, linflp_k18_Guu16);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu16, linflp_k18_yny16, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu16, linflp_k18_Guu16);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu16, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu16, linflp_k18_L16);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L16, linflp_k18_tmp1_2_3, linflp_k18_Rux16);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx16);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu16, linflp_k18_Rux16, linflp_k18_Vxx16);
linflp_k18_msub_3_3(linflp_k18_Gxx16, linflp_k18_Vxx16, linflp_k18_Vxx16);
/* Zeitschritt 15 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx15, linflp_k18_Gxx15);
linflp_k18_m_copy_3_2(linflp_k18_Hxu15, linflp_k18_Gxu15);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx15, linflp_k18_Vxx16, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx15, linflp_k18_Gxx15);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu15, linflp_k18_Gxu15);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx15, linflp_k18_yny15, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx15, linflp_k18_Gxx15);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu15, linflp_k18_Gxu15);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu15, linflp_k18_Guu15);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu15, linflp_k18_Vxx16, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu15, linflp_k18_Guu15);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu15, linflp_k18_yny15, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu15, linflp_k18_Guu15);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu15, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu15, linflp_k18_L15);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L15, linflp_k18_tmp1_2_3, linflp_k18_Rux15);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx15);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu15, linflp_k18_Rux15, linflp_k18_Vxx15);
linflp_k18_msub_3_3(linflp_k18_Gxx15, linflp_k18_Vxx15, linflp_k18_Vxx15);
/* Zeitschritt 14 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx14, linflp_k18_Gxx14);
linflp_k18_m_copy_3_2(linflp_k18_Hxu14, linflp_k18_Gxu14);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx14, linflp_k18_Vxx15, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx14, linflp_k18_Gxx14);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu14, linflp_k18_Gxu14);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx14, linflp_k18_yny14, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx14, linflp_k18_Gxx14);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu14, linflp_k18_Gxu14);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu14, linflp_k18_Guu14);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu14, linflp_k18_Vxx15, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu14, linflp_k18_Guu14);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu14, linflp_k18_yny14, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu14, linflp_k18_Guu14);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu14, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu14, linflp_k18_L14);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L14, linflp_k18_tmp1_2_3, linflp_k18_Rux14);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx14);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu14, linflp_k18_Rux14, linflp_k18_Vxx14);
linflp_k18_msub_3_3(linflp_k18_Gxx14, linflp_k18_Vxx14, linflp_k18_Vxx14);
/* Zeitschritt 13 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx13, linflp_k18_Gxx13);
linflp_k18_m_copy_3_2(linflp_k18_Hxu13, linflp_k18_Gxu13);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx13, linflp_k18_Vxx14, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx13, linflp_k18_Gxx13);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu13, linflp_k18_Gxu13);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx13, linflp_k18_yny13, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx13, linflp_k18_Gxx13);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu13, linflp_k18_Gxu13);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu13, linflp_k18_Guu13);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu13, linflp_k18_Vxx14, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu13, linflp_k18_Guu13);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu13, linflp_k18_yny13, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu13, linflp_k18_Guu13);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu13, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu13, linflp_k18_L13);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L13, linflp_k18_tmp1_2_3, linflp_k18_Rux13);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx13);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu13, linflp_k18_Rux13, linflp_k18_Vxx13);
linflp_k18_msub_3_3(linflp_k18_Gxx13, linflp_k18_Vxx13, linflp_k18_Vxx13);
/* Zeitschritt 12 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx12, linflp_k18_Gxx12);
linflp_k18_m_copy_3_2(linflp_k18_Hxu12, linflp_k18_Gxu12);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx12, linflp_k18_Vxx13, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx12, linflp_k18_Gxx12);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu12, linflp_k18_Gxu12);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx12, linflp_k18_yny12, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx12, linflp_k18_Gxx12);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu12, linflp_k18_Gxu12);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu12, linflp_k18_Guu12);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu12, linflp_k18_Vxx13, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu12, linflp_k18_Guu12);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu12, linflp_k18_yny12, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu12, linflp_k18_Guu12);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu12, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu12, linflp_k18_L12);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L12, linflp_k18_tmp1_2_3, linflp_k18_Rux12);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx12);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu12, linflp_k18_Rux12, linflp_k18_Vxx12);
linflp_k18_msub_3_3(linflp_k18_Gxx12, linflp_k18_Vxx12, linflp_k18_Vxx12);
/* Zeitschritt 11 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx11, linflp_k18_Gxx11);
linflp_k18_m_copy_3_2(linflp_k18_Hxu11, linflp_k18_Gxu11);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx11, linflp_k18_Vxx12, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx11, linflp_k18_Gxx11);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu11, linflp_k18_Gxu11);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx11, linflp_k18_yny11, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx11, linflp_k18_Gxx11);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu11, linflp_k18_Gxu11);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu11, linflp_k18_Guu11);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu11, linflp_k18_Vxx12, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu11, linflp_k18_Guu11);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu11, linflp_k18_yny11, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu11, linflp_k18_Guu11);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu11, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu11, linflp_k18_L11);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L11, linflp_k18_tmp1_2_3, linflp_k18_Rux11);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx11);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu11, linflp_k18_Rux11, linflp_k18_Vxx11);
linflp_k18_msub_3_3(linflp_k18_Gxx11, linflp_k18_Vxx11, linflp_k18_Vxx11);
/* Zeitschritt 10 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx10, linflp_k18_Gxx10);
linflp_k18_m_copy_3_2(linflp_k18_Hxu10, linflp_k18_Gxu10);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx10, linflp_k18_Vxx11, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx10, linflp_k18_Gxx10);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu10, linflp_k18_Gxu10);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx10, linflp_k18_yny10, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx10, linflp_k18_Gxx10);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu10, linflp_k18_Gxu10);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu10, linflp_k18_Guu10);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu10, linflp_k18_Vxx11, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu10, linflp_k18_Guu10);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu10, linflp_k18_yny10, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu10, linflp_k18_Guu10);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu10, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu10, linflp_k18_L10);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L10, linflp_k18_tmp1_2_3, linflp_k18_Rux10);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx10);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu10, linflp_k18_Rux10, linflp_k18_Vxx10);
linflp_k18_msub_3_3(linflp_k18_Gxx10, linflp_k18_Vxx10, linflp_k18_Vxx10);
/* Zeitschritt 9 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx9, linflp_k18_Gxx9);
linflp_k18_m_copy_3_2(linflp_k18_Hxu9, linflp_k18_Gxu9);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx9, linflp_k18_Vxx10, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx9, linflp_k18_Gxx9);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu9, linflp_k18_Gxu9);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx9, linflp_k18_yny9, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx9, linflp_k18_Gxx9);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu9, linflp_k18_Gxu9);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu9, linflp_k18_Guu9);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu9, linflp_k18_Vxx10, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu9, linflp_k18_Guu9);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu9, linflp_k18_yny9, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu9, linflp_k18_Guu9);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu9, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu9, linflp_k18_L9);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L9, linflp_k18_tmp1_2_3, linflp_k18_Rux9);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx9);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu9, linflp_k18_Rux9, linflp_k18_Vxx9);
linflp_k18_msub_3_3(linflp_k18_Gxx9, linflp_k18_Vxx9, linflp_k18_Vxx9);
/* Zeitschritt 8 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx8, linflp_k18_Gxx8);
linflp_k18_m_copy_3_2(linflp_k18_Hxu8, linflp_k18_Gxu8);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx8, linflp_k18_Vxx9, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx8, linflp_k18_Gxx8);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu8, linflp_k18_Gxu8);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx8, linflp_k18_yny8, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx8, linflp_k18_Gxx8);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu8, linflp_k18_Gxu8);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu8, linflp_k18_Guu8);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu8, linflp_k18_Vxx9, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu8, linflp_k18_Guu8);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu8, linflp_k18_yny8, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu8, linflp_k18_Guu8);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu8, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu8, linflp_k18_L8);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L8, linflp_k18_tmp1_2_3, linflp_k18_Rux8);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx8);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu8, linflp_k18_Rux8, linflp_k18_Vxx8);
linflp_k18_msub_3_3(linflp_k18_Gxx8, linflp_k18_Vxx8, linflp_k18_Vxx8);
/* Zeitschritt 7 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx7, linflp_k18_Gxx7);
linflp_k18_m_copy_3_2(linflp_k18_Hxu7, linflp_k18_Gxu7);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx7, linflp_k18_Vxx8, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx7, linflp_k18_Gxx7);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu7, linflp_k18_Gxu7);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx7, linflp_k18_yny7, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx7, linflp_k18_Gxx7);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu7, linflp_k18_Gxu7);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu7, linflp_k18_Guu7);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu7, linflp_k18_Vxx8, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu7, linflp_k18_Guu7);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu7, linflp_k18_yny7, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu7, linflp_k18_Guu7);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu7, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu7, linflp_k18_L7);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L7, linflp_k18_tmp1_2_3, linflp_k18_Rux7);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx7);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu7, linflp_k18_Rux7, linflp_k18_Vxx7);
linflp_k18_msub_3_3(linflp_k18_Gxx7, linflp_k18_Vxx7, linflp_k18_Vxx7);
/* Zeitschritt 6 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx6, linflp_k18_Gxx6);
linflp_k18_m_copy_3_2(linflp_k18_Hxu6, linflp_k18_Gxu6);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx6, linflp_k18_Vxx7, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx6, linflp_k18_Gxx6);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu6, linflp_k18_Gxu6);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx6, linflp_k18_yny6, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx6, linflp_k18_Gxx6);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu6, linflp_k18_Gxu6);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu6, linflp_k18_Guu6);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu6, linflp_k18_Vxx7, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu6, linflp_k18_Guu6);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu6, linflp_k18_yny6, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu6, linflp_k18_Guu6);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu6, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu6, linflp_k18_L6);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L6, linflp_k18_tmp1_2_3, linflp_k18_Rux6);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx6);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu6, linflp_k18_Rux6, linflp_k18_Vxx6);
linflp_k18_msub_3_3(linflp_k18_Gxx6, linflp_k18_Vxx6, linflp_k18_Vxx6);
/* Zeitschritt 5 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx5, linflp_k18_Gxx5);
linflp_k18_m_copy_3_2(linflp_k18_Hxu5, linflp_k18_Gxu5);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx5, linflp_k18_Vxx6, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx5, linflp_k18_Gxx5);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu5, linflp_k18_Gxu5);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx5, linflp_k18_yny5, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx5, linflp_k18_Gxx5);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu5, linflp_k18_Gxu5);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu5, linflp_k18_Guu5);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu5, linflp_k18_Vxx6, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu5, linflp_k18_Guu5);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu5, linflp_k18_yny5, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu5, linflp_k18_Guu5);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu5, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu5, linflp_k18_L5);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L5, linflp_k18_tmp1_2_3, linflp_k18_Rux5);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx5);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu5, linflp_k18_Rux5, linflp_k18_Vxx5);
linflp_k18_msub_3_3(linflp_k18_Gxx5, linflp_k18_Vxx5, linflp_k18_Vxx5);
/* Zeitschritt 4 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx4, linflp_k18_Gxx4);
linflp_k18_m_copy_3_2(linflp_k18_Hxu4, linflp_k18_Gxu4);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx4, linflp_k18_Vxx5, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx4, linflp_k18_Gxx4);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu4, linflp_k18_Gxu4);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx4, linflp_k18_yny4, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx4, linflp_k18_Gxx4);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu4, linflp_k18_Gxu4);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu4, linflp_k18_Guu4);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu4, linflp_k18_Vxx5, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu4, linflp_k18_Guu4);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu4, linflp_k18_yny4, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu4, linflp_k18_Guu4);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu4, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu4, linflp_k18_L4);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L4, linflp_k18_tmp1_2_3, linflp_k18_Rux4);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx4);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu4, linflp_k18_Rux4, linflp_k18_Vxx4);
linflp_k18_msub_3_3(linflp_k18_Gxx4, linflp_k18_Vxx4, linflp_k18_Vxx4);
/* Zeitschritt 3 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx3, linflp_k18_Gxx3);
linflp_k18_m_copy_3_2(linflp_k18_Hxu3, linflp_k18_Gxu3);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx3, linflp_k18_Vxx4, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx3, linflp_k18_Gxx3);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu3, linflp_k18_Gxu3);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx3, linflp_k18_yny3, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx3, linflp_k18_Gxx3);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu3, linflp_k18_Gxu3);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu3, linflp_k18_Guu3);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu3, linflp_k18_Vxx4, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu3, linflp_k18_Guu3);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu3, linflp_k18_yny3, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu3, linflp_k18_Guu3);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu3, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu3, linflp_k18_L3);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L3, linflp_k18_tmp1_2_3, linflp_k18_Rux3);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx3);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu3, linflp_k18_Rux3, linflp_k18_Vxx3);
linflp_k18_msub_3_3(linflp_k18_Gxx3, linflp_k18_Vxx3, linflp_k18_Vxx3);
/* Zeitschritt 2 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx2, linflp_k18_Gxx2);
linflp_k18_m_copy_3_2(linflp_k18_Hxu2, linflp_k18_Gxu2);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx2, linflp_k18_Vxx3, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx2, linflp_k18_Gxx2);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu2, linflp_k18_Gxu2);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx2, linflp_k18_yny2, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx2, linflp_k18_Gxx2);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu2, linflp_k18_Gxu2);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu2, linflp_k18_Guu2);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu2, linflp_k18_Vxx3, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu2, linflp_k18_Guu2);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu2, linflp_k18_yny2, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu2, linflp_k18_Guu2);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu2, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu2, linflp_k18_L2);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L2, linflp_k18_tmp1_2_3, linflp_k18_Rux2);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx2);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu2, linflp_k18_Rux2, linflp_k18_Vxx2);
linflp_k18_msub_3_3(linflp_k18_Gxx2, linflp_k18_Vxx2, linflp_k18_Vxx2);
/* Zeitschritt 1 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx1, linflp_k18_Gxx1);
linflp_k18_m_copy_3_2(linflp_k18_Hxu1, linflp_k18_Gxu1);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid43_sid1_3_3_3(linflp_k18_fx1, linflp_k18_Vxx2, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid43_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx1, linflp_k18_Gxx1);
linflp_k18_mm_sid1_sid46_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu1, linflp_k18_Gxu1);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid52_sid16_10_3(linflp_k18_gx1, linflp_k18_yny1, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid13_sid52_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx1, linflp_k18_Gxx1);
linflp_k18_mm_sid13_sid55_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu1, linflp_k18_Gxu1);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu1, linflp_k18_Guu1);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid46_sid1_3_2_3(linflp_k18_fu1, linflp_k18_Vxx2, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid46_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu1, linflp_k18_Guu1);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid55_sid16_10_2(linflp_k18_gu1, linflp_k18_yny1, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu1, linflp_k18_Guu1);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu1, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu1, linflp_k18_L1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L1, linflp_k18_tmp1_2_3, linflp_k18_Rux1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx1);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu1, linflp_k18_Rux1, linflp_k18_Vxx1);
linflp_k18_msub_3_3(linflp_k18_Gxx1, linflp_k18_Vxx1, linflp_k18_Vxx1);
/* Zeitschritt 0 */
/* Gxx und Gxu */
linflp_k18_m_copy_3_3(linflp_k18_Hxx0, linflp_k18_Gxx0);
linflp_k18_m_copy_3_2(linflp_k18_Hxu0, linflp_k18_Gxu0);
linflp_k18_m_init0_3_3(linflp_k18_tmp1_3_3);
linflp_k18_mtm_sid42_sid1_3_3_3(linflp_k18_fx0, linflp_k18_Vxx1, linflp_k18_tmp1_3_3);
linflp_k18_mm_y_sid1_sid42_3_3_3(linflp_k18_tmp1_3_3, linflp_k18_fx0, linflp_k18_Gxx0);
linflp_k18_mm_sid1_sid45_3_3_2(linflp_k18_tmp1_3_3, linflp_k18_fu0, linflp_k18_Gxu0);
linflp_k18_m_init0_3_10(linflp_k18_tmp1_3_10);
linflp_k18_mtd_sid51_sid15_10_3(linflp_k18_gx0, linflp_k18_yny0, linflp_k18_tmp1_3_10);
linflp_k18_mm_y_sid12_sid51_3_10_3(linflp_k18_tmp1_3_10, linflp_k18_gx0, linflp_k18_Gxx0);
linflp_k18_mm_sid12_sid54_3_10_2(linflp_k18_tmp1_3_10, linflp_k18_gu0, linflp_k18_Gxu0);
/* Guu */
linflp_k18_m_copy_2_2(linflp_k18_Huu0, linflp_k18_Guu0);
linflp_k18_m_init0_2_3(linflp_k18_tmp1_2_3);
linflp_k18_mtm_sid45_sid1_3_2_3(linflp_k18_fu0, linflp_k18_Vxx1, linflp_k18_tmp1_2_3);
linflp_k18_mm_sid8_sid45_2_3_2(linflp_k18_tmp1_2_3, linflp_k18_fu0, linflp_k18_Guu0);
linflp_k18_m_init0_2_10(linflp_k18_tmp1_2_10);
linflp_k18_mtd_sid54_sid15_10_2(linflp_k18_gu0, linflp_k18_yny0, linflp_k18_tmp1_2_10);
linflp_k18_mm_2_10_2(linflp_k18_tmp1_2_10, linflp_k18_gu0, linflp_k18_Guu0);
/* Rux */
linflp_k18_mtr_3_2(linflp_k18_Gxu0, linflp_k18_tmp1_2_3);
linflp_k18_chol_factor_2(linflp_k18_Guu0, linflp_k18_L0);
if(linflp_k18_termcode > -1){return;}
linflp_k18_chol_solve_2_3(linflp_k18_L0, linflp_k18_tmp1_2_3, linflp_k18_Rux0);
if(linflp_k18_termcode > -1){return;}
linflp_k18_m_init0_3_3(linflp_k18_Vxx0);
linflp_k18_mm_y_3_2_3(linflp_k18_Gxu0, linflp_k18_Rux0, linflp_k18_Vxx0);
linflp_k18_msub_3_3(linflp_k18_Gxx0, linflp_k18_Vxx0, linflp_k18_Vxx0);
linflp_k18_error_source = 0;

}


static void linflp_k18_glqdocpip_solve()
{
linflp_k18_error_source = 2;
linflp_k18_stat_num_solve++;
/* Solve: R�ckw�rtsiteration */
/* Zeitschritt 18 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x18, linflp_k18_Gx18);
linflp_k18_v_copy_2(linflp_k18_rrf0u18, linflp_k18_Gu18);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L18, linflp_k18_Gu18, linflp_k18_Ru18);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu18, linflp_k18_Ru18, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx18, linflp_k18_tmp1_3, linflp_k18_Vx18);
/* Zeitschritt 17 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x17, linflp_k18_Gx17);
linflp_k18_v_copy_2(linflp_k18_rrf0u17, linflp_k18_Gu17);
linflp_k18_v_copy_3(linflp_k18_Vx18, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx18, linflp_k18_rf18, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx17, linflp_k18_tmp1_3, linflp_k18_Gx17);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu17, linflp_k18_tmp1_3, linflp_k18_Gu17);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L17, linflp_k18_Gu17, linflp_k18_Ru17);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu17, linflp_k18_Ru17, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx17, linflp_k18_tmp1_3, linflp_k18_Vx17);
/* Zeitschritt 16 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x16, linflp_k18_Gx16);
linflp_k18_v_copy_2(linflp_k18_rrf0u16, linflp_k18_Gu16);
linflp_k18_v_copy_3(linflp_k18_Vx17, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx17, linflp_k18_rf17, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_tmp1_3, linflp_k18_Gx16);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu16, linflp_k18_tmp1_3, linflp_k18_Gu16);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L16, linflp_k18_Gu16, linflp_k18_Ru16);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu16, linflp_k18_Ru16, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx16, linflp_k18_tmp1_3, linflp_k18_Vx16);
/* Zeitschritt 15 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x15, linflp_k18_Gx15);
linflp_k18_v_copy_2(linflp_k18_rrf0u15, linflp_k18_Gu15);
linflp_k18_v_copy_3(linflp_k18_Vx16, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx16, linflp_k18_rf16, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_tmp1_3, linflp_k18_Gx15);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu15, linflp_k18_tmp1_3, linflp_k18_Gu15);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L15, linflp_k18_Gu15, linflp_k18_Ru15);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu15, linflp_k18_Ru15, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx15, linflp_k18_tmp1_3, linflp_k18_Vx15);
/* Zeitschritt 14 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x14, linflp_k18_Gx14);
linflp_k18_v_copy_2(linflp_k18_rrf0u14, linflp_k18_Gu14);
linflp_k18_v_copy_3(linflp_k18_Vx15, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx15, linflp_k18_rf15, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_tmp1_3, linflp_k18_Gx14);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu14, linflp_k18_tmp1_3, linflp_k18_Gu14);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L14, linflp_k18_Gu14, linflp_k18_Ru14);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu14, linflp_k18_Ru14, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx14, linflp_k18_tmp1_3, linflp_k18_Vx14);
/* Zeitschritt 13 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x13, linflp_k18_Gx13);
linflp_k18_v_copy_2(linflp_k18_rrf0u13, linflp_k18_Gu13);
linflp_k18_v_copy_3(linflp_k18_Vx14, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx14, linflp_k18_rf14, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_tmp1_3, linflp_k18_Gx13);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu13, linflp_k18_tmp1_3, linflp_k18_Gu13);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L13, linflp_k18_Gu13, linflp_k18_Ru13);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu13, linflp_k18_Ru13, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx13, linflp_k18_tmp1_3, linflp_k18_Vx13);
/* Zeitschritt 12 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x12, linflp_k18_Gx12);
linflp_k18_v_copy_2(linflp_k18_rrf0u12, linflp_k18_Gu12);
linflp_k18_v_copy_3(linflp_k18_Vx13, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx13, linflp_k18_rf13, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_tmp1_3, linflp_k18_Gx12);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu12, linflp_k18_tmp1_3, linflp_k18_Gu12);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L12, linflp_k18_Gu12, linflp_k18_Ru12);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu12, linflp_k18_Ru12, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx12, linflp_k18_tmp1_3, linflp_k18_Vx12);
/* Zeitschritt 11 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x11, linflp_k18_Gx11);
linflp_k18_v_copy_2(linflp_k18_rrf0u11, linflp_k18_Gu11);
linflp_k18_v_copy_3(linflp_k18_Vx12, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx12, linflp_k18_rf12, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_tmp1_3, linflp_k18_Gx11);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu11, linflp_k18_tmp1_3, linflp_k18_Gu11);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L11, linflp_k18_Gu11, linflp_k18_Ru11);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu11, linflp_k18_Ru11, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx11, linflp_k18_tmp1_3, linflp_k18_Vx11);
/* Zeitschritt 10 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x10, linflp_k18_Gx10);
linflp_k18_v_copy_2(linflp_k18_rrf0u10, linflp_k18_Gu10);
linflp_k18_v_copy_3(linflp_k18_Vx11, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx11, linflp_k18_rf11, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_tmp1_3, linflp_k18_Gx10);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu10, linflp_k18_tmp1_3, linflp_k18_Gu10);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L10, linflp_k18_Gu10, linflp_k18_Ru10);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu10, linflp_k18_Ru10, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx10, linflp_k18_tmp1_3, linflp_k18_Vx10);
/* Zeitschritt 9 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x9, linflp_k18_Gx9);
linflp_k18_v_copy_2(linflp_k18_rrf0u9, linflp_k18_Gu9);
linflp_k18_v_copy_3(linflp_k18_Vx10, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx10, linflp_k18_rf10, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_tmp1_3, linflp_k18_Gx9);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu9, linflp_k18_tmp1_3, linflp_k18_Gu9);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L9, linflp_k18_Gu9, linflp_k18_Ru9);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu9, linflp_k18_Ru9, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx9, linflp_k18_tmp1_3, linflp_k18_Vx9);
/* Zeitschritt 8 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x8, linflp_k18_Gx8);
linflp_k18_v_copy_2(linflp_k18_rrf0u8, linflp_k18_Gu8);
linflp_k18_v_copy_3(linflp_k18_Vx9, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx9, linflp_k18_rf9, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_tmp1_3, linflp_k18_Gx8);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu8, linflp_k18_tmp1_3, linflp_k18_Gu8);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L8, linflp_k18_Gu8, linflp_k18_Ru8);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu8, linflp_k18_Ru8, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx8, linflp_k18_tmp1_3, linflp_k18_Vx8);
/* Zeitschritt 7 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x7, linflp_k18_Gx7);
linflp_k18_v_copy_2(linflp_k18_rrf0u7, linflp_k18_Gu7);
linflp_k18_v_copy_3(linflp_k18_Vx8, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx8, linflp_k18_rf8, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_tmp1_3, linflp_k18_Gx7);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu7, linflp_k18_tmp1_3, linflp_k18_Gu7);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L7, linflp_k18_Gu7, linflp_k18_Ru7);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu7, linflp_k18_Ru7, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx7, linflp_k18_tmp1_3, linflp_k18_Vx7);
/* Zeitschritt 6 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x6, linflp_k18_Gx6);
linflp_k18_v_copy_2(linflp_k18_rrf0u6, linflp_k18_Gu6);
linflp_k18_v_copy_3(linflp_k18_Vx7, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx7, linflp_k18_rf7, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_tmp1_3, linflp_k18_Gx6);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu6, linflp_k18_tmp1_3, linflp_k18_Gu6);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L6, linflp_k18_Gu6, linflp_k18_Ru6);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu6, linflp_k18_Ru6, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx6, linflp_k18_tmp1_3, linflp_k18_Vx6);
/* Zeitschritt 5 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x5, linflp_k18_Gx5);
linflp_k18_v_copy_2(linflp_k18_rrf0u5, linflp_k18_Gu5);
linflp_k18_v_copy_3(linflp_k18_Vx6, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx6, linflp_k18_rf6, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_tmp1_3, linflp_k18_Gx5);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu5, linflp_k18_tmp1_3, linflp_k18_Gu5);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L5, linflp_k18_Gu5, linflp_k18_Ru5);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu5, linflp_k18_Ru5, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx5, linflp_k18_tmp1_3, linflp_k18_Vx5);
/* Zeitschritt 4 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x4, linflp_k18_Gx4);
linflp_k18_v_copy_2(linflp_k18_rrf0u4, linflp_k18_Gu4);
linflp_k18_v_copy_3(linflp_k18_Vx5, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx5, linflp_k18_rf5, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_tmp1_3, linflp_k18_Gx4);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu4, linflp_k18_tmp1_3, linflp_k18_Gu4);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L4, linflp_k18_Gu4, linflp_k18_Ru4);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu4, linflp_k18_Ru4, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx4, linflp_k18_tmp1_3, linflp_k18_Vx4);
/* Zeitschritt 3 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x3, linflp_k18_Gx3);
linflp_k18_v_copy_2(linflp_k18_rrf0u3, linflp_k18_Gu3);
linflp_k18_v_copy_3(linflp_k18_Vx4, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx4, linflp_k18_rf4, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_tmp1_3, linflp_k18_Gx3);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu3, linflp_k18_tmp1_3, linflp_k18_Gu3);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L3, linflp_k18_Gu3, linflp_k18_Ru3);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu3, linflp_k18_Ru3, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx3, linflp_k18_tmp1_3, linflp_k18_Vx3);
/* Zeitschritt 2 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x2, linflp_k18_Gx2);
linflp_k18_v_copy_2(linflp_k18_rrf0u2, linflp_k18_Gu2);
linflp_k18_v_copy_3(linflp_k18_Vx3, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx3, linflp_k18_rf3, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_tmp1_3, linflp_k18_Gx2);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu2, linflp_k18_tmp1_3, linflp_k18_Gu2);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L2, linflp_k18_Gu2, linflp_k18_Ru2);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu2, linflp_k18_Ru2, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx2, linflp_k18_tmp1_3, linflp_k18_Vx2);
/* Zeitschritt 1 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x1, linflp_k18_Gx1);
linflp_k18_v_copy_2(linflp_k18_rrf0u1, linflp_k18_Gu1);
linflp_k18_v_copy_3(linflp_k18_Vx2, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx2, linflp_k18_rf2, linflp_k18_tmp1_3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_tmp1_3, linflp_k18_Gx1);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu1, linflp_k18_tmp1_3, linflp_k18_Gu1);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L1, linflp_k18_Gu1, linflp_k18_Ru1);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu1, linflp_k18_Ru1, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx1, linflp_k18_tmp1_3, linflp_k18_Vx1);
/* Zeitschritt 0 */
/* Gx und Gu */
linflp_k18_v_copy_3(linflp_k18_rrf0x0, linflp_k18_Gx0);
linflp_k18_v_copy_2(linflp_k18_rrf0u0, linflp_k18_Gu0);
linflp_k18_v_copy_3(linflp_k18_Vx1, linflp_k18_tmp1_3);
linflp_k18_mv_3_3(linflp_k18_Vxx1, linflp_k18_rf1, linflp_k18_tmp1_3);
linflp_k18_mtv_sid42_sid2_3_3(linflp_k18_fx0, linflp_k18_tmp1_3, linflp_k18_Gx0);
linflp_k18_mtv_sid45_sid2_3_2(linflp_k18_fu0, linflp_k18_tmp1_3, linflp_k18_Gu0);
/* Ru */
linflp_k18_chol_solve_2_1(linflp_k18_L0, linflp_k18_Gu0, linflp_k18_Ru0);
if(linflp_k18_termcode > -1){return;}
/* Vx */
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_v_init0_3(linflp_k18_tmp1_3);
linflp_k18_mv_3_2(linflp_k18_Gxu0, linflp_k18_Ru0, linflp_k18_tmp1_3);
linflp_k18_vsub_3(linflp_k18_Gx0, linflp_k18_tmp1_3, linflp_k18_Vx0);
/* Solve: Vorw�rtsiteration */
/* dx0 */
linflp_k18_v_copy_3(linflp_k18_rf0, linflp_k18_dx0);
/* Zeitschritt 0 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx0, linflp_k18_dp0);
linflp_k18_mv_3_3(linflp_k18_Vxx0, linflp_k18_dx0, linflp_k18_dp0);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru0, linflp_k18_du0);
linflp_k18_mv_2_3(linflp_k18_Rux0, linflp_k18_dx0, linflp_k18_du0);
linflp_k18_v_turnsign_2(linflp_k18_du0, linflp_k18_du0);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf1, linflp_k18_dx1);
linflp_k18_mv_sid42_sid2_3_3(linflp_k18_fx0, linflp_k18_dx0, linflp_k18_dx1);
linflp_k18_mv_sid45_sid5_3_2(linflp_k18_fu0, linflp_k18_du0, linflp_k18_dx1);
/* Zeitschritt 1 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx1, linflp_k18_dp1);
linflp_k18_mv_3_3(linflp_k18_Vxx1, linflp_k18_dx1, linflp_k18_dp1);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru1, linflp_k18_du1);
linflp_k18_mv_2_3(linflp_k18_Rux1, linflp_k18_dx1, linflp_k18_du1);
linflp_k18_v_turnsign_2(linflp_k18_du1, linflp_k18_du1);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf2, linflp_k18_dx2);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_dx1, linflp_k18_dx2);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu1, linflp_k18_du1, linflp_k18_dx2);
/* Zeitschritt 2 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx2, linflp_k18_dp2);
linflp_k18_mv_3_3(linflp_k18_Vxx2, linflp_k18_dx2, linflp_k18_dp2);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru2, linflp_k18_du2);
linflp_k18_mv_2_3(linflp_k18_Rux2, linflp_k18_dx2, linflp_k18_du2);
linflp_k18_v_turnsign_2(linflp_k18_du2, linflp_k18_du2);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf3, linflp_k18_dx3);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_dx2, linflp_k18_dx3);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu2, linflp_k18_du2, linflp_k18_dx3);
/* Zeitschritt 3 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx3, linflp_k18_dp3);
linflp_k18_mv_3_3(linflp_k18_Vxx3, linflp_k18_dx3, linflp_k18_dp3);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru3, linflp_k18_du3);
linflp_k18_mv_2_3(linflp_k18_Rux3, linflp_k18_dx3, linflp_k18_du3);
linflp_k18_v_turnsign_2(linflp_k18_du3, linflp_k18_du3);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf4, linflp_k18_dx4);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_dx3, linflp_k18_dx4);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu3, linflp_k18_du3, linflp_k18_dx4);
/* Zeitschritt 4 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx4, linflp_k18_dp4);
linflp_k18_mv_3_3(linflp_k18_Vxx4, linflp_k18_dx4, linflp_k18_dp4);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru4, linflp_k18_du4);
linflp_k18_mv_2_3(linflp_k18_Rux4, linflp_k18_dx4, linflp_k18_du4);
linflp_k18_v_turnsign_2(linflp_k18_du4, linflp_k18_du4);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf5, linflp_k18_dx5);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_dx4, linflp_k18_dx5);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu4, linflp_k18_du4, linflp_k18_dx5);
/* Zeitschritt 5 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx5, linflp_k18_dp5);
linflp_k18_mv_3_3(linflp_k18_Vxx5, linflp_k18_dx5, linflp_k18_dp5);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru5, linflp_k18_du5);
linflp_k18_mv_2_3(linflp_k18_Rux5, linflp_k18_dx5, linflp_k18_du5);
linflp_k18_v_turnsign_2(linflp_k18_du5, linflp_k18_du5);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf6, linflp_k18_dx6);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_dx5, linflp_k18_dx6);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu5, linflp_k18_du5, linflp_k18_dx6);
/* Zeitschritt 6 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx6, linflp_k18_dp6);
linflp_k18_mv_3_3(linflp_k18_Vxx6, linflp_k18_dx6, linflp_k18_dp6);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru6, linflp_k18_du6);
linflp_k18_mv_2_3(linflp_k18_Rux6, linflp_k18_dx6, linflp_k18_du6);
linflp_k18_v_turnsign_2(linflp_k18_du6, linflp_k18_du6);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf7, linflp_k18_dx7);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_dx6, linflp_k18_dx7);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu6, linflp_k18_du6, linflp_k18_dx7);
/* Zeitschritt 7 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx7, linflp_k18_dp7);
linflp_k18_mv_3_3(linflp_k18_Vxx7, linflp_k18_dx7, linflp_k18_dp7);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru7, linflp_k18_du7);
linflp_k18_mv_2_3(linflp_k18_Rux7, linflp_k18_dx7, linflp_k18_du7);
linflp_k18_v_turnsign_2(linflp_k18_du7, linflp_k18_du7);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf8, linflp_k18_dx8);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_dx7, linflp_k18_dx8);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu7, linflp_k18_du7, linflp_k18_dx8);
/* Zeitschritt 8 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx8, linflp_k18_dp8);
linflp_k18_mv_3_3(linflp_k18_Vxx8, linflp_k18_dx8, linflp_k18_dp8);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru8, linflp_k18_du8);
linflp_k18_mv_2_3(linflp_k18_Rux8, linflp_k18_dx8, linflp_k18_du8);
linflp_k18_v_turnsign_2(linflp_k18_du8, linflp_k18_du8);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf9, linflp_k18_dx9);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_dx8, linflp_k18_dx9);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu8, linflp_k18_du8, linflp_k18_dx9);
/* Zeitschritt 9 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx9, linflp_k18_dp9);
linflp_k18_mv_3_3(linflp_k18_Vxx9, linflp_k18_dx9, linflp_k18_dp9);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru9, linflp_k18_du9);
linflp_k18_mv_2_3(linflp_k18_Rux9, linflp_k18_dx9, linflp_k18_du9);
linflp_k18_v_turnsign_2(linflp_k18_du9, linflp_k18_du9);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf10, linflp_k18_dx10);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_dx9, linflp_k18_dx10);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu9, linflp_k18_du9, linflp_k18_dx10);
/* Zeitschritt 10 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx10, linflp_k18_dp10);
linflp_k18_mv_3_3(linflp_k18_Vxx10, linflp_k18_dx10, linflp_k18_dp10);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru10, linflp_k18_du10);
linflp_k18_mv_2_3(linflp_k18_Rux10, linflp_k18_dx10, linflp_k18_du10);
linflp_k18_v_turnsign_2(linflp_k18_du10, linflp_k18_du10);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf11, linflp_k18_dx11);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_dx10, linflp_k18_dx11);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu10, linflp_k18_du10, linflp_k18_dx11);
/* Zeitschritt 11 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx11, linflp_k18_dp11);
linflp_k18_mv_3_3(linflp_k18_Vxx11, linflp_k18_dx11, linflp_k18_dp11);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru11, linflp_k18_du11);
linflp_k18_mv_2_3(linflp_k18_Rux11, linflp_k18_dx11, linflp_k18_du11);
linflp_k18_v_turnsign_2(linflp_k18_du11, linflp_k18_du11);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf12, linflp_k18_dx12);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_dx11, linflp_k18_dx12);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu11, linflp_k18_du11, linflp_k18_dx12);
/* Zeitschritt 12 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx12, linflp_k18_dp12);
linflp_k18_mv_3_3(linflp_k18_Vxx12, linflp_k18_dx12, linflp_k18_dp12);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru12, linflp_k18_du12);
linflp_k18_mv_2_3(linflp_k18_Rux12, linflp_k18_dx12, linflp_k18_du12);
linflp_k18_v_turnsign_2(linflp_k18_du12, linflp_k18_du12);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf13, linflp_k18_dx13);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_dx12, linflp_k18_dx13);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu12, linflp_k18_du12, linflp_k18_dx13);
/* Zeitschritt 13 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx13, linflp_k18_dp13);
linflp_k18_mv_3_3(linflp_k18_Vxx13, linflp_k18_dx13, linflp_k18_dp13);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru13, linflp_k18_du13);
linflp_k18_mv_2_3(linflp_k18_Rux13, linflp_k18_dx13, linflp_k18_du13);
linflp_k18_v_turnsign_2(linflp_k18_du13, linflp_k18_du13);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf14, linflp_k18_dx14);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_dx13, linflp_k18_dx14);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu13, linflp_k18_du13, linflp_k18_dx14);
/* Zeitschritt 14 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx14, linflp_k18_dp14);
linflp_k18_mv_3_3(linflp_k18_Vxx14, linflp_k18_dx14, linflp_k18_dp14);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru14, linflp_k18_du14);
linflp_k18_mv_2_3(linflp_k18_Rux14, linflp_k18_dx14, linflp_k18_du14);
linflp_k18_v_turnsign_2(linflp_k18_du14, linflp_k18_du14);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf15, linflp_k18_dx15);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_dx14, linflp_k18_dx15);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu14, linflp_k18_du14, linflp_k18_dx15);
/* Zeitschritt 15 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx15, linflp_k18_dp15);
linflp_k18_mv_3_3(linflp_k18_Vxx15, linflp_k18_dx15, linflp_k18_dp15);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru15, linflp_k18_du15);
linflp_k18_mv_2_3(linflp_k18_Rux15, linflp_k18_dx15, linflp_k18_du15);
linflp_k18_v_turnsign_2(linflp_k18_du15, linflp_k18_du15);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf16, linflp_k18_dx16);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_dx15, linflp_k18_dx16);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu15, linflp_k18_du15, linflp_k18_dx16);
/* Zeitschritt 16 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx16, linflp_k18_dp16);
linflp_k18_mv_3_3(linflp_k18_Vxx16, linflp_k18_dx16, linflp_k18_dp16);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru16, linflp_k18_du16);
linflp_k18_mv_2_3(linflp_k18_Rux16, linflp_k18_dx16, linflp_k18_du16);
linflp_k18_v_turnsign_2(linflp_k18_du16, linflp_k18_du16);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf17, linflp_k18_dx17);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_dx16, linflp_k18_dx17);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu16, linflp_k18_du16, linflp_k18_dx17);
/* Zeitschritt 17 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx17, linflp_k18_dp17);
linflp_k18_mv_3_3(linflp_k18_Vxx17, linflp_k18_dx17, linflp_k18_dp17);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru17, linflp_k18_du17);
linflp_k18_mv_2_3(linflp_k18_Rux17, linflp_k18_dx17, linflp_k18_du17);
linflp_k18_v_turnsign_2(linflp_k18_du17, linflp_k18_du17);
/* dx */
linflp_k18_v_copy_3(linflp_k18_rf18, linflp_k18_dx18);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx17, linflp_k18_dx17, linflp_k18_dx18);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu17, linflp_k18_du17, linflp_k18_dx18);
/* Zeitschritt 18 */
/* dp */
linflp_k18_v_copy_3(linflp_k18_Vx18, linflp_k18_dp18);
linflp_k18_mv_3_3(linflp_k18_Vxx18, linflp_k18_dx18, linflp_k18_dp18);
/* du */
linflp_k18_v_copy_2(linflp_k18_Ru18, linflp_k18_du18);
linflp_k18_mv_2_3(linflp_k18_Rux18, linflp_k18_dx18, linflp_k18_du18);
linflp_k18_v_turnsign_2(linflp_k18_du18, linflp_k18_du18);
/* dx */
linflp_k18_error_source = 0;

}


static void linflp_k18_glqdocpip_rhs_affine()
{
/* Zeitschritt 0 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x0, linflp_k18_rf0x0);
linflp_k18_mv_sid21_sid2_3_3(linflp_k18_Hxx0, linflp_k18_x0, linflp_k18_rf0x0);
linflp_k18_mv_sid24_sid5_3_2(linflp_k18_Hxu0, linflp_k18_u0, linflp_k18_rf0x0);
linflp_k18_vsub_3(linflp_k18_rf0x0, linflp_k18_p0, linflp_k18_rf0x0);
linflp_k18_mtv_sid42_sid2_3_3(linflp_k18_fx0, linflp_k18_p1, linflp_k18_rf0x0);
linflp_k18_mtv_sid51_sid15_10_3(linflp_k18_gx0, linflp_k18_y0, linflp_k18_rf0x0);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u0, linflp_k18_rf0u0);
linflp_k18_mtv_sid24_sid2_3_2(linflp_k18_Hxu0, linflp_k18_x0, linflp_k18_rf0u0);
linflp_k18_mv_sid27_sid5_2_2(linflp_k18_Huu0, linflp_k18_u0, linflp_k18_rf0u0);
linflp_k18_mtv_sid45_sid2_3_2(linflp_k18_fu0, linflp_k18_p1, linflp_k18_rf0u0);
linflp_k18_mtv_sid54_sid15_10_2(linflp_k18_gu0, linflp_k18_y0, linflp_k18_rf0u0);
/* rf */
linflp_k18_v_copy_3(linflp_k18_xinit, linflp_k18_rf0);
linflp_k18_vsub_3(linflp_k18_rf0, linflp_k18_x0, linflp_k18_rf0);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g0, linflp_k18_rc0);
linflp_k18_mv_sid51_sid2_10_3(linflp_k18_gx0, linflp_k18_x0, linflp_k18_rc0);
linflp_k18_mv_sid54_sid5_10_2(linflp_k18_gu0, linflp_k18_u0, linflp_k18_rc0);
linflp_k18_vadd_10(linflp_k18_rc0, linflp_k18_nu0, linflp_k18_rc0);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y0, linflp_k18_nu0, linflp_k18_rk0);
/* Zeitschritt 1 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x1, linflp_k18_rf0x1);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx1, linflp_k18_x1, linflp_k18_rf0x1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu1, linflp_k18_u1, linflp_k18_rf0x1);
linflp_k18_vsub_3(linflp_k18_rf0x1, linflp_k18_p1, linflp_k18_rf0x1);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_p2, linflp_k18_rf0x1);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx1, linflp_k18_y1, linflp_k18_rf0x1);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u1, linflp_k18_rf0u1);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu1, linflp_k18_x1, linflp_k18_rf0u1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu1, linflp_k18_u1, linflp_k18_rf0u1);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu1, linflp_k18_p2, linflp_k18_rf0u1);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu1, linflp_k18_y1, linflp_k18_rf0u1);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f0, linflp_k18_rf1);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx0, linflp_k18_x0, linflp_k18_rf1);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu0, linflp_k18_u0, linflp_k18_rf1);
linflp_k18_vsub_3(linflp_k18_rf1, linflp_k18_x1, linflp_k18_rf1);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g1, linflp_k18_rc1);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx1, linflp_k18_x1, linflp_k18_rc1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu1, linflp_k18_u1, linflp_k18_rc1);
linflp_k18_vadd_10(linflp_k18_rc1, linflp_k18_nu1, linflp_k18_rc1);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y1, linflp_k18_nu1, linflp_k18_rk1);
/* Zeitschritt 2 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x2, linflp_k18_rf0x2);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx2, linflp_k18_x2, linflp_k18_rf0x2);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu2, linflp_k18_u2, linflp_k18_rf0x2);
linflp_k18_vsub_3(linflp_k18_rf0x2, linflp_k18_p2, linflp_k18_rf0x2);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_p3, linflp_k18_rf0x2);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx2, linflp_k18_y2, linflp_k18_rf0x2);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u2, linflp_k18_rf0u2);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu2, linflp_k18_x2, linflp_k18_rf0u2);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu2, linflp_k18_u2, linflp_k18_rf0u2);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu2, linflp_k18_p3, linflp_k18_rf0u2);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu2, linflp_k18_y2, linflp_k18_rf0u2);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f1, linflp_k18_rf2);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_x1, linflp_k18_rf2);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu1, linflp_k18_u1, linflp_k18_rf2);
linflp_k18_vsub_3(linflp_k18_rf2, linflp_k18_x2, linflp_k18_rf2);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g2, linflp_k18_rc2);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx2, linflp_k18_x2, linflp_k18_rc2);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu2, linflp_k18_u2, linflp_k18_rc2);
linflp_k18_vadd_10(linflp_k18_rc2, linflp_k18_nu2, linflp_k18_rc2);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y2, linflp_k18_nu2, linflp_k18_rk2);
/* Zeitschritt 3 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x3, linflp_k18_rf0x3);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx3, linflp_k18_x3, linflp_k18_rf0x3);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu3, linflp_k18_u3, linflp_k18_rf0x3);
linflp_k18_vsub_3(linflp_k18_rf0x3, linflp_k18_p3, linflp_k18_rf0x3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_p4, linflp_k18_rf0x3);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx3, linflp_k18_y3, linflp_k18_rf0x3);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u3, linflp_k18_rf0u3);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu3, linflp_k18_x3, linflp_k18_rf0u3);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu3, linflp_k18_u3, linflp_k18_rf0u3);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu3, linflp_k18_p4, linflp_k18_rf0u3);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu3, linflp_k18_y3, linflp_k18_rf0u3);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f2, linflp_k18_rf3);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_x2, linflp_k18_rf3);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu2, linflp_k18_u2, linflp_k18_rf3);
linflp_k18_vsub_3(linflp_k18_rf3, linflp_k18_x3, linflp_k18_rf3);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g3, linflp_k18_rc3);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx3, linflp_k18_x3, linflp_k18_rc3);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu3, linflp_k18_u3, linflp_k18_rc3);
linflp_k18_vadd_10(linflp_k18_rc3, linflp_k18_nu3, linflp_k18_rc3);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y3, linflp_k18_nu3, linflp_k18_rk3);
/* Zeitschritt 4 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x4, linflp_k18_rf0x4);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx4, linflp_k18_x4, linflp_k18_rf0x4);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu4, linflp_k18_u4, linflp_k18_rf0x4);
linflp_k18_vsub_3(linflp_k18_rf0x4, linflp_k18_p4, linflp_k18_rf0x4);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_p5, linflp_k18_rf0x4);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx4, linflp_k18_y4, linflp_k18_rf0x4);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u4, linflp_k18_rf0u4);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu4, linflp_k18_x4, linflp_k18_rf0u4);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu4, linflp_k18_u4, linflp_k18_rf0u4);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu4, linflp_k18_p5, linflp_k18_rf0u4);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu4, linflp_k18_y4, linflp_k18_rf0u4);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f3, linflp_k18_rf4);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_x3, linflp_k18_rf4);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu3, linflp_k18_u3, linflp_k18_rf4);
linflp_k18_vsub_3(linflp_k18_rf4, linflp_k18_x4, linflp_k18_rf4);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g4, linflp_k18_rc4);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx4, linflp_k18_x4, linflp_k18_rc4);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu4, linflp_k18_u4, linflp_k18_rc4);
linflp_k18_vadd_10(linflp_k18_rc4, linflp_k18_nu4, linflp_k18_rc4);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y4, linflp_k18_nu4, linflp_k18_rk4);
/* Zeitschritt 5 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x5, linflp_k18_rf0x5);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx5, linflp_k18_x5, linflp_k18_rf0x5);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu5, linflp_k18_u5, linflp_k18_rf0x5);
linflp_k18_vsub_3(linflp_k18_rf0x5, linflp_k18_p5, linflp_k18_rf0x5);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_p6, linflp_k18_rf0x5);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx5, linflp_k18_y5, linflp_k18_rf0x5);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u5, linflp_k18_rf0u5);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu5, linflp_k18_x5, linflp_k18_rf0u5);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu5, linflp_k18_u5, linflp_k18_rf0u5);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu5, linflp_k18_p6, linflp_k18_rf0u5);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu5, linflp_k18_y5, linflp_k18_rf0u5);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f4, linflp_k18_rf5);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_x4, linflp_k18_rf5);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu4, linflp_k18_u4, linflp_k18_rf5);
linflp_k18_vsub_3(linflp_k18_rf5, linflp_k18_x5, linflp_k18_rf5);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g5, linflp_k18_rc5);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx5, linflp_k18_x5, linflp_k18_rc5);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu5, linflp_k18_u5, linflp_k18_rc5);
linflp_k18_vadd_10(linflp_k18_rc5, linflp_k18_nu5, linflp_k18_rc5);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y5, linflp_k18_nu5, linflp_k18_rk5);
/* Zeitschritt 6 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x6, linflp_k18_rf0x6);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx6, linflp_k18_x6, linflp_k18_rf0x6);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu6, linflp_k18_u6, linflp_k18_rf0x6);
linflp_k18_vsub_3(linflp_k18_rf0x6, linflp_k18_p6, linflp_k18_rf0x6);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_p7, linflp_k18_rf0x6);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx6, linflp_k18_y6, linflp_k18_rf0x6);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u6, linflp_k18_rf0u6);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu6, linflp_k18_x6, linflp_k18_rf0u6);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu6, linflp_k18_u6, linflp_k18_rf0u6);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu6, linflp_k18_p7, linflp_k18_rf0u6);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu6, linflp_k18_y6, linflp_k18_rf0u6);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f5, linflp_k18_rf6);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_x5, linflp_k18_rf6);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu5, linflp_k18_u5, linflp_k18_rf6);
linflp_k18_vsub_3(linflp_k18_rf6, linflp_k18_x6, linflp_k18_rf6);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g6, linflp_k18_rc6);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx6, linflp_k18_x6, linflp_k18_rc6);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu6, linflp_k18_u6, linflp_k18_rc6);
linflp_k18_vadd_10(linflp_k18_rc6, linflp_k18_nu6, linflp_k18_rc6);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y6, linflp_k18_nu6, linflp_k18_rk6);
/* Zeitschritt 7 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x7, linflp_k18_rf0x7);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx7, linflp_k18_x7, linflp_k18_rf0x7);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu7, linflp_k18_u7, linflp_k18_rf0x7);
linflp_k18_vsub_3(linflp_k18_rf0x7, linflp_k18_p7, linflp_k18_rf0x7);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_p8, linflp_k18_rf0x7);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx7, linflp_k18_y7, linflp_k18_rf0x7);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u7, linflp_k18_rf0u7);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu7, linflp_k18_x7, linflp_k18_rf0u7);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu7, linflp_k18_u7, linflp_k18_rf0u7);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu7, linflp_k18_p8, linflp_k18_rf0u7);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu7, linflp_k18_y7, linflp_k18_rf0u7);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f6, linflp_k18_rf7);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_x6, linflp_k18_rf7);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu6, linflp_k18_u6, linflp_k18_rf7);
linflp_k18_vsub_3(linflp_k18_rf7, linflp_k18_x7, linflp_k18_rf7);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g7, linflp_k18_rc7);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx7, linflp_k18_x7, linflp_k18_rc7);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu7, linflp_k18_u7, linflp_k18_rc7);
linflp_k18_vadd_10(linflp_k18_rc7, linflp_k18_nu7, linflp_k18_rc7);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y7, linflp_k18_nu7, linflp_k18_rk7);
/* Zeitschritt 8 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x8, linflp_k18_rf0x8);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx8, linflp_k18_x8, linflp_k18_rf0x8);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu8, linflp_k18_u8, linflp_k18_rf0x8);
linflp_k18_vsub_3(linflp_k18_rf0x8, linflp_k18_p8, linflp_k18_rf0x8);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_p9, linflp_k18_rf0x8);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx8, linflp_k18_y8, linflp_k18_rf0x8);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u8, linflp_k18_rf0u8);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu8, linflp_k18_x8, linflp_k18_rf0u8);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu8, linflp_k18_u8, linflp_k18_rf0u8);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu8, linflp_k18_p9, linflp_k18_rf0u8);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu8, linflp_k18_y8, linflp_k18_rf0u8);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f7, linflp_k18_rf8);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_x7, linflp_k18_rf8);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu7, linflp_k18_u7, linflp_k18_rf8);
linflp_k18_vsub_3(linflp_k18_rf8, linflp_k18_x8, linflp_k18_rf8);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g8, linflp_k18_rc8);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx8, linflp_k18_x8, linflp_k18_rc8);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu8, linflp_k18_u8, linflp_k18_rc8);
linflp_k18_vadd_10(linflp_k18_rc8, linflp_k18_nu8, linflp_k18_rc8);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y8, linflp_k18_nu8, linflp_k18_rk8);
/* Zeitschritt 9 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x9, linflp_k18_rf0x9);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx9, linflp_k18_x9, linflp_k18_rf0x9);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu9, linflp_k18_u9, linflp_k18_rf0x9);
linflp_k18_vsub_3(linflp_k18_rf0x9, linflp_k18_p9, linflp_k18_rf0x9);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_p10, linflp_k18_rf0x9);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx9, linflp_k18_y9, linflp_k18_rf0x9);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u9, linflp_k18_rf0u9);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu9, linflp_k18_x9, linflp_k18_rf0u9);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu9, linflp_k18_u9, linflp_k18_rf0u9);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu9, linflp_k18_p10, linflp_k18_rf0u9);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu9, linflp_k18_y9, linflp_k18_rf0u9);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f8, linflp_k18_rf9);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_x8, linflp_k18_rf9);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu8, linflp_k18_u8, linflp_k18_rf9);
linflp_k18_vsub_3(linflp_k18_rf9, linflp_k18_x9, linflp_k18_rf9);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g9, linflp_k18_rc9);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx9, linflp_k18_x9, linflp_k18_rc9);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu9, linflp_k18_u9, linflp_k18_rc9);
linflp_k18_vadd_10(linflp_k18_rc9, linflp_k18_nu9, linflp_k18_rc9);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y9, linflp_k18_nu9, linflp_k18_rk9);
/* Zeitschritt 10 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x10, linflp_k18_rf0x10);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx10, linflp_k18_x10, linflp_k18_rf0x10);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu10, linflp_k18_u10, linflp_k18_rf0x10);
linflp_k18_vsub_3(linflp_k18_rf0x10, linflp_k18_p10, linflp_k18_rf0x10);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_p11, linflp_k18_rf0x10);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx10, linflp_k18_y10, linflp_k18_rf0x10);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u10, linflp_k18_rf0u10);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu10, linflp_k18_x10, linflp_k18_rf0u10);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu10, linflp_k18_u10, linflp_k18_rf0u10);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu10, linflp_k18_p11, linflp_k18_rf0u10);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu10, linflp_k18_y10, linflp_k18_rf0u10);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f9, linflp_k18_rf10);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_x9, linflp_k18_rf10);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu9, linflp_k18_u9, linflp_k18_rf10);
linflp_k18_vsub_3(linflp_k18_rf10, linflp_k18_x10, linflp_k18_rf10);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g10, linflp_k18_rc10);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx10, linflp_k18_x10, linflp_k18_rc10);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu10, linflp_k18_u10, linflp_k18_rc10);
linflp_k18_vadd_10(linflp_k18_rc10, linflp_k18_nu10, linflp_k18_rc10);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y10, linflp_k18_nu10, linflp_k18_rk10);
/* Zeitschritt 11 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x11, linflp_k18_rf0x11);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx11, linflp_k18_x11, linflp_k18_rf0x11);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu11, linflp_k18_u11, linflp_k18_rf0x11);
linflp_k18_vsub_3(linflp_k18_rf0x11, linflp_k18_p11, linflp_k18_rf0x11);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_p12, linflp_k18_rf0x11);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx11, linflp_k18_y11, linflp_k18_rf0x11);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u11, linflp_k18_rf0u11);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu11, linflp_k18_x11, linflp_k18_rf0u11);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu11, linflp_k18_u11, linflp_k18_rf0u11);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu11, linflp_k18_p12, linflp_k18_rf0u11);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu11, linflp_k18_y11, linflp_k18_rf0u11);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f10, linflp_k18_rf11);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_x10, linflp_k18_rf11);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu10, linflp_k18_u10, linflp_k18_rf11);
linflp_k18_vsub_3(linflp_k18_rf11, linflp_k18_x11, linflp_k18_rf11);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g11, linflp_k18_rc11);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx11, linflp_k18_x11, linflp_k18_rc11);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu11, linflp_k18_u11, linflp_k18_rc11);
linflp_k18_vadd_10(linflp_k18_rc11, linflp_k18_nu11, linflp_k18_rc11);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y11, linflp_k18_nu11, linflp_k18_rk11);
/* Zeitschritt 12 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x12, linflp_k18_rf0x12);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx12, linflp_k18_x12, linflp_k18_rf0x12);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu12, linflp_k18_u12, linflp_k18_rf0x12);
linflp_k18_vsub_3(linflp_k18_rf0x12, linflp_k18_p12, linflp_k18_rf0x12);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_p13, linflp_k18_rf0x12);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx12, linflp_k18_y12, linflp_k18_rf0x12);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u12, linflp_k18_rf0u12);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu12, linflp_k18_x12, linflp_k18_rf0u12);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu12, linflp_k18_u12, linflp_k18_rf0u12);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu12, linflp_k18_p13, linflp_k18_rf0u12);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu12, linflp_k18_y12, linflp_k18_rf0u12);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f11, linflp_k18_rf12);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_x11, linflp_k18_rf12);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu11, linflp_k18_u11, linflp_k18_rf12);
linflp_k18_vsub_3(linflp_k18_rf12, linflp_k18_x12, linflp_k18_rf12);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g12, linflp_k18_rc12);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx12, linflp_k18_x12, linflp_k18_rc12);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu12, linflp_k18_u12, linflp_k18_rc12);
linflp_k18_vadd_10(linflp_k18_rc12, linflp_k18_nu12, linflp_k18_rc12);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y12, linflp_k18_nu12, linflp_k18_rk12);
/* Zeitschritt 13 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x13, linflp_k18_rf0x13);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx13, linflp_k18_x13, linflp_k18_rf0x13);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu13, linflp_k18_u13, linflp_k18_rf0x13);
linflp_k18_vsub_3(linflp_k18_rf0x13, linflp_k18_p13, linflp_k18_rf0x13);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_p14, linflp_k18_rf0x13);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx13, linflp_k18_y13, linflp_k18_rf0x13);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u13, linflp_k18_rf0u13);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu13, linflp_k18_x13, linflp_k18_rf0u13);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu13, linflp_k18_u13, linflp_k18_rf0u13);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu13, linflp_k18_p14, linflp_k18_rf0u13);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu13, linflp_k18_y13, linflp_k18_rf0u13);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f12, linflp_k18_rf13);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_x12, linflp_k18_rf13);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu12, linflp_k18_u12, linflp_k18_rf13);
linflp_k18_vsub_3(linflp_k18_rf13, linflp_k18_x13, linflp_k18_rf13);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g13, linflp_k18_rc13);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx13, linflp_k18_x13, linflp_k18_rc13);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu13, linflp_k18_u13, linflp_k18_rc13);
linflp_k18_vadd_10(linflp_k18_rc13, linflp_k18_nu13, linflp_k18_rc13);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y13, linflp_k18_nu13, linflp_k18_rk13);
/* Zeitschritt 14 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x14, linflp_k18_rf0x14);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx14, linflp_k18_x14, linflp_k18_rf0x14);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu14, linflp_k18_u14, linflp_k18_rf0x14);
linflp_k18_vsub_3(linflp_k18_rf0x14, linflp_k18_p14, linflp_k18_rf0x14);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_p15, linflp_k18_rf0x14);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx14, linflp_k18_y14, linflp_k18_rf0x14);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u14, linflp_k18_rf0u14);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu14, linflp_k18_x14, linflp_k18_rf0u14);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu14, linflp_k18_u14, linflp_k18_rf0u14);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu14, linflp_k18_p15, linflp_k18_rf0u14);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu14, linflp_k18_y14, linflp_k18_rf0u14);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f13, linflp_k18_rf14);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_x13, linflp_k18_rf14);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu13, linflp_k18_u13, linflp_k18_rf14);
linflp_k18_vsub_3(linflp_k18_rf14, linflp_k18_x14, linflp_k18_rf14);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g14, linflp_k18_rc14);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx14, linflp_k18_x14, linflp_k18_rc14);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu14, linflp_k18_u14, linflp_k18_rc14);
linflp_k18_vadd_10(linflp_k18_rc14, linflp_k18_nu14, linflp_k18_rc14);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y14, linflp_k18_nu14, linflp_k18_rk14);
/* Zeitschritt 15 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x15, linflp_k18_rf0x15);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx15, linflp_k18_x15, linflp_k18_rf0x15);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu15, linflp_k18_u15, linflp_k18_rf0x15);
linflp_k18_vsub_3(linflp_k18_rf0x15, linflp_k18_p15, linflp_k18_rf0x15);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_p16, linflp_k18_rf0x15);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx15, linflp_k18_y15, linflp_k18_rf0x15);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u15, linflp_k18_rf0u15);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu15, linflp_k18_x15, linflp_k18_rf0u15);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu15, linflp_k18_u15, linflp_k18_rf0u15);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu15, linflp_k18_p16, linflp_k18_rf0u15);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu15, linflp_k18_y15, linflp_k18_rf0u15);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f14, linflp_k18_rf15);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_x14, linflp_k18_rf15);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu14, linflp_k18_u14, linflp_k18_rf15);
linflp_k18_vsub_3(linflp_k18_rf15, linflp_k18_x15, linflp_k18_rf15);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g15, linflp_k18_rc15);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx15, linflp_k18_x15, linflp_k18_rc15);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu15, linflp_k18_u15, linflp_k18_rc15);
linflp_k18_vadd_10(linflp_k18_rc15, linflp_k18_nu15, linflp_k18_rc15);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y15, linflp_k18_nu15, linflp_k18_rk15);
/* Zeitschritt 16 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x16, linflp_k18_rf0x16);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx16, linflp_k18_x16, linflp_k18_rf0x16);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu16, linflp_k18_u16, linflp_k18_rf0x16);
linflp_k18_vsub_3(linflp_k18_rf0x16, linflp_k18_p16, linflp_k18_rf0x16);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_p17, linflp_k18_rf0x16);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx16, linflp_k18_y16, linflp_k18_rf0x16);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u16, linflp_k18_rf0u16);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu16, linflp_k18_x16, linflp_k18_rf0u16);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu16, linflp_k18_u16, linflp_k18_rf0u16);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu16, linflp_k18_p17, linflp_k18_rf0u16);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu16, linflp_k18_y16, linflp_k18_rf0u16);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f15, linflp_k18_rf16);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_x15, linflp_k18_rf16);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu15, linflp_k18_u15, linflp_k18_rf16);
linflp_k18_vsub_3(linflp_k18_rf16, linflp_k18_x16, linflp_k18_rf16);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g16, linflp_k18_rc16);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx16, linflp_k18_x16, linflp_k18_rc16);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu16, linflp_k18_u16, linflp_k18_rc16);
linflp_k18_vadd_10(linflp_k18_rc16, linflp_k18_nu16, linflp_k18_rc16);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y16, linflp_k18_nu16, linflp_k18_rk16);
/* Zeitschritt 17 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x17, linflp_k18_rf0x17);
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx17, linflp_k18_x17, linflp_k18_rf0x17);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu17, linflp_k18_u17, linflp_k18_rf0x17);
linflp_k18_vsub_3(linflp_k18_rf0x17, linflp_k18_p17, linflp_k18_rf0x17);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx17, linflp_k18_p18, linflp_k18_rf0x17);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx17, linflp_k18_y17, linflp_k18_rf0x17);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u17, linflp_k18_rf0u17);
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu17, linflp_k18_x17, linflp_k18_rf0u17);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu17, linflp_k18_u17, linflp_k18_rf0u17);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu17, linflp_k18_p18, linflp_k18_rf0u17);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu17, linflp_k18_y17, linflp_k18_rf0u17);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f16, linflp_k18_rf17);
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_x16, linflp_k18_rf17);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu16, linflp_k18_u16, linflp_k18_rf17);
linflp_k18_vsub_3(linflp_k18_rf17, linflp_k18_x17, linflp_k18_rf17);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g17, linflp_k18_rc17);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx17, linflp_k18_x17, linflp_k18_rc17);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu17, linflp_k18_u17, linflp_k18_rc17);
linflp_k18_vadd_10(linflp_k18_rc17, linflp_k18_nu17, linflp_k18_rc17);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y17, linflp_k18_nu17, linflp_k18_rk17);
/* Zeitschritt 18 */
/* rf0x */
linflp_k18_v_copy_3(linflp_k18_f0x18, linflp_k18_rf0x18);
linflp_k18_mv_sid23_sid2_3_3(linflp_k18_Hxx18, linflp_k18_x18, linflp_k18_rf0x18);
linflp_k18_mv_sid26_sid5_3_2(linflp_k18_Hxu18, linflp_k18_u18, linflp_k18_rf0x18);
linflp_k18_vsub_3(linflp_k18_rf0x18, linflp_k18_p18, linflp_k18_rf0x18);
linflp_k18_mtv_sid53_sid17_10_3(linflp_k18_gx18, linflp_k18_y18, linflp_k18_rf0x18);
/* rf0u */
linflp_k18_v_copy_2(linflp_k18_f0u18, linflp_k18_rf0u18);
linflp_k18_mtv_sid26_sid2_3_2(linflp_k18_Hxu18, linflp_k18_x18, linflp_k18_rf0u18);
linflp_k18_mv_sid29_sid5_2_2(linflp_k18_Huu18, linflp_k18_u18, linflp_k18_rf0u18);
linflp_k18_mtv_sid56_sid17_10_2(linflp_k18_gu18, linflp_k18_y18, linflp_k18_rf0u18);
/* rf */
linflp_k18_v_copy_3(linflp_k18_f17, linflp_k18_rf18);
linflp_k18_mv_sid44_sid2_3_3(linflp_k18_fx17, linflp_k18_x17, linflp_k18_rf18);
linflp_k18_mv_sid47_sid5_3_2(linflp_k18_fu17, linflp_k18_u17, linflp_k18_rf18);
linflp_k18_vsub_3(linflp_k18_rf18, linflp_k18_x18, linflp_k18_rf18);
/* rc */
linflp_k18_v_copy_10(linflp_k18_g18, linflp_k18_rc18);
linflp_k18_mv_sid53_sid2_10_3(linflp_k18_gx18, linflp_k18_x18, linflp_k18_rc18);
linflp_k18_mv_sid56_sid5_10_2(linflp_k18_gu18, linflp_k18_u18, linflp_k18_rc18);
linflp_k18_vadd_10(linflp_k18_rc18, linflp_k18_nu18, linflp_k18_rc18);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_y18, linflp_k18_nu18, linflp_k18_rk18);
}


static void linflp_k18_glqdocpip_rhs_corrector()
{
/* Zeitschritt 0 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy0, linflp_k18_dnu0, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk0, linflp_k18_tmp1_10, linflp_k18_rk0);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk0, linflp_k18_tmp2_10, linflp_k18_rk0);
/* Zeitschritt 1 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy1, linflp_k18_dnu1, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk1, linflp_k18_tmp2_10, linflp_k18_rk1);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk1, linflp_k18_tmp1_10, linflp_k18_rk1);
/* Zeitschritt 2 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy2, linflp_k18_dnu2, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk2, linflp_k18_tmp1_10, linflp_k18_rk2);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk2, linflp_k18_tmp2_10, linflp_k18_rk2);
/* Zeitschritt 3 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy3, linflp_k18_dnu3, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk3, linflp_k18_tmp2_10, linflp_k18_rk3);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk3, linflp_k18_tmp1_10, linflp_k18_rk3);
/* Zeitschritt 4 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy4, linflp_k18_dnu4, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk4, linflp_k18_tmp1_10, linflp_k18_rk4);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk4, linflp_k18_tmp2_10, linflp_k18_rk4);
/* Zeitschritt 5 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy5, linflp_k18_dnu5, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk5, linflp_k18_tmp2_10, linflp_k18_rk5);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk5, linflp_k18_tmp1_10, linflp_k18_rk5);
/* Zeitschritt 6 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy6, linflp_k18_dnu6, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk6, linflp_k18_tmp1_10, linflp_k18_rk6);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk6, linflp_k18_tmp2_10, linflp_k18_rk6);
/* Zeitschritt 7 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy7, linflp_k18_dnu7, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk7, linflp_k18_tmp2_10, linflp_k18_rk7);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk7, linflp_k18_tmp1_10, linflp_k18_rk7);
/* Zeitschritt 8 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy8, linflp_k18_dnu8, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk8, linflp_k18_tmp1_10, linflp_k18_rk8);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk8, linflp_k18_tmp2_10, linflp_k18_rk8);
/* Zeitschritt 9 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy9, linflp_k18_dnu9, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk9, linflp_k18_tmp2_10, linflp_k18_rk9);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk9, linflp_k18_tmp1_10, linflp_k18_rk9);
/* Zeitschritt 10 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy10, linflp_k18_dnu10, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk10, linflp_k18_tmp1_10, linflp_k18_rk10);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk10, linflp_k18_tmp2_10, linflp_k18_rk10);
/* Zeitschritt 11 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy11, linflp_k18_dnu11, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk11, linflp_k18_tmp2_10, linflp_k18_rk11);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk11, linflp_k18_tmp1_10, linflp_k18_rk11);
/* Zeitschritt 12 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy12, linflp_k18_dnu12, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk12, linflp_k18_tmp1_10, linflp_k18_rk12);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk12, linflp_k18_tmp2_10, linflp_k18_rk12);
/* Zeitschritt 13 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy13, linflp_k18_dnu13, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk13, linflp_k18_tmp2_10, linflp_k18_rk13);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk13, linflp_k18_tmp1_10, linflp_k18_rk13);
/* Zeitschritt 14 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy14, linflp_k18_dnu14, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk14, linflp_k18_tmp1_10, linflp_k18_rk14);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk14, linflp_k18_tmp2_10, linflp_k18_rk14);
/* Zeitschritt 15 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy15, linflp_k18_dnu15, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk15, linflp_k18_tmp2_10, linflp_k18_rk15);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk15, linflp_k18_tmp1_10, linflp_k18_rk15);
/* Zeitschritt 16 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy16, linflp_k18_dnu16, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk16, linflp_k18_tmp1_10, linflp_k18_rk16);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk16, linflp_k18_tmp2_10, linflp_k18_rk16);
/* Zeitschritt 17 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy17, linflp_k18_dnu17, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk17, linflp_k18_tmp2_10, linflp_k18_rk17);
linflp_k18_v_init1_10(linflp_k18_tmp2_10);
linflp_k18_v_init0_10(linflp_k18_tmp1_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp2_10, linflp_k18_tmp1_10);
linflp_k18_vsub_10(linflp_k18_rk17, linflp_k18_tmp1_10, linflp_k18_rk17);
/* Zeitschritt 18 */
/* rk_corr */
linflp_k18_vv_elemult_10(linflp_k18_dy18, linflp_k18_dnu18, linflp_k18_tmp1_10);
linflp_k18_vadd_10(linflp_k18_rk18, linflp_k18_tmp1_10, linflp_k18_rk18);
linflp_k18_v_init1_10(linflp_k18_tmp1_10);
linflp_k18_v_init0_10(linflp_k18_tmp2_10);
linflp_k18_vv_elemult_1(linflp_k18_sigma, linflp_k18_mu, linflp_k18_tmp1_1);
linflp_k18_sv_10(linflp_k18_tmp1_1, linflp_k18_tmp1_10, linflp_k18_tmp2_10);
linflp_k18_vsub_10(linflp_k18_rk18, linflp_k18_tmp2_10, linflp_k18_rk18);
}


static void linflp_k18_glqdocpip_rhs_reduced()
{
linflp_k18_error_source = 3;
/* Zeitschritt 0 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny0);
linflp_k18_vv_elediv_10(&linflp_k18_y0[0], &linflp_k18_nu0[0], &linflp_k18_yny0[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs0, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk0[0], &linflp_k18_y0[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc0[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny0, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x0, linflp_k18_rrf0x0);
linflp_k18_mtv_sid51_sid15_10_3(linflp_k18_gx0, linflp_k18_tmp1_10_1, linflp_k18_rrf0x0);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u0, linflp_k18_rrf0u0);
linflp_k18_mtv_sid54_sid15_10_2(linflp_k18_gu0, linflp_k18_tmp1_10_1, linflp_k18_rrf0u0);
/* Zeitschritt 1 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny1);
linflp_k18_vv_elediv_10(&linflp_k18_y1[0], &linflp_k18_nu1[0], &linflp_k18_yny1[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs1, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk1[0], &linflp_k18_y1[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny1, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x1, linflp_k18_rrf0x1);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx1, linflp_k18_tmp1_10_1, linflp_k18_rrf0x1);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u1, linflp_k18_rrf0u1);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu1, linflp_k18_tmp1_10_1, linflp_k18_rrf0u1);
/* Zeitschritt 2 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny2);
linflp_k18_vv_elediv_10(&linflp_k18_y2[0], &linflp_k18_nu2[0], &linflp_k18_yny2[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs2, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk2[0], &linflp_k18_y2[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc2[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny2, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x2, linflp_k18_rrf0x2);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx2, linflp_k18_tmp1_10_1, linflp_k18_rrf0x2);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u2, linflp_k18_rrf0u2);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu2, linflp_k18_tmp1_10_1, linflp_k18_rrf0u2);
/* Zeitschritt 3 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny3);
linflp_k18_vv_elediv_10(&linflp_k18_y3[0], &linflp_k18_nu3[0], &linflp_k18_yny3[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs3, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk3[0], &linflp_k18_y3[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc3[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny3, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x3, linflp_k18_rrf0x3);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx3, linflp_k18_tmp1_10_1, linflp_k18_rrf0x3);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u3, linflp_k18_rrf0u3);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu3, linflp_k18_tmp1_10_1, linflp_k18_rrf0u3);
/* Zeitschritt 4 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny4);
linflp_k18_vv_elediv_10(&linflp_k18_y4[0], &linflp_k18_nu4[0], &linflp_k18_yny4[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs4, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk4[0], &linflp_k18_y4[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc4[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny4, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x4, linflp_k18_rrf0x4);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx4, linflp_k18_tmp1_10_1, linflp_k18_rrf0x4);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u4, linflp_k18_rrf0u4);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu4, linflp_k18_tmp1_10_1, linflp_k18_rrf0u4);
/* Zeitschritt 5 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny5);
linflp_k18_vv_elediv_10(&linflp_k18_y5[0], &linflp_k18_nu5[0], &linflp_k18_yny5[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs5, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk5[0], &linflp_k18_y5[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc5[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny5, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x5, linflp_k18_rrf0x5);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx5, linflp_k18_tmp1_10_1, linflp_k18_rrf0x5);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u5, linflp_k18_rrf0u5);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu5, linflp_k18_tmp1_10_1, linflp_k18_rrf0u5);
/* Zeitschritt 6 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny6);
linflp_k18_vv_elediv_10(&linflp_k18_y6[0], &linflp_k18_nu6[0], &linflp_k18_yny6[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs6, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk6[0], &linflp_k18_y6[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc6[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny6, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x6, linflp_k18_rrf0x6);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx6, linflp_k18_tmp1_10_1, linflp_k18_rrf0x6);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u6, linflp_k18_rrf0u6);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu6, linflp_k18_tmp1_10_1, linflp_k18_rrf0u6);
/* Zeitschritt 7 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny7);
linflp_k18_vv_elediv_10(&linflp_k18_y7[0], &linflp_k18_nu7[0], &linflp_k18_yny7[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs7, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk7[0], &linflp_k18_y7[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc7[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny7, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x7, linflp_k18_rrf0x7);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx7, linflp_k18_tmp1_10_1, linflp_k18_rrf0x7);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u7, linflp_k18_rrf0u7);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu7, linflp_k18_tmp1_10_1, linflp_k18_rrf0u7);
/* Zeitschritt 8 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny8);
linflp_k18_vv_elediv_10(&linflp_k18_y8[0], &linflp_k18_nu8[0], &linflp_k18_yny8[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs8, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk8[0], &linflp_k18_y8[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc8[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny8, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x8, linflp_k18_rrf0x8);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx8, linflp_k18_tmp1_10_1, linflp_k18_rrf0x8);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u8, linflp_k18_rrf0u8);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu8, linflp_k18_tmp1_10_1, linflp_k18_rrf0u8);
/* Zeitschritt 9 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny9);
linflp_k18_vv_elediv_10(&linflp_k18_y9[0], &linflp_k18_nu9[0], &linflp_k18_yny9[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs9, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk9[0], &linflp_k18_y9[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc9[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny9, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x9, linflp_k18_rrf0x9);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx9, linflp_k18_tmp1_10_1, linflp_k18_rrf0x9);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u9, linflp_k18_rrf0u9);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu9, linflp_k18_tmp1_10_1, linflp_k18_rrf0u9);
/* Zeitschritt 10 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny10);
linflp_k18_vv_elediv_10(&linflp_k18_y10[0], &linflp_k18_nu10[0], &linflp_k18_yny10[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs10, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk10[0], &linflp_k18_y10[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc10[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny10, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x10, linflp_k18_rrf0x10);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx10, linflp_k18_tmp1_10_1, linflp_k18_rrf0x10);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u10, linflp_k18_rrf0u10);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu10, linflp_k18_tmp1_10_1, linflp_k18_rrf0u10);
/* Zeitschritt 11 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny11);
linflp_k18_vv_elediv_10(&linflp_k18_y11[0], &linflp_k18_nu11[0], &linflp_k18_yny11[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs11, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk11[0], &linflp_k18_y11[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc11[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny11, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x11, linflp_k18_rrf0x11);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx11, linflp_k18_tmp1_10_1, linflp_k18_rrf0x11);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u11, linflp_k18_rrf0u11);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu11, linflp_k18_tmp1_10_1, linflp_k18_rrf0u11);
/* Zeitschritt 12 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny12);
linflp_k18_vv_elediv_10(&linflp_k18_y12[0], &linflp_k18_nu12[0], &linflp_k18_yny12[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs12, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk12[0], &linflp_k18_y12[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc12[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny12, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x12, linflp_k18_rrf0x12);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx12, linflp_k18_tmp1_10_1, linflp_k18_rrf0x12);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u12, linflp_k18_rrf0u12);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu12, linflp_k18_tmp1_10_1, linflp_k18_rrf0u12);
/* Zeitschritt 13 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny13);
linflp_k18_vv_elediv_10(&linflp_k18_y13[0], &linflp_k18_nu13[0], &linflp_k18_yny13[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs13, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk13[0], &linflp_k18_y13[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc13[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny13, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x13, linflp_k18_rrf0x13);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx13, linflp_k18_tmp1_10_1, linflp_k18_rrf0x13);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u13, linflp_k18_rrf0u13);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu13, linflp_k18_tmp1_10_1, linflp_k18_rrf0u13);
/* Zeitschritt 14 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny14);
linflp_k18_vv_elediv_10(&linflp_k18_y14[0], &linflp_k18_nu14[0], &linflp_k18_yny14[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs14, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk14[0], &linflp_k18_y14[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc14[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny14, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x14, linflp_k18_rrf0x14);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx14, linflp_k18_tmp1_10_1, linflp_k18_rrf0x14);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u14, linflp_k18_rrf0u14);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu14, linflp_k18_tmp1_10_1, linflp_k18_rrf0u14);
/* Zeitschritt 15 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny15);
linflp_k18_vv_elediv_10(&linflp_k18_y15[0], &linflp_k18_nu15[0], &linflp_k18_yny15[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs15, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk15[0], &linflp_k18_y15[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc15[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny15, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x15, linflp_k18_rrf0x15);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx15, linflp_k18_tmp1_10_1, linflp_k18_rrf0x15);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u15, linflp_k18_rrf0u15);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu15, linflp_k18_tmp1_10_1, linflp_k18_rrf0u15);
/* Zeitschritt 16 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny16);
linflp_k18_vv_elediv_10(&linflp_k18_y16[0], &linflp_k18_nu16[0], &linflp_k18_yny16[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs16, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk16[0], &linflp_k18_y16[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc16[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny16, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x16, linflp_k18_rrf0x16);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx16, linflp_k18_tmp1_10_1, linflp_k18_rrf0x16);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u16, linflp_k18_rrf0u16);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu16, linflp_k18_tmp1_10_1, linflp_k18_rrf0u16);
/* Zeitschritt 17 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny17);
linflp_k18_vv_elediv_10(&linflp_k18_y17[0], &linflp_k18_nu17[0], &linflp_k18_yny17[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs17, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk17[0], &linflp_k18_y17[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc17[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny17, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x17, linflp_k18_rrf0x17);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx17, linflp_k18_tmp1_10_1, linflp_k18_rrf0x17);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u17, linflp_k18_rrf0u17);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu17, linflp_k18_tmp1_10_1, linflp_k18_rrf0u17);
/* Zeitschritt 18 */
/* yny */
linflp_k18_v_init0_10(linflp_k18_yny18);
linflp_k18_vv_elediv_10(&linflp_k18_y18[0], &linflp_k18_nu18[0], &linflp_k18_yny18[0]);
if(linflp_k18_termcode > -1){return;}
/* v1 */
linflp_k18_v_copy_0(linflp_k18_rhsxs18, linflp_k18_tmp1_10_1);
linflp_k18_vv_elediv_10(&linflp_k18_rk18[0], &linflp_k18_y18[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_rc18[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny18, linflp_k18_tmp1_10_1, linflp_k18_tmp1_10_1);
/* rrf0x */
linflp_k18_v_copy_3(linflp_k18_rf0x18, linflp_k18_rrf0x18);
linflp_k18_mtv_sid53_sid17_10_3(linflp_k18_gx18, linflp_k18_tmp1_10_1, linflp_k18_rrf0x18);
/* rrf0u */
linflp_k18_v_copy_2(linflp_k18_rf0u18, linflp_k18_rrf0u18);
linflp_k18_mtv_sid56_sid17_10_2(linflp_k18_gu18, linflp_k18_tmp1_10_1, linflp_k18_rrf0u18);
linflp_k18_error_source = 0;
}


static void linflp_k18_glqdocpip_rhs_iter_ref()
{
/* Zeitschritt 0 */
/* rf0x */
linflp_k18_mv_sid21_sid2_3_3(linflp_k18_Hxx0, linflp_k18_dx0, linflp_k18_rf0x0);
linflp_k18_mv_sid24_sid5_3_2(linflp_k18_Hxu0, linflp_k18_du0, linflp_k18_rf0x0);
linflp_k18_vsub_3(linflp_k18_rf0x0, linflp_k18_dp0, linflp_k18_rf0x0);
linflp_k18_mtv_sid42_sid2_3_3(linflp_k18_fx0, linflp_k18_dp1, linflp_k18_rf0x0);
linflp_k18_mtv_sid51_sid15_10_3(linflp_k18_gx0, linflp_k18_dy0, linflp_k18_rf0x0);
/* rf0u */
linflp_k18_mtv_sid24_sid2_3_2(linflp_k18_Hxu0, linflp_k18_dx0, linflp_k18_rf0u0);
linflp_k18_mv_sid27_sid5_2_2(linflp_k18_Huu0, linflp_k18_du0, linflp_k18_rf0u0);
linflp_k18_mtv_sid45_sid2_3_2(linflp_k18_fu0, linflp_k18_dp1, linflp_k18_rf0u0);
linflp_k18_mtv_sid54_sid15_10_2(linflp_k18_gu0, linflp_k18_dy0, linflp_k18_rf0u0);
/* rf */
linflp_k18_vsub_3(linflp_k18_rf0, linflp_k18_dx0, linflp_k18_rf0);
/* rc */
linflp_k18_mv_sid51_sid2_10_3(linflp_k18_gx0, linflp_k18_dx0, linflp_k18_rc0);
linflp_k18_mv_sid54_sid5_10_2(linflp_k18_gu0, linflp_k18_du0, linflp_k18_rc0);
linflp_k18_vadd_10(linflp_k18_rc0, linflp_k18_dnu0, linflp_k18_rc0);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy0, linflp_k18_nu0, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk0, linflp_k18_tmp2_10, linflp_k18_rk0);
linflp_k18_vv_elemult_10(linflp_k18_dnu0, linflp_k18_y0, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk0, linflp_k18_tmp2_10, linflp_k18_rk0);
/* Zeitschritt 1 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx1, linflp_k18_dx1, linflp_k18_rf0x1);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu1, linflp_k18_du1, linflp_k18_rf0x1);
linflp_k18_vsub_3(linflp_k18_rf0x1, linflp_k18_dp1, linflp_k18_rf0x1);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_dp2, linflp_k18_rf0x1);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx1, linflp_k18_dy1, linflp_k18_rf0x1);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu1, linflp_k18_dx1, linflp_k18_rf0u1);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu1, linflp_k18_du1, linflp_k18_rf0u1);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu1, linflp_k18_dp2, linflp_k18_rf0u1);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu1, linflp_k18_dy1, linflp_k18_rf0u1);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx0, linflp_k18_dx0, linflp_k18_rf1);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu0, linflp_k18_du0, linflp_k18_rf1);
linflp_k18_vsub_3(linflp_k18_rf1, linflp_k18_dx1, linflp_k18_rf1);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx1, linflp_k18_dx1, linflp_k18_rc1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu1, linflp_k18_du1, linflp_k18_rc1);
linflp_k18_vadd_10(linflp_k18_rc1, linflp_k18_dnu1, linflp_k18_rc1);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy1, linflp_k18_nu1, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk1, linflp_k18_tmp2_10, linflp_k18_rk1);
linflp_k18_vv_elemult_10(linflp_k18_dnu1, linflp_k18_y1, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk1, linflp_k18_tmp2_10, linflp_k18_rk1);
/* Zeitschritt 2 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx2, linflp_k18_dx2, linflp_k18_rf0x2);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu2, linflp_k18_du2, linflp_k18_rf0x2);
linflp_k18_vsub_3(linflp_k18_rf0x2, linflp_k18_dp2, linflp_k18_rf0x2);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_dp3, linflp_k18_rf0x2);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx2, linflp_k18_dy2, linflp_k18_rf0x2);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu2, linflp_k18_dx2, linflp_k18_rf0u2);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu2, linflp_k18_du2, linflp_k18_rf0u2);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu2, linflp_k18_dp3, linflp_k18_rf0u2);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu2, linflp_k18_dy2, linflp_k18_rf0u2);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx1, linflp_k18_dx1, linflp_k18_rf2);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu1, linflp_k18_du1, linflp_k18_rf2);
linflp_k18_vsub_3(linflp_k18_rf2, linflp_k18_dx2, linflp_k18_rf2);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx2, linflp_k18_dx2, linflp_k18_rc2);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu2, linflp_k18_du2, linflp_k18_rc2);
linflp_k18_vadd_10(linflp_k18_rc2, linflp_k18_dnu2, linflp_k18_rc2);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy2, linflp_k18_nu2, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk2, linflp_k18_tmp2_10, linflp_k18_rk2);
linflp_k18_vv_elemult_10(linflp_k18_dnu2, linflp_k18_y2, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk2, linflp_k18_tmp2_10, linflp_k18_rk2);
/* Zeitschritt 3 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx3, linflp_k18_dx3, linflp_k18_rf0x3);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu3, linflp_k18_du3, linflp_k18_rf0x3);
linflp_k18_vsub_3(linflp_k18_rf0x3, linflp_k18_dp3, linflp_k18_rf0x3);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_dp4, linflp_k18_rf0x3);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx3, linflp_k18_dy3, linflp_k18_rf0x3);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu3, linflp_k18_dx3, linflp_k18_rf0u3);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu3, linflp_k18_du3, linflp_k18_rf0u3);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu3, linflp_k18_dp4, linflp_k18_rf0u3);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu3, linflp_k18_dy3, linflp_k18_rf0u3);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx2, linflp_k18_dx2, linflp_k18_rf3);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu2, linflp_k18_du2, linflp_k18_rf3);
linflp_k18_vsub_3(linflp_k18_rf3, linflp_k18_dx3, linflp_k18_rf3);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx3, linflp_k18_dx3, linflp_k18_rc3);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu3, linflp_k18_du3, linflp_k18_rc3);
linflp_k18_vadd_10(linflp_k18_rc3, linflp_k18_dnu3, linflp_k18_rc3);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy3, linflp_k18_nu3, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk3, linflp_k18_tmp2_10, linflp_k18_rk3);
linflp_k18_vv_elemult_10(linflp_k18_dnu3, linflp_k18_y3, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk3, linflp_k18_tmp2_10, linflp_k18_rk3);
/* Zeitschritt 4 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx4, linflp_k18_dx4, linflp_k18_rf0x4);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu4, linflp_k18_du4, linflp_k18_rf0x4);
linflp_k18_vsub_3(linflp_k18_rf0x4, linflp_k18_dp4, linflp_k18_rf0x4);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_dp5, linflp_k18_rf0x4);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx4, linflp_k18_dy4, linflp_k18_rf0x4);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu4, linflp_k18_dx4, linflp_k18_rf0u4);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu4, linflp_k18_du4, linflp_k18_rf0u4);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu4, linflp_k18_dp5, linflp_k18_rf0u4);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu4, linflp_k18_dy4, linflp_k18_rf0u4);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx3, linflp_k18_dx3, linflp_k18_rf4);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu3, linflp_k18_du3, linflp_k18_rf4);
linflp_k18_vsub_3(linflp_k18_rf4, linflp_k18_dx4, linflp_k18_rf4);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx4, linflp_k18_dx4, linflp_k18_rc4);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu4, linflp_k18_du4, linflp_k18_rc4);
linflp_k18_vadd_10(linflp_k18_rc4, linflp_k18_dnu4, linflp_k18_rc4);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy4, linflp_k18_nu4, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk4, linflp_k18_tmp2_10, linflp_k18_rk4);
linflp_k18_vv_elemult_10(linflp_k18_dnu4, linflp_k18_y4, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk4, linflp_k18_tmp2_10, linflp_k18_rk4);
/* Zeitschritt 5 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx5, linflp_k18_dx5, linflp_k18_rf0x5);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu5, linflp_k18_du5, linflp_k18_rf0x5);
linflp_k18_vsub_3(linflp_k18_rf0x5, linflp_k18_dp5, linflp_k18_rf0x5);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_dp6, linflp_k18_rf0x5);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx5, linflp_k18_dy5, linflp_k18_rf0x5);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu5, linflp_k18_dx5, linflp_k18_rf0u5);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu5, linflp_k18_du5, linflp_k18_rf0u5);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu5, linflp_k18_dp6, linflp_k18_rf0u5);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu5, linflp_k18_dy5, linflp_k18_rf0u5);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx4, linflp_k18_dx4, linflp_k18_rf5);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu4, linflp_k18_du4, linflp_k18_rf5);
linflp_k18_vsub_3(linflp_k18_rf5, linflp_k18_dx5, linflp_k18_rf5);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx5, linflp_k18_dx5, linflp_k18_rc5);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu5, linflp_k18_du5, linflp_k18_rc5);
linflp_k18_vadd_10(linflp_k18_rc5, linflp_k18_dnu5, linflp_k18_rc5);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy5, linflp_k18_nu5, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk5, linflp_k18_tmp2_10, linflp_k18_rk5);
linflp_k18_vv_elemult_10(linflp_k18_dnu5, linflp_k18_y5, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk5, linflp_k18_tmp2_10, linflp_k18_rk5);
/* Zeitschritt 6 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx6, linflp_k18_dx6, linflp_k18_rf0x6);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu6, linflp_k18_du6, linflp_k18_rf0x6);
linflp_k18_vsub_3(linflp_k18_rf0x6, linflp_k18_dp6, linflp_k18_rf0x6);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_dp7, linflp_k18_rf0x6);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx6, linflp_k18_dy6, linflp_k18_rf0x6);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu6, linflp_k18_dx6, linflp_k18_rf0u6);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu6, linflp_k18_du6, linflp_k18_rf0u6);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu6, linflp_k18_dp7, linflp_k18_rf0u6);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu6, linflp_k18_dy6, linflp_k18_rf0u6);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx5, linflp_k18_dx5, linflp_k18_rf6);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu5, linflp_k18_du5, linflp_k18_rf6);
linflp_k18_vsub_3(linflp_k18_rf6, linflp_k18_dx6, linflp_k18_rf6);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx6, linflp_k18_dx6, linflp_k18_rc6);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu6, linflp_k18_du6, linflp_k18_rc6);
linflp_k18_vadd_10(linflp_k18_rc6, linflp_k18_dnu6, linflp_k18_rc6);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy6, linflp_k18_nu6, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk6, linflp_k18_tmp2_10, linflp_k18_rk6);
linflp_k18_vv_elemult_10(linflp_k18_dnu6, linflp_k18_y6, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk6, linflp_k18_tmp2_10, linflp_k18_rk6);
/* Zeitschritt 7 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx7, linflp_k18_dx7, linflp_k18_rf0x7);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu7, linflp_k18_du7, linflp_k18_rf0x7);
linflp_k18_vsub_3(linflp_k18_rf0x7, linflp_k18_dp7, linflp_k18_rf0x7);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_dp8, linflp_k18_rf0x7);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx7, linflp_k18_dy7, linflp_k18_rf0x7);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu7, linflp_k18_dx7, linflp_k18_rf0u7);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu7, linflp_k18_du7, linflp_k18_rf0u7);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu7, linflp_k18_dp8, linflp_k18_rf0u7);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu7, linflp_k18_dy7, linflp_k18_rf0u7);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx6, linflp_k18_dx6, linflp_k18_rf7);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu6, linflp_k18_du6, linflp_k18_rf7);
linflp_k18_vsub_3(linflp_k18_rf7, linflp_k18_dx7, linflp_k18_rf7);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx7, linflp_k18_dx7, linflp_k18_rc7);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu7, linflp_k18_du7, linflp_k18_rc7);
linflp_k18_vadd_10(linflp_k18_rc7, linflp_k18_dnu7, linflp_k18_rc7);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy7, linflp_k18_nu7, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk7, linflp_k18_tmp2_10, linflp_k18_rk7);
linflp_k18_vv_elemult_10(linflp_k18_dnu7, linflp_k18_y7, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk7, linflp_k18_tmp2_10, linflp_k18_rk7);
/* Zeitschritt 8 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx8, linflp_k18_dx8, linflp_k18_rf0x8);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu8, linflp_k18_du8, linflp_k18_rf0x8);
linflp_k18_vsub_3(linflp_k18_rf0x8, linflp_k18_dp8, linflp_k18_rf0x8);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_dp9, linflp_k18_rf0x8);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx8, linflp_k18_dy8, linflp_k18_rf0x8);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu8, linflp_k18_dx8, linflp_k18_rf0u8);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu8, linflp_k18_du8, linflp_k18_rf0u8);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu8, linflp_k18_dp9, linflp_k18_rf0u8);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu8, linflp_k18_dy8, linflp_k18_rf0u8);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx7, linflp_k18_dx7, linflp_k18_rf8);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu7, linflp_k18_du7, linflp_k18_rf8);
linflp_k18_vsub_3(linflp_k18_rf8, linflp_k18_dx8, linflp_k18_rf8);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx8, linflp_k18_dx8, linflp_k18_rc8);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu8, linflp_k18_du8, linflp_k18_rc8);
linflp_k18_vadd_10(linflp_k18_rc8, linflp_k18_dnu8, linflp_k18_rc8);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy8, linflp_k18_nu8, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk8, linflp_k18_tmp2_10, linflp_k18_rk8);
linflp_k18_vv_elemult_10(linflp_k18_dnu8, linflp_k18_y8, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk8, linflp_k18_tmp2_10, linflp_k18_rk8);
/* Zeitschritt 9 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx9, linflp_k18_dx9, linflp_k18_rf0x9);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu9, linflp_k18_du9, linflp_k18_rf0x9);
linflp_k18_vsub_3(linflp_k18_rf0x9, linflp_k18_dp9, linflp_k18_rf0x9);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_dp10, linflp_k18_rf0x9);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx9, linflp_k18_dy9, linflp_k18_rf0x9);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu9, linflp_k18_dx9, linflp_k18_rf0u9);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu9, linflp_k18_du9, linflp_k18_rf0u9);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu9, linflp_k18_dp10, linflp_k18_rf0u9);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu9, linflp_k18_dy9, linflp_k18_rf0u9);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx8, linflp_k18_dx8, linflp_k18_rf9);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu8, linflp_k18_du8, linflp_k18_rf9);
linflp_k18_vsub_3(linflp_k18_rf9, linflp_k18_dx9, linflp_k18_rf9);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx9, linflp_k18_dx9, linflp_k18_rc9);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu9, linflp_k18_du9, linflp_k18_rc9);
linflp_k18_vadd_10(linflp_k18_rc9, linflp_k18_dnu9, linflp_k18_rc9);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy9, linflp_k18_nu9, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk9, linflp_k18_tmp2_10, linflp_k18_rk9);
linflp_k18_vv_elemult_10(linflp_k18_dnu9, linflp_k18_y9, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk9, linflp_k18_tmp2_10, linflp_k18_rk9);
/* Zeitschritt 10 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx10, linflp_k18_dx10, linflp_k18_rf0x10);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu10, linflp_k18_du10, linflp_k18_rf0x10);
linflp_k18_vsub_3(linflp_k18_rf0x10, linflp_k18_dp10, linflp_k18_rf0x10);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_dp11, linflp_k18_rf0x10);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx10, linflp_k18_dy10, linflp_k18_rf0x10);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu10, linflp_k18_dx10, linflp_k18_rf0u10);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu10, linflp_k18_du10, linflp_k18_rf0u10);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu10, linflp_k18_dp11, linflp_k18_rf0u10);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu10, linflp_k18_dy10, linflp_k18_rf0u10);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx9, linflp_k18_dx9, linflp_k18_rf10);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu9, linflp_k18_du9, linflp_k18_rf10);
linflp_k18_vsub_3(linflp_k18_rf10, linflp_k18_dx10, linflp_k18_rf10);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx10, linflp_k18_dx10, linflp_k18_rc10);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu10, linflp_k18_du10, linflp_k18_rc10);
linflp_k18_vadd_10(linflp_k18_rc10, linflp_k18_dnu10, linflp_k18_rc10);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy10, linflp_k18_nu10, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk10, linflp_k18_tmp2_10, linflp_k18_rk10);
linflp_k18_vv_elemult_10(linflp_k18_dnu10, linflp_k18_y10, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk10, linflp_k18_tmp2_10, linflp_k18_rk10);
/* Zeitschritt 11 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx11, linflp_k18_dx11, linflp_k18_rf0x11);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu11, linflp_k18_du11, linflp_k18_rf0x11);
linflp_k18_vsub_3(linflp_k18_rf0x11, linflp_k18_dp11, linflp_k18_rf0x11);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_dp12, linflp_k18_rf0x11);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx11, linflp_k18_dy11, linflp_k18_rf0x11);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu11, linflp_k18_dx11, linflp_k18_rf0u11);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu11, linflp_k18_du11, linflp_k18_rf0u11);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu11, linflp_k18_dp12, linflp_k18_rf0u11);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu11, linflp_k18_dy11, linflp_k18_rf0u11);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx10, linflp_k18_dx10, linflp_k18_rf11);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu10, linflp_k18_du10, linflp_k18_rf11);
linflp_k18_vsub_3(linflp_k18_rf11, linflp_k18_dx11, linflp_k18_rf11);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx11, linflp_k18_dx11, linflp_k18_rc11);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu11, linflp_k18_du11, linflp_k18_rc11);
linflp_k18_vadd_10(linflp_k18_rc11, linflp_k18_dnu11, linflp_k18_rc11);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy11, linflp_k18_nu11, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk11, linflp_k18_tmp2_10, linflp_k18_rk11);
linflp_k18_vv_elemult_10(linflp_k18_dnu11, linflp_k18_y11, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk11, linflp_k18_tmp2_10, linflp_k18_rk11);
/* Zeitschritt 12 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx12, linflp_k18_dx12, linflp_k18_rf0x12);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu12, linflp_k18_du12, linflp_k18_rf0x12);
linflp_k18_vsub_3(linflp_k18_rf0x12, linflp_k18_dp12, linflp_k18_rf0x12);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_dp13, linflp_k18_rf0x12);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx12, linflp_k18_dy12, linflp_k18_rf0x12);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu12, linflp_k18_dx12, linflp_k18_rf0u12);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu12, linflp_k18_du12, linflp_k18_rf0u12);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu12, linflp_k18_dp13, linflp_k18_rf0u12);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu12, linflp_k18_dy12, linflp_k18_rf0u12);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx11, linflp_k18_dx11, linflp_k18_rf12);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu11, linflp_k18_du11, linflp_k18_rf12);
linflp_k18_vsub_3(linflp_k18_rf12, linflp_k18_dx12, linflp_k18_rf12);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx12, linflp_k18_dx12, linflp_k18_rc12);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu12, linflp_k18_du12, linflp_k18_rc12);
linflp_k18_vadd_10(linflp_k18_rc12, linflp_k18_dnu12, linflp_k18_rc12);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy12, linflp_k18_nu12, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk12, linflp_k18_tmp2_10, linflp_k18_rk12);
linflp_k18_vv_elemult_10(linflp_k18_dnu12, linflp_k18_y12, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk12, linflp_k18_tmp2_10, linflp_k18_rk12);
/* Zeitschritt 13 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx13, linflp_k18_dx13, linflp_k18_rf0x13);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu13, linflp_k18_du13, linflp_k18_rf0x13);
linflp_k18_vsub_3(linflp_k18_rf0x13, linflp_k18_dp13, linflp_k18_rf0x13);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_dp14, linflp_k18_rf0x13);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx13, linflp_k18_dy13, linflp_k18_rf0x13);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu13, linflp_k18_dx13, linflp_k18_rf0u13);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu13, linflp_k18_du13, linflp_k18_rf0u13);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu13, linflp_k18_dp14, linflp_k18_rf0u13);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu13, linflp_k18_dy13, linflp_k18_rf0u13);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx12, linflp_k18_dx12, linflp_k18_rf13);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu12, linflp_k18_du12, linflp_k18_rf13);
linflp_k18_vsub_3(linflp_k18_rf13, linflp_k18_dx13, linflp_k18_rf13);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx13, linflp_k18_dx13, linflp_k18_rc13);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu13, linflp_k18_du13, linflp_k18_rc13);
linflp_k18_vadd_10(linflp_k18_rc13, linflp_k18_dnu13, linflp_k18_rc13);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy13, linflp_k18_nu13, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk13, linflp_k18_tmp2_10, linflp_k18_rk13);
linflp_k18_vv_elemult_10(linflp_k18_dnu13, linflp_k18_y13, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk13, linflp_k18_tmp2_10, linflp_k18_rk13);
/* Zeitschritt 14 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx14, linflp_k18_dx14, linflp_k18_rf0x14);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu14, linflp_k18_du14, linflp_k18_rf0x14);
linflp_k18_vsub_3(linflp_k18_rf0x14, linflp_k18_dp14, linflp_k18_rf0x14);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_dp15, linflp_k18_rf0x14);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx14, linflp_k18_dy14, linflp_k18_rf0x14);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu14, linflp_k18_dx14, linflp_k18_rf0u14);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu14, linflp_k18_du14, linflp_k18_rf0u14);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu14, linflp_k18_dp15, linflp_k18_rf0u14);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu14, linflp_k18_dy14, linflp_k18_rf0u14);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx13, linflp_k18_dx13, linflp_k18_rf14);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu13, linflp_k18_du13, linflp_k18_rf14);
linflp_k18_vsub_3(linflp_k18_rf14, linflp_k18_dx14, linflp_k18_rf14);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx14, linflp_k18_dx14, linflp_k18_rc14);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu14, linflp_k18_du14, linflp_k18_rc14);
linflp_k18_vadd_10(linflp_k18_rc14, linflp_k18_dnu14, linflp_k18_rc14);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy14, linflp_k18_nu14, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk14, linflp_k18_tmp2_10, linflp_k18_rk14);
linflp_k18_vv_elemult_10(linflp_k18_dnu14, linflp_k18_y14, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk14, linflp_k18_tmp2_10, linflp_k18_rk14);
/* Zeitschritt 15 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx15, linflp_k18_dx15, linflp_k18_rf0x15);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu15, linflp_k18_du15, linflp_k18_rf0x15);
linflp_k18_vsub_3(linflp_k18_rf0x15, linflp_k18_dp15, linflp_k18_rf0x15);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_dp16, linflp_k18_rf0x15);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx15, linflp_k18_dy15, linflp_k18_rf0x15);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu15, linflp_k18_dx15, linflp_k18_rf0u15);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu15, linflp_k18_du15, linflp_k18_rf0u15);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu15, linflp_k18_dp16, linflp_k18_rf0u15);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu15, linflp_k18_dy15, linflp_k18_rf0u15);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx14, linflp_k18_dx14, linflp_k18_rf15);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu14, linflp_k18_du14, linflp_k18_rf15);
linflp_k18_vsub_3(linflp_k18_rf15, linflp_k18_dx15, linflp_k18_rf15);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx15, linflp_k18_dx15, linflp_k18_rc15);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu15, linflp_k18_du15, linflp_k18_rc15);
linflp_k18_vadd_10(linflp_k18_rc15, linflp_k18_dnu15, linflp_k18_rc15);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy15, linflp_k18_nu15, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk15, linflp_k18_tmp2_10, linflp_k18_rk15);
linflp_k18_vv_elemult_10(linflp_k18_dnu15, linflp_k18_y15, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk15, linflp_k18_tmp2_10, linflp_k18_rk15);
/* Zeitschritt 16 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx16, linflp_k18_dx16, linflp_k18_rf0x16);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu16, linflp_k18_du16, linflp_k18_rf0x16);
linflp_k18_vsub_3(linflp_k18_rf0x16, linflp_k18_dp16, linflp_k18_rf0x16);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_dp17, linflp_k18_rf0x16);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx16, linflp_k18_dy16, linflp_k18_rf0x16);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu16, linflp_k18_dx16, linflp_k18_rf0u16);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu16, linflp_k18_du16, linflp_k18_rf0u16);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu16, linflp_k18_dp17, linflp_k18_rf0u16);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu16, linflp_k18_dy16, linflp_k18_rf0u16);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx15, linflp_k18_dx15, linflp_k18_rf16);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu15, linflp_k18_du15, linflp_k18_rf16);
linflp_k18_vsub_3(linflp_k18_rf16, linflp_k18_dx16, linflp_k18_rf16);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx16, linflp_k18_dx16, linflp_k18_rc16);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu16, linflp_k18_du16, linflp_k18_rc16);
linflp_k18_vadd_10(linflp_k18_rc16, linflp_k18_dnu16, linflp_k18_rc16);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy16, linflp_k18_nu16, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk16, linflp_k18_tmp2_10, linflp_k18_rk16);
linflp_k18_vv_elemult_10(linflp_k18_dnu16, linflp_k18_y16, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk16, linflp_k18_tmp2_10, linflp_k18_rk16);
/* Zeitschritt 17 */
/* rf0x */
linflp_k18_mv_sid22_sid2_3_3(linflp_k18_Hxx17, linflp_k18_dx17, linflp_k18_rf0x17);
linflp_k18_mv_sid25_sid5_3_2(linflp_k18_Hxu17, linflp_k18_du17, linflp_k18_rf0x17);
linflp_k18_vsub_3(linflp_k18_rf0x17, linflp_k18_dp17, linflp_k18_rf0x17);
linflp_k18_mtv_sid43_sid2_3_3(linflp_k18_fx17, linflp_k18_dp18, linflp_k18_rf0x17);
linflp_k18_mtv_sid52_sid16_10_3(linflp_k18_gx17, linflp_k18_dy17, linflp_k18_rf0x17);
/* rf0u */
linflp_k18_mtv_sid25_sid2_3_2(linflp_k18_Hxu17, linflp_k18_dx17, linflp_k18_rf0u17);
linflp_k18_mv_sid28_sid5_2_2(linflp_k18_Huu17, linflp_k18_du17, linflp_k18_rf0u17);
linflp_k18_mtv_sid46_sid2_3_2(linflp_k18_fu17, linflp_k18_dp18, linflp_k18_rf0u17);
linflp_k18_mtv_sid55_sid16_10_2(linflp_k18_gu17, linflp_k18_dy17, linflp_k18_rf0u17);
/* rf */
linflp_k18_mv_sid43_sid2_3_3(linflp_k18_fx16, linflp_k18_dx16, linflp_k18_rf17);
linflp_k18_mv_sid46_sid5_3_2(linflp_k18_fu16, linflp_k18_du16, linflp_k18_rf17);
linflp_k18_vsub_3(linflp_k18_rf17, linflp_k18_dx17, linflp_k18_rf17);
/* rc */
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx17, linflp_k18_dx17, linflp_k18_rc17);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu17, linflp_k18_du17, linflp_k18_rc17);
linflp_k18_vadd_10(linflp_k18_rc17, linflp_k18_dnu17, linflp_k18_rc17);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy17, linflp_k18_nu17, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk17, linflp_k18_tmp2_10, linflp_k18_rk17);
linflp_k18_vv_elemult_10(linflp_k18_dnu17, linflp_k18_y17, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk17, linflp_k18_tmp2_10, linflp_k18_rk17);
/* Zeitschritt 18 */
/* rf0x */
linflp_k18_mv_sid23_sid2_3_3(linflp_k18_Hxx18, linflp_k18_dx18, linflp_k18_rf0x18);
linflp_k18_mv_sid26_sid5_3_2(linflp_k18_Hxu18, linflp_k18_du18, linflp_k18_rf0x18);
linflp_k18_vsub_3(linflp_k18_rf0x18, linflp_k18_dp18, linflp_k18_rf0x18);
linflp_k18_mtv_sid53_sid17_10_3(linflp_k18_gx18, linflp_k18_dy18, linflp_k18_rf0x18);
/* rf0u */
linflp_k18_mtv_sid26_sid2_3_2(linflp_k18_Hxu18, linflp_k18_dx18, linflp_k18_rf0u18);
linflp_k18_mv_sid29_sid5_2_2(linflp_k18_Huu18, linflp_k18_du18, linflp_k18_rf0u18);
linflp_k18_mtv_sid56_sid17_10_2(linflp_k18_gu18, linflp_k18_dy18, linflp_k18_rf0u18);
/* rf */
linflp_k18_mv_sid44_sid2_3_3(linflp_k18_fx17, linflp_k18_dx17, linflp_k18_rf18);
linflp_k18_mv_sid47_sid5_3_2(linflp_k18_fu17, linflp_k18_du17, linflp_k18_rf18);
linflp_k18_vsub_3(linflp_k18_rf18, linflp_k18_dx18, linflp_k18_rf18);
/* rc */
linflp_k18_mv_sid53_sid2_10_3(linflp_k18_gx18, linflp_k18_dx18, linflp_k18_rc18);
linflp_k18_mv_sid56_sid5_10_2(linflp_k18_gu18, linflp_k18_du18, linflp_k18_rc18);
linflp_k18_vadd_10(linflp_k18_rc18, linflp_k18_dnu18, linflp_k18_rc18);
/* rk */
linflp_k18_vv_elemult_10(linflp_k18_dy18, linflp_k18_nu18, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk18, linflp_k18_tmp2_10, linflp_k18_rk18);
linflp_k18_vv_elemult_10(linflp_k18_dnu18, linflp_k18_y18, linflp_k18_tmp2_10);
linflp_k18_vadd_10(linflp_k18_rk18, linflp_k18_tmp2_10, linflp_k18_rk18);
}


static void linflp_k18_glqdocpip_dereduce()
{
linflp_k18_error_source = 4;
/* Zeitschritt 0 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs0, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc0[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid51_sid2_10_3(linflp_k18_gx0, linflp_k18_dx0, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid54_sid5_10_2(linflp_k18_gu0, linflp_k18_du0, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk0[0], &linflp_k18_y0[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny0, linflp_k18_tmp1_10_1, linflp_k18_dy0);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu0, linflp_k18_dy0, linflp_k18_dnu0);
linflp_k18_vadd_10(linflp_k18_dnu0, linflp_k18_rk0, linflp_k18_dnu0);
linflp_k18_vv_elediv_10(linflp_k18_dnu0, linflp_k18_y0, linflp_k18_dnu0);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu0, linflp_k18_dnu0);
/* Zeitschritt 1 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs1, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc1[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx1, linflp_k18_dx1, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu1, linflp_k18_du1, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk1[0], &linflp_k18_y1[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny1, linflp_k18_tmp1_10_1, linflp_k18_dy1);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu1, linflp_k18_dy1, linflp_k18_dnu1);
linflp_k18_vadd_10(linflp_k18_dnu1, linflp_k18_rk1, linflp_k18_dnu1);
linflp_k18_vv_elediv_10(linflp_k18_dnu1, linflp_k18_y1, linflp_k18_dnu1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu1, linflp_k18_dnu1);
/* Zeitschritt 2 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs2, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc2[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx2, linflp_k18_dx2, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu2, linflp_k18_du2, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk2[0], &linflp_k18_y2[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny2, linflp_k18_tmp1_10_1, linflp_k18_dy2);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu2, linflp_k18_dy2, linflp_k18_dnu2);
linflp_k18_vadd_10(linflp_k18_dnu2, linflp_k18_rk2, linflp_k18_dnu2);
linflp_k18_vv_elediv_10(linflp_k18_dnu2, linflp_k18_y2, linflp_k18_dnu2);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu2, linflp_k18_dnu2);
/* Zeitschritt 3 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs3, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc3[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx3, linflp_k18_dx3, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu3, linflp_k18_du3, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk3[0], &linflp_k18_y3[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny3, linflp_k18_tmp1_10_1, linflp_k18_dy3);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu3, linflp_k18_dy3, linflp_k18_dnu3);
linflp_k18_vadd_10(linflp_k18_dnu3, linflp_k18_rk3, linflp_k18_dnu3);
linflp_k18_vv_elediv_10(linflp_k18_dnu3, linflp_k18_y3, linflp_k18_dnu3);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu3, linflp_k18_dnu3);
/* Zeitschritt 4 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs4, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc4[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx4, linflp_k18_dx4, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu4, linflp_k18_du4, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk4[0], &linflp_k18_y4[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny4, linflp_k18_tmp1_10_1, linflp_k18_dy4);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu4, linflp_k18_dy4, linflp_k18_dnu4);
linflp_k18_vadd_10(linflp_k18_dnu4, linflp_k18_rk4, linflp_k18_dnu4);
linflp_k18_vv_elediv_10(linflp_k18_dnu4, linflp_k18_y4, linflp_k18_dnu4);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu4, linflp_k18_dnu4);
/* Zeitschritt 5 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs5, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc5[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx5, linflp_k18_dx5, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu5, linflp_k18_du5, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk5[0], &linflp_k18_y5[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny5, linflp_k18_tmp1_10_1, linflp_k18_dy5);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu5, linflp_k18_dy5, linflp_k18_dnu5);
linflp_k18_vadd_10(linflp_k18_dnu5, linflp_k18_rk5, linflp_k18_dnu5);
linflp_k18_vv_elediv_10(linflp_k18_dnu5, linflp_k18_y5, linflp_k18_dnu5);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu5, linflp_k18_dnu5);
/* Zeitschritt 6 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs6, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc6[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx6, linflp_k18_dx6, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu6, linflp_k18_du6, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk6[0], &linflp_k18_y6[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny6, linflp_k18_tmp1_10_1, linflp_k18_dy6);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu6, linflp_k18_dy6, linflp_k18_dnu6);
linflp_k18_vadd_10(linflp_k18_dnu6, linflp_k18_rk6, linflp_k18_dnu6);
linflp_k18_vv_elediv_10(linflp_k18_dnu6, linflp_k18_y6, linflp_k18_dnu6);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu6, linflp_k18_dnu6);
/* Zeitschritt 7 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs7, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc7[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx7, linflp_k18_dx7, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu7, linflp_k18_du7, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk7[0], &linflp_k18_y7[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny7, linflp_k18_tmp1_10_1, linflp_k18_dy7);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu7, linflp_k18_dy7, linflp_k18_dnu7);
linflp_k18_vadd_10(linflp_k18_dnu7, linflp_k18_rk7, linflp_k18_dnu7);
linflp_k18_vv_elediv_10(linflp_k18_dnu7, linflp_k18_y7, linflp_k18_dnu7);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu7, linflp_k18_dnu7);
/* Zeitschritt 8 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs8, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc8[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx8, linflp_k18_dx8, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu8, linflp_k18_du8, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk8[0], &linflp_k18_y8[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny8, linflp_k18_tmp1_10_1, linflp_k18_dy8);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu8, linflp_k18_dy8, linflp_k18_dnu8);
linflp_k18_vadd_10(linflp_k18_dnu8, linflp_k18_rk8, linflp_k18_dnu8);
linflp_k18_vv_elediv_10(linflp_k18_dnu8, linflp_k18_y8, linflp_k18_dnu8);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu8, linflp_k18_dnu8);
/* Zeitschritt 9 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs9, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc9[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx9, linflp_k18_dx9, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu9, linflp_k18_du9, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk9[0], &linflp_k18_y9[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny9, linflp_k18_tmp1_10_1, linflp_k18_dy9);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu9, linflp_k18_dy9, linflp_k18_dnu9);
linflp_k18_vadd_10(linflp_k18_dnu9, linflp_k18_rk9, linflp_k18_dnu9);
linflp_k18_vv_elediv_10(linflp_k18_dnu9, linflp_k18_y9, linflp_k18_dnu9);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu9, linflp_k18_dnu9);
/* Zeitschritt 10 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs10, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc10[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx10, linflp_k18_dx10, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu10, linflp_k18_du10, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk10[0], &linflp_k18_y10[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny10, linflp_k18_tmp1_10_1, linflp_k18_dy10);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu10, linflp_k18_dy10, linflp_k18_dnu10);
linflp_k18_vadd_10(linflp_k18_dnu10, linflp_k18_rk10, linflp_k18_dnu10);
linflp_k18_vv_elediv_10(linflp_k18_dnu10, linflp_k18_y10, linflp_k18_dnu10);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu10, linflp_k18_dnu10);
/* Zeitschritt 11 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs11, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc11[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx11, linflp_k18_dx11, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu11, linflp_k18_du11, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk11[0], &linflp_k18_y11[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny11, linflp_k18_tmp1_10_1, linflp_k18_dy11);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu11, linflp_k18_dy11, linflp_k18_dnu11);
linflp_k18_vadd_10(linflp_k18_dnu11, linflp_k18_rk11, linflp_k18_dnu11);
linflp_k18_vv_elediv_10(linflp_k18_dnu11, linflp_k18_y11, linflp_k18_dnu11);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu11, linflp_k18_dnu11);
/* Zeitschritt 12 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs12, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc12[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx12, linflp_k18_dx12, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu12, linflp_k18_du12, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk12[0], &linflp_k18_y12[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny12, linflp_k18_tmp1_10_1, linflp_k18_dy12);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu12, linflp_k18_dy12, linflp_k18_dnu12);
linflp_k18_vadd_10(linflp_k18_dnu12, linflp_k18_rk12, linflp_k18_dnu12);
linflp_k18_vv_elediv_10(linflp_k18_dnu12, linflp_k18_y12, linflp_k18_dnu12);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu12, linflp_k18_dnu12);
/* Zeitschritt 13 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs13, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc13[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx13, linflp_k18_dx13, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu13, linflp_k18_du13, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk13[0], &linflp_k18_y13[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny13, linflp_k18_tmp1_10_1, linflp_k18_dy13);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu13, linflp_k18_dy13, linflp_k18_dnu13);
linflp_k18_vadd_10(linflp_k18_dnu13, linflp_k18_rk13, linflp_k18_dnu13);
linflp_k18_vv_elediv_10(linflp_k18_dnu13, linflp_k18_y13, linflp_k18_dnu13);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu13, linflp_k18_dnu13);
/* Zeitschritt 14 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs14, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc14[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx14, linflp_k18_dx14, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu14, linflp_k18_du14, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk14[0], &linflp_k18_y14[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny14, linflp_k18_tmp1_10_1, linflp_k18_dy14);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu14, linflp_k18_dy14, linflp_k18_dnu14);
linflp_k18_vadd_10(linflp_k18_dnu14, linflp_k18_rk14, linflp_k18_dnu14);
linflp_k18_vv_elediv_10(linflp_k18_dnu14, linflp_k18_y14, linflp_k18_dnu14);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu14, linflp_k18_dnu14);
/* Zeitschritt 15 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs15, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc15[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx15, linflp_k18_dx15, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu15, linflp_k18_du15, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk15[0], &linflp_k18_y15[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny15, linflp_k18_tmp1_10_1, linflp_k18_dy15);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu15, linflp_k18_dy15, linflp_k18_dnu15);
linflp_k18_vadd_10(linflp_k18_dnu15, linflp_k18_rk15, linflp_k18_dnu15);
linflp_k18_vv_elediv_10(linflp_k18_dnu15, linflp_k18_y15, linflp_k18_dnu15);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu15, linflp_k18_dnu15);
/* Zeitschritt 16 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs16, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc16[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx16, linflp_k18_dx16, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu16, linflp_k18_du16, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk16[0], &linflp_k18_y16[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny16, linflp_k18_tmp1_10_1, linflp_k18_dy16);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu16, linflp_k18_dy16, linflp_k18_dnu16);
linflp_k18_vadd_10(linflp_k18_dnu16, linflp_k18_rk16, linflp_k18_dnu16);
linflp_k18_vv_elediv_10(linflp_k18_dnu16, linflp_k18_y16, linflp_k18_dnu16);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu16, linflp_k18_dnu16);
/* Zeitschritt 17 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs17, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc17[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid52_sid2_10_3(linflp_k18_gx17, linflp_k18_dx17, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid55_sid5_10_2(linflp_k18_gu17, linflp_k18_du17, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk17[0], &linflp_k18_y17[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny17, linflp_k18_tmp1_10_1, linflp_k18_dy17);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu17, linflp_k18_dy17, linflp_k18_dnu17);
linflp_k18_vadd_10(linflp_k18_dnu17, linflp_k18_rk17, linflp_k18_dnu17);
linflp_k18_vv_elediv_10(linflp_k18_dnu17, linflp_k18_y17, linflp_k18_dnu17);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu17, linflp_k18_dnu17);
/* Zeitschritt 18 */
/* dy */
/* Hilfsvektor */
linflp_k18_v_init0_10(linflp_k18_tmp1_10_1);
linflp_k18_m_copy_0_1(linflp_k18_rhsxs18, linflp_k18_tmp1_10_1);
linflp_k18_m_copy_10_1(&linflp_k18_rc18[0], &linflp_k18_tmp1_10_1[0]);
linflp_k18_mv_sid53_sid2_10_3(linflp_k18_gx18, linflp_k18_dx18, linflp_k18_tmp1_10_1);
linflp_k18_mv_sid56_sid5_10_2(linflp_k18_gu18, linflp_k18_du18, linflp_k18_tmp1_10_1);
/* dy_u */
linflp_k18_vv_elediv_10(&linflp_k18_rk18[0], &linflp_k18_y18[0], linflp_k18_tmp2_10_1);
if(linflp_k18_termcode > -1){return;}
linflp_k18_vsub_10(&linflp_k18_tmp1_10_1[0], linflp_k18_tmp2_10_1, &linflp_k18_tmp1_10_1[0]);
linflp_k18_vv_elemult_10(linflp_k18_yny18, linflp_k18_tmp1_10_1, linflp_k18_dy18);
/* dnu */
linflp_k18_vv_elemult_10(linflp_k18_nu18, linflp_k18_dy18, linflp_k18_dnu18);
linflp_k18_vadd_10(linflp_k18_dnu18, linflp_k18_rk18, linflp_k18_dnu18);
linflp_k18_vv_elediv_10(linflp_k18_dnu18, linflp_k18_y18, linflp_k18_dnu18);
if(linflp_k18_termcode > -1){return;}
linflp_k18_v_turnsign_10(linflp_k18_dnu18, linflp_k18_dnu18);
linflp_k18_error_source = 0;

}


/* ###################################################### */
/* Diese Funktion berechnet f�hrt die Nachiteration durch */
/* ###################################################### */
static void linflp_k18_glqdocpip_iter_ref()
{
if(linflp_k18_iter_ref == 1){
linflp_k18_stat_num_iter_ref++;
linflp_k18_stat_iter_ref[linflp_k18_iter] = 1;
/* L�sung sichern */
linflp_k18_v_copy_3(linflp_k18_dx0, linflp_k18_dx_ir0);
linflp_k18_v_copy_2(linflp_k18_du0, linflp_k18_du_ir0);
linflp_k18_v_copy_3(linflp_k18_dp0, linflp_k18_dp_ir0);
linflp_k18_v_copy_10(linflp_k18_dy0, linflp_k18_dy_ir0);
linflp_k18_v_copy_10(linflp_k18_dnu0, linflp_k18_dnu_ir0);
linflp_k18_v_copy_3(linflp_k18_dx1, linflp_k18_dx_ir1);
linflp_k18_v_copy_2(linflp_k18_du1, linflp_k18_du_ir1);
linflp_k18_v_copy_3(linflp_k18_dp1, linflp_k18_dp_ir1);
linflp_k18_v_copy_10(linflp_k18_dy1, linflp_k18_dy_ir1);
linflp_k18_v_copy_10(linflp_k18_dnu1, linflp_k18_dnu_ir1);
linflp_k18_v_copy_3(linflp_k18_dx2, linflp_k18_dx_ir2);
linflp_k18_v_copy_2(linflp_k18_du2, linflp_k18_du_ir2);
linflp_k18_v_copy_3(linflp_k18_dp2, linflp_k18_dp_ir2);
linflp_k18_v_copy_10(linflp_k18_dy2, linflp_k18_dy_ir2);
linflp_k18_v_copy_10(linflp_k18_dnu2, linflp_k18_dnu_ir2);
linflp_k18_v_copy_3(linflp_k18_dx3, linflp_k18_dx_ir3);
linflp_k18_v_copy_2(linflp_k18_du3, linflp_k18_du_ir3);
linflp_k18_v_copy_3(linflp_k18_dp3, linflp_k18_dp_ir3);
linflp_k18_v_copy_10(linflp_k18_dy3, linflp_k18_dy_ir3);
linflp_k18_v_copy_10(linflp_k18_dnu3, linflp_k18_dnu_ir3);
linflp_k18_v_copy_3(linflp_k18_dx4, linflp_k18_dx_ir4);
linflp_k18_v_copy_2(linflp_k18_du4, linflp_k18_du_ir4);
linflp_k18_v_copy_3(linflp_k18_dp4, linflp_k18_dp_ir4);
linflp_k18_v_copy_10(linflp_k18_dy4, linflp_k18_dy_ir4);
linflp_k18_v_copy_10(linflp_k18_dnu4, linflp_k18_dnu_ir4);
linflp_k18_v_copy_3(linflp_k18_dx5, linflp_k18_dx_ir5);
linflp_k18_v_copy_2(linflp_k18_du5, linflp_k18_du_ir5);
linflp_k18_v_copy_3(linflp_k18_dp5, linflp_k18_dp_ir5);
linflp_k18_v_copy_10(linflp_k18_dy5, linflp_k18_dy_ir5);
linflp_k18_v_copy_10(linflp_k18_dnu5, linflp_k18_dnu_ir5);
linflp_k18_v_copy_3(linflp_k18_dx6, linflp_k18_dx_ir6);
linflp_k18_v_copy_2(linflp_k18_du6, linflp_k18_du_ir6);
linflp_k18_v_copy_3(linflp_k18_dp6, linflp_k18_dp_ir6);
linflp_k18_v_copy_10(linflp_k18_dy6, linflp_k18_dy_ir6);
linflp_k18_v_copy_10(linflp_k18_dnu6, linflp_k18_dnu_ir6);
linflp_k18_v_copy_3(linflp_k18_dx7, linflp_k18_dx_ir7);
linflp_k18_v_copy_2(linflp_k18_du7, linflp_k18_du_ir7);
linflp_k18_v_copy_3(linflp_k18_dp7, linflp_k18_dp_ir7);
linflp_k18_v_copy_10(linflp_k18_dy7, linflp_k18_dy_ir7);
linflp_k18_v_copy_10(linflp_k18_dnu7, linflp_k18_dnu_ir7);
linflp_k18_v_copy_3(linflp_k18_dx8, linflp_k18_dx_ir8);
linflp_k18_v_copy_2(linflp_k18_du8, linflp_k18_du_ir8);
linflp_k18_v_copy_3(linflp_k18_dp8, linflp_k18_dp_ir8);
linflp_k18_v_copy_10(linflp_k18_dy8, linflp_k18_dy_ir8);
linflp_k18_v_copy_10(linflp_k18_dnu8, linflp_k18_dnu_ir8);
linflp_k18_v_copy_3(linflp_k18_dx9, linflp_k18_dx_ir9);
linflp_k18_v_copy_2(linflp_k18_du9, linflp_k18_du_ir9);
linflp_k18_v_copy_3(linflp_k18_dp9, linflp_k18_dp_ir9);
linflp_k18_v_copy_10(linflp_k18_dy9, linflp_k18_dy_ir9);
linflp_k18_v_copy_10(linflp_k18_dnu9, linflp_k18_dnu_ir9);
linflp_k18_v_copy_3(linflp_k18_dx10, linflp_k18_dx_ir10);
linflp_k18_v_copy_2(linflp_k18_du10, linflp_k18_du_ir10);
linflp_k18_v_copy_3(linflp_k18_dp10, linflp_k18_dp_ir10);
linflp_k18_v_copy_10(linflp_k18_dy10, linflp_k18_dy_ir10);
linflp_k18_v_copy_10(linflp_k18_dnu10, linflp_k18_dnu_ir10);
linflp_k18_v_copy_3(linflp_k18_dx11, linflp_k18_dx_ir11);
linflp_k18_v_copy_2(linflp_k18_du11, linflp_k18_du_ir11);
linflp_k18_v_copy_3(linflp_k18_dp11, linflp_k18_dp_ir11);
linflp_k18_v_copy_10(linflp_k18_dy11, linflp_k18_dy_ir11);
linflp_k18_v_copy_10(linflp_k18_dnu11, linflp_k18_dnu_ir11);
linflp_k18_v_copy_3(linflp_k18_dx12, linflp_k18_dx_ir12);
linflp_k18_v_copy_2(linflp_k18_du12, linflp_k18_du_ir12);
linflp_k18_v_copy_3(linflp_k18_dp12, linflp_k18_dp_ir12);
linflp_k18_v_copy_10(linflp_k18_dy12, linflp_k18_dy_ir12);
linflp_k18_v_copy_10(linflp_k18_dnu12, linflp_k18_dnu_ir12);
linflp_k18_v_copy_3(linflp_k18_dx13, linflp_k18_dx_ir13);
linflp_k18_v_copy_2(linflp_k18_du13, linflp_k18_du_ir13);
linflp_k18_v_copy_3(linflp_k18_dp13, linflp_k18_dp_ir13);
linflp_k18_v_copy_10(linflp_k18_dy13, linflp_k18_dy_ir13);
linflp_k18_v_copy_10(linflp_k18_dnu13, linflp_k18_dnu_ir13);
linflp_k18_v_copy_3(linflp_k18_dx14, linflp_k18_dx_ir14);
linflp_k18_v_copy_2(linflp_k18_du14, linflp_k18_du_ir14);
linflp_k18_v_copy_3(linflp_k18_dp14, linflp_k18_dp_ir14);
linflp_k18_v_copy_10(linflp_k18_dy14, linflp_k18_dy_ir14);
linflp_k18_v_copy_10(linflp_k18_dnu14, linflp_k18_dnu_ir14);
linflp_k18_v_copy_3(linflp_k18_dx15, linflp_k18_dx_ir15);
linflp_k18_v_copy_2(linflp_k18_du15, linflp_k18_du_ir15);
linflp_k18_v_copy_3(linflp_k18_dp15, linflp_k18_dp_ir15);
linflp_k18_v_copy_10(linflp_k18_dy15, linflp_k18_dy_ir15);
linflp_k18_v_copy_10(linflp_k18_dnu15, linflp_k18_dnu_ir15);
linflp_k18_v_copy_3(linflp_k18_dx16, linflp_k18_dx_ir16);
linflp_k18_v_copy_2(linflp_k18_du16, linflp_k18_du_ir16);
linflp_k18_v_copy_3(linflp_k18_dp16, linflp_k18_dp_ir16);
linflp_k18_v_copy_10(linflp_k18_dy16, linflp_k18_dy_ir16);
linflp_k18_v_copy_10(linflp_k18_dnu16, linflp_k18_dnu_ir16);
linflp_k18_v_copy_3(linflp_k18_dx17, linflp_k18_dx_ir17);
linflp_k18_v_copy_2(linflp_k18_du17, linflp_k18_du_ir17);
linflp_k18_v_copy_3(linflp_k18_dp17, linflp_k18_dp_ir17);
linflp_k18_v_copy_10(linflp_k18_dy17, linflp_k18_dy_ir17);
linflp_k18_v_copy_10(linflp_k18_dnu17, linflp_k18_dnu_ir17);
linflp_k18_v_copy_3(linflp_k18_dx18, linflp_k18_dx_ir18);
linflp_k18_v_copy_2(linflp_k18_du18, linflp_k18_du_ir18);
linflp_k18_v_copy_3(linflp_k18_dp18, linflp_k18_dp_ir18);
linflp_k18_v_copy_10(linflp_k18_dy18, linflp_k18_dy_ir18);
linflp_k18_v_copy_10(linflp_k18_dnu18, linflp_k18_dnu_ir18);
/* rhs sichern */
linflp_k18_v_copy_3(linflp_k18_rf0x0, linflp_k18_rf0x_ir0);
linflp_k18_v_copy_2(linflp_k18_rf0u0, linflp_k18_rf0u_ir0);
linflp_k18_v_copy_3(linflp_k18_rf0, linflp_k18_rf_ir0);
linflp_k18_v_copy_10(linflp_k18_rc0, linflp_k18_rc_ir0);
linflp_k18_v_copy_0(linflp_k18_rs0, linflp_k18_rs_ir0);
linflp_k18_v_copy_10(linflp_k18_rk0, linflp_k18_rk_ir0);
linflp_k18_v_copy_3(linflp_k18_rf0x1, linflp_k18_rf0x_ir1);
linflp_k18_v_copy_2(linflp_k18_rf0u1, linflp_k18_rf0u_ir1);
linflp_k18_v_copy_3(linflp_k18_rf1, linflp_k18_rf_ir1);
linflp_k18_v_copy_10(linflp_k18_rc1, linflp_k18_rc_ir1);
linflp_k18_v_copy_0(linflp_k18_rs1, linflp_k18_rs_ir1);
linflp_k18_v_copy_10(linflp_k18_rk1, linflp_k18_rk_ir1);
linflp_k18_v_copy_3(linflp_k18_rf0x2, linflp_k18_rf0x_ir2);
linflp_k18_v_copy_2(linflp_k18_rf0u2, linflp_k18_rf0u_ir2);
linflp_k18_v_copy_3(linflp_k18_rf2, linflp_k18_rf_ir2);
linflp_k18_v_copy_10(linflp_k18_rc2, linflp_k18_rc_ir2);
linflp_k18_v_copy_0(linflp_k18_rs2, linflp_k18_rs_ir2);
linflp_k18_v_copy_10(linflp_k18_rk2, linflp_k18_rk_ir2);
linflp_k18_v_copy_3(linflp_k18_rf0x3, linflp_k18_rf0x_ir3);
linflp_k18_v_copy_2(linflp_k18_rf0u3, linflp_k18_rf0u_ir3);
linflp_k18_v_copy_3(linflp_k18_rf3, linflp_k18_rf_ir3);
linflp_k18_v_copy_10(linflp_k18_rc3, linflp_k18_rc_ir3);
linflp_k18_v_copy_0(linflp_k18_rs3, linflp_k18_rs_ir3);
linflp_k18_v_copy_10(linflp_k18_rk3, linflp_k18_rk_ir3);
linflp_k18_v_copy_3(linflp_k18_rf0x4, linflp_k18_rf0x_ir4);
linflp_k18_v_copy_2(linflp_k18_rf0u4, linflp_k18_rf0u_ir4);
linflp_k18_v_copy_3(linflp_k18_rf4, linflp_k18_rf_ir4);
linflp_k18_v_copy_10(linflp_k18_rc4, linflp_k18_rc_ir4);
linflp_k18_v_copy_0(linflp_k18_rs4, linflp_k18_rs_ir4);
linflp_k18_v_copy_10(linflp_k18_rk4, linflp_k18_rk_ir4);
linflp_k18_v_copy_3(linflp_k18_rf0x5, linflp_k18_rf0x_ir5);
linflp_k18_v_copy_2(linflp_k18_rf0u5, linflp_k18_rf0u_ir5);
linflp_k18_v_copy_3(linflp_k18_rf5, linflp_k18_rf_ir5);
linflp_k18_v_copy_10(linflp_k18_rc5, linflp_k18_rc_ir5);
linflp_k18_v_copy_0(linflp_k18_rs5, linflp_k18_rs_ir5);
linflp_k18_v_copy_10(linflp_k18_rk5, linflp_k18_rk_ir5);
linflp_k18_v_copy_3(linflp_k18_rf0x6, linflp_k18_rf0x_ir6);
linflp_k18_v_copy_2(linflp_k18_rf0u6, linflp_k18_rf0u_ir6);
linflp_k18_v_copy_3(linflp_k18_rf6, linflp_k18_rf_ir6);
linflp_k18_v_copy_10(linflp_k18_rc6, linflp_k18_rc_ir6);
linflp_k18_v_copy_0(linflp_k18_rs6, linflp_k18_rs_ir6);
linflp_k18_v_copy_10(linflp_k18_rk6, linflp_k18_rk_ir6);
linflp_k18_v_copy_3(linflp_k18_rf0x7, linflp_k18_rf0x_ir7);
linflp_k18_v_copy_2(linflp_k18_rf0u7, linflp_k18_rf0u_ir7);
linflp_k18_v_copy_3(linflp_k18_rf7, linflp_k18_rf_ir7);
linflp_k18_v_copy_10(linflp_k18_rc7, linflp_k18_rc_ir7);
linflp_k18_v_copy_0(linflp_k18_rs7, linflp_k18_rs_ir7);
linflp_k18_v_copy_10(linflp_k18_rk7, linflp_k18_rk_ir7);
linflp_k18_v_copy_3(linflp_k18_rf0x8, linflp_k18_rf0x_ir8);
linflp_k18_v_copy_2(linflp_k18_rf0u8, linflp_k18_rf0u_ir8);
linflp_k18_v_copy_3(linflp_k18_rf8, linflp_k18_rf_ir8);
linflp_k18_v_copy_10(linflp_k18_rc8, linflp_k18_rc_ir8);
linflp_k18_v_copy_0(linflp_k18_rs8, linflp_k18_rs_ir8);
linflp_k18_v_copy_10(linflp_k18_rk8, linflp_k18_rk_ir8);
linflp_k18_v_copy_3(linflp_k18_rf0x9, linflp_k18_rf0x_ir9);
linflp_k18_v_copy_2(linflp_k18_rf0u9, linflp_k18_rf0u_ir9);
linflp_k18_v_copy_3(linflp_k18_rf9, linflp_k18_rf_ir9);
linflp_k18_v_copy_10(linflp_k18_rc9, linflp_k18_rc_ir9);
linflp_k18_v_copy_0(linflp_k18_rs9, linflp_k18_rs_ir9);
linflp_k18_v_copy_10(linflp_k18_rk9, linflp_k18_rk_ir9);
linflp_k18_v_copy_3(linflp_k18_rf0x10, linflp_k18_rf0x_ir10);
linflp_k18_v_copy_2(linflp_k18_rf0u10, linflp_k18_rf0u_ir10);
linflp_k18_v_copy_3(linflp_k18_rf10, linflp_k18_rf_ir10);
linflp_k18_v_copy_10(linflp_k18_rc10, linflp_k18_rc_ir10);
linflp_k18_v_copy_0(linflp_k18_rs10, linflp_k18_rs_ir10);
linflp_k18_v_copy_10(linflp_k18_rk10, linflp_k18_rk_ir10);
linflp_k18_v_copy_3(linflp_k18_rf0x11, linflp_k18_rf0x_ir11);
linflp_k18_v_copy_2(linflp_k18_rf0u11, linflp_k18_rf0u_ir11);
linflp_k18_v_copy_3(linflp_k18_rf11, linflp_k18_rf_ir11);
linflp_k18_v_copy_10(linflp_k18_rc11, linflp_k18_rc_ir11);
linflp_k18_v_copy_0(linflp_k18_rs11, linflp_k18_rs_ir11);
linflp_k18_v_copy_10(linflp_k18_rk11, linflp_k18_rk_ir11);
linflp_k18_v_copy_3(linflp_k18_rf0x12, linflp_k18_rf0x_ir12);
linflp_k18_v_copy_2(linflp_k18_rf0u12, linflp_k18_rf0u_ir12);
linflp_k18_v_copy_3(linflp_k18_rf12, linflp_k18_rf_ir12);
linflp_k18_v_copy_10(linflp_k18_rc12, linflp_k18_rc_ir12);
linflp_k18_v_copy_0(linflp_k18_rs12, linflp_k18_rs_ir12);
linflp_k18_v_copy_10(linflp_k18_rk12, linflp_k18_rk_ir12);
linflp_k18_v_copy_3(linflp_k18_rf0x13, linflp_k18_rf0x_ir13);
linflp_k18_v_copy_2(linflp_k18_rf0u13, linflp_k18_rf0u_ir13);
linflp_k18_v_copy_3(linflp_k18_rf13, linflp_k18_rf_ir13);
linflp_k18_v_copy_10(linflp_k18_rc13, linflp_k18_rc_ir13);
linflp_k18_v_copy_0(linflp_k18_rs13, linflp_k18_rs_ir13);
linflp_k18_v_copy_10(linflp_k18_rk13, linflp_k18_rk_ir13);
linflp_k18_v_copy_3(linflp_k18_rf0x14, linflp_k18_rf0x_ir14);
linflp_k18_v_copy_2(linflp_k18_rf0u14, linflp_k18_rf0u_ir14);
linflp_k18_v_copy_3(linflp_k18_rf14, linflp_k18_rf_ir14);
linflp_k18_v_copy_10(linflp_k18_rc14, linflp_k18_rc_ir14);
linflp_k18_v_copy_0(linflp_k18_rs14, linflp_k18_rs_ir14);
linflp_k18_v_copy_10(linflp_k18_rk14, linflp_k18_rk_ir14);
linflp_k18_v_copy_3(linflp_k18_rf0x15, linflp_k18_rf0x_ir15);
linflp_k18_v_copy_2(linflp_k18_rf0u15, linflp_k18_rf0u_ir15);
linflp_k18_v_copy_3(linflp_k18_rf15, linflp_k18_rf_ir15);
linflp_k18_v_copy_10(linflp_k18_rc15, linflp_k18_rc_ir15);
linflp_k18_v_copy_0(linflp_k18_rs15, linflp_k18_rs_ir15);
linflp_k18_v_copy_10(linflp_k18_rk15, linflp_k18_rk_ir15);
linflp_k18_v_copy_3(linflp_k18_rf0x16, linflp_k18_rf0x_ir16);
linflp_k18_v_copy_2(linflp_k18_rf0u16, linflp_k18_rf0u_ir16);
linflp_k18_v_copy_3(linflp_k18_rf16, linflp_k18_rf_ir16);
linflp_k18_v_copy_10(linflp_k18_rc16, linflp_k18_rc_ir16);
linflp_k18_v_copy_0(linflp_k18_rs16, linflp_k18_rs_ir16);
linflp_k18_v_copy_10(linflp_k18_rk16, linflp_k18_rk_ir16);
linflp_k18_v_copy_3(linflp_k18_rf0x17, linflp_k18_rf0x_ir17);
linflp_k18_v_copy_2(linflp_k18_rf0u17, linflp_k18_rf0u_ir17);
linflp_k18_v_copy_3(linflp_k18_rf17, linflp_k18_rf_ir17);
linflp_k18_v_copy_10(linflp_k18_rc17, linflp_k18_rc_ir17);
linflp_k18_v_copy_0(linflp_k18_rs17, linflp_k18_rs_ir17);
linflp_k18_v_copy_10(linflp_k18_rk17, linflp_k18_rk_ir17);
linflp_k18_v_copy_3(linflp_k18_rf0x18, linflp_k18_rf0x_ir18);
linflp_k18_v_copy_2(linflp_k18_rf0u18, linflp_k18_rf0u_ir18);
linflp_k18_v_copy_3(linflp_k18_rf18, linflp_k18_rf_ir18);
linflp_k18_v_copy_10(linflp_k18_rc18, linflp_k18_rc_ir18);
linflp_k18_v_copy_0(linflp_k18_rs18, linflp_k18_rs_ir18);
linflp_k18_v_copy_10(linflp_k18_rk18, linflp_k18_rk_ir18);
/* Residuum berechnen */
linflp_k18_glqdocpip_rhs_iter_ref();
if(linflp_k18_termcode > -1){return;}
linflp_k18_glqdocpip_rhs_reduced();
if(linflp_k18_termcode > -1){return;}
/* GLS mit Residuum als rechte Seite l�sen */
linflp_k18_glqdocpip_solve();
if(linflp_k18_termcode > -1){return;}
linflp_k18_glqdocpip_dereduce();
if(linflp_k18_termcode > -1){return;}
/* L�sung aktualisieren */
linflp_k18_vadd_3(linflp_k18_dx_ir0, linflp_k18_dx0, linflp_k18_dx0);
linflp_k18_vadd_2(linflp_k18_du_ir0, linflp_k18_du0, linflp_k18_du0);
linflp_k18_vadd_3(linflp_k18_dp_ir0, linflp_k18_dp0, linflp_k18_dp0);
linflp_k18_vadd_10(linflp_k18_dy_ir0, linflp_k18_dy0, linflp_k18_dy0);
linflp_k18_vadd_10(linflp_k18_dnu_ir0, linflp_k18_dnu0, linflp_k18_dnu0);
linflp_k18_vadd_3(linflp_k18_dx_ir1, linflp_k18_dx1, linflp_k18_dx1);
linflp_k18_vadd_2(linflp_k18_du_ir1, linflp_k18_du1, linflp_k18_du1);
linflp_k18_vadd_3(linflp_k18_dp_ir1, linflp_k18_dp1, linflp_k18_dp1);
linflp_k18_vadd_10(linflp_k18_dy_ir1, linflp_k18_dy1, linflp_k18_dy1);
linflp_k18_vadd_10(linflp_k18_dnu_ir1, linflp_k18_dnu1, linflp_k18_dnu1);
linflp_k18_vadd_3(linflp_k18_dx_ir2, linflp_k18_dx2, linflp_k18_dx2);
linflp_k18_vadd_2(linflp_k18_du_ir2, linflp_k18_du2, linflp_k18_du2);
linflp_k18_vadd_3(linflp_k18_dp_ir2, linflp_k18_dp2, linflp_k18_dp2);
linflp_k18_vadd_10(linflp_k18_dy_ir2, linflp_k18_dy2, linflp_k18_dy2);
linflp_k18_vadd_10(linflp_k18_dnu_ir2, linflp_k18_dnu2, linflp_k18_dnu2);
linflp_k18_vadd_3(linflp_k18_dx_ir3, linflp_k18_dx3, linflp_k18_dx3);
linflp_k18_vadd_2(linflp_k18_du_ir3, linflp_k18_du3, linflp_k18_du3);
linflp_k18_vadd_3(linflp_k18_dp_ir3, linflp_k18_dp3, linflp_k18_dp3);
linflp_k18_vadd_10(linflp_k18_dy_ir3, linflp_k18_dy3, linflp_k18_dy3);
linflp_k18_vadd_10(linflp_k18_dnu_ir3, linflp_k18_dnu3, linflp_k18_dnu3);
linflp_k18_vadd_3(linflp_k18_dx_ir4, linflp_k18_dx4, linflp_k18_dx4);
linflp_k18_vadd_2(linflp_k18_du_ir4, linflp_k18_du4, linflp_k18_du4);
linflp_k18_vadd_3(linflp_k18_dp_ir4, linflp_k18_dp4, linflp_k18_dp4);
linflp_k18_vadd_10(linflp_k18_dy_ir4, linflp_k18_dy4, linflp_k18_dy4);
linflp_k18_vadd_10(linflp_k18_dnu_ir4, linflp_k18_dnu4, linflp_k18_dnu4);
linflp_k18_vadd_3(linflp_k18_dx_ir5, linflp_k18_dx5, linflp_k18_dx5);
linflp_k18_vadd_2(linflp_k18_du_ir5, linflp_k18_du5, linflp_k18_du5);
linflp_k18_vadd_3(linflp_k18_dp_ir5, linflp_k18_dp5, linflp_k18_dp5);
linflp_k18_vadd_10(linflp_k18_dy_ir5, linflp_k18_dy5, linflp_k18_dy5);
linflp_k18_vadd_10(linflp_k18_dnu_ir5, linflp_k18_dnu5, linflp_k18_dnu5);
linflp_k18_vadd_3(linflp_k18_dx_ir6, linflp_k18_dx6, linflp_k18_dx6);
linflp_k18_vadd_2(linflp_k18_du_ir6, linflp_k18_du6, linflp_k18_du6);
linflp_k18_vadd_3(linflp_k18_dp_ir6, linflp_k18_dp6, linflp_k18_dp6);
linflp_k18_vadd_10(linflp_k18_dy_ir6, linflp_k18_dy6, linflp_k18_dy6);
linflp_k18_vadd_10(linflp_k18_dnu_ir6, linflp_k18_dnu6, linflp_k18_dnu6);
linflp_k18_vadd_3(linflp_k18_dx_ir7, linflp_k18_dx7, linflp_k18_dx7);
linflp_k18_vadd_2(linflp_k18_du_ir7, linflp_k18_du7, linflp_k18_du7);
linflp_k18_vadd_3(linflp_k18_dp_ir7, linflp_k18_dp7, linflp_k18_dp7);
linflp_k18_vadd_10(linflp_k18_dy_ir7, linflp_k18_dy7, linflp_k18_dy7);
linflp_k18_vadd_10(linflp_k18_dnu_ir7, linflp_k18_dnu7, linflp_k18_dnu7);
linflp_k18_vadd_3(linflp_k18_dx_ir8, linflp_k18_dx8, linflp_k18_dx8);
linflp_k18_vadd_2(linflp_k18_du_ir8, linflp_k18_du8, linflp_k18_du8);
linflp_k18_vadd_3(linflp_k18_dp_ir8, linflp_k18_dp8, linflp_k18_dp8);
linflp_k18_vadd_10(linflp_k18_dy_ir8, linflp_k18_dy8, linflp_k18_dy8);
linflp_k18_vadd_10(linflp_k18_dnu_ir8, linflp_k18_dnu8, linflp_k18_dnu8);
linflp_k18_vadd_3(linflp_k18_dx_ir9, linflp_k18_dx9, linflp_k18_dx9);
linflp_k18_vadd_2(linflp_k18_du_ir9, linflp_k18_du9, linflp_k18_du9);
linflp_k18_vadd_3(linflp_k18_dp_ir9, linflp_k18_dp9, linflp_k18_dp9);
linflp_k18_vadd_10(linflp_k18_dy_ir9, linflp_k18_dy9, linflp_k18_dy9);
linflp_k18_vadd_10(linflp_k18_dnu_ir9, linflp_k18_dnu9, linflp_k18_dnu9);
linflp_k18_vadd_3(linflp_k18_dx_ir10, linflp_k18_dx10, linflp_k18_dx10);
linflp_k18_vadd_2(linflp_k18_du_ir10, linflp_k18_du10, linflp_k18_du10);
linflp_k18_vadd_3(linflp_k18_dp_ir10, linflp_k18_dp10, linflp_k18_dp10);
linflp_k18_vadd_10(linflp_k18_dy_ir10, linflp_k18_dy10, linflp_k18_dy10);
linflp_k18_vadd_10(linflp_k18_dnu_ir10, linflp_k18_dnu10, linflp_k18_dnu10);
linflp_k18_vadd_3(linflp_k18_dx_ir11, linflp_k18_dx11, linflp_k18_dx11);
linflp_k18_vadd_2(linflp_k18_du_ir11, linflp_k18_du11, linflp_k18_du11);
linflp_k18_vadd_3(linflp_k18_dp_ir11, linflp_k18_dp11, linflp_k18_dp11);
linflp_k18_vadd_10(linflp_k18_dy_ir11, linflp_k18_dy11, linflp_k18_dy11);
linflp_k18_vadd_10(linflp_k18_dnu_ir11, linflp_k18_dnu11, linflp_k18_dnu11);
linflp_k18_vadd_3(linflp_k18_dx_ir12, linflp_k18_dx12, linflp_k18_dx12);
linflp_k18_vadd_2(linflp_k18_du_ir12, linflp_k18_du12, linflp_k18_du12);
linflp_k18_vadd_3(linflp_k18_dp_ir12, linflp_k18_dp12, linflp_k18_dp12);
linflp_k18_vadd_10(linflp_k18_dy_ir12, linflp_k18_dy12, linflp_k18_dy12);
linflp_k18_vadd_10(linflp_k18_dnu_ir12, linflp_k18_dnu12, linflp_k18_dnu12);
linflp_k18_vadd_3(linflp_k18_dx_ir13, linflp_k18_dx13, linflp_k18_dx13);
linflp_k18_vadd_2(linflp_k18_du_ir13, linflp_k18_du13, linflp_k18_du13);
linflp_k18_vadd_3(linflp_k18_dp_ir13, linflp_k18_dp13, linflp_k18_dp13);
linflp_k18_vadd_10(linflp_k18_dy_ir13, linflp_k18_dy13, linflp_k18_dy13);
linflp_k18_vadd_10(linflp_k18_dnu_ir13, linflp_k18_dnu13, linflp_k18_dnu13);
linflp_k18_vadd_3(linflp_k18_dx_ir14, linflp_k18_dx14, linflp_k18_dx14);
linflp_k18_vadd_2(linflp_k18_du_ir14, linflp_k18_du14, linflp_k18_du14);
linflp_k18_vadd_3(linflp_k18_dp_ir14, linflp_k18_dp14, linflp_k18_dp14);
linflp_k18_vadd_10(linflp_k18_dy_ir14, linflp_k18_dy14, linflp_k18_dy14);
linflp_k18_vadd_10(linflp_k18_dnu_ir14, linflp_k18_dnu14, linflp_k18_dnu14);
linflp_k18_vadd_3(linflp_k18_dx_ir15, linflp_k18_dx15, linflp_k18_dx15);
linflp_k18_vadd_2(linflp_k18_du_ir15, linflp_k18_du15, linflp_k18_du15);
linflp_k18_vadd_3(linflp_k18_dp_ir15, linflp_k18_dp15, linflp_k18_dp15);
linflp_k18_vadd_10(linflp_k18_dy_ir15, linflp_k18_dy15, linflp_k18_dy15);
linflp_k18_vadd_10(linflp_k18_dnu_ir15, linflp_k18_dnu15, linflp_k18_dnu15);
linflp_k18_vadd_3(linflp_k18_dx_ir16, linflp_k18_dx16, linflp_k18_dx16);
linflp_k18_vadd_2(linflp_k18_du_ir16, linflp_k18_du16, linflp_k18_du16);
linflp_k18_vadd_3(linflp_k18_dp_ir16, linflp_k18_dp16, linflp_k18_dp16);
linflp_k18_vadd_10(linflp_k18_dy_ir16, linflp_k18_dy16, linflp_k18_dy16);
linflp_k18_vadd_10(linflp_k18_dnu_ir16, linflp_k18_dnu16, linflp_k18_dnu16);
linflp_k18_vadd_3(linflp_k18_dx_ir17, linflp_k18_dx17, linflp_k18_dx17);
linflp_k18_vadd_2(linflp_k18_du_ir17, linflp_k18_du17, linflp_k18_du17);
linflp_k18_vadd_3(linflp_k18_dp_ir17, linflp_k18_dp17, linflp_k18_dp17);
linflp_k18_vadd_10(linflp_k18_dy_ir17, linflp_k18_dy17, linflp_k18_dy17);
linflp_k18_vadd_10(linflp_k18_dnu_ir17, linflp_k18_dnu17, linflp_k18_dnu17);
linflp_k18_vadd_3(linflp_k18_dx_ir18, linflp_k18_dx18, linflp_k18_dx18);
linflp_k18_vadd_2(linflp_k18_du_ir18, linflp_k18_du18, linflp_k18_du18);
linflp_k18_vadd_3(linflp_k18_dp_ir18, linflp_k18_dp18, linflp_k18_dp18);
linflp_k18_vadd_10(linflp_k18_dy_ir18, linflp_k18_dy18, linflp_k18_dy18);
linflp_k18_vadd_10(linflp_k18_dnu_ir18, linflp_k18_dnu18, linflp_k18_dnu18);
/* rhs wiederherstellen */
linflp_k18_v_copy_3(linflp_k18_rf0x_ir0, linflp_k18_rf0x0);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir0, linflp_k18_rf0u0);
linflp_k18_v_copy_3(linflp_k18_rf_ir0, linflp_k18_rf0);
linflp_k18_v_copy_10(linflp_k18_rc_ir0, linflp_k18_rc0);
linflp_k18_v_copy_0(linflp_k18_rs_ir0, linflp_k18_rs0);
linflp_k18_v_copy_10(linflp_k18_rk_ir0, linflp_k18_rk0);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir1, linflp_k18_rf0x1);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir1, linflp_k18_rf0u1);
linflp_k18_v_copy_3(linflp_k18_rf_ir1, linflp_k18_rf1);
linflp_k18_v_copy_10(linflp_k18_rc_ir1, linflp_k18_rc1);
linflp_k18_v_copy_0(linflp_k18_rs_ir1, linflp_k18_rs1);
linflp_k18_v_copy_10(linflp_k18_rk_ir1, linflp_k18_rk1);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir2, linflp_k18_rf0x2);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir2, linflp_k18_rf0u2);
linflp_k18_v_copy_3(linflp_k18_rf_ir2, linflp_k18_rf2);
linflp_k18_v_copy_10(linflp_k18_rc_ir2, linflp_k18_rc2);
linflp_k18_v_copy_0(linflp_k18_rs_ir2, linflp_k18_rs2);
linflp_k18_v_copy_10(linflp_k18_rk_ir2, linflp_k18_rk2);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir3, linflp_k18_rf0x3);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir3, linflp_k18_rf0u3);
linflp_k18_v_copy_3(linflp_k18_rf_ir3, linflp_k18_rf3);
linflp_k18_v_copy_10(linflp_k18_rc_ir3, linflp_k18_rc3);
linflp_k18_v_copy_0(linflp_k18_rs_ir3, linflp_k18_rs3);
linflp_k18_v_copy_10(linflp_k18_rk_ir3, linflp_k18_rk3);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir4, linflp_k18_rf0x4);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir4, linflp_k18_rf0u4);
linflp_k18_v_copy_3(linflp_k18_rf_ir4, linflp_k18_rf4);
linflp_k18_v_copy_10(linflp_k18_rc_ir4, linflp_k18_rc4);
linflp_k18_v_copy_0(linflp_k18_rs_ir4, linflp_k18_rs4);
linflp_k18_v_copy_10(linflp_k18_rk_ir4, linflp_k18_rk4);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir5, linflp_k18_rf0x5);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir5, linflp_k18_rf0u5);
linflp_k18_v_copy_3(linflp_k18_rf_ir5, linflp_k18_rf5);
linflp_k18_v_copy_10(linflp_k18_rc_ir5, linflp_k18_rc5);
linflp_k18_v_copy_0(linflp_k18_rs_ir5, linflp_k18_rs5);
linflp_k18_v_copy_10(linflp_k18_rk_ir5, linflp_k18_rk5);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir6, linflp_k18_rf0x6);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir6, linflp_k18_rf0u6);
linflp_k18_v_copy_3(linflp_k18_rf_ir6, linflp_k18_rf6);
linflp_k18_v_copy_10(linflp_k18_rc_ir6, linflp_k18_rc6);
linflp_k18_v_copy_0(linflp_k18_rs_ir6, linflp_k18_rs6);
linflp_k18_v_copy_10(linflp_k18_rk_ir6, linflp_k18_rk6);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir7, linflp_k18_rf0x7);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir7, linflp_k18_rf0u7);
linflp_k18_v_copy_3(linflp_k18_rf_ir7, linflp_k18_rf7);
linflp_k18_v_copy_10(linflp_k18_rc_ir7, linflp_k18_rc7);
linflp_k18_v_copy_0(linflp_k18_rs_ir7, linflp_k18_rs7);
linflp_k18_v_copy_10(linflp_k18_rk_ir7, linflp_k18_rk7);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir8, linflp_k18_rf0x8);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir8, linflp_k18_rf0u8);
linflp_k18_v_copy_3(linflp_k18_rf_ir8, linflp_k18_rf8);
linflp_k18_v_copy_10(linflp_k18_rc_ir8, linflp_k18_rc8);
linflp_k18_v_copy_0(linflp_k18_rs_ir8, linflp_k18_rs8);
linflp_k18_v_copy_10(linflp_k18_rk_ir8, linflp_k18_rk8);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir9, linflp_k18_rf0x9);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir9, linflp_k18_rf0u9);
linflp_k18_v_copy_3(linflp_k18_rf_ir9, linflp_k18_rf9);
linflp_k18_v_copy_10(linflp_k18_rc_ir9, linflp_k18_rc9);
linflp_k18_v_copy_0(linflp_k18_rs_ir9, linflp_k18_rs9);
linflp_k18_v_copy_10(linflp_k18_rk_ir9, linflp_k18_rk9);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir10, linflp_k18_rf0x10);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir10, linflp_k18_rf0u10);
linflp_k18_v_copy_3(linflp_k18_rf_ir10, linflp_k18_rf10);
linflp_k18_v_copy_10(linflp_k18_rc_ir10, linflp_k18_rc10);
linflp_k18_v_copy_0(linflp_k18_rs_ir10, linflp_k18_rs10);
linflp_k18_v_copy_10(linflp_k18_rk_ir10, linflp_k18_rk10);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir11, linflp_k18_rf0x11);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir11, linflp_k18_rf0u11);
linflp_k18_v_copy_3(linflp_k18_rf_ir11, linflp_k18_rf11);
linflp_k18_v_copy_10(linflp_k18_rc_ir11, linflp_k18_rc11);
linflp_k18_v_copy_0(linflp_k18_rs_ir11, linflp_k18_rs11);
linflp_k18_v_copy_10(linflp_k18_rk_ir11, linflp_k18_rk11);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir12, linflp_k18_rf0x12);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir12, linflp_k18_rf0u12);
linflp_k18_v_copy_3(linflp_k18_rf_ir12, linflp_k18_rf12);
linflp_k18_v_copy_10(linflp_k18_rc_ir12, linflp_k18_rc12);
linflp_k18_v_copy_0(linflp_k18_rs_ir12, linflp_k18_rs12);
linflp_k18_v_copy_10(linflp_k18_rk_ir12, linflp_k18_rk12);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir13, linflp_k18_rf0x13);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir13, linflp_k18_rf0u13);
linflp_k18_v_copy_3(linflp_k18_rf_ir13, linflp_k18_rf13);
linflp_k18_v_copy_10(linflp_k18_rc_ir13, linflp_k18_rc13);
linflp_k18_v_copy_0(linflp_k18_rs_ir13, linflp_k18_rs13);
linflp_k18_v_copy_10(linflp_k18_rk_ir13, linflp_k18_rk13);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir14, linflp_k18_rf0x14);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir14, linflp_k18_rf0u14);
linflp_k18_v_copy_3(linflp_k18_rf_ir14, linflp_k18_rf14);
linflp_k18_v_copy_10(linflp_k18_rc_ir14, linflp_k18_rc14);
linflp_k18_v_copy_0(linflp_k18_rs_ir14, linflp_k18_rs14);
linflp_k18_v_copy_10(linflp_k18_rk_ir14, linflp_k18_rk14);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir15, linflp_k18_rf0x15);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir15, linflp_k18_rf0u15);
linflp_k18_v_copy_3(linflp_k18_rf_ir15, linflp_k18_rf15);
linflp_k18_v_copy_10(linflp_k18_rc_ir15, linflp_k18_rc15);
linflp_k18_v_copy_0(linflp_k18_rs_ir15, linflp_k18_rs15);
linflp_k18_v_copy_10(linflp_k18_rk_ir15, linflp_k18_rk15);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir16, linflp_k18_rf0x16);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir16, linflp_k18_rf0u16);
linflp_k18_v_copy_3(linflp_k18_rf_ir16, linflp_k18_rf16);
linflp_k18_v_copy_10(linflp_k18_rc_ir16, linflp_k18_rc16);
linflp_k18_v_copy_0(linflp_k18_rs_ir16, linflp_k18_rs16);
linflp_k18_v_copy_10(linflp_k18_rk_ir16, linflp_k18_rk16);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir17, linflp_k18_rf0x17);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir17, linflp_k18_rf0u17);
linflp_k18_v_copy_3(linflp_k18_rf_ir17, linflp_k18_rf17);
linflp_k18_v_copy_10(linflp_k18_rc_ir17, linflp_k18_rc17);
linflp_k18_v_copy_0(linflp_k18_rs_ir17, linflp_k18_rs17);
linflp_k18_v_copy_10(linflp_k18_rk_ir17, linflp_k18_rk17);
linflp_k18_v_copy_3(linflp_k18_rf0x_ir18, linflp_k18_rf0x18);
linflp_k18_v_copy_2(linflp_k18_rf0u_ir18, linflp_k18_rf0u18);
linflp_k18_v_copy_3(linflp_k18_rf_ir18, linflp_k18_rf18);
linflp_k18_v_copy_10(linflp_k18_rc_ir18, linflp_k18_rc18);
linflp_k18_v_copy_0(linflp_k18_rs_ir18, linflp_k18_rs18);
linflp_k18_v_copy_10(linflp_k18_rk_ir18, linflp_k18_rk18);
}
}


/* ####################################### */
/* Diese Funktion berechnet den Startpunkt */
/*           Startpunktmethode: 0          */
/* ####################################### */
static void linflp_k18_glqdocpip_starting_point()
{
/* Very Cold Start */
/* Zeitschritt 0 */
linflp_k18_v_init0_3(linflp_k18_x0);
linflp_k18_v_init0_2(linflp_k18_u0);
linflp_k18_v_init0_3(linflp_k18_p0);
linflp_k18_v_init1_10(linflp_k18_y0);
linflp_k18_v_init1_10(linflp_k18_nu0);
/* Zeitschritt 1 */
linflp_k18_v_init0_3(linflp_k18_x1);
linflp_k18_v_init0_2(linflp_k18_u1);
linflp_k18_v_init0_3(linflp_k18_p1);
linflp_k18_v_init1_10(linflp_k18_y1);
linflp_k18_v_init1_10(linflp_k18_nu1);
/* Zeitschritt 2 */
linflp_k18_v_init0_3(linflp_k18_x2);
linflp_k18_v_init0_2(linflp_k18_u2);
linflp_k18_v_init0_3(linflp_k18_p2);
linflp_k18_v_init1_10(linflp_k18_y2);
linflp_k18_v_init1_10(linflp_k18_nu2);
/* Zeitschritt 3 */
linflp_k18_v_init0_3(linflp_k18_x3);
linflp_k18_v_init0_2(linflp_k18_u3);
linflp_k18_v_init0_3(linflp_k18_p3);
linflp_k18_v_init1_10(linflp_k18_y3);
linflp_k18_v_init1_10(linflp_k18_nu3);
/* Zeitschritt 4 */
linflp_k18_v_init0_3(linflp_k18_x4);
linflp_k18_v_init0_2(linflp_k18_u4);
linflp_k18_v_init0_3(linflp_k18_p4);
linflp_k18_v_init1_10(linflp_k18_y4);
linflp_k18_v_init1_10(linflp_k18_nu4);
/* Zeitschritt 5 */
linflp_k18_v_init0_3(linflp_k18_x5);
linflp_k18_v_init0_2(linflp_k18_u5);
linflp_k18_v_init0_3(linflp_k18_p5);
linflp_k18_v_init1_10(linflp_k18_y5);
linflp_k18_v_init1_10(linflp_k18_nu5);
/* Zeitschritt 6 */
linflp_k18_v_init0_3(linflp_k18_x6);
linflp_k18_v_init0_2(linflp_k18_u6);
linflp_k18_v_init0_3(linflp_k18_p6);
linflp_k18_v_init1_10(linflp_k18_y6);
linflp_k18_v_init1_10(linflp_k18_nu6);
/* Zeitschritt 7 */
linflp_k18_v_init0_3(linflp_k18_x7);
linflp_k18_v_init0_2(linflp_k18_u7);
linflp_k18_v_init0_3(linflp_k18_p7);
linflp_k18_v_init1_10(linflp_k18_y7);
linflp_k18_v_init1_10(linflp_k18_nu7);
/* Zeitschritt 8 */
linflp_k18_v_init0_3(linflp_k18_x8);
linflp_k18_v_init0_2(linflp_k18_u8);
linflp_k18_v_init0_3(linflp_k18_p8);
linflp_k18_v_init1_10(linflp_k18_y8);
linflp_k18_v_init1_10(linflp_k18_nu8);
/* Zeitschritt 9 */
linflp_k18_v_init0_3(linflp_k18_x9);
linflp_k18_v_init0_2(linflp_k18_u9);
linflp_k18_v_init0_3(linflp_k18_p9);
linflp_k18_v_init1_10(linflp_k18_y9);
linflp_k18_v_init1_10(linflp_k18_nu9);
/* Zeitschritt 10 */
linflp_k18_v_init0_3(linflp_k18_x10);
linflp_k18_v_init0_2(linflp_k18_u10);
linflp_k18_v_init0_3(linflp_k18_p10);
linflp_k18_v_init1_10(linflp_k18_y10);
linflp_k18_v_init1_10(linflp_k18_nu10);
/* Zeitschritt 11 */
linflp_k18_v_init0_3(linflp_k18_x11);
linflp_k18_v_init0_2(linflp_k18_u11);
linflp_k18_v_init0_3(linflp_k18_p11);
linflp_k18_v_init1_10(linflp_k18_y11);
linflp_k18_v_init1_10(linflp_k18_nu11);
/* Zeitschritt 12 */
linflp_k18_v_init0_3(linflp_k18_x12);
linflp_k18_v_init0_2(linflp_k18_u12);
linflp_k18_v_init0_3(linflp_k18_p12);
linflp_k18_v_init1_10(linflp_k18_y12);
linflp_k18_v_init1_10(linflp_k18_nu12);
/* Zeitschritt 13 */
linflp_k18_v_init0_3(linflp_k18_x13);
linflp_k18_v_init0_2(linflp_k18_u13);
linflp_k18_v_init0_3(linflp_k18_p13);
linflp_k18_v_init1_10(linflp_k18_y13);
linflp_k18_v_init1_10(linflp_k18_nu13);
/* Zeitschritt 14 */
linflp_k18_v_init0_3(linflp_k18_x14);
linflp_k18_v_init0_2(linflp_k18_u14);
linflp_k18_v_init0_3(linflp_k18_p14);
linflp_k18_v_init1_10(linflp_k18_y14);
linflp_k18_v_init1_10(linflp_k18_nu14);
/* Zeitschritt 15 */
linflp_k18_v_init0_3(linflp_k18_x15);
linflp_k18_v_init0_2(linflp_k18_u15);
linflp_k18_v_init0_3(linflp_k18_p15);
linflp_k18_v_init1_10(linflp_k18_y15);
linflp_k18_v_init1_10(linflp_k18_nu15);
/* Zeitschritt 16 */
linflp_k18_v_init0_3(linflp_k18_x16);
linflp_k18_v_init0_2(linflp_k18_u16);
linflp_k18_v_init0_3(linflp_k18_p16);
linflp_k18_v_init1_10(linflp_k18_y16);
linflp_k18_v_init1_10(linflp_k18_nu16);
/* Zeitschritt 17 */
linflp_k18_v_init0_3(linflp_k18_x17);
linflp_k18_v_init0_2(linflp_k18_u17);
linflp_k18_v_init0_3(linflp_k18_p17);
linflp_k18_v_init1_10(linflp_k18_y17);
linflp_k18_v_init1_10(linflp_k18_nu17);
/* Zeitschritt 18 */
linflp_k18_v_init0_3(linflp_k18_x18);
linflp_k18_v_init0_2(linflp_k18_u18);
linflp_k18_v_init0_3(linflp_k18_p18);
linflp_k18_v_init1_10(linflp_k18_y18);
linflp_k18_v_init1_10(linflp_k18_nu18);
}


void linflp_k18_glqdocpip_init()
{
/* ## Parameter INIT ##  */
/* Anzahl Ungleichungsbedingungen */
linflp_k18_m_ineq[0] = 190;
/* Toleranz (Abbruchkriterium) */
linflp_k18_tol[0] = 0.0001;
/* Mehrotra Gamma */
linflp_k18_mehrotra_gamma[0] = 0.01;
/* Machine Epsilon */
/* Init Berechnung */
linflp_k18_v_init0_1(linflp_k18_tmp3_1);
linflp_k18_tmp1_1[0] = 1;
linflp_k18_tmp2_1[0] = 1.0f - linflp_k18_tmp1_1[0]/2;
/* Berechnungsschleife: while((1-div/2)!=1){div = div/2} */
while(linflp_k18_tmp2_1[0] != 1.0f){
linflp_k18_tmp1_1[0] = linflp_k18_tmp1_1[0]/2;
linflp_k18_tmp2_1[0] = 1.0f - linflp_k18_tmp1_1[0]/2;
linflp_k18_tmp3_1[0] += 1;
if(linflp_k18_tmp3_1[0] > 100){
linflp_k18_termcode = 10;
return;
}
}
linflp_k18_macheps[0] = linflp_k18_tmp1_1[0];
/* tau */
linflp_k18_tau[0] = 3;
/* termcode */
linflp_k18_termcode = -1;
/* Error Line */
linflp_k18_error_line = 0;
/* Error Source */
linflp_k18_error_source = 0;
/* termcode 1 factor */
linflp_k18_tc1_factor[0] = 10000;
/* termcode 2 factor */
linflp_k18_tc2_factor[0] = 100000000;
/* tmax */
linflp_k18_time_max = 1;
/* max_iter */
linflp_k18_max_iter = 100;
/* num_iter_ref */
linflp_k18_stat_num_iter_ref = 0;
/* num_factor */
linflp_k18_stat_num_factor = 0;
/* num_solve */
linflp_k18_stat_num_solve = 0;
}


int linflp_k18_glqdocpip()
{

/* High Performance Timer (Windows) */
linflp_k18_glqdocpip_timer_start();

/* Init */
linflp_k18_glqdocpip_init();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Anfangsnorm bestimmen (norm_d) */
linflp_k18_glqdocpip_calc_norm_d();

/* starting point */
linflp_k18_glqdocpip_starting_point();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Main Iteration Loop */
for(linflp_k18_iter = 0; linflp_k18_iter < linflp_k18_max_iter; linflp_k18_iter++){

/* Predictor rhs berechnen */
linflp_k18_glqdocpip_rhs_affine();
linflp_k18_glqdocpip_rhs_reduced();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Konvergenz- und Divergenztests, inkl. Berechnung der daf�r n�tigen Parameter */
linflp_k18_glqdocpip_calc_norm_r();
linflp_k18_glqdocpip_calc_mu();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_calc_duality_gap();
linflp_k18_glqdocpip_calc_phi();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_stat();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_check_condiv();
/* Bei entsprechendem Termcode Funktion beenden */
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Predictor GLS faktorisieren */
linflp_k18_glqdocpip_factor();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Predictor GLS l�sen */
linflp_k18_glqdocpip_solve();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_dereduce();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_iter_ref();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Korrekturfaktor f�r CorrectorGLS berechnen, */
/* inkl der daf�r n�tigen Parameter */
linflp_k18_glqdocpip_max_stepsize();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_calc_mu_aff();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_calc_sigma();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Corrector rhs berechnen */
linflp_k18_glqdocpip_rhs_corrector();
linflp_k18_glqdocpip_rhs_reduced();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Corrector GLS l�sen */
linflp_k18_glqdocpip_solve();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_dereduce();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_iter_ref();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}

/* Schritt berechnen und durchf�hren */
linflp_k18_glqdocpip_max_stepsize();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_calc_mu_aff();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_mehrotra_step();
if(linflp_k18_termcode > -1){return linflp_k18_termcode;}
linflp_k18_glqdocpip_step();

/* Ende - Main Iteration Loop */
}


/* Termcode 3: Max Iterations exceeded */
linflp_k18_termcode = 3;
return linflp_k18_termcode;
}