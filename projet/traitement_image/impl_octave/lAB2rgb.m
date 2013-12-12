function rgb = lAB2rgb(lAB)

rgb = lms2rgb(lAB2lms(lAB));
