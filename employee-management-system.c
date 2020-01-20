#include<stdio.h>
#include <windows.h> //for windows related functions like Sleep() function and ect,..

/* FOR ADMINISTRATOR FUNCTION */
void Manage_Employee();
void Add_Employee();
void List_Employee();
void Update_Employee();
void Search_Employee();
void Delete_Employee();
void Exit_System();

// global structure declaration for EmployeeDetails.
struct EmployeeDetails{
	char emp_id[50];
	char fname[50];
	char lname[50];
	char mname[50];
	char age[50];
	char birthdate[50];
	char address[50];
	char contact[50];
	char salary[50];
};
struct EmployeeDetails e;

int main(){
	
	int i;
	
	printf("\n\n\n\n\n\n\n\n\n                      ::::::::::::: E=M=P=L=O=Y=E=E  M=A=N=A=G=E=M=E=N=T  S=Y=S=T=E=M :::::::::::::\n");
	
	printf("\n\n\n\n\n\n\n\n                                                   LOADING PLEASE WAIT\n\n\t\t\t\t\t      ");
	
	for(i = 0; i < 15; i++){
		
		printf(". ");
		Sleep(700);
		
	}
	
	system("cls");
	Manage_Employee();
	
	return 0;
	
}

void Manage_Employee()
{
	char choice;
	
	printf("\n\n\t\t\t\t\t     <<----- MANAGE EMPLOYEE ----->>\n\n");
	
 	printf("\t\t\t\t\t     (1)ADD EMPLOYEE.\n\n");
 	
 	printf("\t\t\t\t\t     (2)ALL EMPLOYEE.\n\n");
 	
 	printf("\t\t\t\t\t     (3)UPDATE EMPLOYEE.\n\n");
 	
 	printf("\t\t\t\t\t     (4)SEARCH EMPLOYEE.\n\n");
 	
 	printf("\t\t\t\t\t     (5)DELETE EMPLOYEE.\n\n");
 	
 	printf("\t\t\t\t\t     (6)EXIT.\n\n\n");
 	
 	printf("\t\t\t\t\t      ENTER CHOICE: ");
 	scanf("\t\t\t\t\t       %s",&choice);
 	
 	switch(choice){
	 	case '1':
	 	system("cls");
	 	Add_Employee();
	 	break;
	 	
	 	case '2':
	 	system("cls");
	 	List_Employee();
	 	break;
	 	
	 	case '3':
	 	system("cls");
	 	Update_Employee();
	 	break;
	 	
	 	case '4':
	 	system("cls");
	 	Search_Employee();
	 	break;
	 	
	 	case '5':
	 	system("cls");
	 	Delete_Employee();
	 	break;
	 	
	 	case '6':
	 	system("cls");
	 	Exit_System();
	 	break;
	 	
	 	default:
	 	system("cls");
	 	printf("\n\n\t\t\t\t\t     INVALID INPUT!\n");
	 	Manage_Employee();
	 }
	 
}

void Add_Employee() {
	
	char another,save;

	FILE *fp_employee_info;
	
	fp_employee_info = fopen("employee_info.txt","a");
	
	if(fp_employee_info == NULL){
		printf("\t\t\t\t\t     FILE DOES NOT EXIST!\n\n");
		exit(1);
	}
	
	printf("\n\t\t\t\t\t     <<----- ADD EMPLOYEE ----->>\n\n");
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE ID:             ");	
	scanf("%s",&e.emp_id);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE FIRSTNAME:      ");
	scanf("%s",&e.fname);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE LASTNAME:       ");
	scanf("%s",&e.lname);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE MIDDLENAME:     ");
	scanf("%s",&e.mname);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE AGE:            ");
	scanf("%s",&e.age);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE BIRTHDATE:      ");
	scanf("%s",&e.birthdate);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE ADDRESS:        ");
	scanf("%s",&e.address);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE CONTACT NUMBER: ");
	scanf("%s",&e.contact);
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE SALARY:         ");
	scanf("%s",&e.salary);
	
	printf("\n\t\t\t\t\t     SAVE(Y/N)? ");
	scanf("%s",&save);
	
	if(save == 'y' || save == 'Y'){
		
		fprintf(fp_employee_info,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);
		
		printf("\n\t\t\t\t\t     SUCCESSSFULLY SAVE!!\n");
		
		fclose(fp_employee_info);	
			
		printf("\t\t\t\t\t     ADD ANOTHER(Y/N)? ");
		scanf("%s",&another);
			
		if(another == 'y' || another == 'Y'){
				
			system("cls");
			Add_Employee();
				
		}else if(another == 'n' || another == 'N'){
				
			system("cls");
			Manage_Employee();
				
		}else{
			
			system("cls");
			printf("\n\n\t\t\t\t\t     INVALID INPUT!!!\n");
			Add_Employee();
			
		}
	
	}else if(save == 'n' || save == 'N'){
		
		system("cls");
		Manage_Employee();
		
	}else{
		
		system("cls");
		printf("\n\n\t\t\t\t\t     INVALID INPUT!!!\n");
		Add_Employee();
		
	}
	
}

void List_Employee() {
	
	char back;
	
	FILE *fp_employee_info;
	
	fp_employee_info = fopen("employee_info.txt","r");
	
	if(fp_employee_info == NULL){
		printf("\t\t\t\t\t     FILE DOES NOT EXIST!!!\n");
		exit(1);
	}
	

	printf("\n\t\t\t\t\t     <<----- ALL EMPLOYEE ----->>\n\n");
	
	while(fscanf(fp_employee_info,"%s %s %s %s %s %s %s %s %s\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary) != EOF){
			printf("\t\t\t\t\t     ============================\n");	
			printf("\t\t\t\t\t     ID:             %s",e.emp_id);	
			printf("\n");
			printf("\t\t\t\t\t     FIRSTNAME:      %s",e.fname);
			printf("\n");
			printf("\t\t\t\t\t     LASTNAME:       %s",e.lname);
		    printf("\n");
			printf("\t\t\t\t\t     MIDDLENAME:     %s",e.mname);
			printf("\n");
			printf("\t\t\t\t\t     AGE:            %s",e.age);
			printf("\n");
			printf("\t\t\t\t\t     BIRTHDATE:      %s",e.birthdate);
			printf("\n");
			printf("\t\t\t\t\t     ADDRESS:        %s",e.address);
			printf("\n");
			printf("\t\t\t\t\t     CONTACT:        %s",e.contact);
			printf("\n");
			printf("\t\t\t\t\t     SALARY:         %s",e.salary);
			printf("\n");
	
	}
	

	
	fclose(fp_employee_info);
	
	printf("\n\n  BACK(Y/N)? ");
	scanf("%s",&back);
	
	if(back == 'y' || back == 'Y'){
		
		system("cls");
		Manage_Employee();
		
	}else if(back == 'n' || back == 'Y'){
		
		system("cls");
		List_Employee();
		
	}else{
		
		system("cls");
		printf("\n\t\t\t\t\t     INVALID INPUT!!!\n\n");
		List_Employee();
		
	}
	
}

void Update_Employee(){
	
	int i;
	int check_save_count;
	char compare_emp_id[20];
	char save_changes;
	char another_update;
	
	FILE *fp_employee_info;
	FILE *fp_temp_file_update_employee;
	
	fp_employee_info = fopen("employee_info.txt","r");
	fp_temp_file_update_employee = fopen("temporary_file _for_update_employee.txt","w");
	
	if(fp_employee_info == NULL && fp_temp_file_update_employee == NULL){
		printf("File doest not exist!\n");
		exit(1);
	}
	
	printf("\n\n\t\t\t\t\t<<----- UPDATE EMPLOYEE ----->>\n\n");
	
	printf("\t\t\t\t\tENTER EMPLOYEE ID: ");
	scanf("%s",&compare_emp_id);
	
	printf("\n");
	
	while(fscanf(fp_employee_info,"%s %s %s %s %s %s %s %s %s",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary) != EOF){
		if(strcmp(compare_emp_id,e.emp_id) == 0){
			
			printf("\t\t\t\t\tEMPLOYEE ID:         %s\n",e.emp_id);
			
			printf("\t\t\t\t\tEMPLOYEE FIRSTNAME:  %s\n",e.fname);
			
			printf("\t\t\t\t\tEMPLOYEE LASTNAME:   %s\n",e.lname);
			
			printf("\t\t\t\t\tEMPLOYEE MIDDLENAME: %s\n",e.mname);
			
			printf("\t\t\t\t\tEMPLOYEE AGE:        %s\n",e.age);
			
			printf("\t\t\t\t\tEMPLOYEE BIRTHDATE:  %s\n",e.birthdate);
			
			printf("\t\t\t\t\tEMPLOYEE ADDRESS:    %s\n",e.address);
			
			printf("\t\t\t\t\tEMPLOYEE CONTACT:    %s\n",e.contact);
			
			printf("\t\t\t\t\tEMPLOYEE SALARY:     %s\n",e.salary);
			
			printf("\n");
			
			printf("\t\t\t\t\tENTER NEW EMPLOYEE ID:   ");
			scanf("%s",&e.emp_id);

			printf("\t\t\t\t\tENTER NEW FIRSTNAME:     ");
			scanf("%s",&e.fname);

			printf("\t\t\t\t\tENTER NEW LASTNAME:      ");
			scanf("%s",&e.lname);

			printf("\t\t\t\t\tENTER NEW MIDDLENAME:    ");
			scanf("%s",&e.mname);

			printf("\t\t\t\t\tENTER NEW AGE:           ");
			scanf("%s",&e.age);

			printf("\t\t\t\t\tENTER NEW BIRTHDATE:     ");
			scanf("%s",&e.birthdate);

			printf("\t\t\t\t\tENTER NEW ADDRESS:       ");
			scanf("%s",&e.address);

			printf("\t\t\t\t\tENTER NEW CONTACT:       ");
			scanf("%s",&e.contact);

			printf("\t\t\t\t\tENTER NEW SALARY:        ");
			scanf("%s",&e.salary);
						
			fprintf(fp_temp_file_update_employee,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);
			
			printf("\n\t\t\t\t\tSUCCESSFULLY CHANGE!!!\n");
			
			check_save_count = 1;
			
			}else{
				
				fprintf(fp_temp_file_update_employee,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);
			
			} // closing brackets for if(strcmp(compare_emp_id,e.emp_id).
				
	} // closing brackets for while loop..
	
	fclose(fp_employee_info);
	fclose(fp_temp_file_update_employee);

	fp_employee_info = fopen("employee_info.txt","w");
	fp_temp_file_update_employee = fopen("temporary_file _for_update_employee.txt","r");
	
	while(fscanf(fp_temp_file_update_employee,"%s %s %s %s %s %s %s %s %s",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary) != EOF){
		
		fprintf(fp_employee_info,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);
		
	}
	
	fclose(fp_employee_info);
	fclose(fp_temp_file_update_employee);
	
	if(check_save_count	!= 1){
		
		system("cls");
		printf("\n\n\t\t\t\t\tUN-IDENTIFIED ID NUMBER!!!\n");
		Update_Employee();
		
	}
	
	printf("\t\t\t\t\tANOTHER UPDATE(Y/N)? ");
	scanf("%s",&another_update);
	
	if(another_update == 'y' || another_update == 'Y'){
		system("cls");
		Update_Employee();
	}else{
		system("cls");
		Manage_Employee();
	}	
			
}

void Search_Employee(){
	
	int check_search_count;
	char compare_id_num[20];
	char search_choice;
	
	FILE *fp_employee_info;
	fp_employee_info = fopen("employee_info.txt","r");
	
	if(fp_employee_info == NULL){
		printf("\t\t\t\t\t     FILE DOES NOT EXIST!!!\n");
		exit(1);
	}
	
	printf("\n\n\t\t\t\t\t     <<----- SEARCH EMPLOYEE ----->>\n\n");
	
	printf("\t\t\t\t\t     SEARCH ID:     ");
	scanf("%s",&compare_id_num);
	
	printf("\n");
	
	while(fscanf(fp_employee_info,"%s %s %s %s %s %s %s %s %s",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary) != EOF){
		if(strcmp(compare_id_num, e.emp_id) == 0){
			
			printf("\t\t\t\t\t     ID NUMBER:     %s\n", e.emp_id);
			
			printf("\t\t\t\t\t     FIRSTNAME:     %s\n", e.fname);
			
			printf("\t\t\t\t\t     LASTNAME:      %s\n", e.lname);
			
			printf("\t\t\t\t\t     MIDDLENAME:    %s\n", e.mname);
			
			printf("\t\t\t\t\t     AGE:           %s\n", e.age);
			
			printf("\t\t\t\t\t     BIRTHDATE:     %s\n", e.birthdate);
			
			printf("\t\t\t\t\t     ADDRESS:       %s\n", e.address);
			
			printf("\t\t\t\t\t     CONTACT:       %s\n", e.contact);
			
			printf("\t\t\t\t\t     SALARY:        %s\n\n", e.salary);
			
			check_search_count = 1;
			
		}
		
	}
	
	fclose(fp_employee_info);
	
	if(check_search_count != 1){
		
		system("cls");
		printf("\n\n\t\t\t\t\t     CANNOT FIND SPECIFIED EMPLOYEE!!!\n");
		Search_Employee();
		
	}
	
	printf("\t\t\t\t\t     ANOTHER SEARCH(Y/N)? ");
	scanf("%s",&search_choice);
	
	if(search_choice == 'y' || search_choice == 'Y'){
		
		system("cls");
		Search_Employee();
		
	}else{
		
		system("cls");
		Manage_Employee();
		
	}
		
}

void Delete_Employee(){
	
	int check_delete_count;
	char compare_id_num[20];
	char delete_choice;
	
	FILE *fp_employee_info;
	FILE *fp_temporary_file_for_delete_employee;
	
	fp_employee_info = fopen("employee_info.txt","r");
	fp_temporary_file_for_delete_employee = fopen("temporary_file_for_delete_employee.txt","w");
	
	if(fp_employee_info == NULL && fp_temporary_file_for_delete_employee == NULL){
		printf("\t\t\t\t\t     FILE DOES NOT EXIST!!!\n");
		exit(1);
	}
	
	printf("\n\n\t\t\t\t\t     <<----- DELETE EMPLOYEE ----->>\n\n");
	
	printf("\t\t\t\t\t     ENTER EMPLOYEE ID:     ");
	scanf("%s",&compare_id_num);
	
	while(fscanf(fp_employee_info,"%s %s %s %s %s %s %s %s %s",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary) != EOF){
		if(strcmp(compare_id_num,e.emp_id) == 0){
			
			printf("\n\t\t\t\t\t     EMPLOYEE ID:           %s\n", e.emp_id);
			
			printf("\t\t\t\t\t     EMPLOYEE FIRSTNAME:    %s\n", e.fname);
			
			printf("\t\t\t\t\t     EMPLOYEE LASTNAME:     %s\n", e.lname);
			
			printf("\t\t\t\t\t     EMPLOYEE MIDDLENAME:   %s\n", e.mname);
			
			printf("\t\t\t\t\t     EMPLOYEE AGE:          %s\n", e.age);
			
			printf("\t\t\t\t\t     EMPLOYEE BIRTHDATE:    %s\n", e.birthdate);
			
			printf("\t\t\t\t\t     EMPLOYEE ADDRESS:      %s\n", e.address);
			
			printf("\t\t\t\t\t     EMPLOYEE CONTACT:      %s\n", e.contact);
			
			printf("\t\t\t\t\t     EMPLOYEE SALARY:       %s\n", e.salary);
			
			printf("\n\t\t\t\t\t     SUCCESSFULLY DELETED!!!\n");
			
			check_delete_count = 1;
			
		}else{
			
			fprintf(fp_temporary_file_for_delete_employee,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);	
		
		} // closing brackets for if(strcmp(compare_id_num,e.emp_id).
		
	} // closing brackets for while loop.
	
	fclose(fp_employee_info);
	fclose(fp_temporary_file_for_delete_employee);
	
	fp_employee_info = fopen("employee_info.txt","w");
	fp_temporary_file_for_delete_employee = fopen("temporary_file_for_delete_employee.txt","r");
	
	while(fscanf(fp_temporary_file_for_delete_employee,"%s %s %s %s %s %s %s %s %s",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact,e.salary) != EOF){
		
		fprintf(fp_employee_info,"%s     %s     %s     %s     %s     %s     %s     %s     %s\n\n",e.emp_id, e.fname, e.lname, e.mname, e.age, e.birthdate, e.address, e.contact, e.salary);
		
	}
	
	fclose(fp_employee_info);
	fclose(fp_temporary_file_for_delete_employee);
	
	if(check_delete_count != 1){
		
		system("cls");
		printf("\n\n\t\t\t\t\t     UN-IDENTIFIED ID NUMBER!!!\n");
		Delete_Employee();
		
	}
	
	printf("\t\t\t\t\t     ANOTHER DELETE(Y/N)? ");
	scanf("%s",&delete_choice);
	
	if(delete_choice == 'y' || delete_choice == 'Y'){
		
		system("cls");
		Delete_Employee();
		
	}else{
		
		system("cls");
		Manage_Employee();
		
	}
	
}

void Exit_System(){
	
	char exit_system_choice;
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tARE YOUR SURE YOU WANT TO EXIT THE SYSTEM(Y/N)? ");
	scanf("%s",&exit_system_choice);
	
	if(exit_system_choice == 'y' || exit_system_choice == 'Y'){
		
		system("cls");
		exit(1);
		
	}else{
		
		system("cls");
		Manage_Employee();
		
	}
	
}
