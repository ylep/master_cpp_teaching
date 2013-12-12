% -*- octave -*-

src = imread ("source.png");
src = im2double(src);
tgt = imread ("target.png");
tgt = im2double(tgt);

src_lms = rgb2lms(src);
src_lAB = lms2lAB(src_lms);
tgt_lms = rgb2lms(tgt);
tgt_lAB = lms2lAB(tgt_lms);
