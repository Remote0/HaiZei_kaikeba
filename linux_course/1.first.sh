#!/bin/bash
#这是注释
echo "Hello Kaikeba!"
echo "Hello Cui^_^"
WorkDir=`pwd`
echo -e "In\033[31;32m ${WorkDir} \033[0m"
echo "Program Name : $0"
echo "Arg1 : $1"
echo "Arg2 : $2"
echo "Arg3 : $3"
echo "Arg4 : $4"
echo "Arg5 : $5"
echo "Arg6 : $6"
echo "\$@ : $@"
echo "\$* : $*"
echo "\$# : $#"
last | grep "${Name}" 1>/dev/null 2>/dev/null
if [[ $? -eq 0 ]];then
    echo "$Name logged in!"
fi
