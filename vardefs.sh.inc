# 
# vardefs.sh.inc
# Author:        LEROY Sébastien
# Creation Date: 2017-10-24 
#
# usage: 
#   1. symlink in the current folder the shellColors.sh file
#   2. symlink (opt.) this file in your script folder 
#   3. source this script at the beginning of your script.
# 

# define general useful scripting variables
CURRENT_FOLDER=$(pwd)
SCRIPT_PATH="$(dirname "$0")"
TS=`date +"%Y%m%d_%H%M"`
if [ -z ${VERBOSE_MODE+x} ]; then VERBOSE_MODE=false; else VERBOSE_MODE=true; fi

# this will check for an xterm* environment varialble and 
# only output color if in an interactive shell
# NB: there are other ways to check for that like $- but it is 
#     not working when launching a script from another proram or scheduler and the shell is not configured properly...
case $TERM in
  *xterm*)
    source "${SCRIPT_PATH}/shellcolors.sh.inc"
    CMDCOL='\e[0;35m'
    RSTCOL='\033[0m'
    printf "${CMDCOL}**Interactive shell**${RSTCOL}\n\n"
  ;;
esac

# Generic logging and script functions
function error {
  FCT_MSG=$1
  printf "%17s - ${red}%7s${RSTCOL} - %s\n" "$(date "+%Y%m%d-%T")" "ERROR" "${FCT_MSG}"
  unset FCT_MSG
}
function warn {
  FCT_MSG=$1
  printf "%17s - ${fg_lred}%7s${RSTCOL} - %s\n" "$(date "+%Y%m%d-%T")" "WARNING" "${FCT_MSG}"
  unset FCT_MSG
}
function info {
  FCT_MSG=$1
  printf "%17s - ${CMDCOL}%7s${RSTCOL} - %s\n" "$(date "+%Y%m%d-%T")" "INFO" "${FCT_MSG}"
  unset FCT_MSG
}
function debug {
  FCT_MSG=$1
  if [ "${VERBOSE_MODE}" = true ]; then
    printf "%17s - ${fg_lgray}%7s - %s${RSTCOL}\n" "$(date "+%Y%m%d-%T")" "DEBUG" "${FCT_MSG}"
  fi
  unset FCT_MSG
}

# Other useful (and colorful) functions to log the scripts' execution
function cmd {
  FCT_MSG=$1
  if [ "${VERBOSE_MODE}" = true ]; then
    printf "%17s - ${CMDCOL}%7s${RSTCOL} - exec cmd: ${fg_lgray}[ %s ]${RSTCOL}\n" "$(date "+%Y%m%d-%T")" "CMD" "${FCT_MSG}"
  fi  
  unset FCT_MSG
}
function fact {
  FCT_MSG=$1
  FCT_VAR=$2
  printf "%17s - ${fg_lblue}%7s${RSTCOL} - %s: ${cyan}%s${RSTCOL}\n" "$(date "+%Y%m%d-%T")" "FACT" "${FCT_MSG}" "${FCT_VAR}"
  unset FCT_MSG FCT_VAR
}
function title {
  FCT_MSG=$1
  printf "%17s - ${CMDCOL}%7s - %s${RSTCOL}\n" "$(date "+%Y%m%d-%T")" "TITLE" "${FCT_MSG}"
  unset FCT_MSG
}





