pub struct Rectangle {
    pub width: u32,
    pub height: u32,
}

pub struct Triangle {
    pub sizes: (u32, u32, u32),
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
    pub fn new(sizes: (u32, u32, u32)) -> Self {
        Self { sizes }
    }

    pub fn is_isosceles(&self) -> bool {
        let sizes = self.sizes;

        sizes.0 == sizes.1 || sizes.0 == sizes.2 || sizes.1 == sizes.0
    }

    pub fn is_equilateral(&self) -> bool {
        let sizes = self.sizes;

        sizes.0 == sizes.1 && sizes.1 == sizes.2
    }

    pub fn is_scalene(&self) -> bool {
        let sizes = self.sizes;

        sizes.0 != sizes.1 && sizes.0 != sizes.2 && sizes.1 != sizes.2
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
