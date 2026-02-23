import java.io.*;
import java.util.ArrayList;

public class SimpleDotGame{
    public static void main(String[] args){
        int numOfGuesses = 0;
        GameHelper helper = new GameHelper();
        DotCom theDotCom = new DotCom();
        int randomNum = (int) (Math.random() * 5);
        ArrayList<String> locations = new ArrayList<String>();
        for (int i = 0; i < 3; i++) {
            locations.add(Integer.toString(randomNum + i)); // Convertido para String
        }
        theDotCom.setLocationCells(locations);
        boolean isAlive = true;
        while (isAlive == true){
            String guess = helper.getUserInput("Insira um numero: ");
            String result = theDotCom.checkYourself(guess);
            numOfGuesses++;
            if(result.equals("kill")){
                isAlive = false;
                System.out.println("Você usuou " + numOfGuesses + " palpites");
            }
        }
    }
}

class DotCom{
    private ArrayList<String> locationCells;
    
    public void setLocationCells(ArrayList<String> loc){
        locationCells = loc;
    }

    public String checkYourself(String userInput){
        String result = "miss";
        int index = locationCells.indexOf(userInput);
        if(index >= 0){
            locationCells.remove(index);
            if(locationCells.isEmpty()){
                result = "kill";
            }else{
                result = "hit";
            }
        }
        System.out.println(result);
        return result;
    }
}

class GameHelper{
    public String getUserInput(String prompt){
        String inputLine = null;
        System.out.print(prompt + " ");
        try{
            BufferedReader is = new BufferedReader(new InputStreamReader(System.in));
            inputLine = is.readLine();
            if(inputLine.length() == 0) return null;
        }catch (IOException e){
            System.out.print("IOException: " + e);
        }
        return inputLine;
    }
}