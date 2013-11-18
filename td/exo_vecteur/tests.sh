#! /bin/sh

testdir=$(dirname $0)

# Mise en exergue des en-têtes
reset=$(tput sgr0 2>/dev/null)
etape=$(tput bold 2>/dev/null)$(tput setaf 4 2>/dev/null)

compilation () {
    N=$1
    shift
    echo "${etape}Compilation du test $N"
    echo g++ -Wall -Wextra -g -I. -o test$N "$testdir"/test$N.cc vecteur.cc "$@" ${reset}

    g++ -Wall -Wextra -g -I. -o test$N "$testdir"/test$N.cc vecteur.cc "$@"
}

execution () {
    echo "${etape}Exécution du test $1${reset}"
    echo ./test$1${reset}

    # MALLOC_CHECK_=3 règle glibc pour afficher les problèmes d'allocation
    # dynamique et abandonner l'exécution
    MALLOC_CHECK_=3 ./test$1
}

compilation 1 && execution 1 \
&& compilation 2 && execution 2 \
&& compilation 3 && execution 3 \
&& compilation 4 && execution 4 \
&& compilation 5 && execution 5 \
&& compilation 6 && execution 6 \
&& compilation 7 vecteur_euclidien.cc && execution 7 \
&& compilation 8 vecteur_euclidien.cc && execution 8 \
