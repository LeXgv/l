#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <iostream>
int main()
{
mq_unlink("/test.mq");
mqd_t qid = 0;
struct mq_attr at = {0};
at.mq_flags = 0;
at.mq_maxmsg = 10;
at.mq_msgsize = 20;

qid = mq_open("/test.mq", O_CREAT | O_RDWR, &at);
if(qid == -1)
{
	std::cout << "Ошибка создания очереди\n";
}
char buf[20] = {0};
while(true){
int r = mq_receive(qid, buf, 20, NULL);
if(r != -1)
{
std::cout << "Ошибка на приеме сообщения\n";
return -2;
}
if(r>0)
{
int file = open("message.txt", O_CREAT | O_TRUNC | O_WRONLY, 0777);
write(file, buf, r);
close(file);
}
}

return 0;
}
