/* ########### */
/* # INCLUDE # */
/* ########### */
#include "mex.h"
#include "mpc123_glqdocpip.h"

void matlab2c(mxArray *mstruct)
{
int j;
mxArray *mxlvl1, *mxlvl2;
double *diptr;
float*dptr;

/* Anfangsbedingung */
mxlvl1 = mxGetField(mstruct,0,"xinit");
dptr = mpc123_get_x0();
diptr = mxGetPr(mxlvl1);
for(j=0; j<6; j++)
{
dptr[j] = (float)diptr [j];
}
/* copy Hxx */
mxlvl1 = mxGetField(mstruct,0,"Hxx");
/* Zeitschritt 0 */
dptr = mpc123_get_Hxx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_Hxx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_Hxx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_Hxx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_Hxx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_Hxx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_Hxx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_Hxx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_Hxx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_Hxx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_Hxx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_Hxx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* copy Hxu */
mxlvl1 = mxGetField(mstruct,0,"Hxu");
/* Zeitschritt 0 */
dptr = mpc123_get_Hxu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_Hxu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_Hxu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_Hxu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_Hxu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_Hxu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_Hxu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_Hxu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_Hxu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_Hxu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_Hxu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_Hxu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* copy Huu */
mxlvl1 = mxGetField(mstruct,0,"Huu");
/* Zeitschritt 0 */
dptr = mpc123_get_Huu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_Huu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_Huu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_Huu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_Huu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_Huu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_Huu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_Huu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_Huu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_Huu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_Huu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_Huu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* copy Hss */
mxlvl1 = mxGetField(mstruct,0,"Hss");
/* Zeitschritt 0 */
dptr = mpc123_get_Hss(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<16; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_Hss(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_Hss(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_Hss(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_Hss(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_Hss(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_Hss(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_Hss(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_Hss(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_Hss(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_Hss(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<64; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_Hss(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<16; j++) {
  dptr[j] = (float)diptr [j];}
/* copy f0x */
mxlvl1 = mxGetField(mstruct,0,"f0x");
/* Zeitschritt 0 */
dptr = mpc123_get_f0x(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_f0x(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_f0x(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_f0x(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_f0x(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_f0x(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_f0x(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_f0x(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_f0x(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_f0x(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_f0x(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_f0x(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* copy f0u */
mxlvl1 = mxGetField(mstruct,0,"f0u");
/* Zeitschritt 0 */
dptr = mpc123_get_f0u(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_f0u(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_f0u(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_f0u(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_f0u(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_f0u(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_f0u(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_f0u(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_f0u(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_f0u(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_f0u(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_f0u(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<1; j++) {
  dptr[j] = (float)diptr [j];}
/* copy f0s */
mxlvl1 = mxGetField(mstruct,0,"f0s");
/* Zeitschritt 0 */
dptr = mpc123_get_f0s(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_f0s(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_f0s(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_f0s(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_f0s(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_f0s(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_f0s(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_f0s(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_f0s(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_f0s(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_f0s(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_f0s(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}
/* copy fx */
mxlvl1 = mxGetField(mstruct,0,"fx");
/* Zeitschritt 0 */
dptr = mpc123_get_fx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_fx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_fx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_fx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_fx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_fx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_fx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_fx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_fx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_fx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_fx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_fx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<36; j++) {
  dptr[j] = (float)diptr [j];}
/* copy fu */
mxlvl1 = mxGetField(mstruct,0,"fu");
/* Zeitschritt 0 */
dptr = mpc123_get_fu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_fu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_fu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_fu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_fu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_fu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_fu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_fu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_fu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_fu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_fu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_fu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* copy f */
mxlvl1 = mxGetField(mstruct,0,"f");
/* Zeitschritt 0 */
dptr = mpc123_get_f(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_f(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_f(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_f(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_f(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_f(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_f(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_f(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_f(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_f(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_f(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_f(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (float)diptr [j];}
/* copy gx */
mxlvl1 = mxGetField(mstruct,0,"gx");
/* Zeitschritt 0 */
dptr = mpc123_get_gx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<24; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_gx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_gx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_gx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_gx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_gx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_gx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_gx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_gx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_gx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_gx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<48; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_gx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<24; j++) {
  dptr[j] = (float)diptr [j];}
/* copy gu */
mxlvl1 = mxGetField(mstruct,0,"gu");
/* Zeitschritt 0 */
dptr = mpc123_get_gu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_gu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_gu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_gu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_gu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_gu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_gu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_gu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_gu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_gu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_gu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_gu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}
/* copy g */
mxlvl1 = mxGetField(mstruct,0,"g");
/* Zeitschritt 0 */
dptr = mpc123_get_g(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 1 */
dptr = mpc123_get_g(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 2 */
dptr = mpc123_get_g(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 3 */
dptr = mpc123_get_g(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 4 */
dptr = mpc123_get_g(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 5 */
dptr = mpc123_get_g(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 6 */
dptr = mpc123_get_g(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 7 */
dptr = mpc123_get_g(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 8 */
dptr = mpc123_get_g(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 9 */
dptr = mpc123_get_g(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 10 */
dptr = mpc123_get_g(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<8; j++) {
  dptr[j] = (float)diptr [j];}
/* Zeitschritt 11 */
dptr = mpc123_get_g(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (float)diptr [j];}

return;
}
void c2matlab(mxArray *output[])
{
/* Pointer auf verschiedene Ebenen im Outputstruct */
mxArray *tmpcell, *tmpdata;
/* Daten-Pointer */
float *dptr;
int *dptr_int;
/* Daten-Output-Pointer */
double *doptr;
int j;
int j1;
int output_dim = 1;
int num_fields = 67;
int num_cells = 12;
int num_cells_single = 1;
/* Feldname für auszugebende Variablen */
const char *field_names[] = {"Hxx", "Hxu", "Huu", "Hss", "f0x", "f0u", "f0s", "fx", "fu", "f", "gx", "gu", "g", "x", "u", "s", "p", "y", "nu", "dx", "du", "dp", "dy", "dnu", "ds", "rf0x", "rf0u", "rf0s", "rf", "rc", "rk", "rs", "rrf0x", "rrf0u", "rhsxs", "yny", "Gxx", "Gxu", "Guu", "Rux", "Vxx", "L", "Gx", "Gu", "Vx", "Ru", "debug_dgap", "debug_phi", "debug_minphi", "debug_norm_d", "debug_norm_r0", "debug_norm_r", "debug_mu0", "debug_mu", "debug_alpha_max", "debug_mehrotra_alpha", "debug_mu_aff", "debug_sigma", "iter", "error_line", "error_source", "termcode", "stat_iter_ref", "stat_num_iter_ref", "stat_num_factor", "stat_num_solve", "stat_time"};

output[0] = mxCreateStructArray(1,&output_dim,num_fields,field_names);

/* copy Hxx */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"Hxx",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_Hxx(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_Hxx(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_Hxx(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_Hxx(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_Hxx(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_Hxx(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_Hxx(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_Hxx(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_Hxx(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_Hxx(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_Hxx(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_Hxx(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }

/* copy Hxu */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Hxu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Hxu(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy Huu */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Huu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Huu(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy Hss */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"Hss",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,4,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_Hss(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_Hss(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_Hss(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_Hss(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_Hss(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_Hss(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_Hss(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_Hss(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_Hss(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_Hss(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,8,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_Hss(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<64;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,4,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_Hss(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }

/* copy f0x */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"f0x",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_f0x(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy f0u */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"f0u",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_f0u(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy f0s */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"f0s",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_f0s(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_f0s(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_f0s(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_f0s(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_f0s(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_f0s(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_f0s(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_f0s(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_f0s(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_f0s(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_f0s(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_f0s(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy fx */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"fx",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_fx(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_fx(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_fx(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_fx(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_fx(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_fx(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_fx(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_fx(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_fx(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_fx(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_fx(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_fx(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }

/* copy fu */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"fu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_fu(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy f */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"f",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_f(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy gx */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"gx",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_gx(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<24;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_gx(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_gx(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_gx(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_gx(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_gx(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_gx(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_gx(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_gx(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_gx(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_gx(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<48;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_gx(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<24;j++) {
doptr[j] = (double)dptr[j]; }

/* copy gu */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"gu",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_gu(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_gu(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_gu(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_gu(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_gu(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_gu(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_gu(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_gu(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_gu(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_gu(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_gu(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_gu(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy g */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"g",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_g(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_g(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_g(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_g(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_g(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_g(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_g(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_g(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_g(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_g(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_g(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_g(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy x */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"x",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_x(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy u */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"u",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_u(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy s */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"s",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_s(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_s(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_s(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_s(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_s(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_s(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_s(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_s(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_s(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_s(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_s(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_s(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy p */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"p",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_p(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy y */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"y",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_y(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_y(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_y(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_y(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_y(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_y(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_y(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_y(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_y(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_y(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_y(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_y(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }

/* copy nu */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"nu",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_nu(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_nu(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_nu(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_nu(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_nu(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_nu(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_nu(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_nu(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_nu(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_nu(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_nu(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_nu(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }

/* copy dx */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"dx",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_dx(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy du */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"du",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_du(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy dp */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"dp",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_dp(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy dy */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"dy",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_dy(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_dy(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_dy(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_dy(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_dy(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_dy(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_dy(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_dy(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_dy(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_dy(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_dy(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_dy(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }

/* copy dnu */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"dnu",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_dnu(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_dnu(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_dnu(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_dnu(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_dnu(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_dnu(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_dnu(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_dnu(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_dnu(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_dnu(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_dnu(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_dnu(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }

/* copy ds */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"ds",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_ds(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_ds(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_ds(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_ds(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_ds(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_ds(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_ds(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_ds(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_ds(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_ds(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_ds(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_ds(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy rf0x */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"rf0x",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_rf0x(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy rf0u */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"rf0u",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_rf0u(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy rf0s */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"rf0s",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_rf0s(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_rf0s(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_rf0s(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_rf0s(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_rf0s(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_rf0s(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_rf0s(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_rf0s(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_rf0s(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_rf0s(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_rf0s(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_rf0s(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy rf */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"rf",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_rf(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy rc */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"rc",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_rc(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_rc(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_rc(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_rc(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_rc(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_rc(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_rc(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_rc(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_rc(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_rc(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_rc(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_rc(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy rk */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"rk",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_rk(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_rk(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_rk(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_rk(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_rk(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_rk(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_rk(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_rk(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_rk(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_rk(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(16,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_rk(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<16;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_rk(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }

/* copy rs */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"rs",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_rs(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_rs(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_rs(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_rs(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_rs(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_rs(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_rs(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_rs(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_rs(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_rs(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_rs(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_rs(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy rrf0x */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"rrf0x",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_rrf0x(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy rrf0u */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"rrf0u",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_rrf0u(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy rhsxs */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"rhsxs",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_rhsxs(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_rhsxs(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_rhsxs(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_rhsxs(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_rhsxs(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_rhsxs(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_rhsxs(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_rhsxs(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_rhsxs(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_rhsxs(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_rhsxs(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_rhsxs(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy yny */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"yny",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_yny(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_yny(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_yny(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_yny(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_yny(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_yny(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_yny(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_yny(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_yny(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_yny(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(8,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_yny(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<8;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(4,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_yny(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<4;j++) {
doptr[j] = (double)dptr[j]; }

/* copy Gxx */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"Gxx",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_Gxx(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_Gxx(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_Gxx(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_Gxx(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_Gxx(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_Gxx(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_Gxx(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_Gxx(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_Gxx(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_Gxx(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_Gxx(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_Gxx(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }

/* copy Gxu */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Gxu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Gxu(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy Guu */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Guu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Guu(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy Rux */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"Rux",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_Rux(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_Rux(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_Rux(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_Rux(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_Rux(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_Rux(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_Rux(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_Rux(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_Rux(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_Rux(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_Rux(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(1,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_Rux(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<6;j++) {
doptr[j] = (double)dptr[j]; }

/* copy Vxx */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"Vxx",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = mpc123_get_Vxx(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = mpc123_get_Vxx(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = mpc123_get_Vxx(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = mpc123_get_Vxx(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = mpc123_get_Vxx(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = mpc123_get_Vxx(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = mpc123_get_Vxx(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = mpc123_get_Vxx(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = mpc123_get_Vxx(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = mpc123_get_Vxx(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = mpc123_get_Vxx(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(6,6,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = mpc123_get_Vxx(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<36;j++) {
doptr[j] = (double)dptr[j]; }

/* copy L */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"L",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_L(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy Gx */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Gx",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Gx(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy Gu */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Gu",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Gu(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy Vx */
tmpdata = mxCreateNumericMatrix(6,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Vx",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Vx(j1);
for (j=0;j<6;j++) {
doptr[j+j1*6] = (double)dptr[j]; }
}

/* copy Ru */
tmpdata = mxCreateNumericMatrix(1,12,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"Ru",tmpdata);
doptr = mxGetPr(tmpdata);
for (j1=0;j1<12;j1++) {
dptr = mpc123_get_Ru(j1);
for (j=0;j<1;j++) {
doptr[j+j1*1] = (double)dptr[j]; }
}

/* copy debug_dgap */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_dgap",tmpdata);
dptr = mpc123_get_debug_dgap();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_phi */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_phi",tmpdata);
dptr = mpc123_get_debug_phi();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_minphi */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_minphi",tmpdata);
dptr = mpc123_get_debug_minphi();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_norm_d */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_norm_d",tmpdata);
dptr = mpc123_get_debug_norm_d();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_norm_r0 */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_norm_r0",tmpdata);
dptr = mpc123_get_debug_norm_r0();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_norm_r */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_norm_r",tmpdata);
dptr = mpc123_get_debug_norm_r();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_mu0 */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_mu0",tmpdata);
dptr = mpc123_get_debug_mu0();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_mu */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_mu",tmpdata);
dptr = mpc123_get_debug_mu();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_alpha_max */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_alpha_max",tmpdata);
dptr = mpc123_get_debug_alpha_max();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_mehrotra_alpha */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_mehrotra_alpha",tmpdata);
dptr = mpc123_get_debug_mehrotra_alpha();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_mu_aff */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_mu_aff",tmpdata);
dptr = mpc123_get_debug_mu_aff();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy debug_sigma */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"debug_sigma",tmpdata);
dptr = mpc123_get_debug_sigma();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }

/* copy iter */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"iter",tmpdata);
dptr_int = mpc123_get_iter();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy error_line */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"error_line",tmpdata);
dptr_int = mpc123_get_error_line();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy error_source */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"error_source",tmpdata);
dptr_int = mpc123_get_error_source();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy termcode */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"termcode",tmpdata);
dptr_int = mpc123_get_termcode();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_iter_ref */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_iter_ref",tmpdata);
dptr_int = mpc123_get_stat_iter_ref();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_iter_ref */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_iter_ref",tmpdata);
dptr_int = mpc123_get_stat_num_iter_ref();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_factor */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_factor",tmpdata);
dptr_int = mpc123_get_stat_num_factor();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_solve */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_solve",tmpdata);
dptr_int = mpc123_get_stat_num_solve();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_time */
tmpdata = mxCreateNumericMatrix(20,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_time",tmpdata);
dptr = mpc123_get_stat_time();
doptr = mxGetPr(tmpdata);
for (j=0;j<20;j++){
doptr[j] = (double)dptr[j]; }


return;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
int termcode = -2;
matlab2c(prhs[0]);
termcode = mpc123_glqdocpip();
mexPrintf("Termcode: %i\n",termcode);
mexEvalString("drawnow;");
{
int i;
double time;
char varname[1024];
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_mv();
sprintf(varname,"Test %20s ()\n","math_mv");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_mv",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_vtm();
sprintf(varname,"Test %20s ()\n","math_vtm");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_vtm",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_mm();
sprintf(varname,"Test %20s ()\n","math_mm");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_mm",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_mtm();
sprintf(varname,"Test %20s ()\n","math_mtm");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_mtm",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_norm_inf();
sprintf(varname,"Test %20s ()\n","math_norm_inf");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_norm_inf",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_vv_elediv();
sprintf(varname,"Test %20s ()\n","math_vv_elediv");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_vv_elediv",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_math_mm_reorder();
sprintf(varname,"Test %20s ()\n","math_mm_reorder");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","math_mm_reorder",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_structure_mult_fx0_v();
sprintf(varname,"Test %20s ()\n","structure_mult_fx0_v");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","structure_mult_fx0_v",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_structure_mult_fx0T_v();
sprintf(varname,"Test %20s ()\n","structure_mult_fx0T_v");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","structure_mult_fx0T_v",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_structure_mult_vT_fx0();
sprintf(varname,"Test %20s ()\n","structure_mult_vT_fx0");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","structure_mult_vT_fx0",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_structure_mult_m_fx0();
sprintf(varname,"Test %20s ()\n","structure_mult_m_fx0");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","structure_mult_m_fx0",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_structure_mult_fx0T_m();
sprintf(varname,"Test %20s ()\n","structure_mult_fx0T_m");
mexPrintf("Test %25s (1000000 Runs): %9.6f ms (avg)\n","structure_mult_fx0T_m",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_affine();
sprintf(varname,"Test %20s ()\n","affine");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","affine",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_reduced();
sprintf(varname,"Test %20s ()\n","reduced");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","reduced",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_factor();
sprintf(varname,"Test %20s ()\n","factor");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","factor",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_solve();
sprintf(varname,"Test %20s ()\n","solve");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","solve",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_dereduce();
sprintf(varname,"Test %20s ()\n","dereduce");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","dereduce",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_starting();
sprintf(varname,"Test %20s ()\n","starting");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","starting",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_rhs_iter_ref();
sprintf(varname,"Test %20s ()\n","rhs_iter_ref");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","rhs_iter_ref",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_iter_ref();
sprintf(varname,"Test %20s ()\n","iter_ref");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","iter_ref",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_norm_d();
sprintf(varname,"Test %20s ()\n","norm_d");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","norm_d",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_norm_r();
sprintf(varname,"Test %20s ()\n","norm_r");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","norm_r",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_mu();
sprintf(varname,"Test %20s ()\n","mu");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","mu",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_duality_gap();
sprintf(varname,"Test %20s ()\n","duality_gap");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","duality_gap",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_calc_phi();
sprintf(varname,"Test %20s ()\n","calc_phi");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","calc_phi",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_check_condiv();
sprintf(varname,"Test %20s ()\n","check_condiv");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","check_condiv",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_max_stepsize();
sprintf(varname,"Test %20s ()\n","max_stepsize");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","max_stepsize",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_mu_aff();
sprintf(varname,"Test %20s ()\n","mu_aff");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","mu_aff",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_sigma();
sprintf(varname,"Test %20s ()\n","sigma");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","sigma",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_corrector();
sprintf(varname,"Test %20s ()\n","corrector");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","corrector",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_mehrotra_step();
sprintf(varname,"Test %20s ()\n","mehrotra_step");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","mehrotra_step",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_step();
sprintf(varname,"Test %20s ()\n","step");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","step",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_startup();
sprintf(varname,"Test %20s ()\n","startup");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","startup",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_1_iteration();
sprintf(varname,"Test %20s ()\n","1_iteration");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","1_iteration",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
for(i=1;i<=1;i++){
time = mpc123_glqdocpip_performance_test_1_iteration_iterref();
sprintf(varname,"Test %20s ()\n","1_iteration_iterref");
mexPrintf("Test %25s (10000 Runs): %9.6f ms (avg)\n","1_iteration_iterref",time);
termcode = mpc123_glqdocpip();
mexEvalString("drawnow;");
}
}
c2matlab(plhs);
return;
}
