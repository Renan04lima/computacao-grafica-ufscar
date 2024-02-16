/**
 * @file hittable_list.h
 * @brief Arquivo de implementação da classe Hittable_list
 */

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "./utils.h"
#include "./hittable.h"
#include <memory>
#include <vector>

/**
 * @brief Classe que representa uma lista de objetos interceptáveis em uma cena.
 * 
 * Esta classe herda de hittable e contém uma lista de objetos que podem ser interceptados por raios.
 */
class hittable_list : public hittable {
  public:
    std::vector<shared_ptr<hittable> > objects; /**< Lista de objetos interceptáveis */

    /**
     * @brief Construtor padrão.
     */
    hittable_list() {}  // Não chama o construtor da classe base

    /**
     * @brief Construtor que adiciona um objeto à lista.
     * 
     * @param object Objeto a ser adicionado à lista.
     */
    hittable_list(std::shared_ptr<hittable> object) { add(object); }

    /**
     * @brief Elimina todos os objetos interceptáveis armazenados na lista.
     */
    void clear() { objects.clear(); }

    /**
     * @brief Adiciona um novo objeto à lista de objetos interceptáveis da cena.
     * 
     * @param object Objeto a ser adicionado à lista.
     */
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    /**
     * @brief Função que verifica se algum dos objetos intercepta algo na cena.
     * 
     * @param r Raio a ser verificado.
     * @param ray_t Dados auxiliares de intervalo do raio.
     * @param rec Estrutura para armazenamento de interceptações.
     * @return true Se algum objeto intercepta o raio.
     * @return false Se nenhum objeto intercepta o raio.
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const noexcept override {
        hit_record temp_rec;
        auto hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif
