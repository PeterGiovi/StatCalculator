#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main(void){

	printf("Name: ");
	char name[50]; char temp[50];
	memset(name,0,50);
	scanf("%49s", name);

	FILE *ptr;
	ptr = fopen("test.txt", "r");

	int score = 0, kills = 0, deaths = 0, assists = 0, ai = 0, cap = 0;
	int scoreT, killsT, deathsT, assistsT, aiT, capT;

	while(!feof(ptr)){

		memset(temp,0,50);
		//fscanf(ptr, "%[^\n]", temp);
		
		bool done = false, found = false;

		while(done != true && !feof(ptr)){ //searches for name in line
			//printf("Entering search (1)\n"); //flag 1
			fscanf(ptr, "%s %d %d %d %d %d %d", temp, &scoreT, &killsT, &deathsT, &assistsT, &aiT, &capT);
			if(strcmp(name, temp) == 0){
				//printf("Entering found (2)\n"); //flag 2
				found = true;
				done = true;
			}
			//printf("Exiting search (3)\n"); //flag 3
		}
		if(found == true){
			/* Debugging code
			printf("\n\nScoreT: %d\n", scoreT);
			printf("KillsT: %d\n", killsT);
			printf("DeathsT: %d\n", deathsT);
			printf("AssistsT: %d\n", assistsT);
			printf("AIT: %d\n", aiT);
			printf("Cap DmgT: %d\n", capT);
			*/
			score += scoreT;
			kills += killsT;
			deaths += deathsT;
			assists += assistsT;
			ai += aiT;
			cap += capT;
		}
	}
	printf("\nScore: %d\n", score);
	printf("Kills: %d\n", kills);
	printf("Deaths: %d\n", deaths);
	printf("Assists: %d\n", assists);
	printf("AI: %d\n", ai);
	printf("Cap Dmg: %d\n", cap);

	printf("\ntype Exit to close");
	scanf("%s", &name);
	return 0;
}