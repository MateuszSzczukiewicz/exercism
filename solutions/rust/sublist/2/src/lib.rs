#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn is_sublist(first_list: &[i32], second_list: &[i32]) -> bool {
    if second_list.len() < first_list.len() {
        return false;
    }

    for i in 0..second_list.len() - first_list.len() {
        let slice = &second_list[i..i + first_list.len()];

        if slice == first_list {
            return true;
        }
    }

    false
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if first_list == second_list {
        Comparison::Equal
    } else if is_sublist(first_list, second_list) {
        Comparison::Superlist
    } else if is_sublist(second_list, first_list) {
        Comparison::Sublist
    } else {
        Comparison::Unequal
    }
}
