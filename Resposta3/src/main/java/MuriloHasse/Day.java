package MuriloHasse;

import java.math.BigDecimal;

public class Day {
    private String dia;
    private BigDecimal valor;


    public BigDecimal getValor() {
        return valor;
    }

    public String getDia() {
        return dia;
    }

    public void setDia(String dia) {
        this.dia = dia;
    }

    public void setValor(BigDecimal valor) {
        this.valor = valor;
    }

    @Override
    public String toString() {
        return "Day{" +
                "dia='" + dia + '\'' +
                ", valor='" + valor + '\'' +
                '}';
    }
}
