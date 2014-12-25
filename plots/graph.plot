#!/usr/bin/gnuplot -perslst

tst = "test2_rk2"

set macros
set termoption linewidth 3;

set style line 1 linecolor rgb '#de181f' linetype 1 lw 3 # Red
set style line 2 linecolor rgb '#0060ae' linetype 1 lw 3 # Blue
set style line 3 linecolor rgb '#228C22' linetype 1 lw 3 # Forest green

set style line 7 linecolor rgb '#000000' linetype 1 lw 3

#set terminal postscript eps enhanced color
set terminal pdf
set output tst.".pdf"

set grid x2tics y2tics
set x2tics 20 format "" scale 0
set y2tics 50 format "" scale 0

set xrange [0:2]
set yrange [-5:15]

plot tst.".dat" using 1:2 title 'Result' with lines, \
     tst.".dat" using 1:3 title 'Original' with lines
