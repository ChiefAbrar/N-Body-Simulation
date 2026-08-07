#ifndef OCTREE_HPP
#define OCTREE_HPP

#include <vector>
#include "vector.hpp"
#include "body.hpp"

struct BoundingBox {
    Vector center;
    double halfWidth = 1.0;

    bool contains(const Vector& p) const {
        return std::abs(p.x - center.x) <= halfWidth && std::abs(p.y - center.y) && std::abs(p.z - center.z) <= halfWidth;
    }
};
class OctreeNode {
    public:
    explicit OctreeNode(const BoundingBox& box);
        void inset(const Body* b);

        void computeForce(const Body& b, double theta, double G, double softening, Vector& outAcc) const;
        bool isLeaf() const {
            return children[0] == nullptr;
        }
        bool isEmpty() const {
            return count == 0;
        }
    private:
        void subdivide();
        int octantOf(const Vector& p) const;
        BoundingBox box;
        std::unique_ptr<OctreeNode> children[8];
        const Body* body = nullptr;
        int count = 0;
        double totalMass = 0.0;
        Vector centerOfMass;
};

std::unique_ptr<OctreeNode> buildTree(const std::vector<Body>& bodies);
#endif