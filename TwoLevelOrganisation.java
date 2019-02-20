import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

class TwoLevelOrganisation{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        int dcount=0;
        TwoLevelDirectoryOrganisation[] tldo = new TwoLevelDirectoryOrganisation[7];
while(true){
        System.out.println(" \n MENU");
        System.out.println("1. Create new file/directory ");
        System.out.println("2. Search for a file/directory ");
        System.out.println("3. Delete a file/directory ");
        System.out.println("4. Display ");
        System.out.println("5. Exit ");
        System.out.println("\n");
        System.out.println("Enter the choice: ");
        int ch=Integer.parseInt(br.readLine());
        switch(ch){
            case 1: {
                dcount++;
                tldo[dcount]=new TwoLevelDirectoryOrganisation(0);
                System.out.println("\n");
                System.out.println("Do you wish to create a directory?");
                String sub=br.readLine();
                if (sub.equals("yes") || sub.equals("YES")  ||sub.equals("Yes")){
                    System.out.println("Enter the name of the directory:  ");
                    str=br.readLine();
                    tldo[dcount].directoryname=str;
                    System.out.println("Enter the number of files in this subdirectory: ");
                    tldo[dcount].fcount=Integer.parseInt(br.readLine());
                    for (int i = 1; i <= tldo[dcount].fcount; i++) {
                        System.out.println("Enter the name of the file: ");
                        str=br.readLine();
                        tldo[dcount].filename[i]=str;
                    }
                }
                else
                {
                    System.out.println("Enter the name of the file: ");
                    str=br.readLine();
                    tldo[dcount].fname=str;
                }
            }break;
            case 2:{
                System.out.println("\n");
                System.out.println("Enter the name of the file:  ");
                str=br.readLine();
                boolean flag=false;
                for(int i=1; i<=dcount; i++){
                    if(str.equals(tldo[i].fname) || (str.equals(tldo[i].directoryname)) ){
                        flag=true;
                    }
                }
                for(int i=1; i<=dcount;i++){
                    for(int j=1;j<=tldo[i].fcount;j++){
                        if(str.equals(tldo[i].filename[j])){
                            flag=true;
                         }
                         else {
                             continue;
                         }

                    }
                  
                 }
                    
                if(flag==true){
                    System.out.println("File found. ");
                }
                else{
                    System.out.println("File not found.");
                }
            }break;
            case 3:{
                System.out.println("\n");                
                System.out.println("Enter the name of the file:  ");
                str=br.readLine();
                boolean flag=false;
                for(int i=1; i<=dcount; i++){
                    if(str.equals(tldo[i].fname)){
                        tldo[i].fname="";
                        tldo[i].dirno=0;
                        dcount--;
                        flag=true;
                    } 
                    if(str.equals(tldo[i].directoryname)){
                        tldo[i].dirno=0;
                        tldo[i].directoryname="";
                        dcount--;
                        flag=true;
                    }
                    
                    }
            
                for(int i=1; i<=dcount;i++){
                    for(int j=1;j<=tldo[i].fcount;j++){
                        if(str.equals(tldo[i].filename[j])){
                            tldo[i].filename[j]="";
                            tldo[i].dirno=0;
                            tldo[i].fcount--;
                            flag=true;
                         }
                         else {
                             continue;
                         }

                    }
                  
                 }
                if(flag==true){
                    System.out.println("File/Folder deleted. ");
                }
                else{
                    System.out.println("File/Folder not found.");
                }
            
            }break;
        
            case 4:{
                System.out.println("\n");
                System.out.println("Directory Structure ");
                 for(int i=1;i<=dcount;i++){
                    //System.out.println("Name: \t " + tldo[i].getdirectoryname());
                    if(tldo[i].fcount==0){
                        System.out.println("File: "+ tldo[i].getfname());
                    }
                    else{
                        System.out.println("Folder: " + tldo[i].getdirectoryname());
                        for(int j=1; j<=tldo[i].fcount;j++){
                            System.out.println(" \t File: " + tldo[i].filename[j]);
                        }
                        
                    }
                 }
            }break;
            case 5: System.exit(0);
        }    
    }
    }
     
}