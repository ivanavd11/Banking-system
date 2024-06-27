# Banking-system
OOP project that I did for my OOP course @ FMI, Sofia University.

The banking system is a console application designed to simulate basic banking functions. The system supports several user roles, including Customers, Bank Employees and Third Party Employees, each with their specific commands and operations.

### Functionalities for Customers:            
- check_avl <bank_name> <account_number>                      
->Check the availability of an account in a particular bank.                 
- open <bank_name>                  
->Submitting a request to open a new account at a specified bank.                 
- close <bank_name> <account_number>             
->Submit a request to close an existing account.                 
- redeem <bank_name> <account_number> <verification_code>            
->Cashing a check received from a third party.                    
- change <new_bank_name> <current_bank_name> <account_number>                        
->Request to transfer an account to another bank.                   
- list <bank_name>               
->Displays all the accounts that the customer has in a particular bank.                
- messages                   
->Shows all messages received from the client.            
- exit                                  
->Exit the current session.                            
- whoami                       
->Displays information about the current user.                   
- help                          
->Displays a list of supported commands.                     

### Functionalities for Bank Employees:   
- tasks                    
->Display the list of tasks assigned to the employee.                  
- view <task_id>                 
->Display detailed information about a specific task.                 
- approve <task_id>                  
->Approve a task assigned to the employee.                                  
- disapprove <task_id> <message>                        
->Disapprove a task with a specific message.                 
- validate <task_id>                
->Validate a Change task to check if the client’s data is correct.                   
- exit                 
->Logout from the current session.                   
- whoami                 
->Display information about the logged-in user.                   
- help                 
->Display a list of supported commands.                         

### Functionalities for Third-Party Employee:               
- send_check <sum> <verification_code> <egn>          
->Create a cheque for a client with a specified EGN.                 
- exit                         
->Logout from the current session.            
- whoami                  
->Display information about the logged-in user.                
- help             
->Display a list of supported commands.

### System Commands: 
- create_bank <bank_name>        
->Create a new bank in the system.            
- signup                 
->Register a new user (Client, Bank Employee, Third-Party Employee).              
- login              
->Login to the system.                  
