pub struct Rectangle {
    pub width: u32,
    pub height: u32,
}

pub struct Triangle {
    pub x: u32,
    pub y: u32,
    pub z: u32,
}

pub enum TriangleType {
    Isosceles,
    Equilateral,
    Scalene,
    Invalid,
}

impl Rectangle {
    pub fn new(width: u32, height: u32) -> Self {
        Rectangle { width, height }
    }

    pub fn area(&self) -> u32 {
        self.width * self.height
    }

    pub fn is_valid(&self) -> bool {
        self.width > 0 && self.height > 0
    }

    pub fn can_hold(&self, other: &Self) -> bool {
        self.width >= other.width && self.height >= other.height
    }
}

impl Triangle {
    pub fn new(x: u32, y: u32, z: u32) -> Self {
        Self { x, y, z }
    }

    pub fn is_isosceles(&self) -> bool {
        self.x == self.y || self.x == self.z || self.y == self.z
    }

    pub fn is_equilateral(&self) -> bool {
        self.x == self.y && self.y == self.z
    }

    pub fn is_scalene(&self) -> bool {
        self.x != self.y && self.x != self.z && self.y != self.z
    }

    pub fn kind(&self) -> TriangleType {
        if self.is_equilateral() { 
            return TriangleType::Equilateral;
        }

        if self.is_isosceles() {
            return TriangleType::Isosceles;
        }

        if self.is_scalene() {
            return TriangleType::Scalene;
        }

        TriangleType::Invalid
    }
}
