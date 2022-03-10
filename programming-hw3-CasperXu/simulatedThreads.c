#include "threadtools.h"

// Please complete this three functions. You may refer to the macro function defined in "threadtools.h"

// Mountain Climbing
// You are required to solve this function via iterative method, instead of recursion.
void MountainClimbing(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);
	if(Work->N==0||Work->N==1){
		sleep(1);
		printf("MountainClimbing: 1\n");
	}
	while(Work->i<=Work->N){
		sleep(1);
		Work->z = Work->x + Work->y;
		printf("MountainClimbing: %d\n",Work->z);
		Work->x = Work->y;
		Work->y = Work->z;
		Work->i++;
		if(switchmode == 0){
			ThreadYield();
		}
		else{
			sigpending(&waiting_mask);
			if(sigismember(&waiting_mask, SIGTSTP))
				sigprocmask(SIG_SETMASK, &alrm_mask,NULL);
			else if(sigismember(&waiting_mask, SIGALRM))
				sigprocmask(SIG_SETMASK, &tstp_mask,NULL);
		}
	}
	ThreadExit();
}

// Reduce Integer
// You are required to solve this function via iterative method, instead of recursion.
void ReduceInteger(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);
	while(Work->N){
		sleep(1);
		if(Work->N%2==0){
			Work->N=Work->N/2;
		}
		else if(Work->N%4==3&&Work->N!=3){
			Work->N++;
		}
		else{
			Work->N--;
		}
		printf("ReduceInteger: %d\n",Work->w);
		Work->w++;
		if(switchmode==0){
			ThreadYield();
		}
		else{
			sigpending(&waiting_mask);
			if(sigismember(&waiting_mask, SIGTSTP))
				sigprocmask(SIG_SETMASK,&alrm_mask,NULL);
			else if(sigismember(&waiting_mask, SIGALRM))
				sigprocmask(SIG_SETMASK,&tstp_mask,NULL);
		}
	}
	ThreadExit()
}

// Operation Count
// You are required to solve this function via iterative method, instead of recursion.
void OperationCount(int thread_id, int number){
	/* Please fill this code section. */
	ThreadInit(thread_id,number);
	sleep(1);
	printf("OperationCount: %d\n",(Work->N)/2*((Work->N+1)/2));
	if(switchmode==1){
		sigpending(&waiting_mask);
		if(sigismember(&waiting_mask, SIGTSTP))
			sigprocmask(SIG_SETMASK, &alrm_mask,NULL);
		else if(sigismember(&waiting_mask, SIGALRM))
			sigprocmask(SIG_SETMASK, &tstp_mask,NULL);
	}
	ThreadExit();
}
// function_name(parameters){
// 	ThreadInit();
// 	for(...){
// 		sleep(1);
// 		function work 
// 		ThreadYield();
// 	} 
// 	ThreadExit();
// }
// {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074,32951280099,53316291173,86267571272,139583862445,225851433717,365435296162,591286729879,956722026041,1548008755920,2504730781961,4052739537881,6557470319842,10610209857723,17167680177565,27777890035288,44945570212853,72723460248141,117669030460994,190392490709135,308061521170129,498454011879264,806515533049393,1304969544928657,2111485077978050,3416454622906707,5527939700884757,8944394323791464,14472334024676221,23416728348467685,37889062373143906,61305790721611591,99194853094755497,160500643816367088,259695496911122585,420196140727489673,679891637638612258,1100087778366101931,1779979416004714189,2880067194370816120,4660046610375530309,7540113804746346429,12200160415121876738,19740274219868223167,31940434634990099905,51680708854858323072,83621143489848422977,135301852344706746049,218922995834555169026,354224848179261915075,573147844013817084101}

