pub struct Triangle {
    pub sizes: (u32, u32, u32),
}

pub enum TriangleType {
    Isosceles,
    Equilateral,
    Scalene,
    Invalid,
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
