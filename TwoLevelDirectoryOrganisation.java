class TwoLevelDirectoryOrganisation{
    int dirno;
    int fcount;
    String directoryname;
    String[] filename;
    String fname;
    
    TwoLevelDirectoryOrganisation(int dno){
        this.dirno=dno;
        this.fcount=0;
        filename = new String[5];
    }
    String getdirectoryname()
    {
        return this.directoryname;
    }
    String getfname(){
        return this.fname;
    }
    
    
}