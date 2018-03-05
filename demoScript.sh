#!/bin/bash
#
# demoScript.sh
# Author:        LEROY Sébastien
# Creation Date: 2018-02-23
#

function usage () {
  printf "Monitoring script of SDPE\n"
  printf "\n"
  printf "$0\n"
  printf "\t -h --help\n"
  printf "\t -v --verbose\n"
}

while [ "$1" != "" ]; do
    PARAM=`echo $1 | awk -F= '{print $1}'`
    VALUE=`echo $1 | awk -F= '{print $2}'`
    case $PARAM in
        -h | --help)
            usage
            exit
            ;;
        -v | --verbose)
            VERBOSE_MODE=true
            ;;
        *)
            echo "ERROR: unknown parameter \"$PARAM\""
            usage
            exit 1
            ;;
    esac
    shift
done

source "$(dirname "$0")/vardefs.sh.inc"

debug "this is a debug message that only appears when verbose mode is ON"
info  "this is an info block"
warn  "this is warning message"
error "this is an error message"

title "This is a démo script"
fact  "this is a fact and it's variable" "324"
cmd   "This is a command line to be executed that also appears only when the Verbose mode is ON"


