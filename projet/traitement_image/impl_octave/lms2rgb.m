% -*- octave -*-

function rgb = lms2rgb(lms)

mat = [ 4.4679  -3.5873  0.1193;
       -1.2186   2.3809 -0.1624;
        0.0497  -0.2439  1.2045];

rgb = im_lin_color_trans(lms, mat);
