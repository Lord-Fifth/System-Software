import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;

class SingleLevelOrganisation{
    
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        SingleLevelDirectoryOrganisation[] dir = new SingleLevelDirectoryOrganisation[7];
        
        String str;
        int ch=0;
        int fcount=0;
        while(true){
            System.out.println("\n MENU");
            System.out.println("1. Create new file ");
            System.out.println("2. Search for a file ");
            System.out.println("3. Delete a file ");
            System.out.println("4. Display all files ");
            System.out.println("5. Exit ");
            System.out.println("\n");
            System.out.println("Enter the choice: ");
            ch=Integer.parseInt(br.readLine());
            switch(ch){
                case 1: {
                    fcount++;
                    dir[fcount]=new SingleLevelDirectoryOrganisation(0);
                    System.out.println("\n");
                    System.out.println("Enter the name of the file:  ");
                    str=br.readLine();
                    dir[fcount].filename=str; 
                    System.out.println("\n");
                    System.out.println("File added.");
                }break;
                case 2:{
                    System.out.println("\n");
                    System.out.println("Enter the name of the file:  ");
                    str=br.readLine();
                    boolean flag=false;
                    for(int i=1; i<=fcount; i++){
                        if(str.equals(dir[i].filename)){
                            flag=true;
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
                    for(int i=1; i<=fcount; i++){
                        if(str.equals(dir[i].filename)){
                            dir[i].filename="";
                            dir[i].dirno=0;
                            fcount--;
                            flag=true;
                        }
                    }
                    if(flag==true){
                        System.out.println("File deleted. ");
                    }
                    else{
                        System.out.println("File not found.");
                    }
                }break;
                case 4:{
                    
                    System.out.println("\n");
                    System.out.println("Directory Structure ");
                     for(int i=1;i<=fcount;i++){
                        System.out.println("File: \t " + dir[i].getdirectoryname());
                     }
                }break;
                case 5: System.exit(0);
            }    
        }
    }
}