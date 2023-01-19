#include "wolf.h"

void wolf::get_neareast_animal(std::vector<std::shared_ptr<animal>> animals)
{
    int animal_distance_x;
    int animal_distance_y;
    int animal_distance;
    int neareast = frame_width;

    for (auto &animal_ptr : animals)
    {
        if (animal_ptr->type == SHEEP)
        {
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance =
                sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            if (neareast > animal_distance)
            {
                neareast = animal_distance;
                nearest_sheep = animal_ptr;
                nearest_sheep_pos_ = animal_ptr->pos;
            }
        }
        else if (animal_ptr->type == DOG)
        {
            animal_distance_x = animal_ptr->pos.x - pos.x;
            animal_distance_y = animal_ptr->pos.y - pos.y;
            animal_distance =
                sqrt(pow(animal_distance_x, 2) + pow(animal_distance_y, 2));
            if (neareast > animal_distance)
            {
                neareast = animal_distance;
                closest_dog_pos_ = animal_ptr->pos;
                // Check if the shepherd's dog is to close of the wolf
                if (animal_distance < DIST_MIN_WOLF)
                    to_close = true;
                else
                {
                    to_close = false;
                }
            }
        }
    }
}

void wolf::move()
{
    is_get_sheep();

    // if th dog is to close then the wolf get away
    if (to_close)
    {
        if (pos.x > closest_dog_pos_.x)
            pos.x++;
        if (pos.x < closest_dog_pos_.x)
            pos.x--;
        if (pos.y > closest_dog_pos_.y)
            pos.y++;
        if (pos.y < closest_dog_pos_.y)
            pos.y--;
    }
    // else he get closer to a sheep
    else
    {
        if (pos.x > nearest_sheep_pos_.x)
            pos.x--;
        if (pos.x < nearest_sheep_pos_.x)
            pos.x++;
        if (pos.y > nearest_sheep_pos_.y)
            pos.y--;
        if (pos.y < nearest_sheep_pos_.y)
            pos.y++;
    }

    // wolf::time_to_catch();
}

/*
 // Create a time_point that will hold the start time
    std::chrono::time_point<std::chrono::steady_clock> start =
 std::chrono::steady_clock::now();

    // Perform some operation
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Calculate the duration of the operation
    std::chrono::duration<double> duration = std::chrono::steady_clock::now() -
 start; std::cout << "Duration of operation: " << duration.count() << " seconds"
 << std::endl;

    // Reset the time_point to the current time
    start = std::chrono::steady_clock::now();
*/

void wolf::time_to_catch()
{
    if (get_Sheep)
    {
        m_lastMealTime = SDL_GetTicks();
    }

    Uint32 elapsedTime = SDL_GetTicks() - m_lastMealTime;

    if (elapsedTime > kStarvationPeriod)
    {
        std::cout << "Wolf has died of starvation" << std::endl;
        isalive = false;
    }
}

void wolf::is_get_sheep()
{
    // Il y a une difference de position de 1 entre les deux image quand elle
    // sont l'un sur l'autre
    if ((nearest_sheep_pos_.x == pos.x || (nearest_sheep_pos_.x - 1 == pos.x)
         || (nearest_sheep_pos_.x + 1 == pos.x)
         || (nearest_sheep_pos_.x + 2 == pos.x)
         || (nearest_sheep_pos_.x - 2 == pos.x))
        && (nearest_sheep_pos_.y == pos.y || (nearest_sheep_pos_.y - 1) == pos.y
            || (nearest_sheep_pos_.y + 1) == pos.y
            || (nearest_sheep_pos_.y - 2) == pos.y
            || (nearest_sheep_pos_.y + 2) == pos.y))
    {
        get_Sheep = true;
        nearest_sheep->isalive = false;
    }
    else
    {
        get_Sheep = false;
    }
}