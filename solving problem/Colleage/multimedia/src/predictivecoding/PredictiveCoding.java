package predictivecoding;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import static java.sql.DriverManager.println;
import java.util.ArrayList;
import java.util.Scanner;

public class PredictiveCoding {
    private int step;
    public ArrayList<Integer> num = new ArrayList<Integer>();
    public ArrayList<pair> rng = new ArrayList<pair>();
    public ArrayList<table> tb = new ArrayList<table>();
   static  Writer  writer ;

    public void SetStep(int steps){step = steps;}
    public int GetStep(){return step;}
    
    static public void writeInput(ArrayList<Integer>tmp) {
            try {
               writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("E:\\output.txt")));
            } catch (IOException ex) {
            } finally {
                try {
                    for(int i = 0 ; i < tmp.size() ; i ++ ){
                       System.out.print(tmp.get(i) + " :: ");
                       writer.write(tmp.get(i) + " ");
                    }
                       writer.close();
                } catch (Exception ex) {
                }
            }
	}

    public void readInput(boolean ch) {
        num.clear(); 
        Scanner input = null;
        try {
                input = new Scanner(new File("E://input.txt"));
        } catch (Exception e) {
                System.out.println("Error Opening the File");
                return;
        }
        SetStep(input.nextInt());
        if(ch){ch=false; num.add(step);}
        while (input.hasNext()) {
            num.add(input.nextInt());
        }
    }
    
    public int getPower(int steps){
        for(int i=0;i<12;i++){
            if(Math.pow(2, i) > steps)return i;
        }
        return 0;
    }
    public void generate(){
        int nmofstp = getPower(step);
        rng.add(new pair(0,0,step-1,(0+(step-1))/2 + 1));
        for(int i=1;i<nmofstp;i++){
            int up = rng.get(rng.size()-1).upper + 1;
            int inv = up + (step-1);
            rng.add(new pair( i , up , inv , (inv + up)/2 + 1));
        }
    }
    public int getqInv(int num){
        pair pr;
        pr = rng.get(0);
        if(pr.low > num)return pr.qInv;
        for(int i=0;i<rng.size();i++){
            pr = rng.get(i);
            if(pr.low <= num && pr.upper >= num)return pr.qInv;
        }
        return pr.qInv;
    }
    
    public void ShowRng(){
        for(int i=0;i<rng.size();i++){
            System.out.println("S :: "+ rng.get(i).code + " " + 
                    rng.get(i).low + " " +rng.get(i).upper + " " + rng.get(i).qInv); 
        }
    }
    public int getq( int num){
        pair pr;
        pr = rng.get(0);
        if(pr.low > num)return pr.code;
        for(int i=0;i<rng.size();i++){
            pr = rng.get(i);
            if(pr.low <= num && pr.upper >= num)return pr.code;
        }
        return pr.code;
    }
    
    public void cpy(table n1 , table n2){
        n1.diff = n2.diff;
        n1.error = n2.error;
        n1.qinv = n2.qinv;
        n1.qr = n2.qr;
        n1.sample = n2.sample;
    }
    public void compress(){
        readInput(false);
        generate();
        table tmp = new table((num.get(0)), 0, 0, 0, 0);
        ArrayList<Integer> t1 = new ArrayList<Integer>();
        t1.add(0);
        for(int i=1;i<num.size();i++){
            tmp.diff = Math.abs(num.get(i)-num.get(i-1));
            tmp.qr = getq(tmp.diff);
            tmp.qinv = getqInv(tmp.diff);
            tmp.sample = tmp.sample + tmp.qinv;
            tmp.error = (int)Math.pow((double)Math.abs(num.get(i) - tmp.sample),(double)2);
            t1.add(getq(tmp.error));
         }
        writeInput(t1);
        System.out.println(" DONE COMPRESS");
    }
    
    public void dec(int st){
        step = st;
        generate();
        readInput(true);
        ArrayList<Integer> t1 = new ArrayList<Integer>();
        for(int i=0;i<num.size();i++){
            t1.add(getqInv(rng.get(num.get(i)).qInv));
        }
        writeInput(t1);
    }
    
    public void main(String[] args) {
        
    }
}
