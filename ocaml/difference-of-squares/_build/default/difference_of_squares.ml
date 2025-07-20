let rec list_from_num num list =
    if num = 0 then list
    else list_from_num (num - 1) (num :: list)

let () = 
  let my_list = list_from_num 40 [] in
  Printf.printf "Lista ma %d elementów\n" (List.length my_list)

let square_of_sum _ = 
    failwith "'square_of_sum' is missing"

let sum_of_squares _ =
    failwith "'sum_of_squares' is missing"

let difference_of_squares _ =
    failwith "'difference_of_squares' is missing"
