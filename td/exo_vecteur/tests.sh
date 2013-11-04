#! /bin/sh

reset=$(tput sgr0 2>/dev/null)
etape=$(tput bold 2>/dev/null)$(tput setaf 4 2>/dev/null)

compilation () {
    echo "${etape}Compilation du test $1"
    echo g++ -Wall -Wextra -o test$1 test$1.cc vecteur.cc${reset}
    g++ -Wall -Wextra -o test$1 test$1.cc vecteur.cc
}

execution () {
    echo "${etape}Exécution du test $1${reset}"
    echo ./test$1${reset}
    ./test$1
}

compilation 1 \
&& execution 1 \
&& compilation 2 \
&& execution 2 \
&& compilation 3 \
&& execution 3 \
&& compilation 4 \
&& execution 4 \
