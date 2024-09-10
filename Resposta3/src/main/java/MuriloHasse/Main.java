package MuriloHasse;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        File json = new File("dados.json");
        ObjectMapper mapper = new ObjectMapper();

        try {

            List<Day> days = mapper.readValue(json, new TypeReference<ArrayList<Day>>() {});
            BigDecimal menor = days.getFirst().getValor();
            BigDecimal maior = days.getFirst().getValor();
            BigDecimal avg = avg(days);
            int k = 0;
            for (Day day : days) {
                if (day.getValor().compareTo(menor) < 0 && day.getValor().compareTo(BigDecimal.ZERO) != 0) {
                    menor = day.getValor();
                }if (day.getValor().compareTo(maior) > 0) {
                    maior = day.getValor();
                }if (day.getValor().compareTo(avg) > 0) {
                    k++;
                }
            }
            System.out.println("Menor valor não considerando dias sem faturamento = " + menor.toString());
            System.out.println("Maior valor = " + maior.toString());
            System.out.println("Media não considerando dias sem faturamento = " + avg);
            System.out.println("Dias em que o faturramento foi maior que a media = " + k);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
    public static BigDecimal avg(List<Day> days){
        BigDecimal avg = BigDecimal.ZERO;
        int i = 0;
        for (Day day : days){
            if (day.getValor().compareTo(BigDecimal.ZERO) != 0) {
                avg = avg.add(day.getValor());
                i++;
            }
        }
        if (i == 0){
            return BigDecimal.ZERO;
        }
        avg = avg.divide(BigDecimal.valueOf(i), RoundingMode.HALF_UP);
        return avg;
    }
}