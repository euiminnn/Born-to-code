import sys
import os

file_name = sys.argv[1]
tmp_file_name = "__TMP__" + file_name
os.rename(file_name, tmp_file_name)

tmp_file_fd = open(tmp_file_name, "r")
write_file_fd = open(file_name, "w")

is_in_comments = 0;

for line in tmp_file_fd:
    if is_in_comments == 0:
        if line == "/**\n":
            is_in_comments = 1
            continue;
        write_file_fd.write(line)
    else:
        if line == " */\n":
            is_in_comments = 0

tmp_file_fd.close()
write_file_fd.close()

os.remove(tmp_file_name)
