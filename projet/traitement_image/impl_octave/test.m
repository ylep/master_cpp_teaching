% -*- octave -*-

dst_lAB = color_transfer(src_lAB, tgt_lAB);

dst_lms = lAB2lms(dst_lAB);
dst = lms2rgb(dst_lms);

imwrite("destination.png", dst(:,:,1), dst(:,:,2), dst(:,:,3))
