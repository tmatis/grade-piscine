# GRADING C 00 tool

TRACE_FILE=trace.log

# COLORS

RED='\033[0;31m';
GREEN='\033[0;32m';
YELLOW='\033[0;33m';
BLUE='\033[0;34m';
PURPLE='\033[0;35m';
CYAN='\033[0;36m';
WHITE='\033[0;37m';
BOLD='\033[1m';
UNDERLINE='\033[4m';
RESET='\033[0m';

# function put in trace

trace_real_path=$(realpath $TRACE_FILE)

exec_trace() {
    echo "$> $1" &>> $trace_real_path
    eval "$1" &>> $trace_real_path
    ret_value=$?
    echo &>> $trace_real_path
    return $ret_value
}

end_test() {
	echo "============$1==============" &>> $trace_real_path
	echo $2 &>> $trace_real_path
}

printf "${CYAN}${BOLD}GRADING C 00 TOOL${RESET}\n\n";

exs_to_grade=$(ls -d */ | xargs | sed 's/\///g');
exs_count=$(ls -d */ | wc -l);

printf "${CYAN}${BOLD}>>> ${RESET} enter your git URL\n";
read repo;
#repo='https://git.hexanyn.fr/42/piscine/c00.git';

printf "\n${CYAN}${BOLD}>>> ${RESET}${BOLD}cloning repo ... ${RESET}";

echo "GRADING C 00 TOOL" > $TRACE_FILE

exec_trace "uname -a"

exec_trace "git clone $repo temp";

ret_value=$?;
if [ $ret_value -eq 0 ]; then
    printf "${GREEN}${BOLD}	[OK]${RESET}\n";
else
    printf "${RED}${BOLD}	[FAILED]${RESET}\n";
    exit 1;
fi

read

exec_trace "ls -la temp/*/*.c";

for ex in $exs_to_grade; do
    echo "============$ex==============" >> $trace_real_path;
    printf "\n${CYAN}${BOLD}>>> ${RESET}${BOLD}grading $ex ... ${RESET}\n";
    C_FILES=$(find $ex/ -name '*.c' -exec basename {} \; | grep -v main.c);
    # check if there is at least one file of C_FILES in ./temp/$ex
    FILES_PRESENT="";
    for file in $C_FILES; do
        if [ -f "./temp/$ex/$file" ]; then
            FILES_PRESENT="$FILES_PRESENT $file";
        fi
    done
    printf "${CYAN}${BOLD}   ${RESET} file turned in ";
    #check if FILES_PRESENT is not empty
    if [ ! -z "$FILES_PRESENT" ]; then
        printf "${GREEN}${BOLD}	[OK]${RESET}\n";
        printf "${CYAN}${BOLD}   ${RESET} compilation ";
        exec_trace "cd temp/$ex";
        exec_trace "clang -Wall -Wextra -Werror -o ../your_bin $FILES_PRESENT ../../$ex/main.c";
        ret_value=$?;
        if [ $ret_value -eq 0 ]; then
		    exec_trace "cd -";
            printf "${GREEN}${BOLD}	[OK]${RESET}\n";
            exec_trace "cd $ex";
            exec_trace "clang -Wall -Wextra -Werror -o ../temp/our_bin $C_FILES ./main.c";
            exec_trace "cd -";
            printf "${CYAN}${BOLD}   ${RESET} execution	";
            exec_trace "./temp/our_bin > ./temp/our_output";
			exec_trace "./temp/your_bin > ./temp/your_output";
			ret_value=$?;
			if [ $ret_value -eq 0 ]; then
				printf "${GREEN}${BOLD}	[OK]${RESET}\n";
				printf "${CYAN}${BOLD}   ${RESET} output	";
				exec_trace "diff -d -a ./temp/your_output ./temp/our_output";
				ret_value=$?;
				if [ $ret_value -eq 0 ]; then
					printf "${GREEN}${BOLD}	[OK]${RESET}\n";
					end_test 'ok' 'everything is fine';
				else
					printf "${RED}${BOLD}	[FAILED]${RESET}\n";
					end_test ko "your output is different from our output"
				fi
			else
			    printf "${RED}${BOLD}	[FAILED]${RESET}\n";
				end_test 'ko' 'your_bin failed to execute'
			fi
        else
			exec_trace "cd -";
            printf "${RED}${BOLD}	[FAILED]${RESET}\n";
			end_test 'ko' 'cannot compile'
        fi
    else
        printf "${RED}${BOLD}	[FAILED]${RESET}\n";
		end_test 'ko' "no file turned in"
    fi

done

exec_trace "rm -rf temp"
