#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
  private:
    unsigned cost_;
    unsigned weight_;

  public:
    Object(const unsigned &cost, const unsigned &weight);

    unsigned getWeight() const;
    unsigned getCost() const;
};

#endif /* OBJECT_H_ */