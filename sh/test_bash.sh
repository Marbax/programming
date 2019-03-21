#!/usr/bin/env bash

user = anotherUser
if grep $user /etc/passwd
then
	echo "The user $user exists"
else
	echo "The user $user doesent exists"
fi

