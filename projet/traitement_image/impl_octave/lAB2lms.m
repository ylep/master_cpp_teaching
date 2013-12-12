% -*- octave -*-

function lms = lAB2lms(lAB)

mat = [ 1  1  1;
        1  1 -1;
        1 -2 0 ] * diag([sqrt(3)/3 sqrt(6)/6 sqrt(2)/2]);

lms = exp(im_lin_color_trans(lAB, mat));
