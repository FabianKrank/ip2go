/* ########### */
/* # INCLUDE # */
/* ########### */
#include "mex.h"
#include "linflp_k24_glqdocpip.h"

void matlab2c(mxArray *mstruct)
{
int j;
mxArray *mxlvl1, *mxlvl2;
double *diptr;
double*dptr;

/* Anfangsbedingung */
mxlvl1 = mxGetField(mstruct,0,"xinit");
dptr = linflp_k24_get_x0();
diptr = mxGetPr(mxlvl1);
for(j=0; j<3; j++)
{
dptr[j] = (double)diptr [j];
}
/* copy Hxx */
mxlvl1 = mxGetField(mstruct,0,"Hxx");
/* Zeitschritt 0 */
dptr = linflp_k24_get_Hxx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_Hxx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_Hxx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_Hxx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_Hxx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_Hxx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_Hxx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_Hxx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_Hxx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_Hxx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_Hxx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_Hxx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_Hxx(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_Hxx(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_Hxx(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_Hxx(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_Hxx(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_Hxx(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_Hxx(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_Hxx(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_Hxx(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_Hxx(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_Hxx(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_Hxx(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_Hxx(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* copy Hxu */
mxlvl1 = mxGetField(mstruct,0,"Hxu");
/* Zeitschritt 0 */
dptr = linflp_k24_get_Hxu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_Hxu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_Hxu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_Hxu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_Hxu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_Hxu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_Hxu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_Hxu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_Hxu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_Hxu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_Hxu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_Hxu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_Hxu(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_Hxu(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_Hxu(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_Hxu(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_Hxu(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_Hxu(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_Hxu(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_Hxu(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_Hxu(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_Hxu(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_Hxu(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_Hxu(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_Hxu(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* copy Huu */
mxlvl1 = mxGetField(mstruct,0,"Huu");
/* Zeitschritt 0 */
dptr = linflp_k24_get_Huu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_Huu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_Huu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_Huu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_Huu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_Huu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_Huu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_Huu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_Huu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_Huu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_Huu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_Huu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_Huu(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_Huu(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_Huu(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_Huu(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_Huu(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_Huu(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_Huu(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_Huu(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_Huu(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_Huu(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_Huu(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_Huu(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_Huu(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<4; j++) {
  dptr[j] = (double)diptr [j];}
/* copy Hss */
mxlvl1 = mxGetField(mstruct,0,"Hss");
/* Zeitschritt 0 */
dptr = linflp_k24_get_Hss(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_Hss(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_Hss(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_Hss(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_Hss(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_Hss(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_Hss(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_Hss(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_Hss(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_Hss(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_Hss(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_Hss(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_Hss(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_Hss(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_Hss(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_Hss(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_Hss(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_Hss(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_Hss(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_Hss(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_Hss(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_Hss(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_Hss(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_Hss(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_Hss(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* copy f0x */
mxlvl1 = mxGetField(mstruct,0,"f0x");
/* Zeitschritt 0 */
dptr = linflp_k24_get_f0x(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_f0x(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_f0x(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_f0x(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_f0x(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_f0x(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_f0x(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_f0x(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_f0x(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_f0x(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_f0x(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_f0x(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_f0x(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_f0x(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_f0x(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_f0x(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_f0x(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_f0x(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_f0x(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_f0x(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_f0x(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_f0x(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_f0x(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_f0x(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_f0x(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* copy f0u */
mxlvl1 = mxGetField(mstruct,0,"f0u");
/* Zeitschritt 0 */
dptr = linflp_k24_get_f0u(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_f0u(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_f0u(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_f0u(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_f0u(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_f0u(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_f0u(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_f0u(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_f0u(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_f0u(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_f0u(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_f0u(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_f0u(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_f0u(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_f0u(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_f0u(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_f0u(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_f0u(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_f0u(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_f0u(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_f0u(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_f0u(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_f0u(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_f0u(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_f0u(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<2; j++) {
  dptr[j] = (double)diptr [j];}
/* copy f0s */
mxlvl1 = mxGetField(mstruct,0,"f0s");
/* Zeitschritt 0 */
dptr = linflp_k24_get_f0s(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_f0s(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_f0s(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_f0s(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_f0s(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_f0s(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_f0s(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_f0s(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_f0s(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_f0s(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_f0s(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_f0s(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_f0s(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_f0s(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_f0s(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_f0s(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_f0s(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_f0s(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_f0s(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_f0s(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_f0s(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_f0s(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_f0s(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_f0s(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_f0s(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<0; j++) {
  dptr[j] = (double)diptr [j];}
/* copy fx */
mxlvl1 = mxGetField(mstruct,0,"fx");
/* Zeitschritt 0 */
dptr = linflp_k24_get_fx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_fx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_fx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_fx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_fx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_fx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_fx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_fx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_fx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_fx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_fx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_fx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_fx(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_fx(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_fx(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_fx(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_fx(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_fx(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_fx(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_fx(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_fx(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_fx(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_fx(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_fx(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_fx(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<9; j++) {
  dptr[j] = (double)diptr [j];}
/* copy fu */
mxlvl1 = mxGetField(mstruct,0,"fu");
/* Zeitschritt 0 */
dptr = linflp_k24_get_fu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_fu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_fu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_fu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_fu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_fu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_fu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_fu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_fu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_fu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_fu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_fu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_fu(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_fu(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_fu(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_fu(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_fu(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_fu(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_fu(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_fu(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_fu(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_fu(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_fu(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_fu(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_fu(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<6; j++) {
  dptr[j] = (double)diptr [j];}
/* copy f */
mxlvl1 = mxGetField(mstruct,0,"f");
/* Zeitschritt 0 */
dptr = linflp_k24_get_f(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_f(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_f(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_f(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_f(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_f(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_f(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_f(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_f(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_f(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_f(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_f(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_f(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_f(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_f(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_f(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_f(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_f(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_f(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_f(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_f(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_f(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_f(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_f(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_f(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<3; j++) {
  dptr[j] = (double)diptr [j];}
/* copy gx */
mxlvl1 = mxGetField(mstruct,0,"gx");
/* Zeitschritt 0 */
dptr = linflp_k24_get_gx(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_gx(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_gx(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_gx(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_gx(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_gx(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_gx(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_gx(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_gx(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_gx(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_gx(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_gx(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_gx(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_gx(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_gx(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_gx(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_gx(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_gx(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_gx(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_gx(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_gx(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_gx(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_gx(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_gx(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_gx(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<30; j++) {
  dptr[j] = (double)diptr [j];}
/* copy gu */
mxlvl1 = mxGetField(mstruct,0,"gu");
/* Zeitschritt 0 */
dptr = linflp_k24_get_gu(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_gu(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_gu(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_gu(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_gu(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_gu(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_gu(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_gu(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_gu(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_gu(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_gu(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_gu(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_gu(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_gu(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_gu(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_gu(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_gu(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_gu(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_gu(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_gu(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_gu(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_gu(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_gu(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_gu(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_gu(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<20; j++) {
  dptr[j] = (double)diptr [j];}
/* copy g */
mxlvl1 = mxGetField(mstruct,0,"g");
/* Zeitschritt 0 */
dptr = linflp_k24_get_g(0);
mxlvl2 = mxGetCell(mxlvl1,0);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 1 */
dptr = linflp_k24_get_g(1);
mxlvl2 = mxGetCell(mxlvl1,1);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 2 */
dptr = linflp_k24_get_g(2);
mxlvl2 = mxGetCell(mxlvl1,2);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 3 */
dptr = linflp_k24_get_g(3);
mxlvl2 = mxGetCell(mxlvl1,3);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 4 */
dptr = linflp_k24_get_g(4);
mxlvl2 = mxGetCell(mxlvl1,4);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 5 */
dptr = linflp_k24_get_g(5);
mxlvl2 = mxGetCell(mxlvl1,5);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 6 */
dptr = linflp_k24_get_g(6);
mxlvl2 = mxGetCell(mxlvl1,6);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 7 */
dptr = linflp_k24_get_g(7);
mxlvl2 = mxGetCell(mxlvl1,7);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 8 */
dptr = linflp_k24_get_g(8);
mxlvl2 = mxGetCell(mxlvl1,8);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 9 */
dptr = linflp_k24_get_g(9);
mxlvl2 = mxGetCell(mxlvl1,9);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 10 */
dptr = linflp_k24_get_g(10);
mxlvl2 = mxGetCell(mxlvl1,10);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 11 */
dptr = linflp_k24_get_g(11);
mxlvl2 = mxGetCell(mxlvl1,11);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 12 */
dptr = linflp_k24_get_g(12);
mxlvl2 = mxGetCell(mxlvl1,12);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 13 */
dptr = linflp_k24_get_g(13);
mxlvl2 = mxGetCell(mxlvl1,13);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 14 */
dptr = linflp_k24_get_g(14);
mxlvl2 = mxGetCell(mxlvl1,14);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 15 */
dptr = linflp_k24_get_g(15);
mxlvl2 = mxGetCell(mxlvl1,15);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 16 */
dptr = linflp_k24_get_g(16);
mxlvl2 = mxGetCell(mxlvl1,16);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 17 */
dptr = linflp_k24_get_g(17);
mxlvl2 = mxGetCell(mxlvl1,17);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 18 */
dptr = linflp_k24_get_g(18);
mxlvl2 = mxGetCell(mxlvl1,18);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 19 */
dptr = linflp_k24_get_g(19);
mxlvl2 = mxGetCell(mxlvl1,19);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 20 */
dptr = linflp_k24_get_g(20);
mxlvl2 = mxGetCell(mxlvl1,20);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 21 */
dptr = linflp_k24_get_g(21);
mxlvl2 = mxGetCell(mxlvl1,21);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 22 */
dptr = linflp_k24_get_g(22);
mxlvl2 = mxGetCell(mxlvl1,22);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 23 */
dptr = linflp_k24_get_g(23);
mxlvl2 = mxGetCell(mxlvl1,23);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}
/* Zeitschritt 24 */
dptr = linflp_k24_get_g(24);
mxlvl2 = mxGetCell(mxlvl1,24);
diptr = mxGetPr(mxlvl2);
for(j=0; j<10; j++) {
  dptr[j] = (double)diptr [j];}

return;
}
void c2matlab(mxArray *output[])
{
/* Pointer auf verschiedene Ebenen im Outputstruct */
mxArray *tmpcell, *tmpdata;
/* Daten-Pointer */
double *dptr;
int *dptr_int;
/* Daten-Output-Pointer */
double *doptr;
int j;
int output_dim = 1;
int num_fields = 15;
int num_cells = 25;
int num_cells_single = 1;
/* Feldname für auszugebende Variablen */
const char *field_names[] = {"x", "u", "s", "p", "y", "nu", "stat_iter_ref", "stat_num_iter_ref", "stat_num_factor", "stat_num_solve", "stat_time", "iter", "error_line", "error_source", "termcode"};

output[0] = mxCreateStructArray(1,&output_dim,num_fields,field_names);

/* copy x */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"x",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_x(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_x(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_x(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_x(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_x(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_x(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_x(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_x(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_x(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_x(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_x(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_x(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_x(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_x(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_x(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_x(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_x(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_x(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_x(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_x(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_x(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_x(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_x(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_x(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_x(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }

/* copy u */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"u",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_u(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_u(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_u(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_u(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_u(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_u(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_u(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_u(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_u(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_u(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_u(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_u(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_u(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_u(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_u(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_u(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_u(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_u(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_u(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_u(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_u(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_u(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_u(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_u(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(2,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_u(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<2;j++) {
doptr[j] = (double)dptr[j]; }

/* copy s */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"s",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_s(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_s(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_s(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_s(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_s(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_s(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_s(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_s(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_s(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_s(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_s(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_s(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_s(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_s(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_s(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_s(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_s(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_s(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_s(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_s(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_s(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_s(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_s(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_s(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(0,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_s(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<0;j++) {
doptr[j] = (double)dptr[j]; }

/* copy p */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"p",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_p(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_p(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_p(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_p(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_p(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_p(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_p(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_p(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_p(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_p(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_p(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_p(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_p(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_p(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_p(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_p(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_p(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_p(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_p(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_p(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_p(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_p(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_p(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_p(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(3,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_p(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<3;j++) {
doptr[j] = (double)dptr[j]; }

/* copy y */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"y",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_y(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_y(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_y(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_y(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_y(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_y(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_y(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_y(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_y(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_y(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_y(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_y(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_y(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_y(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_y(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_y(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_y(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_y(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_y(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_y(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_y(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_y(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_y(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_y(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_y(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }

/* copy nu */
tmpcell = mxCreateCellArray(1,&num_cells);
mxSetField(output[0],0,"nu",tmpcell);
/* Zeitschritt 0 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,0,tmpdata);
dptr = linflp_k24_get_nu(0);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 1 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,1,tmpdata);
dptr = linflp_k24_get_nu(1);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 2 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,2,tmpdata);
dptr = linflp_k24_get_nu(2);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 3 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,3,tmpdata);
dptr = linflp_k24_get_nu(3);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 4 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,4,tmpdata);
dptr = linflp_k24_get_nu(4);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 5 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,5,tmpdata);
dptr = linflp_k24_get_nu(5);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 6 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,6,tmpdata);
dptr = linflp_k24_get_nu(6);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 7 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,7,tmpdata);
dptr = linflp_k24_get_nu(7);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 8 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,8,tmpdata);
dptr = linflp_k24_get_nu(8);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 9 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,9,tmpdata);
dptr = linflp_k24_get_nu(9);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 10 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,10,tmpdata);
dptr = linflp_k24_get_nu(10);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 11 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,11,tmpdata);
dptr = linflp_k24_get_nu(11);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 12 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,12,tmpdata);
dptr = linflp_k24_get_nu(12);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 13 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,13,tmpdata);
dptr = linflp_k24_get_nu(13);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 14 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,14,tmpdata);
dptr = linflp_k24_get_nu(14);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 15 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,15,tmpdata);
dptr = linflp_k24_get_nu(15);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 16 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,16,tmpdata);
dptr = linflp_k24_get_nu(16);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 17 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,17,tmpdata);
dptr = linflp_k24_get_nu(17);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 18 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,18,tmpdata);
dptr = linflp_k24_get_nu(18);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 19 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,19,tmpdata);
dptr = linflp_k24_get_nu(19);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 20 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,20,tmpdata);
dptr = linflp_k24_get_nu(20);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 21 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,21,tmpdata);
dptr = linflp_k24_get_nu(21);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 22 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,22,tmpdata);
dptr = linflp_k24_get_nu(22);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 23 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,23,tmpdata);
dptr = linflp_k24_get_nu(23);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }
/* Zeitschritt 24 */
tmpdata = mxCreateNumericMatrix(10,1,mxDOUBLE_CLASS,mxREAL);
mxSetCell(tmpcell,24,tmpdata);
dptr = linflp_k24_get_nu(24);
doptr = mxGetPr(tmpdata);
for (j=0;j<10;j++) {
doptr[j] = (double)dptr[j]; }

/* copy stat_iter_ref */
tmpdata = mxCreateNumericMatrix(100,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_iter_ref",tmpdata);
dptr_int = linflp_k24_get_stat_iter_ref();
doptr = mxGetPr(tmpdata);
for (j=0;j<100;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_iter_ref */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_iter_ref",tmpdata);
dptr_int = linflp_k24_get_stat_num_iter_ref();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_factor */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_factor",tmpdata);
dptr_int = linflp_k24_get_stat_num_factor();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_num_solve */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_num_solve",tmpdata);
dptr_int = linflp_k24_get_stat_num_solve();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy stat_time */
tmpdata = mxCreateNumericMatrix(100,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"stat_time",tmpdata);
dptr = linflp_k24_get_stat_time();
doptr = mxGetPr(tmpdata);
for (j=0;j<100;j++){
doptr[j] = (double)dptr[j]; }

/* copy iter */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"iter",tmpdata);
dptr_int = linflp_k24_get_iter();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy error_line */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"error_line",tmpdata);
dptr_int = linflp_k24_get_error_line();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy error_source */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"error_source",tmpdata);
dptr_int = linflp_k24_get_error_source();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }

/* copy termcode */
tmpdata = mxCreateNumericMatrix(1,1,mxDOUBLE_CLASS,mxREAL);
mxSetField(output[0],0,"termcode",tmpdata);
dptr_int = linflp_k24_get_termcode();
doptr = mxGetPr(tmpdata);
for (j=0;j<1;j++){
doptr[j] = (double)dptr_int[j]; }


return;
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
int termcode = -2;
matlab2c(prhs[0]);
termcode = linflp_k24_glqdocpip();
mexPrintf("Termcode: %i\n",termcode);
mexEvalString("drawnow;");
c2matlab(plhs);
return;
}
