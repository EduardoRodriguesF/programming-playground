pub fn add(left: usize, right: usize) -> usize {
    left + right
}

pub fn multiply(input: usize, multiplier: usize) -> usize {
    input * multiplier
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn add_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }

    #[test]
    fn multiply_works() {
        let result = multiply(3, 2);
        assert_eq!(result, 6);
    }
}
