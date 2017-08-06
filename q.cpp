#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <iostream>
int main()
{
mqd_t qid = 0;
struct mq_attr at = {0};
at.mq_flags = 0;
at.mq_maxmsg = 10;
at.mq_msgsize = 20;

qid = mq_open("/test", O_CREAT | O_RDWR, &at);
if(qid == -1)
{
	std::cout << "Ошибка создания очереди\n";
}


return 0;
}
