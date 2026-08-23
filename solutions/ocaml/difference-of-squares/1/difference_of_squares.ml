let rec list_from_num num list =
    if num = 0 then list
    else list_from_num (num - 1) (num :: list)

let square_of_sum num =
    let sum = List.fold_left (+) 0 (list_from_num num [])
    in sum * sum

let sum_of_squares num = 
    let squared_list = list_from_num num []
    |> List.map (fun x -> x * x)
    in List.fold_left (+) 0 (squared_list)

let difference_of_squares num =
    square_of_sum num - sum_of_squares num
