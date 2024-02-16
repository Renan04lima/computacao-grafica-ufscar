/**
 * @file interval.h
 * @brief Arquivo de implementação da classe Interval
 */

#ifndef INTERVAL_H
#define INTERVAL_H

/**
 * @brief Classe que representa um intervalo na reta real.
 * 
 * A classe `interval` é utilizada para representar intervalos fechados na reta real, 
 * oferecendo métodos para operações comuns como expansão, verificação de pertencimento,
 * entre outras.
 */
class interval {
  public:
    double min, max; /**< Valores mínimo e máximo do intervalo */

    /**
     * @brief Construtor padrão que cria um intervalo vazio.
     */
    interval() : min(+infinity), max(-infinity) {} // O intervalo padrão é vazio

    /**
     * @brief Construtor que cria um intervalo com valores específicos.
     * 
     * @param _min Valor mínimo do intervalo.
     * @param _max Valor máximo do intervalo.
     */
    interval(double _min, double _max) : min(_min), max(_max) {}

    /**
     * @brief Retorna o tamanho do intervalo.
     * 
     * @return double 
     */
    double size() const {
        return max - min;
    }

    /**
     * @brief Expande o intervalo em ambas as direções.
     * 
     * @param delta Valor de aumento.
     * @return interval Novo intervalo expandido.
     */
    interval expand(double delta) const {
        auto padding = delta/2;
        return interval(min - padding, max + padding);
    }

    /**
     * @brief Verifica se um valor está presente no intervalo.
     * 
     * @param x Valor a ser verificado.
     * @return true Se o valor está no intervalo.
     * @return false Se o valor está fora do intervalo.
     */
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /**
     * @brief Verifica se um valor está nos arredores do intervalo.
     * 
     * @param x Valor a ser verificado.
     * @return true Se o valor está nos arredores do intervalo.
     * @return false Se o valor está dentro do intervalo ou fora dos arredores.
     */
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    /**
     * @brief Retorna o valor mais próximo dentro do intervalo.
     * 
     * @param x Valor a ser verificado.
     * @return double Valor mais próximo dentro do intervalo.
     */
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe; /**< Intervalos especiais: vazio e universo. */
};

const interval interval::empty    = interval(+infinity, -infinity); /**< Intervalo vazio. */
const interval interval::universe = interval(-infinity, +infinity); /**< Intervalo que cobre toda a reta real. */

#endif
